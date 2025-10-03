module DFA.TokenMachineDFA;


auto DFA::TokenMachineDFA::build() -> const States<SingleState> & {
    auto terminals = ast.getTerminals();

    for (auto &state : sdfa.get()) {
        auto next_state_for_non_existing = state.else_goto ? state.else_goto : NULL_STATE;
        for (const auto &terminal : terminals) {
            if (!state.transitions.contains(terminal)) {
                state.transitions.emplace(terminal, TransitionValue {next_state_for_non_existing, false, false, false, NULL_STATE, NULL_STATE, NULL_STATE, false, false, false});
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

auto DFA::TokenMachineDFA::getType() const -> DfaType {
    return Base::getType(states);
}
auto DFA::TokenMachineDFA::clear() -> void {
    states.clear();
}