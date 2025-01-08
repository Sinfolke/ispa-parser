#include <convertion.h>
auto getFunction(dlib& converter, const char* name) {
    return converter.loadfun<std::string, Parser::Tree, int, use_prop_t, Parser::Rule>(name);
}
std::string processFunction(const char* funName, Parser::Tree &tree, int& i, use_prop_t &use_prop, Parser::Rule member, dlib &converter) {
    auto function = getFunction(converter, funName);
    std::string res = function(tree, i, use_prop, member);
    return res;
}


std::string processRule(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter) {
    auto data = std::any_cast<obj_t>(member.data);
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    for (const auto& member : rules) {
        processFunction("on_rule", tree, i, use_prop, member, converter);

        auto exact_member = std::any_cast<obj_t>(member.data);
        auto exact_member_val = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "val"));
        auto exact_member_qualifier = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "qualifier"));
        switch (exact_member_val.name)
        {
            case Parser::Rules::Rule_group:
                process_Rule_group(tree, i, use_prop, member, converter);
                break;
            case Parser::Rules::Rule_csequence:
                process_Rule_csequence(tree, i, use_prop, member, converter);
                break;
            case Parser::Rules::string:
                process_string(tree, i, use_prop, member, converter);
                break;
            case Parser::Rules::accessor:
                process_accessor();
            case Parser::Rules::Rule_hex:
                process_Rule_hex();
            case Parser::Rules::Rule_bin:
                process_Rule_bin();
            case Parser::Rules::other:
                process_Rule_other();
            case Parser::Rules::Rule_escaped:
                process_Rule_escaped();
            case Parser::Rules::Rule_any:
                process_Rule_any();
            case Parser::Rule::op:
                process_Rule_op();
            case Parser::Rules::cll:
                process_Rule_cll();
            case Parser::Rules::linear_comment:
                continue;
            default:
                throw Error("Processing undefined rule %s", Parser::RulesToString(exact_member_val.name));
        }
        
    }
    return "null";
}
std::string process_Rule_group(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter) {
    std::string res = processFunction("on_Rule_group", tree, i, use_prop, member, converter);
    auto data = std::any_cast<obj_t> (member.data);
    std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, ""));
    res += processRule(tree, i, use_prop, member, converter);
    return res;
}
std::string process_Rule_csequence(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter) {
    std::string res = processFunction("on_Rule_csequence", tree, i, use_prop, member, converter);
    auto data = std::any_cast<arr_t<Parser::Rule>>(member.data);
    for (const auto &el : data) {
        switch (el.name) {
            case Parser::Rules::Rule_csequence_diapason:
                res += processFunction("on_Rule_csequence_diapason", tree, i, use_prop, member, converter);
                break;
            case Parser::Rules::Rule_csequence_escape:
                res += processFunction("on_Rule_csequence_escape", tree, i, use_prop, member, converter);
                break;
            case Parser::Rules::Rule_csequence_symbol:
                res += processFunction("on_Rule_csequence_escape", tree, i, use_prop, member, converter);
                break;
            default:
                throw Error("Undefined subrule in process_Rule_csequence");
        }
    }
    return res;
}
std::string process_string(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter) {
    std::string res = processFunction("on_string", tree, i, use_prop, member, converter);
    return res;
};
std::string process_Rule_accessor(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter) {
    auto data = std::any_cast<obj_t>(member.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    std::string res = processFunction("on_accessor", tree, i, use_prop, member, converter);
    return res;
};
std::string convert(Parser::Tree& tree, dlib& converter) {
    std::string result;
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
                processFunction("on_Rule", tree, i, use_prop, member, converter);
                result += processRule(tree, i, use_prop, member, converter);
                break;
        }
    }
    return result;
}