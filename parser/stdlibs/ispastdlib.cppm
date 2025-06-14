//!ISPA_LIB_MANAGER C++ 1.1 ISC-parser Standard-library Versions iscstdlibcpp{VER}-{SUBVER}.h!\\

/**
 * C++ ispa std lib 1.1
 * It contains standard declarations and every C++ generated parser would link toward it
 * It is for case you'd use two ISC parsers in one same project.
 * However it won't cancell that parser does not rely on any library
*/
module;
#include "ispastdlib.hpp"
export module ispastdlibcpp;
import std;
import std.compat;

export namespace ISPA_STD {
    using ISPA_STD::Lexer_No_Tokens_exception;
    using ISPA_STD::Lexer_No_Input_exception;
    using ISPA_STD::Parser_No_Input_exception;
    using ISPA_STD::node_exception;
    using ISPA_STD::bad_get;
    using ISPA_STD::Node;
    using ISPA_STD::match_result;
    using ISPA_STD::TokenFlow;
    using ISPA_STD::Seq;
    using ISPA_STD::error;
    using ISPA_STD::ErrorController;
    using ISPA_STD::Lexer_base;
    using ISPA_STD::LLParser_base;
    using ISPA_STD::LRParser_base;
    using ISPA_STD::ELRParser_base;
};