module NFA;
import logging;
import corelib;
import cpuf.op;
import cpuf.printf;
import logging;
import constants;
import AST.API;
import std;

void NFA::handleTerminal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool &isEntry) {
    states[start].transitions[name] = end;
    if (isEntry && !isWhitespaceToken) {
        states[start].accept_index = accept_index++;
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
            states[start].transitions[name] = loop_state;
            states[loop_state].transitions[name] = loop_state;
            states[loop_state].epsilon_transitions.insert(end);
            break;
        } case '*': {
            // Instead of direct self-loop, use epsilon transitions
            auto loop_state = states.size();
            states.emplace_back();
            states[start].epsilon_transitions.insert(loop_state);
            states[start].epsilon_transitions.insert(end);  // skip option
            states[loop_state].epsilon_transitions.insert(end);  // exit option
            break;
        }
        default:
            break;
    }
}
void NFA::handleNonTermnal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const size_t &start, const size_t &end, bool isEntry) {
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
            states[start].epsilon_transitions.insert(inner_start);
            states[inner_end].epsilon_transitions.insert(inner_start); // loop
            states[inner_end].epsilon_transitions.insert(end);         // or exit
            break;
        }
        case '*': {
            // epsilon -> end
            // loop zero or more
            size_t loop_start = inner_start;
            size_t loop_end = inner_end;
            states[start].epsilon_transitions.insert(inner_start);  // enter
            states[start].epsilon_transitions.insert(end);          // or skip
            states[inner_end].epsilon_transitions.insert(inner_start); // loop
            states[inner_end].epsilon_transitions.insert(end);         // or exit
            break;
        }
        default:
            // normal sequence
            states[start].epsilon_transitions.insert(inner_start);
            states[inner_end].epsilon_transitions.insert(end);
            break;
    }

    if (isEntry && !isWhitespaceToken) {
        states[inner_start].accept_index = accept_index++;
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
    if (isEntry && !isWhitespaceToken) {
        states[start].accept_index = accept_index++;
    }
    switch (member.quantifier) {
        case '?':
            // Allow skipping the group entirely
            states[start].epsilon_transitions.insert(end);
            break;
        case '*':
            // Loop and allow skipping
            // Allow skipping entire group before any run
            states[start].epsilon_transitions.insert(end);
            // After completing the group, loop back to start (but not skip again)
            states[last].epsilon_transitions.insert(start);

            break;
        case '+':
            // Loop back, but no skipping
            states[last].epsilon_transitions.insert(start);
            break;
        default:
            break;
    }
}
void NFA::handleString(const AST::RuleMember &member, const std::string &str, const size_t &start, const size_t &end, bool isEntry) {
    size_t current = start;

    // Construct linear NFA for each character in the string
    for (size_t i = 0; i < str.size(); ++i) {
        size_t next = (i == str.size() - 1) ? end : states.size(); // last char points to `end`

        states.emplace_back(); // make sure enough space exists
        if (next >= states.size()) states.resize(next + 1);

        // Add transition for character
        states[current].transitions[str[i]] = next;

        current = next;
    }

    // Mark accepting state if needed
    if (isEntry && !isWhitespaceToken) {
        states[start].accept_index = accept_index++;
    }

    // Handle quantifiers
    switch (member.quantifier) {
        case '?':
            // Can skip the entire string
            states[start].epsilon_transitions.insert(end);
            break;
        case '*':
            // Skip and loop
            states[start].epsilon_transitions.insert(end); // skip
            states[end].epsilon_transitions.insert(start); // loop
            break;
        case '+':
            // Loop only
            states[end].epsilon_transitions.insert(start);
            break;
        default:
            break;
    }
}
void NFA::handleCsequence(const AST::RuleMember &member, const AST::RuleMemberCsequence &csequence, const size_t &start, const size_t &end, bool isEntry) {
    const auto &chars = csequence.characters;
    const auto &escaped = csequence.escaped;
    // Add transitions for each character from start to end
    for (char c : chars) {
        states[start].transitions[c] = end;
    }
    for (char c : escaped) {
        states[start].transitions[corelib::text::getEscapedFromChar(c)] = end;
    }
    for (auto [from, to] : csequence.diapasons) {
        for (char c = from; c <= to; ++c) {
            states[start].transitions[c] = end;
        }
    }
    // Mark accepting state if needed
    if (isEntry && !isWhitespaceToken) {
        states[end].accept_index = accept_index++;
    }
    // Quantifier handling
    switch (member.quantifier) {
        case '?':
            // Allow skipping the group
            states[start].epsilon_transitions.insert(end);
            break;
        case '*':
            // Allow skipping and looping
            // for (auto &t : states[start].transitions) {
            //     t.second = start;
            // }
            // states[start].epsilon_transitions.insert(end);
            states[end].epsilon_transitions.insert(start); // loop
            states[start].epsilon_transitions.insert(end); // skip
            break;
        case '+':
            // Allow looping only
            states[end].epsilon_transitions.insert(start);
            break;
        default:
            break;
    }
}
auto NFA::buildStateFragment(const AST::RuleMember &member, bool isEntry) -> StateRange {
    if (member.isNospace()) {
        if (!add_space_skip_places.empty())
            add_space_skip_places.pop_back();
        no_add_space_skip_next = true;
        return {NO_STATE_RANGE, NO_STATE_RANGE};
    }
    const size_t start = states.size(), end = start + 1;
    states.emplace_back(); // start
    states.emplace_back(); // end
    if (member.isName()) {
        const auto &name = member.getName();
        if (name.isTerminal()) {
            handleTerminal(member, name.name, start, end, isEntry);
        } else {
            // Check cache
            auto it = fragment_cache.find(name.name);
            if (it != fragment_cache.end()) {
                return {it->second.start, it->second.end};
            }

            if (!processing.insert(name.name).second)
                return {NO_STATE_RANGE, NO_STATE_RANGE};

            handleNonTermnal(member, name.name, start, end, isEntry);

            processing.erase(name.name);

            // Cache the constructed fragment
            fragment_cache[name.name] = {start, end};
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
            if (isEntry && !isWhitespaceToken) {
                states[fragment.start].accept_index = accept_index++;
            }
        }
    } else if (member.isGroup()) {
        handleGroup(member, member.getGroup().values, start, end, isEntry);
    } else if (member.isString()) {
        is_char_table = true;
        handleString(member, member.getString().value, start, end, isEntry);
    } else if (member.isCsequence()) {
        is_char_table = true;
        handleCsequence(member, member.getCsequence(), start, end, isEntry);
    } else if (member.isAny()) {
        states[start].any = end;
    } else {
        std::visit([](auto &m) {
            throw Error("Undefined member: {}", typeid(m).name());
        }, member.value);
    }
    // create new transition __WHITESPACE / ' ' -> itself
    if (!no_add_space_skip_next)
        add_space_skip_places.push_back(start);
    no_add_space_skip_next = false;
    return {start, end};
}
auto NFA::investigateHasNext(size_t place, char c, std::unordered_set<size_t> &visited) -> bool {
    for (const auto &[name, next] : states[place].transitions) {
        if (std::holds_alternative<char>(name)) {
            auto this_c = std::get<char>(name);
            if (this_c == c) {
                return true;
            }
        }
    }
    const auto &e_transitios = states[place].epsilon_transitions;
    return std::ranges::any_of(e_transitios.begin(), e_transitios.end(), [&](const auto &x) {
        if (visited.contains(x))
            return false;
        visited.insert(x);
        return investigateHasNext(x, c, visited);
    });
}
auto NFA::investigateHasNext(size_t place, const stdu::vector<std::string> &name, std::unordered_set<size_t> &visited) -> bool {
    for (const auto &[n, next] : states[place].transitions) {
        if (std::holds_alternative<stdu::vector<std::string>>(n)) {
            const auto &this_c = std::get<stdu::vector<std::string>>(n);
            if (this_c == name) {
                return true;
            }
        }
    }
    const auto &e_transitios = states[place].epsilon_transitions;
    return std::ranges::any_of(e_transitios.begin(), e_transitios.end(), [&](const auto &x) {
        if (visited.contains(x))
            return false;
        visited.insert(x);
        return investigateHasNext(x, name, visited);
    });
}
void NFA::addSpaceSkip() {
    size_t start = 0, end = 0;
    if (is_char_table) {
        auto [s, e] = buildStateFragment(AST::RuleMember {.quantifier = '*', .value = AST::RuleMemberCsequence {.characters = constants::whitespace_chars }}, false);
        start = s;
        end = e;
    } else {
        auto [s, e] = buildStateFragment(AST::RuleMember {.quantifier = '*', .value = AST::RuleMemberName {.name = constants::whitespace }}, false);
        start = s;
        end = e;
    }
    for (const auto &place : add_space_skip_places) {
        std::unordered_set<size_t> visited;
        if (is_char_table) {
            for (const auto c : constants::whitespace_chars) {
                states[place].epsilon_transitions.insert(start);
                states[end].epsilon_transitions.insert(place);
                // if (!investigateHasNext(place, c, visited))
                //     states[place].transitions[c] = place;
            }
        } else {
            if (!investigateHasNext(place, constants::whitespace, visited)) {
                states[place].transitions[constants::whitespace] = place;
            }
        }
    }
}

