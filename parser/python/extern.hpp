#pragma once
#include <PyRawParser.h>

// Compatibility for ISPA parsers generated before the direct dependency API.
namespace ISPA_PYTHON {
using Expression = PyRawParser::Types::expr;
using Statements = PyRawParser::Types::main;
using ExpressionRule = PyRawParser::Exports::ExpressionBlock;
using StatementsRule = PyRawParser::Exports::StatementsBlock;
}
