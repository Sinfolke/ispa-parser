module DFA.MDFA;

import DFA.States;
import DFA.closure;

import hash;
import logging;
import corelib;
import cpuf.op;
import dstd;
import std;

auto DFA::MDFA::build() -> const States<MultiState>& {
    Tlog::Branch b(logger, "DFA.log");

    utype::unordered_map<Closure, std::size_t> dfa_state_map;  // DFA state ID per NFA state set
    utype::unordered_map<std::pair<Closure, std::variant<stdu::vector<std::string>, char>>, Closure> closure_cache;
    std::unordered_map<std::size_t, Closure> closure_index_cache;
    std::queue<Closure> work;

    stdu::vector<std::string> rule_name = nfa.getName();
    NFA::DataBlock dtb = nfa.getDtb();

    // 1. Start state
    StateSet start_set = {0}; // 0 is NFA start state
    Closure start_closure(nfa, start_set);

    auto start_idx = states.makeNew();
    states[start_idx].rule_name = rule_name;
    states[start_idx].dtb = dtb;
    dfa_state_map[start_closure] = start_idx;
    work.push(start_closure);

    struct Conflict {
        const Closure *closure;
        const TransitionValue *value;
        std::size_t any;
    };

    stdu::vector<std::size_t> goto_empty_states;
    logger.log("---- [0] DFA CONSTRUCTION ----");
    logger.increaseIndentLevel();
    while (!work.empty()) {
        Closure current = work.front();
        work.pop();
        std::size_t current_dfa_index = dfa_state_map.at(current);

        auto is_same_output = [](const TransitionValue& a, const TransitionValue& b) {
            return a.next == b.next &&
                   a.new_cst_node == b.new_cst_node &&
                   a.new_member == b.new_member &&
                   a.close_cst_node == b.close_cst_node &&
                   a.new_group == b.new_group &&
                   a.group_close == b.group_close &&
                   a.accept_index == b.accept_index &&
                   a.optional == b.optional &&
                   a.last == b.last;
        };

        // 2. When building input_symbols, group target NFA states that share the same output
        utype::unordered_map<NFA::TransitionKey, stdu::vector<std::pair<TransitionValue, std::size_t>>> input_symbols;
        logger.log("---- [1] DFA TRANSITION CONSTRUCTION ----");
        logger.increaseIndentLevel();
        for (std::size_t nfa_index : current) {
            const auto &state = nfa.getStates().at(nfa_index);
            logger.log("Constructing Transition for nfa state: \n\n{}\n\n", state);
            for (const auto &[symbol, id] : state.transitions) {
                TransitionValue incoming_val {
                    id.next, id.new_cst_node, id.new_member, id.close_cst_node,
                    id.new_group, id.group_close, nfa.getAcceptMap().at(id.next),
                    // change to state.optional, state.last when needed
                    false, false
                };
                // See if we already have a transition for this symbol with identical outputs
                auto& data_list = input_symbols[symbol];
                bool merged = false;
                for (auto& existing : data_list) {
                    if (is_same_output(existing.first, incoming_val)) {
                        // We don't push a new branch! The target NFA state will just be
                        // absorbed into the closure generation later.
                        merged = true;
                        break;
                    }
                }

                if (!merged) {
                    data_list.emplace_back(incoming_val, state.any);
                }
            }
        }
        if (input_symbols.empty() && !rule_name.empty()) {
            // final state
            logger.log("Final state is {}, rule_name: {}", current_dfa_index, rule_name);
            states[current_dfa_index].rule_name = rule_name;
            states[current_dfa_index].dtb = dtb;
            empty_state = current_dfa_index;
            continue;
        }
        logger.decreaseIndentLevel();
        logger.log("---- [2] DFA CONFLICT RESOLUTION ----");
        logger.increaseIndentLevel();
        // DFA construction
        for (const auto &[symbol, data] : input_symbols) {
            // build epsilon closures for conflicts belonging to this symbol only
            stdu::vector<Conflict> conflict_closures;
            if (data.size() > 1) {
                for (const auto &next_state : data) {
                    if (!closure_index_cache.contains(next_state.first.next)) {
                        StateSet new_set = {next_state.first.next};
                        closure_index_cache.emplace(next_state.first.next, Closure(nfa, new_set));
                    }
                    conflict_closures.emplace_back(&closure_index_cache.at(next_state.first.next), &next_state.first, next_state.second);
                }
            }

            if (!closure_cache.contains(std::make_pair(current, symbol))) {
                closure_cache.emplace(std::make_pair(current, symbol), Closure(nfa, current.get(), symbol));
            }
            auto closure_set = closure_cache.at(std::make_pair(current, symbol));
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
                const TransitionValue *main_transition = nullptr;
                for (const auto &next_state : data) {
                    if (!closure_index_cache.contains(next_state.first.next)) {
                        StateSet new_set = {next_state.first.next};
                        closure_index_cache.emplace(next_state.first.next, Closure(nfa, new_set));
                    }
                    const auto &candidate_closure = closure_index_cache.at(next_state.first.next);
                    const bool intersects_main = std::any_of(candidate_closure.begin(), candidate_closure.end(), [&](std::size_t s) {
                        return closure_set_us.contains(s);
                    });
                    if (intersects_main) {
                        main_transition = &next_state.first;
                        break;
                    }
                }
                if (!main_transition) {
                    main_transition = &data.front().first;
                }

                if (!dfa_state_map.contains(closure_set)) {
                    auto new_idx = states.makeNew();
                    states[new_idx].rule_name = rule_name;
                    states[new_idx].dtb = dtb;
                    dfa_state_map.emplace(closure_set, new_idx);
                    work.push(closure_set);
                }
                std::size_t target_index = dfa_state_map.at(closure_set);
                states[current_dfa_index].transitions[symbol].push_back({
                    {target_index, main_transition->new_cst_node, main_transition->new_member, main_transition->close_cst_node, main_transition->new_group, main_transition->group_close, main_transition->accept_index, main_transition->optional, main_transition->last}
                });
            }

            // Add split conflict transitions
            for (const auto *conf : process_conflict_list) {
                const auto &conf_closure = *conf->closure;
                const auto *transition = conf->value;
                if (!conf_closure.empty()) {
                    if (!dfa_state_map.contains(conf_closure)) {
                        auto new_idx = states.makeNew();
                        states[new_idx].rule_name = rule_name;
                        states[new_idx].dtb = dtb;
                        dfa_state_map.emplace(conf_closure, new_idx);
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
    check_dfa();
    return states;
}

auto DFA::MDFA::clear() -> void {
    states.clear();
}
auto DFA::MDFA::getType() const -> DfaType {
    return Base::getType(states);
}

auto DFA::MDFA::check_dfa() -> void {
    std::size_t index = 0;
    try {
        for (const auto &state : states) {
            AssertNe(state.rule_name.empty(), "Empty rule_name in state {}", index);
            AssertNe(state.transitions.empty() && state.else_goto != NULL_STATE, "Else_goto on no-transition state");
            for (const auto &[sym, transitions] : state.transitions) {
                if (std::holds_alternative<stdu::vector<std::string>>(sym)) {
                    const auto &nested_name = std::get<stdu::vector<std::string>>(sym);
                    AssertNe(nested_name.empty(), "Empty nested_name in state {}", index);
                }
                for (const auto &t : transitions) {
                    Assert(states.size() >= t.value.next, "Out of bound transition {} in state {}", t.value.next, index);
                }
            }
            ++index;
        }
    } catch (Error &e) {
        std::cout << "[MDFA] Check Failed > " << e.what() << '\n';
        std::cout << "Runtime checks of DFA are required on unstable release. Please report to 'https://github.com/Sinfolke/ispa-parser'";
        std::cout << "If this happens after switching to unstable version, consider roll back. Otherwise check your unusual tokens";
        std::cout << "Names related to this error: ";
        for (const auto &name : getDfaNames(*this)) {
            std::cout << name.first << ", ";
        }
        std::cout << '\n';
        std::cout << "DFA: \n";
        std::cout << *this;
        std::abort();
    }
}

auto DFA::operator<<(std::ostream& os, const MDFA& dfa) -> std::ostream& {
    std::size_t index = 0;
    for (const auto &state : dfa.get()) {
        os << "State " << index << ": \n";
        for (const auto &[symbol, next] : state.transitions) {
            os << "\t";
            if (std::holds_alternative<char>(symbol)) {
                auto c = std::get<char>(symbol);
                if (std::isprint(c) && !std::isspace(c)) {
                    os << c;
                } else if (std::isspace(c)) {
                    os << corelib::text::getEscapedFromChar(c);
                }
            } else {
                os << corelib::text::join(std::get<stdu::vector<std::string>>(symbol), "::");
            }
            os << " -> ";
            for (const auto &transition : next) {
                os << transition.value.next;
            }
            os << '\n';
        }
        os << "[rule_name]: " << corelib::text::join(state.rule_name, "::") << '\n';
        if (!std::holds_alternative<std::monostate>(state.dtb)) {
            os << "\t[dtb] = {";
            if (std::holds_alternative<NFA::TemplatedDataBlockValue>(state.dtb)) {
                os << (std::get<NFA::TemplatedDataBlockValue>(state.dtb).type == NFA::StoreCstNode::CST_GROUP ? "group" : "node") << "}\n";
            } else {
                os << '\n';
                for (const auto &[name, data] : std::get<NFA::TemplatedDataBlock>(state.dtb)) {
                    os << "\t\t" << name << ": {" << (data.type == NFA::StoreCstNode::CST_GROUP ? "group" : "node") << ", " << data.cst_index << "}\n";
                }
                os << "\t}\n";
            }
        }
        if (state.else_goto != DFA::NULL_STATE) {
            os << "e -> " << state.else_goto;
            if (state.else_goto_accept != DFA::NULL_STATE) {
                os << " [accept -> " << state.else_goto_accept << "]";
            }
            os << '\n';
        }
        ++index;
    }
    return os;
}

