#include "Parser.h"
const Parser::DFA::CharTable<2, 6> Parser::Lexer::dfa_table_0 = {{ 1, ::Parser::DFA::null_state, {
{'\f', 0, ::Parser::DFA::null_state}, {'\v', 0, ::Parser::DFA::null_state}, {'\r', 0, ::Parser::DFA::null_state}, {'\n', 0, ::Parser::DFA::null_state}, {' ', 0, ::Parser::DFA::null_state}, {'\t', 0, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_1 = {{ 0, ::Parser::DFA::null_state, {
{'&', 1, 0}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<7, 7> Parser::Lexer::dfa_table_2 = {{ 0, ::Parser::DFA::null_state, {
{'i', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'m', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'p', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 5, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'t', 6, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_3 = {{ 0, ::Parser::DFA::null_state, {
{'=', 1, 0}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 7> Parser::Lexer::dfa_table_4 = {{ 0, ::Parser::DFA::null_state, {
{'\r', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\f', 0, 0}, {'+', 1, 0}, {'\v', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'+', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<6, 7> Parser::Lexer::dfa_table_5 = {{ 0, ::Parser::DFA::null_state, {
{'w', 1, 0}, {'\t', 0, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'h', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'i', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 5, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<4, 7> Parser::Lexer::dfa_table_6 = {{ 0, ::Parser::DFA::null_state, {
{'f', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 7> Parser::Lexer::dfa_table_7 = {{ 0, ::Parser::DFA::null_state, {
{'-', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'-', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 7> Parser::Lexer::dfa_table_8 = {{ 0, ::Parser::DFA::null_state, {
{'f', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'n', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 7> Parser::Lexer::dfa_table_9 = {{ 0, ::Parser::DFA::null_state, {
{'i', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'f', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_10 = {{ 0, ::Parser::DFA::null_state, {
{']', 1, 0}, {'\r', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\v', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<7, 7> Parser::Lexer::dfa_table_11 = {{ 0, ::Parser::DFA::null_state, {
{'m', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'u', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 5, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 6, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<4, 7> Parser::Lexer::dfa_table_12 = {{ 0, ::Parser::DFA::null_state, {
{'u', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'s', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_13 = {{ 0, ::Parser::DFA::null_state, {
{':', 1, 0}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<4, 8> Parser::Lexer::dfa_table_14 = {{ 0, ::Parser::DFA::null_state, {
{'\v', 0, ::Parser::DFA::null_state}, {'1', 0, 0}, {'\f', 0, ::Parser::DFA::null_state}, {'\r', 0, ::Parser::DFA::null_state}, {'0', 3, ::Parser::DFA::null_state}, {' ', 0, ::Parser::DFA::null_state}, {'\n', 0, ::Parser::DFA::null_state}, {'\t', 0, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'b', 2, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'b', 2, ::Parser::DFA::null_state}, {'0', 1, ::Parser::DFA::null_state}, {'\t', 0, ::Parser::DFA::null_state}} },
};
const Parser::DFA::CharTable<4, 28> Parser::Lexer::dfa_table_15 = {{ 0, ::Parser::DFA::null_state, {
{'D', 0, 0}, {'F', 0, 0}, {'0', 3, ::Parser::DFA::null_state}, {'E', 0, 0}, {'C', 0, 0}, {'B', 0, 0}, {'A', 0, 0}, {'7', 0, 0}, {'\n', 0, ::Parser::DFA::null_state}, {'e', 0, 0}, {'8', 0, 0}, {'5', 0, 0}, {'f', 0, 0}, {'2', 0, 0}, {'1', 0, 0}, {'b', 0, 0}, {'4', 0, 0}, {'a', 0, 0}, {'d', 0, 0}, {'3', 0, 0}, {'c', 0, 0}, {'6', 0, 0}, {'9', 0, 0}, {'\f', 0, ::Parser::DFA::null_state}, {'\v', 0, ::Parser::DFA::null_state}, {'\r', 0, ::Parser::DFA::null_state}, {' ', 0, ::Parser::DFA::null_state}, {'\t', 0, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'x', 2, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'x', 2, ::Parser::DFA::null_state}, {'0', 1, ::Parser::DFA::null_state}, {'\t', 0, ::Parser::DFA::null_state}} },
};
const Parser::DFA::CharTable<3, 1> Parser::Lexer::dfa_table_16 = {{ 0, ::Parser::DFA::null_state, {
{'\\', 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'\\', 2, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<5, 7> Parser::Lexer::dfa_table_17 = {{ 0, ::Parser::DFA::null_state, {
{'\f', 0, 0}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\\', 1, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'\\', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'s', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'0', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<9, 8> Parser::Lexer::dfa_table_18 = {{ 0, ::Parser::DFA::null_state, {
{'f', 2, 0}, {'\f', 0, 0}, {'t', 1, ::Parser::DFA::null_state}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'a', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'u', 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 6, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 7, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'s', 8, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'e', 7, 0}} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_19 = {{ 0, ::Parser::DFA::null_state, {
{',', 1, 0}, {'\t', 0, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 1> Parser::Lexer::dfa_table_20 = {{ 0, ::Parser::DFA::null_state, {
{'\\', 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'\\', 2, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<2, 1> Parser::Lexer::dfa_table_21 = {{ 0, ::Parser::DFA::null_state, {
{&dfa_table_22, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 8> Parser::Lexer::dfa_table_22 = {{ 0, ::Parser::DFA::null_state, {
{'\f', 0, 0}, {']', 2, 1}, {'\v', 0, 0}, {'\r', 0, 0}, {'\\', 1, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'\\', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<5, 7> Parser::Lexer::dfa_table_23 = {{ 0, ::Parser::DFA::null_state, {
{'f', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'m', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_24 = {{ 0, ::Parser::DFA::null_state, {
{'[', 1, 0}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_25 = {{ 0, ::Parser::DFA::null_state, {
{'(', 1, 0}, {'\r', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\v', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_26 = {{ 0, ::Parser::DFA::null_state, {
{';', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<12, 20> Parser::Lexer::dfa_table_27 = {{ 1, 0, {
{'-', 1, 0}, {'7', 11, ::Parser::DFA::null_state}, {'\t', 0, 0}, {'+', 1, 0}, {'8', 10, ::Parser::DFA::null_state}, {'\n', 0, 0}, {'6', 9, ::Parser::DFA::null_state}, {'5', 8, ::Parser::DFA::null_state}, {' ', 0, 0}, {'4', 7, ::Parser::DFA::null_state}, {'2', 6, ::Parser::DFA::null_state}, {'1', 5, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'\v', 0, 0}, {'9', 3, ::Parser::DFA::null_state}, {'\r', 0, 0}, {'0', 2, ::Parser::DFA::null_state}, {',', 0, 0}, {'.', 0, 0}, {'\f', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 1, 0, {
{'0', 1, 0}, {'\f', 0, 0}} },
{ 1, 0, {
{'9', 1, 0}, {'0', 2, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
{ 1, 0, {
{'9', 3, ::Parser::DFA::null_state}, {'3', 1, 0}, {'0', 2, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
{ 1, 0, {
{'1', 1, 0}, {'9', 3, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'0', 2, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
{ 1, 0, {
{'2', 1, 0}, {'1', 5, ::Parser::DFA::null_state}, {'0', 2, ::Parser::DFA::null_state}, {'9', 3, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
{ 1, 0, {
{'4', 1, 0}, {'2', 6, ::Parser::DFA::null_state}, {'1', 5, ::Parser::DFA::null_state}, {'9', 3, ::Parser::DFA::null_state}, {'0', 2, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
{ 1, 0, {
{'5', 1, 0}, {'2', 6, ::Parser::DFA::null_state}, {'4', 7, ::Parser::DFA::null_state}, {'1', 5, ::Parser::DFA::null_state}, {'9', 3, ::Parser::DFA::null_state}, {'0', 2, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
{ 1, 0, {
{'6', 1, 0}, {'5', 8, ::Parser::DFA::null_state}, {'2', 6, ::Parser::DFA::null_state}, {'4', 7, ::Parser::DFA::null_state}, {'1', 5, ::Parser::DFA::null_state}, {'9', 3, ::Parser::DFA::null_state}, {'0', 2, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
{ 1, 0, {
{'6', 9, ::Parser::DFA::null_state}, {'5', 8, ::Parser::DFA::null_state}, {'2', 6, ::Parser::DFA::null_state}, {'4', 7, ::Parser::DFA::null_state}, {'1', 5, ::Parser::DFA::null_state}, {'9', 3, ::Parser::DFA::null_state}, {'0', 2, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'8', 1, 0}, {'\f', 0, 0}} },
{ 1, 0, {
{'6', 9, ::Parser::DFA::null_state}, {'5', 8, ::Parser::DFA::null_state}, {'2', 6, ::Parser::DFA::null_state}, {'4', 7, ::Parser::DFA::null_state}, {'1', 5, ::Parser::DFA::null_state}, {'0', 2, ::Parser::DFA::null_state}, {'9', 3, ::Parser::DFA::null_state}, {'3', 4, ::Parser::DFA::null_state}, {'+', 1, 0}, {'8', 10, ::Parser::DFA::null_state}, {'\f', 0, 0}} },
};
const Parser::DFA::CharTable<2, 69> Parser::Lexer::dfa_table_28 = {{ 1, 0, {
{'Z', 0, 0}, {'Y', 0, 0}, {'P', 0, 0}, {'V', 0, 0}, {'X', 0, 0}, {'W', 0, 0}, {'U', 0, 0}, {'T', 0, 0}, {'S', 0, 0}, {'R', 0, 0}, {'Q', 0, 0}, {'O', 0, 0}, {'N', 0, 0}, {'M', 0, 0}, {'K', 0, 0}, {'I', 0, 0}, {'z', 0, 0}, {'L', 0, 0}, {'y', 0, 0}, {'G', 0, 0}, {'x', 0, 0}, {'J', 0, 0}, {'w', 0, 0}, {'E', 0, 0}, {'v', 0, 0}, {'H', 0, 0}, {'u', 0, 0}, {'C', 0, 0}, {'t', 0, 0}, {'F', 0, 0}, {'s', 0, 0}, {'A', 0, 0}, {'r', 0, 0}, {'D', 0, 0}, {'q', 0, 0}, {'\r', 0, 0}, {'p', 0, 0}, {'B', 0, 0}, {'o', 0, 0}, {'\v', 0, 0}, {'n', 0, 0}, {'m', 0, 0}, {'\t', 0, 0}, {'l', 0, 0}, {'k', 0, 0}, {'\f', 0, 0}, {'9', 0, 0}, {'j', 0, 0}, {'\n', 0, 0}, {'i', 0, 0}, {'7', 0, 0}, {'h', 0, 0}, {'5', 0, 0}, {'f', 0, 0}, {'8', 0, 0}, {'e', 0, 0}, {'2', 0, 0}, {'_', 0, 0}, {'b', 0, 0}, {'1', 0, 0}, {'6', 0, 0}, {'c', 0, 0}, {' ', 0, 0}, {'4', 0, 0}, {'a', 0, 0}, {'3', 0, 0}, {'d', 0, 0}, {'g', 0, 0}, {'0', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_29 = {{ 0, ::Parser::DFA::null_state, {
{'{', 1, 0}, {'\r', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\v', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_30 = {{ 0, ::Parser::DFA::null_state, {
{'|', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 8> Parser::Lexer::dfa_table_31 = {{ 0, ::Parser::DFA::null_state, {
{'/', 1, ::Parser::DFA::null_state}, {'n', 0, 0}, {'\t', 0, ::Parser::DFA::null_state}, {'\v', 0, ::Parser::DFA::null_state}, {'\f', 0, ::Parser::DFA::null_state}, {' ', 0, ::Parser::DFA::null_state}, {'\n', 0, ::Parser::DFA::null_state}, {'\r', 0, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'/', 2, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<4, 8> Parser::Lexer::dfa_table_32 = {{ 0, ::Parser::DFA::null_state, {
{'n', 2, 0}, {'\t', 0, 0}, {'\r', 0, 0}, {'!', 1, 1}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'o', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'t', 1, 0}} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_33 = {{ 0, ::Parser::DFA::null_state, {
{'%', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 11> Parser::Lexer::dfa_table_34 = {{ 0, ::Parser::DFA::null_state, {
{'/', 1, 0}, {'%', 1, 4}, {'-', 1, 0}, {'*', 1, 0}, {'+', 1, 0}, {'\f', 0, 0}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_35 = {{ 0, ::Parser::DFA::null_state, {
{'-', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_36 = {{ 0, ::Parser::DFA::null_state, {
{'\r', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\f', 0, 0}, {'+', 1, 0}, {'\v', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_37 = {{ 0, ::Parser::DFA::null_state, {
{'\r', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'?', 1, 0}, {'\n', 0, 0}, {'\v', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 12> Parser::Lexer::dfa_table_38 = {{ 1, 0, {
{&dfa_table_21, 0, 0}, {'^', 1, 0}, {&dfa_table_20, 0, 0}, {']', 1, 0}, {'\f', 0, 0}, {'\v', 0, 0}, {' ', 0, 0}, {&dfa_table_22, 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'[', 1, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_39 = {{ 0, ::Parser::DFA::null_state, {
{'*', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_40 = {{ 0, ::Parser::DFA::null_state, {
{'@', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<4, 8> Parser::Lexer::dfa_table_41 = {{ 0, ::Parser::DFA::null_state, {
{'|', 2, 0}, {'o', 1, 1}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'|', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 7> Parser::Lexer::dfa_table_42 = {{ 0, ::Parser::DFA::null_state, {
{'-', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'>', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_43 = {{ 0, ::Parser::DFA::null_state, {
{'\f', 0, 0}, {'.', 1, 0}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 8> Parser::Lexer::dfa_table_44 = {{ 1, 0, {
{'\f', 0, 0}, {'\'', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\\', 2, ::Parser::DFA::null_state}, {' ', 0, 0}, {'\n', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 1, 0, {
{'\'', 0, 0}, {'\\', 1, 0}} },
};
const Parser::DFA::CharTable<25, 10> Parser::Lexer::dfa_table_45 = {{ 0, ::Parser::DFA::null_state, {
{'s', 24, ::Parser::DFA::null_state}, {'a', 3, ::Parser::DFA::null_state}, {'\t', 0, 0}, {'m', 2, ::Parser::DFA::null_state}, {'\f', 0, 0}, {';', 1, 0}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'i', 4, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'x', 8, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 9, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'a', 10, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'i', 11, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 12, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 13, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'c', 14, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'p', 15, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'w', 16, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 17, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'p', 18, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 19, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'m', 20, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 21, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 22, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 23, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'p', 6, ::Parser::DFA::null_state}, {'k', 7, 0}} },
};
const Parser::DFA::CharTable<2, 8> Parser::Lexer::dfa_table_46 = {{ 1, 0, {
{'=', 1, 0}, {'\v', 0, 0}, {'\f', 0, 0}, {'\r', 0, 0}, {&dfa_table_34, 1, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<6, 10> Parser::Lexer::dfa_table_47 = {{ 0, ::Parser::DFA::null_state, {
{'>', 5, ::Parser::DFA::null_state}, {'\f', 0, 0}, {'=', 3, 1}, {'<', 4, ::Parser::DFA::null_state}, {'!', 1, 3}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'=', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'=', 2, 0}} },
{ 2, 5, {
{'=', 2, 0}} },
{ 2, 0, {
{'=', 2, 0}} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_48 = {{ 0, ::Parser::DFA::null_state, {
{'}', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<5, 9> Parser::Lexer::dfa_table_49 = {{ 0, ::Parser::DFA::null_state, {
{'n', 2, ::Parser::DFA::null_state}, {'\t', 0, 0}, {&dfa_table_28, 1, 0}, {';', 1, 0}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'a', 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'m', 4, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 1, 0}} },
};
const Parser::DFA::CharTable<5, 8> Parser::Lexer::dfa_table_50 = {{ 0, ::Parser::DFA::null_state, {
{'a', 2, 0}, {'\t', 0, 0}, {'&', 1, 1}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'&', 3, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'n', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'d', 3, 0}} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_51 = {{ 0, ::Parser::DFA::null_state, {
{'\f', 0, 0}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'#', 1, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_52 = {{ 0, ::Parser::DFA::null_state, {
{'$', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 10> Parser::Lexer::dfa_table_53 = {{ 1, 0, {
{'<', 1, 0}, {&dfa_table_54, 2, ::Parser::DFA::null_state}, {',', 0, 0}, {'\t', 0, 0}, {'>', 1, 0}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 1, 0, {
{'>', 1, 0}, {'\r', 0, 0}} },
};
const Parser::DFA::CharTable<16, 13> Parser::Lexer::dfa_table_54 = {{ 0, ::Parser::DFA::null_state, {
{'b', 7, 0}, {' ', 0, 5}, {'v', 6, 1}, {'o', 5, 5}, {'s', 4, 2}, {&dfa_table_53, 15, ::Parser::DFA::null_state}, {'\f', 0, 5}, {'n', 2, 4}, {'\t', 0, 5}, {'a', 1, 5}, {'\v', 0, 5}, {'\r', 0, 5}, {'\n', 0, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 8, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'u', 9, 4}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'t', 10, 2}} },
{ 0, ::Parser::DFA::null_state, {
{'b', 11, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'a', 12, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 13, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 0, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'m', 3, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'j', 0, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 14, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 3, 5}} },
{ 3, 5, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_55 = {{ 0, ::Parser::DFA::null_state, {
{'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {')', 1, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<4, 3> Parser::Lexer::dfa_table_56 = {{ 0, ::Parser::DFA::null_state, {
{&dfa_table_0, 2, ::Parser::DFA::null_state}, {&dfa_table_41, 1, 0}, {&dfa_table_50, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{&dfa_table_0, 3, ::Parser::DFA::null_state}, {&dfa_table_41, 1, 0}} },
{ 1, 1, {
} },
};
const Parser::DFA::CharTable<2, 7> Parser::Lexer::dfa_table_57 = {{ 0, ::Parser::DFA::null_state, {
{'/', 1, 0}, {'\f', 0, 0}, {'\n', 0, 0}, {' ', 0, 0}, {'\v', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
std::array<std::variant<::Parser::DFA::TokenTable, ::Parser::DFA::CharTable, ::Parser::DFA::MultiTable, Parser::Token_res (*) (const char*)>, 256> Parser::Lexer::first_character_dispatch_table = {
	{ }, // '\0'
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // '\a'
	{ }, // '\b'
	{ &dfa_table_0, }, // '\t'
	{ &dfa_table_0, }, // '\n'
	{ &dfa_table_0, }, // '\v'
	{ &dfa_table_0, }, // '\f'
	{ &dfa_table_0, }, // '\r'
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ }, // ''
	{ &dfa_table_0, }, // ' '
	{ }, // '!'
	{ }, // '"'
	{ &dfa_table_51, }, // '#'
	{ &dfa_table_52, }, // '$'
	{ &dfa_table_33, }, // '%'
	{ &dfa_table_1, }, // '&'
	{ }, // '\''
	{ &dfa_table_25, }, // '('
	{ &dfa_table_55, }, // ')'
	{ &dfa_table_39, }, // '*'
	{ &dfa_table_36, &dfa_table_27, &dfa_table_4, }, // '+'
	{ &dfa_table_19, }, // ','
	{ &dfa_table_35, &dfa_table_42, &dfa_table_27, &dfa_table_7, }, // '-'
	{ &dfa_table_43, }, // '.'
	{ &dfa_table_46, &dfa_table_34, &dfa_table_57, &dfa_table_31, }, // '/'
	{ &dfa_table_15, &dfa_table_14, }, // '0'
	{ }, // '1'
	{ }, // '2'
	{ }, // '3'
	{ }, // '4'
	{ }, // '5'
	{ }, // '6'
	{ }, // '7'
	{ }, // '8'
	{ }, // '9'
	{ &dfa_table_13, }, // ':'
	{ &dfa_table_26, }, // ';'
	{ &dfa_table_53, }, // '<'
	{ &dfa_table_3, }, // '='
	{ &dfa_table_47, }, // '>'
	{ &dfa_table_37, }, // '?'
	{ &dfa_table_40, }, // '@'
	{ &dfa_table_28, }, // 'A'
	{ &dfa_table_28, }, // 'B'
	{ &dfa_table_28, }, // 'C'
	{ &dfa_table_28, }, // 'D'
	{ &dfa_table_28, }, // 'E'
	{ &dfa_table_28, }, // 'F'
	{ &dfa_table_28, }, // 'G'
	{ &dfa_table_28, }, // 'H'
	{ &dfa_table_28, }, // 'I'
	{ &dfa_table_28, }, // 'J'
	{ &dfa_table_28, }, // 'K'
	{ &dfa_table_28, }, // 'L'
	{ &dfa_table_28, }, // 'M'
	{ &dfa_table_28, }, // 'N'
	{ &dfa_table_28, }, // 'O'
	{ &dfa_table_28, }, // 'P'
	{ &dfa_table_28, }, // 'Q'
	{ &dfa_table_28, }, // 'R'
	{ &dfa_table_28, }, // 'S'
	{ &dfa_table_28, }, // 'T'
	{ &dfa_table_28, }, // 'U'
	{ &dfa_table_28, }, // 'V'
	{ &dfa_table_28, }, // 'W'
	{ &dfa_table_28, }, // 'X'
	{ &dfa_table_28, }, // 'Y'
	{ &dfa_table_28, }, // 'Z'
	{ &dfa_table_38, &dfa_table_24, }, // '['
	{ &dfa_table_44, &dfa_table_22, &dfa_table_16, &dfa_table_21, &dfa_table_20, &dfa_table_17, }, // '\\'
	{ &dfa_table_10, }, // ']'
	{ }, // '^'
	{ &dfa_table_28, }, // '_'
	{ }, // '`'
	{ &dfa_table_50, &dfa_table_28, }, // 'a'
	{ &dfa_table_54, &dfa_table_28, }, // 'b'
	{ &dfa_table_28, }, // 'c'
	{ &dfa_table_28, }, // 'd'
	{ &dfa_table_28, }, // 'e'
	{ &dfa_table_28, &dfa_table_23, &dfa_table_8, &dfa_table_18, &dfa_table_6, }, // 'f'
	{ &dfa_table_28, }, // 'g'
	{ &dfa_table_28, }, // 'h'
	{ &dfa_table_28, &dfa_table_9, &dfa_table_2, }, // 'i'
	{ &dfa_table_28, }, // 'j'
	{ &dfa_table_28, }, // 'k'
	{ &dfa_table_28, }, // 'l'
	{ &dfa_table_28, &dfa_table_11, }, // 'm'
	{ &dfa_table_49, &dfa_table_32, &dfa_table_28, }, // 'n'
	{ &dfa_table_28, }, // 'o'
	{ &dfa_table_28, }, // 'p'
	{ &dfa_table_28, }, // 'q'
	{ &dfa_table_28, }, // 'r'
	{ &dfa_table_45, &dfa_table_28, }, // 's'
	{ &dfa_table_28, }, // 't'
	{ &dfa_table_28, &dfa_table_12, }, // 'u'
	{ &dfa_table_28, }, // 'v'
	{ &dfa_table_28, &dfa_table_5, }, // 'w'
	{ &dfa_table_28, }, // 'x'
	{ &dfa_table_28, }, // 'y'
	{ &dfa_table_28, }, // 'z'
	{ &dfa_table_29, }, // '{'
	{ &dfa_table_56, &dfa_table_41, &dfa_table_30, }, // '|'
	{ &dfa_table_48, }, // '}'
	{ }, // '~'
	{ }, // ''
	{ }, // 'Ä'
	{ }, // 'Å'
	{ }, // 'Ç'
	{ }, // 'É'
	{ }, // 'Ñ'
	{ }, // 'Ö'
	{ }, // 'Ü'
	{ }, // 'á'
	{ }, // 'à'
	{ }, // 'â'
	{ }, // 'ä'
	{ }, // 'ã'
	{ }, // 'å'
	{ }, // 'ç'
	{ }, // 'é'
	{ }, // 'è'
	{ }, // 'ê'
	{ }, // 'ë'
	{ }, // 'í'
	{ }, // 'ì'
	{ }, // 'î'
	{ }, // 'ï'
	{ }, // 'ñ'
	{ }, // 'ó'
	{ }, // 'ò'
	{ }, // 'ô'
	{ }, // 'ö'
	{ }, // 'õ'
	{ }, // 'ú'
	{ }, // 'ù'
	{ }, // 'û'
	{ }, // 'ü'
	{ }, // '†'
	{ }, // '°'
	{ }, // '¢'
	{ }, // '£'
	{ }, // '§'
	{ }, // '•'
	{ }, // '¶'
	{ }, // 'ß'
	{ }, // '®'
	{ }, // '©'
	{ }, // '™'
	{ }, // '´'
	{ }, // '¨'
	{ }, // '≠'
	{ }, // 'Æ'
	{ }, // 'Ø'
	{ }, // '∞'
	{ }, // '±'
	{ }, // '≤'
	{ }, // '≥'
	{ }, // '¥'
	{ }, // 'µ'
	{ }, // '∂'
	{ }, // '∑'
	{ }, // '∏'
	{ }, // 'π'
	{ }, // '∫'
	{ }, // 'ª'
	{ }, // 'º'
	{ }, // 'Ω'
	{ }, // 'æ'
	{ }, // 'ø'
	{ }, // '¿'
	{ }, // '¡'
	{ }, // '¬'
	{ }, // '√'
	{ }, // 'ƒ'
	{ }, // '≈'
	{ }, // '∆'
	{ }, // '«'
	{ }, // '»'
	{ }, // '…'
	{ }, // ' '
	{ }, // 'À'
	{ }, // 'Ã'
	{ }, // 'Õ'
	{ }, // 'Œ'
	{ }, // 'œ'
	{ }, // '–'
	{ }, // '—'
	{ }, // '“'
	{ }, // '”'
	{ }, // '‘'
	{ }, // '’'
	{ }, // '÷'
	{ }, // '◊'
	{ }, // 'ÿ'
	{ }, // 'Ÿ'
	{ }, // '⁄'
	{ }, // '€'
	{ }, // '‹'
	{ }, // '›'
	{ }, // 'ﬁ'
	{ }, // 'ﬂ'
	{ }, // '‡'
	{ }, // '·'
	{ }, // '‚'
	{ }, // '„'
	{ }, // '‰'
	{ }, // 'Â'
	{ }, // 'Ê'
	{ }, // 'Á'
	{ }, // 'Ë'
	{ }, // 'È'
	{ }, // 'Í'
	{ }, // 'Î'
	{ }, // 'Ï'
	{ }, // 'Ì'
	{ }, // 'Ó'
	{ }, // 'Ô'
	{ }, // ''
	{ }, // 'Ò'
	{ }, // 'Ú'
	{ }, // 'Û'
	{ }, // 'Ù'
	{ }, // 'ı'
	{ }, // 'ˆ'
	{ }, // '˜'
	{ }, // '¯'
	{ }, // '˘'
	{ }, // '˙'
	{ }, // '˚'
	{ }, // '¸'
	{ }, // '˝'
	{ }, // '˛'
	{ }, // 'ˇ'
};
::Parser::Lexer::makeToken(const char* &pos) {
	fcdt_lookup(first_character_dispatch_table, pos);
}
void Parser::Lexer::printTokens(std::ostream& os) {
    for (const auto& token : tokens)
        printToken(os, token);
}
void Parser::Lexer::printToken(std::ostream& os, const Token& token) {
    os << TokensToString(token.name()) << ": ";

    if (token.data().type() == typeid(str_t)) {
        os << '"' << std::any_cast<str_t>(token.data()) << '"';
    } else if (token.data().type() == typeid(num_t)) {
        os << std::any_cast<num_t>(token.data());
    } else if (token.data().type() == typeid(bool_t)) {
        os << std::boolalpha << std::any_cast<bool_t>(token.data());
    } else if (token.data().type() == typeid(Token)) {
        os << "{ ";
        printToken(os, std::any_cast<Token>(token.data())); // Recursive call
        os << " }";
    } else if (token.data().type() == typeid(arr_t<Token>)) { // Handle array of tokens
        os << "[ ";
        auto arr = std::any_cast<arr_t<Token>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printToken(os, *it);
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<str_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<str_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<num_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<num_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<bool_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<bool_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    }
    os << " # " << token.startpos();
    os << '\n';
}
void ::Parser::Parser::printAST(std::ostream &os) {
	size_t indentLevel = 0;
	printRule(os, tree, indentLevel, false);
}
void ::Parser::Parser::printRule(std::ostream &os, const ::Parser::Token &token, size_t &indentLevel, bool addSpaceOnBegin) {
	Lexer::printToken(os, token);
}
void ::Parser::Parser::printRule(std::ostream &os, const ::Parser::Rule &rule, size_t &indentLevel, bool addSpaceOnBegin) {
	printRule(os, rule.data(), indentLevel, addSpaceOnBegin);
}
void ::Parser::Parser::printRule(std::ostream &os, const std::any &data, size_t &indentLevel, bool addSpaceOnBegin) {
	using Token = ::Parser::Token;
	using Rule = ::Parser::Rule;

	if (addSpaceOnBegin) os << std::string(indentLevel, '\t');

if (data.type() == typeid(str_t)) {
        os << '"' << std::any_cast<str_t>(data) << '"';
    } else if (data.type() == typeid(num_t)) {
        os << std::any_cast<num_t>(data);
    } else if (data.type() == typeid(bool_t)) {
        os << std::boolalpha << std::any_cast<bool_t>(data);
    } else if (data.type() == typeid(Token)) {
        os << std::string(indentLevel, '\t');
        Lexer::printToken(os, std::any_cast<Token>(data));
    } else if (data.type() == typeid(arr_t<Token>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<Token>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t');
            Lexer::printToken(os, *it);
        }
        os << std::string(--indentLevel, '\t') << "]";
    } else if (data.type() == typeid(Rule)) {
        os << "{\n";
        indentLevel++;
        printRule(os, std::any_cast<Rule>(data), indentLevel, true);
        os << std::string(--indentLevel, '\t') << "}";
    } else if (data.type() == typeid(arr_t<Rule>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<Rule>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printRule(os, *it, indentLevel, true);
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<str_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<str_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<num_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<num_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << *it;
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<bool_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<bool_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(std::any)) {
        printRule(os, std::any_cast<const std::any&>(data), indentLevel, addSpaceOnBegin);
    } else if (data.type() == typeid(arr_t<std::any>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<const arr_t<std::any>&>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printRule(os, *it, indentLevel, true);
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    }	else if (data.type() == typeid(Types::rule_data_block_regular_datablock_key)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_data_block_regular_datablock_key>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "dt"<< ": ";
		printRule(os, dt.dt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_call)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_call>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "body"<< ": ";
		printRule(os, dt.body, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_decl)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_decl>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "type"<< ": ";
		printRule(os, dt.type, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_term)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_term>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "operators"<< ": ";
		printRule(os, dt.operators, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_logical)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_logical>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "right"<< ": ";
		printRule(os, dt.right, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "op"<< ": ";
		printRule(os, dt.op, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "left"<< ": ";
		printRule(os, dt.left, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll__var)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll__var>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "value"<< ": ";
		printRule(os, dt.value, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "op"<< ": ";
		printRule(os, dt.op, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "id"<< ": ";
		printRule(os, dt.id, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "type"<< ": ";
		printRule(os, dt.type, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_loop_while)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_loop_while>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "expr"<< ": ";
		printRule(os, dt.expr, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_loop_for)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_loop_for>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "cond"<< ": ";
		printRule(os, dt.cond, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "end"<< ": ";
		printRule(os, dt.end, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "decl"<< ": ";
		printRule(os, dt.decl, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll__variable)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll__variable>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "pos"<< ": ";
		printRule(os, dt.pos, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "brace_expression"<< ": ";
		printRule(os, dt.brace_expression, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "pre"<< ": ";
		printRule(os, dt.pre, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::_use_unit)) {
		os << "{\n";
		auto dt = std::any_cast<Types::_use_unit>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "value"<< ": ";
		printRule(os, dt.value, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::moduleImport_from_import_list)) {
		os << "{\n";
		auto dt = std::any_cast<Types::moduleImport_from_import_list>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::_use)) {
		os << "{\n";
		auto dt = std::any_cast<Types::_use>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second"<< ": ";
		printRule(os, dt.second, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_arithmetic)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_arithmetic>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "operators"<< ": ";
		printRule(os, dt.operators, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "nested_rules"<< ": ";
		printRule(os, dt.nested_rules, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "rule"<< ": ";
		printRule(os, dt.rule, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "data_block"<< ": ";
		printRule(os, dt.data_block, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule_member)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_member>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "val"<< ": ";
		printRule(os, dt.val, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "quantifier"<< ": ";
		printRule(os, dt.quantifier, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "prefix"<< ": ";
		printRule(os, dt.prefix, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule_data_block_templated_datablock)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_data_block_templated_datablock>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second_name"<< ": ";
		printRule(os, dt.second_name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first_name"<< ": ";
		printRule(os, dt.first_name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::rule_name)) {
		os << "{\n";
		auto dt = std::any_cast<Types::rule_name>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "nested_name"<< ": ";
		printRule(os, dt.nested_name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "is_nested"<< ": ";
		printRule(os, dt.is_nested, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::moduleDeclaration)) {
		os << "{\n";
		auto dt = std::any_cast<Types::moduleDeclaration>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "base"<< ": ";
		printRule(os, dt.base, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll__if)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll__if>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "stmt"<< ": ";
		printRule(os, dt.stmt, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "expr"<< ": ";
		printRule(os, dt.expr, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::moduleImport_from)) {
		os << "{\n";
		auto dt = std::any_cast<Types::moduleImport_from>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "from"<< ": ";
		printRule(os, dt.from, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "what"<< ": ";
		printRule(os, dt.what, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::object)) {
		os << "{\n";
		auto dt = std::any_cast<Types::object>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "values"<< ": ";
		printRule(os, dt.values, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "keys"<< ": ";
		printRule(os, dt.keys, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "value"<< ": ";
		printRule(os, dt.value, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "key"<< ": ";
		printRule(os, dt.key, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_expr_compare)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_expr_compare>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "sequence"<< ": ";
		printRule(os, dt.sequence, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "operators"<< ": ";
		printRule(os, dt.operators, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_method_call)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_method_call>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "body"<< ": ";
		printRule(os, dt.body, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "name"<< ": ";
		printRule(os, dt.name, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_arguments)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_arguments>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second"<< ": ";
		printRule(os, dt.second, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
	else if (data.type() == typeid(Types::cll_function_parameters)) {
		os << "{\n";
		auto dt = std::any_cast<Types::cll_function_parameters>(data);
indentLevel++;		os << std::string(indentLevel, '\t') << "second"<< ": ";
		printRule(os, dt.second, indentLevel, false);
		os << "\n";
		os << std::string(indentLevel, '\t') << "first"<< ": ";
		printRule(os, dt.first, indentLevel, false);
		os << "\n";
		os << std::string(--indentLevel, '\t') << "}\n";
	}
else os << "<UNDEF TYPE>";
}Parser::Rule_res Parser::Parser::getRule(Lexer::lazy_iterator &pos) {
        return main(pos);
    }
Parser::Rule_res Parser::Parser::getRule(Lexer::iterator &pos) {
        return main(pos);
    }
void ::Parser::Parser::parseFromTokens() {
        auto pos = Lexer::iterator(lexer);
        parseFromPos(pos);
    }
void ::Parser::Parser::lazyParse() {
        auto pos = Lexer::lazy_iterator(lexer, text);
        parseFromPos(pos);
    }
const ::Parser::Types::AUTO_4& Parser::get::AUTO_4(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<const Types::AUTO_4&>(token.data());
}
::Parser::Types::AUTO_4& Parser::get::AUTO_4(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_4) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_4, "Parser");
	return std::any_cast<Types::AUTO_4&>(token.data());
}
const ::Parser::Types::cll_TYPE& Parser::get::cll_TYPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<const Types::cll_TYPE&>(token.data());
}
::Parser::Types::cll_TYPE& Parser::get::cll_TYPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TYPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TYPE, "Parser");
	return std::any_cast<Types::cll_TYPE&>(token.data());
}
const ::Parser::Types::NAME& Parser::get::NAME(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<const Types::NAME&>(token.data());
}
::Parser::Types::NAME& Parser::get::NAME(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NAME) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NAME, "Parser");
	return std::any_cast<Types::NAME&>(token.data());
}
const ::Parser::Types::AUTO_2& Parser::get::AUTO_2(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<const Types::AUTO_2&>(token.data());
}
::Parser::Types::AUTO_2& Parser::get::AUTO_2(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_2) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_2, "Parser");
	return std::any_cast<Types::AUTO_2&>(token.data());
}
const ::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<const Types::cll_COMPARE_OP&>(token.data());
}
::Parser::Types::cll_COMPARE_OP& Parser::get::cll_COMPARE_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_COMPARE_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_COMPARE_OP, "Parser");
	return std::any_cast<Types::cll_COMPARE_OP&>(token.data());
}
const ::Parser::Types::AUTO_11& Parser::get::AUTO_11(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<const Types::AUTO_11&>(token.data());
}
::Parser::Types::AUTO_11& Parser::get::AUTO_11(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_11) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_11, "Parser");
	return std::any_cast<Types::AUTO_11&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_DIAPASON& Parser::get::rule_CSEQUENCE_DIAPASON(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_DIAPASON) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_DIAPASON, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_DIAPASON&>(token.data());
}
const ::Parser::Types::cll_OP& Parser::get::cll_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<const Types::cll_OP&>(token.data());
}
::Parser::Types::cll_OP& Parser::get::cll_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_OP, "Parser");
	return std::any_cast<Types::cll_OP&>(token.data());
}
const ::Parser::Types::AUTO_9& Parser::get::AUTO_9(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<const Types::AUTO_9&>(token.data());
}
::Parser::Types::AUTO_9& Parser::get::AUTO_9(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_9) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_9, "Parser");
	return std::any_cast<Types::AUTO_9&>(token.data());
}
const ::Parser::Types::AUTO_0& Parser::get::AUTO_0(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<const Types::AUTO_0&>(token.data());
}
::Parser::Types::AUTO_0& Parser::get::AUTO_0(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_0) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_0, "Parser");
	return std::any_cast<Types::AUTO_0&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE& Parser::get::rule_CSEQUENCE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE&>(token.data());
}
const ::Parser::Types::NUMBER& Parser::get::NUMBER(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<const Types::NUMBER&>(token.data());
}
::Parser::Types::NUMBER& Parser::get::NUMBER(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::NUMBER) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::NUMBER, "Parser");
	return std::any_cast<Types::NUMBER&>(token.data());
}
const ::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<const Types::cll_LOGICAL_OP&>(token.data());
}
::Parser::Types::cll_LOGICAL_OP& Parser::get::cll_LOGICAL_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_LOGICAL_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_LOGICAL_OP, "Parser");
	return std::any_cast<Types::cll_LOGICAL_OP&>(token.data());
}
const ::Parser::Types::AUTO_3& Parser::get::AUTO_3(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<const Types::AUTO_3&>(token.data());
}
::Parser::Types::AUTO_3& Parser::get::AUTO_3(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_3) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_3, "Parser");
	return std::any_cast<Types::AUTO_3&>(token.data());
}
const ::Parser::Types::AUTO_13& Parser::get::AUTO_13(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<const Types::AUTO_13&>(token.data());
}
::Parser::Types::AUTO_13& Parser::get::AUTO_13(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_13) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_13, "Parser");
	return std::any_cast<Types::AUTO_13&>(token.data());
}
const ::Parser::Types::AUTO_18& Parser::get::AUTO_18(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<const Types::AUTO_18&>(token.data());
}
::Parser::Types::AUTO_18& Parser::get::AUTO_18(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_18) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_18, "Parser");
	return std::any_cast<Types::AUTO_18&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_ESCAPE&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_ESCAPE& Parser::get::rule_CSEQUENCE_ESCAPE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_ESCAPE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_ESCAPE, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_ESCAPE&>(token.data());
}
const ::Parser::Types::AUTO_1& Parser::get::AUTO_1(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<const Types::AUTO_1&>(token.data());
}
::Parser::Types::AUTO_1& Parser::get::AUTO_1(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_1) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_1, "Parser");
	return std::any_cast<Types::AUTO_1&>(token.data());
}
const ::Parser::Types::SPACEMODE& Parser::get::SPACEMODE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<const Types::SPACEMODE&>(token.data());
}
::Parser::Types::SPACEMODE& Parser::get::SPACEMODE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::SPACEMODE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::SPACEMODE, "Parser");
	return std::any_cast<Types::SPACEMODE&>(token.data());
}
const ::Parser::Types::AUTO_7& Parser::get::AUTO_7(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<const Types::AUTO_7&>(token.data());
}
::Parser::Types::AUTO_7& Parser::get::AUTO_7(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_7) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_7, "Parser");
	return std::any_cast<Types::AUTO_7&>(token.data());
}
const ::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<const Types::BOOLEAN&>(token.data());
}
::Parser::Types::BOOLEAN& Parser::get::BOOLEAN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::BOOLEAN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::BOOLEAN, "Parser");
	return std::any_cast<Types::BOOLEAN&>(token.data());
}
const ::Parser::Types::rule_BIN& Parser::get::rule_BIN(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_BIN, "Parser");
	return std::any_cast<const Types::rule_BIN&>(token.data());
}
::Parser::Types::rule_BIN& Parser::get::rule_BIN(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_BIN) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_BIN, "Parser");
	return std::any_cast<Types::rule_BIN&>(token.data());
}
const ::Parser::Types::AUTO_10& Parser::get::AUTO_10(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<const Types::AUTO_10&>(token.data());
}
::Parser::Types::AUTO_10& Parser::get::AUTO_10(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_10) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_10, "Parser");
	return std::any_cast<Types::AUTO_10&>(token.data());
}
const ::Parser::Types::rule_HEX& Parser::get::rule_HEX(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<const Types::rule_HEX&>(token.data());
}
::Parser::Types::rule_HEX& Parser::get::rule_HEX(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_HEX) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_HEX, "Parser");
	return std::any_cast<Types::rule_HEX&>(token.data());
}
const ::Parser::Types::AUTO_19& Parser::get::AUTO_19(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<const Types::AUTO_19&>(token.data());
}
::Parser::Types::AUTO_19& Parser::get::AUTO_19(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_19) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_19, "Parser");
	return std::any_cast<Types::AUTO_19&>(token.data());
}
const ::Parser::Types::AUTO_16& Parser::get::AUTO_16(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<const Types::AUTO_16&>(token.data());
}
::Parser::Types::AUTO_16& Parser::get::AUTO_16(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_16) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_16, "Parser");
	return std::any_cast<Types::AUTO_16&>(token.data());
}
const ::Parser::Types::cll_TEMPLATE& Parser::get::cll_TEMPLATE(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<const Types::cll_TEMPLATE&>(token.data());
}
::Parser::Types::cll_TEMPLATE& Parser::get::cll_TEMPLATE(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_TEMPLATE) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_TEMPLATE, "Parser");
	return std::any_cast<Types::cll_TEMPLATE&>(token.data());
}
const ::Parser::Types::AUTO_12& Parser::get::AUTO_12(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<const Types::AUTO_12&>(token.data());
}
::Parser::Types::AUTO_12& Parser::get::AUTO_12(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_12) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_12, "Parser");
	return std::any_cast<Types::AUTO_12&>(token.data());
}
const ::Parser::Types::AUTO_15& Parser::get::AUTO_15(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<const Types::AUTO_15&>(token.data());
}
::Parser::Types::AUTO_15& Parser::get::AUTO_15(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_15) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_15, "Parser");
	return std::any_cast<Types::AUTO_15&>(token.data());
}
const ::Parser::Types::AUTO_14& Parser::get::AUTO_14(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<const Types::AUTO_14&>(token.data());
}
::Parser::Types::AUTO_14& Parser::get::AUTO_14(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_14) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_14, "Parser");
	return std::any_cast<Types::AUTO_14&>(token.data());
}
const ::Parser::Types::AUTO_17& Parser::get::AUTO_17(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<const Types::AUTO_17&>(token.data());
}
::Parser::Types::AUTO_17& Parser::get::AUTO_17(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_17) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_17, "Parser");
	return std::any_cast<Types::AUTO_17&>(token.data());
}
const ::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<const Types::rule_ESCAPED&>(token.data());
}
::Parser::Types::rule_ESCAPED& Parser::get::rule_ESCAPED(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_ESCAPED) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_ESCAPED, "Parser");
	return std::any_cast<Types::rule_ESCAPED&>(token.data());
}
const ::Parser::Types::AUTO_5& Parser::get::AUTO_5(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_5) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_5, "Parser");
	return std::any_cast<const Types::AUTO_5&>(token.data());
}
::Parser::Types::AUTO_5& Parser::get::AUTO_5(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_5) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_5, "Parser");
	return std::any_cast<Types::AUTO_5&>(token.data());
}
const ::Parser::Types::cll_ASSIGNMENT_OP& Parser::get::cll_ASSIGNMENT_OP(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_ASSIGNMENT_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_ASSIGNMENT_OP, "Parser");
	return std::any_cast<const Types::cll_ASSIGNMENT_OP&>(token.data());
}
::Parser::Types::cll_ASSIGNMENT_OP& Parser::get::cll_ASSIGNMENT_OP(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::cll_ASSIGNMENT_OP) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::cll_ASSIGNMENT_OP, "Parser");
	return std::any_cast<Types::cll_ASSIGNMENT_OP&>(token.data());
}
const ::Parser::Types::AUTO_20& Parser::get::AUTO_20(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<const Types::AUTO_20&>(token.data());
}
::Parser::Types::AUTO_20& Parser::get::AUTO_20(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_20) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_20, "Parser");
	return std::any_cast<Types::AUTO_20&>(token.data());
}
const ::Parser::Types::AUTO_8& Parser::get::AUTO_8(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<const Types::AUTO_8&>(token.data());
}
::Parser::Types::AUTO_8& Parser::get::AUTO_8(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_8) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_8, "Parser");
	return std::any_cast<Types::AUTO_8&>(token.data());
}
const ::Parser::Types::AUTO_21& Parser::get::AUTO_21(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_21) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_21, "Parser");
	return std::any_cast<const Types::AUTO_21&>(token.data());
}
::Parser::Types::AUTO_21& Parser::get::AUTO_21(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_21) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_21, "Parser");
	return std::any_cast<Types::AUTO_21&>(token.data());
}
const ::Parser::Types::STRING& Parser::get::STRING(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<const Types::STRING&>(token.data());
}
::Parser::Types::STRING& Parser::get::STRING(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::STRING) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::STRING, "Parser");
	return std::any_cast<Types::STRING&>(token.data());
}
const ::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<const Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
::Parser::Types::rule_CSEQUENCE_SYMBOL& Parser::get::rule_CSEQUENCE_SYMBOL(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::rule_CSEQUENCE_SYMBOL) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::rule_CSEQUENCE_SYMBOL, "Parser");
	return std::any_cast<Types::rule_CSEQUENCE_SYMBOL&>(token.data());
}
const ::Parser::Types::AUTO_23& Parser::get::AUTO_23(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_23) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_23, "Parser");
	return std::any_cast<const Types::AUTO_23&>(token.data());
}
::Parser::Types::AUTO_23& Parser::get::AUTO_23(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_23) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_23, "Parser");
	return std::any_cast<Types::AUTO_23&>(token.data());
}
const ::Parser::Types::ID& Parser::get::ID(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<const Types::ID&>(token.data());
}
::Parser::Types::ID& Parser::get::ID(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::ID) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::ID, "Parser");
	return std::any_cast<Types::ID&>(token.data());
}
const ::Parser::Types::AUTO_22& Parser::get::AUTO_22(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_22) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_22, "Parser");
	return std::any_cast<const Types::AUTO_22&>(token.data());
}
::Parser::Types::AUTO_22& Parser::get::AUTO_22(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_22) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_22, "Parser");
	return std::any_cast<Types::AUTO_22&>(token.data());
}
const ::Parser::Types::AUTO_6& Parser::get::AUTO_6(const ::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<const Types::AUTO_6&>(token.data());
}
::Parser::Types::AUTO_6& Parser::get::AUTO_6(::Parser::Token &token) {
	if (token.name() != ::Parser::Tokens::AUTO_6) throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::AUTO_6, "Parser");
	return std::any_cast<Types::AUTO_6&>(token.data());
}
const ::Parser::Types::rule_data_block_regular_datablock_key& Parser::get::rule_data_block_regular_datablock_key(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<const Types::rule_data_block_regular_datablock_key&>(rule.data());
}
::Parser::Types::rule_data_block_regular_datablock_key& Parser::get::rule_data_block_regular_datablock_key(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock_key) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock_key, "Parser");
	return std::any_cast<Types::rule_data_block_regular_datablock_key&>(rule.data());
}
const ::Parser::Types::cll_function_body_call& Parser::get::cll_function_body_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<const Types::cll_function_body_call&>(rule.data());
}
::Parser::Types::cll_function_body_call& Parser::get::cll_function_body_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_call, "Parser");
	return std::any_cast<Types::cll_function_body_call&>(rule.data());
}
const ::Parser::Types::rule_data_block& Parser::get::rule_data_block(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block, "Parser");
	return std::any_cast<const Types::rule_data_block&>(rule.data());
}
::Parser::Types::rule_data_block& Parser::get::rule_data_block(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block, "Parser");
	return std::any_cast<Types::rule_data_block&>(rule.data());
}
const ::Parser::Types::cll_function_call& Parser::get::cll_function_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_call, "Parser");
	return std::any_cast<const Types::cll_function_call&>(rule.data());
}
::Parser::Types::cll_function_call& Parser::get::cll_function_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_call, "Parser");
	return std::any_cast<Types::cll_function_call&>(rule.data());
}
const ::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<const Types::cll_function_decl&>(rule.data());
}
::Parser::Types::cll_function_decl& Parser::get::cll_function_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_decl, "Parser");
	return std::any_cast<Types::cll_function_decl&>(rule.data());
}
const ::Parser::Types::cll_expr& Parser::get::cll_expr(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<const Types::cll_expr&>(rule.data());
}
::Parser::Types::cll_expr& Parser::get::cll_expr(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr, "Parser");
	return std::any_cast<Types::cll_expr&>(rule.data());
}
const ::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<const Types::cll_expr_term&>(rule.data());
}
::Parser::Types::cll_expr_term& Parser::get::cll_expr_term(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_term) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_term, "Parser");
	return std::any_cast<Types::cll_expr_term&>(rule.data());
}
const ::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<const Types::cll_expr_logical&>(rule.data());
}
::Parser::Types::cll_expr_logical& Parser::get::cll_expr_logical(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_logical) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_logical, "Parser");
	return std::any_cast<Types::cll_expr_logical&>(rule.data());
}
const ::Parser::Types::cll__var& Parser::get::cll__var(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<const Types::cll__var&>(rule.data());
}
::Parser::Types::cll__var& Parser::get::cll__var(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__var) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__var, "Parser");
	return std::any_cast<Types::cll__var&>(rule.data());
}
const ::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<const Types::cll_loop_while&>(rule.data());
}
::Parser::Types::cll_loop_while& Parser::get::cll_loop_while(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_while) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_while, "Parser");
	return std::any_cast<Types::cll_loop_while&>(rule.data());
}
const ::Parser::Types::cll_loop_for& Parser::get::cll_loop_for(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<const Types::cll_loop_for&>(rule.data());
}
::Parser::Types::cll_loop_for& Parser::get::cll_loop_for(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_loop_for) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_loop_for, "Parser");
	return std::any_cast<Types::cll_loop_for&>(rule.data());
}
const ::Parser::Types::cll__variable& Parser::get::cll__variable(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<const Types::cll__variable&>(rule.data());
}
::Parser::Types::cll__variable& Parser::get::cll__variable(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__variable) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__variable, "Parser");
	return std::any_cast<Types::cll__variable&>(rule.data());
}
const ::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<const Types::rule_nested_rule&>(rule.data());
}
::Parser::Types::rule_nested_rule& Parser::get::rule_nested_rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_nested_rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_nested_rule, "Parser");
	return std::any_cast<Types::rule_nested_rule&>(rule.data());
}
const ::Parser::Types::rvalue& Parser::get::rvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rvalue, "Parser");
	return std::any_cast<const Types::rvalue&>(rule.data());
}
::Parser::Types::rvalue& Parser::get::rvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rvalue, "Parser");
	return std::any_cast<Types::rvalue&>(rule.data());
}
const ::Parser::Types::_use_unit& Parser::get::_use_unit(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use_unit, "Parser");
	return std::any_cast<const Types::_use_unit&>(rule.data());
}
::Parser::Types::_use_unit& Parser::get::_use_unit(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use_unit) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use_unit, "Parser");
	return std::any_cast<Types::_use_unit&>(rule.data());
}
const ::Parser::Types::moduleImport_from_import_list& Parser::get::moduleImport_from_import_list(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from_import_list) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from_import_list, "Parser");
	return std::any_cast<const Types::moduleImport_from_import_list&>(rule.data());
}
::Parser::Types::moduleImport_from_import_list& Parser::get::moduleImport_from_import_list(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from_import_list) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from_import_list, "Parser");
	return std::any_cast<Types::moduleImport_from_import_list&>(rule.data());
}
const ::Parser::Types::_use& Parser::get::_use(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use, "Parser");
	return std::any_cast<const Types::_use&>(rule.data());
}
::Parser::Types::_use& Parser::get::_use(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::_use) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::_use, "Parser");
	return std::any_cast<Types::_use&>(rule.data());
}
const ::Parser::Types::cll_expr_arithmetic& Parser::get::cll_expr_arithmetic(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<const Types::cll_expr_arithmetic&>(rule.data());
}
::Parser::Types::cll_expr_arithmetic& Parser::get::cll_expr_arithmetic(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_arithmetic) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_arithmetic, "Parser");
	return std::any_cast<Types::cll_expr_arithmetic&>(rule.data());
}
const ::Parser::Types::rule& Parser::get::rule(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule, "Parser");
	return std::any_cast<const Types::rule&>(rule.data());
}
::Parser::Types::rule& Parser::get::rule(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule, "Parser");
	return std::any_cast<Types::rule&>(rule.data());
}
const ::Parser::Types::main& Parser::get::main(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<const Types::main&>(rule.data());
}
::Parser::Types::main& Parser::get::main(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::main) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::main, "Parser");
	return std::any_cast<Types::main&>(rule.data());
}
const ::Parser::Types::array& Parser::get::array(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<const Types::array&>(rule.data());
}
::Parser::Types::array& Parser::get::array(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::array) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::array, "Parser");
	return std::any_cast<Types::array&>(rule.data());
}
const ::Parser::Types::rule_member& Parser::get::rule_member(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_member) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_member, "Parser");
	return std::any_cast<const Types::rule_member&>(rule.data());
}
::Parser::Types::rule_member& Parser::get::rule_member(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_member) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_member, "Parser");
	return std::any_cast<Types::rule_member&>(rule.data());
}
const ::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<const Types::rule_data_block_templated_datablock&>(rule.data());
}
::Parser::Types::rule_data_block_templated_datablock& Parser::get::rule_data_block_templated_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_templated_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_templated_datablock, "Parser");
	return std::any_cast<Types::rule_data_block_templated_datablock&>(rule.data());
}
const ::Parser::Types::rule_group& Parser::get::rule_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<const Types::rule_group&>(rule.data());
}
::Parser::Types::rule_group& Parser::get::rule_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_group, "Parser");
	return std::any_cast<Types::rule_group&>(rule.data());
}
const ::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<const Types::cll_expr_value&>(rule.data());
}
::Parser::Types::cll_expr_value& Parser::get::cll_expr_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_value, "Parser");
	return std::any_cast<Types::cll_expr_value&>(rule.data());
}
const ::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<const Types::cll_function_body_decl&>(rule.data());
}
::Parser::Types::cll_function_body_decl& Parser::get::cll_function_body_decl(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_body_decl) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_body_decl, "Parser");
	return std::any_cast<Types::cll_function_body_decl&>(rule.data());
}
const ::Parser::Types::rule_name& Parser::get::rule_name(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<const Types::rule_name&>(rule.data());
}
::Parser::Types::rule_name& Parser::get::rule_name(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_name) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_name, "Parser");
	return std::any_cast<Types::rule_name&>(rule.data());
}
const ::Parser::Types::rule_data_block_regular_datablock& Parser::get::rule_data_block_regular_datablock(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock, "Parser");
	return std::any_cast<const Types::rule_data_block_regular_datablock&>(rule.data());
}
::Parser::Types::rule_data_block_regular_datablock& Parser::get::rule_data_block_regular_datablock(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_data_block_regular_datablock) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_data_block_regular_datablock, "Parser");
	return std::any_cast<Types::rule_data_block_regular_datablock&>(rule.data());
}
const ::Parser::Types::moduleImport& Parser::get::moduleImport(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport, "Parser");
	return std::any_cast<const Types::moduleImport&>(rule.data());
}
::Parser::Types::moduleImport& Parser::get::moduleImport(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport, "Parser");
	return std::any_cast<Types::moduleImport&>(rule.data());
}
const ::Parser::Types::cll_expr_group& Parser::get::cll_expr_group(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<const Types::cll_expr_group&>(rule.data());
}
::Parser::Types::cll_expr_group& Parser::get::cll_expr_group(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_group) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_group, "Parser");
	return std::any_cast<Types::cll_expr_group&>(rule.data());
}
const ::Parser::Types::cll& Parser::get::cll(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<const Types::cll&>(rule.data());
}
::Parser::Types::cll& Parser::get::cll(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll, "Parser");
	return std::any_cast<Types::cll&>(rule.data());
}
const ::Parser::Types::moduleDeclaration& Parser::get::moduleDeclaration(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleDeclaration) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleDeclaration, "Parser");
	return std::any_cast<const Types::moduleDeclaration&>(rule.data());
}
::Parser::Types::moduleDeclaration& Parser::get::moduleDeclaration(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleDeclaration) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleDeclaration, "Parser");
	return std::any_cast<Types::moduleDeclaration&>(rule.data());
}
const ::Parser::Types::cll__if& Parser::get::cll__if(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__if, "Parser");
	return std::any_cast<const Types::cll__if&>(rule.data());
}
::Parser::Types::cll__if& Parser::get::cll__if(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll__if) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll__if, "Parser");
	return std::any_cast<Types::cll__if&>(rule.data());
}
const ::Parser::Types::rule_quantifier& Parser::get::rule_quantifier(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_quantifier, "Parser");
	return std::any_cast<const Types::rule_quantifier&>(rule.data());
}
::Parser::Types::rule_quantifier& Parser::get::rule_quantifier(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_quantifier) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_quantifier, "Parser");
	return std::any_cast<Types::rule_quantifier&>(rule.data());
}
const ::Parser::Types::moduleImport_from& Parser::get::moduleImport_from(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from, "Parser");
	return std::any_cast<const Types::moduleImport_from&>(rule.data());
}
::Parser::Types::moduleImport_from& Parser::get::moduleImport_from(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::moduleImport_from) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::moduleImport_from, "Parser");
	return std::any_cast<Types::moduleImport_from&>(rule.data());
}
const ::Parser::Types::rule_value& Parser::get::rule_value(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_value, "Parser");
	return std::any_cast<const Types::rule_value&>(rule.data());
}
::Parser::Types::rule_value& Parser::get::rule_value(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_value) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_value, "Parser");
	return std::any_cast<Types::rule_value&>(rule.data());
}
const ::Parser::Types::object& Parser::get::object(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<const Types::object&>(rule.data());
}
::Parser::Types::object& Parser::get::object(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::object) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::object, "Parser");
	return std::any_cast<Types::object&>(rule.data());
}
const ::Parser::Types::cll_stmt& Parser::get::cll_stmt(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_stmt) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_stmt, "Parser");
	return std::any_cast<const Types::cll_stmt&>(rule.data());
}
::Parser::Types::cll_stmt& Parser::get::cll_stmt(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_stmt) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_stmt, "Parser");
	return std::any_cast<Types::cll_stmt&>(rule.data());
}
const ::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<const Types::cll_expr_compare&>(rule.data());
}
::Parser::Types::cll_expr_compare& Parser::get::cll_expr_compare(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_expr_compare) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_expr_compare, "Parser");
	return std::any_cast<Types::cll_expr_compare&>(rule.data());
}
const ::Parser::Types::cll_method_call& Parser::get::cll_method_call(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<const Types::cll_method_call&>(rule.data());
}
::Parser::Types::cll_method_call& Parser::get::cll_method_call(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_method_call) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_method_call, "Parser");
	return std::any_cast<Types::cll_method_call&>(rule.data());
}
const ::Parser::Types::cll_function_arguments& Parser::get::cll_function_arguments(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<const Types::cll_function_arguments&>(rule.data());
}
::Parser::Types::cll_function_arguments& Parser::get::cll_function_arguments(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_arguments) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_arguments, "Parser");
	return std::any_cast<Types::cll_function_arguments&>(rule.data());
}
const ::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<const Types::rule_keyvalue&>(rule.data());
}
::Parser::Types::rule_keyvalue& Parser::get::rule_keyvalue(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::rule_keyvalue) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::rule_keyvalue, "Parser");
	return std::any_cast<Types::rule_keyvalue&>(rule.data());
}
const ::Parser::Types::cll_function_parameters& Parser::get::cll_function_parameters(const ::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<const Types::cll_function_parameters&>(rule.data());
}
::Parser::Types::cll_function_parameters& Parser::get::cll_function_parameters(::Parser::Rule &rule) {
	if (rule.name() != ::Parser::Rules::cll_function_parameters) throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::cll_function_parameters, "Parser");
	return std::any_cast<Types::cll_function_parameters&>(rule.data());
}
const Parser::DFA::TokenTable<36, 11> Parser::Parser::dfa_table_0 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 10, 1}, {Tokens::AUTO_20, 18, ::Parser::DFA::null_state}, {Tokens::ID, 16, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 6, 4}, {Tokens::STRING, 5, 4}, {Tokens::AT, 4, 4}, {Tokens::AUTO_0, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 2, ::Parser::DFA::null_state}, {Tokens::NUMBER, 1, 4}} },
{ 2, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 22, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 12, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 11, ::Parser::DFA::null_state}, {Tokens::MINUS, 11, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 11, ::Parser::DFA::null_state}, {Tokens::MODULO, 11, ::Parser::DFA::null_state}, {Tokens::PLUS, 11, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 24, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 14, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 28, ::Parser::DFA::null_state}, {Tokens::ID, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 14, ::Parser::DFA::null_state}, {Tokens::NUMBER, 15, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 12, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 11, ::Parser::DFA::null_state}, {Tokens::MINUS, 11, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 11, ::Parser::DFA::null_state}, {Tokens::MODULO, 11, ::Parser::DFA::null_state}, {Tokens::PLUS, 11, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}} },
{ 6, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 12, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 11, ::Parser::DFA::null_state}, {Tokens::MINUS, 11, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 11, ::Parser::DFA::null_state}, {Tokens::MODULO, 11, ::Parser::DFA::null_state}, {Tokens::PLUS, 11, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}} },
{ 7, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 12, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 11, ::Parser::DFA::null_state}, {Tokens::MINUS, 11, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 11, ::Parser::DFA::null_state}, {Tokens::MODULO, 11, ::Parser::DFA::null_state}, {Tokens::PLUS, 11, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 12, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 11, ::Parser::DFA::null_state}, {Tokens::MINUS, 11, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 11, ::Parser::DFA::null_state}, {Tokens::MODULO, 11, ::Parser::DFA::null_state}, {Tokens::PLUS, 11, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::ID, 8, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 10, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 8, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 32, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 10, 1}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 6, 4}, {Tokens::STRING, 5, 4}, {Tokens::AT, 4, 4}, {Tokens::AUTO_0, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 2, ::Parser::DFA::null_state}, {Tokens::NUMBER, 1, 4}} },
{ 8, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 34, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 8, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 8, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 12, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 11, ::Parser::DFA::null_state}, {Tokens::MINUS, 11, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 11, ::Parser::DFA::null_state}, {Tokens::MODULO, 11, ::Parser::DFA::null_state}, {Tokens::PLUS, 11, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 8, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::AUTO_14, 12, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 17, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 8, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 8, 0, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::ID, 8, 0}} },
{ 8, 0, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::ID, 8, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 8, 0}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 23, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 8, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 8, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 8, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 8, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::ID, 8, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 31, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, ::Parser::DFA::null_state}, {Tokens::DOT, 8, 2}, {Tokens::AUTO_14, 12, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 33, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 8, 1}} },
{ 8, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 35, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 8, ::Parser::DFA::null_state}} },
{ 8, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<7, 3> Parser::Parser::dfa_table_1 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 2, 0}, {Tokens::ID, 1, 1}} },
{ 2, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 4, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::ID, 2, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 4, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 2, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 2, 0}} },
{ 2, 1, {
} },
};
const Parser::DFA::CharTable<9, 8> Parser::Parser::dfa_table_2 = {{ 0, ::Parser::DFA::null_state, {
{'f', 2, 0}, {'\f', 0, 0}, {'t', 1, 1}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'a', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'u', 5, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 6, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 7, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'s', 8, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'e', 7, 0}} },
};
const Parser::DFA::CharTable<3, 8> Parser::Parser::dfa_table_3 = {{ 0, ::Parser::DFA::null_state, {
{'\f', 0, 0}, {']', 2, 1}, {'\v', 0, 0}, {'\r', 0, 0}, {'\\', 1, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'\\', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<4, 4> Parser::Parser::dfa_table_4 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 1, 0}, {Tokens::PLUS, 1, 1}, {Tokens::MULTIPLE, 1, 2}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 1, 0}} },
{ 1, 2, {
} },
};
const Parser::DFA::TokenTable<41, 11> Parser::Parser::dfa_table_5 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 24, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 22, ::Parser::DFA::null_state}, {Tokens::ID, 20, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 18, ::Parser::DFA::null_state}, {Tokens::STRING, 16, ::Parser::DFA::null_state}, {Tokens::AT, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 1, ::Parser::DFA::null_state}, {Tokens::NUMBER, 12, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 28, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 9, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 30, ::Parser::DFA::null_state}, {Tokens::ID, 10, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 9, ::Parser::DFA::null_state}, {Tokens::NUMBER, 10, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 4, ::Parser::DFA::null_state}, {Tokens::AUTO_21, 3, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::ID, 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::NUMBER, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 5, ::Parser::DFA::null_state}, {Tokens::ID, 37, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 9, ::Parser::DFA::null_state}, {Tokens::STRING, 9, ::Parser::DFA::null_state}, {Tokens::AT, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 1, ::Parser::DFA::null_state}, {Tokens::NUMBER, 9, ::Parser::DFA::null_state}} },
{ 3, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 39, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 8, 0}, {Tokens::DIVIDE, 8, 0}, {Tokens::MINUS, 8, 0}, {Tokens::MULTIPLE, 8, 0}, {Tokens::cll_LOGICAL_OP, 8, 0}, {Tokens::MODULO, 8, 0}, {Tokens::PLUS, 8, 0}, {Tokens::ID, 4, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 10, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 8, 0}, {Tokens::ID, 3, 1}} },
{ 3, 1, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 15, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 8, 0}, {Tokens::ID, 3, 1}} },
{ 3, 1, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 17, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 8, 0}, {Tokens::ID, 3, 1}} },
{ 3, 1, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 19, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 8, 0}, {Tokens::ID, 3, 1}} },
{ 3, 1, {
} },
{ 3, 1, {
{Tokens::AUTO_13, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 3, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 21, ::Parser::DFA::null_state}, {Tokens::PLUS, 8, 0}, {Tokens::ID, 4, 1}} },
{ 3, ::Parser::DFA::null_state, {
} },
{ 3, 0, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::ID, 3, 0}} },
{ 3, 0, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::ID, 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 3, 0}} },
{ 3, 1, {
} },
{ 3, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 3, ::Parser::DFA::null_state}} },
{ 3, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 3, ::Parser::DFA::null_state}} },
{ 3, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 31, ::Parser::DFA::null_state}, {Tokens::ID, 3, ::Parser::DFA::null_state}} },
{ 3, ::Parser::DFA::null_state, {
} },
{ 3, 1, {
} },
{ 3, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 34, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 3, 0}} },
{ 3, 1, {
} },
{ 3, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 36, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 3, 0}} },
{ 3, 1, {
} },
{ 3, ::Parser::DFA::null_state, {
{Tokens::AUTO_13, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 35, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 38, ::Parser::DFA::null_state}, {Tokens::PLUS, 8, 0}, {Tokens::ID, 4, 1}, {Tokens::AUTO_20, 33, ::Parser::DFA::null_state}, {Tokens::DOT, 3, 0}} },
{ 3, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 32, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 40, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 3, 0}} },
{ 3, 1, {
} },
};
const Parser::DFA::TokenTable<8, 3> Parser::Parser::dfa_table_6 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::AT, 2, 0}, {Tokens::AUTO_23, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 1, ::Parser::DFA::null_state}, {Tokens::ID, 4, 1}} },
{ 3, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::ID, 4, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, 0}, {Tokens::AT, 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 4, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::ID, 4, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::AT, 4, 0}} },
{ 4, 1, {
} },
};
const Parser::DFA::TokenTable<89, 19> Parser::Parser::dfa_table_7 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 36, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 1, 5}, {Tokens::rule_CSEQUENCE, 1, 7}, {Tokens::rule_NOSPACE, 1, 0}, {Tokens::rule_HEX, 1, 3}, {Tokens::DOT, 1, 8}, {Tokens::AUTO_3, 35, ::Parser::DFA::null_state}, {Tokens::ID, 33, ::Parser::DFA::null_state}, {Tokens::STRING, 1, 2}, {Tokens::rule_BIN, 1, 4}, {Tokens::AUTO_12, 3, 10}, {Tokens::rule_ESCAPED, 1, 1}, {Tokens::rule_OP, 1, 6}, {Tokens::AUTO_5, 32, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, 11}, {Tokens::ID, 1, 11}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 47, ::Parser::DFA::null_state}, {Tokens::AUTO_18, 45, ::Parser::DFA::null_state}, {Tokens::AUTO_17, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 12, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 44, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 11, ::Parser::DFA::null_state}, {Tokens::AT, 9, ::Parser::DFA::null_state}, {Tokens::ID, 42, ::Parser::DFA::null_state}, {Tokens::STRING, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 10, ::Parser::DFA::null_state}, {Tokens::NUMBER, 9, ::Parser::DFA::null_state}, {Tokens::cll_TYPE, 38, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 39, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_15, 40, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 4, 10}, {Tokens::AUTO_12, 1, 10}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, 11}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::NUMBER, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 8, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 53, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 23, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 26, ::Parser::DFA::null_state}, {Tokens::MINUS, 23, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 23, ::Parser::DFA::null_state}, {Tokens::PLUS, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 52, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 23, ::Parser::DFA::null_state}, {Tokens::MODULO, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 50, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 55, ::Parser::DFA::null_state}, {Tokens::ID, 28, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 9, ::Parser::DFA::null_state}, {Tokens::NUMBER, 28, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 59, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 57, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 9, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 15, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 3, 10}, {Tokens::AUTO_5, 2, 11}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 14, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::rule_CSEQUENCE, 14, ::Parser::DFA::null_state}, {Tokens::AT, 4, 10}, {Tokens::STRING, 14, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::DOT, 18, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 73, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 71, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 69, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 3, 10}, {Tokens::rule_ESCAPED, 67, ::Parser::DFA::null_state}, {Tokens::rule_OP, 65, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 63, ::Parser::DFA::null_state}, {Tokens::PLUS, 61, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 18, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 19, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::DOT, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 77, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 75, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 6, ::Parser::DFA::null_state}, {Tokens::ID, 79, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 9, ::Parser::DFA::null_state}, {Tokens::STRING, 9, ::Parser::DFA::null_state}, {Tokens::AT, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 10, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 12, ::Parser::DFA::null_state}, {Tokens::NUMBER, 9, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 14, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::rule_CSEQUENCE, 14, ::Parser::DFA::null_state}, {Tokens::AT, 5, 11}, {Tokens::STRING, 14, ::Parser::DFA::null_state}, {Tokens::ID, 14, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::DOT, 14, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 14, ::Parser::DFA::null_state}, {Tokens::rule_ESCAPED, 14, ::Parser::DFA::null_state}, {Tokens::rule_OP, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 3, 10}, {Tokens::AUTO_5, 2, 11}, {Tokens::QUESTION_MARK, 14, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 14, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 14, ::Parser::DFA::null_state}, {Tokens::PLUS, 14, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 28, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 5, 11}, {Tokens::rule_CSEQUENCE, 5, 11}, {Tokens::rule_NOSPACE, 5, 11}, {Tokens::rule_HEX, 5, 11}, {Tokens::DOT, 5, 11}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::STRING, 5, 11}, {Tokens::rule_BIN, 5, 11}, {Tokens::AUTO_12, 3, 10}, {Tokens::rule_ESCAPED, 5, 11}, {Tokens::rule_OP, 5, 11}, {Tokens::AUTO_5, 2, 11}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, 11}, {Tokens::LINEAR_COMMENT, 5, 11}, {Tokens::rule_CSEQUENCE, 5, 11}, {Tokens::rule_NOSPACE, 5, 11}, {Tokens::rule_HEX, 5, 11}, {Tokens::rule_ESCAPED, 5, 11}, {Tokens::rule_OP, 5, 11}, {Tokens::AUTO_12, 3, 10}, {Tokens::STRING, 85, ::Parser::DFA::null_state}, {Tokens::ID, 87, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::rule_BIN, 83, ::Parser::DFA::null_state}, {Tokens::DOT, 81, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}} },
{ 1, 11, {
{Tokens::__WHITESPACE, 2, 11}, {Tokens::ID, 1, 11}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 34, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::AT, 16, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::DOT, 18, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 19, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 5, 11}} },
{ 1, 10, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::AT, 16, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::rule_HEX, 14, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 4, 10}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 5, 11}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 37, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 1, 0}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 5, 11}} },
{ 1, 10, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 8, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 41, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 43, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 24, 10}, {Tokens::MULTIPLE, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 26, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 46, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 48, ::Parser::DFA::null_state}, {Tokens::AUTO_18, 1, ::Parser::DFA::null_state}, {Tokens::ID, 22, ::Parser::DFA::null_state}, {Tokens::cll_TYPE, 8, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::AT, 31, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::PLUS, 14, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::DOT, 18, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::AUTO_12, 3, 10}, {Tokens::ID, 17, 11}} },
{ 1, 10, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 10, ::Parser::DFA::null_state}, {Tokens::ID, 51, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 3, 10}, {Tokens::AUTO_5, 2, 11}, {Tokens::AUTO_13, 12, ::Parser::DFA::null_state}, {Tokens::AT, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 11, ::Parser::DFA::null_state}, {Tokens::NUMBER, 9, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 19, ::Parser::DFA::null_state}, {Tokens::PLUS, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::DOT, 18, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 54, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 56, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 58, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 60, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 62, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 64, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 66, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 68, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 70, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 72, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 74, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 10, ::Parser::DFA::null_state}, {Tokens::ID, 76, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 3, 10}, {Tokens::AUTO_5, 2, 11}, {Tokens::AUTO_13, 12, ::Parser::DFA::null_state}, {Tokens::AT, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 11, ::Parser::DFA::null_state}, {Tokens::NUMBER, 9, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 19, ::Parser::DFA::null_state}, {Tokens::PLUS, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::DOT, 18, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 78, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 80, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 24, 10}, {Tokens::MULTIPLE, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 26, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 82, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::AT, 29, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, 11, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 84, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::AT, 29, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, 11, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 86, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::AT, 29, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, 11, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 88, ::Parser::DFA::null_state}, {Tokens::DOT, 18, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 15, ::Parser::DFA::null_state}, {Tokens::AT, 29, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, 9}, {Tokens::MULTIPLE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 2, 11}, {Tokens::ID, 49, ::Parser::DFA::null_state}} },
{ 1, 11, {
} },
};
const Parser::DFA::TokenTable<6, 5> Parser::Parser::dfa_table_8 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 4, ::Parser::DFA::null_state}, {Tokens::SPACEMODE, 3, 0}, {Tokens::NAME, 3, 1}, {Tokens::AUTO_8, 2, 2}, {Tokens::ID, 1, 3}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 3, 3}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::ID, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::SPACEMODE, 3, 0}} },
{ 3, 3, {
} },
};
const Parser::DFA::CharTable<4, 8> Parser::Parser::dfa_table_9 = {{ 0, ::Parser::DFA::null_state, {
{'n', 2, 0}, {'\t', 0, 0}, {'\r', 0, 0}, {'!', 1, 1}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'o', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'t', 1, 0}} },
};
const Parser::DFA::TokenTable<134, 20> Parser::Parser::dfa_table_10 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 44, ::Parser::DFA::null_state}, {Tokens::AUTO_18, 42, ::Parser::DFA::null_state}, {Tokens::AUTO_17, 10, 3}, {Tokens::AUTO_13, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 41, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 8, ::Parser::DFA::null_state}, {Tokens::AT, 5, ::Parser::DFA::null_state}, {Tokens::ID, 39, ::Parser::DFA::null_state}, {Tokens::STRING, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 7, ::Parser::DFA::null_state}, {Tokens::NUMBER, 5, ::Parser::DFA::null_state}, {Tokens::cll_TYPE, 35, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 36, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_15, 37, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::ID, 1, 4}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::NUMBER, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 4, 1}, {Tokens::ID, 1, 1}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 50, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 13, 4}, {Tokens::DIVIDE, 13, 4}, {Tokens::AUTO_0, 16, ::Parser::DFA::null_state}, {Tokens::MINUS, 13, 4}, {Tokens::MULTIPLE, 13, 4}, {Tokens::PLUS, 13, 4}, {Tokens::AUTO_4, 49, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 13, 4}, {Tokens::MODULO, 13, 4}, {Tokens::AUTO_7, 46, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 52, ::Parser::DFA::null_state}, {Tokens::ID, 18, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, ::Parser::DFA::null_state}, {Tokens::NUMBER, 18, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 56, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 54, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 10, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 1, 3}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 11, 3}, {Tokens::AUTO_15, 1, 3}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 61, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 13, 3}, {Tokens::AUTO_7, 58, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 2, ::Parser::DFA::null_state}, {Tokens::ID, 63, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 5, ::Parser::DFA::null_state}, {Tokens::STRING, 5, ::Parser::DFA::null_state}, {Tokens::AT, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 9, ::Parser::DFA::null_state}, {Tokens::NUMBER, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 95, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 93, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE, 91, ::Parser::DFA::null_state}, {Tokens::AT, 88, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::STRING, 86, ::Parser::DFA::null_state}, {Tokens::ID, 84, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 82, ::Parser::DFA::null_state}, {Tokens::rule_ESCAPED, 80, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}, {Tokens::DOT, 78, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 76, ::Parser::DFA::null_state}, {Tokens::rule_OP, 74, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 73, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 69, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 71, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 67, ::Parser::DFA::null_state}, {Tokens::PLUS, 65, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 20, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE, 20, ::Parser::DFA::null_state}, {Tokens::AT, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 20, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 20, ::Parser::DFA::null_state}, {Tokens::DOT, 20, ::Parser::DFA::null_state}, {Tokens::STRING, 20, ::Parser::DFA::null_state}, {Tokens::ID, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::rule_ESCAPED, 20, ::Parser::DFA::null_state}, {Tokens::rule_OP, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 17, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 18, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 21, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 11, 3}, {Tokens::AUTO_17, 10, 3}, {Tokens::AUTO_19, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 2, ::Parser::DFA::null_state}, {Tokens::AT, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 8, ::Parser::DFA::null_state}, {Tokens::ID, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 7, ::Parser::DFA::null_state}, {Tokens::STRING, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 9, ::Parser::DFA::null_state}, {Tokens::NUMBER, 5, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_15, 3, ::Parser::DFA::null_state}, {Tokens::cll_TYPE, 4, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 23, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 24, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::DOT, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 28, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 28, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 19, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE, 19, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 19, ::Parser::DFA::null_state}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::STRING, 19, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 19, ::Parser::DFA::null_state}, {Tokens::DOT, 19, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::rule_ESCAPED, 19, ::Parser::DFA::null_state}, {Tokens::rule_OP, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 124, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 122, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE, 120, ::Parser::DFA::null_state}, {Tokens::AT, 118, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::STRING, 116, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 114, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}, {Tokens::DOT, 112, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 110, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 108, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 106, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::rule_ESCAPED, 104, ::Parser::DFA::null_state}, {Tokens::rule_OP, 102, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 100, ::Parser::DFA::null_state}, {Tokens::PLUS, 98, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 19, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 19, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE, 19, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 19, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 19, ::Parser::DFA::null_state}, {Tokens::DOT, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}, {Tokens::STRING, 19, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::rule_ESCAPED, 19, ::Parser::DFA::null_state}, {Tokens::rule_OP, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 31, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 132, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 130, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}, {Tokens::PLUS, 128, ::Parser::DFA::null_state}, {Tokens::AT, 28, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 126, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}, {Tokens::DOT, 31, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}, {Tokens::PLUS, 20, ::Parser::DFA::null_state}, {Tokens::AT, 28, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 20, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 28, ::Parser::DFA::null_state}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}} },
{ 1, 1, {
{Tokens::__WHITESPACE, 4, 1}, {Tokens::ID, 1, 1}} },
{ 1, 4, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::ID, 1, 4}} },
{ 1, 3, {
{Tokens::__WHITESPACE, 38, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, 4}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 40, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 1, 3}, {Tokens::AUTO_7, 14, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 13, 4}, {Tokens::AUTO_13, 17, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 16, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, 4, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::ID, 1, 4}} },
{ 1, 0, {
{Tokens::__WHITESPACE, 43, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, 4}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 45, ::Parser::DFA::null_state}, {Tokens::AUTO_18, 1, 0}, {Tokens::ID, 12, 1}, {Tokens::cll_TYPE, 4, 1}} },
{ 1, 3, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 7, ::Parser::DFA::null_state}, {Tokens::ID, 48, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 9, ::Parser::DFA::null_state}, {Tokens::AT, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 47, ::Parser::DFA::null_state}, {Tokens::NUMBER, 5, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 23, ::Parser::DFA::null_state}, {Tokens::PLUS, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, 3, {
{Tokens::__WHITESPACE, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 51, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, 4}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 53, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 55, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 57, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 7, ::Parser::DFA::null_state}, {Tokens::ID, 60, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 9, ::Parser::DFA::null_state}, {Tokens::AT, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 59, ::Parser::DFA::null_state}, {Tokens::NUMBER, 5, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 23, ::Parser::DFA::null_state}, {Tokens::PLUS, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 62, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 1, 3}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 64, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 14, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 13, 4}, {Tokens::AUTO_13, 17, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 16, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 66, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 68, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 70, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 72, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 21, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 75, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 77, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 79, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 81, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 83, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 85, ::Parser::DFA::null_state}, {Tokens::DOT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 87, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 90, ::Parser::DFA::null_state}, {Tokens::ID, 89, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::rule_OP, 32, ::Parser::DFA::null_state}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 92, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 94, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 96, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::AT, 34, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}, {Tokens::DOT, 31, ::Parser::DFA::null_state}, {Tokens::PLUS, 20, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::ID, 29, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 99, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 101, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 103, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 105, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 107, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 109, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 111, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 113, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE, 91, ::Parser::DFA::null_state}, {Tokens::LINEAR_COMMENT, 93, ::Parser::DFA::null_state}, {Tokens::rule_BIN, 82, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::AT, 88, ::Parser::DFA::null_state}, {Tokens::ID, 84, ::Parser::DFA::null_state}, {Tokens::STRING, 86, ::Parser::DFA::null_state}, {Tokens::rule_ESCAPED, 80, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_23, 24, ::Parser::DFA::null_state}, {Tokens::DOT, 78, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 76, ::Parser::DFA::null_state}, {Tokens::rule_OP, 74, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 73, ::Parser::DFA::null_state}, {Tokens::QUESTION_MARK, 69, ::Parser::DFA::null_state}, {Tokens::rule_NOSPACE, 71, ::Parser::DFA::null_state}, {Tokens::rule_HEX, 67, ::Parser::DFA::null_state}, {Tokens::PLUS, 65, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 96, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 19, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 115, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 117, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 119, ::Parser::DFA::null_state}, {Tokens::ID, 30, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::rule_OP, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 121, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 123, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::ID, 97, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 125, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::ID, 33, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::rule_OP, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 127, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::ID, 33, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::rule_OP, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 129, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::AUTO_3, 26, ::Parser::DFA::null_state}, {Tokens::ID, 33, ::Parser::DFA::null_state}, {Tokens::AUTO_12, 22, ::Parser::DFA::null_state}, {Tokens::rule_OP, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_5, 21, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 131, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 133, ::Parser::DFA::null_state}, {Tokens::AT, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<4, 4> Parser::Parser::dfa_table_11 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE_DIAPASON, 1, 0}, {Tokens::rule_CSEQUENCE_ESCAPE, 1, 1}, {Tokens::rule_CSEQUENCE_SYMBOL, 1, 2}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::rule_CSEQUENCE_DIAPASON, 1, 0}} },
{ 1, 2, {
} },
};
const Parser::DFA::TokenTable<33, 10> Parser::Parser::dfa_table_12 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 15, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 1, 0}, {Tokens::ID, 1, 5}, {Tokens::STRING, 1, 1}, {Tokens::AT, 1, 4}, {Tokens::AUTO_0, 3, 2}, {Tokens::AUTO_13, 2, 3}, {Tokens::NUMBER, 1, 6}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 17, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 4, 3}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 21, ::Parser::DFA::null_state}, {Tokens::ID, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, 2}, {Tokens::NUMBER, 5, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 23, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 7, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 7, ::Parser::DFA::null_state}, {Tokens::MINUS, 7, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 8, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 7, ::Parser::DFA::null_state}, {Tokens::MODULO, 7, ::Parser::DFA::null_state}, {Tokens::PLUS, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 6, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 1, 2}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 28, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 12, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 27, ::Parser::DFA::null_state}, {Tokens::ID, 25, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 10, ::Parser::DFA::null_state}, {Tokens::STRING, 10, ::Parser::DFA::null_state}, {Tokens::AT, 10, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 2, 3}, {Tokens::NUMBER, 10, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 31, ::Parser::DFA::null_state}, {Tokens::ID, 13, ::Parser::DFA::null_state}, {Tokens::NUMBER, 13, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 7, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 7, ::Parser::DFA::null_state}, {Tokens::MINUS, 7, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 8, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 7, ::Parser::DFA::null_state}, {Tokens::MODULO, 7, ::Parser::DFA::null_state}, {Tokens::PLUS, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 6, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 11, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 12, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 16, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 1, 0}} },
{ 1, 6, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 18, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 22, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 24, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::AUTO_13, 14, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_7, 6, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 11, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 11, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 30, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 32, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<4, 3> Parser::Parser::dfa_table_13 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, 0}, {Tokens::AUTO_20, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, 0}} },
{ 1, 1, {
} },
};
const Parser::DFA::TokenTable<4, 3> Parser::Parser::dfa_table_14 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, 0}, {Tokens::AUTO_20, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, 0}} },
{ 1, 1, {
} },
};
const Parser::DFA::TokenTable<4, 3> Parser::Parser::dfa_table_15 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::ID, 1, 0}, {Tokens::NUMBER, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::ID, 1, 0}} },
{ 1, 1, {
} },
};
const Parser::DFA::TokenTable<4, 3> Parser::Parser::dfa_table_16 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::ID, 1, 0}, {Tokens::NUMBER, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::ID, 1, 0}} },
{ 1, 1, {
} },
};
const Parser::DFA::TokenTable<4, 4> Parser::Parser::dfa_table_17 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, 0}, {Tokens::MULTIPLE, 1, 1}, {Tokens::MODULO, 1, 2}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, 0}} },
{ 1, 2, {
} },
};
const Parser::DFA::TokenTable<4, 3> Parser::Parser::dfa_table_18 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::MINUS, 1, 0}, {Tokens::PLUS, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::MINUS, 1, 0}} },
{ 1, 1, {
} },
};
const Parser::DFA::CharTable<4, 8> Parser::Parser::dfa_table_19 = {{ 0, ::Parser::DFA::null_state, {
{'|', 2, 0}, {'o', 1, 1}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'|', 3, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<45, 11> Parser::Parser::dfa_table_20 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 2, 0}, {Tokens::AT, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 5, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 28, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 26, ::Parser::DFA::null_state}, {Tokens::ID, 24, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 22, ::Parser::DFA::null_state}, {Tokens::STRING, 20, ::Parser::DFA::null_state}, {Tokens::AT, 18, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 4, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 3, ::Parser::DFA::null_state}, {Tokens::NUMBER, 16, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 32, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 30, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 11, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 34, ::Parser::DFA::null_state}, {Tokens::ID, 12, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 11, ::Parser::DFA::null_state}, {Tokens::NUMBER, 12, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_21, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::ID, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::NUMBER, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 7, ::Parser::DFA::null_state}, {Tokens::ID, 41, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 11, ::Parser::DFA::null_state}, {Tokens::STRING, 11, ::Parser::DFA::null_state}, {Tokens::AT, 11, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 4, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 3, ::Parser::DFA::null_state}, {Tokens::NUMBER, 11, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 43, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 10, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 10, ::Parser::DFA::null_state}, {Tokens::MINUS, 10, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 10, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 10, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, 0}, {Tokens::MODULO, 10, ::Parser::DFA::null_state}, {Tokens::PLUS, 10, ::Parser::DFA::null_state}, {Tokens::ID, 6, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 12, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 5, 0}} },
{ 5, 1, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 17, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, 0}, {Tokens::PLUS, 10, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, 0}, {Tokens::PLUS, 10, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, 0}, {Tokens::PLUS, 10, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 23, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, 0}, {Tokens::PLUS, 10, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::AUTO_13, 13, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, 0}, {Tokens::PLUS, 10, ::Parser::DFA::null_state}, {Tokens::ID, 6, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::ID, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::ID, 5, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 31, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 33, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 35, ::Parser::DFA::null_state}, {Tokens::ID, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 38, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 40, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::AUTO_13, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 39, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 37, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 42, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 5, 0}, {Tokens::PLUS, 10, ::Parser::DFA::null_state}, {Tokens::ID, 6, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 36, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 44, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 5, ::Parser::DFA::null_state}} },
{ 5, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<3, 8> Parser::Parser::dfa_table_21 = {{ 0, ::Parser::DFA::null_state, {
{'\f', 0, 0}, {'\'', 2, 1}, {'\v', 0, 0}, {'\r', 0, 0}, {'\\', 1, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'\\', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::CharTable<18, 9> Parser::Parser::dfa_table_22 = {{ 0, ::Parser::DFA::null_state, {
{'s', 3, 0}, {'a', 2, 1}, {'\t', 0, 0}, {'\v', 0, 0}, {'m', 1, 2}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'i', 4, 2}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 5, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'k', 6, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'x', 7, 2}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 8, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'i', 9, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 10, 2}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 11, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'p', 12, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 13, 2}} },
{ 0, ::Parser::DFA::null_state, {
{'w', 14, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'p', 15, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'e', 16, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'e', 17, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 13, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'d', 13, 0}} },
};
const Parser::DFA::CharTable<6, 10> Parser::Parser::dfa_table_23 = {{ 0, ::Parser::DFA::null_state, {
{'>', 5, ::Parser::DFA::null_state}, {'\f', 0, 0}, {'=', 3, 1}, {'<', 4, ::Parser::DFA::null_state}, {'!', 1, 3}, {'\v', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}, {'\t', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'=', 2, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'=', 2, 0}} },
{ 2, 5, {
{'=', 2, 0}} },
{ 2, 0, {
{'=', 2, 0}} },
};
const Parser::DFA::TokenTable<37, 12> Parser::Parser::dfa_table_24 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 20, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 19, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 7, ::Parser::DFA::null_state}, {Tokens::AT, 3, ::Parser::DFA::null_state}, {Tokens::ID, 17, ::Parser::DFA::null_state}, {Tokens::STRING, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 4, ::Parser::DFA::null_state}, {Tokens::NUMBER, 3, ::Parser::DFA::null_state}, {Tokens::cll_TYPE, 15, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 16, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, 1}, {Tokens::ID, 1, 1}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 22, ::Parser::DFA::null_state}, {Tokens::cll_COMPARE_OP, 11, 0}, {Tokens::DIVIDE, 11, 0}, {Tokens::MINUS, 11, 0}, {Tokens::MULTIPLE, 11, 0}, {Tokens::MODULO, 11, 0}, {Tokens::PLUS, 11, 0}, {Tokens::cll_LOGICAL_OP, 11, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 26, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 24, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 33, ::Parser::DFA::null_state}, {Tokens::ID, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_2, 3, ::Parser::DFA::null_state}, {Tokens::NUMBER, 14, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_4, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 8, ::Parser::DFA::null_state}, {Tokens::ID, 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::NUMBER, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 5, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 11, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 9, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 8, ::Parser::DFA::null_state}, {Tokens::AUTO_3, 7, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 8, ::Parser::DFA::null_state}, {Tokens::ID, 35, ::Parser::DFA::null_state}, {Tokens::BOOLEAN, 3, ::Parser::DFA::null_state}, {Tokens::STRING, 3, ::Parser::DFA::null_state}, {Tokens::AT, 3, ::Parser::DFA::null_state}, {Tokens::AUTO_0, 6, ::Parser::DFA::null_state}, {Tokens::AUTO_13, 4, ::Parser::DFA::null_state}, {Tokens::NUMBER, 3, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 12, 0}, {Tokens::cll_LOGICAL_OP, 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_14, 1, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 14, ::Parser::DFA::null_state}, {Tokens::AUTO_6, 1, ::Parser::DFA::null_state}} },
{ 1, 1, {
{Tokens::__WHITESPACE, 2, 1}, {Tokens::ID, 1, 1}} },
{ 1, 0, {
{Tokens::__WHITESPACE, 8, ::Parser::DFA::null_state}, {Tokens::ID, 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 18, ::Parser::DFA::null_state}, {Tokens::cll_ASSIGNMENT_OP, 1, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, 0}, {Tokens::AUTO_13, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_20, 12, 0}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, 0, {
{Tokens::__WHITESPACE, 8, ::Parser::DFA::null_state}, {Tokens::ID, 1, 0}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 21, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 1, 0}, {Tokens::cll_TYPE, 2, 1}, {Tokens::ID, 10, 1}} },
{ 1, 1, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 23, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, 0}} },
{ 1, 0, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 25, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 27, ::Parser::DFA::null_state}, {Tokens::AUTO_1, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 29, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, 0}} },
{ 1, 0, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 31, ::Parser::DFA::null_state}, {Tokens::DIVIDE, 1, 0}} },
{ 1, 0, {
} },
{ 1, 0, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 34, ::Parser::DFA::null_state}, {Tokens::ID, 1, ::Parser::DFA::null_state}} },
{ 1, ::Parser::DFA::null_state, {
} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::AUTO_13, 13, ::Parser::DFA::null_state}, {Tokens::AUTO_19, 30, ::Parser::DFA::null_state}, {Tokens::__WHITESPACE, 36, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OP, 11, 0}, {Tokens::AUTO_20, 28, ::Parser::DFA::null_state}, {Tokens::DOT, 1, 0}} },
{ 1, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 32, ::Parser::DFA::null_state}} },
};
const Parser::DFA::CharTable<5, 8> Parser::Parser::dfa_table_25 = {{ 0, ::Parser::DFA::null_state, {
{'a', 2, 0}, {'\t', 0, 0}, {'&', 1, 1}, {'\v', 0, 0}, {'\f', 0, 0}, {' ', 0, 0}, {'\n', 0, 0}, {'\r', 0, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'&', 3, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'n', 4, 0}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'d', 3, 0}} },
};
const Parser::DFA::CharTable<16, 13> Parser::Parser::dfa_table_26 = {{ 0, ::Parser::DFA::null_state, {
{'b', 7, 0}, {' ', 0, 5}, {'v', 6, 1}, {'o', 5, 5}, {'s', 4, 2}, {Tokens::cll_TEMPLATE, 15, ::Parser::DFA::null_state}, {'\f', 0, 5}, {'n', 2, 4}, {'\t', 0, 5}, {'a', 1, 5}, {'\v', 0, 5}, {'\r', 0, 5}, {'\n', 0, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 8, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'u', 9, 4}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{'t', 10, 2}} },
{ 0, ::Parser::DFA::null_state, {
{'b', 11, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'a', 12, 1}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 13, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 0, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'m', 3, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'j', 0, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'r', 3, 5}} },
{ 0, ::Parser::DFA::null_state, {
{'o', 14, 0}} },
{ 0, ::Parser::DFA::null_state, {
{'l', 3, 5}} },
{ 3, 5, {
} },
};
const Parser::DFA::TokenTable<8, 3> Parser::Parser::dfa_table_27 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 6, ::Parser::DFA::null_state}, {Tokens::ID, 5, ::Parser::DFA::null_state}, {Tokens::MULTIPLE, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_9, 2, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::ID, 2, 1}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 4, ::Parser::DFA::null_state}, {Tokens::ID, 2, ::Parser::DFA::null_state}} },
{ 2, 0, {
{Tokens::__WHITESPACE, 1, ::Parser::DFA::null_state}, {Tokens::AUTO_9, 3, 1}, {Tokens::AUTO_1, 4, ::Parser::DFA::null_state}} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 7, ::Parser::DFA::null_state}, {Tokens::ID, 2, 0}} },
{ 2, ::Parser::DFA::null_state, {
} },
};
const Parser::DFA::TokenTable<4, 3> Parser::Parser::dfa_table_28 = {{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 2, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OR, 1, 0}, {Tokens::cll_LOGICAL_AND, 1, 1}} },
{ 0, ::Parser::DFA::null_state, {
} },
{ 0, ::Parser::DFA::null_state, {
{Tokens::__WHITESPACE, 3, ::Parser::DFA::null_state}, {Tokens::cll_LOGICAL_OR, 1, 0}} },
{ 1, 1, {
} },
};

