module NFA;
import logging;
import corelib;
import cpuf.op;
import std;
auto NFA::buildStateFragment(const AST::RuleMember &member, bool isEntry) -> StateRange {
    if (member.isNospace())
        return {NO_STATE_RANGE, NO_STATE_RANGE};
    const size_t start = states.size(), end = start + 1;
    states.emplace_back(); // start
    states.emplace_back(); // end
    if (member.isName()) {
        const auto &name = member.getName();
        if (name.isTerminal()) {
            states[start].transitions[name.name] = end;
            if (isEntry) {
                states[end].accept_index = accept_index++;
            }
            // handle quantifier
            switch (member.quantifier) {
                case '?':
                    // NUMBER -> end
                    // epsilon -> end
                    states[start].epsilon_transitions.push_back(end);
                    break;
                case '+':
                    // NUMBER -> next:
                    //  NUMBER -> this
                    //  epsilon -> end
                    auto loop_state = states.size();
                    states.emplace_back();
                    states[loop_state].transitions[name.name] = loop_state;
                    states[loop_state].epsilon_transitions.push_back(end);
                    break;
                case '*':
                    // NUMBER -> this
                    // epsilon -> end
                    states[start].transitions[name.name] = start;
                    states[start].epsilon_transitions.push_back(end);
                    break;
            }
        } else {
            size_t last = start;
            const auto &prod_rules = tree->operator[](name.name);
            for (auto &prod : prod_rules.rule_members) {
                auto fragment = buildStateFragment(prod, false);
                if (fragment.invalid())
                    continue;
                states[last].epsilon_transitions.push_back(fragment.start);
                last = fragment.end;
            }
            states[last].epsilon_transitions.push_back(end);
            if (isEntry) {
                states[last].accept_index = accept_index++;
            }
        }
    } else if (member.isOp()) {
        const auto &op = member.getOp();
        for (const auto &option : op.options) {
            auto fragment = buildStateFragment(option, false);
            if (fragment.invalid())
                continue;
            // Link entry to fragment start with epsilon
            states[start].epsilon_transitions.push_back(fragment.start);
            // Link fragment end to exit with epsilon
            states[fragment.end].epsilon_transitions.push_back(end);
            if (isEntry) {
                states[fragment.end].accept_index = accept_index++;
            }
        }
    } else if (member.isGroup()) {
        const auto &group = member.getGroup().values;
        size_t last = start;
        for (const auto &sub : group) {
            auto fragment = buildStateFragment(sub, false);
            if (fragment.invalid())
                continue;
            states[last].epsilon_transitions.push_back(fragment.start);
            last = fragment.end;
        }
        // Link final fragment to end
        states[last].epsilon_transitions.push_back(end);
        if (isEntry) {
            states[last].accept_index = accept_index++;
        }
    } else {
        throw Error("Undefined member");
    }
    // create new transition __WHITESPACE -> itself
    states[start].transitions[{"__WHITESPACE"}] = start;
    return {start, end};
}

void NFA::build() {
    if (rules != nullptr) {
        for (const auto &rule : *rules) {
            buildStateFragment(rule, true);
        }
    } else {
        buildStateFragment(*member, true);
    }
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
    os << "State {\n";
    os << "  accept_index: ";
    if (s.accept_index == NFA::NO_ACCEPT)
        os << "NO_ACCEPT";
    else
        os << s.accept_index;
    os << "\n";
    os << "  is_starting_state: " << (s.is_starting_state ? "true" : "false") << "\n";

    os << "  transitions:\n";
    if (s.transitions.empty()) {
        os << "    (none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            os << "    " << key << " -> State " << target << "\n";
        }
    }

    os << "  epsilon_transitions:\n";
    if (s.epsilon_transitions.empty()) {
        os << "    (none)\n";
    } else {
        for (size_t t : s.epsilon_transitions) {
            os << "    State " << t << "\n";
        }
    }
    os << "}\n";
    return os;
}

// Print all states in the vector
std::ostream& operator<<(std::ostream& os, const NFA& nfa) {
    for (size_t i = 0; i < nfa.getStates().size(); ++i) {
        os << "State " << i << ":\n" << nfa.getStates()[i] << "\n";
    }
    return os;
}
