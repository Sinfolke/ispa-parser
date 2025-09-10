export module DFASpans;
import DFA.Collection;
import hash;
import dstd;
import std;

export template<typename CollectionDfaType>
class DFASpans {
    const DFA::Collection<CollectionDfaType> &dfas;
    const std::string &namespace_name;
    std::ostringstream &out;
    const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct;
public:
    void output(bool isToken, const std::string &name) const;
    void outputH(bool isToken) const;
    DFASpans(std::ostringstream &out, const std::string &namespace_name, const DFA::Collection<CollectionDfaType> &dfas, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) : out(out), namespace_name(namespace_name), dfas(dfas), dct(dct) {}
};