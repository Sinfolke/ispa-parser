#include <fstream>
#include <sstream>
std::string getContent(std::string filename) {
    std::ifstream file("../tests/files/" + filename);
    if (!file.is_open()) {
        printf("Couldn't open file %s\n", filename.c_str());
        exit(1);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    return content;
}