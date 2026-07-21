module DFA.CharMachineDFA;
import logging;
import corelib;
import std;
import cpuf.printf;

auto DFA::CharMachineDFA::build() -> const States<CharMachineState>& {
    auto &sorted_states = sorted_dfa.get();
    auto &states = this->states.get();
    auto states_size = sorted_states.size();

    for (std::size_t i = 0; i < states_size; i++) {
        auto type = sorted_dfa.getStateType(sorted_states[i].transitions);
        auto initial_else_goto = sorted_states[i].else_goto;

        if (type == DfaType::Multi && !sorted_states[i].transitions.empty()) {
            std::size_t current_type = sorted_states[i].transitions.begin()->first.index();
            std::size_t partitioned_state = i;

            // FIX 1: Track partitions by index, avoiding pointer invalidation on reallocation
            std::size_t current_partition_idx = std::numeric_limits<std::size_t>::max();
            std::size_t erase_from = sorted_states[i].transitions.size();

            for (std::size_t j = 0; j < sorted_states[i].transitions.size(); ++j) {
                // Fetch copies of symbol and value to protect against references changing layout
                auto symbol = sorted_states[i].transitions[j].first;
                auto value = sorted_states[i].transitions[j].second;

                if (symbol.index() != current_type) {
                    auto new_state = sorted_states.makeNew();
                    sorted_states[new_state].rule_name = sorted_states[i].rule_name;
                    sorted_states[new_state].dtb = sorted_states[i].dtb;

                    if (current_partition_idx == std::numeric_limits<std::size_t>::max()) {
                        sorted_states[i].else_goto = new_state;
                        erase_from = j;
                    } else {
                        sorted_states[current_partition_idx].else_goto = new_state;
                    }

                    getEmptyStateMap()[new_state] = getEmptyStateMap()[partitioned_state];
                    getIndexToEmptyStateMap()[new_state] = getIndexToEmptyStateMap()[partitioned_state];

                    current_type = symbol.index();
                    current_partition_idx = new_state; // Safe index assignment
                    partitioned_state = new_state;
                }

                if (current_partition_idx != std::numeric_limits<std::size_t>::max()) {
                    sorted_states[current_partition_idx].transitions.emplace_back(symbol, value);
                }
            }

            if (current_partition_idx != std::numeric_limits<std::size_t>::max()) {
                sorted_states[current_partition_idx].else_goto = initial_else_goto;
                sorted_states[i].transitions.erase(sorted_states[i].transitions.begin() + erase_from, sorted_states[i].transitions.end());
            }
        }
    }

    bool has_multi_state = false;
    for (auto &state : sorted_states) {
        if (state.transitions.empty()) {
            states.emplace_back(state.nfa_states, std::variant<FullCharTable, SortedTransitions> {SortedTransitions {}}, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
            continue;
        }

        if (std::holds_alternative<char>(state.transitions.begin()->first)) {
            FullCharTable char_table;

            // Initialize entire table with fallback markers cleanly
            TransitionValue default_transition;
            default_transition.next = NULL_STATE;
            char_table.fill(default_transition); // Assumes FullCharTable is an array-like wrapper

            // FIX 2 & 3: Directly map sorted transitions.
            // Eliminates find_if bottleneck and covers full 0-255 character range safely.
            for (const auto &[symbol, value] : state.transitions) {
                auto unsigned_char_idx = static_cast<unsigned char>(std::get<char>(symbol));
                char_table[unsigned_char_idx] = value;
            }

            states.emplace_back(state.nfa_states, char_table, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        } else {
            has_multi_state = true;
            states.emplace_back(state.nfa_states, state.transitions, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        }
    }

    auto same_transitions = [&](const CharMachineStateVariant &a, const CharMachineStateVariant &b) {
        if (a.index() != b.index())
            return false;
        if (std::holds_alternative<FullCharTable>(a)) {
            const auto &ta = std::get<FullCharTable>(a);
            const auto &tb = std::get<FullCharTable>(b);
            for (std::size_t i = 0; i < ta.size(); ++i) {
                if (ta[i] != tb[i])
                    return false;
            }
            return true;
        }
        const auto &ta = std::get<SortedTransitions>(a);
        const auto &tb = std::get<SortedTransitions>(b);
        if (ta.size() != tb.size())
            return false;
        for (std::size_t i = 0; i < ta.size(); ++i) {
            if (ta[i].first != tb[i].first || ta[i].second != tb[i].second)
                return false;
        }
        return true;
    };

    auto same_state = [&](const CharMachineState &a, const CharMachineState &b) {
        return a.else_goto == b.else_goto &&
               a.else_goto_accept == b.else_goto_accept &&
               a.rule_name == b.rule_name &&
               a.dtb == b.dtb &&
               same_transitions(a.transitions, b.transitions);
    };

    stdu::vector<std::size_t> old_to_new(states.size(), NULL_STATE);
    stdu::vector<CharMachineState> compact;
    compact.reserve(states.size());

    for (std::size_t i = 0; i < states.size(); ++i) {
        bool merged = false;
        for (std::size_t j = 0; j < compact.size(); ++j) {
            if (same_state(states[i], compact[j])) {
                old_to_new[i] = j;
                merged = true;
                break;
            }
        }
        if (!merged) {
            old_to_new[i] = compact.size();
            compact.push_back(states[i]);
        }
    }

    for (auto &state : compact) {
        if (std::holds_alternative<FullCharTable>(state.transitions)) {
            auto &table = std::get<FullCharTable>(state.transitions);
            for (auto &t : table) {
                if (t.next != NULL_STATE)
                    t.next = old_to_new[t.next];
            }
        } else {
            auto &transitions = std::get<SortedTransitions>(state.transitions);
            for (auto &[symbol, t] : transitions) {
                if (t.next != NULL_STATE)
                    t.next = old_to_new[t.next];
            }
        }
        if (state.else_goto != NULL_STATE)
            state.else_goto = old_to_new[state.else_goto];
    }

    DfaEmptyStateMap new_empty_state_map;
    for (const auto &[from, to] : getEmptyStateMap()) {
        if (from < old_to_new.size() && to < old_to_new.size())
            new_empty_state_map[old_to_new[from]] = old_to_new[to];
    }
    getEmptyStateMap() = std::move(new_empty_state_map);

    DfaIndexToEmptyStateMap new_index_to_empty_state_map;
    for (const auto &[from, to] : getIndexToEmptyStateMap()) {
        if (from < old_to_new.size() && to < old_to_new.size())
            new_index_to_empty_state_map[old_to_new[from]] = old_to_new[to];
    }
    getIndexToEmptyStateMap() = std::move(new_index_to_empty_state_map);

    if (hasOneEmptyState()) {
        auto old = getEmptyState();
        getEmptyState() = old < old_to_new.size() ? old_to_new[old] : NULL_STATE;
    }

    states = std::move(compact);
    return this->states;
}
auto DFA::CharMachineDFA::getType() const -> DfaType {
    return Base::getType(states);
}
auto DFA::CharMachineDFA::clear() -> void {
    states.clear();
}
auto DFA::operator<<(std::ostream &os, const CharMachineDFA &dfa) -> std::ostream & {
    std::size_t i = 0;
    for (const auto &state : dfa.get()) {
        os << i++ << ": \n";
        if (!state.rule_name.empty())
            os << "\t[rule_name] = " << corelib::text::join(state.rule_name, "::") << "\n";
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
        if (std::holds_alternative<FullCharTable>(state.transitions)) {
            unsigned char c = 0;
            for (const auto &transition : std::get<FullCharTable>(state.transitions)) {
                if (transition.next != NULL_STATE) {
                    os << "\t" << static_cast<char>(c) << " -> " << transition.next << '\n';
                }
                c++;
            }
        } else {
            for (const auto &[name, transition] : std::get<SortedTransitions>(state.transitions)) {
                if (std::holds_alternative<char>(name)) {
                    os << "\t" << std::get<char>(name) << " -> " << transition.next;
                } else {
                    os << "\t" << corelib::text::join(std::get<stdu::vector<std::string>>(name), "::") << " -> " << transition.next;
                }
                if (transition.new_cst_node) {
                    os << " [new_cst_node]";
                }
                if (transition.new_member) {
                    os << " [new_member]";
                }
                if (transition.new_group) {
                    os << " [new_group]";
                }
                if (transition.close_cst_node) {
                    os << " [close_cst_node]";
                }
                if (transition.group_close) {
                    os << " [group_close]";
                }
                os << '\n';
            }
        }
        os << "\t[else_goto] = " << (state.else_goto == NULL_STATE ? std::string("[no]") : std::to_string(state.else_goto)) << '\n';
        os << "\t[else_goto_accept] = " << (state.else_goto_accept == NULL_STATE ? std::string("NULLSTATE") : std::to_string(state.else_goto_accept)) << '\n';
    }
    return os;
}

auto DFA::CharMachineDFA::availableTypes() const -> stdu::vector<LangAPI::Type> {
    stdu::vector<LangAPI::Type> names;
    utype::unordered_set<stdu::vector<std::string>> dedublication;
    for (const auto &state : states) {
        if (!state.rule_name.empty() && !dedublication.contains(state.rule_name)) {
            LangAPI::Symbol s = state.rule_name;
            ;s.path.insert(s.path.begin(), "Types");
            names.push_back(LangAPI::Type {s});
            dedublication.insert(state.rule_name);
        }
    }
    return names;
}
