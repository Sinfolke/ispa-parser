module LALRParser;
import AST.API;
import LRParser;
import hash;
import std;
void LALRParser::rebuildActionTable(const stdu::vector<size_t>& state_mapping) {
    ActionTable new_action_table;

    for (size_t i = 0; i < action_table.size(); ++i) {
        size_t new_state = state_mapping[i];
        for (auto& [sym, action] : action_table[i]) {
            if (action.type == Action_type::SHIFT) {
                action.state = state_mapping[action.state];
            }
            // Use new_state as the target
            new_action_table[new_state][sym] = std::move(action);
        }
    }

    action_table = std::move(new_action_table);
}


void LALRParser::rebuildGotoTable(const stdu::vector<size_t>& state_mapping) {
    GotoTable new_goto_table;

    for (size_t i = 0; i < goto_table.size(); ++i) {
        size_t new_from_state = state_mapping[i];
        for (auto& [nonterminal, next_state] : goto_table[i]) {
            size_t new_to_state = state_mapping[next_state];
            new_goto_table[new_from_state][nonterminal] = new_to_state;
        }
    }

    goto_table = std::move(new_goto_table);
}
stdu::vector<std::pair<stdu::vector<std::string>, LRParser::Action_type>> LALRParser::getActionType(const LR1Core& item, size_t state) {
    // Check if the item is in the action table
    stdu::vector<std::pair<stdu::vector<std::string>, LRParser::Action_type>> action_types;
    auto it = action_table.find(state);
    if (it != action_table.end()) {
        for (auto lookahead : item.lookahead) {
            auto action_it = it->second.find(lookahead);
            if (action_it != it->second.end()) {
                action_types.push_back({lookahead, action_it->second.type});
            }
        }
    }
    return action_types;
}

void LALRParser::build() {
    // identify merge states
    utype::unordered_map<CanonicalItem, stdu::vector<size_t>> core_to_states;
    size_t i = 0;
    for (auto item : canonical_item_set) {
        CanonicalItem core;
        for (auto& el : item) {
            core.insert(el);
        }
        core_to_states[core].push_back(i++);

    }

    // Step 2: Create merged states
    CanonicalItemSet merged_states;
    stdu::vector<size_t> state_mapping(canonical_item_set.size());
    
    for (const auto &[core, states] : core_to_states) {
        auto new_state = merged_states.size();
        merged_states.emplace_back();
        bool conflict = false;
        for (size_t s : states) {
            for (const auto& item : canonical_item_set[s]) {
                // We assume that `core` is a collection of items or states to check for conflict
                for (auto el : core) {
                    // Check if the lookahead of `item` and `el` intersect
                    for (const auto& la : item.lookahead) {
                        // Look for conflicts
                        if (el.lookahead.count(la)) {
                            // Case where both have the same lookahead, we need to check their actions
                            auto item_actions = getActionType(item, s);
                            auto el_actions = getActionType(el, s);
                            // Check if the actions are the same
                            for (const auto& [lookahead, action] : item_actions) {
                                auto it = std::find_if(el_actions.begin(), el_actions.end(), [&lookahead](const auto& pair) { return pair.first == lookahead; });
                                if (it != el_actions.end()) {
                                    // Check if the actions are different
                                    if (action != it->second) {
                                        conflict = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (!conflict) {
            for (auto old_state : states) {
                state_mapping[old_state] = new_state;
                if (old_state == states[0]) continue;
                for (auto& item : canonical_item_set[old_state]) {
                    auto& merged_items = merged_states.back();
                    
                    auto it = merged_items.find(item);
                    if (it != merged_items.end()) {
                        it->lookahead.insert(item.lookahead.begin(), item.lookahead.end());
                    } else {
                        // 👇 Add this line to ensure lookahead is computed for new item
                        merged_items.insert(item);
                    }
                }
            }
        } else {
            // ⚠️ Conflict: do not merge — assign each state its own slot
            for (auto old_state : states) {
                size_t new_state = merged_states.size();
                merged_states.push_back(canonical_item_set[old_state]);
                state_mapping[old_state] = new_state;
            }
            //cpuf::printf("Conflict in merging states %$ -> %$\n", states[0], states[1]);
        }

    }
    utype::unordered_map<size_t, size_t> compact_state_map;
    size_t compact_index = 0;
    
    for (auto& idx : state_mapping) {
        if (!compact_state_map.count(idx)) {
            compact_state_map[idx] = compact_index++;
        }
        idx = compact_state_map[idx];
    }
    
    // rebuild action table
    rebuildActionTable(state_mapping);
    rebuildGotoTable(state_mapping);
}
