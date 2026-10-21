#pragma once
#include <DepParser.h>
#include <ispa/lexical.hpp>
#include <cstring>
#include <vector>

namespace IspaDependency {
using Syntax = ::DepParser::Types::modules::ispa_dep_scanner;
struct Span { std::size_t offset, length; };
}

// Only opaque Python blocks need a custom lexical boundary. All ISPA source
// structure, strings, character groups and comments come from grammar.isc.
class IspaDepLexer : public DepParser::Lexer {
public:
    using Token = DepParser::Token;
    std::vector<IspaDependency::Span> comments;
    std::size_t offset = 0;

    using DepParser::Lexer::push;
    void push(Token&& token) override {
        // Whitespace and comments are trivia in the dependency grammar. Keep
        // their byte spans in the source, without feeding trivia to the parser.
        if (token.template holds<DepParser::Types::__WS>()) return;
        DepParser::Lexer::push(std::move(token));
    }

    Token makeToken(const char*& pos) override {
        offset = getCurrentPos(pos);
        if (pos[0] == 'p' && pos[1] == '{') {
            const char* begin = pos;
            pos = IspaSyntax::scanPythonBlock(begin);
            return Token::create(offset, begin, pos - begin, 0,
                DepParser::Tokens::modules::common::PY_RAW::id,
                ::DepParser::Types::modules::common::PY_RAW{std::string(begin, pos)});
        }
        auto token = DepParser::Lexer::makeToken(pos);
        if (token.empty() || pos == _in + offset)
            throw std::runtime_error("unterminated or unrecognized token in ISPA source");
        if (token.template holds<IspaDependency::Syntax::COMMENT>()) {
            const auto& meta = token.meta();
            comments.push_back({meta.startpos(), meta.length()});
            return Token::create(meta.startpos(), meta.start(), meta.length(), 0,
                DepParser::Tokens::__WS::id, DepParser::Types::__WS{});
        }
        return token;
    }
};

class IspaDepParser : public DepParser::Parser {
    template<class IT> void parseSource(IT begin) {
        while (!begin.isEnd() && (*begin).template holds<DepParser::Types::__WS>()) ++begin;
        auto result = main(begin);
        auto end = result.it;
        while (!end.isEnd() && (*end).template holds<DepParser::Types::__WS>()) ++end;
        if (!result.status || !end.isEnd()) {
            offset = end.isEnd() ? (text ? std::strlen(text) : 0) : (*end).meta().startpos();
            throw std::runtime_error("invalid ISPA dependency syntax");
        }
        tree = std::move(result.node.data());
    }
public:
    std::vector<IspaDependency::Span> comments;
    std::size_t offset = 0;

    void lazyParse() override {
        comments.clear();
        offset = 0;
        IspaDepLexer lexer;
        lexer.setInput(text);
        try {
            parseSource(IspaDepLexer::lazy_iterator(lexer, text));
            comments = std::move(lexer.comments);
        } catch (...) {
            if (!offset) offset = lexer.offset;
            throw;
        }
    }
    void parseFromTokens() override {
        comments.clear();
        offset = 0;
        if (const auto* source = dynamic_cast<const IspaDepLexer*>(lexer)) comments = source->comments;
        parseSource(DepParser::Lexer::iterator(lexer));
    }
};
