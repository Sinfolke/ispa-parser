#include <fstream>
std::string getContent(std::string filename) {
    std::ifstream file("../files/" + filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    return content;
}