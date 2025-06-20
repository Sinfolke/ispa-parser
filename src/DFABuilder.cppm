export module DFABuilder;
import NFA;
import DFA;
import fcdt;
import AST.API;
import AST.Tree;
import dstd;
import std;
export class DFABuilder {
    DFA dfa;
    void log(const NFA &nfa, const stdu::vector<std::string> &fullname) const;
    void log(const DFA &dfa, const stdu::vector<std::string> &fullname) const;
    void log(const NFA &nfa, const std::string &fullname) const;
    void log(const DFA &dfa, const std::string &fullname) const;
    void log(const NFA &nfa, const DFA &dfa, const stdu::vector<std::string> &fullname) const;
public:
    DFABuilder(const AST::Tree& ast, const AST::RuleMember &rule, const stdu::vector<std::string> &fullname);
    DFABuilder(const AST::Tree& ast, const stdu::vector<AST::RuleMember> &rules, const stdu::vector<std::string> &fullname);
    DFABuilder(const AST::Tree& ast, const stdu::vector<stdu::vector<std::string>> &names);
    DFA& get() {
        return dfa;
    }
};