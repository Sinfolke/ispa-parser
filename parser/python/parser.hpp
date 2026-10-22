#pragma once
#include <PyRawParser.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stdexcept>

class PyLexer : public PyRawParser::Lexer {
public:
    using Token = PyRawParser::Token;
private:
    std::vector<std::size_t> indent_stack{0};
    std::deque<Token> token_buffer;

    std::size_t pending_indent = 0;
    std::size_t bracket_depth = 0;

    bool at_line_start = true;
    bool line_has_code = false;
    bool last_logical_line_terminated = true;
    bool finished = false;
    ISPA_STD::RawTokenMeta anchor;
    const char* boundary = nullptr;

    template<typename T>
    static bool is(const Token& token) {
        return token.holds<T>();
    }

    template<typename T>
    Token synthetic(std::size_t id) {
        return Token{ISPA_STD::RawTokenMeta{anchor.startpos(), anchor.start(), anchor.start(), 0,
            anchor.line(), anchor.column(), id}, T {}};
    }

    Token makeIndent() {
        return synthetic<PyRawParser::FlatTypes::INDENT>(PyRawParser::Tokens::INDENT::id);
    }

    Token makeDedent() {
        return synthetic<PyRawParser::FlatTypes::DEDENT>(PyRawParser::Tokens::DEDENT::id);
    }

    Token makeNewline() {
        return synthetic<PyRawParser::FlatTypes::NEWLINE>(PyRawParser::Tokens::NEWLINE::id);
    }

    void processIndentation() {
        const auto previous = indent_stack.back();

        if (pending_indent > previous) {
            indent_stack.push_back(pending_indent);
            token_buffer.push_back(makeIndent());
        }
        else if (pending_indent < previous) {
            while (indent_stack.size() > 1 &&
                   indent_stack.back() > pending_indent) {
                indent_stack.pop_back();
                token_buffer.push_back(makeDedent());
            }

            if (indent_stack.back() != pending_indent) {
                throw std::runtime_error(
                    "IndentationError: unindent does not match "
                    "any outer indentation level"
                );
            }
        }

        pending_indent = 0;
        at_line_start = false;
    }

    // Flushes all buffered tokens (INDENT, DEDENT, NEWLINE, regular tokens)
    // into the underlying Lexer_base token flow.
    void flush_buffer() {
        while (!token_buffer.empty()) {
            Token t = std::move(token_buffer.front());
            token_buffer.pop_front();
            PyRawParser::Lexer::push(std::move(t));
        }
    }

public:
    void setBoundary(const char* end) { boundary = end; setExternalBoundary(); }
    void setBaseIndent(std::size_t indent) {
        indent_stack.assign(1, indent);
        at_line_start = false;
    }
    Token makeToken(const char*& pos) override {
        if (boundary && pos >= boundary) return {};
        const char* start = pos;
        auto make = [&](std::size_t id, auto value) {
            line = __line(pos);
            return Token::create(getCurrentPos(start), start, pos - start, __line(start), id, std::move(value));
        };
        if (*pos == ' ' || *pos == '\t' || *pos == '\f') {
            while (*pos == ' ' || *pos == '\t' || *pos == '\f') ++pos;
            return make(PyRawParser::Tokens::__WS::id, PyRawParser::Types::__WS{});
        }
        if (*pos == '\n' || *pos == '\r') {
            if (*pos++ == '\r' && *pos == '\n') ++pos;
            return make(PyRawParser::Tokens::NEWLINE::id, PyRawParser::Types::NEWLINE{});
        }
        if (*pos == '\'' || *pos == '"') {
            const char quote = *pos++;
            const bool triple = pos[0] == quote && pos[1] == quote;
            if (triple) pos += 2;
            const char* content = pos;
            while (*pos) {
                if (*pos == '\\' && pos[1]) { pos += 2; continue; }
                if (*pos == quote && (!triple || (pos[1] == quote && pos[2] == quote))) {
                    const auto value = std::string(content, pos);
                    pos += triple ? 3 : 1;
                    return make(PyRawParser::Tokens::STRING::id, PyRawParser::Types::STRING{value});
                }
                if (!triple && (*pos == '\n' || *pos == '\r')) break;
                ++pos;
            }
            throw std::runtime_error("Unterminated Python string");
        }
        return PyRawParser::Lexer::makeToken(pos);
    }
    void push(Token &&token) override {
        push(static_cast<const Token&>(token));
    }
    void push(const Token& token) override {
        auto t = token;
        anchor = t.meta();
        if (finished) {
            throw std::logic_error(
                "PyLexer::push() called after finish()"
            );
        }
        if (is<PyRawParser::Types::DEDENT>(t) || is<PyRawParser::Types::INDENT>(t)) {
            t = PyRawParser::Token {t.meta(), PyRawParser::Types::__WS {}};
        }
        // Whitespace at the beginning of a physical line.
        if (at_line_start && is<PyRawParser::FlatTypes::__WS>(t)) {
            for (const char* p = t.meta().start(); p != t.meta().end(); ++p)
                pending_indent = *p == '\t' ? (pending_indent / 8 + 1) * 8 : pending_indent + 1;
            return;
        }
        if (is<PyRawParser::FlatTypes::__WS>(t)) { PyRawParser::Lexer::push(std::move(t)); return; }

        // Bracket tracking for implicit line continuation.
        if (is<PyRawParser::FlatTypes::LPAREN>(t) ||
            is<PyRawParser::FlatTypes::LBRACKET>(t) ||
            is<PyRawParser::FlatTypes::LBRACE>(t)) {
            ++bracket_depth;
        }
        else if (is<PyRawParser::FlatTypes::RPAREN>(t) ||
                 is<PyRawParser::FlatTypes::RBRACKET>(t) ||
                 is<PyRawParser::FlatTypes::RBRACE>(t)) {
            if (bracket_depth > 0) {
                --bracket_depth;
            }
        }

        // Physical newline.
        if (is<PyRawParser::FlatTypes::NEWLINE>(t)) {
            pending_indent = 0;
            at_line_start = true;

            if (bracket_depth > 0) {
                // Implicit continuation: no logical NEWLINE token.
                return;
            }

            if (line_has_code) {
                token_buffer.push_back(std::move(t));
                last_logical_line_terminated = true;
            }

            line_has_code = false;
            flush_buffer();
            return;
        }

        // Comment-only lines do not change indentation.
        if (is<PyRawParser::FlatTypes::COMMENT>(t)) {
            return;
        }

        if (at_line_start) {
            if (bracket_depth == 0) {
                processIndentation();
            } else {
                pending_indent = 0;
                at_line_start = false;
            }
        }

        token_buffer.push_back(std::move(t));
        line_has_code = true;
        last_logical_line_terminated = false;
        flush_buffer();
    }

