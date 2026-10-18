#include "ispa/parser.h"
#include <iostream>
#include <string>


static const char* token_name(Parser::Tokens kind) {
    switch (kind) {
        case Parser::Tokens::NONE: return "NONE";
        case Parser::Tokens::__WS: return "__WS";
        case Parser::Tokens::AUTO: return "AUTO";
        case Parser::Tokens::AMPERSAND: return "AMPERSAND";
        case Parser::Tokens::FAIL: return "FAIL";
        case Parser::Tokens::advanced_rule_dep_decl_DEPENDS: return "advanced_rule_dep_decl_DEPENDS";
        case Parser::Tokens::rule_value_counter_bounded_EQUALS_SIGN: return "rule_value_counter_bounded_EQUALS_SIGN";
        case Parser::Tokens::SEMICOLON: return "SEMICOLON";
        case Parser::Tokens::COLON: return "COLON";
        case Parser::Tokens::rule_nested_rule_NUMBER_SIGN: return "rule_nested_rule_NUMBER_SIGN";
        case Parser::Tokens::LEFT_CURLY_BRACKET: return "LEFT_CURLY_BRACKET";
        case Parser::Tokens::rule_value_shared_counter_registration_AUTO: return "rule_value_shared_counter_registration_AUTO";
        case Parser::Tokens::COMMERCIAL_AT: return "COMMERCIAL_AT";
        case Parser::Tokens::rule_value_QUANTIFIER: return "rule_value_QUANTIFIER";
        case Parser::Tokens::rule_value_NOSPACE: return "rule_value_NOSPACE";
        case Parser::Tokens::template_params_LESS_THAN_SIGN: return "template_params_LESS_THAN_SIGN";
        case Parser::Tokens::rule_value_STRING: return "rule_value_STRING";
        case Parser::Tokens::grammar_modifier_AUTO: return "grammar_modifier_AUTO";
        case Parser::Tokens::grammar_modifier_MOD: return "grammar_modifier_MOD";
        case Parser::Tokens::rule_value_SPACE: return "rule_value_SPACE";
        case Parser::Tokens::template_params_GREATER_THAN_SIGN: return "template_params_GREATER_THAN_SIGN";
        case Parser::Tokens::rule_value_alternative_VERTICAL_LINE: return "rule_value_alternative_VERTICAL_LINE";
        case Parser::Tokens::grammar_modifier_RIGHT_SQUARE_BRACKET: return "grammar_modifier_RIGHT_SQUARE_BRACKET";
        case Parser::Tokens::rule_value_dyn_DOLLAR_SIGN: return "rule_value_dyn_DOLLAR_SIGN";
        case Parser::Tokens::advanced_rule_regular_match_MATCH: return "advanced_rule_regular_match_MATCH";
        case Parser::Tokens::COMMA: return "COMMA";
        case Parser::Tokens::RIGHT_PARENTHESIS: return "RIGHT_PARENTHESIS";
        case Parser::Tokens::LEFT_PARENTHESIS: return "LEFT_PARENTHESIS";
        case Parser::Tokens::RIGHT_CURLY_BRACKET: return "RIGHT_CURLY_BRACKET";
        case Parser::Tokens::NUMBER: return "NUMBER";
        case Parser::Tokens::rule_value_ANY: return "rule_value_ANY";
        case Parser::Tokens::PY_RAW: return "PY_RAW";
        case Parser::Tokens::ID: return "ID";
        case Parser::Tokens::rule_value_CGROUP: return "rule_value_CGROUP";
    }
    return "UNKNOWN";
}
static std::string escaped(const std::string& s) {
    std::string o; for (unsigned char c : s) { if (c == '"' || c == '\\') { o += '\\'; o += c; }
      else if (c == '\n') o += "\\n"; else if (c == '\r') o += "\\r"; else if (c == '\t') o += "\\t";
      else if (c >= 0x20) o += c; } return o;
}
int main() {
    std::string source((std::istreambuf_iterator<char>(std::cin)), {});
    try {
        // Generated DFA diagnostics must not corrupt the JSON protocol.
        struct Diagnostics {
            std::streambuf* previous = std::cout.rdbuf(std::cerr.rdbuf());
            ~Diagnostics() { std::cout.rdbuf(previous); }
        };
        IspaLexer lexer;
        {
            Diagnostics diagnostics;
            lexer.setInput(source);
            lexer.makeTokens();
            struct BridgeParser : IspaParser { using Parser::Parser::main; };
            BridgeParser parser;
            IspaLexer validationLexer;
            // The custom lexer needs its input initialized for Python block line metadata.
            validationLexer.setInput(source.c_str());
            auto result = parser.main(IspaLexer::lazy_iterator(validationLexer, source.c_str()));
            if (!result.status)
                throw std::runtime_error("Could not parse ISPA grammar");
        }
        std::cout << "{\"ok\":true,\"tokens\":[";
        bool first = true;
        for (const auto& token : lexer.getTokens()) {
            if (token.empty()) continue;
            if (!first) std::cout << ','; first = false;
            std::cout << "{\"kind\":\"" << token_name(token.kind()) << "\",\"start\":" << token.meta().startpos()
                      << ",\"length\":" << token.meta().length() << '}';
        }
        std::cout << "]}";
    } catch (const std::exception& e) { std::cout << "{\"ok\":false,\"error\":\"" << escaped(e.what()) << "\"}"; }
}
