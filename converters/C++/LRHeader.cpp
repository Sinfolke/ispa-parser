module LRHeader;
import std;
void LRHeader::addIncludes_h(std::ostringstream &out) const {
    out << "#include <optional>\n\n";
}
void LRHeader::createActionStruct(std::ostringstream &out) const {
    out << "\t" << R"(struct Action {
        enum Action_type {
            SHIFT, REDUCE, ACCEPT, DFA_RESOLVE, ERROR 
        };
        Action_type type;
        size_t state;
    };
)";
}
void LRHeader::createTableTypes(std::ostringstream &out, long long DFA_size) const {
    out
        << "\tusing ActionTable = std::array<std::array<std::optional<::" << namespace_name << "::Action>, "<< tokens.size() << ">, " << max_states + 1 << ">;\n"
        << "\tusing GotoTable = std::array<std::array<std::optional<size_t>, " << rules.size() << ">, " << max_states + 1 << ">;\n"
        << "\tusing RulesTable = std::array<std::pair<Rules, size_t>, " << rules_table.size() << ">;\n"
    ;
    if (DFA_size != -1) {
        out << "\tusing DFATable = std::array<std::pair<::" << namespace_name << "::Action, std::array<std::pair<::" << namespace_name << "::Tokens, size_t>, " << max_dfa_token_map_size + 2 << ">>, " << DFA_size << ">;\n";
    }
}
void LRHeader::create_parser_header(std::ostringstream &out, bool hasDFA) const {
    if (hasDFA) {
        out << "\tclass Parser : public ISPA_STD::ELRParser_base<Tokens, Rules, Action, ActionTable, GotoTable, RulesTable, DFATable> {\n";
    } else {
        out << "\tclass Parser : public ISPA_STD::LRParser_base<Tokens, Rules, Action, ActionTable, GotoTable, RulesTable> {\n";
    }
    out
        << "\t\tprivate:\n"
        << "\t\t\tstatic ActionTable action_table;\n"
        << "\t\t\tstatic GotoTable goto_table;\n"
        << "\t\t\tstatic RulesTable rules_table;\n";
    if (hasDFA)
        out << "\t\t\tstatic DFATable dfa_table;\n";
    out
        << "\t\t\tstd::string TokensToString(Tokens token);\n"
        << "\t\t\tstd::string RulesToString(Rules rule);\n";
}
void LRHeader::addStandardFunctionsParser(std::ostringstream &out) const {
    out 
        << "\t\tvoid parseFromTokens();\n"
        << "\t\tvoid lazyParse();\n";
}
