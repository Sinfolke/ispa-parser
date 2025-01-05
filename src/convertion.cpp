#include <convertion.h>
auto getFunction(dlib& converter, const char* name) {
    return converter.loadfun<std::string, Parser::Tree, int, Parser::Rule>(name);
}
std::string processFunction(const char* funName, Parser::Tree& tree, int& i, Parser::Rule member, dlib& converter, std::string& result) {
    auto function = getFunction(converter, funName);
    std::string res = function(tree, i, member);
    return res;
}
std::string processRule(Parser::Rule& member) {
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
                processFunction("on_Rule", tree, i, member, converter, result);
                result += processRule(member);
                break;
        }
    }
    return result;
}