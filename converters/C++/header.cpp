
#include <list>
#include <IR.h>
#include <logging.h>
#include <converter.h>
std::string createNamespace(use_prop_t use) {
    std::string res = "namespace ";
    res += std::any_cast<std::string>(use["name"].data);
    res += "{\n";
    return res;
}
void writeEnum(std::string &res, std::list<std::string> enm) {
    for (auto el : enm) {
        res += el;
        res += ", ";
    }
    if (res.size()) {
        res[res.size() - 2] = '\n'; // replace comma with newline
        res.back() = '}';
        res.insert(res.size() - 2, "\t");
    } else {
        res += "\n\t}\n";
    }
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
extern "C" std::string convert_header(std::list<std::string> tokens, std::list<std::string> rules, use_prop_t use) {
    std::string res;
    res += createNamespace(use);
    res += createTokensEnum(tokens);
    res += createRulesEnum(rules);
    return res;
}