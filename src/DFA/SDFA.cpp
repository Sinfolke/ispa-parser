module DFA.SDFA;
import cpuf.op;
import cpuf.printf;
import logging;
import corelib;
import dstd;
import std;

void DFA::SDFA::unrollMultiTransition(std::size_t state_id, const NFA::TransitionKey &symbol,
                                       stdu::vector<MultiTransitionValue> &val,
                                       SeenSymbol &seen, WalkedState &walked_state) {
    Tlog::Branch b(logger, "DFA/unrollMultiTransition");

    // ---------------------------------------------------------------------
    // Step 0: memoize on the *set* of states being merged (classic subset-
    // construction dedup). If we've already built a merged DFA state for
    // this exact combination of targets, reuse it instead of creating a
    // new one.
    //
    // This is what actually bounds the recursion. The per-element guard in
    // step 2 below only fires once every single alternative has
    // individually been visited before; for a cyclic construct (`a*`,
    // `(ab)*`, ...) each loop iteration produces a target set that
    // overlaps a previous one without being identical to it, so that guard
    // never trips and step 6 mints a brand-new state every time - which is
    // how you end up with tens of thousands of near-duplicate states.
    // Keying on the full sorted target set closes that gap: the number of
    // distinct reachable subsets is finite, so this guarantees
    // termination.
    //
    // NOTE: requires `SeenSymbol` to be keyed by the sorted target-id set,
    // e.g. `std::map<stdu::vector<std::size_t>, std::size_t>` (or an
    // unordered_map with a vector hash). It's already threaded through and
    // already cleared per top-level call in build() - it just wasn't used
    // for anything before. If SeenSymbol is currently declared differently,
    // its declaration needs to change to match.
    // ---------------------------------------------------------------------
    stdu::vector<std::size_t> target_set;
    target_set.reserve(val.size());
    for (const auto &alt : val)
        target_set.push_back(alt.value.next);
    std::sort(target_set.begin(), target_set.end());
    target_set.erase(std::unique(target_set.begin(), target_set.end()), target_set.end());

    // ---------------------------------------------------------------------
    // Step 1: aggregate CST/grouping metadata. When several NFA states
    // collapse onto one DFA state for `symbol`, we can't just keep one of
    // them: each alternative may carry different CST-node bookkeeping
    // (new_cst_node/new_member/...). The merged state inherits the union
    // of that bookkeeping regardless of whether we hit the cache below.
    // ---------------------------------------------------------------------
    struct MergedMetadata {
        bool new_cst_node = false, new_member = false, close_cst_node = false;
        bool optional = false, last = false;
        std::size_t new_group = NFA::NULL_STATE, close_group = NFA::NULL_STATE;
    };

    auto aggregateMetadata = [](const stdu::vector<MultiTransitionValue> &alts) {
        MergedMetadata m;
        for (const auto &alt : alts) {
            m.new_cst_node  |= alt.value.new_cst_node;
            m.new_member    |= alt.value.new_member;
            m.close_cst_node |= alt.value.close_cst_node;
            m.optional      |= alt.value.optional;
            m.last          |= alt.value.last;
            if (alt.value.new_group != NFA::NULL_STATE)   m.new_group = alt.value.new_group;
            if (alt.value.group_close != NFA::NULL_STATE) m.close_group = alt.value.group_close;
        }
        return m;
    };

    const MergedMetadata meta = aggregateMetadata(val);

    auto makeMergedTransitionValue = [&](std::size_t next_state) {
        return MultiTransitionValue{next_state, meta.new_cst_node, meta.new_member, meta.close_cst_node,
                                     meta.new_group, meta.close_group, meta.optional, meta.last};
    };

    if (const auto cached = seen.find(target_set); cached != seen.end()) {
        b.log("reusing merged state {} for already-seen target set", cached->second);
        val = {makeMergedTransitionValue(cached->second)};
        return;
    }

    const std::size_t current_dfa_state = mdfa.get().makeNew();
    seen[target_set] = current_dfa_state; // register BEFORE recursing, so cycles resolve back to us
    mdfa.get()[current_dfa_state].rule_name = mdfa.get()[state_id].rule_name;
    mdfa.get()[current_dfa_state].dtb       = mdfa.get()[state_id].dtb;
    walked_state[current_dfa_state];

    // ---------------------------------------------------------------------
    // Step 2: per-alternative recursion guard. If *every* alternative's
    // target has already been visited on this recursive path, there is
    // nothing new to look ahead into - collapse to a single arbitrary
    // (furthest) target instead.
    // TODO: implement more complex logic to cancel saved input if a path
    // without input is chosen.
    // ---------------------------------------------------------------------
    const bool all_targets_already_walked = std::all_of(val.begin(), val.end(), [&](const auto &alt) {
        return walked_state.contains(alt.value.next);
    });

    if (all_targets_already_walked) {
        mdfa.get().get().pop_back(); // discard the state we just allocated, it ends up unused
        seen.erase(target_set);      // ...and its cache entry - it never actually existed
        const auto furthest = std::max_element(val.begin(), val.end(), [](const auto &a, const auto &b) {
            return a.value.next < b.value.next;
        });
        const std::size_t target = walked_state.at(furthest->value.next);
        val = {makeMergedTransitionValue(target)};
        b.log("preventing recursion: val = {}", target);
        return;
    }

    // ---------------------------------------------------------------------
    // Step 3: seed the lookahead queue with every not-yet-visited
    // alternative, remembering each in walked_state so a nested call can
    // detect a cycle back to it via step 2.
    // ---------------------------------------------------------------------
    std::queue<std::pair<std::size_t, std::size_t>> work; // (dfa state to inspect, index into val)
    std::size_t remaining_in_batch = 0;
    for (std::size_t val_index = 0; val_index < val.size(); ++val_index) {
        const std::size_t next_state = val[val_index].value.next;
        if (walked_state.contains(next_state))
            continue;
        walked_state[next_state] = current_dfa_state;
        work.emplace(next_state, val_index);
        remaining_in_batch++;
    }

    // ---------------------------------------------------------------------
    // Step 4: gather one level of lookahead. For every alternative, collect
    // the transitions reachable from its target state, grouped by which
    // alternative they came from.
    //
    // NOTE: substep 3 ("push deeper if a symbol has several goto states")
    // is intentionally not implemented yet, so `work` never grows past its
    // initial seeding and every iteration below starts a fresh group. If/when
    // multi-level lookahead is implemented, that's where new work items
    // would get pushed instead of stopping at one level.
    // ---------------------------------------------------------------------
    using LookaheadSet = stdu::vector<MultiTransitions>;
    using Lookaheads = stdu::vector<std::pair<LookaheadSet, std::size_t>>;
    Lookaheads lookaheads;

    while (!work.empty()) {
        if (work.size() == remaining_in_batch) {
            lookaheads.emplace_back();
            remaining_in_batch--;
        }
        const auto [state_to_inspect, val_index] = work.front();
        work.pop();

        lookaheads.back().first.emplace_back();
        lookaheads.back().second = val_index;
        MultiTransitions &current_group = lookaheads.back().first.back();

        for (auto &[trans_symbol, targets] : mdfa.get()[state_to_inspect].transitions) {
            for (auto &target : targets) {
                target.dfa_merge_conflict = val[val_index].dfa_merge_conflict;
                current_group[trans_symbol].push_back(target);
            }
        }
    }

    // ---------------------------------------------------------------------
    // Step 5: build the merged state's transitions from the gathered
    // lookahead.
    // ---------------------------------------------------------------------
    if (!dfa_empty_state_map_.empty())
        dfa_empty_state_map_[current_dfa_state] = dfa_empty_state_map_[state_id];
    if (!dfa_index_to_empty_state_map_.empty())
        dfa_index_to_empty_state_map_[current_dfa_state] = dfa_index_to_empty_state_map_[state_id];

    logger.log("Lookaheads size: {}", lookaheads.size());
    for (std::size_t i = 0; i < lookaheads.size(); ++i) {
        const auto &[lookahead_set, val_index] = lookaheads[i];
        // Each group holds exactly one entry today (see the NOTE in step 4);
        // `.front()` is the single-level lookahead for this alternative.
        const MultiTransitions &transitions_by_symbol = lookahead_set.front();
        logger.log("transitions_by_symbol.size(): {}", transitions_by_symbol.size());

        if (transitions_by_symbol.empty()) {
            // This alternative has no outgoing transitions: fall back to the
            // existing "empty state" for the original rule.
            const std::size_t empty_state = getEmptyState(state_id);
            b.log("using dfa_empty_state_map: {}", empty_state);
            mdfa.get()[current_dfa_state].else_goto = empty_state;
            mdfa.get()[current_dfa_state].else_goto_accept = val.at(i).value.accept_index;
            continue;
        }

        for (const auto &[trans_symbol, targets] : transitions_by_symbol) {
            auto &dst_targets = mdfa.get()[current_dfa_state].transitions[trans_symbol];
            dst_targets.insert(dst_targets.end(), targets.begin(), targets.end());

            const bool has_optional_last = std::any_of(
                mdfa.get()[current_dfa_state].transitions.begin(),
                mdfa.get()[current_dfa_state].transitions.end(),
                [](const auto &entry) {
                    return std::any_of(entry.second.begin(), entry.second.end(), [](const auto &alt) {
                        return alt.value.optional && alt.value.last;
                    });
                });
            if (has_optional_last) {
                for (const auto &target : targets) {
                    if (const auto end_state = mdfa.get().canBeEndState(target.value.next); end_state != NULL_STATE) {
                        mdfa.get()[current_dfa_state].else_goto = end_state;
                        break;
                    }
                }
            }
        }
    }

    // ---------------------------------------------------------------------
    // Step 6: any symbol that still maps to more than one *distinct* target
    // is still ambiguous - recurse to resolve it the same way. Two
    // alternatives that both happen to land on the same target (e.g. 'a'
    // -> [17, 17]) are not a real conflict; dedupe first so they don't get
    // treated as one and waste a recursive call/state.
    // ---------------------------------------------------------------------
    for (auto &[trans_symbol, targets] : mdfa.get()[current_dfa_state].transitions) {
        std::sort(targets.begin(), targets.end(), [](const auto &a, const auto &b) {
            return a.value.next < b.value.next;
        });
        targets.erase(std::unique(targets.begin(), targets.end(), [](const auto &a, const auto &b) {
            return a.value.next == b.value.next;
        }), targets.end());

        if (targets.size() > 1) {
            unrollMultiTransition(current_dfa_state, trans_symbol, targets, seen, walked_state);
        }
    }

    val = {makeMergedTransitionValue(current_dfa_state)};
}

