module ELRParser;
import std;
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
            if (!closure.count(it->second)) {
                closure.insert(it->second);
                work.push(it->second);
            }
        }
    }
    return closure;
}
ELRParser::Lookahead_set ELRParser::getLookeaheadSet(const std::vector<std::string> &fullname, std::unordered_set<std::vector<std::string>> &visited) {
    if (visited.count(fullname))
        return {};
    visited.insert(fullname);
    Lookahead_set lookahead_set;
    for (const auto &place : use_places[fullname]) {
        const auto &options = initial_item_set[place];
        for (const auto &option : options) {
            // get next symbol
            for (auto it = option.members.begin(); it != option.members.end(); it++) {
                const auto &rule = *it;
                const auto &name = rule.getName();
                if (name.name == fullname) {
                    // found this rule, get all next possible symbols
                    lookahead_set.emplace_back();
                    for (auto it2 = it + 1; it2 != option.members.end(); it2++) {
                        const auto &next_rule = *it2;
                        const auto &next_rule_name = next_rule.getName();
                        if (corelib::text::isUpper(next_rule_name.name.back())) {
                            lookahead_set.back().token_sequence.push_back(next_rule_name.name);
                        } else {
                            lookahead_set.back().nested.push_back(getLookeaheadSet(next_rule_name.name, visited));
                            lookahead_set.back().token_sequence.push_back(lookahead_set.back().nested.size() - 1);
                        }
                    }
                }
            }
        }
    }
    return lookahead_set;
}
void ELRParser::processLookaheadSet(const Lookahead_set &lookahead_set, size_t nfa_initial_index, const Action& action) {
    for (const auto &option : lookahead_set) {
        size_t current = nfa_initial_index;
        for (const auto &token : option.token_sequence) {
            if (std::holds_alternative<std::vector<std::string>>(token)) {
                // token, add
                auto name = std::get<std::vector<std::string>>(token);
                auto &current_nfa_state = nfa_states[current];
                if (current_nfa_state.transitions.count(name)) {
                    // already exists; jump to it's index to add one more alternative
                    current = current_nfa_state.transitions[name];
                } else {
                    current = nfa_states.size();
                    current_nfa_state.transitions[name] = current;
                    nfa_states.emplace_back();
                }
            } else if (std::holds_alternative<size_t>(token)) {
                auto nested_id = std::get<size_t>(token);
                processLookaheadSet(option.nested[nested_id], current, action);
            }
        }
        nfa_states[current].reduce_action = action;
    }
}
void ELRParser::build() {
    transform();
    prepare();
    buildTable();
    // build nfa
    for (auto &conflict : conflicts) {
        auto &[items, place, conflicts, state] = conflict;
        if (items.size() != conflicts.size())
            throw Error("Items size differce with conflicts size");
        size_t nfa_state = nfa_states.size();
        bool no_process_next = false;
        nfa_states.emplace_back(); // Start state
        nfa_states[nfa_state].is_starting_state = true; // first item is starting state
        nfa_states[nfa_state].place = place;
        for (size_t i = 0; i < items.size(); i++) {
            const auto &item = items[i];
            const auto &conflict = conflicts[i];
            // register reduce action on place and shift action later on shift/reduce conflict
            if (items.size() == 2) {
                if (conflicts[0].type == Action_type::SHIFT && conflicts[1].type == Action_type::REDUCE) {
                    nfa_states[nfa_state].reduce_action = conflicts[1];
                    no_process_next = true;
                } else if (conflicts[0].type == Action_type::REDUCE && conflicts[1].type == Action_type::SHIFT) {
                    std::swap(conflicts[0], conflicts[1]);
                    std::swap(items[0], items[1]);
                    i--;
                    continue;
                }
            }
            auto current = nfa_state;
            if (conflict.type == Action_type::SHIFT) {
                // handle shift action as defaultly in NFA
                for (size_t j = item.dot_pos; j < item.rhs.members.size(); ++j) {
                    auto sym = item.rhs.members[j];
                    size_t next = nfa_states.size();
                    nfa_states.emplace_back();
                    const auto &name = sym.getName();
                    if (corelib::text::isUpper(name.name.back())) {
                        // terminal, just push
                        nfa_states[current].transitions[name.name] = next;
                    } else {
                        // non terminal, unroll using first set
                        auto f = first[name.name];
                        for (const auto &token : f) {
                            if (token == std::vector<std::string>{"ε"}) {
                                nfa_states[current].epsilon_transition = next;
                                continue;
                            }
                            nfa_states[current].transitions[token] = next;
                        }
                    }
                    current = next;
                }
                nfa_states[current].reduce_action = conflicts[i];
            } else {
                // reduce
                // perform automatic conflict resolution based on following cotext of this rule
                // 1. Get all possible next lookahead entries for this rule
                cpuf::printf("REDUCE/REDUCE resolution for %$ on %$\n", state, nfa_state);
                std::unordered_set<std::vector<std::string>> visited;
                Lookahead_set lookahead_set = getLookeaheadSet(item.lhs, visited);
                processLookaheadSet(lookahead_set, nfa_state, conflict);

            }
            if (no_process_next)
                break;
        }
    }
    // build dfa based on nfa
    if (nfa_states.empty()) // return if nfa is empty
        return;

    std::unordered_map<std::set<size_t>, size_t> dfa_state_map;
    std::queue<std::set<size_t>> worklist;

    for (size_t i = 0; i < nfa_states.size(); ++i) {
        if (nfa_states[i].is_starting_state) {
            std::set<size_t> start = epsilon_closure({i});
            if (!dfa_state_map.count(start)) {
                size_t index = dfa_states.size();
                dfa_states.push_back({start});
                dfa_state_map[start] = index;
                worklist.push(start);
            }
        }
    }
    while (!worklist.empty()) {
        std::set<size_t> current_set = worklist.front();
        worklist.pop();
        size_t current_dfa_index = dfa_state_map[current_set];

        std::unordered_map<std::vector<std::string>, std::set<size_t>> symbol_to_nfa_targets;

        // Populate symbol_to_nfa_targets for all transitions in the current NFA set
        for (size_t state : current_set) {
            for (const auto& [symbol, target] : nfa_states[state].transitions) {
                if (!symbol.empty()) { // Exclude ε-transitions
                    symbol_to_nfa_targets[symbol].insert(target);
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
            // also for each state move nfa.place to dfa
            dfa_states[current_dfa_index].places.push_back(nfa_states[state].place);
            if (dfa_states[current_dfa_index].epsilon_transition != 0 && nfa_states[state].epsilon_transition != 0) {
                throw Error("Epsilon is already taken");
            }
            dfa_states[current_dfa_index].epsilon_transition = nfa_states[state].epsilon_transition;
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
        for (const auto &[sym, target] : nfa_states[i].transitions) {
            out << "\t--" << sym << "--> " << target << "\n";
        }
        if (nfa_states[i].epsilon_transition != 0) {
            out << "\tepsilon -> " << nfa_states[i].epsilon_transition << "\n";
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
        if (state.epsilon_transition != 0) {
            out << "epsilon -> " << state.epsilon_transition << '\n';
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
