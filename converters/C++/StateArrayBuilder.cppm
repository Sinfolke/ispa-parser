export module StateArrayBuilder;

import DFA.Collection;
import LexerBuilder;
import std;

export class StateArrayBuilder {
    std::ostringstream &out;
    const DFA::Collection::StateSet_t &data;
    bool isToken;
    const std::string &namespace_name;
    const DFA::Collection dfas;
    const LexerBuilder::DfaCompatibleTable *dfa_compatible_table;
    const std::string &prefix;
public:
    void output();
    void outputHeader();
    StateArrayBuilder(
        std::ostringstream &out,
        bool isToken,
        const DFA::Collection::StateSet_t &data,
        const std::string &namespace_name,
        const DFA::Collection &dfas,
        const LexerBuilder::DfaCompatibleTable *compatible_table,
        const std::string &prefix
        )
    : out(out), isToken(isToken), data(data), namespace_name(namespace_name), dfas(dfas), dfa_compatible_table(compatible_table), prefix(prefix) {};
};