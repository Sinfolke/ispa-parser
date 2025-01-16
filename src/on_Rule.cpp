#include <any>
#include <sstream>
#include <defs.h>
#include <parser.h>
#include <corelib.h>
EXPORT void on_Rule(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    std::stringstream res;
    auto data = std::any_cast<obj_t>(member.data);
    std::string name = std::any_cast<std::string>(std::any_cast<Parser::Rule> (corelib::map::get(data, "name")).data);
    if (corelib::text::startsWithRange(name, 'A', 'Z')) {
        processingToken = true;
        res << "::Parser::Token_result " << name << "(const char* in) {";
    } else {
        processingToken = false;
        res << "::Parser::Rule_result " << name << "(const TokenFlow &flow, int &pos) {";
    }
    buf += res.str();
}
