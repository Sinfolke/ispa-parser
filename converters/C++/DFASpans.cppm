export module DFASpans;
import DFAS;
import hash;
import dstd;
import std;
export class DFASpans {
    const DFAS &dfas;
    const std::string &namespace_name;
    std::ostringstream &out;
    const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct;
public:
    void output(bool isToken, const std::string &name) const;
    void outputH(bool isToken) const;
    DFASpans(std::ostringstream &out, const std::string &namespace_name, const DFAS &dfas, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) : out(out), namespace_name(namespace_name), dfas(dfas), dct(dct) {}
};