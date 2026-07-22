module NFA;
import logging;
import corelib;
import cpuf.op;
import cpuf.printf;
import logging;
import constants;
import AST.API;
import LLIR.RuleBuilder;
import std;

void NFA::handleTerminal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const std::size_t &start, const std::size_t &end, bool &isLastMember, bool addStoreActions) {
    states[start].transitions[name] = {end};
    if (addStoreActions && !member.prefix.empty()) {
        states[start].transitions[name].new_cst_node = true;
        states[start].transitions[name].new_member = true;
        cst_node_close_propagate.push_back(end);
    }
    if (isLastMember && !isWhitespaceToken) {
        states[start].accept_index = accept_index++;
        states[start].last = true;
    }
    // handle quantifier
    switch (member.quantifier) {
        case '?':
            // NUMBER -> end
            // epsilon -> end
            states[start].epsilon_transitions.insert(end);
            states[start].optional = true;
            break;
        case '+': {
            // NUMBER -> next:
            //  NUMBER -> this
            //  epsilon -> end
            auto loop_state = states.size();
            states.emplace_back();
            states[start].transitions[name].next = loop_state;
            states[loop_state].transitions[name] = {loop_state};
            if (addStoreActions) {
                states[loop_state].transitions[name].new_cst_node = true;
            }
            states[loop_state].epsilon_transitions.insert(end);

            states[loop_state].optional = true;
            break;
        } case '*': {
            auto loop_state = states.size();
            states.emplace_back();
            states[start].transitions[name].next = loop_state;
            states[loop_state].transitions[name] = {loop_state};
            if (addStoreActions) {
                states[loop_state].transitions[name].new_cst_node = true;
            }
            states[loop_state].epsilon_transitions.insert(end);

            states[start].optional = true;
            states[loop_state].optional = true;
            break;
        }
        default:
            break;
    }
}

void NFA::handleNonTermnal(const AST::RuleMember &member, const stdu::vector<std::string> &name, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions) {
    // NO STORE ACTIONS IN THIS FUNCTION AS IT ONLY MEET FOR DECISTION LOOKUP NOT LEXING
    std::size_t inner_start = states.size();
    std::size_t inner_end = inner_start + 1;
    states.emplace_back(); // inner start
    states.emplace_back(); // inner end
    std::size_t last = inner_start;

    const auto &prod_rules = tree[name];
    for (const auto &prod : prod_rules.rule_members) {
        auto fragment = buildStateFragment(prod, false, addStoreActions);
        if (fragment.invalid())
            continue;
        states[last].epsilon_transitions.insert(fragment.start);
        last = fragment.end;
    }
    states[last].epsilon_transitions.insert(inner_end);
    // now handle quantifier
    switch (member.quantifier) {
        case '?':
            states[start].epsilon_transitions.insert(inner_start);
            states[start].epsilon_transitions.insert(end);
            states[inner_end].epsilon_transitions.insert(end);

            states[start].optional = true;
            break;
        case '+': {
            states[start].epsilon_transitions.insert(inner_start);
            states[inner_end].epsilon_transitions.insert(inner_start); // loop
            states[inner_end].epsilon_transitions.insert(end);         // or exit

            states[inner_start].optional = true;
            break;
        }
        case '*': {
            states[start].epsilon_transitions.insert(inner_start);  // enter
            states[start].epsilon_transitions.insert(end);          // or skip
            states[inner_end].epsilon_transitions.insert(inner_start); // loop
            states[inner_end].epsilon_transitions.insert(end);         // or exit

            states[start].optional = true;
            states[inner_start].optional = true;
            break;
        }
        default:
            states[start].epsilon_transitions.insert(inner_start);
            states[inner_end].epsilon_transitions.insert(end);
            break;
    }

    if (isLastMember) {
        states[inner_start].accept_index = accept_index++;
        states[inner_start].last = true;
    }
    if (!states[inner_start].last && !states[inner_start].optional)
        return;
    auto states_to_propagate_last = getStatesToPropagate(inner_start);
    for (const auto s : states_to_propagate_last) {
        states[s].last = states[inner_start].last;
        states[s].optional = states[inner_start].optional;
    }
}

