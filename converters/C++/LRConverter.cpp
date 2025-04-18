#include <LRConverter.h>
void LRConverter::addIncludesCpp(std::ostringstream &out, const std::string &name) {
    out << "#include \"" << name << ".h\"\n";
}
void LRConverter::createActionTable(std::ostringstream &out) {
    const auto &table = data->getActionTable();
    const auto tokens = data->getTerminalNames(); // Ensure this returns a vector in the same order as indexing
    max_terminals = tokens.size();
    out << namespace_name << "::ActionTable " << namespace_name << "::Parser::action_table = {{\n";

    for (size_t state = 0; state < max_states; ++state) {
        out << "  {{\n"; // Begin row
        for (size_t t = 0; t < tokens.size(); ++t) {
            std::string token = corelib::text::join(tokens[t], "_");
            auto it_state = table.find(state);
            if (it_state != table.end()) {
                const auto& state_table = it_state->second;
                auto it_action = state_table.find(token);
                if (it_action != state_table.end()) {
                    const auto& action = it_action->second;
                    out << "\t::" << namespace_name << "::Action{::" << namespace_name << "::Action::" << LRParser::ActionTypeToString(action.type) << ", " << action.state << "},\n";
                } else {
                    out << "\tstd::nullopt,\n";
                }
            } else {
                out << "\tstd::nullopt,\n";
            }
        }
        out << "\t}},\n"; // End row
    }

    out << "}};\n";
}
void LRConverter::createGotoTable(std::ostringstream &out) {
    const auto &table = data->getGotoTable(); // GotoTable is unordered_map<size_t, unordered_map<string, size_t>>
    const auto nonterminals = data->getNonTerminalNames(); // assume this returns std::vector<std::string> of all non-terminals
    max_nonterminals = nonterminals.size();

    // create mapping from non-terminal to column index
    std::unordered_map<std::string, size_t> nt_index_map;
    for (size_t i = 0; i < nonterminals.size(); ++i) {
        nt_index_map[corelib::text::join(nonterminals[i], "_")] = i;
    }

    out << namespace_name << "::GotoTable " << namespace_name << "::Parser::goto_table = {{\n";

    for (size_t state = 0; state < max_states; ++state) {
        out << "\t{{";
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
        out << "}},\n";
    }

    out << "}};\n";
}
void LRConverter::createRulesTable(std::ostringstream &out) {
    auto rules = data->getRulesTable();
    out << namespace_name << "::RulesTable " << namespace_name << "::Parser::rules_table = {\n";
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
    auto rules_fullname = data->getNonTerminalNames();
    auto tokens_fullname = data->getTerminalNames();
    std::vector<std::string> tokens, rules;
    std::for_each(tokens_fullname.begin(), tokens_fullname.end(), [&tokens](const auto &vec){
        if (std::find(tokens.begin(), tokens.end(), corelib::text::join(vec, "_")) == tokens.end())
            tokens.push_back(corelib::text::join(vec, "_"));
    });
    std::for_each(rules_fullname.begin(), rules_fullname.end(), [&rules](const auto &vec){
        if (std::find(rules.begin(), rules.end(), corelib::text::join(vec, "_")) == rules.end())
            rules.push_back(corelib::text::join(vec, "_"));
    });
    LLIR tokens_ir(tree->getRawTree(), true);
    tokens_ir.makeIR();
    tokens_ir.optimizeIR();
    LLConverter converter(tokens_ir, *tree, &lexer_code, &success_var, filename);
    auto datablocks = tree->get_data_blocks(tokens_ir);
    data_block_tokens = datablocks.first;
    data_block_rules = datablocks.second;
    converter.addHeader(out);
    converter.addTokensToString(tokens, out);
    converter.addRulesToString(rules, out);
    converter.addStandardFunctionsLexer(out);
    //converter.addStandardFunctionsParser();
    converter.addLexerCode_Header(out);
    converter.convertLexerCode(lexer_code.getData(), out);
    converter.addLexerCode_Bottom(out, success_var.var);
    converter.convertData(out);
    max_states = data->getMaxStatesCount();
    createActionTable(out);
    createGotoTable(out);
    createRulesTable(out);
}
void LRConverter::addIncludes_h(std::ostringstream &out) {
    out << "#include <optional>\n\n";
}
void LRConverter::createActionStruct(std::ostringstream &out) {
    out << "\t" << R"(struct Action {
        enum Action_type {
            SHIFT, REDUCE, ACCEPT, ERROR
        };
        Action_type type;
        size_t state;
    };
)";

}
void LRConverter::createTableTypes(std::ostringstream &out) {
    out
        << "\t\tusing ActionTable = std::array<std::array<std::optional<::" << namespace_name << "::Action>, "<< max_terminals << ">, " << max_states << ">;\n"
        << "\t\tusing GotoTable = std::array<std::array<std::optional<size_t>, " << max_nonterminals << ">, " << max_states << ">;\n"
        << "\t\tusing RulesTable = std::array<std::pair<Rules, size_t>, " << max_nonterminals << ">;\n"
    ;
}
void LRConverter::create_parser_header(std::ostringstream &out) {
    out << "\tclass Parser : public ISPA_STD::LRParser_base<Tokens, Rules, Action, ActionTable, GotoTable, RulesTable> {\n"
        << "\t\tprivate:\n"
        << "\t\t\tstatic ActionTable action_table;\n"
        << "\t\t\tstatic GotoTable goto_table;\n"
        << "\t\t\tstatic RulesTable rules_table;\n";
}
void LRConverter::outputHeader(std::ostringstream& out, std::string &filename) {
    auto tokens_fullname = data->getTerminalNames();
    auto rules_fullname = data->getNonTerminalNames();
    std::vector<std::string> tokens, rules;
    std::for_each(tokens_fullname.begin(), tokens_fullname.end(), [&tokens](const auto &vec){
        if (std::find(tokens.begin(), tokens.end(), corelib::text::join(vec, "_")) == tokens.end())
            tokens.push_back(corelib::text::join(vec, "_"));
    });
    std::for_each(rules_fullname.begin(), rules_fullname.end(), [&rules](const auto &vec){
        if (std::find(rules.begin(), rules.end(), corelib::text::join(vec, "_")) == rules.end())
            rules.push_back(corelib::text::join(vec, "_"));
    });
    createLibrary(out, filename);
    createIncludes(out);
    addIncludes_h(out);
    createDefaultTypes(out);
    createNamespace(out, filename);
    createActionStruct(out);
    createTypes(out, filename);
    createTokensEnum(out, tokens);
    createRulesEnum(out, rules);
    getTypesFromStdlib(out);
    createToStringFunction(out);
    createTableTypes(out);
    createTypesNamespace(out, data_block_tokens, data_block_rules);
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