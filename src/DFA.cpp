module DFA;
import cpuf.op;
import cpuf.printf;
import corelib;
import logging;
import hash;
import std;

auto DFA::epsilonClosure(const std::vector<size_t>& states) const -> std::vector<size_t> {
    std::set<size_t> closure(states.begin(), states.end());
    std::queue<size_t> work;
    for (size_t s : states) work.push(s);

    while (!work.empty()) {
        size_t current = work.front();
        work.pop();

        const auto &epsilons = nfa->getStates().at(current).epsilon_transitions;

        for (size_t target_state : epsilons) {
            if (!closure.contains(target_state)) {
                closure.insert(target_state);
                work.push(target_state);
            }
        }
    }

    return { closure.begin(), closure.end() };
}
auto DFA::move(const std::vector<size_t> &states, const NFA::TransitionKey &symbol) const -> std::vector<size_t> {
    std::set<size_t> result;

    for (auto state_id : states) {
        const auto &state = nfa->getStates().at(state_id);
        auto it = state.transitions.find(symbol);
        if (it != state.transitions.end()) {
            result.insert(it->second);  // assuming only one target per symbol
        }
    }

    return { result.begin(), result.end() };
}

auto DFA::findEmptyState() -> size_t {
    for (size_t i = 0; i < mstates.size(); ++i) {
        if (mstates[i].transitions.empty())
            return i;
    }
    return mstates.size();
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
bool DFA::includesWhitespace(const MultiState &state) {
    for (const auto &t : state.transitions) {
        if (t.first == NFA::TransitionKey {std::vector<std::string> {"__WHITESPACE"} })
            return true;
    }
    return false;
}
bool DFA::isTerminateState(const MultiState &state) {
    if (state.else_goto != 0)
        return false;
    bool was = false;
    for (const auto &t : state.transitions) {
        if (std::visit([](auto &el) {
            return typeid(el) == typeid(char);
        }, t.first))
            return false;
        if (t.second.size() > 1)
            return false;
        if (t.first == NFA::TransitionKey {std::vector<std::string> {"__WHITESPACE"}})
            continue;
        if (was)
            return false;
        was = true;
    }
    return was;
}

void DFA::removeDublicateStates() {
    std::unordered_map<size_t, size_t> remove_states;  // duplicate idx -> original idx
    std::unordered_map<size_t, std::vector<size_t>> hash_buckets;

    uhash hasher;

    // Step 1: Identify duplicate states with custom uhash
    for (size_t i = 0; i < mstates.size(); ++i) {
        size_t h = hasher(mstates[i]);
        auto& bucket = hash_buckets[h];

        bool found_duplicate = false;
        for (size_t idx : bucket) {
            if (mstates[i] == mstates[idx]) {
                remove_states[i] = idx;
                found_duplicate = true;
                break;
            }
        }
        if (!found_duplicate) {
            bucket.push_back(i);
        }
    }

    // Union-find style representative finder with path compression
    auto find_representative = [&](size_t idx) {
        while (remove_states.contains(idx)) {
            size_t parent = remove_states[idx];
            if (!remove_states.contains(parent))
                break;
            idx = parent;
        }
        return idx;
    };

    // Step 2: Build new_states and old_to_new mapping
    stdu::vector<MultiState> new_states;
    std::unordered_map<size_t, size_t> old_to_new;

    for (size_t i = 0; i < mstates.size(); ++i) {
        if (!remove_states.contains(i)) {
            size_t new_index = new_states.size();
            new_states.push_back(mstates[i]);
            old_to_new[i] = new_index;
        }
    }

    // Step 3: Map duplicates to their representative’s new index
    for (const auto& [dup, orig] : remove_states) {
        size_t rep = find_representative(orig);
        old_to_new[dup] = old_to_new.at(rep);
    }

    // Step 4: Update transitions
    for (auto& s : new_states) {
        for (auto& [sym, vec] : s.transitions) {
            for (auto& t : vec) {
                t.next = old_to_new.at(t.next);
            }
        }
    }

    // Step 5: Finalize
    mstates = std::move(new_states);
}
void DFA::unrollMultiTransition(const NFA::TransitionKey &symbol, stdu::vector<TransitionValue> &val, SeenSymbol &seen, WalkedState &walked_state) {
    // step 1: get lookaheads for every transition's goto
    using LookaheadSet = stdu::vector<MultiTransitions>;
    using Lookaheads = stdu::vector<LookaheadSet>;
    Lookaheads lookaheads;
    std::queue<size_t> work;
    size_t work_size = 0;
    for (const auto &v: val) {
        work.push(v.next);
        work_size++;
    };
    Tlog::Branch b(logger, "DFA/unrollMultiTransition");
    while (!work.empty()) {
        // substep 1: for every symbol in val push new lookahead set
        if (work.size() == work_size) {
            lookaheads.emplace_back();
            // should reach 0 when all is computed. Indicates that work has only initial conflict symbols and so lookahead should be pushed
            work_size--;
        }
        auto current = work.front();
        work.pop();
        // substep 2: push lookaheads to latest lookahead set
        lookaheads.back().emplace_back();
        for (const auto &t : mstates[current].transitions) {
            for (const auto &next : t.second) {
                if (!walked_state.contains(next.next)) {
                    // not loop, push
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
    size_t current_dfa_state = mstates.size();
    mstates.emplace_back();
    logger.log("Lookaheads size: {}", lookaheads.size());
    for (size_t i = 0; i < lookaheads.size(); ++i) {
        const auto &l = lookaheads[i];
        logger.log("l[0].size(): {}", l[0].size());
        if (l[0].empty()) {
            mstates[current_dfa_state].else_goto = findEmptyState();
            mstates[current_dfa_state].else_goto_accept = val[i].accept_index;
            continue;
        }
        for (const auto &[sym, go]: l[0]) {
            mstates[current_dfa_state].transitions[sym].push_back(go.back());
            // should be only one state even though it is an array right now
        }
    }
    // find more dublicate states and unroll
    std::unordered_set<size_t> next_indices;
    for (const auto &s : mstates[current_dfa_state].transitions) {
        for (const auto &t : s.second) {
            next_indices.insert(t.next);
        }
    }
    if (seen[symbol].contains(next_indices))
        return;
    seen[symbol].insert(next_indices);
    for (auto &[sym, go]: mstates[current_dfa_state].transitions) {
        if (go.size() > 1) {
            unrollMultiTransition(sym, go, seen, walked_state);
        }
    }
    val = {{current_dfa_state}};
}

void DFA::unrollMultiTransitionPaths() {
    SeenSymbol seen;
    WalkedState walked_state;
    for (size_t i = 0; i < mstates.size(); ++i) {
        auto &state = mstates[i];
        for (auto &t : state.transitions) {
            if (t.second.size() > 1) {
                unrollMultiTransition(t.first, t.second, seen, walked_state);
                seen.clear();
                walked_state.clear();
            }
        }
    }
}
void DFA::switchToSingleState() {
    for (auto &state : mstates) {
        states.emplace_back();
        states.back().else_goto = state.else_goto;
        states.back().else_goto_accept = state.else_goto_accept;
        for (auto &t : state.transitions) {
            states.back().transitions[t.first] = std::move(t.second.back());
            t.second.pop_back();
        }
    }
    mstates.clear();
}
void DFA::accumulateTerminalStates(size_t i, std::unordered_set<size_t> &terminals, std::unordered_set<size_t> &visited) {
    std::vector<size_t> path;
    const auto &state = mstates.at(i);
    if (isTerminateState(state)) {
        // first value transition
        terminals.insert(i);
        return;
    }
    visited.insert(i);
    for (const auto &t : state.transitions) {
        for (const auto &next : t.second) {
            const auto &id = next.next;
            if (visited.contains(id))
                continue;
            visited.insert(id);
            accumulateTerminalStates(id, terminals, visited);
        }
    }
    if (state.else_goto != 0 && visited.contains(state.else_goto)) {
        accumulateTerminalStates(state.else_goto, terminals, visited);
    }

}
void DFA::terminateEarly() {
    std::unordered_set<size_t> terminals;
    std::unordered_set<size_t> visited;
    accumulateTerminalStates(0, terminals, visited);
    if (terminals.empty())
        return;
    // terminate states
    auto empty_state = findEmptyState();
    if (empty_state == mstates.size()) {
        mstates.emplace_back();
    }
    for (const auto &id : terminals) {
        for (auto &t : mstates[id].transitions) {
            if (t.first != NFA::TransitionKey {std::vector<std::string>{"__WHITESPACE"}}) {
                for (auto &next : t.second) {
                    next.next = empty_state;
                }
            }
        }
        if (mstates[id].else_goto != 0)
            mstates[id].else_goto = empty_state;
    }
}
void DFA::WalkDfaToGetUnreachableStates(size_t i, std::unordered_set<size_t> &reachable) {
    std::vector<size_t> path;
    const auto &state = states.at(i);
    for (const auto &t : state.transitions) {
        const auto &id = t.second.next;
        if (reachable.contains(id))
            continue;
        reachable.insert(id);

        WalkDfaToGetUnreachableStates(id, reachable);
    }
    if (state.else_goto != 0 && !reachable.contains(state.else_goto)) {
        reachable.insert(state.else_goto);
        WalkDfaToGetUnreachableStates(state.else_goto, reachable);
    }
}
void DFA::removeUnreachableStates() {
    std::unordered_set<size_t> reachable;
    reachable.insert(0);
    Tlog::Branch b(logger, "DFA/removeUnreachableStates");
    WalkDfaToGetUnreachableStates(0, reachable);

    // Step 1: Create mapping from old ID to new ID
    std::unordered_map<size_t, size_t> old_to_new;
    stdu::vector<SingleState> new_states;
    for (size_t i = 0; i < states.size(); ++i) {
        if (reachable.contains(i)) {
            old_to_new[i] = new_states.size();
            new_states.push_back(states[i]);
        }
    }
    logger.log("reachable: {}", reachable);
    logger.log("old_to_new: {}", old_to_new);
    // Step 2: Fix transitions
    for (auto& state : new_states) {
        for (auto& [symbol, trans] : state.transitions) {
            trans.next = old_to_new.at(trans.next);
        }
        state.else_goto = old_to_new.at(state.else_goto);
    }
    states = std::move(new_states);
}

void DFA::build() {
    using StateSet = std::vector<size_t>;
    if (nfa->getStates().empty()) return;
    Tlog::Branch b(logger, "DFA.log");

    utype::unordered_map<StateSet, size_t> dfa_state_map;  // DFA state ID per NFA state set
    utype::unordered_map<std::pair<StateSet, std::variant<stdu::vector<std::string>, char>>, StateSet> closure_cache;
    std::unordered_map<size_t, StateSet> closure_index_cache;
    std::queue<StateSet> work;

    // 1. Start state closure
    StateSet start_set = {0}; // Assuming 0 is NFA start state
    StateSet start_closure = epsilonClosure(start_set);

    size_t dfa_start_index = 0;
    dfa_state_map[start_closure] = dfa_start_index;
    mstates.emplace_back(); // for DFA state 0
    work.push(start_closure);
    while (!work.empty()) {
        StateSet current = work.front();
        std::sort(current.begin(), current.end());
        work.pop();
        logger.log("current: {}", current);
        size_t current_dfa_index = dfa_state_map[current];

        // Collect all symbols from the current NFA states (ignore epsilon transitions)
        utype::unordered_map<NFA::TransitionKey, stdu::vector<TransitionValue>> input_symbols;
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
        stdu::vector<const stdu::vector<TransitionValue>*> conflicts;
        for (const auto &[symbol, data] : input_symbols) {
            if (data.size() > 1) {
                conflicts.push_back(&data);
            }
        }
        // build epsilon closures for each conflict symbol
        using Conflict = std::pair<StateSet, const TransitionValue*>;
        std::vector<Conflict> conflict_closures;
        for (const auto &conf : conflicts) {
            for (const auto &next_state : *conf) {
                if (!closure_index_cache.contains(next_state.next)) {
                    closure_index_cache[next_state.next] = epsilonClosure({next_state.next});
                }
                conflict_closures.emplace_back(closure_index_cache.at(next_state.next), &next_state);
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
            StateSet closure_set;

            if (closure_cache.contains(std::make_pair(current, symbol))) {
                closure_set = closure_cache.at(std::make_pair(current, symbol));
            } else {
                StateSet move_set = move(current, symbol);
                closure_set = epsilonClosure(move_set);
                closure_cache.emplace(std::make_pair(current, symbol), closure_set);
            }
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
                        auto find_it = std::find(closure_set.begin(), closure_set.end(), s);
                        if (find_it != closure_set.end()) {
                            closure_set.erase(find_it);
                        }
                    }
                    process_conflict_list.push_back(&closure);
                }
            }

            // Add main (non-conflict) closure if any
            if (!closure_set.empty()) {
                if (!dfa_state_map.count(closure_set)) {
                    size_t new_index = mstates.size();
                    dfa_state_map[closure_set] = new_index;
                    mstates.emplace_back();
                    work.push(closure_set);
                }
                size_t target_index = dfa_state_map[closure_set];
                mstates[current_dfa_index].transitions[symbol].emplace_back(
                    target_index, data.back().accept_index
                );
            }

            // Add split conflict transitions
            for (const auto *conf : process_conflict_list) {
                const auto &conf_closure = conf->first;
                const auto *transition = conf->second;

                if (!dfa_state_map.count(conf_closure)) {
                    size_t new_index = mstates.size();
                    dfa_state_map[conf_closure] = new_index;
                    mstates.emplace_back();
                    work.push(conf_closure);
                }

                size_t target_index = dfa_state_map[conf_closure];
                mstates[current_dfa_index].transitions[symbol].emplace_back(
                    target_index, transition->accept_index
                );
            }
            if (goto_empty_state) {
                auto empty_state = findEmptyState();
                if (empty_state == mstates.size()) {
                    mstates.emplace_back();
                    work.push({empty_state});
                }
                mstates[current_dfa_index].else_goto = empty_state;
                mstates[current_dfa_index].else_goto_accept = empty_state_accept;
            }
        }

    }
    // various optimizations
    removeDublicateStates();
    terminateEarly();
    unrollMultiTransitionPaths();
    switchToSingleState();
    removeUnreachableStates();
}

// Print a single state
std::ostream &operator<<(std::ostream &os, const DFA::MultiState &s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            std::visit([&os](auto &key) {
                os << "\t" << key << " -> State ";
            }, key);
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
std::ostream &operator<<(std::ostream &os, const DFA::SingleState &s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            std::visit([&os](auto &key) {
                os << "\t" << key << " -> State ";
            }, key);
            os << target.next << (target.accept_index != NFA::NO_ACCEPT ? std::string(" { accept -> ") + std::to_string(target.accept_index) + " } " : std::string(""));
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
    if (dfa.getMultiStates().empty()) {
        for (size_t i = 0; i < dfa.getStates().size(); ++i) {
            os << "State " << i << ":\n" << dfa.getStates()[i] << "\n";
        }
    } else {
        for (size_t i = 0; i < dfa.getMultiStates().size(); ++i) {
            os << "State " << i << ":\n" << dfa.getMultiStates()[i] << "\n";
        }
    }

    return os;
}
