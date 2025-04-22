#include <LALRParser.h>
std::set<std::vector<std::string>> LALRParser::compute_first_sequence(const std::vector<rule_other>& beta, const std::set<std::vector<std::string>>& la) {
    std::set<std::vector<std::string>> result;
    bool epsilon_in_all = true;

    for (const auto& sym : beta) {
        const auto& f = first[sym.fullname];

        std::set<std::vector<std::string>> temp;
        for (const auto& prefix : result.empty() ? std::set<std::vector<std::string>>{{}} : result) {
            for (const auto& x : f) {
                if (x == std::vector<std::string>{"ε"}) continue;
                auto next = prefix;
                next.insert(next.end(), x.begin(), x.end());
                temp.insert(std::move(next));
            }
        }
        result = std::move(temp);

        if (!f.count({"ε"})) {
            epsilon_in_all = false;
            break;
        }
    }

    if (epsilon_in_all) {
        for (const auto& prefix : result) {
            for (const auto& x : la) {
                auto next = prefix;
                next.insert(next.end(), x.begin(), x.end());
                result.insert(std::move(next));
            }
        }
    }

    return result;
}
void LALRParser::build() {
    LRParser::prepare(); // Standard LR preparation
    LRParser::buildTable(); // Build the initial LR table
    
    // Step 1: Identify mergeable states (same LR(0) core)
    std::unordered_map<std::unordered_set<LR0Core>, std::vector<size_t>> core_to_states;
    for (size_t i = 0; i < canonical_item_set.size(); ++i) {
        std::unordered_set<LR0Core> core;
        for (const auto& item : canonical_item_set[i]) {
            core.insert({item.lhs, item.rhs, item.dot_pos});
        }
        core_to_states[core].push_back(i);
    }

    // Step 2: Create merged states
    CanonicalItemSet merged_states;
    std::vector<size_t> state_mapping(canonical_item_set.size());
    
    for (const auto& [core, states] : core_to_states) {
        size_t new_state = merged_states.size();
        merged_states.emplace_back();
        
        for (size_t old_state : states) {
            state_mapping[old_state] = new_state;
            for (const auto& item : canonical_item_set[old_state]) {
                auto& merged_items = merged_states.back();
                auto it = std::find(merged_items.begin(), merged_items.end(), item);
                
                if (it != merged_items.end()) {
                    it->lookahead.insert(item.lookahead.begin(), item.lookahead.end());
                } else {
                    // 👇 Add this line to ensure lookahead is computed for new item
                    merged_items.insert(item);
                }
            }
        }
    }
    

    // Step 3: Perform lookahead propagation
    bool changed;
    do {
        changed = false;
        
        // First build a mapping of all kernel items to their states
        std::map<LR0Core, std::vector<std::pair<size_t, LR1Core*>>> item_to_state;
        for (size_t state_id = 0; state_id < merged_states.size(); ++state_id) {
            for (auto& item : merged_states[state_id]) {
                LR0Core core{item.lhs, item.rhs, item.dot_pos};
                item_to_state[core].push_back(std::pair<size_t, LR1Core*> {state_id, const_cast<LR1Core*>(&item)});
            }
        }


        // Then propagate lookaheads
        for (size_t state_id = 0; state_id < merged_states.size(); ++state_id) {
            for (auto& item : merged_states[state_id]) {
                if (item.dot_pos >= item.rhs.size()) continue;  // Skip completed items
                
                auto next_sym = item.rhs[item.dot_pos];
                if (!corelib::text::isUpper(next_sym.name)) continue;  // Only propagate through non-terminals

                // Compute lookaheads to propagate (FIRST(βa) where item is [A→α·Bβ, a])
                std::set<std::vector<std::string>> propagation_la;
                
                // Case 1: β exists (β is not empty)
                if (item.dot_pos + 1 < item.rhs.size()) {
                    std::vector<rule_other> beta(item.rhs.begin() + item.dot_pos + 1, item.rhs.end());
                    auto propagation_la = compute_first_sequence(beta, item.lookahead);
                    
                }
                // Case 2: β is empty (B is last symbol)
                else {
                    propagation_la = item.lookahead;
                }
                auto prod = initial_item_set.find(next_sym.fullname);
                if (prod == initial_item_set.end()) continue;  // No productions for this non-terminal
                const auto& productions = prod->second;
                for (const auto& prod : productions) {
                    // Create successor core [B→·γ]
                    LR0Core successor_core;
                    successor_core.lhs = next_sym;
                    successor_core.rhs = prod;
                    successor_core.dot_pos = 0;
                    
                    // Find all matching items in the goto state
                    auto it = item_to_state.find(successor_core);
                    if (it != item_to_state.end()) {
                        for (auto& state_item_pair : it->second) {
                            size_t target_state_id = state_item_pair.first;
                            LR1Core* target_item = state_item_pair.second;
                            
                            // Verify this is in the correct goto state
                            if (goto_table[state_id].count(next_sym.fullname) && 
                                goto_table[state_id][next_sym.fullname] == target_state_id) {
                                // Propagate lookaheads
                                for (const auto& la : propagation_la) {
                                    if (target_item->lookahead.insert(la).second) {
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
    
            }
        }
    } while (changed);

    canonical_item_set = std::move(merged_states);
    LRParser::buildTable();
}
