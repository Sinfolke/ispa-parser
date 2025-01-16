#include <convertion.h>
auto getFunction(dlib& converter, const char* name) {
    return converter.loadfun<void, use_prop_t&, std::string&, Parser::Rule>(name);
}
void processFunction(const char* funName, dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto function = getFunction(converter, funName);
    function(use_prop, buf, member);
}


void processRule(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    auto data = std::any_cast<obj_t>(member.data);
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    for (const auto& member : rules) {
        processFunction("on_rule", converter, use_prop, buf, member);

        auto exact_member = std::any_cast<obj_t>(member.data);
        auto exact_member_val = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "val"));
        auto exact_member_qualifier = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "qualifier"));
        switch (exact_member_val.name)
        {
            case Parser::Rules::Rule_group:
                process_Rule_group(converter, use_prop, buf, member);
                break;
            case Parser::Rules::Rule_csequence:
                process_Rule_csequence(converter, use_prop, buf, member);
                break;
            case Parser::Rules::string:
                process_string(converter, use_prop, buf, member);
                break;
            case Parser::Rules::accessor:
                process_accessor(converter, use_prop, buf, member);
            case Parser::Rules::Rule_hex:
                process_Rule_hex(converter, use_prop, buf, member);
            case Parser::Rules::Rule_bin:
                process_Rule_bin(converter, use_prop, buf, member);
            case Parser::Rules::Rule_other:
                process_Rule_other(converter, use_prop, buf, member);
            case Parser::Rules::Rule_escaped:
                process_Rule_escaped(converter, use_prop, buf, member);
            case Parser::Rules::Rule_any:
                process_Rule_any(converter, use_prop, buf, member);
            case Parser::Rules::Rule_op:
                process_Rule_op(converter, use_prop, buf, member);
            case Parser::Rules::cll:
                process_cll(converter, use_prop, buf, member);
            case Parser::Rules::linear_comment:
                continue;
            default:
                throw Error("Processing undefined rule %s", Parser::RulesToString(exact_member_val.name));
        }
        
    }
}
void process_Rule_group(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_group", converter, use_prop, buf, member);
    auto data = std::any_cast<obj_t> (member.data);
    std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, ""));
    processRule(converter, use_prop, buf, member);
}
void process_Rule_csequence(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_csequence", converter, use_prop, buf, member);
    auto data = std::any_cast<arr_t<Parser::Rule>>(member.data);
    for (const auto &el : data) {
        switch (el.name) {
            case Parser::Rules::Rule_csequence_diapason:
                processFunction("on_Rule_csequence_diapason", converter, use_prop, buf, member);
                break;
            case Parser::Rules::Rule_csequence_escape:
                processFunction("on_Rule_csequence_escape", converter, use_prop, buf, member);
                break;
            case Parser::Rules::Rule_csequence_symbol:
                processFunction("on_Rule_csequence_escape", converter, use_prop, buf, member);
                break;
            default:
                throw Error("Undefined subrule '%s' in process_Rule_csequence", Parser::RulesToString(el.name));
        }
    }
}
void process_accessor(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    auto data = std::any_cast<obj_t>(member.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    second.insert(second.begin(), first);
    for (auto &el : second) {
        auto el_data = std::any_cast<Parser::Rule>(el.data);
        switch (el_data.name) {
            case Parser::Rules::accessors_char:
                processFunction("on_accessor_char", converter, use_prop, buf, member);
                break;
            case Parser::Rules::accessors_element:
                processFunction("on_accessor_element", converter, use_prop, buf, member);
                break;
            case Parser::Rules::accessors_group:
                processFunction("on_accessor_group", converter, use_prop, buf, member);
                break;
            default:
                throw Error("Undefined accessor kind '%s' in process_Rule_accessor", Parser::RulesToString(el.name));
        }
    }
};
void process_Rule_hex(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_hex", converter, use_prop, buf, member);
}
void process_Rule_bin(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_bin", converter, use_prop, buf, member);
}
void process_Rule_other(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_other", converter, use_prop, buf, member);
}
void process_Rule_escaped(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_escaped", converter, use_prop, buf, member);

    auto data = std::any_cast<obj_t>(member.data);
    process_number(converter, use_prop, buf, std::any_cast<Parser::Rule>(corelib::map::get(data, "num")));
}
void process_Rule_any(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_any", converter, use_prop, buf, member);
}
void process_Rule_op(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_op", converter, use_prop, buf, member);
}
void process_cll(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_cll", converter, use_prop, buf, member);
}
void process_string(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_string", converter, use_prop, buf, member);
};
void process_number(use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_number", converter, use_prop, buf, member);
}

std::string convert(Parser::Tree& tree, dlib& converter) {
    std::string buf; // a buffer where the output will be storred
    use_prop_t use_prop;
    for (const auto& member : tree) {
        if (member.name == Parser::Rules::use) {
            auto data = std::any_cast<arr_t<Parser::Rule>>(member.data);
            for (const auto& el : data) {
                auto el_data = std::any_cast<obj_t>(el.data);
                auto el_name = std::any_cast<Parser::Rule> (corelib::map::get(el_data, "name"));
                use_prop[std::any_cast<std::string> (el_name.data)] = std::any_cast<Parser::Rule> (corelib::map::get(el_data, "value"));
            }
        }
    }
    for (int i = 0; i < tree.size(); i++) {
        auto member = tree[i];
        switch (member.name) {
            case Parser::Rules::Rule:
                processFunction("on_Rule", converter, use_prop, buf, member);
                processRule(converter, use_prop, buf, member);
                break;
        }
    }
    return buf;
}