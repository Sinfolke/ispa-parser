#include <any>
#include <sstream>

#include <parser.h>
#include <internal_types.h>
#include <corelib.h>
bool processingToken = false;
std::string on_Rule(Parser::Tree tree, int i, Parser::Rule member) {
    std::stringstream res;
    auto data = std::any_cast<obj_t>(member.data);
    std::string name = std::any_cast<std::string>(std::any_cast<Parser::Rule> (corelib::map::get(data, "name")).data);
    if (corelib::text::startsWithRange(name, 'A', 'Z')) {
        processingToken = true;
        res << "::Parser::Token_result " << name << "(const char* in) {";
    } else {
        processingToken = false;
        res << "::Parser::Rule_result " << name << "(const TokenFlow& flow, int& pos) {";
    }
    return res.str();
}