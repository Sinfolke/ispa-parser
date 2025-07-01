export module StateArrayBuilder;
import DFA;
import DFAS;
import LexerBuilder;

import std;
export class StateArrayBuilder {
    std::ostringstream &out;
    const std::pair<DFAS::StateSet, DFAS::StateSetLocationMap> &data;
    bool isToken;
    const std::string &namespace_name;
    const DFAS dfas;
    const LexerBuilder::DfaCompatibleTable *dfa_compatible_table;
    const std::string &prefix;
public:
    void output();
    void outputHeader();
    StateArrayBuilder(
        std::ostringstream &out,
        bool isToken,
        const std::pair<DFAS::StateSet, DFAS::StateSetLocationMap> &data,
        const std::string &namespace_name,
        const DFAS &dfas,
        const LexerBuilder::DfaCompatibleTable *compatible_table,
        const std::string &prefix
        )
    : out(out), isToken(isToken), data(data), namespace_name(namespace_name), dfas(dfas), dfa_compatible_table(compatible_table), prefix(prefix) {};
};