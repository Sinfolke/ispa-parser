#pragma once
#include <corelib.h>
#include <parser.h>
#include <internal_types.h>
#include <list>
#include <IR/IR.h>
void literalsToToken(Parser::Tree &tree, Parser::Tree &treeInsert);
void replaceDublications(Parser::Tree &tree);
void inlineTokens(Parser::Tree &tree);
void sortByPriority(Parser::Tree &tree, Parser::Tree &current_tree);
void addSpaceToken(Parser::Tree &tree);
std::pair<std::list<std::string>, std::list<std::string>> getTokenAndRuleNames(Parser::Tree tree, std::string nested_name);
use_prop_t accamulate_use_data_to_map(Parser::Tree use);
void getUsePlacesTable(Parser::Tree &tree, use_place_t &use_places, std::vector<std::string> fullname);
std::pair<data_block_t, data_block_t> get_data_blocks(const IR &ir);
lexer_code getCodeForLexer(Parser::Tree &tree, use_place_t use_places, IR ir);