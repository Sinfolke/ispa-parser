#include <convertion.h>
auto getFunction(dlib& converter, const char* name) {
    return converter.loadfun<void, Parser::Tree, int, use_prop_t, std::string&, Parser::Rule>(name);
}
void processFunction(const char* funName, Parser::Tree &tree, int& i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    auto function = getFunction(converter, funName);
    function(tree, i, use_prop, buf, member);
}


void processRule(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    auto data = std::any_cast<obj_t>(member.data);
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    for (const auto& member : rules) {
        processFunction("on_rule", tree, i, use_prop, buf, member, converter);

        auto exact_member = std::any_cast<obj_t>(member.data);
        auto exact_member_val = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "val"));
        auto exact_member_qualifier = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "qualifier"));
        switch (exact_member_val.name)
        {
            case Parser::Rules::Rule_group:
                process_Rule_group(tree, i, use_prop, buf, member, converter);
                break;
            case Parser::Rules::Rule_csequence:
                process_Rule_csequence(tree, i, use_prop, buf, member, converter);
                break;
            case Parser::Rules::string:
                process_string(tree, i, use_prop, buf, member, converter);
                break;
            case Parser::Rules::accessor:
                process_accessor(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::Rule_hex:
                process_Rule_hex(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::Rule_bin:
                process_Rule_bin(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::Rule_other:
                process_Rule_other(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::Rule_escaped:
                process_Rule_escaped(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::Rule_any:
                process_Rule_any(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::Rule_op:
                process_Rule_op(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::cll:
                process_cll(tree, i, use_prop, buf, member, converter);
            case Parser::Rules::linear_comment:
                continue;
            default:
                throw Error("Processing undefined rule %s", Parser::RulesToString(exact_member_val.name));
        }
        
    }
}
void process_Rule_group(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_group", tree, i, use_prop, buf, member, converter);
    auto data = std::any_cast<obj_t> (member.data);
    std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, ""));
    processRule(tree, i, use_prop, buf, member, converter);
}
void process_Rule_csequence(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_csequence", tree, i, use_prop, buf, member, converter);
    auto data = std::any_cast<arr_t<Parser::Rule>>(member.data);
    for (const auto &el : data) {
        switch (el.name) {
            case Parser::Rules::Rule_csequence_diapason:
                processFunction("on_Rule_csequence_diapason", tree, i, use_prop, buf, member, converter);
                break;
            case Parser::Rules::Rule_csequence_escape:
                processFunction("on_Rule_csequence_escape", tree, i, use_prop, buf, member, converter);
                break;
            case Parser::Rules::Rule_csequence_symbol:
                processFunction("on_Rule_csequence_escape", tree, i, use_prop, buf, member, converter);
                break;
            default:
                throw Error("Undefined subrule '%s' in process_Rule_csequence", Parser::RulesToString(el.name));
        }
    }
}
void process_accessor(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    auto data = std::any_cast<obj_t>(member.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    second.insert(second.begin(), first);
    for (auto &el : second) {
        auto el_data = std::any_cast<Parser::Rule>(el.data);
        switch (el_data.name) {
            case Parser::Rules::accessors_char:
                processFunction("on_accessor_char", tree, i, use_prop, buf, member, converter);
                break;
            case Parser::Rules::accessors_element:
                processFunction("on_accessor_element", tree, i, use_prop, buf, member, converter);
                break;
            case Parser::Rules::accessors_group:
                processFunction("on_accessor_group", tree, i, use_prop, buf, member, converter);
                break;
            default:
                throw Error("Undefined accessor kind '%s' in process_Rule_accessor", Parser::RulesToString(el.name));
        }
    }
};
void process_Rule_hex(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_hex", tree, i, use_prop, buf, member, converter);
}
void process_Rule_bin(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_bin", tree, i, use_prop, buf, member, converter);
}
void process_Rule_other(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_other", tree, i, use_prop, buf, member, converter);
}
void process_Rule_escaped(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_escaped", tree, i, use_prop, buf, member, converter);

    auto data = std::any_cast<obj_t>(member.data);
    process_number(tree, i, use_prop, buf, std::any_cast<Parser::Rule>(corelib::map::get(data, "num")), converter);
}
void process_Rule_any(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_any", tree, i, use_prop, buf, member, converter);
}
void process_Rule_op(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_Rule_op", tree, i, use_prop, buf, member, converter);
}
void process_cll(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_cll", tree, i, use_prop, buf, member, converter);
}
void process_string(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_string", tree, i, use_prop, buf, member, converter);
};
void process_number(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter) {
    processFunction("on_number", tree, i, use_prop, buf, member, converter);
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
                processFunction("on_Rule", tree, i, use_prop, buf, member, converter);
                processRule(tree, i, use_prop, buf, member, converter);
                break;
        }
    }
    return buf;
}