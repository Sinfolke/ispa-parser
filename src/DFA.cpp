module DFA;
import cpuf.op;
import cpuf.printf;
import std;

auto DFA::epsilonClosure(const std::set<size_t>& states) -> std::set<size_t> {
    std::set<size_t> closure = states;
    std::queue<size_t> work;
    for (size_t s : states) work.push(s);

    while (!work.empty()) {
        size_t current = work.front();
        work.pop();

        const auto &transitions = nfa_states->operator[](current).transitions;

        for (const auto& [symbol, target_state] : transitions) {
            if (symbol.empty()) {  // This is an epsilon transition
                if (!closure.count(target_state)) {
                    closure.insert(target_state);
                    work.push(target_state);
                }
            }
        }
    }
    return closure;
}
auto DFA::move(const std::set<size_t> &states, const stdu::vector<std::string> &symbol) -> std::set<size_t> {
    std::set<size_t> result;

    for (auto state_id : states) {
        const auto &state = nfa_states->at(state_id);
        auto it = state.transitions.find(symbol);
        if (it != state.transitions.end()) {
            result.insert(it->second);  // assuming only one target per symbol
        }
    }

    return result;
}
void DFA::build() {
    if (nfa_states->empty()) return;

    using StateSet = std::set<size_t>;

    utype::unordered_map<StateSet, size_t> dfa_state_map;  // DFA state ID per NFA state set
    std::queue<StateSet> work;

    // 1. Start state closure
    StateSet start_set = {0}; // Assuming 0 is NFA start state
    StateSet start_closure = epsilonClosure(start_set);

    size_t dfa_start_index = 0;
    dfa_state_map[start_closure] = dfa_start_index;
    states.emplace_back(); // for DFA state 0
    work.push(start_closure);

    while (!work.empty()) {
        StateSet current = work.front();
        work.pop();

        size_t current_dfa_index = dfa_state_map[current];

        // Collect all symbols from the current NFA states (ignore epsilon transitions)
        utype::unordered_set<stdu::vector<std::string>> input_symbols;
        for (size_t nfa_index : current) {
            const auto &state = nfa_states->at(nfa_index);
            for (const auto &[symbol, _] : state.transitions) {
                if (!symbol.empty())
                    input_symbols.insert(symbol);
            }
        }
        // Assign accept_index here, once per DFA state
        size_t accept_index = NFA::NO_ACCEPT;
        for (size_t nfa_state_id : current) {
            const auto &nfa_state = nfa_states->at(nfa_state_id);
            if (nfa_state.accept_index != NFA::NO_ACCEPT) {
                accept_index = nfa_state.accept_index;
                break;
            }
        }
        states[current_dfa_index].accept_index = accept_index;
        for (const auto &symbol : input_symbols) {
            // 3. Move on symbol, then epsilonClosure
            StateSet move_set = move(current, symbol);
            StateSet closure_set = epsilonClosure(move_set);

            if (closure_set.empty()) continue;

            // If not seen before, assign new DFA state
            if (!dfa_state_map.count(closure_set)) {
                size_t new_index = states.size();
                dfa_state_map[closure_set] = new_index;
                states.emplace_back();
                work.push(closure_set);
                cpuf::printf("Pushing {} to work", closure_set);
            }

            // Record transition
            size_t target_index = dfa_state_map[closure_set];
            states[current_dfa_index].transitions[symbol] = target_index;
            // Determine accept index for current DFA state, if any
        }
    }
}

// Print a single state
std::ostream& operator<<(std::ostream& os, const DFA::state& s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            os << "\t" << key << " -> State " << target << "\n";
        }
    }

    if (s.accept_index != NFA::NO_ACCEPT) {
        os << "\n\taccept -> " << s.accept_index << "\n";
    }
    return os;
}

// Print all states in the vector
std::ostream& operator<<(std::ostream& os, const DFA& dfa) {
    for (size_t i = 0; i < dfa.getStates().size(); ++i) {
        os << "State " << i << ":\n" << dfa.getStates()[i] << "\n";
    }
    return os;
}
