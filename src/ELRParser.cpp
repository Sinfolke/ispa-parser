#include <ELRParser.h>

void ELRParser::build() {
    LRParser::buildTable(false); // Build the initial LR table without automatic conflict resolution
    // build nfa
    for (const auto &[items, place, conflicts] : conflicts) {
        if (items.size() == 2) {
            auto item = items[0];
            auto next = items[1];
            if (item.rhs == next.rhs) {
                // resolve conflict by picking shift over reduce. If reduce/reduce conflict report it
                if (conflicts[0].type == Action_type::REDUCE && conflicts[1].type == Action_type::REDUCE) {
                    cpuf::printf("Insoluble Reduce/Reduce conflict in NFA for rule %$\n", corelib::text::join(item.lhs.fullname, "_"));
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
                }
            }
            size_t current = start_state;
            for (size_t j = 0; j < item.rhs.size(); ++j) {
                auto sym = item.rhs[j].fullname;
                size_t next = nfa_states.size();
                nfa_states.emplace_back();
                nfa_states[current].transitions[sym].push_back(next);
                current = next;
            }
            nfa_states[current].reduce_action = conflicts[i]; // correct one-to-one mapping
        }
        
        
    }
    // build dfa based on nfa
    std::map<std::set<size_t>, size_t> dfa_state_ids; // map NFA state set → DFA id

    std::queue<std::set<size_t>> worklist;

    // Start with initial NFA state {0}
    worklist.push({0});
    dfa_state_ids[{0}] = 0;
    dfa_states.push_back(DFA_state{{0}, {}, std::nullopt});

    while (!worklist.empty()) {
        auto current_set = worklist.front();
        worklist.pop();
        size_t current_id = dfa_state_ids[current_set];
        auto &current_dfa = dfa_states[current_id];
    
        // Gather all transitions from the NFA states in current_set
        std::unordered_map<std::vector<std::string>, std::set<size_t>> symbol_to_target_set;
    
        for (auto state_id : current_set) {
            const auto &nfa = nfa_states[state_id];
            for (const auto &[sym, targets] : nfa.transitions) {
                for (auto t : targets) {
                    symbol_to_target_set[sym].insert(t);
                }
            }
            if (nfa.reduce_action && !current_dfa.reduce_action)
                current_dfa.reduce_action = nfa.reduce_action;
        }
    
        // Create DFA transitions
        for (const auto &[sym, target_set] : symbol_to_target_set) {
            if (dfa_state_ids.find(target_set) == dfa_state_ids.end()) {
                size_t new_id = dfa_states.size();
                dfa_state_ids[target_set] = new_id;
                dfa_states.push_back(DFA_state{target_set, {}, std::nullopt});
                worklist.push(target_set);
            }
            current_dfa.transitions[sym] = dfa_state_ids[target_set];
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

        if (state.reduce_action.has_value()) {
            out << " ["
                << LRParser::ActionTypeToString(state.reduce_action.value().type) << " " << state.reduce_action.value().state
                << "]\n";
        }
        out << "\n";
    }

    out.close();
}
