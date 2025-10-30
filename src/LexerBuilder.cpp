module LexerBuilder;
import corelib;
import LLIR.Builder;
import LLIR.Builder.Data;
import LLIR.Builder.DataWrapper;
import LLIR.Rule.MemberBuilder;
import LLIR.RuleBuilder;
import NFA;
import constants;
import DFA.API;
import DFA.functionality;
import DFA.CharMachineDFA;
import DFA.TokenMachineDFA;
import cpuf.printf;
import std;

void accumulateNestedNames(stdu::vector<AST::RuleMember> members, stdu::vector<stdu::vector<std::string>> &names) {
    for (const auto &mem : members) {
        if (mem.isGroup())
            accumulateNestedNames(mem.getGroup().values, names);
        if (mem.isOp())
            accumulateNestedNames(mem.getOp().options, names);
        if (mem.isName())
            names.push_back(mem.getName().name);
    }
}
void LexerBuilder::build() {
    // 1. Prepare FCDT (function call dependency tree)
    fcdt.build();

    // 2. Track which function chains (mem groups) were already processed
    utype::unordered_set<stdu::vector<stdu::vector<std::string>>> built_groups;

    std::size_t dfa_count = 0;

    // 3. Iterate over each group of rule names from FCDT
    for (const auto &rule_group : fcdt.get()) {
        if (rule_group.empty())
            continue;

        // Skip already processed rule groups
        if (built_groups.contains(rule_group))
            continue;
        built_groups.insert(rule_group);

        NameToDfaMap involved_symbols;
        auto current_group = rule_group;

        std::size_t base_dfa_index = 0;
        bool has_base_dfa = false;

        // --- 4. Process each rule in the group ---
        for (const auto &rule_name : rule_group) {
            // Assign a DFA index for this group (shared for all rules)
            if (!has_base_dfa) {
                base_dfa_index = dfa_count++;
                has_base_dfa = true;
            }

            involved_symbols[rule_name] = base_dfa_index;
            name_to_dfa[rule_name] = base_dfa_index;

            // --- 5. Collect nested rule names and build DFAs for them ---
            stdu::vector<stdu::vector<std::string>> nested_names;
            accumulateNestedNames(ast[rule_name].rule_members, nested_names);

            for (const auto &nested_name : nested_names) {
                std::size_t nested_dfa_index = dfa_count++;
                name_to_dfa[nested_name] = nested_dfa_index;
                involved_symbols[nested_name] = nested_dfa_index;

                NFA nested_nfa(
                    ast, nested_name,
                    &ast[nested_name].data_block,
                    ast[nested_name].rule_members,
                    nested_name == constants::whitespace,
                    true
                );

                nested_nfa.build(true);
                stdu::vector nfas {nested_nfa};
                dfas.get().push_back(DFA::build(ast, nfas));
            }
        }

        // --- 6. Build merged DFA for the entire rule group ---
        if (has_base_dfa) {
            stdu::vector<NFA> group_nfas;

            for (const auto &rule_name : current_group) {
                NFA rule_nfa(
                    ast, rule_name,
                    &ast[rule_name].data_block,
                    ast[rule_name].rule_members,
                    rule_name == constants::whitespace,
                    true
                );

                rule_nfa.build(true);
                group_nfas.push_back(rule_nfa);
            }

            auto merged_dfa = DFA::build(ast, group_nfas);
            auto &dfa_collection = dfas.get();

            // Insert merged DFA at consistent position
            if (base_dfa_index >= dfa_collection.size()) {
                dfa_collection.push_back(merged_dfa);
            } else {
                dfa_collection.insert(dfa_collection.begin() + base_dfa_index, merged_dfa);
            }
        }

        // --- 7. Record which names are part of this DFA set ---
        dispatch_names_involve.emplace(current_group, involved_symbols);
    }
}
auto LexerBuilder::getDataBlocks() const -> LLIR::DataBlockList {
    LLIR::DataBlockList list;
    for (const auto &[name, rule] : ast) {
        if (corelib::text::isLower(name.back()))
            continue;
        // token here
        DFA::Collection<DFA::TokenMachineDFA> dfas; LLIR::RuleBuilder builder(ast, name, rule, dfas); builder.build();
        list[name] = builder.getData().block;
    }
    return list;
}

auto LexerBuilder::getStateSet() const -> DFA::Collection<DFA::CharMachineDFA>::StateSet_t {
    return dfas.getStateSet();
}