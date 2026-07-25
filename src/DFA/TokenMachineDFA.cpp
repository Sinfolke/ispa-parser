module DFA.TokenMachineDFA;
import corelib;

auto DFA::TokenMachineDFA::build() -> const States<SingleState> & {
    auto terminals = ast.getTerminals();

    for (auto &state : sdfa.get()) {
        for (const auto &terminal : terminals) {
            if (!state.transitions.contains(terminal)) {
                state.transitions.emplace(terminal, TransitionValue {NULL_STATE, false, false, false, NULL_STATE, NULL_STATE, NULL_STATE, false, false});
            }
        }
    }

    // move to current DFA
    for (auto &state : sdfa.get()) {
        states.get().push_back(std::move(state));
    }
    sdfa.clear();
    return states;
}
auto DFA::operator<<(std::ostream &os, const TokenMachineDFA &dfa) -> std::ostream & {
    std::size_t i = 0;
    for (const auto &state : dfa.get()) {
        os << i++ << ": \n";

        if (!state.rule_name.empty()) {
            os << "\t[rule_name] = " << corelib::text::join(state.rule_name, "::") << "\n";
        }

        // Iterate directly through Token transitions
        for (const auto &[name, transition] : state.transitions) {
            if (transition.next == NULL_STATE) continue;
            // TokenMachineDFA typically uses token names rather than chars
            if (std::holds_alternative<stdu::vector<std::string>>(name)) {
                os << "\t" << corelib::text::join(std::get<stdu::vector<std::string>>(name), "::") << " -> " << transition.next;
            } else if (std::holds_alternative<char>(name)) {
                // Fallback just in case, though unexpected for Token DFA
                os << "\t" << std::get<char>(name) << " -> " << transition.next;
            }

            // Print accept index if this transition concludes a lookahead
            if (transition.accept_index != NULL_STATE) {
                os << " [accept_index=" << transition.accept_index << "]";
            }

            os << '\n';
        }

        os << "\t[else_goto] = " << (state.else_goto == NULL_STATE ? std::string("[no]") : std::to_string(state.else_goto)) << '\n';
        os << "\t[else_goto_accept] = " << (state.else_goto_accept == NULL_STATE ? std::string("NULLSTATE") : std::to_string(state.else_goto_accept)) << '\n';
    }
    return os;
}
auto DFA::TokenMachineDFA::getType() const -> DfaType {
    return Base::getType(states);
}
auto DFA::TokenMachineDFA::clear() -> void {
    states.clear();
}