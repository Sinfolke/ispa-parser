#include <parser.h>

void literalsToToken(Parser::Tree& tree);
void replaceDublications(Parser::Tree& tree);
Parser::Tree getReplacedTree(Parser::Tree& tree, Parser::Tree& rules);