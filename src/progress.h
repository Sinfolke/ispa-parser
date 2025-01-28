#pragma once
#include <parser.h>
void literalsToToken(Parser::Tree &tree, Parser::Tree &treeInsert);
void replaceDublications(Parser::Tree &tree);
void sortByPriority(Parser::Tree &tree);