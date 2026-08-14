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

                if (nfa_state.action_index != NFA::NULL_STATE) {
                    nfa.getActionTable()[nfa_state.action_index].DFA_next_state = current_dfa_index;
                }
            }

            states[current_dfa_index].accept_binding = best_binding;

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
                        input_symbols.try_emplace(symbol, closure_set);
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
        std::vector<NFA::ActionState> deduplicated_lr_table;
        std::unordered_map<std::size_t, std::size_t> lr_index_remap;

        for (std::size_t i = 0; i < nfa.getActionTable().size(); ++i) {
            const auto &entry = nfa.getActionTable()[i];
            std::size_t canonical_idx = NULL_STATE;

            for (std::size_t j = 0; j < deduplicated_lr_table.size(); ++j) {
                if (deduplicated_lr_table[j].action == entry.action &&
                    deduplicated_lr_table[j].variable == entry.variable &&
                    deduplicated_lr_table[j].DFA_next_state == entry.DFA_next_state) {
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
    void DFA::optimizeSemanticTable() {
        const auto &source_semantic_table = nfa.getSemanticTable();
        logger.log(
            "Semantic source table size: {}",
            source_semantic_table.size()
        );
        std::vector<bool> used(source_semantic_table.size(), false);
        std::unordered_set<std::size_t> referenced;
        for (std::size_t i = 0; i < states.size(); ++i) {
            auto &binding = states[i].accept_binding;
            if (!binding.has_value()) {
                logger.log(
                    "DFA state {}: no accept binding",
                    i
                );
                continue;
            }

            if (!binding->target_semantic_state.has_value()) {
                logger.log(
                    "DFA state {}: token={}, NO semantic state",
                    i,
                    binding->token_id
                );
                continue;
            }

            const auto semantic =
                *binding->target_semantic_state;

            logger.log(
                "DFA state {}: token={}, semantic={}",
                i,
                binding->token_id,
                semantic
            );

            referenced.insert(semantic);
            if (!binding.has_value() || !binding->target_semantic_state.has_value())
                continue;

            const std::size_t idx = *binding->target_semantic_state;
            if (idx >= used.size()) {
                binding->target_semantic_state.reset();
                continue;
            }
            used[idx] = true;
        }
        logger.log(
            "Referenced semantic entries: {}",
            referenced.size()
        );

        std::unordered_map<std::size_t, std::size_t> remap;
        stdu::vector<LangAPI::Statements> compacted;
        for (std::size_t i = 0; i < source_semantic_table.size(); ++i) {
            if (!used[i]) continue;
            remap[i] = compacted.size();
            compacted.push_back(source_semantic_table[i]);
        }

        for (std::size_t i = 0; i < states.size(); ++i) {
            auto &binding = states[i].accept_binding;
            if (!binding.has_value() || !binding->target_semantic_state.has_value())
                continue;

            const std::size_t old_idx = *binding->target_semantic_state;
            auto remap_it = remap.find(old_idx);
            if (remap_it == remap.end()) {
                binding->target_semantic_state.reset();
                continue;
            }
            binding->target_semantic_state = remap_it->second;
        }

        semantic_table = std::move(compacted);
    }
    auto DFA::sameAcceptBinding(
        const SingleState &a,
        const SingleState &b
    ) -> bool {
        if (a.accept_binding.has_value() != b.accept_binding.has_value())
            return false;

        if (!a.accept_binding)
            return true;

        const auto &lhs = *a.accept_binding;
        const auto &rhs = *b.accept_binding;

        return
            lhs.token_id == rhs.token_id &&
            lhs.is_unique_representation == rhs.is_unique_representation &&
            lhs.reduce_rule_id == rhs.reduce_rule_id &&
            lhs.target_semantic_state == rhs.target_semantic_state;
    }

    auto DFA::initialClass(const SingleState &s) -> std::size_t {
        std::size_t h = 0;

        if (s.accept_binding.has_value()) {
            const auto &binding = *s.accept_binding;

            hash_combine(h, binding.token_id);
            hash_combine(h, binding.is_unique_representation);

            if (binding.reduce_rule_id.has_value())
                hash_combine(h, *binding.reduce_rule_id);
            else
                hash_combine(h, NFA::NULL_STATE);

            if (binding.target_semantic_state.has_value())
                hash_combine(h, *binding.target_semantic_state);
            else
                hash_combine(h, NFA::NULL_STATE);
        } else {
            hash_combine(h, 0xDEADBEEF);
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
            std::visit([&](auto &&arg) {
                using T = std::decay_t<decltype(arg)>;

                if constexpr (std::is_same_v<T, DFATarget>) {
                    key.push_back(
                        TransitionKeyExt {
                            sym,
                            NFA::TableType::DFA,
                            NFA::NULL_STATE,
                            partition_of.at(arg.dfa_state_id)
                        }
                    );
                } else if constexpr (std::is_same_v<T, LRTarget>) {
                    key.push_back(
                        TransitionKeyExt {
                            sym,
                            NFA::TableType::Action,
                            arg.lr_state_id,
                            NFA::NULL_STATE
                        }
                    );
                } else if constexpr (std::is_same_v<T, ActionTarget>) {
                    key.push_back(
                        TransitionKeyExt {
                            sym,
                            NFA::TableType::Semantic,
                            arg.action_id,
                            NFA::NULL_STATE
                        }
                    );
                }
            }, target);
        }

        std::sort(key.begin(), key.end());
        return key;
    }

    auto DFA::minimize() -> States<SingleState> {
        Tlog::Branch b(logger, "DFA/minimize.log");
        logger.increaseIndentLevel();

        const auto &input = states;
        const std::size_t n = input.size();

        if (n == 0) {
            logger.log("Minimized 0 states -> 0 states");
            logger.decreaseIndentLevel();
            return States<SingleState>(&nfa);
        }

        /*
         * ------------------------------------------------------------
         * 1. Initial partition
         * ------------------------------------------------------------
         *
         * States with different observable acceptance/semantic behaviour
         * must never be placed in the same initial class.
         */
        std::unordered_map<std::size_t, std::size_t> partition_of;

        std::unordered_map<std::size_t, std::size_t> initial_hash_to_class;

        std::size_t class_count = 0;

        for (std::size_t i = 0; i < n; ++i) {
            const std::size_t hash = initialClass(input[i]);

            auto [it, inserted] =
                initial_hash_to_class.emplace(hash, class_count);

            if (inserted)
                ++class_count;

            partition_of[i] = it->second;
        }

        /*
         * ------------------------------------------------------------
         * 2. Partition refinement
         * ------------------------------------------------------------
         *
         * A state is identified by:
         *
         *   - its acceptance/semantic behaviour
         *   - its transition symbols
         *   - the kind of transition
         *   - the action/semantic target
         *   - the partition containing a DFA target
         *
         * Continue until no state changes partition.
         */
        bool changed = true;

        while (changed) {
            changed = false;

            std::unordered_map<std::size_t, std::size_t> new_partition;
            std::map<
                std::pair<
                    std::size_t,
                    std::vector<TransitionKeyExt>
                >,
                std::size_t
            > signature_to_class;

            std::size_t new_class_count = 0;

            for (std::size_t i = 0; i < n; ++i) {
                const auto key = refinementKey(
                    input[i],
                    partition_of
                );

                const std::size_t accept_hash =
                    initialClass(input[i]);

                const auto signature =
                    std::make_pair(accept_hash, key);

                auto [it, inserted] =
                    signature_to_class.emplace(
                        signature,
                        new_class_count
                    );

                if (inserted)
                    ++new_class_count;

                new_partition[i] = it->second;

                if (new_partition[i] != partition_of[i])
                    changed = true;
            }

            partition_of = std::move(new_partition);

            logger.log(
                "Partition refinement: {} classes",
                new_class_count
            );
        }

        /*
         * ------------------------------------------------------------
         * 3. Give every partition its new DFA state index
         * ------------------------------------------------------------
         */
        std::unordered_map<std::size_t, std::size_t> class_to_new_index;

        States<SingleState> output(&nfa);

        for (std::size_t i = 0; i < n; ++i) {
            const std::size_t cls = partition_of.at(i);

            if (class_to_new_index.contains(cls))
                continue;

            const std::size_t new_index = output.makeNew();
            class_to_new_index.emplace(cls, new_index);
        }

        /*
         * ------------------------------------------------------------
         * 4. Construct minimized states
         * ------------------------------------------------------------
         *
         * Every partition is represented by one original state.
         *
         * Because semantic/acceptance information participates in the
         * partition signature, states in one partition have compatible
         * accept bindings.
         */
        std::unordered_set<std::size_t> constructed_classes;

        for (std::size_t i = 0; i < n; ++i) {
            const std::size_t cls = partition_of.at(i);
            const std::size_t new_idx = class_to_new_index.at(cls);

            if (!constructed_classes.insert(cls).second)
                continue;

            const auto &source = input[i];
            auto &destination = output[new_idx];

            destination.accept_binding = source.accept_binding;

            for (const auto &[symbol, target] : source.transitions) {
                std::visit([&](auto &&arg) {
                    using T = std::decay_t<decltype(arg)>;

                    if constexpr (std::is_same_v<T, DFATarget>) {
                        const std::size_t target_class =
                            partition_of.at(arg.dfa_state_id);

                        const std::size_t target_state =
                            class_to_new_index.at(target_class);

                        destination.transitions[symbol] =
                            DFATarget {target_state};
                    } else {
                        /*
                         * LRTarget and ActionTarget refer to external
                         * tables rather than DFA states, so their identity
                         * is preserved directly.
                         */
                        destination.transitions[symbol] = arg;
                    }
                }, target);
            }
        }

        /*
         * ------------------------------------------------------------
         * 5. Prune unreachable states
         * ------------------------------------------------------------
         */
        std::vector<bool> reachable(output.size(), false);
        std::queue<std::size_t> q;

        if (!output.empty()) {
            reachable[0] = true;
            q.push(0);
        }

        while (!q.empty()) {
            const std::size_t current = q.front();
            q.pop();

            for (const auto &[symbol, target] :
                 output[current].transitions) {

                if (!std::holds_alternative<DFATarget>(target))
                    continue;

                const std::size_t next =
                    std::get<DFATarget>(target).dfa_state_id;

                if (next >= reachable.size())
                    continue;

                if (reachable[next])
                    continue;

                reachable[next] = true;
                q.push(next);
            }
        }

        /*
         * ------------------------------------------------------------
         * 6. Remove unreachable states and rebase DFA targets
         * ------------------------------------------------------------
         */
        States<SingleState> reachable_output(&nfa);

        std::vector<std::size_t> state_remap(
            output.size(),
            NFA::NULL_STATE
        );

        for (std::size_t i = 0; i < output.size(); ++i) {
            if (!reachable[i])
                continue;

            state_remap[i] = reachable_output.makeNew();
        }

        for (std::size_t i = 0; i < output.size(); ++i) {
            if (!reachable[i])
                continue;

            const std::size_t new_idx = state_remap[i];

            auto &destination = reachable_output[new_idx];
            const auto &source = output[i];

            destination.accept_binding =
                source.accept_binding;

            for (const auto &[symbol, target] :
                 source.transitions) {

                std::visit([&](auto &&arg) {
                    using T = std::decay_t<decltype(arg)>;

                    if constexpr (std::is_same_v<T, DFATarget>) {
                        const std::size_t old_target =
                            arg.dfa_state_id;

                        if (old_target >= state_remap.size())
                            return;

                        const std::size_t new_target =
                            state_remap[old_target];

                        if (new_target == NFA::NULL_STATE)
                            return;

                        destination.transitions[symbol] =
                            DFATarget {new_target};
                    } else {
                        destination.transitions[symbol] = arg;
                    }
                }, target);
            }
        }

        logger.log(
            "Minimized {} states -> {} states",
            n,
            reachable_output.size()
        );

        /*
         * ------------------------------------------------------------
         * 7. Replace DFA states
         * ------------------------------------------------------------
         */
        this->states = std::move(reachable_output);

        /*
         * ------------------------------------------------------------
         * 8. Rebuild auxiliary tables from the surviving DFA
         * ------------------------------------------------------------
         */
        optimizeRegistersAndLRTable();
        optimizeSemanticTable();

        logger.decreaseIndentLevel();

        return states;
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
        using Signature = std::vector<std::pair<NFA::TableType, std::size_t>>;

        std::unordered_map<Signature, std::size_t, uhash> class_of_signature;
        CharClassTable table;

        for (std::size_t c = 0; c < ALPHABET_SIZE; ++c) {
            Signature sig;
            sig.reserve(n);
            NFA::TransitionKey key{static_cast<char>(c)};
            for (std::size_t i = 0; i < n; ++i) {
                auto it = states[i].transitions.find(key);
                if (it == states[i].transitions.end()) {
                    sig.emplace_back(NFA::TableType::DFA, NULL_STATE);
                } else {
                    std::visit([&](auto &&target) {
                        using T = std::decay_t<decltype(target)>;
                        if constexpr (std::is_same_v<T, DFATarget>) {
                            sig.emplace_back(NFA::TableType::DFA, target.dfa_state_id);
                        } else if constexpr (std::is_same_v<T, LRTarget>) {
                            sig.emplace_back(NFA::TableType::Action, target.lr_state_id);
                        } else if constexpr (std::is_same_v<T, ActionTarget>) {
                            sig.emplace_back(NFA::TableType::Semantic, target.action_id);
                        }
                    }, it->second);
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
            output[new_idx].accept_binding = states[i].accept_binding;
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
                std::visit([&](auto &&target) {
                    using T = std::decay_t<decltype(target)>;
                    if constexpr (std::is_same_v<T, DFATarget>) {
                        output[new_idx].transitions[cls] = TransitionValue{target.dfa_state_id, NFA::TableType::DFA, NULL_STATE};
                    } else if constexpr (std::is_same_v<T, LRTarget>) {
                        output[new_idx].transitions[cls] = TransitionValue{target.lr_state_id, NFA::TableType::Action, target.reduce_rule_id};
                    } else if constexpr (std::is_same_v<T, ActionTarget>) {
                        output[new_idx].transitions[cls] = TransitionValue{target.action_id, NFA::TableType::Semantic, NULL_STATE};
                    }
                }, value);
            }
        }

        logger.decreaseIndentLevel();
        return ClassifiedDFA{std::move(table), std::move(output)};
    }

    auto DFA::clear() -> void {
        states.clear();
    }
    auto DFA::getType() const -> DfaType {
        return nfa.isCharNfa() ? DfaType::Char : DfaType::Token;
    }

    auto DFA::check_dfa() -> void {
        std::size_t index = 0;
        try {
            for (const auto &state : states) {
                for (const auto &[sym, transitions] : state.transitions) {
                    if (std::holds_alternative<stdu::vector<std::string>>(sym)) {
                        const auto &nested_name = std::get<stdu::vector<std::string>>(sym);
                        AssertNe(nested_name.empty(), "Empty nested_name in state {}", index);
                    }
                    if (std::holds_alternative<DFATarget>(transitions)) {
                        const auto next = std::get<DFATarget>(transitions).dfa_state_id;
                        Assert(states.size() > next, "Out of bound transition {} in state {}", next, index);
                    }
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
        (void)dfa;
        os << "<DFA stream dump unavailable for current transition model>\n";
        return os;
    }
    auto operator<<(std::ostream& os, const ClassifiedDFA& dfa) -> std::ostream& {
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
            ++index;
        }
        return os;
    }
}