void NFA::handleGroup(const AST::RuleMember &member, const stdu::vector<AST::RuleMember> &group, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions) {
    std::size_t last = start;
    bool was_storing_group = store_entire_group;
    store_entire_group = true;

    std::size_t group_entry = NULL_STATE;

    for (const auto &sub : group) {
        auto fragment = buildStateFragment(sub, false, addStoreActions);
        if (fragment.invalid())
            continue;

        if (group_entry == NULL_STATE) {
            group_entry = fragment.start; // Capture first inner state
        }

        states[last].epsilon_transitions.insert(fragment.start);
        last = fragment.end;
    }
    store_entire_group = was_storing_group;

    // Link final fragment to end
    states[last].epsilon_transitions.insert(end);

    // Keep accept_index on start for early path decision lookup
    if (isLastMember && !isWhitespaceToken) {
        states[start].accept_index = accept_index++;
        states[start].last = true;
    }

    // Loop back to group_entry (inner content), NOT start!
    // This prevents re-entering the whitespace-skip logic on loop iterations.
    std::size_t loop_target = (group_entry != NULL_STATE) ? group_entry : start;

    switch (member.quantifier) {
        case '?':
            states[start].epsilon_transitions.insert(end);
            states[start].optional = true;
            break;
        case '+':
            states[last].epsilon_transitions.insert(loop_target); // Loop inner content
            states[last].epsilon_transitions.insert(end);         // Allow exit to accept state
            break;
        case '*':
            states[start].epsilon_transitions.insert(end);         // Skip group
            states[last].epsilon_transitions.insert(loop_target); // Loop inner content
            states[last].epsilon_transitions.insert(end);         // Allow exit to accept state
            states[start].optional = true;
            break;
        default:
            break;
    }

    // Capture group actions
    if (addStoreActions && group_entry != NULL_STATE) {
        std::size_t current_group = group_count++;
        auto open_states = getStatesToPropagate(group_entry);
        open_states.insert(group_entry);

        for (const auto s : open_states) {
            for (auto &t : states[s].transitions) {
                t.second.new_group = current_group;
            }
        }
        group_close_propagate.emplace_back(end, current_group);
    }

    if (!states[start].last && !states[start].optional)
        return;

    auto states_to_propagate_last = getStatesToPropagate(start);
    for (const auto s : states_to_propagate_last) {
        states[s].last = states[start].last;
        states[s].optional = states[start].optional;
    }
}

void NFA::handleString(const AST::RuleMember &member, const std::string &str, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions) {
    constexpr auto NO_NEXT_AFTER = std::numeric_limits<std::size_t>::max();
    std::size_t current = start;
    std::size_t next_after = NO_NEXT_AFTER;
    std::size_t inner_end = states.size();
    states.emplace_back();
    states[inner_end].epsilon_transitions.insert(end);
    // Construct linear NFA for each character in the string
    for (std::size_t i = 0; i < str.size(); ++i) {
        std::size_t next;
        if (i == str.size() - 1) {
            next = inner_end; // last char
        } else {
            next = states.size();
            states.emplace_back();
        }
        auto &t = states[current].transitions[str[i]];
        t.next = next;
        if ((addStoreActions && !member.prefix.empty()) || store_entire_group) {
            t.new_member = !i;
            t.new_cst_node = !i;

            if (!i)
                next_after = next;
        }
        current = next;
    }
    if (addStoreActions)
        cst_node_close_propagate.push_back(end);
    // Mark accepting state if needed
    if (isLastMember && !isWhitespaceToken) {
        states[start].accept_index = accept_index++;
        states[start].last = true;
    }

    // Handle quantifiers
    switch (member.quantifier) {
        case '?':
            states[start].epsilon_transitions.insert(end);
            states[start].optional = true;
            break;
        case '+':
            if (next_after != NO_NEXT_AFTER) {
                states[inner_end].transitions[str[0]] = {next_after, true, false};
                states[inner_end].epsilon_transitions.insert(end);
            } else {
                states[end].epsilon_transitions.insert(start);
            }
            break;
        case '*':
            states[start].epsilon_transitions.insert(end);
            if (next_after != NO_NEXT_AFTER) {
                states[inner_end].transitions[str[0]] = {next_after, true, false};
                states[inner_end].epsilon_transitions.insert(end);
            } else {
                states[end].epsilon_transitions.insert(start);
            }
            states[start].optional = true;
            break;
        default:
            break;
    }
    if (!states[start].last && !states[start].optional)
        return;
    auto states_to_propagate_last = getStatesToPropagate(start);
    for (const auto s : states_to_propagate_last) {
        states[s].last = states[start].last;
        states[s].optional = states[start].optional;
    }
}

