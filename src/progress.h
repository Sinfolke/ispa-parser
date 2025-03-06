#pragma once
#include <parser.h>
#include <internal_types.h>
#include <list>
void literalsToToken(Parser::Tree &tree, Parser::Tree &treeInsert);
void replaceDublications(Parser::Tree &tree);
void inlineTokens(Parser::Tree &tree);
void sortByPriority(Parser::Tree &tree);
std::pair<std::list<std::string>, std::list<std::string>> getTokenAndRuleNames(Parser::Tree tree, std::string nested_name);
use_prop_t accamulate_use_data_to_map(Parser::Tree use);