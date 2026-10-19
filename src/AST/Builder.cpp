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
    AST::SourcePosition position(const UAST::SourcePosition& p) {
        return {p.file, p.offset, p.length, p.line, p.column};
    }
    AST::PythonNode python(const UAST::PythonNode& n) {
        AST::PythonNode out{n.kind, n.field, n.scalar, position(n.position), n.absent, {}};
        for (const auto& child : n.children) out.children.push_back(python(child));
        return out;
    }
    template<class Params> stdu::vector<std::string> parameters(const Params& p) {
        stdu::vector<std::string> out;
        if (p.empty() || payload(p).value.empty()) return out;
        const auto& args = payload(payload(p).value);
        if (!args.first_p.empty()) out.push_back(id(args.first_p));
        for (const auto& arg : args.following_p) out.push_back(id(arg));
        return out;
    }
    template<class T> AST::PythonAction action(const T& n, const UAST::SourcePosition& p) {
        AST::PythonAction out{python(n.python), {}, position(p)};
        for (const auto& binding : n.bindings) out.bindings.push_back({binding.name, binding.optional, binding.list});
        return out;
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
            output.features.push_back(AST::SpacePattern{position(item.position)});
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::name>>) {
            const auto& n = payload(item);
            if (!n.temp_params.empty() || !n.param.empty())
                output.features.push_back(AST::DeclarationSyntax{{}, parameters(n.param), parameters(n.temp_params), position(item.position)});
            // Resolve references after all declarations have been collected.
            auto path = qualifiedName(n);
            output.value = AST::RuleMemberName{path};
        } else if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_group>>>) {
            auto children = convertValues(payload(item).value, [this](const Value& v) { return convertValue(v); });
            output.value = AST::RuleMemberGroup{std::move(children)};
        }
        else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_ANY>>) {
            output.value = AST::RuleMemberAny{};
        }
        else {
            AST::DynamicPattern dynamic;
            dynamic.position = position(item.position);
            std::visit([&](const auto& n) {
                using D = std::decay_t<decltype(n)>;
                if constexpr (std::is_same_v<D, UAST::Node<UAST::ID>>) dynamic.name = id(n);
                else if constexpr (!std::is_same_v<D, std::monostate>) dynamic.expression = action(payload(payload(n).value), payload(n).value.position);
            }, payload(item).value);
            output.features.push_back(std::move(dynamic));
        }
    }, pattern.value);
    return output;
}

AST::RuleMember AST::Builder::convertValue(const Value& value) {
    return std::visit([this](const auto& n) -> AST::RuleMember {
        using T = std::decay_t<decltype(n)>;
        if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_one_capture>>>)
            return convertCapture(payload(n));
        else if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_mul_capture>>>) {
            AST::RuleMember out;
            out.position = position(n.position);
            AST::RuleMemberGroup group;
            for (const auto& c : payload(n).cap)
                group.values.push_back(std::make_shared<AST::RuleMember>(convertCapture(payload(c))));
            out.value = std::move(group);
            const char kind = std::holds_alternative<UAST::Node<UAST::COMMERCIAL_AT>>(payload(n).type) ? '@' : '%';
            out.features.push_back(AST::RegionCapture{kind, out.position});
            return out;
        } else unsupported("absent rule value");
    }, value.value);
}

