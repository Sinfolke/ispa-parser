#pragma once
#include <parser.h>
#include <internal_types.h>
#include <corelib.h>
void normalizeRule(Parser::Rule &member, bool is_nested);
void normalizeTree(Parser::Tree &tree, bool is_nested);