#include <parser.h>
namespace Tokens {
    Parser::Rule singleRuleToToken(Parser::Rule input);
    Parser::Rule make_rule();
    Parser::Rule make_rule(Parser::Rules name);
    Parser::Rule make_rule(Parser::Rules name, std::any data);
    bool compare_rule(Parser::Rule first, Parser::Rule second);
    int compare_rules(Parser::Tree token_rule, Parser::Tree rules);
}