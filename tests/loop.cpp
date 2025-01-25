#include <lib.h>
#include <parser.h>

int main() {
    printf("\n### while loop\n");
    std::string content = getContent("loop_while");
    Parser::Parser parser(content.c_str());
    auto tree = parser.loop_while(content.c_str());
    printf("\n### for loop\n");
    content = getContent("loop_for");
    parser = ::Parser::Parser(content.c_str());
    tree = parser.loop_for(content.c_str());
    return 0;
}