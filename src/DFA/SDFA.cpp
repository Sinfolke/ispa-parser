module DFA.SDFA;

import logging;
import dstd;
import std;

void DFA::SDFA::unrollMultiTransition(std::size_t state_id, const NFA::TransitionKey &symbol, stdu::vector<MultiTransitionValue> &val, SeenSymbol &seen, WalkedState &walked_state) {
    // step 1: get lookaheads for every transition's goto
    Tlog::Branch b(logger, "DFA/unrollMultiTransition");
    using LookaheadSet = stdu::vector<MultiTransitions>;
    using Lookaheads = stdu::vector<std::pair<LookaheadSet, std::size_t>>;
    Lookaheads lookaheads;
    std::queue<std::pair<std::size_t, std::size_t>> work;
    std::size_t work_size = 0;
    std::size_t current_dfa_state = mdfa.get().makeNew();
    mdfa.get()[current_dfa_state].rule_name = mdfa.get()[state_id].rule_name;
    mdfa.get()[current_dfa_state].dtb = mdfa.get()[state_id].dtb;
    bool all_recursive = true;
    // TODO: implement more complex logic to cancel saved input if path without input is chosen
    // if at least one alternative has new_cst_node or new_member, set them to true
    bool new_cst_node = false, new_member = false, close_cst_node = false, optional = false, last = false;
    std::size_t new_group = NFA::NULL_STATE, close_group = NFA::NULL_STATE;
    for (const auto &v : val) {
        if (v.value.new_cst_node)
            new_cst_node = true;
        if (v.value.new_member)
            new_member = true;
        if (v.value.close_cst_node)
            close_cst_node = true;
        if (v.value.new_group != NFA::NULL_STATE)
            new_group = v.value.new_group;
        if (v.value.group_close != NFA::NULL_STATE)
            close_group = v.value.group_close;
        if (v.value.optional)
            optional = true;
        if (v.value.last)
            last = true;
    }
    walked_state[current_dfa_state];
    std::size_t v_count = 0;
    for (const auto &v: val) {
        if (!walked_state.contains(v.value.next)) {
            all_recursive = false;
            walked_state[v.value.next] = current_dfa_state;
        } else {
            v_count++;
            continue;
        }
        work.emplace(v.value.next, v_count++);
        work_size++;
    };
    if (all_recursive) {
        mdfa.get().get().pop_back();
        val = {{ walked_state.at(std::max_element(val.begin(), val.end(), [](const auto& a, const auto& b) { return a.value.next < b.value.next;})->value.next),  new_cst_node, new_member, close_cst_node, new_group, close_group, optional, last }};
        b.log("preventing recursion: val = {}", val.back().value.next);
        return;
    }
    while (!work.empty()) {
        // substep 1: for every symbol in val push new lookahead set
        if (work.size() == work_size) {
            lookaheads.emplace_back();
            // should reach 0 when all is computed. Indicates that work has only initial conflict symbols and so lookahead should be pushed
            work_size--;
        }
        auto [current, val_id] = work.front();
        work.pop();
        // substep 2: push lookaheads to latest lookahead set
        lookaheads.back().first.emplace_back();
        lookaheads.back().second = val_id;
        for (auto &t : mdfa.get()[current].transitions) {
            for (auto &next : t.second) {
                // not loop, push
                next.dfa_merge_conflict = val[val_id].dfa_merge_conflict;
                lookaheads.back().first.back()[t.first].push_back(next);
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
    if (!dfa_empty_state_map_.empty())
        dfa_empty_state_map_[current_dfa_state] = dfa_empty_state_map_[state_id];
    if (!dfa_index_to_empty_state_map_.empty())
        dfa_index_to_empty_state_map_[current_dfa_state] = dfa_index_to_empty_state_map_[state_id];
    logger.log("Lookaheads size: {}", lookaheads.size());
    for (std::size_t i = 0; i < lookaheads.size(); ++i) {
        const auto &[l, val_id] = lookaheads[i];
        logger.log("l[0].size(): {}", l[0].size());
        if (l[0].empty()) {
            std::size_t empty_state;
            if (auto merge_conf = val.at(val_id).dfa_merge_conflict; merge_conf != NULL_STATE) {
                empty_state = getEmptyStateByDfaId(merge_conf);
                b.log("using dfa_index_to_empty_state_map: {} ({})", empty_state, merge_conf);
            } else {
                empty_state = getEmptyState(state_id);
                b.log("using dfa_empty_state_map: {}", empty_state);
            }
            mdfa.get()[current_dfa_state].else_goto = empty_state;
            mdfa.get()[current_dfa_state].else_goto_accept = val.at(i).value.accept_index;
            continue;
        }
        for (const auto &[sym, go]: l[0]) {
            // should be only one state even though it is an array right now
            mdfa.get()[current_dfa_state].transitions[sym].push_back(go.back());
            if (std::any_of(mdfa.get()[current_dfa_state].transitions.begin(), mdfa.get()[current_dfa_state].transitions.end(), [&](const auto &key_value_pair) {
                return key_value_pair.second.back().value.optional && key_value_pair.second.back().value.last;
            })) {
                if (auto v = mdfa.get().canBeEndState(go.back().value.next); v != NULL_STATE) {
                    mdfa.get()[current_dfa_state].else_goto = v;
                }
            }
        }
    }
    // find more dublicate states and unroll
    // std::unordered_set<std::size_t> next_indices;
    // for (const auto &s : mstates[current_dfa_state].transitions) {
    //     for (const auto &t : s.second) {
    //         next_indices.insert(t.value.next);
    //     }
    // }
    // if (!seen[symbol].insert(next_indices).second)
    //     return;
    for (auto &[sym, go]: mdfa.get()[current_dfa_state].transitions) {
        if (go.size() > 1) {
            unrollMultiTransition(current_dfa_state, sym, go, seen, walked_state);
        }
    }
    val = {{current_dfa_state, new_cst_node, new_member, close_cst_node, new_group, close_group, optional, last}};
}

auto DFA::SDFA::build() -> const States<SingleState>& {
    SeenSymbol seen;
    WalkedState walked_state;
    SeenSymbol global_seen;
    for (std::size_t i = 0; i < mdfa.get().size(); ++i) {
        auto &state = mdfa.get()[i];
        for (auto &t : state.transitions) {
            if (t.second.size() > 1) {
                std::unordered_set<std::size_t> next_indices;
                for (const auto el : t.second) {
                    next_indices.insert(el.value.next);
                }
                if (!global_seen[t.first].insert(next_indices).second)
                    break;
                unrollMultiTransition(i, t.first, t.second, seen, walked_state);
                seen.clear();
                walked_state.clear();
            }
        }
    }
    // switch to single state
    for (auto &state : mdfa.get()) {
        auto index = states.makeNew();
        states[index].else_goto = state.else_goto;
        states[index].else_goto_accept = state.else_goto_accept;
        for (auto &t : state.transitions) {
            states[index].transitions[t.first] = std::move(t.second.back().value);
        }
        states[index].rule_name = std::move(state.rule_name);
        states[index].dtb = std::move(state.dtb);
    }
    mdfa.clear();
    return states;
}
auto DFA::SDFA::clear() -> void {
    states.clear();
}
auto DFA::SDFA::getType() const -> DfaType {
    return Base::getType(states);
}
