export module LexerBuilder;
import hash;
import AST.API;
import AST.Tree;
import DFA;
import LLIR.API;
import LLIR;
import fcdt;
import dstd;
import std;
export class LexerBuilder {
public:
    static constexpr auto DFA_NOT_COMPATIBLE = std::numeric_limits<std::size_t>::max();
    using DfaCompatibleTable = utype::unordered_map<stdu::vector<std::string>, std::size_t>;
    using NameToDfaMap = utype::unordered_map<stdu::vector<std::string>, std::size_t>;
    using DispatchNamesInvolve = utype::unordered_map<stdu::vector<stdu::vector<std::string>>, NameToDfaMap>;

    using StateSet = utype::unordered_set<DFA::Transitions>;
    using StateSetLocationMap = utype::unordered_map<std::pair<std::size_t, std::size_t>, std::size_t>;
private:
    AST::Tree &ast;
    stdu::vector<DFA> dfas;
    LLIR::IR function_ir;
    FCDT fcdt;
    DfaCompatibleTable dfa_compatible_table;
    DispatchNamesInvolve dispatch_names_involve;
    std::vector<std::size_t> token_type;
    std::size_t highest_states_count = 0;
    std::size_t highest_transition_count = 0;
    bool isDfaCompatible(const stdu::vector<AST::RuleMember> &member);
public:
    LexerBuilder(AST::Tree &ast) : ast(ast), fcdt(ast) {};
    void build();
    auto& getDFAS() { return dfas; }
    auto& getFCDT() { return fcdt; }
    auto& getDfaCompatibleTable() { return dfa_compatible_table; }
    auto& getDispatchNamesInvolve() { return dispatch_names_involve; }
    auto& getFunctionsIR() { return function_ir; }
    auto& getDFAS() const { return dfas; }
    auto& getFCDT() const { return fcdt; }
    auto& getDfaCompatibleTable() const { return dfa_compatible_table; }
    auto& getDispatchNamesInvolve() const { return dispatch_names_involve; }
    auto& getFunctionsIR() const  { return function_ir; }
    auto& getMaxStatesCount() const{ return highest_states_count; }
    auto& getMaxTransitionCount() const { return highest_transition_count; }

    auto getStateSet() const -> std::pair<StateSet, StateSetLocationMap>;

};