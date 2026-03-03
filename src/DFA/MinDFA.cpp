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
    DfaEmptyStateMap new_empty_state_map;
    for (auto &el : sdfa.getEmptyStateMap()) {
        new_empty_state_map[old_to_new.at(el.first)] = old_to_new.at(el.second);
    }
    sdfa.getEmptyStateMap() = std::move(new_empty_state_map);
    for (auto &el : sdfa.getIndexToEmptyStateMap()) {
        el.second = old_to_new.at(el.second);
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
    if (!reachable.contains(i))
        reachable.insert(i);
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
    if (sdfa.getEmptyStateMap().contains(i)) {
        auto empty = sdfa.getEmptyStateMap().at(i);
        if (!reachable.contains(empty)) {
            reachable.insert(empty);
            WalkDfaToGetUnreachableStates(sdfa, empty, reachable);
        }
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
    DfaEmptyStateMap new_empty_state_map;
    for (auto &el : sdfa.getEmptyStateMap()) {
        if (old_to_new.contains(el.first)) {
            new_empty_state_map[old_to_new.at(el.first)] = old_to_new.at(el.second);
        }
    }
    sdfa.getEmptyStateMap() = std::move(new_empty_state_map);
    DfaIndexToEmptyStateMap new_index_to_empty_state_map;
    for (auto &el : sdfa.getIndexToEmptyStateMap()) {
        if (old_to_new.contains(el.second)) {
            new_index_to_empty_state_map[el.first] = old_to_new.at(el.second);
        }
    }
    sdfa.getIndexToEmptyStateMap() = std::move(new_index_to_empty_state_map);
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
    // 0) Quick hygiene passes to simplify the input graph
    terminateEarly(sdfa);
    removeSelfLoop(sdfa);
    removeDublicateStates(sdfa);
    removeUnreachableStates(sdfa);

    // 1) Build a global alphabet (all explicit symbols) and remember which states have else_goto
    stdu::vector<NFA::TransitionKey> alphabet;
    alphabet.reserve(64);
    {
        utype::unordered_set<NFA::TransitionKey> seen_sym;
        for (const auto &st : sdfa.get()) {
            for (const auto &kv : st.transitions) {
                if (seen_sym.insert(kv.first).second) {
                    alphabet.push_back(kv.first);
                }
            }
        }
    }

    auto get_transition = [&](const SingleState &s, const NFA::TransitionKey &sym) -> std::pair<TransitionValue, std::size_t> {
        if (auto it = s.transitions.find(sym); it != s.transitions.end()) {
            return {it->second, it->second.next};
        }
        // No explicit transition: fall back to else_goto with neutral output
        return {TransitionValue {}, s.else_goto ? s.else_goto : s.else_goto};
    };

    // 3) Initial partitioning by per-symbol outputs and else_goto_accept (Mealy-style)
    //    Also include each state's mapped empty-state to avoid merging states that differ
    //    only by the path-specific empty state used by construction.
    stdu::vector<std::size_t> state_block(sdfa.get().size(), 0);
    std::unordered_map<std::size_t, std::size_t> sig_to_block; // hash(signature) -> block id
    stdu::vector<stdu::vector<std::size_t>> blocks;
    blocks.reserve(sdfa.get().size());

    // Helper to obtain the effective empty state for a given DFA state id.
    auto get_effective_empty_for_state = [&](std::size_t sid) -> std::size_t {
        const auto &emap = sdfa.getEmptyStateMap();
        if (!emap.empty()) {
            if (auto it = emap.find(sid); it != emap.end()) {
                return it->second;
            }
            // If per-state map exists but this state has no entry, treat as missing
            return NULL_STATE;
        }
        if (sdfa.hasOneEmptyState()) {
            return sdfa.getEmptyState();
        }
        return NULL_STATE;
    };

    auto build_output_signature = [&](std::size_t sid) -> std::size_t {
        const SingleState &s = sdfa.get()[sid];
        // Hash the outputs (TransitionValue without `next`) for each symbol present in the global alphabet;
        // also include presence/identity of else_goto_accept and whether else_goto exists.
        std::size_t h = 1469598103934665603ull; // FNV-1a basis
        auto mix = [&](std::size_t v) {
            h ^= v; h *= 1099511628211ull;
        };
        for (const auto &sym : alphabet) {
            if (auto it = s.transitions.find(sym); it != s.transitions.end()) {
                const auto &tv = it->second; // TransitionValue
                // Exclude `next` from hash: only outputs matter for initial grouping
                mix(std::hash<bool>{}(tv.new_cst_node));
                mix(std::hash<bool>{}(tv.new_member));
                mix(std::hash<bool>{}(tv.close_cst_node));
                mix(std::hash<std::size_t>{}(tv.new_group));
                mix(std::hash<std::size_t>{}(tv.group_close));
                mix(std::hash<std::size_t>{}(tv.accept_index));
                mix(std::hash<bool>{}(tv.consume));
                mix(std::hash<bool>{}(tv.optional));
                mix(std::hash<bool>{}(tv.last));
            } else {
                // Missing explicit edge -> else path with neutral output
                const auto &tv = TransitionValue {};
                mix(std::hash<bool>{}(tv.new_cst_node));
                mix(std::hash<bool>{}(tv.new_member));
                mix(std::hash<bool>{}(tv.close_cst_node));
                mix(std::hash<std::size_t>{}(tv.new_group));
                mix(std::hash<std::size_t>{}(tv.group_close));
                mix(std::hash<std::size_t>{}(tv.accept_index));
                mix(std::hash<bool>{}(tv.consume));
                mix(std::hash<bool>{}(tv.optional));
                mix(std::hash<bool>{}(tv.last));
            }
        }
        mix(std::hash<std::size_t>{}(s.else_goto));
        mix(std::hash<std::size_t>{}(s.else_goto_accept));
        // Include the effective empty state id to keep states with different empty targets separate
        mix(std::hash<std::size_t>{}(get_effective_empty_for_state(sid)));
        return h;
    };

    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        const auto sig = build_output_signature(i);
        auto [it, inserted] = sig_to_block.emplace(sig, blocks.size());
        if (inserted) blocks.emplace_back();
        std::size_t bid = it->second;
        state_block[i] = bid;
        blocks[bid].push_back(i);
    }

    // 4) Refinement: split blocks until stable using (output, target_block) per symbol
    bool changed = true;
    stdu::vector<std::size_t> new_block_of_state(sdfa.get().size());
    while (changed) {
        changed = false;
        stdu::vector<stdu::vector<std::size_t>> next_blocks;
        next_blocks.reserve(blocks.size());
        for (const auto &block : blocks) {
            if (block.size() <= 1) {
                next_blocks.push_back(block);
                continue;
            }
            // Map signature -> list of states
            std::unordered_map<std::size_t, stdu::vector<std::size_t>> groups;
            for (auto sid : block) {
                const auto &s = sdfa.get()[sid];
                std::size_t h = 1469598103934665603ull;
                auto mix = [&](std::size_t v) { h ^= v; h *= 1099511628211ull; };
                for (const auto &sym : alphabet) {
                    auto [tv, nxt] = get_transition(s, sym);
                    // outputs (without next)
                    mix(std::hash<bool>{}(tv.new_cst_node));
                    mix(std::hash<bool>{}(tv.new_member));
                    mix(std::hash<bool>{}(tv.close_cst_node));
                    mix(std::hash<std::size_t>{}(tv.new_group));
                    mix(std::hash<std::size_t>{}(tv.group_close));
                    mix(std::hash<std::size_t>{}(tv.accept_index));
                    mix(std::hash<bool>{}(tv.consume));
                    mix(std::hash<bool>{}(tv.optional));
                    mix(std::hash<bool>{}(tv.last));
                    // target partition id (or special for NULL_STATE)
                    std::size_t pid = (nxt == NULL_STATE) ? std::numeric_limits<std::size_t>::max() : state_block[nxt];
                    mix(pid + 0x9e3779b97f4a7c15ull);
                }
                mix(std::hash<std::size_t>{}(s.else_goto));
                mix(std::hash<std::size_t>{}(s.else_goto_accept));
                // Also refine by the partition of the effective empty state, so that
                // states that route to different (or differently-refined) empty states
                // split appropriately.
                {
                    const auto empty_sid = get_effective_empty_for_state(sid);
                    // Guard against out-of-range indices coming from malformed/mismatched
                    // empty state mappings. If the empty state id is NULL_STATE or outside
                    // the current state_block range, treat it as a special partition id
                    // (i.e., do not use it for splitting with a concrete partition).
                    std::size_t pid = (empty_sid == NULL_STATE || empty_sid >= state_block.size())
                                      ? std::numeric_limits<std::size_t>::max()
                                      : state_block[empty_sid];
                    mix(pid + 0x517cc1b727220a95ull);
                }
                groups[h].push_back(sid);
            }
            if (groups.size() == 1) {
                next_blocks.push_back(block);
            } else {
                changed = true;
                for (auto &kv : groups) {
                    next_blocks.push_back(std::move(kv.second));
                }
            }
        }
        if (changed) {
            blocks = std::move(next_blocks);
            for (std::size_t bid = 0; bid < blocks.size(); ++bid) {
                for (auto s : blocks[bid]) state_block[s] = bid;
            }
        }
    }

    // 5) Build minimized DFA: pick representative for each block and remap transitions to block ids
    States<SingleState> new_states(nullptr);
    stdu::vector<std::size_t> block_to_new(blocks.size(), NULL_STATE);
    for (std::size_t bid = 0; bid < blocks.size(); ++bid) {
        const auto repr = blocks[bid].front();
        std::size_t nid = new_states.makeNew();
        new_states[nid] = sdfa.get()[repr];
        block_to_new[bid] = nid;
    }
    for (auto &st : new_states) {
        for (auto &kv : st.transitions) {
            auto nxt = kv.second.next;
            if (nxt != NULL_STATE)
                kv.second.next = block_to_new[state_block[nxt]];
        }
        if (st.else_goto) {
            st.else_goto = block_to_new[state_block[st.else_goto]];
        }
    }

    // 6) Rebuild empty state maps according to new indices
    std::unordered_map<std::size_t, std::size_t> old_to_new;
    for (std::size_t sid = 0; sid < sdfa.get().size(); ++sid) {
        old_to_new[sid] = block_to_new[state_block[sid]];
    }
    DfaEmptyStateMap new_empty_state_map;
    for (auto &el : sdfa.getEmptyStateMap()) {
        new_empty_state_map[old_to_new.at(el.first)] = old_to_new.at(el.second);
    }
    sdfa.getEmptyStateMap() = std::move(new_empty_state_map);
    for (auto &el : sdfa.getIndexToEmptyStateMap()) {
        el.second = old_to_new.at(el.second);
    }
    if (sdfa.hasOneEmptyState()) {
        // Remap the single empty state only if it exists in the mapping to avoid out_of_range
        const std::size_t old_empty = sdfa.getEmptyState();
        if (auto it = old_to_new.find(old_empty); it != old_to_new.end()) {
            sdfa.getEmptyState() = it->second;
        } else {
            // If the old empty state has been removed during minimization, null it out safely
            sdfa.getEmptyState() = NULL_STATE;
        }
    }

    // 7) Finalize
    sdfa.get() = std::move(new_states);
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

