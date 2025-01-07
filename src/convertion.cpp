#include <convertion.h>
auto getFunction(dlib& converter, const char* name) {
    return converter.loadfun<std::string, Parser::Tree, int, Parser::Rule>(name);
}
std::string processFunction(const char* funName, Parser::Tree &tree, int& i, Parser::Rule member, dlib &converter) {
    auto function = getFunction(converter, funName);
    std::string res = function(tree, i, member);
    return res;
}


std::string processRule(Parser::Tree &tree, int &i, Parser::Rule member, dlib &converter) {
    auto data = std::any_cast<obj_t>(member.data);
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    auto nested_rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
    for (const auto& member : rules) {
        processFunction("on_rule", tree, i, member, converter);

        auto exact_member = std::any_cast<obj_t>(member.data);
        auto exact_member_val = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "val"));
        auto exact_member_qualifier = std::any_cast<Parser::Rule>(corelib::map::get(exact_member, "qualifier"));
        /*
        switch (exact_member_val.name)
        {
            case Parser::Rules::Rule_group:
                process_Rule_group();
            case Parser::Rules::Rule_csequence:
                process_Rule_csequence();
            case Parser::Rules::string:
                process_string();
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
        */
    }
    return "null";
}
std::string convert(Parser::Tree& tree, dlib& converter) {
    std::string result;
    std::unordered_map<std::string, Parser::Rule> use_prop;
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
                processFunction("on_Rule", tree, i, member, converter);
                result += processRule(tree, i, member, converter);
                break;
        }
    }
    return result;
}