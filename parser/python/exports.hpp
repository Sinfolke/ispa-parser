#pragma once
#include <PyRawParser.h>

// External entry points use the parser's original node types and implementation.
#include <ispastdlib/external.hpp>
namespace PyRawParser::Exports {
struct ExpressionBlock {
    using node_type = PyRawParser::Types::expr;
    static bool starts(const char* origin, const char* start);
    static ISPA_STD::ExternalResult<node_type> parse(const char* origin, const char* start);
};
struct StatementsBlock {
    using node_type = PyRawParser::Types::main;
    static bool starts(const char* origin, const char* start);
    static ISPA_STD::ExternalResult<node_type> parse(const char* origin, const char* start);
};
struct RawStatements {
    using node_type = PyRawParser::Types::main;
    static bool starts(const char* origin, const char* start);
    static ISPA_STD::ExternalResult<node_type> parse(const char* origin, const char* start);
};
}
