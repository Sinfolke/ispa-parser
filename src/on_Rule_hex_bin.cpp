#include <defs.h>
EXPORT void on_Rule_hex(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<std::string>(member.data);
    std::stringstream expr;
    buf += "if (!";
    for (int i = 0; i < data.size(); i += 2) {
        if (i != 0)
            expr << "&&";
        if (i + 1 > data.size()) {
            expr << "(*pos + " << std::to_string(i) << ") == 0x" << data[i] << data;
        } 
    }
}
