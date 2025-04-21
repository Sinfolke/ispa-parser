#include <LALRParser.h>

void LALRParser::build() {
    // Step 1: Prepare core structures
    LRParser::prepare(); // handles transform(), first/follow, etc.

    // Step 3: Merge LR(1) states with same LR(0) core to build LALR(1)
    std::unordered_map<std::set<std::tuple<rule_other, std::vector<rule_other>, size_t>>, size_t> core_to_index;
    CanonicalItemSet merged_items;
    std::vector<std::vector<size_t>> merge_map(canonical_item_set.size());

    for (size_t i = 0; i < canonical_item_set.size(); ++i) {
        std::set<std::tuple<rule_other, std::vector<rule_other>, size_t>> core;

        for (const auto& el : canonical_item_set[i]) {
            core.emplace(el.lhs, el.rhs, el.dot_pos);
        }

        auto it = core_to_index.find(core);
        if (it == core_to_index.end()) {
            size_t new_index = merged_items.size();
            merged_items.emplace_back();
            core_to_index[core] = new_index;
        }

        size_t merged_index = core_to_index[core];
        merge_map[i].push_back(merged_index);
    }

    // Step 4: Merge lookaheads
    for (size_t i = 0; i < canonical_item_set.size(); ++i) {
        size_t merged_index = merge_map[i][0];

        for (const auto& el : canonical_item_set[i]) {
            CanonicalEl item = el;
            auto& target_set = merged_items[merged_index];
            auto found = target_set.find(item);
            if (found != target_set.end()) {
                const_cast<CanonicalEl&>(*found).lookahead.insert(item.lookahead.begin(), item.lookahead.end());
            } else {
                target_set.insert(item);
            }
        }
    }

    // Replace the old canonical_item_set with merged one
    canonical_item_set = std::move(merged_items);

    // Step 5: Build Action and Goto tables
    LRParser::buildTable();
}
