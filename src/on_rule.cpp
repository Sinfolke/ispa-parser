#include <defs.h>
char qualifier;
void on_rule(Parser::Tree tree, int i, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<obj_t>(member.data);
    qualifier = std::any_cast<char>(std::any_cast<Parser::Rule>(corelib::map::get(data, "qualifier")));
}