void NFA::handleCsequence(const AST::RuleMember &member, const AST::RuleMemberCsequence &csequence, const std::size_t &start, const std::size_t &end, bool isLastMember, bool addStoreActions) {
    const auto &chars = csequence.characters;
    const auto &escaped = csequence.escaped;
    if (addStoreActions)
        cst_node_close_propagate.push_back(end);
    if (csequence.negative) {
        constexpr auto max = std::numeric_limits<unsigned char>::max();
        std::bitset<max + 1> prohibited;
        for (char c : chars) prohibited.set(static_cast<unsigned char>(c));
        for (char c : escaped) prohibited.set(static_cast<unsigned char>(corelib::text::getEscapedFromChar(c)));
        for (auto [from, to] : csequence.diapasons) {
            for (char c = from; c <= to; ++c)
                prohibited.set(static_cast<unsigned char>(c));
        }
        for (unsigned char c = std::numeric_limits<char>::min();; ++c) {
            if (!prohibited.test(c)) {
                auto &t = states[start].transitions[static_cast<char>(c)];
                t = {end};
                if ((addStoreActions && !member.prefix.empty()) || store_entire_group) {
                    t.new_cst_node = true;
                    t.new_member = true;
                }
            }
            if (c == max)
                break;
        }
    } else {
        for (char c : chars) {
            auto &t = states[start].transitions[c];
            t.next = end;
            if ((addStoreActions && !member.prefix.empty()) || store_entire_group) {
                t.new_cst_node = true;
                t.new_member = true;
            }
        }
        for (char c : escaped) {
            auto &t = states[start].transitions[corelib::text::getEscapedFromChar(c)];
            t.next = end;
            if ((addStoreActions && !member.prefix.empty()) || store_entire_group) {
                t.new_cst_node = true;
                t.new_member = true;
            }
        }
        for (auto [from, to] : csequence.diapasons) {
            for (char c = from; c <= to; ++c) {
                auto &t = states[start].transitions[c];
                t.next = end;
                if ((addStoreActions && !member.prefix.empty()) || store_entire_group) {
                    t.new_cst_node = true;
                    t.new_member = true;
                }
            }
        }
    }
    // Mark accepting state if needed
    if (isLastMember && !isWhitespaceToken) {
        states[end].accept_index = accept_index++;
        states[start].last = true;
    }
    // Quantifier handling
    auto loop_state = states.size();
    switch (member.quantifier) {
        case '?':
            states[start].epsilon_transitions.insert(end);
            states[start].optional = true;
            break;
        case '+': {
            for (auto &t : states[start].transitions) {
                t.second.next = loop_state;
            }
            auto first = states[start];
            states.push_back(first);
            for (auto &t : states[loop_state].transitions) {
                t.second.new_member = false;
                t.second.new_cst_node = false;
                t.second.close_cst_node = false;
            }
            states[loop_state].epsilon_transitions.insert(end);
            states[loop_state].optional = true;

            // Close CST node when exiting the loop fragment to `end`
            if (addStoreActions)
                cst_node_close_propagate.push_back(end);
            break;
        }
        case '*': {
            for (auto &t : states[start].transitions) {
                t.second.next = loop_state;
            }
            auto first = states[start];
            states.push_back(first);
            for (auto &t : states[loop_state].transitions) {
                t.second.new_member = false;
                t.second.new_cst_node = false;
                t.second.close_cst_node = false;
            }
            states[start].epsilon_transitions.insert(end);
            states[loop_state].epsilon_transitions.insert(end);

            states[start].optional = true;
            states[loop_state].optional = true;

            // Close CST node when exiting the loop fragment to `end`
            if (addStoreActions)
                cst_node_close_propagate.push_back(end);
            break;
        }
        default:
            if (addStoreActions)
                cst_node_close_propagate.push_back(end);
            break;
    }
}

