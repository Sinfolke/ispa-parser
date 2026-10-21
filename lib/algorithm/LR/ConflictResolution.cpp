module LRParser;
import std;

void LRParser::resolveConflicts(std::size_t max_lookahead) {
    if (!max_lookahead) throw std::invalid_argument("LR conflict lookahead must be positive");
    if (restoreResolutions(max_lookahead)) return;
    auto_conflicts = true;
    decision_k = k;
    resolutions.clear();
    for (std::size_t i = 0; i < conflicts.size(); ++i) resolutions.push_back(Resolution{i});
    if (conflicts.empty()) { cacheResolutions(max_lookahead); return; }

    // FIRST/FOLLOW overapproximations are conservative: commit a cell only if
    // every candidate has disjoint continuation windows. Overlaps, exhausted
    // budgets and nonproductive contexts remain explicit runtime alternatives.
    struct BudgetExceeded {};
    for (std::size_t depth = k + 1; depth <= max_lookahead; ++depth) {
        if (std::none_of(resolutions.begin(), resolutions.end(), [](const auto& r) { return !r.lookahead; })) break;
        std::size_t work = 0, entries = 0;
        auto tick = [&] { if (++work > 2000000) throw BudgetExceeded{}; };
        auto concat = [&](const Lookaheads& left, const Lookaheads& right) {
            Lookaheads result;
            for (const auto& a : left) for (const auto& b : right) {
                tick();
                auto window = a;
                if (window.size() < depth) {
                    const auto n = std::min(depth - window.size(), b.size());
                    window.insert(window.end(), b.begin(), b.begin() + n);
                }
                result.insert(std::move(window));
                if (result.size() > 100000) throw BudgetExceeded{};
            }
            return result;
        };
        try {
            std::map<Name, Lookaheads> first, follow;
            for (const auto& p : productions) { first[p.lhs]; follow[p.lhs]; }
            auto suffix = [&](const Production& p, std::size_t begin, Lookaheads trailing) {
                Lookaheads result{Lookahead{}};
                for (std::size_t i = begin; i < p.rhs.size(); ++i) {
                    const auto& symbol = p.rhs[i];
                    result = concat(result, isNonterminal(symbol) ? first.at(symbol) : Lookaheads{Lookahead{symbol}});
                }
                return concat(result, trailing);
            };
            auto merge = [&](Lookaheads& to, const Lookaheads& from) {
                const auto before = to.size();
                to.insert(from.begin(), from.end());
                entries += to.size() - before;
                if (entries > 200000) throw BudgetExceeded{};
                return to.size() != before;
            };
            bool changed;
            do {
                changed = false;
                for (const auto& p : productions) {
                    tick();
                    changed |= merge(first[p.lhs], suffix(p, 0, Lookaheads{Lookahead{}}));
                }
            } while (changed);
            follow[augmented].insert(Lookahead(depth, eof));
            do {
                changed = false;
                for (const auto& p : productions) for (std::size_t i = 0; i < p.rhs.size(); ++i) {
                    tick();
                    if (isNonterminal(p.rhs[i])) changed |= merge(follow[p.rhs[i]], suffix(p, i + 1, follow.at(p.lhs)));
                }
            } while (changed);
            for (auto& resolution : resolutions) {
                if (resolution.lookahead) continue;
                const auto& conflict = conflicts[resolution.conflict];
                std::map<Lookahead, std::vector<Action>> proposals;
                for (const auto& origin : conflict.origins) {
                    const auto& p = productions.at(origin.item.production);
                    const auto windows = origin.action.type == Action_type::SHIFT
                        ? suffix(p, origin.item.dot_pos, follow.at(p.lhs)) : follow.at(p.lhs);
                    for (const auto& window : windows) {
                        if (window.size() != depth || !std::equal(conflict.lookahead_sequence.begin(), conflict.lookahead_sequence.end(), window.begin())) continue;
                        auto& actions = proposals[window];
                        if (std::find(actions.begin(), actions.end(), origin.action) == actions.end()) actions.push_back(origin.action);
                    }
                }
                // Missing action contexts are not evidence that an action is
                // impossible. Fall back instead of silently deleting it.
                bool separated = !proposals.empty();
                for (const auto& action : conflict.actions) {
                    bool found = false;
                    for (const auto& [window, actions] : proposals) {
                        if (actions.size() != 1) separated = false;
                        if (std::find(actions.begin(), actions.end(), action) != actions.end()) found = true;
                    }
                    separated &= found;
                }
                if (!separated) continue;
                resolution.lookahead = depth;
                for (const auto& [window, actions] : proposals)
                    resolution.decisions.push_back(Decision{conflict.state, window, actions.front()});
                decision_k = std::max(decision_k, depth);
            }
        } catch (const BudgetExceeded&) { break; }
    }
    cacheResolutions(max_lookahead);
}