Parser::Token Parser::Lexer::makeToken(const char*& pos) {
	return ;
}
Parser::Token_res Parser::Lexer::__WHITESPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	::Parser::bool_t success_2 = false;
	while (*(pos + 0) == ' ' || *(pos + 0) == '\t' || *(pos + 0) == '\n' || *(pos + 0) == '\r' || *(pos + 0) == '\v' || *(pos + 0) == '\f')
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
		success_2 = true;
	}
	if (!success_2)
	{
		reportError(pos, " , \t, \n, \r, \v or \f");
		return {};
	}
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::__WHITESPACE)};
}
Parser::Token_res Parser::Lexer::AUTO_23(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '&'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_23 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_23, data)};
}
Parser::Token_res Parser::Lexer::AUTO_22(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "import", 6) && !(*(pos + 6)>='a' && *(pos + 6)<='z' || *(pos + 6)>='A' && *(pos + 6)<='Z' || *(pos + 6)>='0' && *(pos + 6)<='9' || *(pos + 6) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 6);
	success_1 = true;
	pos += 6;
	skip_spaces(pos);
	::Parser::Types::AUTO_22 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_22, data)};
}
Parser::Token_res Parser::Lexer::AUTO_21(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_21 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_21, data)};
}
Parser::Token_res Parser::Lexer::AUTO_20(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "++", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::Types::AUTO_20 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_20, data)};
}
Parser::Token_res Parser::Lexer::AUTO_18(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "while", 5) && !(*(pos + 5)>='a' && *(pos + 5)<='z' || *(pos + 5)>='A' && *(pos + 5)<='Z' || *(pos + 5)>='0' && *(pos + 5)<='9' || *(pos + 5) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 5);
	success_1 = true;
	pos += 5;
	skip_spaces(pos);
	::Parser::Types::AUTO_18 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_18, data)};
}
Parser::Token_res Parser::Lexer::AUTO_17(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "for", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	skip_spaces(pos);
	::Parser::Types::AUTO_17 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_17, data)};
}
Parser::Token_res Parser::Lexer::AUTO_19(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "--", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::Types::AUTO_19 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_19, data)};
}
Parser::Token_res Parser::Lexer::AUTO_16(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "fn", 2) && !(*(pos + 2)>='a' && *(pos + 2)<='z' || *(pos + 2)>='A' && *(pos + 2)<='Z' || *(pos + 2)>='0' && *(pos + 2)<='9' || *(pos + 2) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::Types::AUTO_16 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_16, data)};
}
Parser::Token_res Parser::Lexer::AUTO_15(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "if", 2) && !(*(pos + 2)>='a' && *(pos + 2)<='z' || *(pos + 2)>='A' && *(pos + 2)<='Z' || *(pos + 2)>='0' && *(pos + 2)<='9' || *(pos + 2) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::Types::AUTO_15 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_15, data)};
}
Parser::Token_res Parser::Lexer::AUTO_14(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_14 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_14, data)};
}
Parser::Token_res Parser::Lexer::AUTO_10(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "module", 6) && !(*(pos + 6)>='a' && *(pos + 6)<='z' || *(pos + 6)>='A' && *(pos + 6)<='Z' || *(pos + 6)>='0' && *(pos + 6)<='9' || *(pos + 6) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 6);
	success_1 = true;
	pos += 6;
	skip_spaces(pos);
	::Parser::Types::AUTO_10 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_10, data)};
}
Parser::Token_res Parser::Lexer::AUTO_8(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "use", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	skip_spaces(pos);
	::Parser::Types::AUTO_8 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_8, data)};
}
Parser::Token_res Parser::Lexer::AUTO_6(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ':'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_6 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_6, data)};
}
Parser::Token_res Parser::Lexer::rule_BIN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "0b", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	while (*(pos + 0) == '0' || *(pos + 0) == '1')
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		reportError(pos, "0 or 1");
		return {};
	}
	skip_spaces(pos);
	::Parser::Types::rule_BIN data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_BIN, data)};
}
Parser::Token_res Parser::Lexer::rule_HEX(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "0x", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	::Parser::bool_t success_4 = false;
	while ((*(pos + 0)>='0' && *(pos + 0)<='9') || (*(pos + 0)>='A' && *(pos + 0)<='F') || (*(pos + 0)>='a' && *(pos + 0)<='f'))
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
		success_4 = true;
	}
	if (!success_4)
	{
		reportError(pos, "0-9, A-F or a-f");
		return {};
	}
	skip_spaces(pos);
	::Parser::Types::rule_HEX data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_HEX, data)};
}
Parser::Token_res Parser::Lexer::rule_ESCAPED(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\\'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	char _2;
	::Parser::bool_t success_3 = false;
	if (*(pos + 0) == '\0')
	{
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::rule_ESCAPED data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_ESCAPED, data)};
}
Parser::Token_res Parser::Lexer::rule_NOSPACE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "\\s0", 3)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 3);
	success_1 = true;
	pos += 3;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_NOSPACE)};
}
Parser::Token_res Parser::Lexer::BOOLEAN(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	auto begin_9 = pos;
	::Parser::str_t d;
	if (success_3)
	{
		success_1 = true;
		d = _0;
		pos = begin_9;
	}
	skip_spaces(pos);
	::Parser::Types::BOOLEAN data = d;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::BOOLEAN, data)};
}
Parser::Token_res Parser::Lexer::AUTO_1(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ','))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_1 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_1, data)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE_ESCAPE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\\'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	char _2;
	::Parser::bool_t success_3 = false;
	if (*(pos + 0) == '\0')
	{
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::rule_CSEQUENCE_ESCAPE data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE_ESCAPE, data)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE_DIAPASON(const char* pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (!(pos->name() == ::Parser::Tokens::rule_CSEQUENCE_SYMBOL))
	{
		return {};
	}
	_0 = *pos;
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	char _2;
	::Parser::bool_t success_3 = false;
	if (!(*(pos + 0) == '-'))
	{
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _4;
	::Parser::bool_t success_5 = false;
	if (!(pos->name() == ::Parser::Tokens::rule_CSEQUENCE_SYMBOL))
	{
		return {};
	}
	_4 = *pos;
	success_5 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::rule_CSEQUENCE_DIAPASON data;
	data.from = _0;
	data.to = _4;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE_DIAPASON, data)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE_SYMBOL(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	dfa_lookup_result_2 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_2)
	{
		case 0: {
			char _3;
			::Parser::bool_t success_4 = false;
			if (!(*(pos + 0) == '\\'))
			{
				return {};
			}
			_3 = *(pos + 0);
			success_4 = true;
			pos += 1;
			skip_spaces(pos);

			break;

		}
		case 1: {
			char _5;
			::Parser::bool_t success_6 = false;
			if (!(!(*(pos + 0) == ']')))
			{
				return {};
			}
			_5 = *(pos + 0);
			success_6 = true;
			pos += 1;
			skip_spaces(pos);

			break;

		}
	}
;
	skip_spaces(pos);
	::Parser::Types::rule_CSEQUENCE_SYMBOL data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE_SYMBOL, data)};
}
Parser::Token_res Parser::Lexer::AUTO_9(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "from", 4) && !(*(pos + 4)>='a' && *(pos + 4)<='z' || *(pos + 4)>='A' && *(pos + 4)<='Z' || *(pos + 4)>='0' && *(pos + 4)<='9' || *(pos + 4) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	skip_spaces(pos);
	::Parser::Types::AUTO_9 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_9, data)};
}
Parser::Token_res Parser::Lexer::AUTO_13(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_13 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_13, data)};
}
Parser::Token_res Parser::Lexer::AUTO_3(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '('))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_3 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_3, data)};
}
Parser::Token_res Parser::Lexer::AUTO_7(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_7 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_7, data)};
}
Parser::Token_res Parser::Lexer::NUMBER(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (*(pos + 0) == '+' || *(pos + 0) == '-')
	{
		_0 += ::Parser::str_t(pos, 1);
		success_1 = true;
		pos += 1;
	}
	skip_spaces(pos);
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	auto begin_7 = pos;
	if (success_5)
	{
		success_3 = true;
		pos = begin_7;
	}
	skip_spaces(pos);
	::Parser::bool_t success_13 = false;
	::Parser::bool_t success_11 = false;
	::Parser::str_t _8;
	::Parser::bool_t success_9 = false;
	auto begin_15 = pos;
	do
	{
		char _10;
		if (!(*(begin_15 + 0) == '.' || *(begin_15 + 0) == ','))
		{
			break;
		}
		_10 = *(begin_15 + 0);
		success_11 = true;
		begin_15 += 1;
		skip_spaces(begin_15);
		::Parser::str_t _12;
		::Parser::bool_t success_14 = false;
		while ((*(begin_15 + 0)>='0' && *(begin_15 + 0)<='9'))
		{
			_12 += ::Parser::str_t(begin_15, 1);
			success_13 = true;
			begin_15 += 1;
			success_14 = true;
		}
		if (!success_14)
		{
			reportError(pos, "0-9");
			break;
		}
		_8 += _10;
		_8 += _12;
	}
	while(0);
	if (success_11 && success_13)
	{
		success_9 = true;
		pos = begin_15;
	}
	skip_spaces(pos);
	::Parser::Types::NUMBER data;
	data.sign = _0;
	data.dec = _8;
	data.main = _2;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NUMBER, data)};
}
Parser::Token_res Parser::Lexer::ID(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	auto begin_6 = pos;
	if (success_3)
	{
		success_1 = true;
		pos = begin_6;
	}
	skip_spaces(pos);
	::Parser::Types::ID data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::ID, data)};
}
Parser::Token_res Parser::Lexer::AUTO_0(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '{'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_0 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_0, data)};
}
Parser::Token_res Parser::Lexer::rule_OP(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '|'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_OP)};
}
Parser::Token_res Parser::Lexer::LINEAR_COMMENT(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "//", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	while (!(*(pos + 0) == 'n' && *(pos + 0) != '\0'))
	{
		_2 += ::Parser::str_t(pos, 1);
		success_3 = true;
		pos += 1;
	}
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::LINEAR_COMMENT)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_NOT(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	dfa_lookup_result_2 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_2)
	{
		case 0: {
			::Parser::str_t _3;
			::Parser::bool_t success_4 = false;
			if (!(!std::strncmp(pos + 0, "not", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
			{
				return {};
			}
			_3 += ::Parser::str_t(pos, 3);
			success_4 = true;
			pos += 3;
			skip_spaces(pos);

			break;

		}
		case 1: {
			char _5;
			::Parser::bool_t success_6 = false;
			if (!(*(pos + 0) == '!'))
			{
				return {};
			}
			_5 = *(pos + 0);
			success_6 = true;
			pos += 1;
			skip_spaces(pos);

			break;

		}
	}
;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_NOT)};
}
Parser::Token_res Parser::Lexer::MODULO(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '%'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MODULO)};
}
Parser::Token_res Parser::Lexer::cll_OP(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	skip_spaces(pos);
	switch (*pos)
	{
		case NONE: {
			char _2;
			::Parser::bool_t success_3 = false;
			if (!(*(pos + 0) == '/'))
			{
				return {};
			}
			_2 = *(pos + 0);
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			_0 = ;

			break;

		}
		case NONE: {
			char _4;
			::Parser::bool_t success_5 = false;
			if (!(*(pos + 0) == '%'))
			{
				return {};
			}
			_4 = *(pos + 0);
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			_0 = ;

			break;

		}
		case NONE: {
			char _6;
			::Parser::bool_t success_7 = false;
			if (!(*(pos + 0) == '/'))
			{
				return {};
			}
			_6 = *(pos + 0);
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			_0 = ;

			break;

		}
		case NONE: {
			char _8;
			::Parser::bool_t success_9 = false;
			if (!(*(pos + 0) == '/'))
			{
				return {};
			}
			_8 = *(pos + 0);
			success_9 = true;
			pos += 1;
			skip_spaces(pos);
			_0 = ;

			break;

		}
		case NONE: {
			char _10;
			::Parser::bool_t success_11 = false;
			if (!(*(pos + 0) == '/'))
			{
				return {};
			}
			_10 = *(pos + 0);
			success_11 = true;
			pos += 1;
			skip_spaces(pos);
			_0 = ;

			break;

		}
	}
;
	skip_spaces(pos);
	::Parser::Types::cll_OP data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_OP, data)};
}
Parser::Token_res Parser::Lexer::MINUS(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '-'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MINUS)};
}
Parser::Token_res Parser::Lexer::PLUS(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '+'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::PLUS)};
}
Parser::Token_res Parser::Lexer::QUESTION_MARK(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '?'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::QUESTION_MARK)};
}
Parser::Token_res Parser::Lexer::rule_CSEQUENCE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '['))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	char _2;
	::Parser::bool_t success_3 = false;
	if (*(pos + 0) == '^')
	{
		_2 = *(pos + 0);
		success_3 = true;
		pos += 1;
	}
	skip_spaces(pos);
	::Parser::bool_t success_7 = 1;
	::Parser::arr_t<::Parser::Rule> shadow_10;
	::Parser::Rule _4;
	::Parser::bool_t success_5 = false;
	auto begin_9 = pos;
	while (1)
	{
		::Parser::Rule_res _6;
		dfa_lookup_result_8 = DFA_DECIDE(begin_9);
		switch (dfa_lookup_result_8)
		{
			case 0: {
				_6 = *begin_9;

				break;

			}
			case 1: {
				_6 = *begin_9;

				break;

			}
			case 2: {
				_6 = *begin_9;

				break;

			}
		}
;
		_4 = _6;
		shadow_10.push_back(_4);
	}
	if (success_7)
	{
		success_5 = true;
		pos = begin_9;
	}
	skip_spaces(pos);
	char _11;
	::Parser::bool_t success_12 = false;
	if (!(*(pos + 0) == ']'))
	{
		return {};
	}
	_11 = *(pos + 0);
	success_12 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::rule_CSEQUENCE data;
	data._not = _2;
	data.val = shadow_10;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::rule_CSEQUENCE, data)};
}
Parser::Token_res Parser::Lexer::MULTIPLE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '*'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::MULTIPLE)};
}
Parser::Token_res Parser::Lexer::AT(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '@'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AT)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_OR(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	dfa_lookup_result_2 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_2)
	{
		case 0: {
			::Parser::str_t _3;
			::Parser::bool_t success_4 = false;
			if (!(!std::strncmp(pos + 0, "||", 2)))
			{
				return {};
			}
			_3 += ::Parser::str_t(pos, 2);
			success_4 = true;
			pos += 2;
			skip_spaces(pos);

			break;

		}
		case 1: {
			::Parser::str_t _5;
			::Parser::bool_t success_6 = false;
			if (!(!std::strncmp(pos + 0, "or", 2) && !(*(pos + 2)>='a' && *(pos + 2)<='z' || *(pos + 2)>='A' && *(pos + 2)<='Z' || *(pos + 2)>='0' && *(pos + 2)<='9' || *(pos + 2) == '_')))
			{
				return {};
			}
			_5 += ::Parser::str_t(pos, 2);
			success_6 = true;
			pos += 2;
			skip_spaces(pos);

			break;

		}
	}