    void push() override {
        if (finished)
            return;

        // Let required closing-delimiter matches report and repair EOF.
        // The final logical newline still belongs to the containing statement.
        auto& output = getTokensReference();
        const char* end = boundary ? boundary : _in + std::char_traits<char>::length(_in);
        anchor = ISPA_STD::RawTokenMeta{static_cast<std::size_t>(end - _in), end, end, 0, __line(end), __column(end), 0};

        // Complete the last logical line.
        if (line_has_code && !last_logical_line_terminated) {
            output.push_back(makeNewline());
        }

        // Complete any remaining indentation blocks.
        while (indent_stack.size() > 1) {
            indent_stack.pop_back();
            output.push_back(makeDedent());
        }

        pending_indent = 0;
        at_line_start = true;
        line_has_code = false;
        last_logical_line_terminated = true;
        finished = true;

        // Append EOF exactly once.
        output.push_back(Token{});
    }

    void reset() {
        indent_stack.assign(1, 0);
        token_buffer.clear();

        pending_indent = 0;
        bracket_depth = 0;

        at_line_start = true;
        line_has_code = false;
        last_logical_line_terminated = true;
        finished = false;
    }
};
class PyParser : public ::PyRawParser::Parser {
public:
    using ::PyRawParser::Parser::parseLazy;
    template<class IT>
    auto parseExpression(IT begin) {
        reset_recovery();
        // A standalone expression leaves the lexer's final logical newline
        // to its caller. Give hierarchical recovery that enclosing boundary.
        auto frame = recovery_frame("Python expression entry");
        recovery_at<ISPA_STD::Recovery::Tokens<PyRawParser::Tokens::NEWLINE::id>>(
            "NEWLINE", "NEWLINE");
        return expr(begin);
    }
    auto parseLazy(const std::string& source)
        -> ::PyRawParser::Types::main
    {
        reset_recovery();
        PyLexer lexer;
        lexer.setInput(source);

        auto it = PyLexer::lazy_iterator(lexer, source.c_str());
        auto result = main(it);

        if (!result.status) {
            throw std::runtime_error("Lazy parsing failed");
        }

        if (!result.it.isEnd()) {
            throw std::runtime_error(
                "Unexpected tokens after parsed input"
            );
        }

        return result.node.data();
    }
};