auto DFA::SDFA::build() -> const States<SingleState>& {
    // `seen` memoizes merged states by their canonical target-set for the
    // whole build() call. One SDFA::build() call processes a single rule's
    // MDFA, and MDFA::build() stamps every state it creates with the same
    // rule_name/dtb (both come from one `nfa.getName()`/`nfa.getDtb()`
    // captured once at the top of that function) - so any state_id here
    // already shares an identical rule_name/dtb with any other. That makes
    // it always safe to reuse a merged state built while resolving one
    // state's ambiguous symbol for another state's ambiguous symbol
    // elsewhere in the same rule, instead of rebuilding an equivalent
    // lookahead chain from scratch every time. NOT clearing `seen` here
    // (only `walked_state`, which is a within-recursion cycle guard rather
    // than a cache) is what lets that sharing happen.
    SeenSymbol seen;
    WalkedState walked_state;
    for (std::size_t i = 0; i < mdfa.get().size(); ++i) {
        auto &state = mdfa.get()[i];
        for (auto &t : state.transitions) {
            if (t.second.size() > 1) {
                unrollMultiTransition(i, t.first, t.second, seen, walked_state);
                walked_state.clear();
            }
        }
    }
    // switch to single state
    for (auto &state : mdfa.get()) {
        auto index = states.makeNew();
        states[index].else_goto = state.else_goto;
        states[index].else_goto_accept = state.else_goto_accept;
        for (auto &t : state.transitions) {
            states[index].transitions[t.first] = std::move(t.second.front().value);
        }
        states[index].rule_name = std::move(state.rule_name);
        states[index].dtb = std::move(state.dtb);
    }
    mdfa.clear();
    check_dfa();
    return states;
}

