module LangRepr.Construct;

import Dump;

import LLIR.API;
import NFA;
import DFA.API;

import constants;
import corelib;
import cpuf.printf;
import logging;
import hash;
import DFA.Collection;
import DFA.CharMachineDFA;
import DFA.Base;

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
        // 2. Sort
        // --- Collect deps ---
        utype::unordered_map<Name, utype::unordered_set<Name>> deps;
        utype::unordered_map<Name, std::size_t> usage_count;
        utype::unordered_set<Name> to_forward_declare;
        for (const Name &n : order) {
            const Node *node = root.find(n);
            if (!node) { deps[n] = {}; continue; }

            utype::unordered_set<Name> used;
            if (node->data.is_regular_data_block()) {
                auto dt = node->data.getRegularDataBlock().second;
                auto [s, _to_forward_declare] = collectReferencedNames(dt);
                for (const auto &[name, count] : s) {
                    usage_count[name] += count;
                    used.insert(name);
                }
                to_forward_declare.insert(_to_forward_declare.begin(), _to_forward_declare.end());
            } else if (node->data.is_inclosed_map()) {
                for (const auto &p : node->data.getInclosedMap()) {
                    auto [s, _to_forward_declare] = collectReferencedNames(p.second.second);
                    for (const auto &[name, count] : s) {
                        usage_count[name] += count;
                        used.insert(name);
                    }
                    to_forward_declare.insert(_to_forward_declare.begin(), _to_forward_declare.end());
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
        utype::unordered_set<Name> dependent;
        if (sorted.size() != order.size()) {
            cycled.reserve(order.size() - sorted.size());
            for (const Name &n : order) {
                if (indeg[n] > 0) cycled.insert(n);
            }
            // append remaining preserving original order (or compute SCCs and handle)
            utype::unordered_set<Name> independent;
            for (const Name &n : cycled) {
                if (usage_count[n] == 1) {
                    independent.insert(n);
                } else {
                    dependent.insert(n);
                }
            }
            stdu::vector<Name> sorted_final;

            // 3a: Add all acyclic nodes in original Kahn order
            for (const Name &n : sorted) {
                if (!cycled.contains(n)) {
                    sorted_final.push_back(n);
                }
            }

            // 3b: Topologically sort independents among themselves
            utype::unordered_map<Name, std::size_t> indeg2;
            for (const Name &n : independent) {
                indeg2[n] = 0;
            }

            // Count dependencies **only on other independent nodes** (acyclic already sorted)
            for (const auto& [u, adj] : deps) {
                if (!independent.contains(u)) continue;
                for (const Name &v : adj) {
                    if (independent.contains(v)) ++indeg2[u]; // increment **for u**, not v
                }
            }

            // Kahn for independents
            std::deque<Name> q2;
            for (const Name &n : independent) {
                if (indeg2[n] == 0) q2.push_back(n);
            }

            while (!q2.empty()) {
                Name v = q2.front(); q2.pop_front();
                sorted_final.push_back(v);

                // Decrement indegree for independent nodes that depend on v
                for (const Name &dep : rev_deps[v]) {
                    if (!independent.contains(dep)) continue;
                    --indeg2[dep];
                    if (indeg2[dep] == 0) q2.push_back(dep);
                }
            }

            // 3c: Append dependents in original input order
            for (const Name &n : order) {
                if (dependent.contains(n)) sorted_final.push_back(n);
            }

            // Replace original sorted
            sorted = std::move(sorted_final);
        }
        auto needs_box = dependent;
        needs_box.insert(to_forward_declare.begin(), to_forward_declare.end());
        // `sorted` now contains dependency-first order for acyclic parts,
        // followed by any cyclical group(s) (which you must handle specially).
        // Use `sorted` for emission.

        // 3. Wrap everything into `Types` and FlatTypes namespace
        LangAPI::Namespace flatTypesNamespace {.name = "FlatTypes"};
        LangAPI::Namespace typesNamespace { .name = "Types" };
        for (const auto &dep : dependent) {
            flatTypesNamespace.declarations.push_back(LangAPI::ForwardDeclaredClass::createDeclaration(LangAPI::ForwardDeclaredClass {.name = corelib::text::join(dep, "_")}));
        }
        for (const auto &dep : to_forward_declare) {
            flatTypesNamespace.declarations.push_back(LangAPI::ForwardDeclaredClass::createDeclaration(LangAPI::ForwardDeclaredClass {.name = corelib::text::join(dep, "_")}));
        }
        // output types to flatTypes namespace
        auto switchToFlatType = [&](LangAPI::Type &t) {
            if (t.isSymbol()) {
                std::string path;
                std::size_t count = 0;
                for (const auto &part : t.getSymbol().path) {
                    if (std::holds_alternative<std::string>(part)) {
                        const auto &part_str = std::get<std::string>(part);
                        path += part_str + "_";
                    }
                    count++;
                }
                path.pop_back();
                t.type = LangAPI::Symbol {path};
            }
        };
        std::function<void(LangAPI::Type &)> switchToFlatTypeRecursively = [&](LangAPI::Type &t) {
            if (auto vt = t.getValueType(); vt == LangAPI::ValueType::Token || vt == LangAPI::ValueType::Rule || vt == LangAPI::ValueType::TokenResult || vt == LangAPI::ValueType::RuleResult || vt == LangAPI::ValueType::Box) {
                switchToFlatType(std::get<LangAPI::Type>(t.template_parameters[0]));
            } else {
                for (auto &templ : t.template_parameters) {
                    if (std::holds_alternative<LangAPI::Type>(templ)) {
                        switchToFlatTypeRecursively(std::get<LangAPI::Type>(templ));
                    }
                }
            }
        };

        std::function<void(LangAPI::Type &)> makeDependentTypeBox = [&](LangAPI::Type &t) {
            if (t.isSymbol()) {
                Name actual_name;
                const auto &first = t.getSymbol().path[0];
                for (const auto &part : t.getSymbol().path) {
                    if (!std::holds_alternative<std::string>(part))
                        return;
                    actual_name.push_back(std::get<std::string>(part));
                }
                if (!needs_box.contains(actual_name))
                    return;
                t.template_parameters = {LangAPI::Type {LangAPI::Symbol {corelib::text::join(actual_name, "_")}}};
                t.type = LangAPI::ValueType::Box;
            } else if (t.isValueType()) {
                const auto &vtype = t.getValueType();
                if (vtype == LangAPI::ValueType::Box || vtype == LangAPI::ValueType::Token || vtype == LangAPI::ValueType::Rule || vtype == LangAPI::ValueType::RuleResult || vtype == LangAPI::ValueType::TokenResult) {
                    makeDependentTypeBox(std::get<LangAPI::Type>(t.template_parameters[0]));
                }
            }
        };
        std::function<void(LangAPI::Type &)> makeDependentTypeBoxRecursively = [&](LangAPI::Type &t) {
            if (auto vt = t.getValueType(); vt == LangAPI::ValueType::Token || vt == LangAPI::ValueType::Rule || vt == LangAPI::ValueType::TokenResult || vt == LangAPI::ValueType::RuleResult || vt == LangAPI::ValueType::Box) {
                makeDependentTypeBox(std::get<LangAPI::Type>(t.template_parameters[0]));
            } else {
                for (auto &templ : t.template_parameters) {
                    if (std::holds_alternative<LangAPI::Type>(templ)) {
                        makeDependentTypeBoxRecursively(std::get<LangAPI::Type>(templ));
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
                makeDependentTypeBoxRecursively(type);
                switchToFlatTypeRecursively(type);
                c.data.push_back(
                    std::make_pair(
                        std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration(LangAPI::Variable {.name = "value", .type = type})),
                        LangAPI::Visibility::Public
                    )
                );
            } else if (old->data.is_inclosed_map()) {
                for (const auto &[name, type] : old->data.getInclosedMap()) {
                    auto t = type.second;
                    makeDependentTypeBoxRecursively(t);
                    switchToFlatTypeRecursively(t);
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
            for (const auto& [childName, childNode] : node.children) {
                fullname.push_back(childName);
                auto nested = build(*childNode, childName, fullname);
                fullname.pop_back();
                s.data.push_back(std::make_pair(std::make_shared<LangAPI::Declaration>(std::move(nested)), LangAPI::Visibility::Public));
            }
            return LangAPI::Class::createDeclaration(std::move(s));
        };
        // Build top-level children of root
        for (const auto& [name, node] : new_tree.children) {
            Name fullname = {name};
            auto topDecls = build(*node, name, fullname);
            typesNamespace.declarations.push_back(std::move(topDecls));
        }
        holder.push(flatTypesNamespace);
        holder.push(typesNamespace);
    }
    auto Construct::constructLexer() -> void {
        LangAPI::IspaLibSymbol lexer_symbol {LangAPI::StdlibExports::Lexer};
        // We include all rule and token types for consistency between Lexer and Parser
        // MainNode first
        LangAPI::Symbol main_tn = {"Types", "main"};
        lexer_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(main_tn));

        for (const auto &dtb : ir.getDataBlocks()) {
            if (dtb.first == stdu::vector<std::string>{"main"}) continue;
            LangAPI::Symbol tn = dtb.first;
            tn.path.insert(tn.path.begin(), "Types");
            lexer_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(tn));
        }
        for (const auto &dtb : lexer_builder.getDataBlocks()) {
            LangAPI::Symbol tn = dtb.first;
            tn.path.insert(tn.path.begin(), "Types");
            lexer_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(tn));
        }

        LangAPI::Class lexer {
            .name = "Lexer",
            .inherit_members = {std::make_pair(LangAPI::Visibility::Public, lexer_symbol)},
            .default_visibility = LangAPI::Visibility::Private
        };

        struct StateData{
            LangAPI::IspaLibSymbol type;
            stdu::vector<stdu::vector<std::string>> names;
            int transition_size;
        };
        const auto &dfas = lexer_builder.getDFAS().get();
        std::size_t count = 0;
        auto states = lexer_builder.getDFAS().getStateSet();

        // construct states
        utype::unordered_map<std::size_t, StateData> state_exports_cache;

        // Tracks which DFA tables are referenced by MultiTable transitions and their node type lists (unique, stable order)
        utype::unordered_map<std::size_t, stdu::vector<std::pair<LangAPI::Type, stdu::vector<std::string>>>> referenced_by_multitable;
        utype::unordered_map<std::size_t, stdu::vector<stdu::vector<std::string>>> multitable_nodes;
        utype::unordered_map<std::size_t, stdu::vector<LangAPI::IspaLibSymbol>> state_multi_types;
        utype::unordered_map<std::size_t, bool> state_force_char_table;
        // For each state id, remember which DFA tables it references via MultiTable transitions
        utype::unordered_map<std::size_t, stdu::vector<std::size_t>> state_referred_tables;
        utype::unordered_map<std::size_t, LangAPI::Type> state_build_type;

        // Build reverse map for DFA names
        utype::unordered_map<std::size_t, stdu::vector<std::string>> dfa_index_to_name;
        for (const auto& [name, index] : lexer_builder.getNameToDFAIndex()) {
            dfa_index_to_name[index] = name;
        }

        // Small local helpers to reduce duplication and improve readability
        using TypeParam = std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>;

        // Recursively ensure that every LangAPI::Symbol used as a type has "Types" prefixed to its path.
        // This is required because many generated types live under the Types:: namespace and nested
        // template arguments must be adjusted as well.
        auto ensureTypesNsFull = [&](auto &self, LangAPI::Type &t) -> void {
            if (t.isSymbol()) {
                auto &sym = t.getSymbol();
                bool has_types_prefix = false;
                if (!sym.path.empty() && std::holds_alternative<std::string>(sym.path.front())) {
                    has_types_prefix = (std::get<std::string>(sym.path.front()) == std::string("Types"));
                }
                if (!has_types_prefix) {
                    sym.path.insert(sym.path.begin(), std::string("Types"));
                }
            } else if (t.isIspaLibSymbol()) {
                auto &isym = t.getIspaLibSymbol();
                for (auto &tp : isym.template_parameters) {
                    if (std::holds_alternative<std::shared_ptr<LangAPI::Type>>(tp)) {
                        auto &pt = *std::get<std::shared_ptr<LangAPI::Type>>(tp);
                        self(self, pt);
                    }
                }
            }
            // If it's a ValueType, nothing to do. Also process Type's own template_parameters.
            for (auto &tp : t.template_parameters) {
                if (std::holds_alternative<LangAPI::Type>(tp)) {
                    auto &nt = std::get<LangAPI::Type>(tp);
                    self(self, nt);
                }
            }
        };
        auto ensureTypesNs = [&](LangAPI::Type &t) { ensureTypesNsFull(ensureTypesNsFull, t); };

        auto getTransitionCount = [](const auto &transitions) -> int {
            if (std::holds_alternative<DFA::FullCharTable>(transitions)) {
                return static_cast<int>(std::get<DFA::FullCharTable>(transitions).size());
            }
            return static_cast<int>(std::get<DFA::SortedTransitions>(transitions).size());
        };

        auto makeIntRValue = [](int v) -> std::shared_ptr<LangAPI::RValue> {
            return std::make_shared<LangAPI::RValue>(
                LangAPI::Int::createRValue(LangAPI::Int{.value = v})
            );
        };

        auto makeMultiTransitionParamForNode = [](LangAPI::Symbol tn) -> TypeParam {
            return TypeParam{std::make_shared<LangAPI::Type>(
                LangAPI::IspaLibSymbol{
                    .exports = LangAPI::StdlibExports::DfaMultiTransition,
                    .template_parameters = { TypeParam{ std::make_shared<LangAPI::Type>(tn) } }
                }
            )};
        };

        auto buildStateSymbol = [&](DFA::DfaType state_type, LangAPI::Symbol tn, DFA::DfaType dfa_type) -> LangAPI::IspaLibSymbol {
            LangAPI::IspaLibSymbol s;
            tn.path.insert(tn.path.begin(), "Types");
            auto makeReturnType = [&]() -> std::shared_ptr<LangAPI::Type> {
                auto rt = std::make_shared<LangAPI::Type>(tn);
                ensureTypesNs(*rt);
                return rt;
            };
            switch (state_type) {
                case DFA::DfaType::Char:
                    s.exports = LangAPI::StdlibExports::DfaCharState;
                    break;
                case DFA::DfaType::Token:
                    s.exports = LangAPI::StdlibExports::DfaTokenState;
                    break;
                case DFA::DfaType::Multi:
                    s.exports = LangAPI::StdlibExports::DfaMultiTableState;
                    s.template_parameters = { makeReturnType() };
                    break;
                default:
                    switch (dfa_type) {
                        case DFA::DfaType::Char:
                            s.exports = LangAPI::StdlibExports::DfaCharEmptyState;
                            s.template_parameters.push_back(makeReturnType());
                            break;
                        case DFA::DfaType::Multi:
                            s.exports = LangAPI::StdlibExports::DfaMultiTableEmptyState;
                            s.template_parameters.push_back(makeReturnType());
                            break;
                        default: break;
                    }
            }
            return s;
        };

        // Constructs the lambda for EmptyState with proper data vector type.
        // If dfa_type is Multi, provide node_types (template params for MultiTableDataVector) for correct emission
        auto makeEmptyStateLambda = [&](DFA::DfaType dfa_type, const stdu::vector<std::string> &name, const stdu::vector<std::string> &clear_name,
                                        const NFA::DataBlock &nfa_dtb, const stdu::vector<LangAPI::Symbol>& node_types) -> LangAPI::Lambda {
            stdu::vector<std::pair<LangAPI::Type, std::string>> params;
            params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaEmptyStateMemberBegin}}, "mb"});
            params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaEmptyStateGroupBegin}}, "gb"});
            if (dfa_type == DFA::DfaType::Multi) {
                stdu::vector<std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>> tp;
                if (!node_types.empty()) {
                    tp.reserve(node_types.size());
                    for (const auto &ty : node_types) {
                        auto p = std::make_shared<LangAPI::Type>(ty);
                        ensureTypesNs(*p);
                        tp.push_back(std::move(p));
                    }
                }
                params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaMultiTableEmptyStateLambdaParameter, .template_parameters = std::move(tp)}}, "dv"});
            } else {
                params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaCharTableEmptyStateLambdaParameter}}, "dv"});
            }

            LangAPI::Statements body;
            const auto data_blocks = lexer_builder.getDataBlocks();
            const auto &data_block = data_blocks.at(clear_name);
            long long member_pos = 0;
            LangAPI::IspaLibSymbol call_sym {.exports = LangAPI::StdlibExports::DfaCstStore};
            for (const auto &s : node_types) {
                auto p = std::make_shared<LangAPI::Type>(s);
                ensureTypesNs(*p);
                call_sym.template_parameters.push_back(std::move(p));
            }
            if (data_block.is_inclosed_map()) {
                const auto &templated_data_block = std::get<NFA::TemplatedDataBlock>(nfa_dtb);
                LangAPI::Type data_t { LangAPI::Symbol {name} };
                ensureTypesNs(data_t);
                body.push_back(LangAPI::Variable::createStatement(LangAPI::Variable {.name = "data", .type = std::move(data_t)}));
                for (const auto &[mname, mdata] : data_block.getInclosedMap()) {
                    stdu::vector<std::string> msymbol_array = {mname};
                    LangAPI::StorageSymbol msymbol = msymbol_array;
                    LangAPI::Symbol position_manager = (templated_data_block.at(mname).first == NFA::StoreCstNode::CST_GROUP ? "gb" : "mb");
                    call_sym.exports = templated_data_block.at(mname).first == NFA::StoreCstNode::CST_GROUP ? LangAPI::StdlibExports::DfaCstGroupStore : LangAPI::StdlibExports::DfaCstStore;
                    auto tp = std::make_shared<LangAPI::Type>(mdata.second);
                    ensureTypesNs(*tp);
                    call_sym.template_parameters.insert(call_sym.template_parameters.begin(), std::move(tp));
                    msymbol.what = LangAPI::Symbol::createExpression(LangAPI::Symbol {"data"});

                    body.push_back(LangAPI::IspaLibFunctionCall::createStatement(LangAPI::IspaLibFunctionCall {.symbol = call_sym, .args = {LangAPI::StorageSymbol::createExpression(msymbol), LangAPI::Int::createExpression(LangAPI::Int {.value = member_pos}), LangAPI::Symbol::createExpression(position_manager), LangAPI::Symbol::createExpression(LangAPI::Symbol {"dv"})}}));
                    call_sym.template_parameters.erase(call_sym.template_parameters.begin());
                    member_pos++;
                }
                body.push_back(LangAPI::Return::createStatement(LangAPI::Return {.value = LangAPI::Symbol::createExpression(LangAPI::Symbol {"data"})}));
            } else if (!data_block.empty()) {
                const auto &block = data_block.getRegularDataBlock();
                const auto &sv_data_block = std::get<NFA::SingleValueDataBlock>(nfa_dtb);
                LangAPI::StorageSymbol msymbol;
                LangAPI::Symbol position_manager = (sv_data_block == NFA::StoreCstNode::CST_GROUP ? "gb" : "mb");
                call_sym.exports = sv_data_block == NFA::StoreCstNode::CST_GROUP ? LangAPI::StdlibExports::DfaCstGroupStore : LangAPI::StdlibExports::DfaCstStore;
                {
                    auto tp = std::make_shared<LangAPI::Type>(block.second);
                    ensureTypesNs(*tp);
                    call_sym.template_parameters.insert(call_sym.template_parameters.begin(), std::move(tp));
                }
                msymbol.what = LangAPI::Symbol::createExpression(LangAPI::Symbol {"data"});
                msymbol.path = {"value"};
                {
                    LangAPI::Type data_t { LangAPI::Symbol {name} };
                    ensureTypesNs(data_t);
                    body.push_back(LangAPI::Variable::createStatement(LangAPI::Variable {.name = "data", .type = std::move(data_t)}));
                }
                body.push_back(LangAPI::IspaLibFunctionCall::createStatement(LangAPI::IspaLibFunctionCall {.symbol = call_sym, .args = {LangAPI::StorageSymbol::createExpression(msymbol), LangAPI::Int::createExpression(LangAPI::Int {.value = 0}), LangAPI::Symbol::createExpression(position_manager), LangAPI::Symbol::createExpression(LangAPI::Symbol {"dv"})}}));
                body.push_back(LangAPI::Return::createStatement(LangAPI::Return {.value = LangAPI::Symbol::createExpression(LangAPI::Symbol {"data"})}));
            } else {
                {
                    LangAPI::Type data_t { LangAPI::Symbol {name} };
                    ensureTypesNs(data_t);
                    body.push_back(LangAPI::Variable::createStatement(LangAPI::Variable {.name = "data", .type = std::move(data_t)}));
                }
                body.push_back(LangAPI::Return::createStatement(LangAPI::Return {.value = LangAPI::Symbol::createExpression(LangAPI::Symbol {"data"})}));
            }
            return LangAPI::Lambda{ .parameters = std::move(params), .statements = std::move(body) };
        };
        for (const auto &state : states.state_set) {

            const auto [dfa_idx, state_idx] = states.state_in_dfa_location_map.at(count);
            const auto &dfa = dfas.at(dfa_idx);

            // We only care about SortedTransitions
            if (!std::holds_alternative<DFA::SortedTransitions>(state.transitions)) {
                ++count;
                continue;
            }

            const auto &[type, tn_path] = states.state_to_type.at(count);

            const auto &sorted_transitions =
                std::get<DFA::SortedTransitions>(state.transitions);

            for (const auto &[symbol, transition] : sorted_transitions) {

                // Only MultiTable transitions (vector<string> symbol)
                if (!std::holds_alternative<stdu::vector<std::string>>(symbol))
                    continue;

                const auto &sym_name =
                    std::get<stdu::vector<std::string>>(symbol);

                const auto referred_dfa_index =
                    lexer_builder.getNameToDFAIndex().at(sym_name);

                // Only care if current DFA is Multi
                if (dfa.getType() != DFA::DfaType::Multi)
                    continue;

                // Extract node type from this state
                LangAPI::Type node_type { LangAPI::Symbol {sym_name} };

                auto &vec1 = referenced_by_multitable[referred_dfa_index];
                auto &vec2 = multitable_nodes[dfa_idx];
                if (std::find_if(vec1.begin(), vec1.end(), [&](const auto &vec_part) { return vec_part.first == node_type; }) == vec1.end()) {
                    vec1.push_back({node_type, sym_name});
                }
                if (std::find(vec2.begin(), vec2.end(), sym_name) == vec2.end()) {
                    vec2.push_back(sym_name);
                }
            }

            ++count;
        }
        count = 0;
        for (const auto &state : states.state_set) {
            const auto [dfa_idx, local_state_index] = states.state_in_dfa_location_map.at(count);
            const auto &dfa = dfas.at(dfa_idx);
            auto [type, tn_path] = states.state_to_type.at(count);
            LangAPI::Symbol tn = tn_path;
            LangAPI::Symbol return_type_sym = tn;
            return_type_sym.path.insert(return_type_sym.path.begin(), "Types");

            const int transition_size = getTransitionCount(state.transitions);
            auto s = buildStateSymbol(type, tn, dfa.getType());

            stdu::vector<LangAPI::Expression> transitions;
            const stdu::vector<std::string> *clear_name;
            stdu::vector<std::string> token_name = {"Tokens"};
            stdu::vector<std::string> token_type = {"Types"};
            LangAPI::Lambda construct_lambda;
            stdu::vector<stdu::vector<std::string>> names;
            bool empty = false;
            if (std::holds_alternative<DFA::FullCharTable>(state.transitions)) {
                const auto &char_transitions = std::get<DFA::FullCharTable>(state.transitions);
                unsigned char c = std::numeric_limits<unsigned char>::min();
                for (const auto &transition : char_transitions) {
                    transitions.push_back(
                        LangAPI::IspaLibDfaTransition::createExpression(LangAPI::IspaLibDfaTransition {
                            .symbol = static_cast<char>(c),
                            .next = transition.next,
                            .new_cst_node = transition.new_cst_node,
                            .new_member = transition.new_member,
                            .close_cst_node = transition.close_cst_node,
                            .new_group = transition.new_group,
                            .group_close = transition.group_close,
                            .accept = transition.accept_index,
                            .transition_type = LangAPI::IspaLibSymbol {.exports = LangAPI::StdlibExports::DfaCharTransition}
                        })
                    );
                    c++;
                }
            } else {
                const auto &sorted_transitions = std::get<DFA::SortedTransitions>(state.transitions);
                if (sorted_transitions.empty() && state.else_goto == 0) {
                    clear_name = &state.rule_name;
                    token_name.insert(token_name.end(), state.rule_name.begin(), state.rule_name.end());
                    token_type.insert(token_type.end(), state.rule_name.begin(), state.rule_name.end());
                    stdu::vector<LangAPI::Symbol> node_types;
                    // Prepare lambda with correct data vector type
                    if (dfa.getType() == DFA::DfaType::Multi) {
                        for (const auto &node_type : multitable_nodes.at(dfa_idx)) {
                            LangAPI::Symbol sym {node_type};
                            sym.path.insert(sym.path.begin(), "Types");
                            node_types.push_back(sym);
                            s.template_parameters.push_back(std::make_shared<LangAPI::Type>(sym));
                        }
                    }
                    construct_lambda = makeEmptyStateLambda(dfa.getType(), token_type, state.rule_name, state.dtb, node_types);
                    empty = true;
                    s.exports = dfa.getType() == DFA::DfaType::Char ? LangAPI::StdlibExports::DfaCharEmptyState : LangAPI::StdlibExports::DfaMultiTableEmptyState;
                } else s.template_parameters.push_back(std::make_shared<LangAPI::RValue>(LangAPI::Int {.value = transition_size}));
                bool is_referring_char_table = !empty && std::all_of(sorted_transitions.begin(), sorted_transitions.end(), [&] (const auto & transition_pair) {
                    return dfas.at(lexer_builder.getNameToDFAIndex().at(std::get<stdu::vector<std::string>>(transition_pair.first))).getType() == DFA::DfaType::Char;
                });
                for (const auto &[symbol, transition] : sorted_transitions) {
                    stdu::vector<std::string> name;
                    if (std::holds_alternative<stdu::vector<std::string>>(symbol)) {
                        const auto &sym_name = std::get<stdu::vector<std::string>>(symbol);
                        const auto referred_dfa_idx = lexer_builder.getNameToDFAIndex().at(sym_name);

                        // Record that this state references that DFA table
                        auto &refs = state_referred_tables[count];
                        if (std::find(refs.begin(), refs.end(), referred_dfa_idx) == refs.end())
                            refs.push_back(referred_dfa_idx);

                        LangAPI::IspaLibSymbol new_s;
                        std::vector<TypeParam> params;
                        // Fetch frozen node pack
                        const auto it_nodes = referenced_by_multitable.find(referred_dfa_idx);
                        if (it_nodes == referenced_by_multitable.end() || it_nodes->second.empty())
                            throw Error("Undefined node pack for multitable transition");
                        for (const auto &ty : it_nodes->second) {
                            auto sym = ty.first.getSymbol();
                            sym.path.insert(sym.path.begin(), "Types");
                            params.push_back(std::make_shared<LangAPI::Type>(sym));
                            if (is_referring_char_table) {
                                s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Type {LangAPI::IspaLibSymbol {LangAPI::StdlibExports::DfaCharTableTransition, {std::make_shared<LangAPI::Type>(sym)}}}));
                            } else {
                                s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Type {LangAPI::IspaLibSymbol {LangAPI::StdlibExports::DfaMultiTransition, {std::make_shared<LangAPI::Type>(sym)}}}));
                            }
                            names.push_back(ty.second);
                        }
                        if (is_referring_char_table) {
                            const auto &referred_dfa = dfas.at(referred_dfa_idx);
                            new_s = LangAPI::IspaLibSymbol {
                                .exports = LangAPI::StdlibExports::DfaCharTableTransition,
                                .template_parameters = std::move(params)
                            };
                        } else {
                            new_s = {
                                .exports = LangAPI::StdlibExports::DfaMultiTransition,
                                .template_parameters = std::move(params)
                            };
                        }
                        transitions.push_back(
                            LangAPI::IspaLibDfaTransition::createExpression(
                                LangAPI::IspaLibDfaTransition{
                                    .symbol = referred_dfa_idx,
                                    .next = transition.next,
                                    .new_cst_node = transition.new_cst_node,
                                    .new_member = transition.new_member,
                                    .close_cst_node = transition.close_cst_node,
                                    .new_group = transition.new_group,
                                    .group_close = transition.group_close,
                                    .accept = transition.accept_index,
                                    .transition_type = new_s,
                                    .is_refferring_char_table = is_referring_char_table
                                }
                            )
                        );
                    } else {
                        transitions.push_back(
                         LangAPI::IspaLibDfaTransition::createExpression(LangAPI::IspaLibDfaTransition {
                                 .symbol = std::get<char>(symbol),
                                 .next = transition.next,
                                 .new_cst_node = transition.new_cst_node,
                                 .new_member = transition.new_member,
                                 .close_cst_node = transition.close_cst_node,
                                 .new_group = transition.new_group,
                                 .group_close = transition.group_close,
                                 .accept = transition.accept_index,
                                 .transition_type = s,
                                 .is_refferring_char_table = false
                             })
                         );
                    }
                }
            }
            lexer.data.push_back(
                std::make_pair(
	                std::make_shared<LangAPI::Declaration>(LangAPI::Variable::createDeclaration( LangAPI::Variable {
	                .name = std::string("dfa_state_") + std::to_string(count),
	                .type = s,
                    .value = empty ? LangAPI::IspaLibDfaEmptyState::createExpression(LangAPI::IspaLibDfaEmptyState {.token_name = *clear_name, .construction_lambda = std::make_shared<LangAPI::Lambda>(construct_lambda)}) : LangAPI::Array::createExpression(LangAPI::Array { .values = transitions}),
                    .is_static = true
	            })),
                LangAPI::Visibility::Private
                )
            );
            state_exports_cache.emplace(count, decltype(state_exports_cache)::node_type::mapped_type {s, names, transition_size});
            ++count;
        }
        // construct DFA tables
        for (std::size_t dfa_count = 0; dfa_count < dfas.size(); ++dfa_count) {
	        const auto &dfa = dfas.at(dfa_count);
	        stdu::vector<LangAPI::Expression> dfa_table_states;
            std::shared_ptr<LangAPI::Type> return_type_ptr;
	        bool multitable = dfa.getType() == DFA::DfaType::Multi;

            auto dfa_available_types = dfa.availableTypes();
            if (dfa_available_types.size() == 1) {
                return_type_ptr = std::make_shared<LangAPI::Type>(dfa_available_types.front());
            } else {
                return_type_ptr = std::make_shared<LangAPI::Type>(LangAPI::ValueType::Variant);
                for (const auto &name : dfa_available_types) {
                    return_type_ptr->template_parameters.push_back(LangAPI::Type(name));
                }
            }
            auto table_params = std::vector<std::variant<std::shared_ptr<LangAPI::Type>, std::shared_ptr<LangAPI::RValue>>> {
                std::make_shared<LangAPI::Type>(*return_type_ptr),
                std::make_shared<LangAPI::RValue>(
                    LangAPI::Int::createRValue(LangAPI::Int {.value = (long long) dfa.get().size()})
                )
              };
            if (multitable) {
                for (std::size_t state_count = 0; state_count < dfa.get().size(); ++state_count) {
                    const auto &state_id = states.location_in_set.at(std::make_pair(dfa_count, state_count));
                    auto [type, names, size] = state_exports_cache.at(state_id);
                    const auto &state = states.state_set.get().at(state_id);
                    if (!type.template_parameters.empty() && type.exports != LangAPI::StdlibExports::DfaCharTableState && !(std::holds_alternative<DFA::SortedTransitions>(state.transitions) && std::get<DFA::SortedTransitions>(state.transitions).empty())) {
                        table_params.push_back(type.template_parameters.back());
                    }
                }
            }
            // Decide table kind based on computed multitable flag, not by parameter count
            LangAPI::Variable dfa_table_var {
                .name = "dfa_table_" + std::to_string(dfa_count),
                .type = LangAPI::Type {
                    LangAPI::IspaLibSymbol {
                        multitable ? LangAPI::StdlibExports::DfaMultiTable : LangAPI::StdlibExports::DfaCharTable,
                        table_params
                    }
                },
                .value = LangAPI::Array::createExpression(LangAPI::Array { .values = dfa_table_states }),
                .is_static = true
            };
            lexer.data.emplace_back(std::make_shared<LangAPI::Declaration>(LangAPI::Statement::createDeclaration(dfa_table_var)), LangAPI::Visibility::Private);
	        }
	        holder.push(lexer);

            // Debug DFA and State relationships
            {
                // Map index back to name for readability
                std::map<std::size_t, stdu::vector<std::string>> idx_to_name;
                for (const auto& [name, idx] : lexer_builder.getNameToDFAIndex()) {
                    idx_to_name[idx] = name;
                }

                if (dumper.shouldDump("dfa_relations")) {
                    std::ofstream out(dumper.makeDumpPath("dfa_relations.txt"));
                    if (out.is_open()) {
                        out << "DFA Relationships and Dependencies\n";
                        out << "================================\n\n";

                        for (std::size_t i = 0; i < dfas.size(); ++i) {
                            const auto& dfa = dfas.at(i);
                            out << "DFA " << i;
                            if (idx_to_name.count(i)) {
                                out << " (" << corelib::text::join(idx_to_name[i], "::") << ")";
                            }
                            out << "\n";
                            out << "  Type: " << (dfa.getType() == DFA::DfaType::Char ? "Char" : "Multi") << "\n";

                            // Show which node types this table supports (if it's a MultiTable)
                            if (referenced_by_multitable.count(i)) {
                                out << "  Supported Node Types (as MultiTable):\n";
                                for (const auto& type : referenced_by_multitable.at(i)) {
                                    cpuf::printf("\t{}: {}\n", type.second, type.first);
                                }
                            }

                            // Show references to other DFAs
                            std::set<std::size_t> refs;
                            for (std::size_t s_idx = 0; s_idx < dfa.get().size(); ++s_idx) {
                                const auto& state_id = states.location_in_set.at({i, s_idx});
                                if (state_referred_tables.count(state_id)) {
                                    for (auto ref_idx : state_referred_tables.at(state_id)) {
                                        refs.insert(ref_idx);
                                    }
                                }
                            }

                            if (!refs.empty()) {
                                out << "  Depends on:\n";
                                for (auto ref_idx : refs) {
                                    out << "    -> DFA " << ref_idx;
                                    if (idx_to_name.count(ref_idx)) {
                                        out << " (" << corelib::text::join(idx_to_name[ref_idx], "::") << ")";
                                    }
                                    out << "\n";
                                }
                            }
                            out << "\n";
                        }
                    }
                }

                if (dumper.shouldDump("state_relations")) {
                    std::ofstream out(dumper.makeDumpPath("state_relations.txt"));
                    if (out.is_open()) {
                        std::size_t s_idx = 0;
                        for (const auto &state : states.state_set) {
                            const auto [dfa_idx, state_idx] = states.state_in_dfa_location_map.at(s_idx);
                            out << "Global State " << s_idx << " (DFA " << dfa_idx;
                            if (idx_to_name.count(dfa_idx)) {
                                out << " [" << corelib::text::join(idx_to_name[dfa_idx], "::") << "]";
                            }
                            out << ")\n";

                            if (state_exports_cache.count(s_idx)) {
                                const auto& [s_type, s_name, n_trans] = state_exports_cache.at(s_idx);
                                out << "  Export Type: " << s_type.exports << " (Transitions: " << n_trans << ")\n";
                                if (!s_type.template_parameters.empty()) {
                                    out << "  Template Parameters:\n";
                                    for (const auto& tp : s_type.template_parameters) {
                                        if (std::holds_alternative<std::shared_ptr<LangAPI::Type>>(tp)) {
                                            out << "    - Type: " << *std::get<std::shared_ptr<LangAPI::Type>>(tp) << "\n";
                                        } else {
                                            out << "    - RValue: " << *std::get<std::shared_ptr<LangAPI::RValue>>(tp) << "\n";
                                        }
                                    }
                                }
                            }

                            if (state_multi_types.count(s_idx) && !state_multi_types.at(s_idx).empty()) {
                                out << "  Multi-Transition Signatures used:\n";
                                for (const auto& sym : state_multi_types.at(s_idx)) {
                                    out << "    - " << (int)sym.exports << " <";
                                    for (const auto& tp : sym.template_parameters) {
                                        if (std::holds_alternative<std::shared_ptr<LangAPI::Type>>(tp)) {
                                            out << *std::get<std::shared_ptr<LangAPI::Type>>(tp) << ", ";
                                        }
                                    }
                                    out << ">\n";
                                }
                            }

                            if (std::holds_alternative<DFA::SortedTransitions>(state.transitions)) {
                                const auto &sorted = std::get<DFA::SortedTransitions>(state.transitions);
                                if (sorted.empty()) {
                                    out << "  (Empty/Accepting State)\n";
                                } else {
                                    out << "  Transitions:\n";
                                    for (const auto &[symbol, transition] : sorted) {
                                        out << "    - ";
                                        if (std::holds_alternative<char>(symbol)) {
                                            out << "'" << std::get<char>(symbol) << "'";
                                        } else if (std::holds_alternative<stdu::vector<std::string>>(symbol)) {
                                            out << "DFA Ref: " << corelib::text::join(std::get<stdu::vector<std::string>>(symbol), "::");
                                        }
                                        out << " -> Next: " << transition.next << " (Accept: " << transition.accept_index << ")\n";
                                    }
                                }
                            } else if (std::holds_alternative<DFA::FullCharTable>(state.transitions)) {
                                out << "  (Full Char Table Transitions)\n";
                            }

                            out << "\n";
                            s_idx++;
                        }
                    }
                }
            }
    }
    auto Construct::constructParser() -> void {
        LangAPI::IspaLibSymbol parser_symbol {LangAPI::StdlibExports::Parser};
        // MainNode first
        LangAPI::Symbol main_tn = {"main"};
        main_tn.path.insert(main_tn.path.begin(), "Types");
        parser_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(main_tn));

        // Then all other rules
        for (const auto &dtb : ir.getDataBlocks()) {
            if (dtb.first == stdu::vector<std::string>{"main"}) continue;
            LangAPI::Symbol tn = dtb.first;
            tn.path.insert(tn.path.begin(), "Types");
            parser_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(tn));
        }
        // And also all token types (Lexer_base needs them in LLParser_base)
        for (const auto &dtb : lexer_builder.getDataBlocks()) {
            LangAPI::Symbol tn = dtb.first;
            tn.path.insert(tn.path.begin(), "Types");
            parser_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(tn));
        }

        LangAPI::Class parser {
            .name = "Parser",
            .inherit_members = {std::make_pair(LangAPI::Visibility::Public, parser_symbol)},
            .default_visibility = LangAPI::Visibility::Private
        };
        // construct DFAs
        for (const auto &dfa : ir.getDfas()) {

        }
        for (const auto &fun_data : ir.getData()) {
            std::function<void(LangAPI::Type&)> fun_data_type_modifier = [&](LangAPI::Type& t) {
                if (t.isSymbol()) {
                    auto &sym = t.getSymbol();
                    sym.path.insert(sym.path.begin(), "Types");
                } else {
                    for (auto &tp : t.template_parameters) {
                        if (std::holds_alternative<LangAPI::Type>(tp))
                            fun_data_type_modifier(std::get<LangAPI::Type>(tp));
                    }
                }
            };
            LangAPI::Symbol fun_data_symbol = fun_data.name;
            fun_data_symbol.path.insert(fun_data_symbol.path.begin(), "Types");
            for (auto &statement : fun_data.members) {
                if (statement.isVariable()) {
                    auto &var = statement.getVariable();
                    fun_data_type_modifier(var.type);
                } else if (statement.isExpression()) {
                    auto &expr = statement.getExpression();
                    if (expr.size() == 1 && expr.front().isDfaLookup()) {
                        auto &dfa_lookup = expr.front().getDfaLookup();
                        fun_data_type_modifier(dfa_lookup.return_type);
                    }
                }
            }
            parser.data.push_back(
                std::make_pair(
                    std::make_shared<LangAPI::Declaration>(
                        LangAPI::Function::createDeclaration(LangAPI::Function {
                            .type = LangAPI::Type {LangAPI::IspaLibSymbol {LangAPI::StdlibExports::Node, {std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Rules"}), std::make_shared<LangAPI::Type>(LangAPI::Symbol {fun_data_symbol})}}},
                            .name = corelib::text::join(fun_data.name, "_"),
                            .parameters = {std::make_pair(LangAPI::Type {LangAPI::IspaLibSymbol {LangAPI::StdlibExports::ParserFunctionParameter} }, "pos")},
                            .statements =  fun_data.members,
                            .template_parameters = {"Iterator"}
                        })
                    ),
                    LangAPI::Visibility::Public
                )
            );
        }
        holder.push(parser);
    }

    auto Construct::construct() -> Holder& {
        constructTokensAndRulesEnum();
        //constructTokensAndRulesEnumToString();
        constructTypesNamespace();
        constructLexer();
        // constructParser();
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
