#include <lib.h>
#include <parser.h>

int main() {
    printf("\n### test 1\n");
    std::string content = getContent("if");
    Parser::Parser parser(content.c_str());
    auto tree = parser.cll_if(content.c_str());
    return 0;
}