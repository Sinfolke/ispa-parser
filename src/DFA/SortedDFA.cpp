module DFA.SortedDFA;
import boost;
import std;

void DFA::SortedDFA::sort() {
    // move states from min dfa to this dfa
    for (const auto &state : min_dfa.get()) {
        auto new_state_id = states.makeNew();
        states[new_state_id].dtb = std::move(state.dtb);
        states[new_state_id].else_goto = state.else_goto;
        states[new_state_id].else_goto_accept = state.else_goto_accept;
        states[new_state_id].nfa_states = std::move(state.nfa_states);
        states[new_state_id].rule_name = std::move(state.rule_name);
        // create a sorted vector
        SortedTransitions::sequence_type sorted_transitions;
        sorted_transitions.reserve(states.size());
        for (const auto &[key, value] : state.transitions) {
            sorted_transitions.emplace_back(key, std::move(value));
        }
        std::sort(sorted_transitions.begin(), sorted_transitions.end(), Comparator(ast));
        states[new_state_id].transitions.adopt_sequence(std::move(sorted_transitions));
    }
}

auto DFA::SortedDFA::getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType {
    return Base::getType(states, isToken, dct);
}