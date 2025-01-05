// Tokenizator class definitions
#include "Parser.h"
Parser::TokenFlow Parser::Tokenizator::makeTokenFlow() {
    // Implement the tokenization logic here
    return {};
}

// Token methods
Parser::Token_result Parser::Tokenizator::NUMBER(const char* const in) {
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
    skipSpaces(pos);
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

Parser::Token_result Parser::Tokenizator::OP(const char* const in) {
    // matched sequence: [ "12", "-", "5", "<", "4", "*", "100" ]
    // groups sequence: [ /* here is first group */    [ 0x4, 0x5, 0x6, 0x7 ] - pointers to location of matched elements ]
    int c = 0;
    const char* pos = in;
    Token_result result;
    Group<1> current; // that was the max size groups could have
    Groups groups = {}; // unused here
    current.push();
    skipSpaces(pos);
    if ((c = *pos) == '+' || c == '-' || c == '/' || c == '*') {
        current[0] = string_part(pos, 1);
        ++pos;
    } else return {};

    result.result = true;
    result.newpos = in;
    result.token = Token(getCurrentPos(in), in, pos, Tokens::OP, current[0]); // the data section fill up later
    return result;
}
Parser::Token_result Parser::Tokenizator::COP(const char* const in) {
    // matched sequence: [ "12", "-", "5", "<", "4", "*", "100" ]
    // groups: [ /* here is first group */    [ 0x4, 0x5, 0x6, 0x7 ] 
    //          (pointers to location of matched elements | a token result | a rule result ] )
    int c = 0;
    const char* pos = in;
    Token_result result;
    Group<1> current; // that was the max size groups could have
    Groups groups = {}; // unused here
    current.push();
    skipSpaces(pos);
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
Parser::Token_result Parser::Tokenizator::END(const char* const in) {
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


Parser::Rule_result Parser::Parser::expr(const Token* const in) {
    Token token;
    const Token* pos = in;
    Rule_result result;
    Group<4> current;
    Groups groups = {};


    // on top declaration of user defined variables
    std::deque<std::map<std::string, std::any>> data;
    std::deque<std::string> COP;
    std::deque<std::string> LEFT;
    std::deque<std::string> OP;
    std::deque<std::string> RIGHT;

    // do matching... NUMBER OP NUMBER (COP NUMBER OP NUMBER)?
    //     data[0] = { left: %1, op: %2, right: %3, COP: "" };
    if (pos->name != Tokens::NUMBER || (pos + 1)->name != Tokens::OP || (pos + 2)->name != Tokens::NUMBER) {
        return {};
    }
    data.push_back( { {  "left", *pos }, { "op", *(pos + 1) }, { "right", *(pos + 2) }, { "COP", "" } } );
    pos += 3;
    if (pos->name == Tokens::COP && (pos + 1)->name == Tokens::NUMBER && (pos + 2)->name == Tokens::OP && (pos + 3)->name == Tokens::NUMBER) {
        // data[1] = { left: $1>%1, op: $1>%2, right: $1>%3, COP: $1>4 }
        data.push_back( { {  "left", *pos }, { "op", *(pos + 1) }, { "right", *(pos + 2) }, { "COP", *(pos + 3) } } );
        pos += 4;
    }
    result.newpos = pos - in;
    result.result = true;
    result.token = data;
    return result;
}