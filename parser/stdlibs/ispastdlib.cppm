//!ISPA_LIB_MANAGER C++ 1.1 ISC-parser Standard-library Versions iscstdlibcpp{VER}-{SUBVER}.h!\\

/**
 * C++ ispa std lib 1.1
 * It contains standard declarations and every C++ generated parser would link toward it
 * It is for case you'd use two ISC parsers in one same project.
 * However it won't cancell that parser does not rely on any library
*/
module;
#include "old/ispastdlib.hpp"
export module ispastdlibcpp;
import std;

export namespace ISPA_STD {
    using ISPA_STD::Lexer_No_Tokens_exception;
    using ISPA_STD::Lexer_No_Input_exception;
    using ISPA_STD::Parser_No_Input_exception;
    using ISPA_STD::AdvancedDFA_exception;
    using ISPA_STD::node_exception;
    using ISPA_STD::bad_get;
    using ISPA_STD::Node;
    using ISPA_STD::match_result;
    using ISPA_STD::TokenFlow;
    using ISPA_STD::Seq;
    using ISPA_STD::error;
    using ISPA_STD::ErrorController;
    namespace DFAAPI {
        using ISPA_STD::DFAAPI::null_state;
        using ISPA_STD::DFAAPI::CharEmptyState;
        using ISPA_STD::DFAAPI::CallableTokenEmptyState;
        using ISPA_STD::DFAAPI::MultiTableEmptyState;
        using ISPA_STD::DFAAPI::State;
        using ISPA_STD::DFAAPI::CharTransition;
        using ISPA_STD::DFAAPI::TokenTransition;
        using ISPA_STD::DFAAPI::CallableTokenTransition;
        using ISPA_STD::DFAAPI::CharTableTransition;
        using ISPA_STD::DFAAPI::CallableTokenTableTransition;
        using ISPA_STD::DFAAPI::MultiTableTransition;
        using ISPA_STD::DFAAPI::AnyTransition;
        using ISPA_STD::DFAAPI::CharTableState;
        using ISPA_STD::DFAAPI::TokenTableState;
        using ISPA_STD::DFAAPI::CallableTokenState;
        using ISPA_STD::DFAAPI::MultiTableState;
        using ISPA_STD::DFAAPI::SpanCharTableState;
        using ISPA_STD::DFAAPI::SpanTokenTableState;
        using ISPA_STD::DFAAPI::SpanCallableTokenState;
        using ISPA_STD::DFAAPI::SpanMultiTableState;
        using ISPA_STD::DFAAPI::CharTable;
        using ISPA_STD::DFAAPI::TokenTable;
        using ISPA_STD::DFAAPI::CallableTokenTable;
        using ISPA_STD::DFAAPI::MultiTable;
        using ISPA_STD::DFAAPI::SpanCharTable;
        using ISPA_STD::DFAAPI::SpanTokenTable;
        using ISPA_STD::DFAAPI::SpanCallableTokenTable;
        using ISPA_STD::DFAAPI::EmptyState;
        using ISPA_STD::DFAAPI::Transition;
        using ISPA_STD::DFAAPI::SpanState;
        using ISPA_STD::DFAAPI::SpanMultiTable;
    };
    using ISPA_STD::DFA;
    using ISPA_STD::AdvancedDFA;
    using ISPA_STD::Lexer_base;
    using ISPA_STD::LLParser_base;
    using ISPA_STD::LRParser_base;
    using ISPA_STD::ELRParser_base;
}