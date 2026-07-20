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
    // 1. Prepare First Character Dispatch Table structure
    fcdt.build();

    // Track which rule groups have already been built to map duplicates to the same index
    utype::unordered_map<stdu::vector<stdu::vector<std::string>>, std::size_t> built_group_to_index;

    // 2. Clear and reserve space for the new raw index dispatch table
    new_fcdt.clear();
    new_fcdt.reserve(fcdt.get().size());

    auto& dfa_collection = dfas.get();
    constexpr std::size_t INVALID_DFA_INDEX = std::numeric_limits<std::size_t>::max();

    // 3. Iterate over each group of rule names from FCDT
    bool any_group_built = false;
    for (const auto &rule_group : fcdt.get()) {
        // Handle empty entries safely to maintain 1:1 layout matching with characters
        if (rule_group.empty()) {
            new_fcdt.push_back(INVALID_DFA_INDEX);
            continue;
        }

        // Check if this identical rule-set configuration has already been compiled
        auto it = built_group_to_index.find(rule_group);
        if (it != built_group_to_index.end()) {
            new_fcdt.push_back(it->second); // Reuse the existing table index
            continue;
        }

        // The base index for this new group is simply the current collection size
        std::size_t base_dfa_index = dfa_collection.size();
        built_group_to_index[rule_group] = base_dfa_index;
        new_fcdt.push_back(base_dfa_index);

        // --- 4. Build Merged DFA for the entire rule group FIRST ---
        stdu::vector<NFA> group_nfas;
        group_nfas.reserve(rule_group.size());

        for (const auto &rule_name : rule_group) {
            NFA rule_nfa(
                ast, rule_name,
                &ast[rule_name].data_block,
                ast[rule_name].rule_members,
                rule_name == constants::whitespace,
                true
            );
            rule_nfa.build(true);
            group_nfas.push_back(std::move(rule_nfa));
        }

        // Safely push the base group machine into place
        dfa_collection.push_back(DFA::build(ast, group_nfas));
        any_group_built = true;

        // --- 5. Map Symbols and Process Nested Sub-Rules ---
        NameToDfaMap involved_symbols;

        for (const auto &rule_name : rule_group) {
            involved_symbols[rule_name] = base_dfa_index;
            name_to_dfa[rule_name] = base_dfa_index;

            stdu::vector<stdu::vector<std::string>> nested_names;
            accumulateNestedNames(ast[rule_name].rule_members, nested_names);

            for (const auto &nested_name : nested_names) {
                // The nested index automatically tracks the appending vector boundary
                std::size_t nested_dfa_index = dfa_collection.size();
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

                stdu::vector<NFA> nfas{std::move(nested_nfa)};
                dfa_collection.push_back(DFA::build(ast, nfas));
            }
        }

        // --- 6. Record tracking metadata for this group ---
        dispatch_names_involve.emplace(rule_group, std::move(involved_symbols));
    }

    // 7. Fallback: If FCDT produced no buildable groups (e.g., grammar changes
    //    resulted in an empty dispatch), build a single merged DFA over all token rules.
    //    This prevents empty DFA collections that make downstream tests meaningless.
    if (!any_group_built) {
        // Collect all token-like rules from AST. Heuristic used elsewhere: skip names ending with lowercase.
        stdu::vector<stdu::vector<std::string>> token_rule_names;
        for (const auto &entry : ast) {
            const auto &name = entry.first;
            if (corelib::text::isLower(name.back())) {
                continue; // likely non-token (e.g., parser rule)
            }
            token_rule_names.push_back(name);
        }

        if (!token_rule_names.empty()) {
            // Build a merged DFA for all tokens to serve as base index 0
            stdu::vector<NFA> group_nfas;
            group_nfas.reserve(token_rule_names.size());
            for (const auto &rule_name : token_rule_names) {
                NFA rule_nfa(
                    ast, rule_name,
                    &ast[rule_name].data_block,
                    ast[rule_name].rule_members,
                    rule_name == constants::whitespace,
                    true
                );
                rule_nfa.build(true);
                group_nfas.push_back(std::move(rule_nfa));
            }

            std::size_t base_dfa_index = dfa_collection.size();
            dfa_collection.push_back(DFA::build(ast, group_nfas));

            // Map each token (and its nested members) to DFAs as in the main path
            NameToDfaMap involved_symbols;
            for (const auto &rule_name : token_rule_names) {
                involved_symbols[rule_name] = base_dfa_index;
                name_to_dfa[rule_name] = base_dfa_index;

                stdu::vector<stdu::vector<std::string>> nested_names;
                accumulateNestedNames(ast[rule_name].rule_members, nested_names);
                for (const auto &nested_name : nested_names) {
                    std::size_t nested_dfa_index = dfa_collection.size();
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
                    stdu::vector<NFA> nfas{std::move(nested_nfa)};
                    dfa_collection.push_back(DFA::build(ast, nfas));
                }
            }

            // Record as a synthetic dispatch entry for diagnostics
            if (!token_rule_names.empty()) {
                dispatch_names_involve.emplace(token_rule_names, std::move(involved_symbols));
            }
        }
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