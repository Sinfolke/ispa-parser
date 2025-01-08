#pragma once
#include <parser.h>
#include <cpuf/dlib.h>
#include <ostream>
#include <sstream>
#include <internal_types.h>
#include <corelib.h>
#include <convertion.h>
using use_prop_t = std::unordered_map<std::string, Parser::Rule>;
auto getFunction(dlib& converter, const char* name);
std::string processFunction(const char* funName, Parser::Tree &tree, int& i, use_prop_t &use_prop, Parser::Rule member, dlib &converter);
std::string processRule(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter);
std::string process_Rule_group(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter);
std::string process_Rule_csequence(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter);
std::string process_string(Parser::Tree &tree, int &i, use_prop_t &use_prop, Parser::Rule member, dlib &converter);
std::string convert(Parser::Tree& tree, dlib& converter);