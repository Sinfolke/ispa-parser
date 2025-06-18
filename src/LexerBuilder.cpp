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
    for (const auto &[name, rule] : ast) {
        if (corelib::text::isLower(name.back()))
            continue;
        if (isDfaCompatible(rule.rule_members)) {
            dfas.push_back(DFABuilder(ast, rule.rule_members, name).get());
            is_dfa_involved_table[name] = dfa_count++;;
        } else {
            LLIR::RuleBuilder builder(ast, name, rule, function_dfas);
            functions.push_back(builder.getData());
            is_dfa_involved_table[name] = std::numeric_limits<std::size_t>::max();
        }
    }
}
