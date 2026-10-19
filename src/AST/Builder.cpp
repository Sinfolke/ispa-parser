module;
#include <../../parser/stdlibs/ispastdlib.hpp>
#include <ispastdlib/node.hpp>
#include <ispastdlib/raw_token.hpp>
#include <output/Parser.h>
module AST.Builder;
import AST.types;
import AST.Tree;
import cpuf.printf;
import corelib;
import logging;
import dstd;
import std;

namespace {
    template<typename T>
    const T& payload(const T& value) {
        return value;
    }

    template<typename T>
    const T& payload(const std::shared_ptr<T>& value) {
        if (!value) {
            throw std::runtime_error("Null parser AST node");
        }
        return *value;
    }

    template<typename T>
    decltype(auto) payload(const UAST::Node<T>& node) {
        return payload(node.data());
    }
    std::string id(const UAST::Node<UAST::ID>& node) {
        return payload(node).value;
    }
    stdu::vector<std::string> qualifiedName(const UAST::name& n) {
        stdu::vector<std::string> result;
        result.push_back(id(n.primary));
        for (const auto& segment : n.nested) result.push_back(id(segment));
        return result;
    }
    [[noreturn]] void unsupported(const std::string& message) {
        throw std::runtime_error("ISPA bootstrap converter: unsupported " + message);
    }
    std::string unescapeString(std::string value) {
        // Lexer returns literal body, as in the original Builder. Preserve escape behavior.
        for (std::size_t i = 0; i < value.size(); ++i) {
            if (value[i] != '\\' || i + 1 == value.size()) continue;
            value.erase(i, 1);
            if (value[i] != '\'' && value[i] != '"')
                value[i] = corelib::text::getEscapedFromChar(value[i]);
        }
        return value;
    }
    AST::RuleMemberCsequence characterGroup(bool negative, const std::string& text) {
        AST::RuleMemberCsequence out;
        std::size_t i = 0;
        out.negative = negative;
        while (i < text.size()) {
            if (text[i] == '\\' && i + 1 < text.size()) {
                out.escaped.push_back(text[i + 1]); i += 2; continue;
            }
            if (i + 2 < text.size() && text[i + 1] == '-') {
                out.diapasons.push_back({text[i], text[i + 2]}); i += 3; continue;
            }
            out.characters.push_back(text[i++]);
        }
        return out;
    }

    // The generated parser uses both Node<Rules, Value> and
    // Node<Rules, shared_ptr<Value>> for recursive rule values.
    // Keep conversion inside Builder through the supplied callback.
    template<typename T, typename Converter>
    auto convertValues(const std::vector<T>& values, Converter&& convert)
        -> stdu::vector<std::shared_ptr<AST::RuleMember>>
    {
        stdu::vector<std::shared_ptr<AST::RuleMember>> result;
        for (const auto& node : values) {
            result.push_back(std::make_shared<AST::RuleMember>(
                convert(payload(node))
            ));
        }
        return result;
    }
    static AST::RegularDataBlock makeAtDataBlock() {
        AST::rvalue rv;
        rv.value = AST::At{};

        AST::CllExprValue value;
        value.value = std::move(rv);

        return AST::make_expr_from_value(value);
    }
}

AST::RuleMember AST::Builder::convertPattern(const Pattern& pattern) {
    AST::RuleMember output;
    std::visit([&](const auto& item) {
        using T = std::decay_t<decltype(item)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            unsupported("empty pattern");
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_STRING>>) {
            output.value = AST::String{unescapeString(payload(item).value)};
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_CGROUP>>) {
            output.value = characterGroup(payload(item).negative == '^', payload(item).v);
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_NOSPACE>>) {
            output.value = AST::RuleMemberNospace{};
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_SPACE>>) {
            unsupported("explicit SPACE pattern (no corresponding legacy AST node)");
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::name>>) {
            const auto& n = payload(item);
            if (!n.temp_params.empty() || !n.param.empty())
                unsupported("parameterized name reference");
            // All declarations have been pre-registered before body conversion.
            // Look up the full reference, first inside this rule, then its parent,
            // and finally the global namespace. Qualified names work too.
            auto path = resolveName(qualifiedName(n));
            output.value = AST::RuleMemberName{path};
        } else if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_group>>>) {
            auto children = convertValues(payload(item).value, [this](const Value& v) { return convertValue(v); });
            output.value = AST::RuleMemberGroup{std::move(children)};
        }
        else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_ANY>>) {
            output.value = AST::RuleMemberAny{};
        }
        else {
            unsupported("dynamic pattern");
        }
    }, pattern.value);
    return output;
}

