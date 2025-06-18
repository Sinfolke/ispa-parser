export module LexerBuilder;
import hash;
import AST.API;
import AST.Tree;
import DFA;
import LLIR.API;
import fcdt;
import dstd;
import std;
export class LexerBuilder {
public:
    static constexpr auto DFA_NOT_INVOLVED = std::numeric_limits<std::size_t>::max();
    using isDfaInvolvedTable = utype::unordered_map<stdu::vector<std::string>, std::size_t>;
private:
    AST::Tree &ast;
    stdu::vector<DFA> dfas;
    stdu::vector<DFA> function_dfas;
    stdu::vector<LLIR::Data> functions;
    FCDT fcdt;
    isDfaInvolvedTable is_dfa_involved_table;
    bool isDfaCompatible(const stdu::vector<AST::RuleMember> &member);
public:
    LexerBuilder(AST::Tree &ast) : ast(ast), fcdt(ast) {};
    void build();
    auto getDFAS() { return dfas; }
    auto getFunctionDFAS() { return function_dfas; }
    auto getFunctions() { return functions; }
    auto getFCDT() { return fcdt; }
    auto getIsDfaInvolvedTable() { return is_dfa_involved_table; }
    auto& getDFAS() const { return dfas; }
    auto& getFunctionDFAS() const { return function_dfas; }
    auto& getFunctions() const { return functions; }
    auto& getFCDT() const { return fcdt; }
    auto& getIsDfaInvolvedTable() const { return is_dfa_involved_table; }
};