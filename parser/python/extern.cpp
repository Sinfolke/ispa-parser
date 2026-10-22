#include <PyRawParser.h>
#include "parser.hpp"
#include <ispa/lexical.hpp>
#include <cctype>

namespace PyRawParser::Exports {
namespace {
struct Parser : PyRawParser::Parser {
    using PyRawParser::Parser::expr;
    using PyRawParser::Parser::main;
};
const char* blockStart(const char* start) {
    while (start && *start && std::isspace(static_cast<unsigned char>(*start))) ++start;
    return start;
}
template<bool expression>
auto parseBlock(const char* origin, const char* start) {
    using Data = std::conditional_t<expression, PyRawParser::Types::expr, PyRawParser::Types::main>;
    start = blockStart(start);
    const char* end = IspaSyntax::scanPythonBlock(start);
    try {
        PyLexer lexer;
        lexer.setBoundary(end - 1);
        Parser parser;
        PyLexer::lazy_iterator begin(lexer, origin, start + 2);
        auto result = [&] {
            if constexpr (expression) return parser.expr(begin);
            else return parser.main(begin);
        }();
        auto cursor = result.it;
        if constexpr (expression) {
            if (!cursor.isEnd() && cursor->template holds<PyRawParser::Types::NEWLINE>()) ++cursor;
        }
        // The shipped Python parser predates transactional probe diagnostics:
        // failed optional suffix probes may leave diagnostics on a valid tree.
        // Its authoritative result is the match status and the consumed span.
        if (!result.status || !cursor.isEnd()) {
            std::string detail = "invalid Python action or unconsumed Python tokens";
            if (!parser.getErrors().empty()) detail += ": " + parser.getErrors().front().message;
            else if (!cursor.isEnd()) detail += ": " + std::string(cursor->meta().start(), cursor->meta().length());
            throw std::runtime_error(detail);
        }
        auto node = std::move(result.node);
        return ISPA_STD::ExternalResult<Data>{true,
            ISPA_STD::external_node(origin, start + 2, end - 1, std::move(node)), end};
    } catch (const std::exception& error) {
        const auto line = 1 + std::count(origin, start, '\n');
        throw std::runtime_error("Python action at line " + std::to_string(line) + ": " + error.what());
    }
}
}
bool ExpressionBlock::starts(const char*, const char* start) {
    start = blockStart(start);
    return start && start[0] == 'p' && start[1] == '{';
}
bool StatementsBlock::starts(const char* origin, const char* start) { return ExpressionBlock::starts(origin, start); }
ISPA_STD::ExternalResult<ExpressionBlock::node_type> ExpressionBlock::parse(const char* origin, const char* start) { return parseBlock<true>(origin, start); }
ISPA_STD::ExternalResult<StatementsBlock::node_type> StatementsBlock::parse(const char* origin, const char* start) { return parseBlock<false>(origin, start); }
}
