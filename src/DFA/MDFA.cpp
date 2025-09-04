module DFA.MDFA;

import DFA.States;
import DFA.closure;

import hash;
import logging;
import dstd;
import std;

auto DFA::MDFA::build() -> const States<MultiState>& {
    Tlog::Branch b(logger, "DFA.log");

    utype::unordered_map<Closure, std::size_t> dfa_state_map;  // DFA state ID per NFA state set
    utype::unordered_map<std::pair<Closure, std::variant<stdu::vector<std::string>, char>>, Closure> closure_cache;
    std::unordered_map<std::size_t, Closure> closure_index_cache;
    std::queue<Closure> work;

    // 1. Start state
    StateSet start_set = {0}; // 0 is NFA start state
    Closure start_closure(nfa, start_set);

    dfa_state_map[start_closure] = states.makeNew();
    work.push(start_closure);

    stdu::vector<std::string>  rule_name;
    NFA::DataBlock dtb;
    stdu::vector<std::size_t> goto_empty_states;
    while (!work.empty()) {
        Closure current = work.front();
        work.pop();
        logger.log("current: {}", current);
        std::size_t current_dfa_index = dfa_state_map.at(current);

        // Collect all symbols from the current NFA states (ignore epsilon transitions)
        utype::unordered_map<NFA::TransitionKey, stdu::vector<std::pair<TransitionValue, std::size_t>>> input_symbols;
        for (std::size_t nfa_index : current) {
            const auto &state = nfa.getStates().at(nfa_index);
            for (const auto &[symbol, id] : state.transitions) {
                input_symbols[symbol].emplace_back(TransitionValue {id.next, id.new_cst_node, id.new_member, id.close_cst_node, id.new_group, id.group_close, nfa.getAcceptMap().at(id.next), state.optional, state.last}, state.any);
            }
            if (!state.rule_name.empty()) {
                rule_name = state.rule_name;
                dtb = state.dtb;
            }
        }
        if (input_symbols.empty()) {
            // final state
            states[current_dfa_index].rule_name = rule_name;
            states[current_dfa_index].dtb = dtb;
            empty_state = current_dfa_index;
            continue;
        }
        stdu::vector<const stdu::vector<std::pair<TransitionValue, std::size_t>>*> conflicts;
        for (const auto &[symbol, data] : input_symbols) {
            if (data.size() > 1) {
                conflicts.push_back(&data);
            }
        }
        // build epsilon closures for each conflict symbol
        struct Conflict {
            const Closure *closure;
            const TransitionValue *value;
            std::size_t any;
        };
        stdu::vector<Conflict> conflict_closures;
        for (const auto &conf : conflicts) {
            for (const auto &next_state : *conf) {
                if (!closure_index_cache.contains(next_state.first.next)) {
                    StateSet new_set = {next_state.first.next};
                    closure_index_cache.emplace(next_state.first.next, Closure(nfa, new_set));
                }
                conflict_closures.emplace_back(&closure_index_cache.at(next_state.first.next), &next_state.first, next_state.second);
            }
        }
        // DFA construction
        for (const auto &[symbol, data] : input_symbols) {
            std::size_t empty_state_accept = 0;

            if (!closure_cache.contains(std::make_pair(current, symbol))) {
                closure_cache.emplace(std::make_pair(current, symbol), Closure(nfa, current.get(), symbol));
            }
            auto closure_set = closure_cache.at(std::make_pair(current, symbol));
            logger.log("stdu::vector<std::size_t>: ({}, {})", closure_set, closure_set);
            if (closure_set.empty()) continue;
            // bool goto_empty_state = std::any_of(closure_set.begin(), closure_set.end(), [&](auto &el) {
            //     if (auto id = leadToEmptyState(el)) {
            //         empty_state_accept = nfa->getAcceptMap().at(id);
            //         return true;
            //     }
            //     return false;
            // });
            // Separate conflicting stdu::vector<std::size_t> subsets
            stdu::vector<const Conflict*> process_conflict_list;
            std::unordered_set<std::size_t> closure_set_us(closure_set.begin(), closure_set.end());
            for (const auto &closure : conflict_closures) {
                const auto &conf_set = *closure.closure;
                bool is_subset = std::all_of(conf_set.begin(), conf_set.end(), [&](std::size_t s) {
                    return closure_set_us.contains(s);
                });
                if (is_subset) {
                    for (std::size_t s : conf_set.get()) {
                        closure_set_us.erase(s);
                    }
                    process_conflict_list.push_back(&closure);
                }
            }
            closure_set.get().assign(closure_set_us.begin(), closure_set_us.end());
            std::sort(closure_set.begin(), closure_set.end());

            // Add main (non-conflict) stdu::vector<std::size_t> if any
            if (!closure_set.empty()) {
                if (!dfa_state_map.contains(closure_set)) {
                    dfa_state_map.emplace(closure_set, states.makeNew());
                    work.push(closure_set);
                }
                std::size_t target_index = dfa_state_map.at(closure_set);
                states[current_dfa_index].transitions[symbol].push_back({
                    {target_index, data.back().first.new_cst_node, data.back().first.new_member, data.back().first.close_cst_node, data.back().first.new_group, data.back().first.group_close, data.back().first.accept_index, data.back().first.optional, data.back().first.last}
                });
            }

            // Add split conflict transitions
            for (const auto *conf : process_conflict_list) {
                const auto &conf_closure = *conf->closure;
                const auto *transition = conf->value;
                if (!conf_closure.empty()) {
                    if (!dfa_state_map.contains(conf_closure)) {
                        dfa_state_map.emplace(conf_closure, states.makeNew());
                        work.push(conf_closure);
                    }

                    std::size_t target_index = dfa_state_map.at(conf_closure);
                    states[current_dfa_index].transitions[symbol].push_back({
                        {target_index, transition->new_cst_node, transition->new_member, transition->close_cst_node, transition->new_group, transition->group_close, transition->accept_index, transition->optional, transition->last}
                    });
                }
            }
            // if (goto_empty_state) {
            //     goto_empty_states.push_back(current_dfa_index);
            //     mstates[current_dfa_index].else_goto_accept = empty_state_accept;
            // }
        }
    }
    if (states.empty()) {
        throw Error("DFA cannot be empty");
    }
    if (empty_state == NULL_STATE) {
        empty_state = states.makeNew();
        states[empty_state].rule_name = rule_name;
        states[empty_state].dtb = dtb;
    }
    return states;
}

auto DFA::MDFA::clear() -> void {
    states.clear();
}
auto DFA::MDFA::getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType {
    return Base::getType(states, isToken, dct);
}

