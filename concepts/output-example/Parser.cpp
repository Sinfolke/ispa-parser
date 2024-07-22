// Tokenisator class definitions
#include "Parser.h"

Parser::TokenFlow Parser::Tokenisator::makeTokenFlow() {
    // Implement the tokenization logic here
    return {};
}

// Token methods
Parser::Token_result Parser::Tokenisator::NUMBER(const char* const in) {
    // matched sequence: [ "12", "-", "5", "<", "4", "*", "100" ]
    // groups sequence: [ /* here is first group */    [ 0x4, 0x5, 0x6, 0x7 ] - pointers to location of matched elements ]
    int c = 0;
    const char* pos = in;
    Token_result result;
    Group<2> current; // that was the max size groups could have
    Groups groups = {}; // unused here
    current.push();

    if ((c = *pos) == '-') {
        current[0] = string_part(pos, 1);
        ++pos;
    }

    if (c >= '0' && c <= '9') {
        const char* const start = pos;
        do ++pos; while ((c = *pos) >= '0' && c <= '9');
        current[1] = string_part(start, pos);
    } else return {};

    result.result = true;
    result.newpos = in;
    result.token = Token(getCurrentPos(in), in, pos, Tokens::NUMBER);
    return result;
}

Parser::Token_result Parser::Tokenisator::OP(const char* const in) {
    // matched sequence: [ "12", "-", "5", "<", "4", "*", "100" ]
    // groups sequence: [ /* here is first group */    [ 0x4, 0x5, 0x6, 0x7 ] - pointers to location of matched elements ]
    int c = 0;
    const char* pos = in;
    Token_result result;
    Group<1> current; // that was the max size groups could have
    Groups groups = {}; // unused here
    current.push();

    if ((c = *pos) == '+' || c == '-' || c == '/' || c == '*') {
        current[0] = string_part(pos, 1);
        ++pos;
    } else return {};

    result.result = true;
    result.newpos = in;
    result.token = Token(getCurrentPos(in), in, pos, Tokens::OP, current[0]); // the data section fill up later
    return result;
}
Parser::Token_result Parser::Tokenisator::COP(const char* const in) {
    // matched sequence: [ "12", "-", "5", "<", "4", "*", "100" ]
    // groups: [ /* here is first group */    [ 0x4, 0x5, 0x6, 0x7 ] 
    //          (pointers to location of matched elements | a token result | a rule result ] )
    int current_pos = getCurrentPos(in);
    int c = 0;
    const char* pos = in;
    Token_result result;
    Group<1> current; // that was the max size groups could have
    Groups groups = {}; // unused here
    current.push();

    if ((c = *pos) == '>' || c == '<') {
        if (*(pos + 1) == '=') {
            current[0] = string_part(pos, 2);
            pos += 2;
        } else {
            current[0] = string_part(pos, 1);
            ++pos;
        }
    } else return {};
    result.result = true;
    result.newpos = in;
    result.token = Token(getCurrentPos(in), pos, in, Tokens::NUMBER, current[0]); // the data section fill up later
    return result;
}
Parser::Token_result Parser::Tokenisator::END(const char* const in) {
    Token_result result;
    Group<1> current; // that was the max size groups could have
    Groups groups = {}; // unused here

    if (*in != ';')
        return {};

    result.result = true;
    result.newpos = in;
    result.token = Token(getCurrentPos(in), in, 1, Tokens::END);
    // no data section
    return result;
}
Parser::Tree Parser::Parser::parse() {
    // parse logic here
    return {};
}
// Rule methods


Parser::Tree Parser::Parser::expr(const Token* const in) {
    int current_pos = getCurrentPos(in);
    Token token;
    const Token* pos = in;
    Rule_result result;
    Group<4> current;
    Groups groups = {};


    // on top declaration of user defined variables
    std::deque<std::unordered_map<std::string, std::string>> data;
    std::deque<std::string> COP;
    std::deque<std::string> LEFT;
    std::deque<std::string> OP;
    std::deque<std::string> RIGHT;

    // do matching... NUMBER OP NUMBER (COP NUMBER OP NUMBER)?

    if ((token = *pos).name == Tokens::NUMBER) {
        current.push()
    }



    // $array<object<string>> data;
    // $array<string> COP = $1>%1;
    // $array<string> LEFT = $1>%2;
    // $array<string> OP = $1>%3;
    // $array<string> RIGHT = $1>%4;
    return Tree();
}