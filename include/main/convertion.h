#pragma once
#include <parser.h>
#include <cpuf/dlib.h>
#include <ostream>
#include <sstream>
#include <internal_types.h>
#include <corelib.h>
auto getFunction(dlib& converter, const char* name);
std::string processRule(Parser::Rule& member);
std::string processFunction(const char* funName, Parser::Tree& tree, int& i, Parser::Rule member, dlib& converter, std::stringstream& result);
std::string convert(Parser::Tree& tree, dlib& converter);