
#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdarg>
#include <unordered_map>
#include <stdexcept>
#include <forward_list>
#include <list>
#include <cstdio>
#include <filesystem>


#include <cpuf/cdevinfo> // cdevinfo, devinfo.h
#include <cpuf/color.h>
#include <cpuf/dlib.h>
#include <cpuf/let>
#include <cpuf/printf.h>
#include <cpuf/constexpr>

#include <logging.h>
#include <tree.h>
#include <corelib.h>
#include <init.h>

#include <args.h>
#include <../parser/Parser.h>
#include <TreeAPI.h>
#include <AST.h>
#include <IR/LLIR.h>
#include <LRParser.h>
#include <LALRParser.h>
#include <ELRParser.h>
#include <converter_base.h>
void printHelp();