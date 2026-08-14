module LexerBuilder;
import corelib;
import LLIR.Builder;
import LLIR.Builder.Data;
import LLIR.Builder.DataWrapper;
import LLIR.Rule.MemberBuilder;
import LLIR.RuleBuilder;
import NFA;
import DFA.API;
import DFA.functionality;
import DFA;
import logging;
import constants;
import cpuf.printf;
import std;

void accumulateNestedNames(stdu::vector<AST::RuleMember> members, stdu::vector<stdu::vector<std::string>> &names) {
    for (const auto &mem : members) {
        if (mem.isGroup())
            accumulateNestedNames(mem.getGroup().values, names);
        if (mem.isOp())
            accumulateNestedNames(mem.getOp().options, names);
        if (mem.isName())
            names.push_back(mem.getName().name);
    }
}
void LexerBuilder::build() {
    stdu::vector<NFA> nfas;
    std::size_t accept_index = 0;
    for (const auto &[name, rule] : ast) {
        if (corelib::text::isLower(name.back())) {
            continue;
        }
        // token here
        NFA nfa(ast, name, &rule.data_block, rule.rule_members, name == constants::whitespace, true, &accept_index);
        nfa.build(true);
        nfas.push_back(nfa);
    }
    if (nfas.empty()) {
        throw Error("Your grammar does not have any DFA-based token");
    }
    auto dfa_meta = DFA::build(ast, nfas);
    dfa = std::get<0>(dfa_meta);
    lr_table = std::get<1>(dfa_meta);
    semantic_table = std::get<2>(dfa_meta);
    max_registers_count = std::get<3>(dfa_meta);
    // output LR table with

}
auto LexerBuilder::getDataBlocks() const -> LLIR::DataBlockList {
    LLIR::DataBlockList list;
    for (const auto &[name, rule] : ast) {
        if (corelib::text::isLower(name.back()))
            continue;
        // token here
        LLIR::RuleBuilder builder(ast, name, rule, nullptr); builder.build();
        list[name] = builder.getData().block;
    }
    return list;
}