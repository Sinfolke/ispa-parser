#pragma once
#include <parser.h>
#include <internal_types.h>
#include <corelib.h>
#include <algorithm>
void normalizeRule(Parser::Rule &member, arr_t<std::string> &fullname, arr_t<std::pair<std::string, arr_t<std::string>>> &nested_rule_names);
void normalizeTree(Parser::Tree &tree, arr_t<std::string> &fullname, arr_t<std::pair<std::string, arr_t<std::string>>> &nested_rule_names);
