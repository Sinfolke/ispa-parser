module NFA;
import logging;
import corelib;
import cpuf.op;
import cpuf.printf;
import std;
void NFA::handleTerminal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool &isEntry) {
    states[start].transitions[name] = end;
    if (isEntry) {
        states[end].accept_index = accept_index++;
    }
    // handle quantifier
    switch (member.quantifier) {
        case '?':
            // NUMBER -> end
            // epsilon -> end
            states[start].epsilon_transitions.insert(end);
            break;
        case '+': {
            // NUMBER -> next:
            //  NUMBER -> this
            //  epsilon -> end
            auto loop_state = states.size();
            states.emplace_back();
            states[loop_state].transitions[name] = loop_state;
            states[loop_state].epsilon_transitions.insert(end);
            break;
        } case '*':
            // NUMBER -> this
            // epsilon -> end
            states[start].transitions[name] = start;
            states[start].epsilon_transitions.insert(end);
            break;
        default:
            break;
    }
}
void NFA::handleNonTermnal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool isEntry) {
    processing.insert(name);
    size_t inner_start = states.size();
    size_t inner_end = inner_start + 1;
    states.emplace_back(); // inner start
    states.emplace_back(); // inner end
    size_t last = inner_start;

    const auto &prod_rules = tree->operator[](name);
    for (auto &prod : prod_rules.rule_members) {
        auto fragment = buildStateFragment(prod, false);
        if (fragment.invalid())
            continue;
        states[last].epsilon_transitions.insert(fragment.start);
        last = fragment.end;
    }
    states[last].epsilon_transitions.insert(inner_end);
    // now handle quantifier
    switch (member.quantifier) {
        case '?':
            // epsilon -> end
            // fragment -> end
            states[start].epsilon_transitions.insert(inner_start);
            states[start].epsilon_transitions.insert(end);
            states[inner_end].epsilon_transitions.insert(end);
            break;
        case '+': {
            // loop at end
            size_t loop_start = inner_start;
            size_t loop_end = inner_end;
            states[start].epsilon_transitions.insert(loop_start);
            states[loop_end].epsilon_transitions.insert(loop_start);
            states[loop_end].epsilon_transitions.insert(end);
            break;
        }
        case '*': {
            // epsilon -> end
            // loop zero or more
            size_t loop_start = inner_start;
            size_t loop_end = inner_end;
            states[start].epsilon_transitions.insert(loop_start);
            states[start].epsilon_transitions.insert(end);
            states[loop_end].epsilon_transitions.insert(loop_start);
            states[loop_end].epsilon_transitions.insert(end);
            break;
        }
        default:
            // normal sequence
            states[start].epsilon_transitions.insert(inner_start);
            states[inner_end].epsilon_transitions.insert(end);
            break;
    }

    if (isEntry) {
        states[inner_end].accept_index = accept_index++;
    }
}
void NFA::handleGroup(const AST::RuleMember &member, const stdu::vector<AST::RuleMember> &group, const size_t &start, const size_t &end, bool isEntry) {
    size_t last = start;
    for (const auto &sub : group) {
        auto fragment = buildStateFragment(sub, false);
        if (fragment.invalid())
            continue;
        states[last].epsilon_transitions.insert(fragment.start);
        last = fragment.end;
    }
    // Link final fragment to end
    states[last].epsilon_transitions.insert(end);
    if (isEntry) {
        cpuf::printf("registering accept state for state \"{}\"", states[last]);
        states[last].accept_index = accept_index++;
    }
    switch (member.quantifier) {
        case '?':
            // Allow skipping the group entirely
            states[start].epsilon_transitions.insert(end);
            break;
        case '*':
            // Loop and allow skipping
            states[last].epsilon_transitions.insert(start); // loop back
            states[start].epsilon_transitions.insert(end);  // skip
            break;
        case '+':
            // Loop back, but no skipping
            states[last].epsilon_transitions.insert(start);
            break;
        default:
            break;
    }
}

auto NFA::buildStateFragment(const AST::RuleMember &member, bool isEntry) -> StateRange {
    if (member.isNospace())
        return {NO_STATE_RANGE, NO_STATE_RANGE};
    const size_t start = states.size(), end = start + 1;
    states.emplace_back(); // start
    states.emplace_back(); // end
    if (member.isName()) {
        const auto &name = member.getName();
        if (name.isTerminal()) {
            handleTerminal(member, name.name, start, end, isEntry);
        } else {
            if (processing.contains(name.name))
                return {NO_STATE_RANGE, NO_STATE_RANGE};
            processing.insert(name.name);
            handleNonTermnal(member, name.name, start, end, isEntry);
        }
    } else if (member.isOp()) {
        const auto &op = member.getOp();
        for (const auto &option : op.options) {
            auto fragment = buildStateFragment(option, false);
            if (fragment.invalid())
                continue;
            // Link entry to fragment start with epsilon
            states[start].epsilon_transitions.insert(fragment.start);
            states[fragment.end].epsilon_transitions.insert(end);
            if (isEntry) {
                states[fragment.start].accept_index = accept_index++;
            }
        }
    } else if (member.isGroup()) {
        handleGroup(member, member.getGroup().values, start, end, isEntry);
    } else {
        throw Error("Undefined member");
    }
    // create new transition __WHITESPACE -> itself
    states[start].transitions[{"__WHITESPACE"}] = start;
    return {start, end};
}
void NFA::removeDeadStates() {
    for (auto it = states.begin(); it != states.end(); /* no increment here */) {
        const auto &state = *it;
        if (state.accept_index == NO_ACCEPT && state.transitions.empty() && state.epsilon_transitions.empty()) {
            it = states.erase(it); // erase returns next valid iterator
        } else {
            ++it;
        }
    }
}

void NFA::build() {
    if (rules != nullptr) {
        for (auto it = rules->begin(); it != rules->end() - 1; ++it) {
            buildStateFragment(*it, false);
        }
        // register one accept state for the last state in rule sequence
        buildStateFragment(rules->back(), true);
    } else {
        buildStateFragment(*member, true);
    }
    //removeDeadStates();
}
std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec) {
    os << '"';
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) os << "::";
        os << vec[i];
    }
    os << '"';
    return os;
}
// Print a single state
std::ostream& operator<<(std::ostream& os, const NFA::state& s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            os << "\t" << key << " -> State " << target << "\n";
        }
    }

    os << "\te -> ";
    if (s.epsilon_transitions.empty()) {
        os << "(none)\n";
    } else {
        for (size_t t : s.epsilon_transitions) {
            os << t << ", ";
        }
    }
    if (s.accept_index != NFA::NO_ACCEPT) {
        os << "\n\taccept -> " << s.accept_index << "\n";
    }
    return os;
}

// Print all states in the vector
std::ostream& operator<<(std::ostream& os, const NFA& nfa) {
    for (size_t i = 0; i < nfa.getStates().size(); ++i) {
        os << "State " << i << ":\n" << nfa.getStates()[i] << "\n";
    }
    return os;
}
