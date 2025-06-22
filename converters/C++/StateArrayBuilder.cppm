export module TransitionArrayBuilder;
import DFA;
import LexerBuilder;

import std;
export class StateArrayBuilder {
    std::ostringstream &out;
    std::ostringstream &h_out;
    std::ostringstream cached_h_out;
    const DFA &dfa;
    std::pair<LexerBuilder::StateSet, LexerBuilder::StateSetLocationMap> &data;
    bool isToken;
    const std::string &namespace_name;
    const LexerBuilder &lexer_data;
public:
    void output();
    void outputHeader() const;
    StateArrayBuilder(
        std::ostringstream &out,
        std::ostringstream &h_out,
        bool isToken,
        const DFA &dfa,
        std::pair<LexerBuilder::StateSet, LexerBuilder::StateSetLocationMap> &data,
        const std::string &namespace_name,
        const LexerBuilder &lexer_data
        )
    : out(out), h_out(h_out), isToken(isToken), dfa(dfa), data(data), namespace_name(namespace_name), lexer_data(lexer_data) {};
};