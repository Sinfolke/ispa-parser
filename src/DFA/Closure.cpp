module DFA.closure;
import std;

void DFA::Closure::epsilonClosure() {
    std::queue<std::size_t> work;
    std::set<std::size_t> new_closure;
    if (closure.empty()) {
        new_closure.insert(current.begin(), current.end());
    } else {
        new_closure.insert(closure.begin(), closure.end());
    }
    for (std::size_t s : current) work.push(s);

    while (!work.empty()) {
        std::size_t current = work.front();
        work.pop();

        const auto &epsilons = nfa.getStates().at(current).epsilon_transitions;

        for (std::size_t target_state : epsilons) {
            if (!new_closure.contains(target_state)) {
                new_closure.insert(target_state);
                work.push(target_state);
            }
        }
    }
    closure.assign(new_closure.begin(), new_closure.end());
}

void DFA::Closure::move(){
    std::set<std::size_t> result;

    for (auto state_id : current) {
        const auto &state = nfa.getStates().at(state_id);
        auto it = state.transitions.find(*symbol);
        if (it != state.transitions.end()) {
            result.insert(it->second.next);  // assuming only one target per symbol
        }
    }

    closure.assign(result.begin(), result.end());
}

DFA::Closure::Closure(const NFA &nfa, const stdu::vector<std::size_t> &current) : nfa(nfa), current(current) {
    epsilonClosure();
}
DFA::Closure::Closure(const NFA &nfa, const stdu::vector<std::size_t> &current, const NFA::TransitionKey &symbol) : nfa(nfa), current(current), symbol(&symbol) {
    move();
    epsilonClosure();
};