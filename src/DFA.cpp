module DFA;
import cpuf.op;
import cpuf.printf;
import corelib;
import logging;
import hash;
import constants;
import std;

auto DFA::epsilonClosure(const stdu::vector<std::size_t>& states) const -> stdu::vector<std::size_t> {
    std::set<std::size_t> Closure(states.begin(), states.end());
    std::queue<std::size_t> work;
    for (std::size_t s : states) work.push(s);

    while (!work.empty()) {
        std::size_t current = work.front();
        work.pop();

        const auto &epsilons = nfa->getStates().at(current).epsilon_transitions;

        for (std::size_t target_state : epsilons) {
            if (!Closure.contains(target_state)) {
               Closure.insert(target_state);
                work.push(target_state);
            }
        }
    }

    return { Closure.begin(), Closure.end() };
}
auto DFA::move(const stdu::vector<std::size_t> &states, const NFA::TransitionKey &symbol) const -> stdu::vector<std::size_t> {
    std::set<std::size_t> result;

    for (auto state_id : states) {
        const auto &state = nfa->getStates().at(state_id);
        auto it = state.transitions.find(symbol);
        if (it != state.transitions.end()) {
            result.insert(it->second);  // assuming only one target per symbol
        }
    }

    return { result.begin(), result.end() };
}

auto DFA::findEmptyState() const -> std::size_t {
    if (mstates.empty()) {
        for (std::size_t i = 0; i < states.size(); ++i) {
            if (states[i].transitions.empty())
                return i;
        }
        return states.size();
    } else {
        for (std::size_t i = 0; i < mstates.size(); ++i) {
            if (mstates[i].transitions.empty())
                return i;
        }
        return mstates.size();
    }
}
bool DFA::leadToEmptyState(std::size_t current) const {
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
bool DFA::includesWhitespace(const MultiState &state) const {
    for (const auto &t : state.transitions) {
        if (t.first == NFA::TransitionKey {constants::whitespace})
            return true;
    }
    return false;
}
bool DFA::isTerminateState(const MultiState &state) const {
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
        if (t.first == NFA::TransitionKey {constants::whitespace})
            continue;
        if (was)
            return false;
        was = true;
    }
    return was;
}