AST::RuleMember AST::Builder::convertCapture(const UAST::rule_value_one_capture& value) {
    AST::RuleMember output = convertPattern(payload(value.val));
    output.position = position(value.val.position);
    auto patternFeatures = std::move(output.features);
    output.features.clear();
    if (!value.registration.empty())
        output.features.push_back(AST::SharedCounterRegistration{id(payload(value.registration).value), position(value.registration.position)});
    if (!value.v_cap.empty())
        output.features.push_back(AST::VariableCapture{id(payload(value.v_cap).value), position(value.v_cap.position)});
    if (!value.fail_cap.empty()) {
        AST::FailMarker marker;
        marker.position = position(value.fail_cap.position);
        const auto& n = payload(value.fail_cap).value;
        if (!n.empty()) { marker.name = qualifiedName(payload(n)); marker.parameters = parameters(payload(n).param); }
        output.features.push_back(std::move(marker));
    }

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
        original.features = std::move(patternFeatures);
        alternatives.options.push_back(std::make_shared<AST::RuleMember>(std::move(original)));
        for (const auto& alt : value.alts) {
            auto next = convertPattern(payload(payload(alt).value));
            alternatives.options.push_back(std::make_shared<AST::RuleMember>(std::move(next)));
        }
        output.value = std::move(alternatives);
    } else {
        output.features.insert(output.features.begin(), patternFeatures.begin(), patternFeatures.end());
    }

    if (!value.quantifier.empty()) {
        const auto& q = payload(value.quantifier);
        if (!q.repetitions.empty()) {
            AST::Counter counter;
            counter.position = position(q.repetitions.position);
            std::visit([&](const auto& n) {
                using T = std::decay_t<decltype(n)>;
                if constexpr (std::is_same_v<T, UAST::Node<UAST::ID>>) { counter.kind = "name"; counter.bound = id(n); }
                else if constexpr (std::is_same_v<T, UAST::Node<UAST::NUMBER>>) { counter.kind = "number"; counter.bound = payload(n).full; if (!payload(n).floating.empty()) counter.bound += "." + payload(n).floating; }
                else if constexpr (std::is_same_v<T, UAST::Node<UAST::expr>>) { counter.kind = "expression"; counter.expression = action(payload(n), n.position); }
            }, payload(q.repetitions).value);
            output.features.push_back(std::move(counter));
        }
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
                const auto& expression = std::get<UAST::Node<UAST::expr>>(single.value);
                rule_features.push_back(action(payload(expression), expression.position));
            }
        } else if constexpr (std::is_same_v<
            T,
            UAST::Node<
                UAST::rule_ast_full
            >
        >) {
            for (const auto& part : payload(item).value) {
                auto a = action(payload(payload(part).e), part.position);
                a.target = id(payload(part).key);
                rule_features.push_back(std::move(a));
            }
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
    output.features = std::move(rule_features);
    rule_features.clear();
    if (!rule.fail_pointer.empty()) {
        AST::FailBinding binding;
        binding.position = position(rule.fail_pointer.position);
        binding.names.push_back(id(payload(rule.fail_pointer).f));
        for (const auto& n : payload(rule.fail_pointer).seq) binding.names.push_back(id(n));
        output.features.push_back(std::move(binding));
    }
    output.isTopLevel = fullname.size() == 1;
    tree_map[fullname] = std::move(output);

    // convertGrammar() owns exactly one scope push/pop per declaration.
    for (const auto& nested : rule.nested) {
        const auto& grammar = payload(payload(nested).value);
        convertGrammar(grammar);
    }

}
void AST::Builder::convertGrammar(const Grammar& grammar) {
    const auto path = qualifiedName(payload(grammar.name));
    const auto scopeSize = fullname.size();
    fullname.insert(fullname.end(), path.begin(), path.end());

    AST::DeclarationSyntax declaration;
    declaration.position = position(grammar.name.position);
    declaration.parameters = parameters(payload(grammar.name).param);
    declaration.templateParameters = parameters(payload(grammar.name).temp_params);
    for (const auto& mod : grammar.mod) declaration.modifiers.push_back(payload(payload(mod).value).value);
    if (!declaration.modifiers.empty() || !declaration.parameters.empty() || !declaration.templateParameters.empty())
        rule_features.push_back(std::move(declaration));
    using OrdinaryNode = UAST::Node<std::shared_ptr<Rule>>;
    if (const auto* ordinary = std::get_if<OrdinaryNode>(&grammar.entry)) {
        convertRule(payload(*ordinary));
    } else {
        AST::Rule out;
        out.features = std::move(rule_features);
        rule_features.clear();
        const auto& advanced = std::get<UAST::Node<UAST::advanced_rule>>(grammar.entry);
        out.features.push_back(AST::AdvancedRule{python(UAST::describe(payload(advanced), advanced.position)), position(advanced.position)});
        for (const auto& entry : payload(advanced).body) {
            if (const auto* statement = std::get_if<UAST::Node<UAST::stmt>>(&entry))
                out.features.push_back(action(payload(*statement), statement->position));
        }
        tree_map[fullname] = std::move(out);
    }
    tree_map.at(fullname).position = position(grammar.name.position);
    fullname.resize(scopeSize);
}

void AST::Builder::convertMain(const UAST::main& main) {
    for (const auto& entry : main.value) {
        std::visit([&](const auto& value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, UAST::Node<UAST::grammar>>) {
                convertGrammar(payload(value));
            } else if constexpr (std::is_same_v<T, UAST::Node<UAST::fail_block>>) {
                const auto& block = payload(value);
                const auto& n = payload(block.name);
                fail_blocks.push_back(AST::FailBlock{qualifiedName(n), parameters(n.param), action(payload(block.val), block.val.position), position(value.position)});
            }
        }, entry);
    }
}

void AST::Builder::build() {
    tree_map.clear();
    fail_blocks.clear();
    rule_features.clear();
    fullname.clear();

    convertMain(input);

    // Search the containing rule and then its enclosing scopes using the
    // entire reference path. Never fall back to a matching final segment:
    // rule.ast must not accidentally bind to a global ast declaration.
    for (auto& [scope, rule] : tree_map) {
        const auto resolve = [&](const auto& self, AST::RuleMember& member) -> void {
            if (member.isName()) {
                auto& reference = member.getName().name;
                for (std::size_t size = scope.size();; --size) {
                    stdu::vector<std::string> candidate(scope.begin(), scope.begin() + size);
                    candidate.insert(candidate.end(), reference.begin(), reference.end());
                    if (tree_map.contains(candidate)) {
                        reference = std::move(candidate);
                        break;
                    }
                    if (size == 0) break;
                }
            } else if (member.isGroup()) {
                for (auto& child : member.getGroup().values) self(self, *child);
            } else if (member.isOp()) {
                for (auto& child : member.getOp().options) self(self, *child);
            }
        };
        for (auto& member : rule.rule_members) resolve(resolve, *member);
    }
}
