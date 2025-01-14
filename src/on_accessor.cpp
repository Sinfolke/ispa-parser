#include <defs.h>
int accessor_number = 0;
void on_accessor(Parser::Tree &tree, int &i, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<obj_t>(member.data);
}
