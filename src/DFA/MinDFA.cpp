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
    constexpr std::size_t DEAD = std::numeric_limits<std::size_t>::max();

    std::unordered_map<std::size_t, std::size_t> duplicate_to_orig;

    auto same_transition = [](TransitionValue lhs, TransitionValue rhs) {
        // `accept_index` is tied to NFA-origin numbering and does not affect
        // the observable DFA shape used by dump/dispatch.
        lhs.accept_index = NULL_STATE;
        rhs.accept_index = NULL_STATE;
        return lhs == rhs;
    };

    auto same_state = [&](const SingleState &a, const SingleState &b) {
        if (a.transitions.size() != b.transitions.size())
            return false;
        if (a.else_goto != b.else_goto ||
            a.else_goto_accept != b.else_goto_accept ||
            a.rule_name != b.rule_name ||
            a.dtb != b.dtb)
            return false;

        for (const auto &[sym, t] : a.transitions) {
            auto it = b.transitions.find(sym);
            if (it == b.transitions.end())
                return false;
            if (!same_transition(t, it->second))
                return false;
        }
        return true;
    };

    stdu::vector<std::size_t> representatives;

    // ----------------------------
    // 1) detect duplicates
    // ----------------------------
    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        bool matched = false;

        for (std::size_t j : representatives) {
            if (same_state(sdfa.get()[i], sdfa.get()[j])) {
                duplicate_to_orig[i] = j;
                matched = true;
                break;
            }
        }

        if (!matched)
            representatives.push_back(i);
    }

    // ----------------------------
    // 2) resolve representative chain safely
    // ----------------------------
    auto resolve = [&](std::size_t x) -> std::size_t {
        while (duplicate_to_orig.contains(x)) {
            std::size_t p = duplicate_to_orig[x];
            if (!duplicate_to_orig.contains(p))
                return p;
            x = p;
        }
        return x;
    };

    // ----------------------------
    // 3) build new state set
    // ----------------------------
    States<SingleState> new_states(nullptr);
    std::unordered_map<std::size_t, std::size_t> old_to_new;

    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        if (!duplicate_to_orig.contains(i)) {
            std::size_t nid = new_states.makeNew();
            new_states[nid] = sdfa.get()[i];
            old_to_new[i] = nid;
        }
    }

    // map duplicates → representative
    for (auto &[dup, orig] : duplicate_to_orig) {
        std::size_t rep = resolve(orig);

        auto it = old_to_new.find(rep);
        if (it != old_to_new.end()) {
            old_to_new[dup] = it->second;
        }
    }

    // ----------------------------
    // 4) remap transitions safely
    // ----------------------------
    for (auto &st : new_states) {
        for (auto &kv : st.transitions) {
            auto it = old_to_new.find(kv.second.next);
            if (it != old_to_new.end())
                kv.second.next = it->second;
            else
                kv.second.next = NULL_STATE;
        }

        if (st.else_goto != NULL_STATE) {
            auto it = old_to_new.find(st.else_goto);
            if (it != old_to_new.end())
                st.else_goto = it->second;
            else
                st.else_goto = NULL_STATE;
        }
    }

    // ----------------------------
    // 5) rebuild empty state map safely (NO .at)
    // ----------------------------
    DfaEmptyStateMap new_empty_state_map;

    for (const auto &el : sdfa.getEmptyStateMap()) {
        auto it_from = old_to_new.find(el.first);
        auto it_to   = old_to_new.find(el.second);

        if (it_from == old_to_new.end() || it_to == old_to_new.end())
            continue;

        new_empty_state_map[it_from->second] = it_to->second;
    }

    sdfa.getEmptyStateMap() = std::move(new_empty_state_map);

    // ----------------------------
    // 6) rebuild index-to-empty-state map safely (key AND value remapped)
    // ----------------------------
    DfaIndexToEmptyStateMap new_index_to_empty_state_map;

    for (const auto &el : sdfa.getIndexToEmptyStateMap()) {
        auto it_key = old_to_new.find(el.first);
        auto it_val = old_to_new.find(el.second);

        if (it_key == old_to_new.end() || it_val == old_to_new.end())
            continue;

        new_index_to_empty_state_map[it_key->second] = it_val->second;
    }

    sdfa.getIndexToEmptyStateMap() = std::move(new_index_to_empty_state_map);

    // ----------------------------
    // 7) fix global empty state
    // ----------------------------
    if (sdfa.hasOneEmptyState()) {
        auto it = old_to_new.find(sdfa.getEmptyState());
        sdfa.getEmptyState() =
            (it != old_to_new.end()) ? it->second : NULL_STATE;
    }

    // ----------------------------
    // 8) finalize
    // ----------------------------
    sdfa.get() = std::move(new_states);
}

