#include <ELRParser.h>
bool ELRParser::isELR() const {
    return true;
}
const std::vector<ELRParser::DFA_state>& ELRParser::getDFA() const {
    return dfa_states;
}
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
    for (auto &[items, place, conflicts, state] : conflicts) {
        if (items.size() == 2) {
            auto item = items[0];
            auto next = items[1];
            if (item.rhs == next.rhs && item.dot_pos == next.dot_pos) {
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
        bool to_continue = false;
        for (auto it = conflicts.begin(); it != conflicts.end(); it++) {
            auto conflict = *it;
            for (auto it2 = conflicts.begin(); it2 != conflicts.end(); it2++) {
                const auto conflict2 = *it2;
                if (it == it2)
                    continue;
                if (conflict.type == Action_type::REDUCE && conflict2.type == Action_type::REDUCE) {
                    cpuf::printf("Insoluble REDUCE/REDUCE conflict in NFA\n");
                    to_continue = true;
                }
            }
        }
        if (to_continue)
            continue;
        std::sort(conflicts.begin(), conflicts.end(), [](const Action &a, const Action &b) {
            if (a.type == Action_type::REDUCE && b.type != Action_type::REDUCE) {
                return true;  // REDUCE comes before anything else
            }
            if (a.type != Action_type::REDUCE && b.type == Action_type::REDUCE) {
                return false; // SHIFT comes after REDUCE
            }
            return false;
        });
        std::sort(items.begin(), items.end(), [](const LR1Core &first, const LR1Core &second) {
            return first.dot_pos > second.dot_pos;
        });
        nfa_states.emplace_back(); // Start state
        nfa_states[nfa_states.size() - 1].is_starting_state = true; // first item is starting state
        nfa_states[nfa_states.size() - 1].place = place;
        for (size_t i = 0; i < items.size(); ++i) {
            size_t start_state = nfa_states.size() - 1;
            const auto &item = items[i];
            if (i + 1 < items.size()) {
                const auto &next = items[i + 1];
                if (item.rhs == next.rhs && item.dot_pos == next.dot_pos) {
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
            auto current = start_state;
            nfa_states[current].reduce_action = conflicts[i]; // correct one-to-one mapping
            for (size_t j = item.dot_pos - 2; j < item.rhs.size(); ++j) {
                auto sym = item.rhs[j];
                size_t next = nfa_states.size();
                nfa_states.emplace_back();
                if (corelib::text::isUpper(sym.name)) {
                    // terminal, just push
                    nfa_states[current].transitions[sym.fullname].push_back(next);
                } else {
                    // non terminal, unroll using first set
                    auto f = first[sym.fullname];
                    for (const auto &token : f) {
                        nfa_states[current].transitions[token].push_back(next);
                    }
                }
                current = next;

            }
        }
        
        
    }
    // build dfa based on nfa
    if (nfa_states.empty()) // return if nfa is empty
        return;

    std::unordered_map<std::set<size_t>, size_t> dfa_state_map;
    std::queue<std::set<size_t>> worklist;
    std::set<size_t> start_set = {};


    start_set = epsilon_closure(start_set); // Get ε-closure of the start states
    dfa_states.push_back({start_set});
    dfa_state_map[start_set] = 0;
    worklist.push(start_set);
    // Collect all starting NFA states (accounting for ε-closure)
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
            for (const auto& [symbol, targets] : nfa_states[state].transitions) {
                if (!symbol.empty()) { // Exclude ε-transitions
                    symbol_to_nfa_targets[symbol].insert(targets.begin(), targets.end());
                }
            }
        }

        // Process each symbol and its target set (for SHIFT actions)
        for (const auto& [symbol, target_set] : symbol_to_nfa_targets) {
            std::set<size_t> closure = epsilon_closure(target_set);

            // If the target set is not already a DFA state, add it
            if (!dfa_state_map.count(closure)) {
                size_t new_dfa_index = dfa_states.size();
                dfa_states.push_back({closure});
                dfa_state_map[closure] = new_dfa_index;
                worklist.push(closure);
            }

            // Add transition for the current DFA state on this symbol
            dfa_states[current_dfa_index].transitions[symbol] = dfa_state_map[closure];

        }

        // Resolve REDUCE actions: assign if all underlying NFA states agree
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
                        // Handle conflict resolution here
                        reduce_action.reset(); // Reset if the conflict cannot be resolved
                        break;
                    }
                }
            }
            dfa_states[current_dfa_index].places.push_back(nfa_states[state].place);
        }
        // Assign the resolved reduce action to the DFA state
        dfa_states[current_dfa_index].action = reduce_action;
    }
    for (size_t i = 0; i < dfa_states.size(); i++) {
        for (auto place : dfa_states[i].places) {
            if (place != nullptr) {
                *place = {Action_type::DFA_RESOLVE, i};
            }
        }

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

        if (state.action.has_value()) {
            out << " ["
                << LRParser::ActionTypeToString(state.action.value().type) << " " << state.action.value().state
                << "]\n";
        }
        out << "\n";
    }

    out.close();
}
