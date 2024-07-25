#include "main.h"
#include <cpuf/let>
int main(int argc, char** argv) {
    devinfolog();
    let a = "Hello, world!";
    std::cout << a << "\nC++ version: " << CXX_STR << std::endl;
}
