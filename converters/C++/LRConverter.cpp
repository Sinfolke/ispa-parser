#include <LRConverter.h>
void LRConverter::addIncludesCpp(std::ostringstream &out, const std::string &name) {
    out << "#include <" << name << ".h>\n";
}
void LRConverter::createActionTable(std::ostringstream &out) {
    const auto &table = data.getActionTable();
    const auto max_states = data.getMaxStatesCount();
    const auto tokens = data.getTerminalNames(); // Ensure this returns a vector in the same order as indexing
    out << "constexpr auto MAX_TERMINALS = " << tokens.size() << ";\n";
    out << "constexpr auto MAX_STATES = " << max_states << ";\n";
    out << "static constexpr std::array<std::array<std::optional<Action>, MAX_TERMINALS>, MAX_STATES> action_table = {\n";

    for (size_t state = 0; state < max_states; ++state) {
        out << "  {\n"; // Begin row
        for (size_t t = 0; t < tokens.size(); ++t) {
            std::string token = corelib::text::join(tokens[t], "_");
            auto it_state = table.find(state);
            if (it_state != table.end()) {
                const auto& state_table = it_state->second;
                auto it_action = state_table.find(token);
                if (it_action != state_table.end()) {
                    const auto& action = it_action->second;
                    out << "\tAction{::" << namespace_name << "::Action::" << LRParser::ActionTypeToString(action.type) << ", " << action.state << "},\n";
                } else {
                    out << "\tstd::nullopt,\n";
                }
            } else {
                out << "\tstd::nullopt,\n";
            }
        }
        out << "  },\n"; // End row
    }

    out << "};\n";
}
void LRConverter::createGotoTable(std::ostringstream &out) {
    const auto &table = data.getGotoTable(); // GotoTable is unordered_map<size_t, unordered_map<string, size_t>>
    const auto nonterminals = data.getNonTerminalNames(); // assume this returns std::vector<std::string> of all non-terminals

    const size_t max_states = data.getMaxStatesCount();
    const size_t max_nonterminals = nonterminals.size();

    // create mapping from non-terminal to column index
    std::unordered_map<std::string, size_t> nt_index_map;
    for (size_t i = 0; i < nonterminals.size(); ++i) {
        nt_index_map[corelib::text::join(nonterminals[i], "_")] = i;
    }

    // Output table constants
    out << "constexpr auto MAX_NONTERMINALS = " << max_nonterminals << ";\n";

    out << "static constexpr std::array<std::array<std::optional<size_t>, MAX_NONTERMINALS>, MAX_STATES> goto_table = {\n";

    for (size_t state = 0; state < max_states; ++state) {
        out << "  {";
        auto it = table.find(state);
        if (it != table.end()) {
            // temp row with all nullopt
            std::vector<std::string> row(max_nonterminals, "std::nullopt");

            for (const auto &[nt, next_state] : it->second) {
                auto idx = nt_index_map[nt];
                row[idx] = "std::make_optional(" + std::to_string(next_state) + ")";
            }

            for (size_t i = 0; i < max_nonterminals; ++i) {
                out << row[i];
                if (i + 1 < max_nonterminals)
                    out << ", ";
            }
        } else {
            // all nullopt for this row
            for (size_t i = 0; i < max_nonterminals; ++i) {
                out << "std::nullopt";
                if (i + 1 < max_nonterminals)
                    out << ", ";
            }
        }
        out << "},\n";
    }

    out << "};\n";
}
void LRConverter::createRulesTable(std::ostringstream &out) {
    auto rules = data.getRulesTable();
    out << "static constexpr std::array<std::pair<size_t, size_t>, " << rules.size() << "> rules_table = {\n";
    out << "\t{\n";
    for (size_t i = 0; i < rules.size(); ++i) {
        const auto &rule = rules[i];
        out << "\t{::" << namespace_name << "::Rules::" << corelib::text::join(rule.first, "_") << ", " << rule.second.first << "}";
        if (i + 1 < rules.size()) out << ",";
        out << "\n";
    }
    out << "\t}\n";
    out << "};\n";
}
void LRConverter::outputIR(std::ostringstream &out, std::string &filename) {
    addIncludesCpp(out, filename);
    createActionTable(out);
    createGotoTable(out);
    createRulesTable(out);
}
void LRConverter::outputHeader(std::ostringstream& out, std::string &filename) {
    auto [tokens, rules] = tree->getTokenAndRuleNames();
    createLibrary(out, namespace_name);
    createNamespace(out, namespace_name);
    createTypes(out, namespace_name);
    createTokensEnum(out, tokens);
    createRulesEnum(out, rules);
    getTypesFromStdlib(out);
    createToStringFunction(out);
    // createTypesNamespace(out, data_block_tokens, data_block_rules);
    // create_get_namespace(out, namespace_name, data_block_tokens, data_block_rules);
    create_lexer_header(out, tokens);
    create_parser_header(out);
    close_parser_header(out);
    close_library(out, namespace_name);
}
void LRConverter::output(std::string filename) {
    namespace_name = filename;
    std::ostringstream cpp_out, h_out;
    outputIR(cpp_out, filename);
    outputHeader(h_out, filename);
    std::ofstream cpp(filename + ".cpp");
    std::ofstream h(filename + ".h");
    if (!cpp) {
        std::cerr << "Failed open file for writing\n";
        return;
    }
    cpp << cpp_out.str();
    h << h_out.str();
}
extern "C" LRConverter_base* getLRConverter(LRParser& data, Tree& tree) {
    return new LRConverter(data, tree);
}