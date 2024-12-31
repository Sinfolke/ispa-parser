#include <parser.h>
namespace Tokens {
    Parser::Rule singleRuleToToken(Parser::Rule input);
    Parser::Rule make_rule(Parser::Rules name, std::any data);
}