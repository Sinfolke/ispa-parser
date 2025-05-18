module;
module LRConverter;
void LRConverter::addIncludesCpp(std::ostringstream &out, const std::string &name) const {
    out << "#include \"" << name << ".h\"\n";
}
void LRConverter::createActionTable(std::ostringstream &out) const {
    auto max_terminals = tokens.size(); // Ensure tokens are in the correct order
    out << namespace_name << "::ActionTable " << namespace_name << "::Parser::action_table = {{\n";
    // convert map of states to row map
    const auto row_table = data->getActionTableAsRow();
    for (size_t state = 0; state < row_table.size(); ++state) {
        out << "\t{{/*" << state << "*/";
        const auto &value = row_table[state];
        std::vector<std::string> row(max_terminals, "std::nullopt");
        for (const auto &[name, action] : value) {
            auto search_name = name;
            if (search_name == std::vector<std::string>{"$"})
                search_name = std::vector<std::string>{"NONE"};
            auto find_it = std::find(tokens.begin(), tokens.end(), search_name);
            if (find_it == tokens.end())
                throw Error("Token '%$' in action table not found among 'tokens'. State '%$'", corelib::text::join(name, "_"), state);
            auto index = find_it - tokens.begin();
            row[index] = "/*" + corelib::text::join(search_name, "_") + "*/ std::make_optional(::" + namespace_name + "::Action{::" + namespace_name + "::Action::Action_type::" + LRParser::ActionTypeToString(action.type) + ", " + std::to_string(action.state) + "})";
        }
        out << row[0];
        for (auto it = row.begin() + 1; it != row.end(); ++it) {
            out << ", " << *it;
        }
        out << "}}";
        if (state + 1 < row_table.size()) out << ",";
        out << "\n";
    }
    out << "}};\n";
}
void LRConverter::createGotoTable(std::ostringstream &out) const {
    auto max_nonterminals = rules.size();
    auto row_table = data->getGotoTableAsRow();
    out << namespace_name << "::GotoTable " << namespace_name << "::Parser::goto_table = {{\n";
    for (size_t state = 0; state < row_table.size(); ++state) {
        out << "\t{{";
        const auto &value = row_table[state];
        std::vector<std::string> row(max_nonterminals, "std::nullopt");
        for (auto [name, new_state] : value) {
            auto search_name = name;
            if (search_name == std::vector<std::string>{"$"})
                search_name = std::vector<std::string>{"NONE"};
            auto find_it = std::find(rules.begin(), rules.end(), search_name);
            if (find_it == rules.end())
                throw Error("Token '%$' in goto table not found among 'rules'", corelib::text::join(name, "_"));
            auto index = find_it - rules.begin();
            row[index] = "std::make_optional(" + std::to_string(new_state) + ")";
        }
        out << row[0];
        for (auto it = row.begin() + 1; it != row.end(); ++it) {
            out << ", " << *it;
        }
        out << "}}";
        if (state + 1 < row_table.size()) out << ",";
        out << "\n";
    }
    out << "}};\n";
}
void LRConverter::createRulesTable(std::ostringstream &out) {
    rules_table = data->getRulesTable();
    out << namespace_name << "::RulesTable " << namespace_name << "::Parser::rules_table = {\n";
    out << "\t{\n";
    for (size_t i = 0; i < rules_table.size(); ++i) {
        const auto &rule = rules_table[i];
        out << "\t{::" << namespace_name << "::Rules::" << corelib::text::join(rule.first, "_") << ", " << rule.second.first << "}";
        if (i + 1 < rules_table.size()) out << ",";
        out << "\n";
    }
    out << "\t}\n";
    out << "};\n";
}
void LRConverter::createDFATable(std::ostringstream &out) {
    if (!data->isELR()) {
        return;
    }
    auto dt = reinterpret_cast<const ELRParser*>(data);
    const auto &dfa = dt->getDFA();

    out << namespace_name << "::DFATable " << namespace_name << "::Parser::dfa_table = {\n";
    max_dfa_token_map_size = std::max_element(dfa.begin(), dfa.end(), [](const ELRParser::DFA_state& state1, const ELRParser::DFA_state& state2) {
        return state1.transitions.size() < state2.transitions.size();
    })->transitions.size();    
    for (const auto &[nfa_states, transitions, action, place, epsilon_transition] : dfa) {
        // Write Action
        out << "\tstd::make_pair(::" << namespace_name << "::Action {";

        if (action.has_value()) {
            const auto &act = action.value();
            out << "::" << namespace_name << "::Action::" << LRParser::ActionTypeToString(act.type) << ", " << act.state;
        } else {
            out << "::" << namespace_name << "::Action::ERR, 0"; // Default Action if none (e.g., SHIFT 0)
        }

        out << "}, std::array<std::pair<::" << namespace_name << "::Tokens, size_t>, " << max_dfa_token_map_size + 2 << "> {";

        // Write transitions array
        size_t i = 0;
        for (const auto &[name, transition] : transitions) {
            if (i == 0) {
                out << "std::make_pair(::" << namespace_name << "::Tokens::NONE, " << epsilon_transition << "), ";
            }
            out << "std::make_pair(::" << namespace_name << "::Tokens::" << corelib::text::join(name, "_") << ", " << transition << ')';
            if (i + 1 != tokens.size()) {
                out << ", ";
            }
            i++;
        }
        while(max_dfa_token_map_size + 1 > i) {
            out << "std::make_pair(::" << namespace_name << "::Tokens::NONE, 0)";
            i++;
            if (i < max_dfa_token_map_size + 1) {
                out << ", ";
            }
        }

        out << "}),\n";
    }

    out << "};\n";
}
void LRConverter::addparseFromFunctions(std::ostringstream &out, bool hasDFA) const {
    if (hasDFA) {
        out << "void ::" << namespace_name << R"(::Parser::parseFromTokens() {
            auto pos = Lexer::iterator(lexer);
            parseFromPos(pos, action_table, goto_table, rules_table, dfa_table);
        })" << '\n';
            out << "void ::" << namespace_name << R"(::Parser::lazyParse() {
            if (lexer == nullptr) {
                Lexer lexer(text);
                auto pos = Lexer::lazy_iterator(lexer, text);
                parseFromPos(pos, action_table, goto_table, rules_table, dfa_table);
            } else {
                auto pos = Lexer::lazy_iterator(lexer, text);
                parseFromPos(pos, action_table, goto_table, rules_table, dfa_table);
            }
        })" << '\n';
    } else {
        out << "void ::" << namespace_name << R"(::Parser::parseFromTokens() {
            auto pos = Lexer::iterator(lexer);
            parseFromPos(pos, action_table, goto_table, rules_table);
        })" << '\n';
            out << "void ::" << namespace_name << R"(::Parser::lazyParse() {
            if (lexer == nullptr) {
                Lexer lexer(text);
                auto pos = Lexer::lazy_iterator(lexer, text);
                parseFromPos(pos, action_table, goto_table, rules_table);
            } else {
                auto pos = Lexer::lazy_iterator(lexer, text);
                parseFromPos(pos, action_table, goto_table, rules_table);
            }
        })" << '\n';
    }

}
void LRConverter::outputIR(std::ostringstream &out, std::string &filename) {
    addIncludesCpp(out, filename);
    LLIR_old tokens_ir(tree, true);
    LLConverter converter(tokens_ir, *tree, &lexer_code, &success_var, filename);
    data_block_tokens = converter.getDataBlockToken();
    data_block_rules = converter.getDataBlockRules();
    converter.addHeader(out);
    out << "std::string " << namespace_name << "::Parser::TokensToString(Tokens token) {\n"
        << "\t\treturn ::" << namespace_name << "::TokensToString(token);\n"
        << "\t}\n";
    out << "std::string " << namespace_name << "::Parser::RulesToString(Rules rule) {\n"
        << "\t\treturn ::" << namespace_name << "::RulesToString(rule);\n"
        << "\t}\n";
    converter.addStandardFunctionsLexer(out);
    addparseFromFunctions(out, data->isELR());
    //converter.addStandardFunctionsParser();
    converter.addLexerCode_Header(out);
    converter.convertLexerCode(lexer_code.getMembers(), out);
    converter.addLexerCode_Bottom(out, success_var);
    converter.convertData(out);
    max_states = data->getMaxStatesCount();
    createActionTable(out);
    createGotoTable(out);
    createRulesTable(out);
    createDFATable(out);
}
void LRConverter::outputHeader(std::ostringstream& out, std::string &filename) const {
    LLHeader::createLibrary(out, filename);
    LLHeader::createIncludes(out);
    LRHeader::addIncludes_h(out);
    LLHeader::createDefaultTypes(out);
    LLHeader::createNamespace(out, filename);
    LRHeader::createActionStruct(out);
    LLHeader::createTypes(out, filename);
    LLHeader::createTokensEnum(out, tokens);
    LLHeader::createRulesEnum(out, rules);
    LLHeader::getTypesFromStdlib(out);
    LLHeader::createToStringFunction(tokens, rules, out);
    if (data->isELR()) {
        LRHeader::createTableTypes(out, reinterpret_cast<const ELRParser*>(data)->getDFA().size());
    } else {
        LRHeader::createTableTypes(out, -1);
    }
    LLHeader::createTypesNamespace(out, data_block_tokens, data_block_rules);
    // create_get_namespace(out, namespace_name, data_block_tokens, data_block_rules);
    LLHeader::create_lexer_header(out, tokens);
    LRHeader::create_parser_header(out, data->isELR());
    LRHeader::addStandardFunctionsParser(out);
    LLHeader::close_parser_header(out);
    LLHeader::close_library(out, namespace_name);
}
void LRConverter::output(std::filesystem::path name) {
    namespace_name = name.filename().string();
    std::ostringstream cpp_out, h_out;
    this->tokens = tree->getTerminals();
    this->rules = tree->getNonTerminals();
    tokens.insert(tokens.begin(), {"NONE"});
    rules.insert(rules.begin(), {"NONE"});
    outputIR(cpp_out, namespace_name);
    outputHeader(h_out, namespace_name);
    std::ofstream cpp(name.string() + ".cpp");
    std::ofstream h(name.string() + ".h");
    if (!cpp) {
        std::cerr << "Failed open file for writing\n";
        return;
    }
    cpp << cpp_out.str();
    h << h_out.str();
}
extern "C" LRConverter_base* getLRConverter(LRParser& data, ASTPass& tree) {
    return new LRConverter(data, tree);
}