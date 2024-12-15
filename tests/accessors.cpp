#include <lib.h>
#include <parser.h>

int main() {
    std::string content = getContent("accessor");
    Parser::Parser parser(content.c_str());
    auto tree = parser.accessor(content.c_str());
    return 0;
}