void NFA::AccessMapVisitState(size_t index, size_t accept_index, std::unordered_set<size_t>& visited) {
    // Stop if already visited with this accept_index (to prevent infinite recursion)
    if (!visited.insert(index).second)
        return;

    if (states[index].accept_index != NO_ACCEPT) {
        accept_index = states[index].accept_index;
    }
    accept_map[index] = accept_index;

    // Recurse through all transitions, including epsilon
    for (const auto &[symbol, target] : states[index].transitions) {
        AccessMapVisitState(target, accept_index, visited);
    }
    for (const auto &e : states[index].epsilon_transitions) {
        AccessMapVisitState(e + 1, accept_index, visited);
    }
}
void NFA::buildAcceptMap() {
    accept_map.clear();
    for (size_t i = 0; i < states.size(); ++i) {
        if (states[i].accept_index != NO_ACCEPT) {
            std::unordered_set<size_t> local_visited;
            AccessMapVisitState(i, states[i].accept_index, local_visited);
        } else if (!accept_map.contains(i)) {
            accept_map[i] = NO_ACCEPT;
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
    if (!isWhitespaceToken) {
        addSpaceSkip();;
    }
    buildAcceptMap();

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
            std::visit([&os, &target](auto &key) {
                if constexpr (std::is_same_v<std::decay_t<decltype(key)>, char>) {
                    os << "\t '" << corelib::text::getEscapedAsStr(key, false) << "' -> State ";
                } else {
                    os << "\t '" << key << "' -> State ";
                }
            }, key);
            os << target << '\n';
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
