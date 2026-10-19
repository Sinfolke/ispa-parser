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

    template<typename T>
    static bool is(const Token& token) {
        return token.holds<T>();
    }

    template<typename T>
    static Token makeToken() {
        return Token{ISPA_STD::RawTokenMeta {}, T {}};
    }

    static Token makeIndent() {
        return makeToken<PyRawParser::FlatTypes::INDENT>();
    }

    static Token makeDedent() {
        return makeToken<PyRawParser::FlatTypes::DEDENT>();
    }

    static Token makeNewline() {
        return makeToken<PyRawParser::FlatTypes::NEWLINE>();
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
    void push(Token &&token) override {
        std::cout << "push(&&);" << std::endl;
        push(static_cast<const Token&>(token));
    }
    void push(const Token& token) override {
        std::cout << "push(&);" << std::endl;
        auto t = std::move(token);
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
            pending_indent += t.to_node<PyRawParser::FlatTypes::__WS>().length();
        }

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

        if (bracket_depth != 0) {
            throw std::runtime_error(
                "SyntaxError: unexpected EOF inside brackets"
            );
        }

        auto& output = getTokensReference();

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
    auto parseLazy(const std::string& source)
        -> ::PyRawParser::Types::main
    {
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