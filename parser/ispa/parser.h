
#pragma once
#include <Parser.h>

#include <stdexcept>
#include <string>
#include <string_view>

class IspaLexer : public Parser::Lexer {
public:
    using Token = Parser::Token;

private:
    // Scans a single-quoted ISPA grammar string.
    //
    // Examples:
    //   'hello'
    //   'it\\'s working'
    //   '\\\\'
    //   '\\n'
    //
    // Returns a pointer immediately after the closing quote.
    static const char* scanString(const char* begin) {
        if (!begin || *begin != '\'')
            throw std::runtime_error("Expected ISPA string");

        const char* p = begin + 1;

        while (*p != '\0') {
            if (*p == '\\') {
                ++p;

                if (*p == '\0')
                    throw std::runtime_error(
                        "Unterminated escape sequence in ISPA string"
                    );

                ++p;
                continue;
            }

            if (*p == '\'')
                return p + 1;

            if (*p == '\n' || *p == '\r')
                throw std::runtime_error(
                    "Unterminated ISPA string before newline"
                );

            ++p;
        }

        throw std::runtime_error("Unterminated ISPA string");
    }
    static const char* scanCharacterGroup(const char* begin) {
        if (!begin || *begin != '[')
            throw std::runtime_error("Expected character group");

        const char* p = begin + 1;

        while (*p) {
            if (*p == '\\') {
                if (!p[1])
                    throw std::runtime_error(
                        "Unterminated character group escape"
                    );

                p += 2;
                continue;
            }

            if (*p == ']')
                return p + 1;

            ++p;
        }

        throw std::runtime_error("Unterminated character group");
    }
    static const char* scanPythonBlock(const char* begin) {
        if (!begin || *begin != 'p' || *(begin + 1) != '{')
            throw std::runtime_error("Expected Python block");

        const char* p = begin + 2;
        unsigned depth = 1;

        char quote = '\0';
        bool triple = false;
        bool comment = false;

        while (*p) {
            const char c = *p;

            if (comment) {
                if (c == '\n' || c == '\r')
                    comment = false;

                ++p;
                continue;
            }

            if (quote) {
                if (c == '\\' && p[1]) {
                    p += 2;
                    continue;
                }

                if (triple) {
                    if (p[0] == quote &&
                        p[1] == quote &&
                        p[2] == quote) {
                        quote = '\0';
                        triple = false;
                        p += 3;
                        continue;
                    }
                } else if (c == quote) {
                    quote = '\0';
                    ++p;
                    continue;
                }

                ++p;
                continue;
            }

            if (c == '#') {
                comment = true;
                ++p;
                continue;
            }

            if (c == '\'' || c == '"') {
                quote = c;
                triple = p[1] == c && p[2] == c;

                p += triple ? 3 : 1;
                continue;
            }

            if (c == '{') {
                ++depth;
            } else if (c == '}') {
                if (--depth == 0)
                    return p + 1;
            }

            ++p;
        }

        throw std::runtime_error(
            "Unterminated Python block"
        );
    }

public:
    Token makeToken(const char*& pos) override {
        // Python semantic code block: p{ ... }
        if (pos[0] == 'p' && pos[1] == '{') {
            const char* begin = pos;
            const char* end = scanPythonBlock(begin);

            auto token = Parser::Token::create(
                Lexer::getCurrentPos(pos),
                begin,
                static_cast<long long>(end - begin),
                Lexer::__line(pos),
                Parser::Tokens::PY_RAW::id,
                Parser::Types::PY_RAW{
                    .value = std::string(begin, end)
                }
            );

            pos = end;
            return token;
        }

        // Single-quoted ISPA grammar string.
        if (pos[0] == '\'') {
            const char* begin = pos;
            const char* end = scanString(begin);

            auto token = Parser::Token::create(
                Lexer::getCurrentPos(pos),
                begin,
                static_cast<long long>(end - begin),
                0,
                Parser::Tokens::rule::value::STRING::id,
                Parser::Types::rule::value::STRING{
                    // Preserve escapes, remove surrounding quotes.
                    .value = std::string(begin + 1, end - 1)
                }
            );

            pos = end;
            return token;
        }
        if (pos[0] == '[') {
            const char* begin = pos;
            const char* end = scanCharacterGroup(begin);
            char negative = '\0';
            const char* v_begin = begin + 1;
            if (*(begin + 1) == '^') {
                negative = '^';
                v_begin += 1;
            }
            auto token = Parser::Token::create(
                Lexer::getCurrentPos(pos),
                begin,
                static_cast<long long>(end - begin),
                0,
                Parser::Tokens::rule::value::CGROUP::id,
                Parser::Types::rule::value::CGROUP{
                    .negative = negative,
                    .v = std::string(v_begin, end - 1)
                }
            );

            pos = end;
            return token;
        }
        return Parser::Lexer::makeToken(pos);
    }
};
class IspaParser : public Parser::Parser {
    public:
        auto lazyParse() -> void override {
            IspaLexer lexer;
            auto res = main(IspaLexer::lazy_iterator(lexer, text));
            if (!res.status) {
                throw ISPA_STD::IspaAPIExcept("Could not parse ISPA grammar");
            }
            tree = res.node.data();
        }
};