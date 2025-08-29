module DFA.MachineDFA;
import std;

auto DFA::MachineDFA::build() -> States<SingleState> {
    for (std::size_t i = 0; i < sorted_dfa.get().size(); i++) {
        const auto &state = sorted_dfa.get().get()[i];
        auto type = sorted_dfa.getType();
    }

    return states;
}

auto DFA::MachineDFA::getStateType(const Transitions &transitions, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct, bool isToken) -> DfaType {
    return getStateType(states, transitions, dct, isToken);
}
auto DFA::MachineDFA::getType(bool isToken, const utype::unordered_map<stdu::vector<std::string>, std::size_t> *dct) const -> DfaType {
    return getType(states, isToken, dct);
}
