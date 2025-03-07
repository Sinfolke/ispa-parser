#include <lib.h>
#include <parser.h>

int main() {
    std::string content = getContent("cll_ternary");
    Parser::Parser parser(content.c_str());
    auto tree = parser.cll_ternary(content.c_str());
    return 0;
}