;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_OR)};
}
Parser::Token_res Parser::Lexer::AUTO_11(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "->", 2)))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 2);
	success_1 = true;
	pos += 2;
	skip_spaces(pos);
	::Parser::Types::AUTO_11 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_11, data)};
}
Parser::Token_res Parser::Lexer::DOT(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '.'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::DOT)};
}
Parser::Token_res Parser::Lexer::STRING(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '\''))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_5 = 1;
	::Parser::str_t _2;
	::Parser::bool_t success_3 = false;
	auto begin_16 = pos;
	while (1)
	{
		::Parser::Rule_res _4;
		dfa_lookup_result_6 = DFA_DECIDE(begin_16);
		switch (dfa_lookup_result_6)
		{
			case 0: {
				::Parser::str_t _7;
				::Parser::bool_t success_8 = false;
				auto begin_13 = begin_16;
				if (success_10 && success_12)
				{
					success_8 = true;
					begin_16 = begin_13;
				}
				skip_spaces(begin_16);

				break;

			}
			case 1: {
				char _14;
				::Parser::bool_t success_15 = false;
				if (!(!(*(begin_16 + 0) == '\'')))
				{
					return {};
				}
				_14 = *(begin_16 + 0);
				success_15 = true;
				begin_16 += 1;
				skip_spaces(begin_16);

				break;

			}
		}
;
		_2 += _4;
	}
	if (success_5)
	{
		success_3 = true;
		pos = begin_16;
	}
	skip_spaces(pos);
	char _17;
	::Parser::bool_t success_18 = false;
	if (!(*(pos + 0) == '\''))
	{
		return {};
	}
	_17 = *(pos + 0);
	success_18 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::STRING data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::STRING, data)};
}
Parser::Token_res Parser::Lexer::SPACEMODE(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "spacemode", 9) && !(*(pos + 9)>='a' && *(pos + 9)<='z' || *(pos + 9)>='A' && *(pos + 9)<='Z' || *(pos + 9)>='0' && *(pos + 9)<='9' || *(pos + 9) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 9);
	success_1 = true;
	pos += 9;
	skip_spaces(pos);
	::Parser::Rule_res _2;
	::Parser::bool_t success_3 = 1;
	dfa_lookup_result_4 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_4)
	{
		case 0: {
			::Parser::str_t _5;
			::Parser::bool_t success_6 = false;
			if (!(!std::strncmp(pos + 0, "skipped", 7) && !(*(pos + 7)>='a' && *(pos + 7)<='z' || *(pos + 7)>='A' && *(pos + 7)<='Z' || *(pos + 7)>='0' && *(pos + 7)<='9' || *(pos + 7) == '_')))
			{
				return {};
			}
			_5 += ::Parser::str_t(pos, 7);
			success_6 = true;
			pos += 7;
			skip_spaces(pos);

			break;

		}
		case 1: {
			::Parser::str_t _7;
			::Parser::bool_t success_8 = false;
			if (!(!std::strncmp(pos + 0, "allowed", 7) && !(*(pos + 7)>='a' && *(pos + 7)<='z' || *(pos + 7)>='A' && *(pos + 7)<='Z' || *(pos + 7)>='0' && *(pos + 7)<='9' || *(pos + 7) == '_')))
			{
				return {};
			}
			_7 += ::Parser::str_t(pos, 7);
			success_8 = true;
			pos += 7;
			skip_spaces(pos);

			break;

		}
		case 2: {
			::Parser::str_t _9;
			::Parser::bool_t success_10 = false;
			if (!(!std::strncmp(pos + 0, "mixed", 5) && !(*(pos + 5)>='a' && *(pos + 5)<='z' || *(pos + 5)>='A' && *(pos + 5)<='Z' || *(pos + 5)>='0' && *(pos + 5)<='9' || *(pos + 5) == '_')))
			{
				return {};
			}
			_9 += ::Parser::str_t(pos, 5);
			success_10 = true;
			pos += 5;
			skip_spaces(pos);

			break;

		}
	}
