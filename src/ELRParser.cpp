#include <ELRParser.h>
std::set<size_t> ELRParser::epsilon_closure(const std::set<size_t>& states) {
    std::set<size_t> closure = states;
    std::queue<size_t> work;
    for (size_t s : states) work.push(s);

    while (!work.empty()) {
        size_t current = work.front();
        work.pop();
        auto it = nfa_states[current].transitions.find({}); // Empty vector = ε-transition
        if (it != nfa_states[current].transitions.end()) {
            for (size_t target : it->second) {
                if (!closure.count(target)) {
                    closure.insert(target);
                    work.push(target);
                }
            }
        }
    }
    return closure;
}
void ELRParser::build() {
    transform();
    prepare();
    buildTable(false);
    // build nfa
    for (const auto &[items, place, conflicts, state] : conflicts) {
        if (items.size() == 2) {
            auto item = items[0];
            auto next = items[1];
            if (item.rhs == next.rhs) {
                // resolve conflict by picking shift over reduce. If reduce/reduce conflict report it
                if (conflicts[0].type == Action_type::REDUCE && conflicts[1].type == Action_type::REDUCE) {
                    cpuf::printf("Insoluble REDUCE/REDUCE conflict in NFA for rule %$\n", corelib::text::join(item.lhs.fullname, "_"));
                } else if (conflicts[0].type == Action_type::SHIFT && conflicts[1].type == Action_type::REDUCE) {
                    *place = conflicts[0];
                } else {
                    *place = conflicts[1];
                }
                continue;
            }
        }
        size_t start_state = nfa_states.size();
        nfa_states.emplace_back(); // Start state
        nfa_states[start_state].is_starting_state = true; // first item is starting state
        for (size_t i = 0; i < items.size(); ++i) {
            const auto &item = items[i];
            if (i + 1 < items.size()) {
                const auto &next = items[i + 1];
                if (item.rhs == next.rhs) {
                    cpuf::printf("Insoluble high ambiguity in NFA for rule %$ and %$. Rhs: ", corelib::text::join(item.lhs.fullname, "_"), corelib::text::join(next.lhs.fullname, "_"));
                    for (auto el : item.rhs) {
                        cpuf::printf("%$ ", corelib::text::join(el.fullname, "_"));
                    }
                    cpuf::printf(", ");
                    for (auto el : next.rhs) {
                        cpuf::printf("%$ ", corelib::text::join(el.fullname, "_"));
                    }
                    cpuf::printf("\n");
                }
            }
            size_t current = start_state;
            for (size_t j = item.dot_pos - 2; j < item.rhs.size(); ++j) {
                auto sym = item.rhs[j];
                size_t next = nfa_states.size();
                nfa_states.emplace_back();
                if (corelib::text::isUpper(sym.name)) {
                    // terminal, just push
                    nfa_states[current].transitions[sym.fullname].push_back(next);
                } else {
                    // non terminal, untoll using first set
                    auto f = first[sym.fullname];
                    for (const auto &token : f) {
                        nfa_states[current].transitions[token].push_back(next);
                    }
                }
                current = next;

            }
            nfa_states[current].reduce_action = conflicts[i]; // correct one-to-one mapping
        }
        
        
    }
    // build dfa based on nfa
    if (nfa_states.empty()) // return if nfa is empty
        return;
    std::unordered_map<std::set<size_t>, size_t> dfa_state_map;
    std::queue<std::set<size_t>> worklist;
    std::set<size_t> start_set = {0};
    start_set = epsilon_closure(start_set);
    dfa_states.push_back({start_set});
    dfa_state_map[start_set] = 0;
    for (size_t i = 0; i < nfa_states.size(); ++i) {
        if (nfa_states[i].is_starting_state) {
            worklist.push({i});
        }
    }
    while (!worklist.empty()) {
        std::set<size_t> current_set = worklist.front();
        worklist.pop();
        size_t current_dfa_index = dfa_state_map[current_set];

        std::unordered_map<std::vector<std::string>, std::set<size_t>> symbol_to_nfa_targets;

        // Populate symbol_to_nfa_targets for all transitions in the current NFA set
        for (size_t state : current_set) {
            cpuf::printf("state %$, transitions size: %$\n", state, nfa_states[state].transitions.size());
            for (const auto& [symbol, targets] : nfa_states[state].transitions) {
                cpuf::printf("processing %$ for symbol %$, targets: %$:", state, symbol, targets);
                if (!symbol.empty()) { // Exclude ε-transitions here
                    symbol_to_nfa_targets[symbol].insert(targets.begin(), targets.end());
                }
            }
        }

        // Process each symbol and its target set
        for (const auto& [symbol, target_set] : symbol_to_nfa_targets) {
            // Compute ε-closure of the target set
            std::set<size_t> closure = epsilon_closure(target_set);

            if (!dfa_state_map.count(closure)) {
                // New DFA state
                size_t new_dfa_index = dfa_states.size();
                dfa_states.push_back({closure});
                dfa_state_map[closure] = new_dfa_index;
                worklist.push(closure);
            }

            // Add transition to the current DFA state
            dfa_states[current_dfa_index].transitions[symbol] = dfa_state_map[closure];
        }

        // Resolve reduce actions: only assign if all underlying NFA states agree
        std::optional<Action> reduce_action;
        for (size_t state : current_set) {
            if (nfa_states[state].reduce_action.has_value()) {
                if (!reduce_action.has_value()) {
                    reduce_action = nfa_states[state].reduce_action;
                } else {
                    auto current_action = reduce_action.value();
                    auto new_action = nfa_states[state].reduce_action.value();
                    if (current_action.type != new_action.type || current_action.state != new_action.state) {
                        // Conflict: different action types or states
                        cpuf::printf("Conflict in DFA state %$ between actions %$ and %$\n", current_dfa_index, LRParser::ActionTypeToString(current_action.type), LRParser::ActionTypeToString(new_action.type));
                        // Handle conflict resolution here; prefer one action or leave unresolved
                        reduce_action.reset(); // Reset to no action if conflict cannot be resolved
                        break;
                    }
                }
            }
        }
        // Assign the resolved reduce action to the DFA state
        dfa_states[current_dfa_index].reduce_action = reduce_action;
    }
}

