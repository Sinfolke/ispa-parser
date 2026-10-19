/**
 * ispastdlib/parser.hpp - LLParser_base
 * Part of the split ISPA std lib; include <ispastdlib.hpp> for everything.
 */
#pragma once
#include <ispastdlib/core.hpp>
#include <ispastdlib/node.hpp>
#include <ispastdlib/lexer.hpp>
#include <ispastdlib/raw_token.hpp>
#include <ispastdlib/token_flow.hpp>
#include <ispastdlib/traits.hpp>

namespace ISPA_STD {
    /* PARSER */
    template<typename MainNode, typename Token>
    class LLParser_base {
    protected:
        Lexer_base<Token>* lexer = nullptr;
        const char* text = nullptr;
        MainNode tree;
        // skip spaces for tokens
        template <typename SpaceTokenType, typename IT>
        void skip_spaces(IT& pos) {
            if ((*pos).template holds<SpaceTokenType>())
                ++pos;
        }
        void raise_error(const Token& node, const std::string& message) {
            // if constexpr (is_raw_token_v<Token>) {
            //     // Error path: report from the shared metadata only. Printing the payload would
            //     // need a visitor over every alternative, i.e. exactly the instantiation cost
            //     // RawToken exists to avoid. The source slice is the token's text.
            //     if (node.empty() && node.meta().start() == nullptr)
            //         return;
            //     const auto& m = node.meta();
            //     std::cerr << "Error at token " << (int) m.name() << "(at position " << m.startpos() << ")" << ": " << message << std::endl;
            //     if (m.start())
            //         std::cerr << "Token: \n" << std::string_view(m.start(), m.length()) << std::endl;
            // } else {
            //     std::visit([&](auto&& arg) {
            //         using T = std::decay_t<decltype(arg)>;
            //         if constexpr (!std::is_same_v<T, std::monostate>) {
            //             std::cerr << "Error at token " << (int) arg.name() << "(at position " << arg.startpos() << ")" << ": " << message << std::endl;
            //             std::cerr << "Token: \n" << arg << std::endl;
            //         }
            //     }, node);
            // }
        }
        static void PANIC_MODE() {}
    public:
        // Constructors
        LLParser_base() {}
        LLParser_base(Lexer_base<Token>& lexer) {
            this->lexer = &lexer;
        }
        LLParser_base(const char* text) : text(text) {}
        virtual ~LLParser_base() {}
        // Parsing methods
        MainNode& parse(Lexer_base<Token>& lex) {
            lexer = &lex;
            return parse();
        }
        MainNode& parse(const char* txt) {
            text = txt;
            return parseLazy();
        }
        void setInput(Lexer_base<Token> &lex) {
            if (!lex.hasTokens())
                lexer = &lex;
        }
        void setInput(const char* txt) {
            text = txt;
        }
        void clearInput() {
            lexer = nullptr;
            text = nullptr;
        }
    protected:
        /**
         * Parse NON-LAZILY input
         */
        virtual MainNode& parse() {
            if (lexer == nullptr)
                throw IspaAPIExcept("Can't parse because no input lexer is provided");
            if (!lexer->hasInput())
                lexer->makeTokens();
            parseFromTokens();
            return tree;
        }
        /*
         * Parse LAZILY input
         */
        virtual MainNode& parseLazy() {
            if (text == nullptr)
                throw IspaAPIExcept("Can't parse because no input text is provided");
            lazyParse();
            return tree;
        }
        /*
         * DO NOT OVERRIDE
         * This function is used internally as bridge between generator and std lib
         * you should override Lexer::parse() instead
         */
        virtual void parseFromTokens() = 0;
        /*
         * DO NOT OVERRIDE
         * This function is used internally as bridge between generator and std lib
         * you should override Lexer::parseLazy() instead
         */
        virtual void lazyParse() = 0;
    };
} // namespace ISPA_STD
