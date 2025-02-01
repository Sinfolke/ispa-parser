#include <fstream>
#include <sstream>
#include <stdexcept>
#include <parser.h>
int main() {
    std::ifstream f(__ROOT_DIR__ "/IR-convertion-group.isc");
    if (!f)
        throw std::runtime_error("Cannot open file");
    std::stringstream ss;
    ss << f.rdbuf();
    std::string content = ss.str();
    
}