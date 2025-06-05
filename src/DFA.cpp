module DFA;
import cpuf.op;
import cpuf.printf;
import corelib;
import logging;
import std;

auto DFA::epsilonClosure(const stdu::vector<size_t>& states) const -> stdu::vector<size_t> {
    stdu::vector<size_t> closure = states;
    std::queue<size_t> work;
    for (size_t s : states) work.push(s);

    while (!work.empty()) {
        size_t current = work.front();
        work.pop();

        const auto &epsilons = nfa->getStates().at(current).epsilon_transitions;

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
        const auto &state = nfa->getStates().at(state_id);
        auto it = state.transitions.find(symbol);
        if (it != state.transitions.end()) {
            result.push_back(it->second);  // assuming only one target per symbol
        }
    }

    return result;
}


void DFA::removeDublicateStates() {
    std::unordered_map<size_t, size_t> remove_states;

    // Step 1: Identify duplicate states
    for (size_t i = 0; i < states.size(); ++i) {
        for (size_t j = i + 1; j < states.size(); ++j) {
            if (states[i] == states[j]) {
                remove_states[j] = i;
            }
        }
    }

    // Step 2: Build new_states and mapping from old to new index
    stdu::vector<state> new_states;
    std::unordered_map<size_t, size_t> old_to_new;

    for (size_t i = 0; i < states.size(); ++i) {
        if (!remove_states.contains(i)) {
            size_t new_index = new_states.size();
            new_states.push_back(states[i]);
            old_to_new[i] = new_index;
        } else {
            old_to_new[i] = remove_states.at(i);
        }
    }

    // Step 3: Map removed duplicates to their original state’s new index
    for (const auto& [dup, orig] : remove_states) {
        auto o = orig;
        while (remove_states.contains(o)) {
            o = remove_states.at(o);
        }
        old_to_new[dup] = old_to_new.at(o);
    }

    // Step 4: Update all transitions to use new indices
    for (auto& s : new_states) {
        for (auto& [sym, vec] : s.transitions) {
            for (auto& t : vec) {
                t.next = old_to_new.at(t.next);
            }
        }
    }

    // Step 5: Finalize
    states = std::move(new_states);
}
// void DFA::walkDfaToTerminate(size_t i) {
//     std::unordered_set<size_t> visited;
//     std::vector<size_t> path;
//     Tlog::Branch b(logger, "DFA/walkDfaToTerminate.log");
//
//
// }
//
// void DFA::terminateEarly() {
//     walkDfaToTerminate(0);
// }
auto DFA::findEmptyState() -> size_t {
    for (size_t i = 0; i < states.size(); ++i) {
        if (states[i].transitions.empty())
            return i;
    }
    return states.size();
}
bool DFA::leadToEmptyState(size_t current) {
    if (!nfa->getStates().at(current).transitions.empty())
        return false;
    bool all_lead_o_empty = true;
    for (const auto &t : nfa->getStates().at(current).epsilon_transitions) {
        if (!leadToEmptyState(t)) {
            return false;
        }
    }
    return true;
}

