
#include <list>
#include <IR.h>
#include <string>
#include <list>
#include <any>
#include <logging.h>
#include <converter.h>
std::string createNamespace(use_prop_t use) {
    std::string res = "namespace ";
    res += std::any_cast<std::string>(use["name"].data);
    res += " {\n";
    return res;
}
void writeEnum(std::string &res, std::list<std::string> enm) {
    res += "\t\t";
    for (auto el : enm) {
        res += el;
        res += ", ";
    }
    if (res.size())
        res.erase(res.size() - 2);

    res += "\n\t};\n";
}
std::string createTokensEnum(std::list<std::string> tokens) {
    std::string res = "\tenum class Tokens {\n";
    writeEnum(res, tokens);
    return res;
}
std::string createRulesEnum(std::list<std::string> rules) {
    std::string res = "\tenum class Rules {\n";
    writeEnum(res, rules);
    return res;
}
std::string create_tokenizator_header(std::list<std::string> tokens) {
    std::string res = "\tclass Tokenizator {\n\t\tpublic:\n";
    for (auto name : tokens) {
        res += "\t\t\tToken_res " + name + "(const char*);\n";
    }
    res += "\t};\n";
    return res;
}
std::string create_parser_header(std::list<std::string> tokens) {
    std::string res = "\tclass Parser {\n\t\tpublic:\n";
    for (auto name : tokens) {
        res += "\t\t\tRule_res " + name + "(Token*);\n";
    }
    res += "\t};\n";
    return res;
}
extern "C" std::string convert_header(std::list<std::string> tokens, std::list<std::string> rules, use_prop_t use) {
    std::string res;
    res += createNamespace(use);
    res += createTokensEnum(tokens);
    res += createRulesEnum(rules);
    res += create_tokenizator_header(tokens);
    res += create_parser_header(rules);
    res += "\n}"; // close enum
    return res;
}