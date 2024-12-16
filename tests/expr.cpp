#include <lib.h>
#include <parser.h>

int main() {
    printf("\n### test 1\n");
    std::string content = getContent("expr1");
    Parser::Parser parser(content.c_str());
    auto tree = parser.expr(content.c_str());
    printf("\n### test 2\n");
    content = getContent("expr2");
    parser = ::Parser::Parser(content.c_str());
    tree = parser.expr(content.c_str());
    printf("\n### test 3\n");
    content = getContent("expr3");
    parser = ::Parser::Parser(content.c_str());
    tree = parser.expr(content.c_str());
    return 0;
}