module DFA.MinDFA;

import DFA.API;
import NFA;
import cpuf.printf;
import constants;
import hash;
import logging;
import dstd;
import std;

void DFA::MinDFA::removeDublicateStates(SDFA &sdfa) {
    std::unordered_map<std::size_t, std::size_t> remove_states;  // duplicate idx -> original idx
    std::unordered_map<std::size_t, stdu::vector<std::size_t>> hash_buckets;

    uhash hasher;

    // Step 1: Identify duplicate states with custom uhash
    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        std::size_t h = hasher(sdfa.get()[i]);
        auto& bucket = hash_buckets[h];

        bool found_duplicate = false;
        for (std::size_t idx : bucket) {
            if (sdfa.get()[i] == sdfa.get()[idx]) {
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
    States<SingleState> new_states(nullptr);
    std::unordered_map<std::size_t, std::size_t> old_to_new;

    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        if (!remove_states.contains(i)) {
            std::size_t new_index = new_states.makeNew();
            new_states[new_index] = sdfa.get()[i];
            old_to_new[i] = new_index;
        }
    }

    // Step 3: Map duplicates to their representative’s new index
    for (const auto& [dup, orig] : remove_states) {
        old_to_new[dup] = old_to_new.at(find_representative(orig));
    }

    // Step 4: Update transitions
    for (auto& s : new_states) {
        for (auto& [sym, t] : s.transitions) {
            t.next = old_to_new.at(t.next);
        }
        if (s.else_goto) {
            s.else_goto = old_to_new.at(s.else_goto);
        }
    }
    for (auto &el : sdfa.getEmptyStateMap()) {
        el.second = old_to_new.at(el.second);
    }
    for (auto &el : sdfa.getIndexToEmptyStateMap()) {
        el.second = old_to_new.at(el.second);
    }
    if (!sdfa.isMerged()) {
        sdfa.getEmptyState() = old_to_new.at(sdfa.getEmptyState());
    }
    // Step 5: Finalize
    sdfa.get() = std::move(new_states);
}
void DFA::MinDFA::accumulateTerminalStates(SDFA &sdfa, std::size_t i, std::unordered_set<std::size_t> &terminals, std::unordered_set<std::size_t> &visited) {
    stdu::vector<std::size_t> path;
    const auto &state = sdfa.get()[i];
    if (sdfa.get().isTerminateState(state)) {
        // first value transition
        terminals.insert(i);
        return;
    }
    visited.insert(i);
    for (const auto &[symbol, t] : state.transitions) {
        const auto &id = t.next;
        if (visited.contains(id))
            continue;
        visited.insert(id);
        accumulateTerminalStates(sdfa, id, terminals, visited);
    }
    if (state.else_goto && visited.contains(state.else_goto)) {
        if (visited.contains(state.else_goto))
            return;
        visited.insert(state.else_goto);
        accumulateTerminalStates(sdfa, state.else_goto, terminals, visited);
    }

}
void DFA::MinDFA::terminateEarly(SDFA &sdfa) {
    if (sdfa.isMerged()) {
        return; // merged DFA is meant for character DFA only -> never terminate early
    }
    std::unordered_set<std::size_t> terminals;
    std::unordered_set<std::size_t> visited;
    accumulateTerminalStates(sdfa, 0, terminals, visited);
    if (terminals.empty())
        return;
    // terminate states
    for (const auto &id : terminals) {
        for (auto &[symbol, t] : sdfa.get()[id].transitions) {
            if (symbol != NFA::TransitionKey {constants::whitespace}) {
                t.next = sdfa.getEmptyState(id);
            }
        }
    }
}
void DFA::MinDFA::WalkDfaToGetUnreachableStates(SDFA &sdfa, std::size_t i, std::unordered_set<std::size_t> &reachable) {
    const auto &state = sdfa.get()[i];
    for (const auto &t : state.transitions) {
        const auto &id = t.second.next;
        if (reachable.contains(id))
            continue;
        reachable.insert(id);

        WalkDfaToGetUnreachableStates(sdfa, id, reachable);
    }
    if (state.else_goto && !reachable.contains(state.else_goto)) {
        reachable.insert(state.else_goto);
        WalkDfaToGetUnreachableStates(sdfa, state.else_goto, reachable);
    }
}
void DFA::MinDFA::removeUnreachableStates(SDFA &sdfa) {
    std::unordered_set<std::size_t> reachable;
    reachable.insert(0);
    Tlog::Branch b(logger, "DFA/removeUnreachableStates");
    WalkDfaToGetUnreachableStates(sdfa, 0, reachable);

    // Step 1: Create mapping from old ID to new ID
    std::unordered_map<std::size_t, std::size_t> old_to_new;
    stdu::vector<SingleState> new_states;
    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        if (reachable.contains(i)) {
            old_to_new[i] = new_states.size();
            new_states.push_back(sdfa.get()[i]);
        }
    }
    logger.log("reachable: {}", reachable);
    logger.log("old_to_new: {}", old_to_new);
    // Step 2: Fix transitions
    for (auto& state : new_states) {
        for (auto& [symbol, trans] : state.transitions) {
            trans.next = old_to_new.at(trans.next);
        }
        if (state.else_goto)
            state.else_goto = old_to_new.at(state.else_goto);
    }
    for (auto &el : sdfa.getEmptyStateMap()) {
        if (old_to_new.contains(el.second)) {
            el.second = old_to_new.at(el.second);
        }
    }
    for (auto &el : sdfa.getIndexToEmptyStateMap()) {
        if (old_to_new.contains(el.second)) {
            el.second = old_to_new.at(el.second);
        }
    }
    sdfa.get().get() = std::move(new_states);
}
void DFA::MinDFA::removeSelfLoop(SDFA &sdfa) {
    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        auto &state = sdfa.get()[i];
        if (state.transitions.empty() || state.else_goto && state.else_goto != i)
            continue;
        if (std::all_of(state.transitions.begin(), state.transitions.end(), [&](auto &transition) {
            return transition.second.next == i;
        })) {
            state.else_goto = sdfa.getEmptyState(i);
        }
    }
}
void DFA::MinDFA::removeDublicateStates() {
    removeDublicateStates(sdfa);
}
void DFA::MinDFA::removeSelfLoop() {
    removeSelfLoop(sdfa);
}
void DFA::MinDFA::removeUnreachableStates() {
    removeUnreachableStates(sdfa);
}
void DFA::MinDFA::terminateEarly() {
    terminateEarly(sdfa);
}

void DFA::MinDFA::minimize(SDFA &sdfa) {
    removeDublicateStates(sdfa);
    terminateEarly(sdfa);
    removeSelfLoop(sdfa);
    removeUnreachableStates(sdfa);
}
void DFA::MinDFA::minimize() {
    minimize(sdfa);
    // move it here
    for (auto &state : sdfa.get())
        states[states.makeNew()] = std::move(state);
    dfa_empty_state_map_ = sdfa.getEmptyStateMap();
    dfa_index_to_empty_state_map_ = sdfa.getIndexToEmptyStateMap();
}
auto DFA::MinDFA::getType() const -> DfaType {
    return Base::getType(states);
}
auto DFA::MinDFA::clear() -> void {
    states.clear();
}