void ELRParser::printNfa(const std::string filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }
    for (size_t i = 0; i < nfa_states.size(); ++i) {
        out << "State " << i << ":\n";
        // Print transitions
        for (const auto &[sym, targets] : nfa_states[i].transitions) {
            for (size_t target : targets) {
                out << "  --" << sym << "--> " << target << "\n";
            }
        }

        // Print reduce action if present
        if (nfa_states[i].reduce_action.has_value()) {
            const auto &action = nfa_states[i].reduce_action.value();
            out << '[' << LRParser::ActionTypeToString(action.type) << " " << action.state << ']' << "\n";
        }

        out << "\n";
    }

    out.close();
}
void ELRParser::printDfa(const std::string filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to open DFA output file: " << filename << "\n";
        return;
    }

    for (size_t i = 0; i < dfa_states.size(); ++i) {
        const auto &state = dfa_states[i];
        out << i << ": {";
        bool first = true;
        for (auto id : state.nfa_states) {
            if (!first) out << ", ";
            out << id;
            first = false;
        }
        out << "}:\n";

        for (const auto &[symbols, target] : state.transitions) {
            out << "  --{ ";
            for (size_t j = 0; j < symbols.size(); ++j) {
                out << symbols[j];
                if (j + 1 < symbols.size()) out << ", ";
            }
            out << " }--> " << target << "\n";
        }

        if (state.reduce_action.has_value()) {
            out << " ["
                << LRParser::ActionTypeToString(state.reduce_action.value().type) << " " << state.reduce_action.value().state
                << "]\n";
        }
        out << "\n";
    }

    out.close();
}
