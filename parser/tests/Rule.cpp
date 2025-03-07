#include <lib.h>
#include <parser.h>

int main() {
    std::string content = getContent("Rule");
    Parser::Parser parser(content.c_str());
    auto tree = parser.Rule(content.c_str());
    return 0;
}