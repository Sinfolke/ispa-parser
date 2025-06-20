module DFABuilder;
import AST.Tree;
import Dump;
import logging;
import constants;
import corelib;
import cpuf.op;
import dstd;
import std;

void DFABuilder::log(const NFA &nfa, const stdu::vector<std::string> &fullname) const {
    if (dumper.shouldDump("NFA")) {
        std::ofstream NFA_dump_file;
        NFA_dump_file.open(dumper.makeDumpPath("NFA"), std::ios::app);
        if (!NFA_dump_file.is_open()) {
            throw Error("Couldn't open NFA file");
        }
        NFA_dump_file << "---------- " << fullname << "----------\n";
        NFA_dump_file << nfa;
    }
}
void DFABuilder::log(const DFA &dfa, const stdu::vector<std::string> &fullname) const {
    if (dumper.shouldDump("DFA")) {
        std::ofstream DFA_dump_file;
        DFA_dump_file.open(dumper.makeDumpPath("DFA"), std::ios::app);
        if (!DFA_dump_file.is_open()) {
            throw Error("Couldn't open DFA file");
        }
        DFA_dump_file << "---------- " << fullname << "----------\n";
        DFA_dump_file << dfa;
    };
}
void DFABuilder::log(const NFA &nfa, const std::string &fullname) const {
    if (dumper.shouldDump("NFA")) {
        std::ofstream NFA_dump_file;
        NFA_dump_file.open(dumper.makeDumpPath("NFA"), std::ios::app);
        if (!NFA_dump_file.is_open()) {
            throw Error("Couldn't open NFA file");
        }
        NFA_dump_file << "---------- " << fullname << "----------\n";
        NFA_dump_file << nfa;
    }
}
void DFABuilder::log(const DFA &dfa, const std::string &fullname) const {
    if (dumper.shouldDump("DFA")) {
        std::ofstream DFA_dump_file;
        DFA_dump_file.open(dumper.makeDumpPath("DFA"), std::ios::app);
        if (!DFA_dump_file.is_open()) {
            throw Error("Couldn't open DFA file");
        }
        DFA_dump_file << "---------- " << fullname << "----------\n";
        DFA_dump_file << dfa;
    };
}
void DFABuilder::log(const NFA &nfa, const DFA &dfa, const stdu::vector<std::string> &fullname) const {
    if (dumper.shouldDump("NFA")) {
        std::ofstream NFA_dump_file;
        NFA_dump_file.open(dumper.makeDumpPath("NFA"), std::ios::app);
        if (!NFA_dump_file.is_open()) {
            throw Error("Couldn't open NFA file");
        }
        NFA_dump_file << "---------- " << fullname << "----------\n";
        NFA_dump_file << nfa;
    }
    if (dumper.shouldDump("DFA")) {
        std::ofstream DFA_dump_file;
        DFA_dump_file.open(dumper.makeDumpPath("DFA"), std::ios::app);
        if (!DFA_dump_file.is_open()) {
            throw Error("Couldn't open DFA file");
        }
        DFA_dump_file << "---------- " << fullname << "----------\n";
        DFA_dump_file << dfa;
    };
}
DFABuilder::DFABuilder(const AST::Tree& ast, const AST::RuleMember &rule, const stdu::vector<std::string> &fullname) : dfa(stdu::vector<DFA::SingleState> {}) {
    NFA nfa(ast, rule, fullname == constants::whitespace);
    nfa.build();
    DFA dfa_tmp(nfa);
    dfa_tmp.build();
    log(nfa, dfa_tmp, fullname);
    dfa = std::move(dfa_tmp);
}
DFABuilder::DFABuilder(const AST::Tree& ast, const stdu::vector<AST::RuleMember> &rules, const stdu::vector<std::string> &fullname) : dfa(stdu::vector<DFA::SingleState> {}) {
    NFA nfa(ast, rules, fullname == constants::whitespace);
    nfa.build();
    DFA dfa_tmp(nfa);
    dfa_tmp.build();
    log(nfa, dfa_tmp, fullname);
    dfa = std::move(dfa_tmp);
}
DFABuilder::DFABuilder(const AST::Tree &ast, const stdu::vector<stdu::vector<std::string>> &names) : dfa(stdu::vector<DFA::SingleState> {}) {
    stdu::vector<NFA> nfas;
    for (const auto &name : names) {
        NFA n(ast, ast[name].rule_members, name == constants::whitespace);
        n.build();
        nfas.push_back(n);
        log(n, name);
    }
    DFA dfa_tmp(nfas);
    dfa_tmp.buildWMerge();
    std::string name;
    for (const auto &n : names) {
        name += corelib::text::join(n, "::") + ", ";
    }
    log(dfa_tmp, name);
    dfa = std::move(dfa_tmp);
}