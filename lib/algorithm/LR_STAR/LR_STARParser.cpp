module LR_STARParser;

LR_STARParser::LR_STARParser(AST::Tree* tree, std::size_t k) : LRParser(tree, k, false) {}
LR_STARParser::LR_STARParser(AST::Tree& tree, std::size_t k) : LRParser(&tree, k, false) {}
void LR_STARParser::build() {}
