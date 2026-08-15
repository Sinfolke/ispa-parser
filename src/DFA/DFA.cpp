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

        utype::unordered_map<
            std::pair<Closure, NFA::TransitionKey>,
            Closure
        > closure_cache;

        std::queue<Closure> work;

        /*
         * Maps NFA state index -> list of DFA state indices containing it.
         */
        utype::unordered_map<
            std::size_t,
            std::vector<std::size_t>
        > nfa_to_dfa;

        std::vector<Closure> dfa_closures;

        /*
         * Deduplication caches for table construction during subset generation.
         * Key: (NFA table index, target DFA state index) -> DFA table index
         */
        std::map<std::pair<std::size_t, std::size_t>, std::size_t> action_remap;
        std::map<std::pair<std::size_t, std::size_t>, std::size_t> semantic_remap;

        states.clear();
        lr_table = nfa.getActionTable();
        semantic_table.clear();

        // ================================================================
        // 1. Start subset construction
        // ================================================================

        StateSet start_set = {0};
        Closure start_closure(nfa, start_set);

        const std::size_t start_idx = states.makeNew();

        dfa_state_map.emplace(start_closure, start_idx);
        dfa_closures.push_back(start_closure);
        work.push(start_closure);

        // ================================================================
        // 2. Subset construction
        // ================================================================

        while (!work.empty()) {
            Closure current = work.front();
            work.pop();

            const std::size_t current_dfa_index = dfa_state_map.at(current);

            // Register NFA -> DFA membership and acceptance priority
            std::optional<NFA::TokenBinding> best_binding;

            for (const std::size_t nfa_index : current) {
                nfa_to_dfa[nfa_index].push_back(current_dfa_index);

                const auto &nfa_state = nfa.getStates().at(nfa_index);
                auto accept_it = nfa.getAcceptMap().find(nfa_index);

                std::optional<NFA::TokenBinding> binding =
                    accept_it != nfa.getAcceptMap().end()
                        ? std::make_optional(accept_it->second)
                        : nfa_state.accept_binding;

                if (!binding.has_value())
                    continue;

                if (!best_binding.has_value() || binding->token_id < best_binding->token_id) {
                    best_binding = binding;
                }
            }

            states[current_dfa_index].accept_binding = best_binding;

            // Collect outgoing transitions
            struct TransitionInfo {
                NFA::TableType table_type;
                std::size_t table_index;
                Closure closure;
            };

            std::vector<std::pair<NFA::TransitionKey, TransitionInfo>> transitions;

            for (const std::size_t nfa_index : current) {
                const auto &nfa_state = nfa.getStates().at(nfa_index);

                for (const auto &[symbol, ids] : nfa_state.transitions) {
                    const auto cache_key = std::make_pair(current, symbol);

                    if (!closure_cache.contains(cache_key)) {
                        closure_cache.emplace(
                            cache_key,
                            Closure(nfa, current.get(), symbol)
                        );
                    }

                    const Closure &closure_set = closure_cache.at(cache_key);
                    if (closure_set.empty())
                        continue;

                    for (const auto &transition : ids) {
                        transitions.emplace_back(
                            symbol,
                            TransitionInfo {
                                .table_type = transition.table_type,
                                .table_index = transition.next,
                                .closure = closure_set
                            }
                        );
                    }
                }
            }

            // Construct DFA transitions
            for (const auto &[symbol, info] : transitions) {
                const auto &closure_set = info.closure;
                std::size_t target_index;

                auto state_it = dfa_state_map.find(closure_set);
                if (state_it == dfa_state_map.end()) {
                    target_index = states.makeNew();
                    dfa_state_map.emplace(closure_set, target_index);
                    dfa_closures.push_back(closure_set);
                    work.push(closure_set);
                } else {
                    target_index = state_it->second;
                }

                auto &dfa_transition = states[current_dfa_index].transitions[symbol];

                // 1. Resolve action_index from transition or target NFA closure states
                std::size_t action_idx = NFA::NULL_STATE;
                if (info.table_type == NFA::TableType::Action) {
                    action_idx = info.table_index;
                } else {
                    for (const std::size_t nfa_st : closure_set) {
                        if (nfa_st < nfa.getStates().size() &&
                            nfa.getStates()[nfa_st].action_index != NFA::NULL_STATE) {
                            action_idx = nfa.getStates()[nfa_st].action_index;
                            break;
                        }
                    }
                }

                // 2. Emit ActionTarget or SemanticTarget / DFATarget accordingly
                if (action_idx != NFA::NULL_STATE && action_idx < lr_table.size()) {
                    lr_table[action_idx].DFA_next_state = target_index;
                    dfa_transition = ActionTarget {
                        .id = action_idx,
                        .action = lr_table[action_idx].action
                    };
                } else if (info.table_type == NFA::TableType::Semantic) {
                    dfa_transition = SemanticTarget {
                        .id = info.table_index
                    };
                } else {
                    dfa_transition = DFATarget {
                        .id = target_index
                    };
                }
            }
        }

        // ================================================================
        // 3. Resolve semantic REDUCE states
        // ================================================================

        for (std::size_t dfa_index = 0; dfa_index < states.size(); ++dfa_index) {
            auto &binding = states[dfa_index].accept_binding;

            if (!binding.has_value() || !binding->target_semantic_state.has_value())
                continue;

            const std::size_t nfa_semantic_index = *binding->target_semantic_state;
            if (nfa_semantic_index >= nfa.getSemanticTable().size()) {
                throw Error("DFA state {} references invalid semantic state {}", dfa_index, nfa_semantic_index);
            }

            const auto &nfa_semantic = nfa.getSemanticTable().at(nfa_semantic_index);
            std::size_t next_dfa_state = NFA::NULL_STATE;

            if (nfa_semantic.next_state != NFA::NULL_STATE) {
                const auto it = nfa_to_dfa.find(nfa_semantic.next_state);
                if (it == nfa_to_dfa.end() || it->second.empty()) {
                    throw Error("Cannot resolve semantic next NFA state {} to DFA state", nfa_semantic.next_state);
                }
                next_dfa_state = it->second.front();
            }

            const auto key = std::make_pair(nfa_semantic_index, next_dfa_state);
            auto [it, inserted] = semantic_remap.emplace(key, semantic_table.size());

            if (inserted) {
                auto semantic_copy = nfa_semantic;
                semantic_copy.next_state = next_dfa_state;
                semantic_table.push_back(std::move(semantic_copy));
            }

            binding->target_semantic_state = it->second;
        }

        // ================================================================
        // 4. Validate
        // ================================================================

        if (states.empty())
            throw Error("DFA cannot be empty");

        check_dfa();
        return states;
    }

    void DFA::optimizeRegistersAndLRTable() {
        std::vector<bool> used(lr_table.size(), false);
        for (const auto &state : states) {
            for (const auto &[symbol, target] : state.transitions) {
                if (std::holds_alternative<ActionTarget>(target)) {
                    const std::size_t idx = std::get<ActionTarget>(target).id;
                    if (idx < used.size()) used[idx] = true;
                }
            }
        }

        std::vector<NFA::ActionState> deduplicated_lr_table;
        std::unordered_map<std::size_t, std::size_t> lr_index_remap;

        for (std::size_t i = 0; i < lr_table.size(); ++i) {
            if (!used[i]) continue;
            const auto &entry = lr_table[i];
            std::size_t canonical_idx = NFA::NULL_STATE;

            for (std::size_t j = 0; j < deduplicated_lr_table.size(); ++j) {
                if (deduplicated_lr_table[j].action == entry.action &&
                    deduplicated_lr_table[j].variable == entry.variable &&
                    deduplicated_lr_table[j].DFA_next_state == entry.DFA_next_state) {
                    canonical_idx = j;
                    break;
                    }
            }

            if (canonical_idx == NFA::NULL_STATE) {
                canonical_idx = deduplicated_lr_table.size();
                deduplicated_lr_table.push_back(entry);
            }
            lr_index_remap[i] = canonical_idx;
        }

        lr_table = std::move(deduplicated_lr_table);

        for (auto &state : states) {
            for (auto &[symbol, target] : state.transitions) {
                if (std::holds_alternative<ActionTarget>(target)) {
                    auto &act = std::get<ActionTarget>(target);
                    if (auto it = lr_index_remap.find(act.id); it != lr_index_remap.end()) {
                        act.id = it->second;
                    }
                }
            }
        }
    }

    void DFA::optimizeSemanticTable() {
        const auto &source_semantic_table = semantic_table;
        std::vector<bool> used(source_semantic_table.size(), false);

        for (std::size_t i = 0; i < states.size(); ++i) {
            // Mark accept bindings
            auto &binding = states[i].accept_binding;
            if (binding.has_value() && binding->target_semantic_state.has_value()) {
                const std::size_t idx = *binding->target_semantic_state;
                if (idx < used.size()) used[idx] = true;
            }

            // Mark semantic transitions
            for (const auto &[symbol, target] : states[i].transitions) {
                if (std::holds_alternative<SemanticTarget>(target)) {
                    const std::size_t idx = std::get<SemanticTarget>(target).id;
                    if (idx < used.size()) used[idx] = true;
                }
            }
        }

        std::unordered_map<std::size_t, std::size_t> remap;
        std::vector<NFA::SemanticState> compacted;
        for (std::size_t i = 0; i < source_semantic_table.size(); ++i) {
            if (!used[i]) continue;
            remap[i] = compacted.size();
            compacted.push_back(source_semantic_table[i]);
        }

        // Remap bindings
        for (std::size_t i = 0; i < states.size(); ++i) {
            auto &binding = states[i].accept_binding;
            if (!binding.has_value() || !binding->target_semantic_state.has_value())
                continue;

            const std::size_t old_idx = *binding->target_semantic_state;
            if (auto remap_it = remap.find(old_idx); remap_it != remap.end()) {
                binding->target_semantic_state = remap_it->second;
            } else {
                binding->target_semantic_state.reset();
            }
        }

        // Remap transition targets
        for (auto &state : states) {
            for (auto &[symbol, target] : state.transitions) {
                if (std::holds_alternative<SemanticTarget>(target)) {
                    auto &sem = std::get<SemanticTarget>(target);
                    if (auto it = remap.find(sem.id); it != remap.end()) {
                        sem.id = it->second;
                    }
                }
            }
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

        for (const auto &[symbol, target] : s.transitions) {
            std::visit([&](auto &&arg) {
                using T = std::decay_t<decltype(arg)>;

                if constexpr (std::is_same_v<T, DFATarget>) {
                    key.push_back(TransitionKeyExt{
                        .symbol = symbol,
                        .table_type = NFA::TableType::DFA,
                        .action = NFA::Action::UNDEF,
                        .action_id = NFA::NULL_STATE,
                        .target_partition = partition_of.at(arg.id)
                    });
                }
                else if constexpr (std::is_same_v<T, ActionTarget>) {
                    const auto &act_entry = lr_table.at(arg.id);
                    const std::size_t target_part = (act_entry.DFA_next_state != NFA::NULL_STATE)
                        ? partition_of.at(act_entry.DFA_next_state)
                        : NFA::NULL_STATE;

                    key.push_back(TransitionKeyExt{
                        .symbol = symbol,
                        .table_type = NFA::TableType::Action,
                        .action = act_entry.action,
                        .action_id = arg.id,
                        .target_partition = target_part
                    });
                }
                else if constexpr (std::is_same_v<T, SemanticTarget>) {
                    const auto &sem_entry = semantic_table.at(arg.id);
                    std::size_t target_part = (sem_entry.next_state != NFA::NULL_STATE)
                        ? partition_of.at(sem_entry.next_state)
                        : NFA::NULL_STATE;

                    key.push_back(TransitionKeyExt{
                        .symbol = symbol,
                        .table_type = NFA::TableType::Semantic,
                        .action = NFA::Action::UNDEF,
                        .action_id = arg.id,
                        .target_partition = target_part
                    });
                }
            }, target);
        }

        std::sort(key.begin(), key.end());
        return key;
    }

    auto DFA::minimize() -> States<SingleState> {
        Tlog::Branch b(logger, "DFA/minimize.log");

        const auto &input = states;
        const std::size_t n = input.size();

        if (n == 0) {
            return States<SingleState>(&nfa);
        }

        // 1. Initial partition
        std::unordered_map<std::size_t, std::size_t> partition_of;
        std::unordered_map<std::size_t, std::size_t> initial_hash_to_class;
        std::size_t class_count = 0;

        for (std::size_t i = 0; i < n; ++i) {
            const std::size_t hash = initialClass(input[i]);
            auto [it, inserted] = initial_hash_to_class.emplace(hash, class_count);
            if (inserted) ++class_count;
            partition_of[i] = it->second;
        }

        // 2. Partition refinement
        bool changed = true;
        while (changed) {
            changed = false;

            std::unordered_map<std::size_t, std::size_t> new_partition;
            std::map<std::pair<std::size_t, std::vector<TransitionKeyExt>>, std::size_t> signature_to_class;
            std::size_t new_class_count = 0;

            for (std::size_t i = 0; i < n; ++i) {
                const auto key = refinementKey(input[i], partition_of);
                const std::size_t accept_hash = initialClass(input[i]);
                const auto signature = std::make_pair(accept_hash, key);

                auto [it, inserted] = signature_to_class.emplace(signature, new_class_count);
                if (inserted) ++new_class_count;

                new_partition[i] = it->second;
                if (new_partition[i] != partition_of[i])
                    changed = true;
            }

            partition_of = std::move(new_partition);
        }

        // 3. Assign new DFA indices to surviving classes
        std::unordered_map<std::size_t, std::size_t> class_to_new_index;
        States<SingleState> output(&nfa);

        for (std::size_t i = 0; i < n; ++i) {
            const std::size_t cls = partition_of.at(i);
            if (!class_to_new_index.contains(cls)) {
                class_to_new_index.emplace(cls, output.makeNew());
            }
        }

        // 4. Construct minimized state transitions
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
                        const auto target_class = partition_of.at(arg.id);
                        destination.transitions[symbol] = DFATarget{ class_to_new_index.at(target_class) };
                    }
                    else if constexpr (std::is_same_v<T, ActionTarget>) {
                        destination.transitions[symbol] = arg;
                    }
                    else if constexpr (std::is_same_v<T, SemanticTarget>) {
                        destination.transitions[symbol] = arg;
                    }
                }, target);
            }
        }

        // 5. Reachability analysis
        std::vector<bool> reachable(output.size(), false);
        std::queue<std::size_t> q;

        if (!output.empty()) {
            reachable[0] = true;
            q.push(0);
        }

        while (!q.empty()) {
            const std::size_t current = q.front();
            q.pop();

            for (const auto &[symbol, target] : output[current].transitions) {
                std::size_t next_st = NFA::NULL_STATE;

                if (std::holds_alternative<DFATarget>(target)) {
                    next_st = std::get<DFATarget>(target).id;
                } else if (std::holds_alternative<ActionTarget>(target)) {
                    next_st = lr_table.at(std::get<ActionTarget>(target).id).DFA_next_state;
                } else if (std::holds_alternative<SemanticTarget>(target)) {
                    next_st = semantic_table.at(std::get<SemanticTarget>(target).id).next_state;
                }

                if (next_st != NFA::NULL_STATE && next_st < reachable.size() && !reachable[next_st]) {
                    reachable[next_st] = true;
                    q.push(next_st);
                }
            }
        }

        // 6. Prune unreachable states & rebase table pointers
        States<SingleState> reachable_output(&nfa);
        std::vector<std::size_t> state_remap(output.size(), NFA::NULL_STATE);

        for (std::size_t i = 0; i < output.size(); ++i) {
            if (reachable[i]) {
                state_remap[i] = reachable_output.makeNew();
            }
        }

        // Map original DFA state targets through class collapse + reachability pruning
        auto resolve_state = [&](std::size_t old_dfa_idx) -> std::size_t {
            if (old_dfa_idx == NFA::NULL_STATE) return NFA::NULL_STATE;
            std::size_t cls = partition_of.at(old_dfa_idx);
            std::size_t interim_idx = class_to_new_index.at(cls);
            return state_remap[interim_idx];
        };

        for (auto &act : lr_table) {
            act.DFA_next_state = resolve_state(act.DFA_next_state);
        }

        for (auto &semantic : semantic_table) {
            semantic.next_state = resolve_state(semantic.next_state);
        }

        for (std::size_t i = 0; i < output.size(); ++i) {
            if (!reachable[i]) continue;

            const std::size_t new_idx = state_remap[i];
            auto &destination = reachable_output[new_idx];
            const auto &source = output[i];

            destination.accept_binding = source.accept_binding;

            for (const auto &[symbol, target] : source.transitions) {
                std::visit([&](auto &&arg) {
                    using T = std::decay_t<decltype(arg)>;

                    if constexpr (std::is_same_v<T, DFATarget>) {
                        std::size_t final_target = resolve_state(arg.id);
                        if (final_target != NFA::NULL_STATE) {
                            destination.transitions[symbol] = DFATarget{ final_target };
                        }
                    } else {
                        destination.transitions[symbol] = arg;
                    }
                }, target);
            }
        }

        this->states = std::move(reachable_output);

        // 7. Re-optimize auxiliary action and semantic state tables
        optimizeRegistersAndLRTable();
        optimizeSemanticTable();

        return this->states;
    }

    auto DFA::classify() -> ClassifiedDFA {
        if (!nfa.isCharNfa()) {
            throw Error("classify() only applies to character-keyed (CharMachineDFA) automata");
        }

        constexpr std::size_t ALPHABET_SIZE = 256;
        const std::size_t n = states.size();

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
                            sig.emplace_back(NFA::TableType::DFA, target.id);
                        } else if constexpr (std::is_same_v<T, ActionTarget>) {
                            sig.emplace_back(NFA::TableType::Action, target.id);
                        } else if constexpr (std::is_same_v<T, SemanticTarget>) {
                            sig.emplace_back(NFA::TableType::Semantic, target.id);
                        }
                    }, it->second);
                }
            }
            auto [it, inserted] = class_of_signature.try_emplace(sig, class_of_signature.size());
            table.char_to_class[c] = it->second;
        }
        table.num_classes = class_of_signature.size();

        States<State<ClassTransitions>> output(&nfa);
        for (std::size_t i = 0; i < n; ++i) {
            auto new_idx = output.makeNew();
            output[new_idx].accept_binding = states[i].accept_binding;
            output[new_idx].transitions.assign(table.num_classes, TransitionValue{});

            for (const auto &[symbol, value] : states[i].transitions) {
                if (!std::holds_alternative<char>(symbol)) continue;
                unsigned char c = static_cast<unsigned char>(std::get<char>(symbol));
                std::size_t cls = table.char_to_class[c];

                std::visit([&](auto &&target) {
                    using T = std::decay_t<decltype(target)>;
                    if constexpr (std::is_same_v<T, DFATarget>) {
                        output[new_idx].transitions[cls] = TransitionValue{target.id, NFA::TableType::DFA, NULL_STATE};
                    } else if constexpr (std::is_same_v<T, ActionTarget>) {
                        output[new_idx].transitions[cls] = TransitionValue{target.id, NFA::TableType::Action, NULL_STATE};
                    } else if constexpr (std::is_same_v<T, SemanticTarget>) {
                        output[new_idx].transitions[cls] = TransitionValue{target.id, NFA::TableType::Semantic, NULL_STATE};
                    }
                }, value);
            }
        }

        return ClassifiedDFA{std::move(table), std::move(output)};
    }

    auto DFA::clear() -> void {
        states.clear();
        lr_table.clear();
        semantic_table.clear();
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
                        const auto next = std::get<DFATarget>(transitions).id;
                        Assert(states.size() > next, "Out of bound transition {} in state {}", next, index);
                    } else if (std::holds_alternative<ActionTarget>(transitions)) {
                        const auto act_idx = std::get<ActionTarget>(transitions).id;
                        Assert(lr_table.size() > act_idx, "Out of bound action index {} in state {}", act_idx, index);
                    } else if (std::holds_alternative<SemanticTarget>(transitions)) {
                        const auto sem_idx = std::get<SemanticTarget>(transitions).id;
                        Assert(semantic_table.size() > sem_idx, "Out of bound semantic index {} in state {}", sem_idx, index);
                    }
                }
                ++index;
            }
        } catch (Error &e) {
            std::cout << "[MDFA] Check Failed > " << e.what() << '\n';
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
                if (t.next == NULL_STATE) continue;
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