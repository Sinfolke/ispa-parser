module DFA.CharMachineDFA;
import logging;
import corelib;
import std;
import cpuf.printf;

auto DFA::CharMachineDFA::build() -> const States<CharMachineState>& {
    // move to current class
    auto &sorted_states = sorted_dfa.get();
    auto &states = this->states.get();
    auto states_size = sorted_states.size();
    for (std::size_t i = 0; i < states_size; i++) {
        auto type = sorted_dfa.getStateType(sorted_states[i].transitions);
        auto initial_else_goto = sorted_states[i].else_goto;
        if (type == DfaType::Multi && !sorted_states[i].transitions.empty()) {
            // Copy maps from the original state

            std::size_t current_type = sorted_states[i].transitions.begin()->first.index();
            std::size_t partitioned_state = i;
            SortedState *current_partition = nullptr;
            std::size_t erase_from = sorted_states[i].transitions.size();
            for (std::size_t j = 0; j < sorted_states[i].transitions.size(); ++j) {
                const auto &[symbol, value] = sorted_states[i].transitions[j];
                if (symbol.index() != current_type) {
                    // Start a new partition
                    auto new_state = sorted_states.makeNew();
                    sorted_states[new_state].rule_name = sorted_states[i].rule_name;
                    sorted_states[new_state].dtb = sorted_states[i].dtb;
                    if (current_partition == nullptr) {
                        sorted_states[i].else_goto = new_state;
                        erase_from = j;
                    } else {
                        current_partition->else_goto = new_state;
                    }

                    getEmptyStateMap()[new_state] = getEmptyStateMap()[partitioned_state];
                    getIndexToEmptyStateMap()[new_state] = getIndexToEmptyStateMap()[partitioned_state];

                    current_type = symbol.index();
                    current_partition = &sorted_states[new_state];
                    partitioned_state = new_state;
                } else if (current_partition == nullptr)
                    continue;

                current_partition->transitions.emplace_back(symbol, value);
            }

            // Connect the last partition to the original else_goto
            if (current_partition != nullptr) {
                current_partition->else_goto = initial_else_goto;
                sorted_states[i].transitions.erase(sorted_states[i].transitions.begin() + erase_from, sorted_states[i].transitions.end());
            }
        }
    }
    // add all characters to transition & unroll else_goto in character states
    bool has_multi_state = false;
    for (auto &state : sorted_states) {
        FullCharTable char_table;
        if (state.transitions.empty()) {
            states.emplace_back(state.nfa_states, std::variant<FullCharTable, SortedTransitions> {SortedTransitions {}}, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
            continue;
        }
        if (std::holds_alternative<char>(state.transitions.begin()->first)) {
            // a state is always either char or advanced in this stage
            for (unsigned char uc = 0; uc < std::numeric_limits<unsigned char>::max() - 1; uc++) {
                auto c = static_cast<char>(uc);
                TransitionValue transition;
                if (auto it = std::find_if(state.transitions.begin(), state.transitions.end(), [&](const auto &v) { return std::get<char>(v.first) == c; }); it != state.transitions.end()) {
                    transition = it->second;
                } else {
                    transition.next = NULL_STATE;
                }
                char_table[c] = transition;
            }
            states.emplace_back(state.nfa_states, char_table, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        } else {
            has_multi_state = true;
            states.emplace_back(state.nfa_states, state.transitions, state.else_goto, state.else_goto_accept, state.rule_name, state.dtb);
        }
    }
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
            if (std::holds_alternative<NFA::SingleValueDataBlock>(state.dtb)) {
                os << (std::get<NFA::SingleValueDataBlock>(state.dtb) == NFA::StoreCstNode::CST_GROUP ? "group" : "node") << "}\n";
            } else {
                os << '\n';
                for (const auto &[name, data] : std::get<NFA::TemplatedDataBlock>(state.dtb)) {
                    os << "\t\t" << name << ": {" << (data.first == NFA::StoreCstNode::CST_GROUP ? "group" : "node") << ", " << data.second << "}\n";
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
                    os << "\t" << std::get<char>(name) << " -> " << transition.next << '\n';
                } else {
                    os << "\t" << corelib::text::join(std::get<stdu::vector<std::string>>(name), "::") << " -> " << transition.next << '\n';
                }
            }
        }
        os << "\t[else_goto] = " << (state.else_goto == 0 ? std::string("[no]") : std::to_string(state.else_goto)) << '\n';
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
