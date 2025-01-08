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
void processFunction(const char* funName, Parser::Tree &tree, int& i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void processRule(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_group(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_csequence(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_accessor(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_hex(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_bin(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_other(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_escaped(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_any(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_Rule_op(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_cll(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_string(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
void process_number(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member, dlib &converter);
std::string convert(Parser::Tree& tree, dlib& converter);