AST::RuleMember AST::Builder::convertValue(const Value& value) {
    return std::visit([this](const auto& n) -> AST::RuleMember {
        using T = std::decay_t<decltype(n)>;
        if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_one_capture>>>)
            return convertCapture(payload(n));
        else unsupported("region capture or absent rule value");
    }, value.value);
}

AST::RuleMember AST::Builder::convertCapture(const UAST::rule_value_one_capture& value) {
    if (!value.registration.empty()) unsupported("shared counter registration");
    if (!value.v_cap.empty() && !value.ast_cap.empty())
        unsupported("combined variable and AST captures");

    AST::RuleMember output = convertPattern(payload(value.val));
    // TODO
    // if (!value.v_cap.empty()) {
    //     output.prefix.present = true;
    //     output.prefix.present = true;
    //     output.prefix.name = id(payload(value.v_cap).value);
    // }

    if (!value.ast_cap.empty()) {
        output.prefix.present = true;

        const auto& capture = payload(value.ast_cap);

        if (!capture.value.empty())
            output.prefix.name = id(capture.value);
    }
    if (!value.alts.empty()) {
        AST::RuleMemberOp alternatives;
        auto original = output;
        original.prefix.clear();
        alternatives.options.push_back(std::make_shared<AST::RuleMember>(std::move(original)));
        for (const auto& alt : value.alts) {
            auto next = convertPattern(payload(payload(alt).value));
            alternatives.options.push_back(std::make_shared<AST::RuleMember>(std::move(next)));
        }
        output.value = std::move(alternatives);
    }

    if (!value.quantifier.empty()) {
        const auto& q = payload(value.quantifier);
        if (!q.repetitions.empty()) unsupported("bounded or dynamic repetition");
        if (!q.quantifier.empty()) output.quantifier = payload(q.quantifier).value;
    }
    return output;
}

AST::DataBlock AST::Builder::convertData(
    const UAST::Node<UAST::rule_ast>& data) {
    AST::DataBlock result;
    if (data.empty()) return result;
    const auto& d = payload(data);
    std::visit([&](const auto& item) {
        using T = std::decay_t<decltype(item)>;
        if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_ast_abbr>>) {
            AST::TemplatedDataBlock out;
            out.names.push_back(id(payload(item).f));
            for (const auto& v : payload(item).seq) out.names.push_back(id(v));
            result.value = std::move(out);
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_ast_single_value>>) {
            const auto& single = payload(item);

            using AtNode = UAST::Node<
                UAST::COMMERCIAL_AT
            >;

            if (std::holds_alternative<AtNode>(single.value)) {
                result.value = makeAtDataBlock();
            } else {
                unsupported("single-value expression");
            }
        } else if constexpr (std::is_same_v<
            T,
            UAST::Node<
                UAST::rule_ast_full
            >
        >) {
            unsupported("full AST data block conversion");
        } else if constexpr (std::is_same_v<T, std::monostate>) {
            // absent data block
        }
    }, d.value);
    return result;
}

void AST::Builder::convertRule(const Rule& rule) {
    AST::Rule output;
    output.rule_members = convertValues(rule.v, [this](const Value& v) { return convertValue(v); });
    output.data_block = convertData(rule.ast_pointer);
    output.isTopLevel = fullname.size() == 1;
    std::cerr << "[BOOTSTRAP] Rule: ";

    for (const auto& part : fullname)
        std::cerr << part << "::";

    std::cerr
        << " members=" << output.rule_members.size()
        << " datablock=" << output.data_block.value.index()
        << " nested=" << rule.nested.size()
        << '\n';
    auto declared = tree_map.find(fullname);
    if (declared == tree_map.end())
        throw std::runtime_error("ISPA bootstrap: conversion of undeclared grammar rule");
    declared->second = std::move(output);

    // convertGrammar() owns exactly one scope push/pop per declaration.
    for (const auto& nested : rule.nested) {
        const auto& grammar = payload(payload(nested).value);
        convertGrammar(grammar);
    }

}
// "rule.value" / "rule::value" / {"rule","value"} -> {"rule","value"}
AST::Name AST::Builder::normalizeReference(const AST::Name& reference) {
    AST::Name out;
    for (const auto& part : reference) {
        std::string cur;
        auto flush = [&] { if (!cur.empty()) { out.push_back(cur); cur.clear(); } };
        for (char c : part) {
            if (c == '.' || c == ':') flush();
            else cur += c;
        }
        flush();
    }
    return out;
}

