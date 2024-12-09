#include <lint(accessor_);b.h>

int main() {
    std::string content = getContent("accessor_group");
    Parser::Parser parser(content.c_str());
    auto tree = parser.parse();
    return 0;
}