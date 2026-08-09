module DFA.functionality;

import DFA.API;
import DFA.Base;
import DFA;
import corelib;
import hash;
import std;


void DFA::mergeTwoNFA(NFA &first, NFA &second, std::size_t rule_idx) {
    if (second.getStates().empty()) {
        second.build(false);
    }
    if (second.getStates().empty()) {
        return;
    }

    const std::size_t offset = first.getStates().size();
    auto &f = first.getStates();
    const auto &s = second.getStates();

    // Append all states from 'second' and rebase all internal links.
    for (const auto &state : s) {
        auto new_state = state;
        for (auto &[symbol, target_ids] : new_state.transitions) {
            for (auto &target_id : target_ids) {
                target_id.next += offset;
            }
        }
        utype::unordered_set<NFA::TransitionValue> rebased_epsilon;
        for (auto target_id : new_state.epsilon_transitions) {
            target_id.next += offset;
            rebased_epsilon.insert(target_id);
        }
        new_state.epsilon_transitions = std::move(rebased_epsilon);
        if (new_state.any != NFA::NULL_STATE) {
            new_state.any += offset;
        }
        f.emplace_back(std::move(new_state));
    }

    // Union starts via epsilon edge from the shared start state to the appended NFA start.
    f[0].epsilon_transitions.insert({offset});
}

auto DFA::mergeNFAS(const stdu::vector<NFA> &nfas) -> NFA {
    NFA merged = nfas[0];
    if (merged.getStates().empty()) {
        merged.build(false);
    }

    for (std::size_t i = 1; i < nfas.size(); ++i) {
        NFA next = nfas[i]; // Create mutable copy
        mergeTwoNFA(merged, next, i);
    }
    return merged;
}
auto DFA::build(const AST::Tree &ast, const NFA &nfa) -> DFA {
    DFA dfa(&nfa);
    dfa.build();
    dfa.minimize();
    return dfa;
}
auto DFA::build(const AST::Tree &ast, const stdu::vector<NFA> &nfa_collection) -> DFA::ClassifiedDFA {
    auto mergedNFA = mergeNFAS(nfa_collection);
    // construct tables
    auto dfa = DFA(&mergedNFA);
    dfa.build();
    dfa.minimize();
    return dfa.classify();
}