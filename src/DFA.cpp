module DFA;
import cpuf.op;
import cpuf.printf;
import std;

auto DFA::epsilonClosure(const stdu::vector<size_t>& states) const -> stdu::vector<size_t> {
    stdu::vector<size_t> closure = states;
    std::queue<size_t> work;
    for (size_t s : states) work.push(s);

    while (!work.empty()) {
        size_t current = work.front();
        work.pop();

        const auto &epsilons = nfa_states->at(current).epsilon_transitions;

        for (size_t target_state : epsilons) {
            if (std::find(closure.begin(), closure.end(), target_state) == closure.end()) {
                closure.push_back(target_state);
                work.push(target_state);
            }
        }
    }

    return closure;
}
auto DFA::move(const stdu::vector<size_t> &states, const stdu::vector<std::string> &symbol) const -> std::vector<size_t> {
    std::vector<size_t> result;

    for (auto state_id : states) {
        const auto &state = nfa_states->at(state_id);
        auto it = state.transitions.find(symbol);
        if (it != state.transitions.end()) {
            result.push_back(it->second);  // assuming only one target per symbol
        }
    }

    return result;
}
void DFA::build() {
    if (nfa_states->empty()) return;

    using StateSet = stdu::vector<size_t>;

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
        utype::unordered_map<stdu::vector<std::string>, transition_value> input_symbols;
        for (size_t nfa_index : current) {
            const auto &state = nfa_states->at(nfa_index);
            for (const auto &[symbol, id] : state.transitions) {
                if (!symbol.empty())
                    input_symbols[symbol] = {id, state.accept_index};
            }
        }
        size_t accept_count = 0;
        for (const auto &[symbol, data] : input_symbols) {
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
            }

            // Record transition
            size_t target_index = dfa_state_map[closure_set];
            states[current_dfa_index].transitions[symbol] = {target_index, data.ACCEPT_STATE};
            size_t current_accept_count = accept_count;
            if (symbol == std::vector<std::string>{"__WHITESPACE"}) {
                states[current_dfa_index].transitions[symbol].ACCEPT_STATE = NFA::NO_ACCEPT;
                continue;
            }
            for (const auto &c : current) {
                if (nfa_states->at(c).accept_index != NFA::NO_ACCEPT) {
                    if (current_accept_count != 0) {
                        current_accept_count--;
                        continue;
                    }
                    accept_count++;
                    states[current_dfa_index].transitions[symbol].ACCEPT_STATE = nfa_states->at(c).accept_index;
                    break;
                }
            }
        }
    }
}

// Print a single state
std::ostream &operator<<(std::ostream &os, const DFA::state &s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            os << "\t" << key << " -> State " << target.next
            << (target.ACCEPT_STATE != NFA::NO_ACCEPT ? std::string(" { accept -> ") + std::to_string(target.ACCEPT_STATE) + " } " : std::string(""))
            << "\n";
        }
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
