#pragma once
#include <ispa_dep_scanner/bootstrapped/DepParser.h>
template<char begin, char end>
auto skip_bounded_list(const char* &i) {
    if (*i == begin) {
        while (*i && *i != end) {
            if (*i == '\\') {
                ++i;
            }
            ++i;
        }
        return true;
    }
    return false;
}
class IspaDepLexer : public DepParser::Lexer {
    auto makeToken(const char* &i) -> DepParser::Token override {
        // skip string/cgroups that may contain arbitary characters
        while (skip_bounded_list<'\'', '\''>(i) || skip_bounded_list<'[', ']'>(i)) {}
        const char* begin;
        do {
            begin = i;
            auto res = DepParser::Lexer::makeToken(i);
            if (i != begin) {
                return res;
            }
            ++i;
        } while (i);
        return DepParser::Token {};
    }
};
class IspaDepParser : public DepParser::Parser {
    auto lazyParse() -> void override {
        IspaDepLexer lexer;
        tree = main(IspaDepLexer::lazy_iterator(lexer, text)).node.data();
    }
    auto parseFromTokens() -> void override {
        tree = main(IspaDepLexer::iterator(lexer)).node.data();
    }
};
