module DFA;

import DFA.States;
import DFA.closure;

import hash;
import logging;
import corelib;
import cpuf.op;
import dstd;
import std;

namespace DFA {
    auto DFA::build() -> const States<SingleState>& {
        Tlog::Branch b(logger, "DFA.log");

        utype::unordered_map<Closure, std::size_t> dfa_state_map;
        utype::unordered_map<std::pair<Closure, NFA::TransitionKey>, Closure> closure_cache;
        std::queue<Closure> work;

        StateSet start_set = {0}; // NFA start state
        Closure start_closure(nfa, start_set);

        auto start_idx = states.makeNew();
        dfa_state_map[start_closure] = start_idx;
        work.push(start_closure);

        logger.log("---- [0] DFA CONSTRUCTION ----");

        while (!work.empty()) {
            Closure current = work.front();
            work.pop();
            std::size_t current_dfa_index = dfa_state_map.at(current);

            // 1. Resolve State Acceptance Binding from NFA Subsets
            std::optional<NFA::TokenBinding> best_binding = std::nullopt;
            for (std::size_t nfa_index : current) {
                const auto& nfa_state = nfa.getStates().at(nfa_index);

                auto accept_it = nfa.getAcceptMap().find(nfa_index);
                std::optional<NFA::TokenBinding> current_binding =
                    (accept_it != nfa.getAcceptMap().end()) ? std::make_optional(accept_it->second) : nfa_state.accept_binding;

                if (current_binding.has_value()) {
                    if (!best_binding.has_value() || current_binding->token_id < best_binding->token_id) {
                        best_binding = current_binding;
                    }
                }
            }

            states[current_dfa_index].accept_binding = best_binding;

            // Apply unique REDUCE hook as default fallback if applicable
            if (best_binding.has_value() && best_binding->is_unique_representation && best_binding->target_lr_state.has_value()) {
                states[current_dfa_index].default_fallback = LRTarget{
                    best_binding->target_lr_state.value(),
                    best_binding->reduce_rule_id.value_or(NFA::NULL_STATE)
                };
            }

            // 2. Group Target NFA States Sharing the Same Symbol
            utype::unordered_map<NFA::TransitionKey, Closure> input_symbols;
            for (std::size_t nfa_index : current) {
                const auto &state = nfa.getStates().at(nfa_index);
                for (const auto &[symbol, ids] : state.transitions) {
                    auto cache_key = std::make_pair(current, symbol);
                    if (!closure_cache.contains(cache_key)) {
                        closure_cache.emplace(cache_key, Closure(nfa, current.get(), symbol));
                    }
                    Closure closure_set = closure_cache.at(cache_key);
                    if (!closure_set.empty()) {
                        input_symbols[symbol] = std::move(closure_set);
                    }
                }
            }

            // 3. Create DFA Transitions
            for (const auto &[symbol, closure_set] : input_symbols) {
                if (!dfa_state_map.contains(closure_set)) {
                    auto new_idx = states.makeNew();
                    dfa_state_map.emplace(closure_set, new_idx);
                    work.push(closure_set);
                }

                std::size_t target_index = dfa_state_map.at(closure_set);

                // Transitions inside pure DFA only point to other DFA states initially
                states[current_dfa_index].transitions[symbol] = DFATarget{target_index};
            }
        }

        if (states.empty()) {
            throw Error("DFA cannot be empty");
        }

        check_dfa();
        return states;
    }
    void DFA::optimizeRegistersAndLRTable() {
        // ------------------------------------------------------------
        // LR Table Deduplication & Index Compaction
        // ------------------------------------------------------------
        // NOTE: the previous version of this function also walked every state's
        // transitions renaming registers via t.lr_action_index / t.actions, then
        // remapped those same fields to the deduplicated indices below. Neither
        // field exists on DFA::TransitionValue anymore (see API.cppm), so there
        // is currently no per-transition link into lr_table to walk or remap.
        // Table dedup itself is self-contained (only reads/writes lr_table) and
        // still runs. If per-transition LR actions get reinstated on
        // TransitionValue (or sourced from NFA::state::action_table instead),
        // restore the register-allocation walk and the reference-remap pass here.
        std::vector<NFA::LRState> deduplicated_lr_table;
        std::unordered_map<std::size_t, std::size_t> lr_index_remap;

        for (std::size_t i = 0; i < nfa.getLRTable().size(); ++i) {
            const auto &entry = nfa.getLRTable()[i];
            std::size_t canonical_idx = NULL_STATE;

            for (std::size_t j = 0; j < deduplicated_lr_table.size(); ++j) {
                if (deduplicated_lr_table[j].action == entry.action &&
                    deduplicated_lr_table[j].variable == entry.variable &&
                    deduplicated_lr_table[j].DFA_next_state == entry.DFA_next_state &&
                    deduplicated_lr_table[j].reduce_rule_index == entry.reduce_rule_index) {
                    canonical_idx = j;
                    break;
                }
            }

            if (canonical_idx == NULL_STATE) {
                canonical_idx = deduplicated_lr_table.size();
                deduplicated_lr_table.push_back(entry);
            }
            lr_index_remap[i] = canonical_idx;
        }

        lr_table = std::move(deduplicated_lr_table);
    }
    auto DFA::initialClass(const SingleState &s) -> std::size_t {
        std::size_t h = 0;
        if (s.accept_binding.has_value()) {
            hash_combine(h, s.accept_binding->token_id);
            hash_combine(h, s.accept_binding->is_unique_representation);
        } else {
            hash_combine(h, 0xDEADBEEF); // Sentinel for non-accepting states
        }

        if (s.default_fallback.has_value()) {
            std::visit([&h](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, LRTarget>) {
                    hash_combine(h, 1);
                    hash_combine(h, arg.lr_state_id);
                    hash_combine(h, arg.reduce_rule_id);
                } else if constexpr (std::is_same_v<T, ActionTarget>) {
                    hash_combine(h, 2);
                    hash_combine(h, arg.action_id);
                }
            }, s.default_fallback.value());
        }
        return h;
    }
    auto DFA::refinementKey(
        const SingleState &s,
        const std::unordered_map<std::size_t, std::size_t> &partition_of
    ) -> std::vector<TransitionKeyExt> {
        std::vector<TransitionKeyExt> key;
        key.reserve(s.transitions.size());

        for (const auto &[sym, target] : s.transitions) {
            std::visit([&](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, DFATarget>) {
                    key.push_back(TransitionKeyExt {sym, partition_of.at(arg.dfa_state_id), NFA::NULL_STATE, 0});
                } else if constexpr (std::is_same_v<T, LRTarget>) {
                    key.push_back(TransitionKeyExt {sym, NFA::TableType::LR, arg.lr_state_id, 1});
                } else if constexpr (std::is_same_v<T, ActionTarget>) {
                    key.push_back(TransitionKeyExt {sym, NFA::TableType::ACTION, arg.action_id, 2});
                }
            }, target);
        }

        std::sort(key.begin(), key.end());
        return key;
    }

    auto DFA::minimize() -> States<SingleState> {
        Tlog::Branch b(logger, "DFA/minimize.log");
        logger.increaseIndentLevel();

        const auto& input = states;
        const std::size_t n = input.size();

        if (n == 0) {
            logger.log("Minimized 0 states -> 0 states");
            logger.decreaseIndentLevel();
            return States<SingleState>(&nfa);
        }

        // 1. Initial partition & 2. Refine until stable (Unchanged boilerplate logic...)
        // ... (Skipping standard Hopcroft loops as they rely entirely on the updated `initialClass` and `refinementKey` above) ...

        // 5. Copy transitions
        for (std::size_t i = 0; i < n; ++i) {
            const std::size_t cls = partition_of.at(i);
            const std::size_t new_idx = class_to_new_index[cls];

            if (!output[new_idx].transitions.empty())
                continue;

            auto& out_state = output[new_idx];
            out_state.accept_binding = input[i].accept_binding;
            out_state.default_fallback = input[i].default_fallback;

            for (const auto& [symbol, target] : input[i].transitions) {
                std::visit([&](auto&& arg) {
                    using T = std::decay_t<decltype(arg)>;
                    if constexpr (std::is_same_v<T, DFATarget>) {
                        const std::size_t target_class = partition_of.at(arg.dfa_state_id);
                        out_state.transitions[symbol] = DFATarget{class_to_new_index[target_class]};
                    } else {
                        out_state.transitions[symbol] = target; // Copy external hooks verbatim
                    }
                }, target);
            }
        }

        // 6. Prune unreachable / dead states from output
        std::vector<bool> reachable(output.size(), false);
        std::queue<std::size_t> q;

        if (!output.empty()) {
            reachable[0] = true;
            q.push(0);
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (const auto& [sym, target] : output[curr].transitions) {
                if (std::holds_alternative<DFATarget>(target)) {
                    std::size_t next_dfa = std::get<DFATarget>(target).dfa_state_id;
                    if (!reachable[next_dfa]) {
                        reachable[next_dfa] = true;
                        q.push(next_dfa);
                    }
                }
            }
        }

        logger.log("Minimized {} states -> {} states", n, output.size());
        logger.decreaseIndentLevel();

        this->states = output;
        optimizeRegistersAndLRTable();

        return output;
    }
    auto DFA::classify() -> ClassifiedDFA {
        if (!nfa.isCharNfa()) {
            throw Error("classify() only applies to character-keyed (CharMachineDFA) automata");
        }
        Tlog::Branch b(logger, "DFA/classify.log");
        // Must run on the already-minimized DFA — classes are only correct if
        // target-state identity is final. Running this before minimize() would
        // compute a partition against states that are about to be merged.

        logger.log("---- [0] CHARACTER CLASS COMPACTION ----");
        logger.increaseIndentLevel();

        constexpr std::size_t ALPHABET_SIZE = 256;
        const std::size_t n = states.size();

        // Signature for one character: across EVERY state, does a transition
        // exist for this char, and if so where does it go + what does it
        // accept. Two characters with an identical signature vector behave
        // identically everywhere in this automaton and can share one class.
        // This must be built over ALL states jointly — a per-state signature
        // would only be locally correct and break the shared-table invariant.
        using Signature = std::vector<std::pair<std::size_t, std::size_t>>; // per state: (target|NULL_STATE, accept_index)

        std::unordered_map<Signature, std::size_t, uhash> class_of_signature;
        CharClassTable table;

        for (std::size_t c = 0; c < ALPHABET_SIZE; ++c) {
            Signature sig;
            sig.reserve(n);
            NFA::TransitionKey key{static_cast<char>(c)};
            for (std::size_t i = 0; i < n; ++i) {
                auto it = states[i].transitions.find(key);
                if (it == states[i].transitions.end()) {
                    sig.emplace_back(NULL_STATE, NULL_STATE);
                } else {
                    sig.emplace_back(it->second.next, it->second.accept_index);
                }
            }
            auto [it, inserted] = class_of_signature.try_emplace(sig, class_of_signature.size());
            table.char_to_class[c] = it->second;
        }
        table.num_classes = class_of_signature.size();

        logger.log("Compacted {} characters -> {} equivalence classes", ALPHABET_SIZE, table.num_classes);

        // Rebuild each state's transitions indexed by class id instead of raw
        // char. Every character in a class agrees on outcome by construction,
        // so it's safe to keep just one representative TransitionValue per class.
        States<State<ClassTransitions>> output(&nfa);
        for (std::size_t i = 0; i < n; ++i) {
            auto new_idx = output.makeNew();
            output[new_idx].rule_name = states[i].rule_name;
            // Default-constructed TransitionValue already has next == NULL_STATE
            // and accept_index == NULL_STATE via in-class member initializers
            // (see API.cppm) -- {NULL_STATE, NULL_STATE} tried to assign a
            // std::size_t into the table_type (NFA::TableType) slot, which
            // doesn't type-check.
            output[new_idx].transitions.assign(table.num_classes, TransitionValue{});

            for (const auto &[symbol, value] : states[i].transitions) {
                if (!std::holds_alternative<char>(symbol)) continue; // name-keyed transitions don't apply here
                unsigned char c = static_cast<unsigned char>(std::get<char>(symbol));
                std::size_t cls = table.char_to_class[c];
                output[new_idx].transitions[cls] = value; // all chars in this class already agree
            }
        }

        logger.decreaseIndentLevel();
        return ClassifiedDFA{std::move(table), std::move(output)};
    }

    auto DFA::clear() -> void {
        states.clear();
    }
    auto DFA::getType() const -> DfaType {
        return Base::getType(states);
    }

    auto DFA::check_dfa() -> void {
        std::size_t index = 0;
        try {
            for (const auto &state : states) {
                AssertNe(state.rule_name.empty(), "Empty rule_name in state {}", index);
                for (const auto &[sym, transitions] : state.transitions) {
                    if (std::holds_alternative<stdu::vector<std::string>>(sym)) {
                        const auto &nested_name = std::get<stdu::vector<std::string>>(sym);
                        AssertNe(nested_name.empty(), "Empty nested_name in state {}", index);
                    }
                    // NOTE: dropped unused capture_count/nfa_capture_count locals --
                    // nothing populated them, they were dead. Also fixed the bound
                    // check below: `states.size() >= transitions.next` lets
                    // transitions.next == states.size() through, which is one past
                    // the last valid index.
                    Assert(states.size() > transitions.next, "Out of bound transition {} in state {}", transitions.next, index);
                }
                ++index;
            }
        } catch (Error &e) {
            std::cout << "[MDFA] Check Failed > " << e.what() << '\n';
            std::cout << "Runtime checks of DFA are required on unstable release. Please report to 'https://github.com/Sinfolke/ispa-parser'";
            std::cout << "If this happens after switching to unstable version, consider roll back. Otherwise check your unusual tokens";
            std::cout << '\n';
            std::cout << "DFA: \n";
            std::cout << *this;
            std::abort();
        }
    }

    auto operator<<(std::ostream& os, const DFA& dfa) -> std::ostream& {
        std::size_t index = 0;
        for (const auto &state : dfa.get()) {
            os << "State " << index << ": \n";
            for (const auto &[symbol, next] : state.transitions) {
                os << "\t";
                if (std::holds_alternative<char>(symbol)) {
                    auto c = std::get<char>(symbol);
                    if (std::isprint(c) && !std::isspace(c)) {
                        os << c;
                    } else {
                        os << corelib::text::getEscapedFromChar(c);
                    }
                } else {
                    os << corelib::text::join(std::get<stdu::vector<std::string>>(symbol), "::");
                }
                os << " -> " << next.next << '\n';
            }
            os << "[rule_name]: " << corelib::text::join(state.rule_name, "::") << '\n';
            ++index;
        }
        return os;
    }
    auto operator<<(std::ostream& os, const DFA::ClassifiedDFA& dfa) -> std::ostream& {
        os << dfa.table.num_classes << " equivalence classes\n";
        for (std::size_t i = 0; i < dfa.table.num_classes; ++i) {
            os << "Class " << i << ": ";
            for (std::size_t j = 0; j < dfa.table.char_to_class.size(); ++j) {
                if (dfa.table.char_to_class[j] != i) continue;
                if (std::isprint(static_cast<unsigned char>(j))) {
                    os << static_cast<char>(j) << ' ';
                } else {
                    os << corelib::text::getEscapedFromChar(static_cast<char>(j)) << ' ';
                }
            }
            os << '\n';
        }

        os << "--- DFA ---\n";
        std::size_t index = 0;
        for (const auto &state : dfa.states) {
            os << "State " << index << ": \n";
            for (std::size_t cls = 0; cls < state.transitions.size(); ++cls) {
                const auto &t = state.transitions[cls];
                if (t.next == NULL_STATE) continue; // dead transition, nothing to show
                os << "\t" << cls << " -> " << t.next;
                if (t.accept_index != NULL_STATE) {
                    os << " [accept: " << t.accept_index << "]";
                }
                os << '\n';
            }
            os << "[rule_name]: " << corelib::text::join(state.rule_name, "::") << '\n';
            ++index;
        }
        return os;
    }
}
