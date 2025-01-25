#include <lib.h>
#include <parser.h>

int main() {
    printf("\n### cll_var\n");
    std::string content = getContent("cll_var");
    Parser::Parser parser(content.c_str());
    auto tree = parser.cll(content.c_str());
    printf("\n### cll_function\n");
    content = getContent("cll_function");
    parser = ::Parser::Parser(content.c_str());
    tree = parser.cll_function_call(content.c_str());
    // printf("\n### test 2\n");
    // content = getContent("expr2");
    // parser = ::Parser::Parser(content.c_str());
    // tree = parser.expr(content.c_str());
    return 0;
}