void DFA::MinDFA::accumulateTerminalStates(SDFA &sdfa, std::size_t i, std::unordered_set<std::size_t> &terminals, std::unordered_set<std::size_t> &visited) {
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
    if (state.else_goto != NULL_STATE && !visited.contains(state.else_goto)) {
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
    if (state.else_goto != NULL_STATE && !reachable.contains(state.else_goto)) {
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
        if (state.else_goto != NULL_STATE)
            state.else_goto = old_to_new.at(state.else_goto);
    }
    DfaEmptyStateMap new_empty_state_map;
    for (auto &el : sdfa.getEmptyStateMap()) {
        auto it_from = old_to_new.find(el.first);
        auto it_to   = old_to_new.find(el.second);
        if (it_from == old_to_new.end() || it_to == old_to_new.end())
            continue;
        new_empty_state_map[it_from->second] = it_to->second;
    }
    sdfa.getEmptyStateMap() = std::move(new_empty_state_map);
    DfaIndexToEmptyStateMap new_index_to_empty_state_map;
    for (auto &el : sdfa.getIndexToEmptyStateMap()) {
        auto it_key = old_to_new.find(el.first);
        auto it_val = old_to_new.find(el.second);
        if (it_key == old_to_new.end() || it_val == old_to_new.end())
            continue;
        new_index_to_empty_state_map[it_key->second] = it_val->second;
    }
    sdfa.getIndexToEmptyStateMap() = std::move(new_index_to_empty_state_map);
    // Keep the single empty-state index consistent with the new numbering
    // (the maps above are remapped, but the standalone empty_state was not).
    if (sdfa.hasOneEmptyState()) {
        auto it = old_to_new.find(sdfa.getEmptyState());
        sdfa.getEmptyState() = (it != old_to_new.end()) ? it->second : NULL_STATE;
    }
    sdfa.get().get() = std::move(new_states);
}

void DFA::MinDFA::removeSelfLoop(SDFA &sdfa) {
    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        auto &state = sdfa.get()[i];
        if (state.transitions.empty() || state.else_goto != NULL_STATE && state.else_goto != i)
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
    removeUnreachableStates(sdfa);
    // `terminateEarly` can prematurely cut still-live continuation paths
    // (e.g. keyword tails sharing prefixes), so keep full transitions here.
    removeSelfLoop(sdfa);


    constexpr std::size_t DEAD = std::numeric_limits<std::size_t>::max();

    struct Signature {
        // Each edge stores the transition symbol together with the full
        // TransitionValue payload (its `next` field repurposed to hold the
        // target block id). This ensures that states which reach equivalent
        // blocks but perform different semantic actions (accept_index,
        // new_cst_node, new_member, close_cst_node, new_group, group_close,
        // ...) are NOT merged during minimization.
        std::vector<std::pair<NFA::TransitionKey, TransitionValue>> edges;
        std::size_t else_block = DEAD;
        std::size_t else_goto_accept = DEAD;
        stdu::vector<std::string> rule_name;
        NFA::DataBlock dtb;

        bool operator==(const Signature &o) const = default;

    private:
        friend struct ::uhash;
        auto members() const {
            return std::tie(edges, else_block, else_goto_accept, rule_name, dtb);
        }
    };

    // --------------------------
    // 1) alphabet
    // --------------------------
    stdu::vector<NFA::TransitionKey> alphabet;
    utype::unordered_set<NFA::TransitionKey> seen;

    for (const auto &st : sdfa.get()) {
        for (const auto &kv : st.transitions) {
            if (seen.insert(kv.first).second)
                alphabet.push_back(kv.first);
        }
    }

    // --------------------------
    // helper
    // --------------------------
    auto get_transition = [&](const SingleState &s,
                              const NFA::TransitionKey &sym)
        -> std::pair<TransitionValue, std::size_t>
    {
        if (auto it = s.transitions.find(sym); it != s.transitions.end())
            return {it->second, it->second.next};

        return {TransitionValue{}, s.else_goto};
    };

    // --------------------------
    // initial partition
    // --------------------------
    stdu::vector<std::size_t> state_block(sdfa.get().size(), 0);

    utype::unordered_map<Signature, std::size_t> sig_to_block;
    stdu::vector<stdu::vector<std::size_t>> blocks;

    auto build_signature = [&](std::size_t sid) -> Signature {
        Signature sig;
        const auto &s = sdfa.get()[sid];

        sig.edges.reserve(alphabet.size());

        for (const auto &sym : alphabet) {
            auto [tv, nxt] = get_transition(s, sym);
            std::size_t bid = (nxt == NULL_STATE)
                ? DEAD
                : state_block[nxt];

            // Repurpose `next` to carry the destination block id so that both
            // the target block AND the transition actions participate in the
            // signature equality/hash.
            tv.next = bid;

            // `accept_index` is an NFA-origin index and may legitimately differ
            // between otherwise equivalent DFA states. It is not part of the
            // externally observable DFA structure dumped in `Dumps/DFA.txt`,
            // and keeping it in the minimization signature prevents expected
            // merges like the duplicate states in the first COMPARE_OP DFA.
            tv.accept_index = NULL_STATE;
            sig.edges.emplace_back(sym, tv);
        }

        // Edges are built in a fixed alphabet order for every state, so the
        // sequences are already aligned and no sorting is required.
        if (sig.edges.empty()) {
            sig.rule_name = s.rule_name;
            sig.dtb = s.dtb;
        } else {
            sig.else_block = (s.else_goto == NULL_STATE)
                ? DEAD
                : state_block[s.else_goto];

            sig.else_goto_accept = s.else_goto_accept;
        }
        return sig;
    };

    for (std::size_t i = 0; i < sdfa.get().size(); ++i) {
        Signature sig = build_signature(i);

        auto [it, inserted] = sig_to_block.emplace(sig, blocks.size());
        if (inserted) blocks.emplace_back();

        blocks[it->second].push_back(i);
    }

    // Pass 2: Commit the initial block assignments BEFORE refinement
    for (std::size_t b = 0; b < blocks.size(); ++b) {
        for (auto s : blocks[b]) {
            state_block[s] = b;
        }
    }

    // --------------------------
    // refinement
    // --------------------------
    bool changed = true;

    while (changed) {
        changed = false;
        stdu::vector<stdu::vector<std::size_t>> next_blocks;

        for (const auto &block : blocks) {
            if (block.size() <= 1) {
                next_blocks.push_back(block);
                continue;
            }

            utype::unordered_map<Signature, stdu::vector<std::size_t>> groups;

            for (auto sid : block) {
                groups[build_signature(sid)].push_back(sid);
            }

            if (groups.size() == 1) {
                next_blocks.push_back(block);
            } else {
                changed = true;
                for (auto &g : groups)
                    next_blocks.push_back(std::move(g.second));
            }
        }

        if (changed) {
            blocks = std::move(next_blocks);

            for (std::size_t b = 0; b < blocks.size(); ++b)
                for (auto s : blocks[b])
                    state_block[s] = b;
        }
    }

    // --------------------------
    // rebuild DFA
    // --------------------------
    States<SingleState> new_states(nullptr);
    stdu::vector<std::size_t> block_to_new(blocks.size(), NULL_STATE);

    for (std::size_t b = 0; b < blocks.size(); ++b) {
        auto repr = blocks[b].front();
        std::size_t nid = new_states.makeNew();
        new_states[nid] = sdfa.get()[repr];
        block_to_new[b] = nid;
    }

    for (auto &st : new_states) {
        for (auto &kv : st.transitions) {
            if (kv.second.next != NULL_STATE)
                kv.second.next = block_to_new[state_block[kv.second.next]];
        }

        if (st.else_goto != NULL_STATE)
            st.else_goto = block_to_new[state_block[st.else_goto]];
    }

    // --------------------------
    // remap auxiliary structures
    // --------------------------
    std::unordered_map<std::size_t, std::size_t> old_to_new;

    for (std::size_t i = 0; i < sdfa.get().size(); ++i)
        old_to_new[i] = block_to_new[state_block[i]];

    DfaEmptyStateMap new_map;

    for (auto &e : sdfa.getEmptyStateMap()) {
        if (old_to_new.contains(e.first) && old_to_new.contains(e.second))
            new_map[old_to_new[e.first]] = old_to_new[e.second];
    }

    sdfa.getEmptyStateMap() = std::move(new_map);

    DfaIndexToEmptyStateMap new_index_to_empty_state_map;

    for (auto &e : sdfa.getIndexToEmptyStateMap()) {
        if (old_to_new.contains(e.first) && old_to_new.contains(e.second))
            new_index_to_empty_state_map[old_to_new[e.first]] = old_to_new[e.second];
    }

    sdfa.getIndexToEmptyStateMap() = std::move(new_index_to_empty_state_map);

    if (sdfa.hasOneEmptyState()) {
        auto old = sdfa.getEmptyState();
        sdfa.getEmptyState() =
            old_to_new.contains(old) ? old_to_new[old] : NULL_STATE;
    }

    sdfa.get() = std::move(new_states);

    // Run explicit duplicate-state compaction on the rebuilt DFA.
    // This is especially important for identical empty/fallback states,
    // which may still appear after partition rebuild.
    removeDublicateStates(sdfa);

    // Keep only states reachable from the start after all rewrites.
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