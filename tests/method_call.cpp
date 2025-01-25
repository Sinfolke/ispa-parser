#include <lib.h>
#include <parser.h>

int main() {
    std::string content = getContent("method_call");
    Parser::Parser parser(content.c_str());
    auto tree = parser.method_call(content.c_str());
    return 0;
}