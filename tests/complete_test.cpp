#include <parser.h>
#include <fstream>
#include <iostream>
#include <sstream>
int main() {
    system("cd " __ROOT_DIR__);
    std::ifstream file("parser/dataTypes.isc");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file.\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    Parser::Parser parser(content.c_str());
    auto tree = parser.parse();
    file.close();
    return 0;
}