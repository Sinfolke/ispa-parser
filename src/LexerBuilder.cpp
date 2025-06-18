module LexerBuilder;
import corelib;
import LLIR.Builder;
import LLIR.Builder.Data;
import LLIR.Builder.DataWrapper;
import LLIR.Rule.MemberBuilder;
import LLIR.RuleBuilder;
import std;
bool LexerBuilder::isDfaCompatible(const stdu::vector<AST::RuleMember> &member) {
    for (const auto &mem : member) {
        if (mem.isCll())
            return false;
    }
    return true;
}

void LexerBuilder::build() {
    fcdt.build();
    std::size_t dfa_count = 0;
    for (auto mem : fcdt.get()) {
        if (mem.empty())
            continue;
        std::unordered_set<std::unordered_set<std::vector<std::string>>> build;
        for (const auto &name : mem) {
            if (isDfaCompatible(ast[name].rule_members)) {
                is_dfa_involved_table[name] = dfa_count;
            } else {
                is_dfa_involved_table[name] = DFA_NOT_INVOLVED;
                mem.erase(name);
                LLIR::RuleBuilder builder(ast, name, ast[name], function_dfas);
                functions.push_back(builder.getData());
            }
        }
        dfas.push_back(DFABuilder(ast, mem).get());
        dfa_count++;
    }
}
