#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main() {
    Parser::Tokenizator tokenizator;
    Parser::Parser parser;
    tokenizator.makeTokensFromFile("parser/parser/Rule.isc");
    std::ofstream ofile("tokens");
    if (!ofile) {
        std::cerr << "could not open token file\n";
        exit(1);
    }
    tokenizator.printTokens(ofile);
    std::cout << std::endl;
}