auto DFA::SDFA::check_dfa() -> void {
    std::size_t index = 0;
    try {
        for (const auto &state : states) {
            AssertNe(state.rule_name.empty(), "Empty rule_name in state {}", index);
            for (const auto &[sym, t] : state.transitions) {
                if (std::holds_alternative<stdu::vector<std::string>>(sym)) {
                    const auto &nested_name = std::get<stdu::vector<std::string>>(sym);
                    AssertNe(nested_name.empty(), "Empty nested_name in state {}", index);
                }
                Assert(states.size() >= t.next, "Out of bound transition {} in state {}", t.next, index);
            }
            ++index;
        }
    } catch (Error &e) {
        std::cout << "[SDFA] Check Failed > " << e.what() << '\n';
        std::cout << "Runtime checks of DFA are required on unstable release. Please report to 'https://github.com/Sinfolke/ispa-parser'";
        std::cout << "If this happens after switching to unstable version, consider roll back. Otherwise check your unusual tokens";
        std::cout << "Names related to this error: ";
        for (const auto &name : getDfaNames(*this)) {
            std::cout << name.first << ", ";
        }
        std::cout << '\n';
        std::cout << "DFA: \n";
        std::cout << *this;
        std::abort();
    }
}

auto DFA::operator<<(std::ostream& os, const SDFA& dfa) -> std::ostream& {
    std::size_t index = 0;
    for (const auto &state : dfa.get()) {
        os << "State " << index << ": \n";
        for (const auto &[symbol, next] : state.transitions) {
            os << "\t";
            if (std::holds_alternative<char>(symbol)) {
                auto c = std::get<char>(symbol);
                if (std::isprint(c) && !std::isspace(c)) {
                    os << c;
                } else if (std::isspace(c)) {
                    os << corelib::text::getEscapedFromChar(c);
                }
            } else {
                os << corelib::text::join(std::get<stdu::vector<std::string>>(symbol), "::");
            }
            os << " -> ";
            os << next.next;
            os << '\n';
        }
        os << "[rule_name]: " << corelib::text::join(state.rule_name, "::") << '\n';
        if (!std::holds_alternative<std::monostate>(state.dtb)) {
            os << "\t[dtb] = {";
            if (std::holds_alternative<NFA::TemplatedDataBlockValue>(state.dtb)) {
                os << (std::get<NFA::TemplatedDataBlockValue>(state.dtb).type == NFA::StoreCstNode::CST_GROUP ? "group" : "node") << "}\n";
            } else {
                os << '\n';
                for (const auto &[name, data] : std::get<NFA::TemplatedDataBlock>(state.dtb)) {
                    os << "\t\t" << name << ": {" << (data.type == NFA::StoreCstNode::CST_GROUP ? "group" : "node") << ", " << data.cst_index << "}\n";
                }
                os << "\t}\n";
            }
        }
        if (state.else_goto != DFA::NULL_STATE) {
            os << "e -> " << state.else_goto;
            if (state.else_goto_accept != DFA::NULL_STATE) {
                os << " [accept -> " << state.else_goto_accept << "]";
            }
            os << '\n';
        }
        ++index;
    }
    return os;
}



auto DFA::SDFA::clear() -> void {
    states.clear();
}
auto DFA::SDFA::getType() const -> DfaType {
    return Base::getType(states);
}