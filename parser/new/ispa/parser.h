
#pragma once
#include "output/Parser.h"

#include <stdexcept>
#include <string>
#include <string_view>

class IspaLexer : public Parser::Lexer {
public:
    using Token = Parser::Token;

private:
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
                triple =
                    p[1] == c &&
                    p[2] == c;

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
        if (pos[0] == 'p' && pos[1] == '{') {
            const char* begin = pos;
            const char* end = scanPythonBlock(begin);

            auto token = Parser::Token::create(
                Lexer::getCurrentPos(pos),
                begin,
                static_cast<long long>(end - begin),
                Lexer::__line(pos),
                Parser::Tokens::PY_RAW,
                Parser::Types::PY_RAW{
                    .value = std::string(begin, end)
                }
            );

            pos = end;
            return token;
        }

        return Parser::Lexer::makeToken(pos);
    }
};
