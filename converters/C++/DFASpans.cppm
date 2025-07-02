export module DFASpans;
import DFAS;
import std;
export class DFASpans {
    const DFAS &dfas;
    const std::string &namespace_name;
    std::ostringstream &out;
public:
    void output(bool isToken, const std::string &name) const;
    void outputH(bool isToken) const;
    DFASpans(std::ostringstream &out, const std::string &namespace_name, const DFAS &dfas) : out(out), namespace_name(namespace_name), dfas(dfas) {}
};