void DFA::unrollMultiTransition(const stdu::vector<std::string> &symbol, stdu::vector<transition_value> &val, SeenSymbol &seen, WalkedState &walked_state) {
    // step 1: get lookaheads for every transition's goto
    using LookaheadSet = stdu::vector<Transitions>;
    using Lookaheads = stdu::vector<LookaheadSet>;
    Lookaheads lookaheads;
    std::queue<size_t> work;
    size_t work_size = 0;
    for (const auto &v: val) {
        work.push(v.next);
        walked_state.insert(v.next);
        work_size++;
    };
    while (!work.empty()) {
        // substep 1: for every symbol in val push new lookahead set
        if (work.size() == work_size) {
            lookaheads.emplace_back();
            // should reach 0 when all is computed. Indicates that work has only initial conflict symbols and so lookahead should be pushed
            work_size--;
        }
        auto current = work.front();
        work.pop();
        if (lookaheads.back().size() >= 1)
            continue; // 1 lookahead enough
        // substep 2: push lookaheads to latest lookahead set
        lookaheads.back().emplace_back();
        for (const auto &t : states[current].transitions) {
            for (const auto &next : t.second) {
                if (!walked_state.contains(next.next)) {
                    // not loop, push
                    cpuf::dprintf("{}", next.next);
                    lookaheads.back().back()[t.first].push_back(next);
                    walked_state.insert(next.next);
                }
            }
        }
        //lookaheads.back().push_back(states[current].transitions);
        // further accumulation is not yet needed


        // substep 3: push to work every transition & transform if it has several goto states

        // for (const auto &t : states[current].transitions) {
        //     if (t.second.size() > 1) {
        //         // unroll if has several goto states
        //         unrollMultiTransition(t.first, t.second);
        //     }
        //     work.push(t.second.back().next);
        // }
    }
    // step 2: based on lookaheads compute new states
    size_t current_dfa_state = states.size();
    states.emplace_back();
    for (size_t i = 0; i < lookaheads.size(); ++i) {
        const auto &l = lookaheads[i];
        if (l[0].empty()) {
            states[current_dfa_state].else_goto = findEmptyState();
            states[current_dfa_state].else_goto_accept = val[i].accept_index;
            continue;
        }
        for (const auto &[sym, go]: l[0]) {
            states[current_dfa_state].transitions[sym].push_back(go.back());
            // should be only one state even thoguh it is an array
        }
    }

    // find more dublicate states and unroll
    std::unordered_set<size_t> next_indices;
    for (const auto &s : states[current_dfa_state].transitions) {
        for (const auto &t : s.second) {
            next_indices.insert(t.next);
        }
    }
    if (seen[symbol].contains(next_indices))
        return;
    seen[symbol].insert(next_indices);
    for (auto &[sym, go]: states[current_dfa_state].transitions) {
        if (go.size() > 1) {
            unrollMultiTransition(sym, go, seen, walked_state);
        }
    }
    val = {{current_dfa_state}};
}

