module LangRepr.Construct;

import LLIR.API;

import constants;
import corelib;
import cpuf.printf;
import logging;
import hash;

import dstd;
import std;

namespace LangRepr {
    auto Construct::constructTokensAndRulesEnum() -> void {
        LangAPI::Enum tokens_enum("Tokens");
        LangAPI::Enum rules_enum("Rules");
        for (const auto &dtb : lexer_builder.getDataBlocks()) {
            tokens_enum.value.push_back(corelib::text::join(dtb.first, "_"));
        }
        for (const auto &dtb : ir.getDataBlocks()) {
            rules_enum.value.push_back(corelib::text::join(dtb.first, "_"));
        }
        holder.push(tokens_enum);
        holder.push(rules_enum);
    }
    auto Construct::constructTokensAndRulesEnumToString() -> void {
        auto constructSwitchFromDataBlockList = [](const LLIR::DataBlockList &list, const char* name) {
            LangAPI::Switch ss;
            ss.expression = LangAPI::Symbol::createExpression(LangAPI::Symbol {name});
            for (const auto &[name, block] : list) {
                ss.cases.emplace_back();
                ss.cases.back().first = LangAPI::Symbol::createRValue(LangAPI::Symbol {corelib::text::join(name, "_")});
                ss.cases.back().second = LangAPI::Return::createStatements(LangAPI::Return {.value = LangAPI::String::createExpression(corelib::text::join(name, "_"))});
            }
            return ss;
        };
        LangAPI::Function tokens_fun {
            .name = "tokensToString",
            .parameters = { std::make_pair<LangAPI::Type>(LangAPI::Symbol {"Tokens"}, "token") },
            .statements = LangAPI::Switch::createStatements(constructSwitchFromDataBlockList(lexer_builder.getDataBlocks(), "tokens"))
        };
        LangAPI::Function rules_fun {
            .name = "rulesToString",
            .parameters = { std::make_pair<LangAPI::Type>(LangAPI::Symbol {"Rules"}, "rules") },
            .statements = LangAPI::Switch::createStatements(constructSwitchFromDataBlockList(ir.getDataBlocks(), "rules"))
        };
        holder.push(tokens_fun);
        holder.push(rules_fun);
    }
    auto Construct::constructTypesNamespace() -> void {
        // Tree node to represent namespaces/types
        Node root;
        stdu::vector<Name> order;
        utype::unordered_map<Name, std::size_t> name_to_index_in_order;
        utype::unordered_map<Name, std::size_t> reorder_count;

        // 1. Build the tree
        auto buildDtb = [&root, &order, &name_to_index_in_order](const LLIR::DataBlockList &dtb_list) {
            for (const auto& dtb : dtb_list) {
                const Name &nameParts = dtb.first;
                name_to_index_in_order.emplace(nameParts, order.size());
                order.push_back(nameParts);
                root.find_or_emplace(nameParts)->data = dtb.second;
            }

        };
        auto lexer_data_blocks = lexer_builder.getDataBlocks();
        auto parser_data_blocks = ir.getDataBlocks();
        buildDtb(lexer_data_blocks);
        buildDtb(parser_data_blocks);
        // 2. Sort Function
        // --- Collect deps as you already do (deps: node -> set<dependency>) ---
        utype::unordered_map<Name, utype::unordered_set<Name>> deps;
        for (const Name &n : order) {
            const Node *node = root.find(n);
            if (!node) { deps[n] = {}; continue; }

            utype::unordered_set<Name> used;
            if (node->data.is_regular_data_block()) {
                auto dt = node->data.getRegularDataBlock().second;
                auto s = collectReferencedNames(dt);
                used.insert(s.begin(), s.end());
            } else if (node->data.is_inclosed_map()) {
                for (const auto &p : node->data.getInclosedMap()) {
                    auto s = collectReferencedNames(p.second.second);
                    used.insert(s.begin(), s.end());
                }
            }
            // remove self-dependency if any
            used.erase(n);
            deps[n] = std::move(used);
        }

        // --- Build reverse graph: dependency -> set of dependents
        utype::unordered_map<Name, utype::unordered_set<Name>> rev_deps;
        for (const Name &n : order) rev_deps[n]; // ensure key exists
        for (const auto &kv : deps) {
            const Name &node = kv.first;
            for (const Name &dep : kv.second) {
                // if `dep` is not one of our known names, skip it
                if (name_to_index_in_order.find(dep) == name_to_index_in_order.end()) continue;
                rev_deps[dep].insert(node); // dep -> node (dependent)
            }
        }

        // --- indegree = number of dependencies each node has
        utype::unordered_map<Name, std::size_t> indeg;
        for (const Name &n : order) indeg[n] = deps[n].size();

        // --- initialize queue with indeg == 0, preserving original order
        std::deque<Name> q;
        for (const Name &n : order) {
            if (indeg[n] == 0) q.push_back(n);
        }

        // --- Kahn: when we pop v, we iterate rev_deps[v] (dependents) and decrement them
        stdu::vector<Name> sorted;
        sorted.reserve(order.size());
        while (!q.empty()) {
            Name v = q.front(); q.pop_front();
            sorted.push_back(v);
            // for each dependent of v
            for (const Name &dependent : rev_deps[v]) {
                // decrement indegree of dependent (it had one less unresolved dependency)
                if (indeg[dependent] > 0) {
                    --indeg[dependent];
                    if (indeg[dependent] == 0) {
                        q.push_back(dependent);
                    }
                }
            }
        }

        // cycles: nodes with indeg > 0
        utype::unordered_set<Name> cycled;
        if (sorted.size() != order.size()) {
            cycled.reserve(order.size() - sorted.size());
            for (const Name &n : order) {
                if (indeg[n] > 0) cycled.insert(n);
            }
            // Report or handle cycles: emit forward declarations for `remaining`
            cpuf::printf("Types sorting: cycle detected among {} items: {}", cycled.size(), cycled);
            // append remaining preserving original order (or compute SCCs and handle)
            for (const Name &n : cycled) sorted.push_back(n);
        }

        // `sorted` now contains dependency-first order for acyclic parts,
        // followed by any cyclical group(s) (which you must handle specially).
        // Use `sorted` for emission.

        // 3. Wrap everything into `Types` and FlatTypes namespace
        LangAPI::Namespace flatTypesNamespace {.name = "FlatTypes"};
        LangAPI::Namespace typesNamespace { .name = "Types" };

        // output types to flatTypes namespace
        std::function<void(LangAPI::Type &)> adjustType = [&](LangAPI::Type &t) {
            if (t.isSymbol()) {
                std::string path;
                for (const auto &part : t.getSymbol().path) {
                    if (std::holds_alternative<std::string>(part)) {
                        path += std::get<std::string>(part) + "_";
                    }
                }
                path.pop_back();
                t.type = LangAPI::Symbol {path};
            }
        };
        std::function<void(LangAPI::Type &)> adjustTypeRecursively = [&](LangAPI::Type &t) {
            if (auto vt = t.getValueType(); vt == LangAPI::ValueType::Token || vt == LangAPI::ValueType::Rule || vt == LangAPI::ValueType::TokenResult || vt == LangAPI::ValueType::RuleResult) {
                adjustType(std::get<LangAPI::Type>(t.template_parameters[0]));
            } else {
                for (auto &templ : t.template_parameters) {
                    if (std::holds_alternative<LangAPI::Type>(templ)) {
                        adjustTypeRecursively(std::get<LangAPI::Type>(templ));
                    }
                }
            }
        };
        for (const auto &fullName : sorted) {
            const Node *old = root.find(fullName);
            if (!old) continue; // or throw
            LangAPI::Class c;
            c.name = corelib::text::join(fullName, "_");
            if (old->data.is_regular_data_block()) {
                auto type = old->data.getRegularDataBlock().second;
                adjustTypeRecursively(type);
                c.data.push_back(
                    std::make_pair(
                        std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(LangAPI::Variable {.name = "value", .type = type})),
                        LangAPI::Visibility::Public
                    )
                );
            } else if (old->data.is_inclosed_map()) {
                for (const auto &[name, type] : old->data.getInclosedMap()) {
                    auto t = type.second;
                    adjustTypeRecursively(t);
                    if (auto vt = t.getValueType(); vt == LangAPI::ValueType::Token || vt == LangAPI::ValueType::Rule || vt == LangAPI::ValueType::TokenResult || vt == LangAPI::ValueType::RuleResult) {
                        adjustType(std::get<LangAPI::Type>(t.template_parameters[0]));
                    }
                    c.data.push_back((std::make_pair(std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(LangAPI::Variable {.name = name, .type = t})), LangAPI::Visibility::Public)));
                }
            }
            flatTypesNamespace.declarations.push_back(LangAPI::Class::createDeclaration(std::move(c)));
        }

        // build index map (fast lookup of sorted order)
        utype::unordered_map<Name, std::size_t> sorted_index;
        sorted_index.reserve(sorted.size());
        for (std::size_t i = 0; i < sorted.size(); ++i) sorted_index[sorted[i]] = i;

        // recursive factory: takes old Node* and the full path for that node
        std::function<std::unique_ptr<SortedNode>(const Node*, const Name&)> make_sorted_from_node;
        make_sorted_from_node = [&](const Node* old_ptr, const Name &fullPath) -> std::unique_ptr<SortedNode> {
            if (!old_ptr) return nullptr;
            auto out = std::make_unique<SortedNode>();

            // copy data (or move if you intentionally want to steal)
            out->data = old_ptr->data;

            // collect child names and their indices (if known)
            std::vector<std::pair<std::size_t, std::string>> child_order;
            child_order.reserve(old_ptr->children.size());

            std::size_t unknown_base = sorted.size() + 1; // index for children not in 'sorted'
            for (const auto &child_pair : old_ptr->children) {
                Name childFull = fullPath;
                childFull.push_back(child_pair.first);
                auto it = sorted_index.find(childFull);
                std::size_t idx = (it != sorted_index.end() ? it->second : unknown_base++);
                child_order.emplace_back(idx, child_pair.first);
            }

            // stable sort children by their position in global 'sorted'
            std::stable_sort(child_order.begin(), child_order.end(),
                             [](const auto &a, const auto &b){ return a.first < b.first; });

            // build children in sorted order, recursively passing the child's full path
            for (const auto &p : child_order) {
                const std::string &childName = p.second;
                Name childFull = fullPath;
                childFull.push_back(childName);
                const Node *childOld = old_ptr->children.at(childName).get();
                auto childSorted = make_sorted_from_node(childOld, childFull);
                out->children.emplace(childName, std::move(childSorted));
            }

            return out;
        };

        // top-level loop: build new_tree following 'sorted' order
        SortedNode new_tree;
        for (const auto &fullName : sorted) {
            // walk or create path in new_tree, but use factory only for the leaf node
            SortedNode* cur = &new_tree;
            for (std::size_t i = 0; i < fullName.size(); ++i) {
                const auto &part = fullName[i];
                auto it = cur->children.find(part);
                if (it == cur->children.end()) {
                    cur->children.emplace(part, std::make_unique<SortedNode>());
                    it = cur->children.find(part);
                }
                cur = it->second.get();
            }

            // populate cur->data + its children using make_sorted_from_node
            const Node *old = root.find(fullName);
            if (!old) continue; // or throw
            // take the result subtree (already sorted among its children)
            auto subtree = make_sorted_from_node(old, fullName);
            if (subtree) {
                // move data and children into the placeholder node `cur`
                cur->data = std::move(subtree->data);
                cur->children = std::move(subtree->children);
            }
        }

        // 2. Recursive builder
        std::function<LangAPI::Declaration(const SortedNode&, const std::string&, stdu::vector<std::string>&)> build;
        build = [&](const SortedNode& node, const std::string& name, stdu::vector<std::string> &fullname) -> LangAPI::Declaration {
            // Build children first
            stdu::vector<std::pair<Name, const SortedNode*>> child_output_order;
            if (node.children.empty()) {
                return LangAPI::TypeAlias::createDeclaration(LangAPI::TypeAlias {.name = name, .type = LangAPI::Symbol {"FlatTypes", corelib::text::join(fullname, "_")}});
            }
            LangAPI::Class s;
            s.name = name;
            s.inherit_members = {std::make_pair(LangAPI::Visibility::Public, LangAPI::Symbol {"FlatTypes", corelib::text::join(fullname, "_")})};
            for (const auto &child_pair : node.children) {
                auto new_full_name = fullname;
                new_full_name.push_back(child_pair.first);
                child_output_order.push_back(std::make_pair(new_full_name, child_pair.second.get()));
            }
            std::sort(child_output_order.begin(), child_output_order.end(), [&](const auto &a, const auto &b) {
                return std::find(sorted.begin(), sorted.end(), a.first) < std::find(sorted.begin(), sorted.end(), b.first);
            });
            for (const auto& [childName, childNode] : child_output_order) {
                auto nested = build(*childNode, childName.back(), fullname);
                s.data.push_back(std::make_pair(std::make_shared<LangAPI::Declaration>(std::move(nested)), LangAPI::Visibility::Public));
            }
            return LangAPI::Class::createDeclaration(std::move(s));
        };
        // Build top-level children of root
        for (const auto& [name, node] : new_tree.children) {
            stdu::vector<std::string> fullname = {name};
            auto topDecls = build(*node, name, fullname);
            typesNamespace.declarations.push_back(std::move(topDecls));
        }
        holder.push(flatTypesNamespace);
        holder.push(typesNamespace);
    }

    auto Construct::construct() -> Holder& {
        constructTokensAndRulesEnum();
        constructTokensAndRulesEnumToString();
        constructTypesNamespace();
        LangAPI::Namespace ns;
        ns.name = namespace_name;
        ns.declarations = std::move(holder.get());
        holder.get().clear();
        holder.push(ns);
        return holder;
    }
    auto Construct::construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, LangAPI::Language lang, const std::string &namespace_name) -> Holder {
        Construct construct(std::move(lexer_builder), std::move(ir), lang, namespace_name);
        return construct.construct();
    }
}
