#include <defs.h>
EXPORT void on_rule(std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<obj_t>(member.data);
    qualifier = std::any_cast<char>(std::any_cast<Parser::Rule>(corelib::map::get(data, "qualifier")));
}
