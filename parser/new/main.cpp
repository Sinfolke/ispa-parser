#include "output/Parser.h"
#include <ispastdlib.hpp>
#include <iostream>
#include <fstream>
#include <variant>

#include <vector>
#include <queue>
#include <variant>

class PyLexer : public Parser::Lexer {
public:
    using Token = Parser::Token;

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
        return std::holds_alternative<
            ISPA_STD::Node<Parser::Tokens, T>
        >(token);
    }

    template<typename T>
    static Token makeToken() {
        using Node = ISPA_STD::Node<Parser::Tokens, T>;
        return Token{std::in_place_type<Node>};
    }

    static Token makeIndent() {
        return makeToken<Parser::FlatTypes::INDENT>();
    }

    static Token makeDedent() {
        return makeToken<Parser::FlatTypes::DEDENT>();
    }

    static Token makeNewline() {
        return makeToken<Parser::FlatTypes::NEWLINE>();
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

public:
    void push(const Token& token) {
        if (std::holds_alternative<std::monostate>(token)) {
            finish();
            return;
        }
        if (finished) {
            throw std::logic_error(
                "PyLexer::push() called after finish()"
            );
        }

        // Whitespace at the beginning of a physical line.
        if (at_line_start && is<Parser::FlatTypes::__WS>(token)) {
            pending_indent +=
                std::get<ISPA_STD::Node<
                    Parser::Tokens,
                    Parser::FlatTypes::__WS
                >>(token).length();

            return;
        }

        // Bracket tracking for implicit line continuation.
        if (is<Parser::FlatTypes::LPAREN>(token) ||
            is<Parser::FlatTypes::LBRACKET>(token) ||
            is<Parser::FlatTypes::LBRACE>(token)) {
            ++bracket_depth;
        }
        else if (is<Parser::FlatTypes::RPAREN>(token) ||
                 is<Parser::FlatTypes::RBRACKET>(token) ||
                 is<Parser::FlatTypes::RBRACE>(token)) {
            if (bracket_depth > 0) {
                --bracket_depth;
            }
        }

        // Physical newline.
        if (is<Parser::FlatTypes::NEWLINE>(token)) {
            pending_indent = 0;
            at_line_start = true;

            if (bracket_depth > 0) {
                // Implicit continuation: no logical NEWLINE token.
                return;
            }

            if (line_has_code) {
                token_buffer.push_back(token);
                last_logical_line_terminated = true;
            }

            line_has_code = false;
            return;
        }

        // Comment-only lines do not change indentation.
        if (is<Parser::FlatTypes::COMMENT>(token)) {
            return;
        }

        // Whitespace within a line is not indentation.
        if (is<Parser::FlatTypes::__WS>(token)) {
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

        token_buffer.push_back(token);
        line_has_code = true;
        last_logical_line_terminated = false;
    }

    bool hasToken() const {
        return !token_buffer.empty();
    }

    Token pop() {
        if (token_buffer.empty()) {
            throw std::runtime_error(
                "PyLexer token buffer is empty"
            );
        }

        Token token = std::move(token_buffer.front());
        token_buffer.pop_front();
        return token;
    }

    // Call after the underlying lexer reaches EOF.
    void finish() {
        if (finished)
            return;

        if (bracket_depth != 0) {
            throw std::runtime_error(
                "SyntaxError: unexpected EOF inside brackets"
            );
        }

        // Emit the missing logical NEWLINE.
        if (line_has_code && !last_logical_line_terminated) {
            token_buffer.push_back(makeNewline());
        }

        // Emit final DEDENT tokens after NEWLINE.
        while (indent_stack.size() > 1) {
            indent_stack.pop_back();
            token_buffer.push_back(makeDedent());
        }
        std::cout << "Finish called: " << std::endl;
        pending_indent = 0;
        at_line_start = true;
        line_has_code = false;
        last_logical_line_terminated = true;
        finished = true;
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

int main(int argc, const char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " \"<input>\"\n";
        return 1;
    }
    if (std::string(argv[1]) == "--file") {
        std::ifstream inputf(argv[2]);
        if (!inputf.is_open()) {
            throw std::runtime_error("Failed to open input file");
        }
        std::string s((std::istreambuf_iterator<char>(inputf)), {});
        Parser::Lexer lexer;
        lexer.makeTokens(s);
        Parser::Parser parser;
        Parser::Types::main &node = parser.parse(lexer);
        std::ofstream of("tree.txt");
        of << node << "\n\n";
    } else {
        Parser::Lexer lexer;
        lexer.makeTokens(argv[1]);
        Parser::Parser parser;
        Parser::Types::main &node = parser.parse(lexer);
        std::ofstream of("tree.txt");
        of << node << "\n\n";
    }
}