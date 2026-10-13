#include "Parser.h"
#include <iostream>
#include <string>
#include <variant>

static const char* token_name(Parser::Tokens t) {
    switch (t) {
#define T(x) case Parser::Tokens::x: return #x
        T(NONE); T(compound_statement_AUTO_0); T(name_AUTO_0); T(fail_block_AUTO_0);
        T(grammar_modifier_AUTO_1); T(grammar_modifier_AUTO_0); T(forward_declaration_AUTO_0);
        T(advanced_rule_dep_decl_AUTO_0); T(rule_value_alternative_AUTO_0); T(rule_value_group_AUTO_0);
        T(rule_value_var_capture_AUTO_0); T(rule_ast_full_part_AUTO_0); T(expr_AUTO_1); T(expr_AUTO_0);
        T(rule_value_QUANTIFIER); T(rule_value_counter_bounded_AUTO_0); T(rule_value_CGROUP);
        T(template_params_AUTO_0); T(__WS); T(rule_nested_rule_AUTO_0); T(rule_value_STRING);
        T(rule_value_ast_capture_AUTO_0); T(advanced_rule_AUTO_0); T(template_params_AUTO_1);
        T(rule_value_SPACE); T(rule_value_shared_counter_registration_AUTO_0); T(advanced_rule_AUTO_1);
        T(param_AUTO_0); T(NUMBER); T(advanced_rule_match_AUTO_0); T(ID);
#undef T
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
        Parser::Lexer lexer;
        lexer.setInput(source);
        lexer.makeTokens();
        Parser::Parser parser;
        // Parser::parse(lexer) avoids the setInput() token-presence guard.
        
        const auto& ast = parser.parse(lexer);
        std::cout << "{\"ok\":true,\"ast\":\"" << escaped(ast.to_string()) << "\",\"tokens\":[";
        bool first = true;
        for (const auto& token : lexer.getTokens()) {
            std::visit([&](const auto& node) {
                using N = std::decay_t<decltype(node)>;
                if constexpr (!std::is_same_v<N, std::monostate>) {
                    if (!first) std::cout << ','; first = false;
                    std::cout << "{\"kind\":\"" << token_name(node.name()) << "\",\"start\":" << node.startpos()
                              << ",\"length\":" << node.length() << '}';
                }
            }, token);
        }
        std::cout << "]}";
    } catch (const std::exception& e) { std::cout << "{\"ok\":false,\"error\":\"" << escaped(e.what()) << "\"}"; }
}
