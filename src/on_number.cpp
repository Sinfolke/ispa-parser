#include <defs.h>
EXPORT void on_number(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<obj_t>(member.data);
    auto full = std::any_cast<std::string>(corelib::map::get(data, "full"));
    buf += full;
}