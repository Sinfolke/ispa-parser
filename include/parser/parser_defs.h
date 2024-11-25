#define TOKEN(x, ...) Parser::Token_result Parser::Tokenisator::x (const char* in, ##__VA_ARGS__)
#define Rule(x, ...) Parser::Rule_result Parser::Parser::x (const char* in, ##__VA_ARGS__)
#define TO(t, x) std::any_cast<t>(x)
#define TOKEN_SUCCESS(in, pos, name) return { \
    true, { \
        getCurrentPos(in), in, pos, Parser::Tokens::name \
    } \
}
#define TOKEN_SUCCESSD(in, pos, name, data) return { \
    true, { \
        getCurrentPos(in), in, pos, Parser::Tokens::name, data \
    } \
}
#define RULE_SUCCESS(in, pos, name) return { \
    true, { \
        getCurrentPos(in), in, pos, ::Parser::Parser::name \
    } \
}
#define RULE_SUCCESSD(in, pos, name, data) return { \
    true, { \
        getCurrentPos(in), in, pos, ::Parser::Parser::name, data \
    } \
}
