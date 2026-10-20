module LALRParser;
import std;

LALRParser::LALRParser(AST::Tree* tree, std::size_t k) : LRParser(tree, k, false) { build(); }
LALRParser::LALRParser(AST::Tree& tree, std::size_t k) : LRParser(&tree, k, false) { build(); }

void LALRParser::mergeLR0Cores() {
    using CoreSet = std::set<LR0Core>;
    std::map<CoreSet, std::size_t> merged_by_core;
    std::vector<std::size_t> old_to_new(canonical_item_set.size());
    CanonicalItemSet merged;

    // Iterate canonical states in BFS order. State 0 always maps to state 0.
    for (std::size_t old = 0; old < canonical_item_set.size(); ++old) {
        CoreSet core;
        for (const auto& [item, ignored] : canonical_item_set[old]) core.insert(item);
        auto found = merged_by_core.find(core);
        std::size_t dest;
        if (found == merged_by_core.end()) {
            dest = merged.size();
            merged_by_core.emplace(std::move(core), dest);
            merged.emplace_back();
        } else {
            dest = found->second;
        }
        old_to_new[old] = dest;
        for (const auto& [item, lookaheads] : canonical_item_set[old]) {
            auto& target = merged[dest][item];
            target.insert(lookaheads.begin(), lookaheads.end());
        }
    }

    std::vector<TransitionRow> merged_transitions(merged.size());
    for (std::size_t old = 0; old < transitions.size(); ++old) {
        const auto from = old_to_new[old];
        for (const auto& [symbol, target] : transitions[old]) {
            const auto to = old_to_new.at(target);
            auto [it, inserted] = merged_transitions[from].emplace(symbol, to);
            if (!inserted && it->second != to)
                throw std::logic_error("LALR: inconsistent transition after LR(0) core merge");
        }
    }
    canonical_item_set = std::move(merged);
    transitions = std::move(merged_transitions);
}

void LALRParser::build() {
    buildCanonical();
    mergeLR0Cores();
    // Correct LALR(k) merging can introduce RR conflicts in an LR(k) grammar.
    // Do not refuse a merge to mask those conflicts (that would not be LALR(1)).
    buildTables();
}
