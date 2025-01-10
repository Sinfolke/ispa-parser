#include <defs.h>

void on_string(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    if (!processingToken)
        throw Error("Cannot process string inside non-token rule");
    auto data_str = std::any_cast<std::string>(member.data);
    std::stringstream str;
    str << "if (!strncmp(pos, \"" << data_str << "\", sizeof(\"" << data_str << "\"))\n";
    str << "\treturn {};";
    buf += str.str();
}