void DFA::unrollMultiTransitionPaths() {
    SeenSymbol seen;
    WalkedState walked_state;
    for (size_t i = 0; i < states.size(); ++i) {
        auto &state = states[i];
        for (auto &t : state.transitions) {
            if (i >= 1000) {
                break;
            }
            if (t.second.size() > 1) {
                unrollMultiTransition(t.first, t.second, seen, walked_state);
                seen.clear();
                walked_state.clear();
            }
        }
    }
}
void DFA::build() {
    using StateSet = stdu::vector<size_t>;
    if (nfa->getStates().empty()) return;
    Tlog::Branch b(logger, "DFA.log");

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
        logger.log("current: {}", current);
        size_t current_dfa_index = dfa_state_map[current];

        // Collect all symbols from the current NFA states (ignore epsilon transitions)
        utype::unordered_map<stdu::vector<std::string>, stdu::vector<transition_value>> input_symbols;
        for (size_t nfa_index : current) {
            const auto &state = nfa->getStates().at(nfa_index);
            for (const auto &[symbol, id] : state.transitions) {
                logger.log("Registering input symbol {}: id: {}, accept_index: {}", symbol, id, nfa->getAcceptMap().at(id));
                input_symbols[symbol].emplace_back(id, nfa->getAcceptMap().at(id));
            }
        }
        // Early cutoff opportunity
        // if (input_symbols.size() == 1 || input_symbols.size() == 2 && input_symbols.contains({"__WHITESPACE"})) {
        //     const auto &[symbol, data] = *input_symbols.begin();
        //     StateSet move_set = move(current, symbol);
        //     StateSet closure_set = epsilonClosure(move_set);
        //
        //     // Check if closure_set contains only accepting NFA states
        //     bool all_non_accepting = true;
        //     for (auto c : closure_set) {
        //         if (nfa->getStates().at(c).accept_index != NFA::NO_ACCEPT) {
        //             all_non_accepting = false;
        //             break;
        //         }
        //     }
        //
        //     if (all_non_accepting) {
        //         // Mark this transition as final, no need to explore further
        //         continue; // Don't push to work queue
        //     }
        // }
        // determine conflict symbols
        stdu::vector<const stdu::vector<transition_value>*> conflicts;
        for (const auto &[symbol, data] : input_symbols) {
            if (data.size() > 1) {
                conflicts.push_back(&data);
            }
        }
        // build epsilon closures for each conflict symbol
        using Conflict = std::pair<StateSet, const transition_value*>;
        std::vector<Conflict> conflict_closures;
        for (const auto &conf : conflicts) {
            for (const auto &next_state : *conf) {
                conflict_closures.emplace_back(epsilonClosure({next_state.next}), &next_state);
            }
        }
        // DFA construction
        for (const auto &[symbol, data] : input_symbols) {
            size_t empty_state_accept = 0;
            bool goto_empty_state = std::any_of(current.begin(), current.end(), [&](auto &el) {
                if (leadToEmptyState(el)) {
                    empty_state_accept = nfa->getAcceptMap().at(el);
                    return true;
                }
                return false;
            });

            StateSet move_set = move(current, symbol);
            StateSet closure_set = epsilonClosure(move_set);
            logger.log("move_set: {}", move_set);
            logger.log("closure: {}", closure_set);
            if (closure_set.empty()) continue;

            // Separate conflicting closure subsets
            std::vector<const Conflict*> process_conflict_list;
            for (const auto &closure : conflict_closures) {
                const StateSet &conf_set = closure.first;
                bool is_subset = std::all_of(conf_set.begin(), conf_set.end(), [&](size_t s) {
                    return std::find(closure_set.begin(), closure_set.end(), s) != closure_set.end();
                });
                if (is_subset) {
                    for (size_t s : conf_set) {
                        auto it = std::find(closure_set.begin(), closure_set.end(), s);
                        if (it != closure_set.end())
                            closure_set.erase(it);
                    }
                    process_conflict_list.push_back(&closure);
                }
            }

            // Add main (non-conflict) closure if any
            if (!closure_set.empty()) {
                if (!dfa_state_map.count(closure_set)) {
                    size_t new_index = states.size();
                    dfa_state_map[closure_set] = new_index;
                    states.emplace_back();
                    work.push(closure_set);
                }
                size_t target_index = dfa_state_map[closure_set];
                states[current_dfa_index].transitions[symbol].emplace_back(
                    target_index, data.back().accept_index
                );
            }

            // Add split conflict transitions
            for (const auto *conf : process_conflict_list) {
                const auto &conf_closure = conf->first;
                const auto *transition = conf->second;

                if (!dfa_state_map.count(conf_closure)) {
                    size_t new_index = states.size();
                    dfa_state_map[conf_closure] = new_index;
                    states.emplace_back();
                    work.push(conf_closure);
                }

                size_t target_index = dfa_state_map[conf_closure];
                states[current_dfa_index].transitions[symbol].emplace_back(
                    target_index, transition->accept_index
                );
            }
            if (goto_empty_state) {
                auto empty_state = findEmptyState();
                if (empty_state == states.size()) {
                    states.emplace_back();
                    work.push({empty_state});
                }
                states[current_dfa_index].else_goto = empty_state;
                states[current_dfa_index].else_goto_accept = empty_state_accept;
            }
        }

    }

    // various optimizations
    //terminateEarly();
    removeDublicateStates();
    unrollMultiTransitionPaths();
}

// Print a single state
std::ostream &operator<<(std::ostream &os, const DFA::state &s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            os << "\t" << key << " -> State ";
            if (target.size() != 1) {
               os << "{ ";
            }
            for (const auto t : target) {
                os << t.next << (t.accept_index != NFA::NO_ACCEPT ? std::string(" { accept -> ") + std::to_string(t.accept_index) + " } " : std::string(""));
                if (target.size() != 1)
                    os << ", ";
            }
            if (target.size() != 1)
                os << " }";
            os << "\n";
        }
    }
    if (s.else_goto != 0) {
        os << "\t[else goto] -> " << s.else_goto;
        if (s.else_goto_accept != NFA::NO_ACCEPT) {
            os << " { accept -> " << s.else_goto_accept << " }";
        }
        os << '\n';
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
