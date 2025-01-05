#include <convertion.h>
#include <parser.h>
#include <cpuf/dlib.h>
#include <ostream>
#include <sstream>
auto getFunction(dlib& converter, const char* name) {
    return converter.loadfun<std::string, Parser::Tree, int, Parser::Rule>(name);
}
std::string processFunction(const char* funName, Parser::Tree& tree, int& i, Parser::Rule member, dlib& converter, std::stringstream& result) {
    auto function = getFunction(converter, funName);
    std::string res = function(tree, i, member);
    result << res;
}
std::string convert(Parser::Tree& tree, dlib& converter) {
    std::stringstream result;
    for (int i = 0; i < tree.size(); i++) {
        auto member = tree[i];
        switch (member.name) {
            case Parser::Rules::Rule:
                processFunction("on_Rule", tree, i, member, converter, result);
                result << processRule(member);
                break;
            case Parser::Rules::use:
                processFunction("on_use", tree, i, member, converter, result);
                break;
            // not implementing import
        }

    }
}