#include <defs.h>
void on_number(Parser::Tree &tree, int &i, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<obj_t>(member.data);
    auto full = std::any_cast<std::string>(corelib::map::get(data, "full"));
    buf += full;
}