auto NFA::buildStateFragment(const AST::RuleMember &member, bool isLastMember, bool addStoreActions) -> StateRange {
    if (member.isNospace()) {
        no_add_space_skip_next = true;
        return {NULL_STATE, NULL_STATE};
    }
    const std::size_t start = states.size(), end = start + 1;
    states.emplace_back(); // start
    states.emplace_back(); // end
    if (member.isName()) {
        const auto &name = member.getName();
        if (name.isTerminal()) {
            handleTerminal(member, name.name, start, end, isLastMember, addStoreActions);
        } else {
            auto it = fragment_cache.find(name.name);
            if (it != fragment_cache.end()) {
                return {it->second.start, it->second.end};
            }

            if (!processing.insert(name.name).second)
                return {NULL_STATE, NULL_STATE};

            handleNonTermnal(member, name.name, start, end, isLastMember, addStoreActions);

            processing.erase(name.name);

            fragment_cache[name.name] = {start, end};
        }
    } else if (member.isOp()) {
        const auto &op = member.getOp();
        auto cached_no_space_skip = no_add_space_skip_next;
        auto cached_group_count = group_count;
        bool was_group = false;

        // FIX 1: Set store_entire_group if the outer Op member carries a capture prefix (@)[cite: 7]
        bool was_storing_group = store_entire_group;
        if (!member.prefix.empty()) {
            store_entire_group = true;
        }

        for (const auto &option : op.options) {
            no_add_space_skip_next = cached_no_space_skip;
            group_count = cached_group_count;
            if (option.isGroup())
                was_group = true;
            auto fragment = buildStateFragment(option, false, addStoreActions);
            if (fragment.invalid())
                continue;
            // Link entry to fragment start with epsilon
            states[start].epsilon_transitions.insert(fragment.start);
            states[fragment.end].epsilon_transitions.insert(end);
            if (isLastMember && !isWhitespaceToken) {
                states[fragment.start].accept_index = accept_index++;
                states[fragment.start].last = true;
            }
            if (!states[fragment.start].last)
                continue;
            auto states_to_propagate_last = getStatesToPropagate(start);
            for (const auto s : states_to_propagate_last) {
                states[s].last = states[start].last;
            }
        }

        store_entire_group = was_storing_group;

        if (was_group && cached_group_count == group_count) {
            group_count++;
        }
    } else if (member.isGroup()) {
        handleGroup(member, member.getGroup().values, start, end, isLastMember, addStoreActions);
    } else if (member.isString()) {
        handleString(member, member.getString().value, start, end, isLastMember, addStoreActions);
    } else if (member.isCsequence()) {
        handleCsequence(member, member.getCsequence(), start, end, isLastMember, addStoreActions);
    } else if (member.isAny()) {
        for (unsigned char c = std::numeric_limits<unsigned char>::min(); c != std::numeric_limits<unsigned char>::max(); c++) {
            states[start].transitions[static_cast<char>(c)] = {end, true, true};
        }
        states[start].transitions[static_cast<char>(std::numeric_limits<unsigned char>::max())] = {end, true, true};
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

void NFA::getStatesToPropagate(std::size_t state_id, std::unordered_set<std::size_t> &result) {
    const auto &state = states[state_id];
    if (state.transitions.empty() && state.epsilon_transitions.empty())
        return;
    result.insert(state_id);
    for (const auto &epsilon : state.epsilon_transitions) {
        if (result.contains(epsilon))
            continue;
        getStatesToPropagate(epsilon, result);
    }
}

auto NFA::getStatesToPropagate(std::size_t id) -> std::unordered_set<std::size_t> {
    std::unordered_set<std::size_t> result;
    getStatesToPropagate(id, result);
    return result;
}

auto NFA::investigateHasNext(std::size_t place, char c, std::unordered_set<std::size_t> &visited) -> bool {
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

auto NFA::investigateHasNext(std::size_t place, const stdu::vector<std::string> &name, std::unordered_set<std::size_t> &visited) -> bool {
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
    for (const auto &place : add_space_skip_places) {
        std::unordered_set<std::size_t> visited;
        auto &state = states[place];
        for (const auto c : constants::whitespace_chars) {
            if (!investigateHasNext(place, c, visited)) {
                state.transitions[c] = {place};
            }
        }
    }
}

void NFA::acceptMapVisitState(std::size_t index, std::size_t accept_index, std::unordered_set<std::size_t>& visited) {
    if (!visited.insert(index).second)
        return;

    if (states[index].accept_index != NULL_STATE) {
        accept_index = states[index].accept_index;
    }
    accept_map[index] = accept_index;

    for (const auto &[symbol, target] : states[index].transitions) {
        acceptMapVisitState(target.next, accept_index, visited);
    }
    for (const auto &e : states[index].epsilon_transitions) {
        acceptMapVisitState(e + 1, accept_index, visited);
    }
}

void NFA::buildAcceptMap() {
    accept_map.clear();
    for (std::size_t i = 0; i < states.size(); ++i) {
        if (states[i].accept_index != NULL_STATE) {
            std::unordered_set<std::size_t> local_visited;
            acceptMapVisitState(i, states[i].accept_index, local_visited);
        } else if (!accept_map.contains(i)) {
            accept_map[i] = NULL_STATE;
        }
    }
}

void NFA::generateTemplatedDataBlockFromSingleRule(const AST::RuleMember &mem, TemplatedDataBlock &templated_data_block, std::size_t &prefix_index, std::size_t &index, std::size_t &group_index) {
    if (!mem.prefix.empty()) {
        if (dtb->getTemplatedDataBlock().names.size() <= prefix_index) {
            return;
        }
        const auto &name = dtb->getTemplatedDataBlock().names[prefix_index++];
        if (mem.isGroup()) {
            templated_data_block.emplace(name, TemplatedDataBlockValue {.type = StoreCstNode::CST_GROUP, .cst_index = group_index++, .AST = &mem});
        } else if (mem.isOp()) {
            templated_data_block.emplace(name, TemplatedDataBlockValue {.type = StoreCstNode::CST_CONDITION, .cst_index = index++, .AST = &mem});
        } else {
            templated_data_block.emplace(name, TemplatedDataBlockValue {.type = StoreCstNode::CST_NODE, .cst_index = index++, .AST = &mem});
        }
    }

    if (mem.isGroup()) {
        generateTemplatedDataBlockFromRules(mem.getGroup().values, templated_data_block, prefix_index, index, group_index);
    } else if (mem.isOp()) {
        std::size_t start_prefix_index = prefix_index;
        std::size_t max_prefix_index = prefix_index;
        std::size_t start_index = index;
        std::size_t max_index = index;
        std::size_t start_group_index = group_index;
        std::size_t max_group_index = group_index;

        for (const auto &opt : mem.getOp().options) {
            std::size_t current_prefix_index = start_prefix_index;
            std::size_t current_index = start_index;
            std::size_t current_group_index = start_group_index;

            generateTemplatedDataBlockFromSingleRule(opt, templated_data_block, current_prefix_index, current_index, current_group_index);

            max_prefix_index = std::max(max_prefix_index, current_prefix_index);
            max_index = std::max(max_index, current_index);
            max_group_index = std::max(max_group_index, current_group_index);
        }
        prefix_index = max_prefix_index;
        index = max_index;
        group_index = max_group_index;
    }
}

void NFA::generateTemplatedDataBlockFromRules(const stdu::vector<AST::RuleMember> &rules, TemplatedDataBlock &templated_data_block, std::size_t &prefix_index, std::size_t &index, std::size_t &group_index) {
    for (const auto &mem : rules) {
        generateTemplatedDataBlockFromSingleRule(mem, templated_data_block, prefix_index, index, group_index);
    }
}

void NFA::generateSingleDataBlockFromRules(const stdu::vector<AST::RuleMember> &rules, TemplatedDataBlockValue &single_data_block, bool &isAlreadyConstructed) {
    if (isAlreadyConstructed)
        return;
    for (const auto &mem : rules) {
        if (!mem.prefix.empty()) {
            single_data_block = {
                .type = mem.isGroup() ? StoreCstNode::CST_GROUP : mem.isOp() ? StoreCstNode::CST_CONDITION : StoreCstNode::CST_NODE,
                .cst_index = 0,
                .AST = &mem,
            };
            isAlreadyConstructed = true;
            return;
        }
        if (mem.isGroup()) {
            generateSingleDataBlockFromRules(mem.getGroup().values, single_data_block, isAlreadyConstructed);
            if (isAlreadyConstructed)
                return;
        } else if (mem.isOp()) {
            generateSingleDataBlockFromRules(mem.getOp().options, single_data_block, isAlreadyConstructed);
            if (isAlreadyConstructed)
                return;
        }
    };
}

void NFA::build(bool addStoreActions) {
    if (isWhitespaceToken)
        addStoreActions = false;
    std::size_t last_state;
    if (rules != nullptr) {
        for (auto it = rules->begin(); it != rules->end() - 1; ++it) {
            auto [start, end] = buildStateFragment(*it, false, addStoreActions);
            if (end != NULL_STATE)
                states[end].epsilon_transitions.insert(states.size());
        }
        auto [start, end] = buildStateFragment(rules->back(), true, addStoreActions);
        if (states.empty()) {
            throw Error("NFA cannot be empty");
        }
        last_state = end;
    } else {
        last_state = buildStateFragment(*member, true, addStoreActions).end;
    }
    if (addStoreActions) {
        if (dtb == nullptr)
            nfadtb = std::monostate {};
        else if (dtb->isTemplatedDataBlock()) {
            TemplatedDataBlock templated_data_block;
            std::size_t prefix_index = 0;
            std::size_t index = 0;
            std::size_t group_index = 0;
            generateTemplatedDataBlockFromRules(*rules, templated_data_block, prefix_index, index, group_index);
            nfadtb = templated_data_block;
        } else if (dtb->isRegularDataBlock()) {
            TemplatedDataBlockValue single_value_data_block;
            bool isAlreadyConstructed = false;
            generateSingleDataBlockFromRules(*rules, single_value_data_block, isAlreadyConstructed);
            nfadtb = single_value_data_block;
        } else {
            nfadtb = std::monostate {};
        }
        states[last_state].rule_name = name_;
        states[last_state].dtb = nfadtb;
    }
    for (const auto &el : group_close_propagate) {
        auto propagate_states = getStatesToPropagate(el.first);
        for (const auto state_id : propagate_states) {
            auto &state = states[state_id];
            for (auto &t : state.transitions) {
                t.second.group_close = el.second;
            }
        }
    }
    for (const auto id : cst_node_close_propagate) {
        auto propagate_states = getStatesToPropagate(id);
        for (const auto state_id : propagate_states) {
            auto &state = states[state_id];
            for (auto &t : state.transitions) {
                // DO NOT set close_cst_node if this transition is also opening a new CST node!
                if (!t.second.new_cst_node) {
                    t.second.close_cst_node = true;
                }
            }
        }
    }
    if (!isWhitespaceToken) {
        addSpaceSkip();
    }
    buildAcceptMap();
}

std::ostream& operator<<(std::ostream& os, const NFA::state& s) {
    if (s.transitions.empty()) {
        os << "\t(none)\n";
    } else {
        for (const auto& [key, target] : s.transitions) {
            std::visit([&os](auto &key) {
                if constexpr (std::is_same_v<std::decay_t<decltype(key)>, char>) {
                    os << "\t '" << corelib::text::getEscapedAsStr(key, false) << "' -> State ";
                } else {
                    os << "\t '" << key << "' -> State ";
                }
            }, key);
            os << '(' << target.next << ')';
            if (target.new_cst_node)
                os << " [new_cst_node]";
            if (target.new_member) {
                os << " [new_member]";
            }
            if (target.close_cst_node) {
                os << " [close_cst_node]";
            }
            if (target.new_group != NFA::NULL_STATE) {
                os << " [new_group]";
            }
            if (target.group_close != NFA::NULL_STATE) {
                os << " [group_close]";
            }
            os << '\n';
        }
    }

    os << "\te -> ";
    if (s.epsilon_transitions.empty()) {
        os << "(none)\n";
    } else {
        for (std::size_t t : s.epsilon_transitions) {
            os << t << ", ";
        }
    }
    if (s.accept_index != NFA::NULL_STATE) {
        os << "\n\taccept -> " << s.accept_index << "\n";
    }
    if (!s.rule_name.empty()) {
        os << "\tdata: \n";
        os << "\t\t[name]: " << s.rule_name << "\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const NFA& nfa) {
    for (std::size_t i = 0; i < nfa.getStates().size(); ++i) {
        os << "State " << i << ":\n" << nfa.getStates()[i] << "\n";
    }
    return os;
}