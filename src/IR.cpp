#include <IR.h>
#include <internal_types.h>
#include <corelib.h>
#include <parser.h>
// a structure used to cout
void IR::ir::add(IR::ir repr) {
    elements.insert(elements.end(), repr.elements.begin(), repr.elements.end());
}
void IR::ir::push(IR::member member) {
    elements.push_back(member);
}
size_t getElementByAccessor(arr_t<size_t> &elements, size_t index) {
    return elements[index];
}
size_t getGroupedElementByAccessor(arr_t<size_t> &elements, arr_t<size_t> &groups, size_t index) {
    return elements[groups[index]];
}
size_t getGroupedElementByAccessor(arr_t<size_t> &elements, arr_t<size_t> &groups, size_t group_index, size_t index) {
    return elements[groups[group_index] + index];
}
IR::ir ruleToIr(Parser::Rule &rule_rule, IR::ir &member, arr_t<size_t> &elements, arr_t<size_t> &groups) {
    member.elements.push_back(IR::member{ IR::types::RULE, });

    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));


    switch (rule.name) {
        case Parser::Rules::Rule_group: 
        {
            groups.push_back(member.elements.size() + 1);
            auto data = std::any_cast<obj_t>(rule.data);

            // Extract variables within this block to avoid scope conflicts.
            auto variable = std::any_cast<Parser::Rule>(corelib::map::get(data, "variable"));
            auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
            auto var_rule = std::any_cast<Parser::Rule>(variable.data);

            IR::ir values = rulesToIr(val);
            IR::member var = {
                IR::types::VARIABLE,
                var_rule,
                values.elements.size(),
            };
            member.push(var);
            member.add(values);
            break;
        }
        case Parser::Rules::Rule_csequence:
        {
            elements.push_back(rule);
            auto data = std::any_cast<obj_t>(rule.data);
            auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
            auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
            arr_t<IR::cond_unit> expr;
            bool first = true;
            for (auto &value : values) {
                if (first) {
                    expr.push_back({IR::condition::GROUP_OPEN});
                    if (_not) {
                        expr.push_back({IR::condition::NOT});
                        expr.push_back({IR::condition::GROUP_OPEN});
                    }
                } else {
                    expr.push_back({IR::condition::AND});
                }
                switch (value.name) {
                    case Parser::Rules::Rule_csequence_diapason:
                    {
                        auto data = std::any_cast<arr_t<char>>(value.data);
                        expr.push_back({IR::condition::GROUP_OPEN});
                        expr.push_back({IR::condition::ACCESSOR, 0, Parser::Rules::accessors_char});
                        expr.push_back({IR::condition::HIGHER_OR_EQUAL});
                        expr.push_back({IR::condition::CHARACTER, data[0]});
                        expr.push_back({IR::condition::AND});
                        expr.push_back({IR::condition::ACCESSOR, 0, Parser::Rules::accessors_char});
                        expr.push_back({IR::condition::HIGHER_OR_EQUAL});
                        expr.push_back({IR::condition::CHARACTER, data[1]});
                        expr.push_back({IR::condition::GROUP_CLOSE});
                        break;
                    }
                    default:
                    {
                        if (value.name != Parser::Rules::Rule_csequence_escape && value.name != Parser::Rules::Rule_csequence_symbol)
                            throw Error("undefined csequence subrule");
                        auto data = std::any_cast<std::string>(value.data);
                        expr.push_back({IR::condition::ACCESSOR, 0, Parser::Rules::accessors_char});
                        expr.push_back({IR::condition::EQUAL});
                        expr.push_back({IR::condition::CHARACTER, data});
                    }
                }
            }
            expr.push_back({IR::condition::GROUP_CLOSE});
            if (_not)
                expr.push_back({IR::condition::GROUP_CLOSE});
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
        }
        case Parser::Rules::string:
        {
            auto data = std::any_cast<std::string>(rule.data);
            arr_t<IR::cond_unit> expr = {
                {IR::condition::ACCESSOR_STRING, 0, Parser::Rules::accessors_char}, {IR::condition::EQUAL}, {IR::condition::STRING, data}
            };
            auto mem = IR::member {
                IR::types::IF,
                expr
            };
            member.push(mem);
        }
        case Parser::Rules::accessor:
            
        default:
            throw Error("Converting undefined rule");
    }

    return member;
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules) {
    IR::ir result;
    arr_t<size_t> elements;
    arr_t<size_t> groups;
    for (auto &rule : rules) {
        ruleToIr(rule, result, elements, groups);
    }
    return result;
}
IR::ir treeToIr(Parser::Tree &tree) {
    IR::ir result_ir;
    for (auto &el : tree) {
        if (el.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(el.data);
        auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
        result_ir.add(rulesToIr(rules));
    }
    return result_ir;
}