void DFA::removeDublicateStates() {
    std::unordered_map<std::size_t, std::size_t> remove_states;  // duplicate idx -> original idx
    std::unordered_map<std::size_t, stdu::vector<std::size_t>> hash_buckets;

    uhash hasher;

    // Step 1: Identify duplicate states with custom uhash
    for (std::size_t i = 0; i < mstates.size(); ++i) {
        std::size_t h = hasher(mstates[i]);
        auto& bucket = hash_buckets[h];

        bool found_duplicate = false;
        for (std::size_t idx : bucket) {
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
    auto find_representative = [&](std::size_t idx) {
        while (remove_states.contains(idx)) {
            std::size_t parent = remove_states[idx];
            if (!remove_states.contains(parent))
                break;
            idx = parent;
        }
        return idx;
    };

    // Step 2: Build new_states and old_to_new mapping
    stdu::vector<MultiState> new_states;
    std::unordered_map<std::size_t, std::size_t> old_to_new;

    for (std::size_t i = 0; i < mstates.size(); ++i) {
        if (!remove_states.contains(i)) {
            std::size_t new_index = new_states.size();
            new_states.push_back(mstates[i]);
            old_to_new[i] = new_index;
        }
    }

    // Step 3: Map duplicates to their representative’s new index
    for (const auto& [dup, orig] : remove_states) {
        std::size_t rep = find_representative(orig);
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
    std::queue<std::size_t> work;
    std::size_t work_size = 0;
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
    std::size_t current_dfa_state = mstates.size();
    mstates.emplace_back();
    logger.log("Lookaheads size: {}", lookaheads.size());
    for (std::size_t i = 0; i < lookaheads.size(); ++i) {
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
    std::unordered_set<std::size_t> next_indices;
    for (const auto &s : mstates[current_dfa_state].transitions) {
        for (const auto &t : s.second) {
            next_indices.insert(t.next);
        }
    }
    if (!seen[symbol].insert(next_indices).second)
        return;
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
    SeenSymbol global_seen;
    for (std::size_t i = 0; i < mstates.size(); ++i) {
        auto &state = mstates[i];
        for (auto &t : state.transitions) {
            if (t.second.size() > 1) {
                std::unordered_set<std::size_t> next_indices;
                for (const auto el : t.second) {
                    next_indices.insert(el.next);
                }
                if (!global_seen[t.first].insert(next_indices).second)
                    break;
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
void DFA::accumulateTerminalStates(std::size_t i, std::unordered_set<std::size_t> &terminals, std::unordered_set<std::size_t> &visited) {
    stdu::vector<std::size_t> path;
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
        if (visited.contains(state.else_goto))
            return;
        visited.insert(state.else_goto);
        accumulateTerminalStates(state.else_goto, terminals, visited);
    }

}
void DFA::terminateEarly() {
    std::unordered_set<std::size_t> terminals;
    std::unordered_set<std::size_t> visited;
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
            if (t.first != NFA::TransitionKey {constants::whitespace}) {
                for (auto &next : t.second) {
                    next.next = empty_state;
                }
            }
        }
        if (mstates[id].else_goto != 0)
            mstates[id].else_goto = empty_state;
    }
}
void DFA::WalkDfaToGetUnreachableStates(std::size_t i, std::unordered_set<std::size_t> &reachable) {
    stdu::vector<std::size_t> path;
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
    std::unordered_set<std::size_t> reachable;
    reachable.insert(0);
    Tlog::Branch b(logger, "DFA/removeUnreachableStates");
    WalkDfaToGetUnreachableStates(0, reachable);

    // Step 1: Create mapping from old ID to new ID
    std::unordered_map<std::size_t, std::size_t> old_to_new;
    stdu::vector<SingleState> new_states;
    for (std::size_t i = 0; i < states.size(); ++i) {
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
void DFA::removeSelfLoop() {
    std::size_t empty_state = findEmptyState();
    if (empty_state == states.size()) {
        states.emplace_back(); // create it once
    }

    for (std::size_t i = 0; i < states.size(); ++i) {
        auto &state = states[i];
        if (state.transitions.empty())
            continue;
        if (std::all_of(state.transitions.begin(), state.transitions.end(), [&](auto &next) {
            return next.second.next == i;
        })) {
            state.else_goto = empty_state;
        }
    }
}
auto DFA::mergeTwoDFA(DFA &first, const DFA &second) {
    std::size_t offset = first.getMultiStates().size();
    auto &f = first.getMultiStates();
    const auto &s = second.getMultiStates();
    for (const auto &[symbol, next] : s[0].transitions) {
        for (const auto &n : next) {
            f[0].transitions[symbol].emplace_back(offset + n.next, n.accept_index);
        }
    }
    // Copy and fixup second DFA states
    for (const auto &state : s) {
        State new_state = state; // assuming State is your DFA state type
        for (auto &[symbol, nexts] : new_state.transitions) {
            for (auto &next : nexts) {
                next.next += offset;
            }
        }
        if (new_state.else_goto)
            new_state.else_goto += offset;

        f.emplace_back(std::move(new_state));
    }
}

auto DFA::mergeDFAS(stdu::vector<DFA> &dfas) -> DFA {
    auto &initial_states = dfas[0];
    for (auto it = dfas.begin() + 1; it != dfas.end(); ++it) {
        mergeTwoDFA(initial_states, *it);
    }
    return initial_states;
}

void DFA::build(bool switchToSingleState) {
    using StateSet = stdu::vector<std::size_t>;
    if (nfa->getStates().empty()) return;
    Tlog::Branch b(logger, "DFA.log");

    utype::unordered_map<StateSet, std::size_t> dfa_state_map;  // DFA state ID per NFA state set
    utype::unordered_map<std::pair<StateSet, std::variant<stdu::vector<std::string>, char>>, StateSet> closure_cache;
    std::unordered_map<std::size_t, StateSet> closure_index_cache;
    std::queue<StateSet> work;

    // 1. Start state stdu::vector<std::size_t>
    StateSet start_set = {0}; // Assuming 0 is NFA start state
    auto start_closure = epsilonClosure(start_set);

    std::size_t dfa_start_index = 0;
    dfa_state_map[start_closure] = dfa_start_index;
    mstates.emplace_back(); // for DFA state 0
    work.push(start_closure);
    while (!work.empty()) {
        StateSet current = work.front();
        std::sort(current.begin(), current.end());
        work.pop();
        logger.log("current: {}", current);
        std::size_t current_dfa_index = dfa_state_map[current];

        // Collect all symbols from the current NFA states (ignore epsilon transitions)
        utype::unordered_map<NFA::TransitionKey, stdu::vector<std::pair<TransitionValue, std::size_t>>> input_symbols;
        for (std::size_t nfa_index : current) {
            const auto &state = nfa->getStates().at(nfa_index);
            for (const auto &[symbol, id] : state.transitions) {
                input_symbols[symbol].emplace_back(TransitionValue {id, nfa->getAcceptMap().at(id)}, state.any ? state.any : NFA::NO_ANY);
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
        stdu::vector<const stdu::vector<std::pair<TransitionValue, std::size_t>>*> conflicts;
        for (const auto &[symbol, data] : input_symbols) {
            if (data.size() > 1) {
                conflicts.push_back(&data);
            }
        }
        // build epsilon closures for each conflict symbol
        struct Conflict {
            const StateSet *closure;
            const TransitionValue *value;
            std::size_t any;
        };
        stdu::vector<Conflict> conflict_closures;
        for (const auto &conf : conflicts) {
            for (const auto &next_state : *conf) {
                if (!closure_index_cache.contains(next_state.first.next)) {
                    closure_index_cache[next_state.first.next] = epsilonClosure({next_state.first.next});
                }
                conflict_closures.emplace_back(&closure_index_cache.at(next_state.first.next), &next_state.first, next_state.second);
            }
        }
        // DFA construction
        for (const auto &[symbol, data] : input_symbols) {
            std::size_t empty_state_accept = 0;
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
            logger.log("stdu::vector<std::size_t>: ({}, {})", closure_set, closure_set);
            if (closure_set.empty()) continue;

            // Separate conflicting stdu::vector<std::size_t> subsets
            stdu::vector<const Conflict*> process_conflict_list;
            for (const auto &closure : conflict_closures) {
                const StateSet &conf_set = *closure.closure;
                bool is_subset = std::all_of(conf_set.begin(), conf_set.end(), [&](std::size_t s) {
                    return std::find(closure_set.begin(), closure_set.end(), s) != closure_set.end();
                });
                if (is_subset) {
                    for (std::size_t s : conf_set) {
                        auto find_it = std::find(closure_set.begin(), closure_set.end(), s);
                        if (find_it != closure_set.end()) {
                            closure_set.erase(find_it);
                        }
                    }
                    process_conflict_list.push_back(&closure);
                }
            }

            // Add main (non-conflict) stdu::vector<std::size_t> if any
            if (!closure_set.empty()) {
                if (!dfa_state_map.count(closure_set)) {
                    std::size_t new_index = mstates.size();
                    dfa_state_map[closure_set] = new_index;
                    mstates.emplace_back();
                    work.push(closure_set);
                }
                std::size_t target_index = dfa_state_map[closure_set];
                mstates[current_dfa_index].transitions[symbol].emplace_back(
                    target_index, data.back().first.accept_index
                );
            }

            // Add split conflict transitions
            for (const auto *conf : process_conflict_list) {
                const auto &conf_closure = *conf->closure;
                const auto *transition = conf->value;

                if (!dfa_state_map.count(conf_closure)) {
                    std::size_t new_index = mstates.size();
                    dfa_state_map[conf_closure] = new_index;
                    mstates.emplace_back();
                    work.push(conf_closure);
                }

                std::size_t target_index = dfa_state_map[conf_closure];
                mstates[current_dfa_index].transitions[symbol].emplace_back(
                    target_index, transition->accept_index
                );
                if (conf->any != NFA::NO_ANY) {
                    mstates[current_dfa_index].else_goto = conf->any;
                }
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
    if (switchToSingleState) {
        unrollMultiTransitionPaths();
        this->switchToSingleState();
        removeUnreachableStates();
        removeSelfLoop();
    }
}
void DFA::buildWMerge() {
    stdu::vector<DFA> dfas;
    for (const auto &nfa : *mergable_nfas) {
        DFA d(nfa);
        d.build(false);
        dfas.push_back(d);
    }
    mstates = std::move(mergeDFAS(dfas)).getMultiStates();
    removeDublicateStates();
    terminateEarly();
    unrollMultiTransitionPaths();
    switchToSingleState();
    removeUnreachableStates();
    removeSelfLoop();
}
auto DFA::getType(bool isToken) const -> DfaType {
    DfaType dfa_type = DfaType::NONE;
    if (mstates.empty()) {
        for (const auto &state : states) {
            for (const auto &[symbol, next] : state.transitions) {
                if (std::holds_alternative<char>(symbol)) {
                    if (dfa_type == DfaType::Char || dfa_type == DfaType::NONE) {
                        dfa_type = DfaType::Char;
                    } else {
                        dfa_type = DfaType::Multi;
                        break;
                    }
                } else {
                    if (dfa_type == DfaType::Token || dfa_type == DfaType::NONE) {
                        dfa_type = isToken ? DfaType::CallableToken : DfaType::Token;
                    } else {
                        dfa_type = DfaType::Multi;
                        break;
                    }
                }
            }
        }
    } else {
        for (const auto &state : mstates) {
            for (const auto &[symbol, next] : state.transitions) {
                if (std::holds_alternative<char>(symbol)) {
                    if (dfa_type == DfaType::Char || dfa_type == DfaType::NONE) {
                        dfa_type = DfaType::Char;
                    } else {
                        dfa_type = DfaType::Multi;
                        break;
                    }
                } else {
                    if (dfa_type == DfaType::Token || dfa_type == DfaType::NONE) {
                        dfa_type = DfaType::Token;
                    } else {
                        dfa_type = DfaType::Multi;
                        break;
                    }
                }
            }
        }
    }
    return dfa_type;
}
auto DFA::getTypeStr(bool isToken) const -> std::string {
    switch (getType(isToken)) {
        case DFA::DfaType::Char:
            return "CharTable";
        case DFA::DfaType::Token:
            return "TokenTable";
        case DFA::DfaType::CallableToken:
            return "CallableTokenTable";
        case DFA::DfaType::Multi:
            return "MultiTable";
        default:
            throw Error("Undefined DFA type");;
    }
}
auto DFA::getSpanTypeStr(bool isToken) const -> std::string {
    switch (getType(isToken)) {
        case DFA::DfaType::Char:
            return "DFA::SpanCharTable";
        case DFA::DfaType::Token:
            return "DFA::SpanTokenTable";
        case DFA::DfaType::CallableToken:
            return "DFA::SpanCallableTokenTable";
        case DFA::DfaType::Multi:
            return "DFA::SpanMultiTable";
        default:
            throw Error("Unknown DFA type for span");
    }
}
auto DFA::getTransitionType(bool isToken) const -> std::string {
    switch (getType(isToken)) {
        case DFA::DfaType::Char:
            return "CharTransition";
        case DFA::DfaType::Token:
            return "TokenTransition";
        case DFA::DfaType::CallableToken:
            return "CallableTokenTransition";
        case DFA::DfaType::Multi:
            return "MultiTransition";
        default:
            throw Error("Undefined DFA type");;
    }
}
auto DFA::getTransitionType(const NFA::TransitionKey &transition_key, bool isToken) -> DfaType {
    if (std::holds_alternative<char>(transition_key)) {
        return DfaType::Char;
    } else {
        return isToken ? DfaType::Token : DfaType::CallableToken;
    }
}
auto DFA::getTransitionTypeStr(const NFA::TransitionKey &transition_key, bool isToken) -> std::string {
    switch (getTransitionType(transition_key, isToken)) {
        case DFA::DfaType::Char:
            return "CharTransition";
        case DFA::DfaType::Token:
            return "TokenTransition";
        case DFA::DfaType::CallableToken:
            return "CallableTokenTransition";
        default:
            throw Error("Not allowed DFA transition type");
    }
}
auto DFA::getStateType(bool isToken) const -> std::string {
    return getTypeStr(isToken) + "State";
}
auto DFA::getStateType(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType {
    DfaType dfa_type = DfaType::NONE;
    for (const auto &[symbol, next] : transitions) {
        if (std::holds_alternative<char>(symbol)) {
            if (dfa_type == DfaType::Char || dfa_type == DfaType::NONE) {
                dfa_type = DfaType::Char;
            } else {
                dfa_type = DfaType::Multi;
                break;
            }
        } else {
            auto &sym = std::get<stdu::vector<std::string>>(symbol);
            if ((dfa_type == DfaType::Token || dfa_type == DfaType::NONE) && dct && !dct->contains(sym)) {
                dfa_type = DfaType::Token;
            } else {
                dfa_type = DfaType::Multi;
                break;
            }
        }
    }
    return dfa_type;
}
auto DFA::getStateTypeStr(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> std::string {
    switch (getStateType(transitions, dct, isToken)) {
        case DFA::DfaType::Char:
            return "CharTableState";
        case DFA::DfaType::Token:
            return "TokenTableState";
        case DFA::DfaType::CallableToken:
            return "CallableTokenTableState";
        case DFA::DfaType::Multi:
            return "MultiTableState";
        case DfaType::NONE:
            return "EmptyTableState";
        default:
            throw Error("Undefined DFA type");;
    }
}

auto DFA::getMaxTransitionCount() const -> std::size_t {
    std::size_t count = 0;
    if (mstates.empty()) {
        for (const auto &state : states) {
            count = std::max<std::size_t>(count, state.transitions.size());
        }
    } else {
        for (const auto &state : mstates) {
            count = std::max<std::size_t>(count, state.transitions.size());
        }
    }
    return count;
}



// Print a single state
std::ostream &operator<<(std::ostream &os, const DFA::MultiState &s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            std::visit([&os](auto &key) {
                if constexpr (std::is_same_v<std::decay_t<decltype(key)>, char>)
                    os << "\t'" << corelib::text::getEscapedAsStr(key, false) << "' -> State ";
                else
                    os << "\t" << key << " -> State ";
            }, key);
            if (target.size() != 1) {
               os << "{ ";
            }
            for (const auto &t : target) {
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
                if constexpr (std::is_same_v<std::decay_t<decltype(key)>, char>)
                    os << "\t" << corelib::text::getEscapedAsStr(key, false) << " -> State ";
                else
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
        for (std::size_t i = 0; i < dfa.getStates().size(); ++i) {
            os << "State " << i << ":\n" << dfa.getStates()[i] << "\n";
        }
    } else {
        for (std::size_t i = 0; i < dfa.getMultiStates().size(); ++i) {
            os << "State " << i << ":\n" << dfa.getMultiStates()[i] << "\n";
        }
    }

    return os;
}