std::string AST::Builder::printable(const AST::Name& parts) {
    std::string result;
    for (const auto& p : parts) {
        if (!result.empty()) result += "::";
        result += p;
    }
    return result;
}

// Lexical lookup: innermost scope -> enclosing scopes -> global.
std::optional<AST::Name> AST::Builder::tryResolve(const AST::Name& ref) const {
    for (std::size_t depth = fullname.size(); ; --depth) {
        AST::Name candidate(fullname.begin(), fullname.begin() + depth);
        candidate.insert(candidate.end(), ref.begin(), ref.end());
        if (tree_map.find(candidate) != tree_map.end())
            return candidate;
        if (depth == 0) break;
    }

    // Optional, deliberate fallback: unique suffix match anywhere in the tree,
    // so `value` written outside `rule` still finds `rule::value`.
    // Remove this block if you want strict lexical scoping.
    std::optional<AST::Name> found;
    for (const auto& [key, _] : tree_map) {
        if (key.size() < ref.size()) continue;
        if (!std::equal(ref.begin(), ref.end(), key.end() - ref.size())) continue;
        if (found) return std::nullopt;   // ambiguous: refuse to guess
        found = key;
    }
    return found;
}

AST::Name AST::Builder::resolveName(const AST::Name& rawReference) const {
    const AST::Name reference = normalizeReference(rawReference);
    if (reference.empty())
        throw std::runtime_error("ISPA bootstrap: empty rule reference");

    if (auto r = tryResolve(reference)) return *r;

    if (!allowDeferredReferences)   // set true only while multi-module linking
        throw std::runtime_error(
            "ISPA: unresolved reference '" + printable(reference) +
            "' from scope '" + printable(fullname) + "'");

    std::cerr << "[BOOTSTRAP] Deferred reference '" << printable(reference)
              << "' from '" << printable(fullname) << "'\n";
    return reference;
}

void AST::Builder::predeclareGrammar(const Grammar& grammar) {
    const auto path = qualifiedName(payload(grammar.name));

    if (path.size() != 1)
        unsupported("qualified grammar declaration");

    fullname.push_back(path.front());

    const auto [it, inserted] =
        tree_map.emplace(fullname, AST::Rule{});

    if (!inserted) {
        throw std::runtime_error(
            "ISPA bootstrap: duplicate grammar declaration: " +
            printable(fullname)
        );
    }

    using OrdinaryNode =
        UAST::Node<std::shared_ptr<Rule>>;

    if (const auto* ordinary =
        std::get_if<OrdinaryNode>(&grammar.entry)) {

        for (const auto& nested : payload(*ordinary).nested) {
            predeclareGrammar(payload(payload(nested).value));
        }
    }

    fullname.pop_back();
}

void AST::Builder::convertGrammar(const Grammar& grammar) {
    // TODO: grammar modifiers and parameter declarations are not lowered yet.
    const auto path = qualifiedName(payload(grammar.name));
    if (path.size() != 1) unsupported("qualified grammar declaration");
    fullname.push_back(path.front());

    using OrdinaryNode = UAST::Node<std::shared_ptr<Rule>>;
    if (const auto* ordinary = std::get_if<OrdinaryNode>(&grammar.entry)) {
        convertRule(payload(*ordinary));
    } else {
        // TODO: advanced grammar bodies; intentionally not generated.
    }
    fullname.pop_back();
}

void AST::Builder::convertMain(const UAST::main& main) {
    for (const auto& entry : main.value) {
        std::visit([&](const auto& value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, UAST::Node<UAST::grammar>>) {
                convertGrammar(payload(value));
            } else if constexpr (std::is_same_v<T, UAST::Node<UAST::fail_block>>) {
                // Placeholder: failure handlers do not participate in the grammar tree.
            }
        }, entry);
    }
}

void AST::Builder::build() {
    if (!root) throw std::runtime_error("ISPA bootstrap: no parse root");
    tree_map.clear();
    fullname.clear();

    // Pass 1: symbol table across all top-level and nested rule declarations.
    for (const auto& entry : root->value) {
        std::visit([this](const auto& value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T,
                UAST::Node<UAST::grammar>>) {
                predeclareGrammar(payload(value));
            }
        }, entry);
    }

    // Pass 2: convert bodies with a complete declaration table.
    // All forward references, including later top-level rules and nested
    // siblings, must already have entries in tree_map.
    fullname.clear();
    convertMain(*root);
}
