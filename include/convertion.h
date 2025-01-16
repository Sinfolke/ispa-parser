#pragma once
#include <parser.h>
#include <cpuf/dlib.h>
#include <ostream>
#include <sstream>
#include <internal_types.h>
#include <corelib.h>
#include <convertion.h>
auto getFunction(dlib& converter, const char* name);
void processFunction(const char* funName, dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void processRule(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_group(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_csequence(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_accessor(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_hex(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_bin(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_other(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_escaped(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_any(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_Rule_op(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_cll(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_string(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void process_number(dlib &converter, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
std::string convert(Parser::Tree& tree, dlib& converter);