;
	skip_spaces(pos);
	char _11;
	::Parser::bool_t success_12 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_11 = *(pos + 0);
	success_12 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::SPACEMODE data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::SPACEMODE, data)};
}
Parser::Token_res Parser::Lexer::cll_ASSIGNMENT_OP(const char* pos) {
	auto in = pos;
	::Parser::Token _0;
	::Parser::bool_t success_1 = false;
	if (pos->name() == ::Parser::Tokens::cll_OP)
	{
		_0 = *pos;
		success_1 = true;
		pos += 1;
	}
	skip_spaces(pos);
	char _2;
	::Parser::bool_t success_3 = false;
	if (!(*(pos + 0) == '='))
	{
		return {};
	}
	_2 = *(pos + 0);
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::cll_ASSIGNMENT_OP data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_ASSIGNMENT_OP, data)};
}
Parser::Token_res Parser::Lexer::cll_COMPARE_OP(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	dfa_lookup_result_2 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_2)
	{
		case 0: {
			::Parser::str_t _3;
			::Parser::bool_t success_4 = false;
			if (!(!std::strncmp(pos + 0, ">=", 2)))
			{
				return {};
			}
			_3 += ::Parser::str_t(pos, 2);
			success_4 = true;
			pos += 2;
			skip_spaces(pos);

			break;

		}
		case 1: {
			::Parser::str_t _5;
			::Parser::bool_t success_6 = false;
			if (!(!std::strncmp(pos + 0, "==", 2)))
			{
				return {};
			}
			_5 += ::Parser::str_t(pos, 2);
			success_6 = true;
			pos += 2;
			skip_spaces(pos);

			break;

		}
		case 2: {
			::Parser::str_t _7;
			::Parser::bool_t success_8 = false;
			if (!(!std::strncmp(pos + 0, "<=", 2)))
			{
				return {};
			}
			_7 += ::Parser::str_t(pos, 2);
			success_8 = true;
			pos += 2;
			skip_spaces(pos);

			break;

		}
		case 3: {
			::Parser::str_t _9;
			::Parser::bool_t success_10 = false;
			if (!(!std::strncmp(pos + 0, "!=", 2)))
			{
				return {};
			}
			_9 += ::Parser::str_t(pos, 2);
			success_10 = true;
			pos += 2;
			skip_spaces(pos);

			break;

		}
		case 4: {
			char _11;
			::Parser::bool_t success_12 = false;
			if (!(*(pos + 0) == '>'))
			{
				return {};
			}
			_11 = *(pos + 0);
			success_12 = true;
			pos += 1;
			skip_spaces(pos);

			break;

		}
		case 5: {
			char _13;
			::Parser::bool_t success_14 = false;
			if (!(*(pos + 0) == '<'))
			{
				return {};
			}
			_13 = *(pos + 0);
			success_14 = true;
			pos += 1;
			skip_spaces(pos);

			break;

		}
	}
