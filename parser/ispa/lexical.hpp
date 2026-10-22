#pragma once
#include <cctype>
#include <string_view>
#include <stdexcept>

// Shared lexical boundary for opaque Python action blocks.
namespace IspaSyntax {
inline bool keyword(const char* start, std::string_view word) {
    for (char c : word) if (!*start || *start++ != c) return false;
    return !std::isalnum(static_cast<unsigned char>(*start)) && *start != '_';
}

// Stop at an ISPA match statement or the enclosing brace, never at punctuation
// inside a Python string, comment, container, or parenthesized expression.
inline const char* scanPythonStatements(const char* begin) {
    const char* p = begin;
    unsigned depth = 0;
    char quote = '\0';
    bool triple = false, comment = false, line_start = true;
    while (*p) {
        const char c = *p;
        if (comment) {
            if (c == '\n' || c == '\r') { comment = false; line_start = true; }
            ++p; continue;
        }
        if (quote) {
            if (c == '\\' && p[1]) { p += 2; continue; }
            if (c == quote && (!triple || (p[1] == quote && p[2] == quote))) {
                p += triple ? 3 : 1; quote = '\0'; continue;
            }
            ++p; continue;
        }
        if (!depth && c == '}') return p;
        if (!depth && line_start && keyword(p, "match")) return p;
        if (c == '#') { comment = true; ++p; continue; }
        if (c == '\'' || c == '"') {
            quote = c; triple = p[1] == c && p[2] == c;
            p += triple ? 3 : 1; line_start = false; continue;
        }
        if (c == '{' || c == '(' || c == '[') ++depth;
        else if (c == '}' || c == ')' || c == ']') {
            if (!depth) throw std::runtime_error("Unmatched delimiter in Python action");
            --depth;
        }
        if (c == '\n' || c == '\r' || (!depth && c == ';')) line_start = true;
        else if (!std::isspace(static_cast<unsigned char>(c))) line_start = false;
        if (c == '\\' && (p[1] == '\n' || p[1] == '\r')) {
            p += 2; line_start = false; continue;
        }
        ++p;
    }
    if (quote || depth) throw std::runtime_error("Unterminated Python action");
    return p;
}

inline const char* scanBracedPython(const char* begin) {
    if (!begin || *begin != '{') throw std::runtime_error("Expected Python body");
    const char* p = begin + 1;
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
inline const char* scanPythonBlock(const char* begin) {
    if (!begin || *begin != 'p' || *(begin + 1) != '{') throw std::runtime_error("Expected Python block");
    return scanBracedPython(begin + 1);
}
}
