#include <defs.h>
EXPORT void on_accessor(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<obj_t>(member.data);
}