;
	skip_spaces(pos);
	::Parser::Types::cll_COMPARE_OP data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_COMPARE_OP, data)};
}
Parser::Token_res Parser::Lexer::AUTO_2(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '}'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_2 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_2, data)};
}
Parser::Token_res Parser::Lexer::NAME(const char* pos) {
	auto in = pos;
	::Parser::str_t _0;
	::Parser::bool_t success_1 = false;
	if (!(!std::strncmp(pos + 0, "name", 4) && !(*(pos + 4)>='a' && *(pos + 4)<='z' || *(pos + 4)>='A' && *(pos + 4)<='Z' || *(pos + 4)>='0' && *(pos + 4)<='9' || *(pos + 4) == '_')))
	{
		return {};
	}
	_0 += ::Parser::str_t(pos, 4);
	success_1 = true;
	pos += 4;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::ID))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	char _4;
	::Parser::bool_t success_5 = false;
	if (!(*(pos + 0) == ';'))
	{
		return {};
	}
	_4 = *(pos + 0);
	success_5 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::NAME data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::NAME, data)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_AND(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	dfa_lookup_result_2 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_2)
	{
		case 0: {
			::Parser::str_t _3;
			::Parser::bool_t success_4 = false;
			if (!(!std::strncmp(pos + 0, "and", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
			{
				return {};
			}
			_3 += ::Parser::str_t(pos, 3);
			success_4 = true;
			pos += 3;
			skip_spaces(pos);

			break;

		}
		case 1: {
			::Parser::str_t _5;
			::Parser::bool_t success_6 = false;
			if (!(!std::strncmp(pos + 0, "&&", 2)))
			{
				return {};
			}
			_5 += ::Parser::str_t(pos, 2);
			success_6 = true;
			pos += 2;
			skip_spaces(pos);

			break;

		}
	}
;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_AND)};
}
Parser::Token_res Parser::Lexer::AUTO_5(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '#'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_5 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_5, data)};
}
Parser::Token_res Parser::Lexer::AUTO_12(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '$'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_12 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_12, data)};
}
Parser::Token_res Parser::Lexer::cll_TEMPLATE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '<'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Token _2;
	::Parser::bool_t success_3 = false;
	if (!(pos->name() == ::Parser::Tokens::cll_TYPE))
	{
		return {};
	}
	_2 = *pos;
	success_3 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::bool_t success_9 = false;
	::Parser::bool_t success_7 = false;
	::Parser::bool_t success_5 = false;
	auto begin_11 = pos;
	while (1)
	{
		char _6;
		if (!(*(begin_11 + 0) == ','))
		{
			break;
		}
		_6 = *(begin_11 + 0);
		success_7 = true;
		begin_11 += 1;
		skip_spaces(begin_11);
		::Parser::Token _8;
		::Parser::arr_t<::Parser::Token> shadow_10;
		if (!(begin_11->name() == ::Parser::Tokens::cll_TYPE))
		{
			break;
		}
		_8 = *begin_11;
		success_9 = true;
		begin_11 += 1;
		shadow_10.push_back(_8);
	}
	if (success_7 && success_9)
	{
		success_5 = true;
		pos = begin_11;
	}
	skip_spaces(pos);
	char _12;
	::Parser::bool_t success_13 = false;
	if (!(*(pos + 0) == '>'))
	{
		return {};
	}
	_12 = *(pos + 0);
	success_13 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::cll_TEMPLATE data;
	data.first = _2;
	data.second = shadow_10;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TEMPLATE, data)};
}
Parser::Token_res Parser::Lexer::cll_TYPE(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	dfa_lookup_result_2 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_2)
	{
		case 0: {
			::Parser::str_t _3;
			::Parser::bool_t success_4 = false;
			if (!(!std::strncmp(pos + 0, "bool", 4) && !(*(pos + 4)>='a' && *(pos + 4)<='z' || *(pos + 4)>='A' && *(pos + 4)<='Z' || *(pos + 4)>='0' && *(pos + 4)<='9' || *(pos + 4) == '_')))
			{
				return {};
			}
			_3 += ::Parser::str_t(pos, 4);
			success_4 = true;
			pos += 4;
			skip_spaces(pos);

			break;

		}
		case 1: {
			::Parser::str_t _5;
			::Parser::bool_t success_6 = false;
			if (!(!std::strncmp(pos + 0, "var", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
			{
				return {};
			}
			_5 += ::Parser::str_t(pos, 3);
			success_6 = true;
			pos += 3;
			skip_spaces(pos);

			break;

		}
		case 2: {
			::Parser::str_t _7;
			::Parser::bool_t success_8 = false;
			if (!(!std::strncmp(pos + 0, "str", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
			{
				return {};
			}
			_7 += ::Parser::str_t(pos, 3);
			success_8 = true;
			pos += 3;
			skip_spaces(pos);

			break;

		}
		case 3: {
			::Parser::bool_t success_10 = false;
			auto begin_15 = pos;
			if (success_12 && success_14)
			{
				success_10 = true;
				pos = begin_15;
			}
			skip_spaces(pos);

			break;

		}
		case 4: {
			::Parser::str_t _16;
			::Parser::bool_t success_17 = false;
			if (!(!std::strncmp(pos + 0, "num", 3) && !(*(pos + 3)>='a' && *(pos + 3)<='z' || *(pos + 3)>='A' && *(pos + 3)<='Z' || *(pos + 3)>='0' && *(pos + 3)<='9' || *(pos + 3) == '_')))
			{
				return {};
			}
			_16 += ::Parser::str_t(pos, 3);
			success_17 = true;
			pos += 3;
			skip_spaces(pos);

			break;

		}
		case 5: {
			::Parser::bool_t success_19 = false;
			auto begin_24 = pos;
			if (success_21 && success_23)
			{
				success_19 = true;
				pos = begin_24;
			}
			skip_spaces(pos);

			break;

		}
	}
;
	skip_spaces(pos);
	::Parser::Types::cll_TYPE data;
	data.type = _11;
	data.templ = _13;

	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_TYPE, data)};
}
Parser::Token_res Parser::Lexer::AUTO_4(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == ')'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	::Parser::Types::AUTO_4 data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::AUTO_4, data)};
}
Parser::Token_res Parser::Lexer::cll_LOGICAL_OP(const char* pos) {
	auto in = pos;
	::Parser::Rule_res _0;
	::Parser::bool_t success_1 = 1;
	dfa_lookup_result_2 = DFA_DECIDE(pos);
	switch (dfa_lookup_result_2)
	{
		case 0: {
			_0 = *pos;

			break;

		}
		case 1: {
			_0 = *pos;

			break;

		}
	}
;
	skip_spaces(pos);
	::Parser::Types::cll_LOGICAL_OP data = NONE;
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::cll_LOGICAL_OP, data)};
}
Parser::Token_res Parser::Lexer::DIVIDE(const char* pos) {
	auto in = pos;
	char _0;
	::Parser::bool_t success_1 = false;
	if (!(*(pos + 0) == '/'))
	{
		return {};
	}
	_0 = *(pos + 0);
	success_1 = true;
	pos += 1;
	skip_spaces(pos);
	return {true, ::Parser::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::Parser::Tokens::DIVIDE)};
}
