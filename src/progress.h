#pragma once
#include <parser.h>
#include <internal_types.h>
#include <list>
#include <IR.h>
void literalsToToken(Parser::Tree &tree, Parser::Tree &treeInsert);
void replaceDublications(Parser::Tree &tree);
void inlineTokens(Parser::Tree &tree);
void sortByPriority(Parser::Tree &tree);
void addSpaceToken(Parser::Tree &tree);
std::pair<std::list<std::string>, std::list<std::string>> getTokenAndRuleNames(Parser::Tree tree, std::string nested_name);
use_prop_t accamulate_use_data_to_map(Parser::Tree use);
std::pair<std::list<std::pair<IR::data_block, std::string>>, std::list<std::pair<IR::data_block, std::string>>> get_data_blocks(IR::ir ir);