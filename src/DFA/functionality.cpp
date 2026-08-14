module DFA.functionality;

import DFA.API;
import DFA.Base;
import DFA;
import corelib;
import logging;
import hash;
import std;


void DFA::mergeTwoNFA(
    NFA &first,
    NFA &second,
    std::size_t rule_idx
) {
    if (second.getStates().empty()) {
        second.build(false);
    }

    if (second.getStates().empty()) {
        return;
    }

    const std::size_t state_offset =
        first.getStates().size();

    const std::size_t action_offset =
        first.getActionTable().size();

    const std::size_t semantic_offset =
        first.getSemanticTable().size();

    auto &first_states = first.getStates();
    const auto &second_states = second.getStates();

    /*
     * ------------------------------------------------------------
     * Copy states
     * ------------------------------------------------------------
     */
    for (const auto &state : second_states) {
        auto new_state = state;

        // DFA/NFA state references.
        for (auto &[symbol, target_ids] : new_state.transitions) {
            for (auto &target : target_ids) {
                target.next += state_offset;
            }
        }

        // Epsilon state references.
        utype::unordered_set<NFA::TransitionValue>
            rebased_epsilon;

        for (auto target : new_state.epsilon_transitions) {
            target.next += state_offset;
            rebased_epsilon.insert(target);
        }

        new_state.epsilon_transitions =
            std::move(rebased_epsilon);

        // ANY transition.
        if (new_state.any != NFA::NULL_STATE) {
            new_state.any += state_offset;
        }

        /*
         * Action-table references are NFA-local.
         */
        if (new_state.action_index != NFA::NULL_STATE) {
            new_state.action_index += action_offset;
        }

        /*
         * Semantic-table references are NFA-local.
         *
         * This is the important part for your current bug.
         */
        if (new_state.accept_binding.has_value()) {
            auto &binding = *new_state.accept_binding;

            if (binding.target_semantic_state.has_value()) {
                *binding.target_semantic_state += semantic_offset;
            }
        }

        first_states.emplace_back(std::move(new_state));
    }

    /*
     * ------------------------------------------------------------
     * Merge start states
     * ------------------------------------------------------------
     */
    first_states[0].epsilon_transitions.insert({
        state_offset,
        NFA::TableType::Action
    });

    /*
     * ------------------------------------------------------------
     * Merge LR / Action table
     * ------------------------------------------------------------
     */
    {
        auto &first_actions =
            first.getActionTable();

        const auto &second_actions =
            second.getActionTable();

        first_actions.insert(
            first_actions.end(),
            second_actions.begin(),
            second_actions.end()
        );
    }

    /*
     * ------------------------------------------------------------
     * Merge Semantic table
     * ------------------------------------------------------------
     */
    {
        auto &first_semantic =
            first.getSemanticTable();

        const auto &second_semantic =
            second.getSemanticTable();

        first_semantic.insert(
            first_semantic.end(),
            second_semantic.begin(),
            second_semantic.end()
        );
    }

}

auto DFA::mergeNFAS(
    const stdu::vector<NFA> &nfas
) -> std::pair<NFA, std::size_t> {
    NFA merged = nfas[0];

    if (merged.getStates().empty()) {
        merged.build(false);
    }
    std::size_t max_registers_count = 0;
    for (std::size_t i = 1; i < nfas.size(); ++i) {
        NFA next = nfas[i];

        mergeTwoNFA(
            merged,
            next,
            i
        );
        max_registers_count = std::max(max_registers_count, next.getRegistersCount());
    }
    merged.buildAcceptMap();
    return std::make_pair(merged, max_registers_count);
}
auto DFA::build(const AST::Tree &ast, const NFA &nfa) -> DFA {
    auto mutable_nfa = nfa;
    DFA dfa(&mutable_nfa);
    dfa.build();
    dfa.minimize();
    return dfa;
}
auto DFA::build(const AST::Tree &ast, const stdu::vector<NFA> &nfa_collection) -> std::tuple<ClassifiedDFA, stdu::vector<NFA::ActionState>, stdu::vector<LangAPI::Statements>, std::size_t> {
    auto [mergedNFA, max_registers_count] = mergeNFAS(nfa_collection);
    // construct tables
    auto dfa = DFA(&mergedNFA);

    Tlog::Branch b(logger, "DFA-build.log");
    // All state-local accept bindings have now been rebased.
    // Reconstruct the global accept map from them.
    logger.log(
        "Merged NFA action table: {}",
        mergedNFA.getActionTable().size()
    );

    for (std::size_t i = 0;
         i < mergedNFA.getActionTable().size();
         ++i) {

        const auto &action =
            mergedNFA.getActionTable()[i];

        logger.log(
            "  action[{}]: {} {}",
            i,
            static_cast<int>(action.action),
            action.variable.name
        );
         }

    dfa.build();
    dfa.minimize();
    return std::make_tuple(dfa.classify(), dfa.getLR(), dfa.getSemantic(), max_registers_count);
}