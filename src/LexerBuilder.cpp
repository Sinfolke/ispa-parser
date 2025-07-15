module LexerBuilder;
import corelib;
import LLIR.Builder;
import LLIR.Builder.Data;
import LLIR.Builder.DataWrapper;
import LLIR.Rule.MemberBuilder;
import LLIR.RuleBuilder;
import DFABuilder;
import cpuf.printf;
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
    utype::unordered_set<stdu::vector<stdu::vector<std::string>>> build;
    stdu::vector<DFA> function_dfas;
    stdu::vector<LLIR::Data> functions;
    for (auto mem : fcdt.get()) { // mem should be copy
        if (mem.empty())
            continue;
        if (build.contains(mem)) {
            continue;
        }
        build.insert(mem);
        NameToDfaMap involved_symbols;
        for (const auto &name : mem) {
            if (isDfaCompatible(ast[name].rule_members)) {
                involved_symbols[name] = dfa_count;
                dfa_compatible_table[name] = dfa_count;
            } else {
                dfa_compatible_table[name] = DFA_NOT_COMPATIBLE;
                auto it = std::find(mem.begin(), mem.end(), name);
                mem.erase(it);
                LLIR::RuleBuilder builder(ast, name, ast[name], function_dfas);
                functions.push_back(builder.getData());
            }
        }
        dispatch_names_involve.emplace(mem, involved_symbols);
        DFABuilder builder(ast, mem, true);
        dfas.getDFAS().push_back(builder.get());
        highest_states_count = std::max(highest_states_count, builder.get().getStates().size());
        highest_transition_count = std::max(highest_transition_count, builder.get().getMaxTransitionCount());
        dfa_count++;
    }
    function_ir = std::move(LLIR::IR(functions, function_dfas));
}

auto LexerBuilder::getStateSet() const -> DFAS::StateSet_t {
    utype::unordered_map<DFA::Transitions, std::size_t> state_to_map;

    std::size_t dfa_count = 0;
    auto state_set = dfas.getStateSet();
    function_ir.getDfas().getStateSet(state_set);
    return state_set;
}