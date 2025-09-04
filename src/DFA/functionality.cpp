module DFA.functionality;

import DFA.API;
import DFA.MDFA;
import DFA.SDFA;
import DFA.MinDFA;
import DFA.SortedDFA;
import DFA.MachineDFA;
import std;

auto DFA::buildDfaIndexToEmptyStateMap(stdu::vector<MDFA> &dfas) -> DfaIndexToEmptyStateMap {
    DfaIndexToEmptyStateMap dfa_index_to_empty_state_map;

    std::size_t global_offset = 0;
    for (std::size_t dfa_idx = 0; dfa_idx < dfas.size(); ++dfa_idx) {
        auto &dfa = dfas[dfa_idx];

        // scan this DFA's states, starting from index 1 to skip start state
        std::size_t empty_global = std::numeric_limits<std::size_t>::max();
        for (std::size_t local = 1; local < dfa.get().size(); ++local) {
            if (dfa.get()[local].transitions.empty()) {
                empty_global = global_offset + local;
                break;
            }
        }

        // if none found, append one:
        if (empty_global == std::numeric_limits<std::size_t>::max()) {
            empty_global = global_offset + dfa.get().makeNew();
        }

        dfa_index_to_empty_state_map[dfa_idx] = empty_global;

        // advance offset for next DFA
        global_offset += dfa.get().size();
    }
    return dfa_index_to_empty_state_map;
}

auto DFA::buildDfaEmptyStateMap(stdu::vector<MDFA> &dfas) -> DfaEmptyStateMap {
    DfaEmptyStateMap dfa_empty_state_map;
    std::size_t count = 0;
    for (auto &dfa : dfas) {
        std::size_t empty_state = NFA::NULL_STATE;
        stdu::vector<std::size_t> delayed;
        for (const auto &state : dfa.get()) {
            if (state.transitions.empty() && !state.rule_name.empty()) {
                empty_state = count;
                for (const auto id : delayed) {
                    dfa_empty_state_map[id] = empty_state;
                }
                delayed.clear();
            } else if (empty_state == NFA::NULL_STATE) {
                delayed.push_back(count);
                count++;
                continue;
            }
            dfa_empty_state_map[count] = empty_state;
            count++;
        }
        if (!delayed.empty()) {
            empty_state = dfa.get().makeNew();
            for (const auto id : delayed) {
                dfa_empty_state_map[id] = empty_state;
            }
        }
    }
    return dfa_empty_state_map;
}
void DFA::mergeTwoDFA(MDFA &first, const MDFA &second, std::size_t index)  {
    std::size_t offset = first.get().size();
    auto &f = first.get();
    const auto &s = second.get();
    for (const auto &[symbol, next] : s[0].transitions) {
        for (const auto &n : next) {
            f[0].transitions[symbol].emplace_back(TransitionValue {offset + n.value.next, n.value.new_cst_node, n.value.new_member, n.value.close_cst_node, n.value.new_group, n.value.group_close, n.value.accept_index, n.value.optional, n.value.last}, index);
        }
    }
    // Copy and fixup second DFA states
    for (const auto &state : s) {
        auto new_state = state;
        for (auto &[symbol, nexts] : new_state.transitions) {
            for (auto &next : nexts) {
                next.value.next += offset;
            }
        }
        if (new_state.else_goto)
            new_state.else_goto += offset;

        f.constructNewFrom(std::move(new_state));
    }
}

auto DFA::mergeDFAS(stdu::vector<MDFA> &dfas) -> MDFA {
    auto &initial_states = dfas[0];
    for (auto it = dfas.begin() + 1; it != dfas.end(); ++it) {
        mergeTwoDFA(initial_states, *it, it - dfas.begin());
    }
    return initial_states;
}
auto DFA::build(const AST::Tree &ast, const NFA &nfa) -> MachineDFA {
    MDFA mdfa(nfa); mdfa.build();
    SDFA sdfa(mdfa); sdfa.build();
    MinDFA min_dfa(sdfa); min_dfa.minimize();
    SortedDFA sorted_dfa(ast, min_dfa); sorted_dfa.sort();
    MachineDFA machine_dfa(ast, sorted_dfa); machine_dfa.build();
    return machine_dfa;
}
auto DFA::build(const AST::Tree &ast, const stdu::vector<NFA> &nfa_collection) -> MachineDFA {
    stdu::vector<MDFA> dfas;
    for (const auto &nfa : nfa_collection) {
        MDFA mdfa(nfa); mdfa.build();
        dfas.push_back(mdfa);
    }
    // construct tables
    auto dfa_index_to_empty_state_map = buildDfaIndexToEmptyStateMap(dfas);
    auto dfa_empty_state_map = buildDfaEmptyStateMap(dfas);
    auto dfa = mergeDFAS(dfas);
    SDFA sdfa(dfa, dfa_empty_state_map, dfa_index_to_empty_state_map); sdfa.build();
    MinDFA min_dfa(sdfa, dfa_empty_state_map, dfa_index_to_empty_state_map); min_dfa.minimize();
    SortedDFA sorted_dfa(ast, min_dfa, dfa_empty_state_map, dfa_index_to_empty_state_map); sorted_dfa.sort();
    MachineDFA machine_dfa(ast, sorted_dfa, dfa_empty_state_map, dfa_index_to_empty_state_map); machine_dfa.build();
    return machine_dfa;
}