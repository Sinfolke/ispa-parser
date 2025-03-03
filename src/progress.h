#pragma once
#include <parser.h>
#include <internal_types.h>
void literalsToToken(Parser::Tree &tree, Parser::Tree &treeInsert);
void replaceDublications(Parser::Tree &tree);
void inlineTokens(Parser::Tree &tree);
void sortByPriority(Parser::Tree &tree);
use_prop_t accamulate_use_data_to_map(Parser::Tree use);