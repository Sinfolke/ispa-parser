
#include <list>
#include <IR/IR.h>
#include <string>
#include <list>
#include <any>
#include <logging.h>
#include <LLConverter.h>
#include <LLHeader.h>
#include <unordered_map>
void LLHeader::createIncludes(std::ostringstream &out) const {
    out << "#include <string>\n";
    out << "#include <list>\n";
    out << "#include <unordered_map>\n";
    out << "#include <iscstdlibc++.h>\n";
    out << "#include <fstream>\n";
    out << "#include <iterator>\n\n";
    out << "#include <iostream>\n";
}
void LLHeader::createLibrary(std::ostringstream& out, std::string namespace_name) const {


    out << "#pragma once\n";
    out << "#ifndef " << corelib::text::ToUpper(namespace_name) << "\n";
    out << "#define " << corelib::text::ToUpper(namespace_name) << "\n\n";

}
void LLHeader::createDefaultTypes(std::ostringstream &out) const {
    std::unordered_map<std::string, std::string> macros = {
        {"BOOL_TYPE", "bool"},
        {"NUM_TYPE", "double"},
        {"STR_TYPE", "std::string"},
        {"ANY_TYPE", "std::any"},
        {"ARR_TYPE", "std::list"},
        {"OBJ_TYPE", "std::unordered_map"}
    };


    for (auto [macro, deftype] : macros) {
        auto actual_name = corelib::text::ToUpper(namespace_name) + "_" + macro;
        
        out << "#ifndef " << actual_name << "\n";
        out << "#define " << actual_name << " " << deftype << "\n";
        out << "#endif\n";
    }
}
void LLHeader::close_library(std::ostringstream &out, std::string namespace_name) const {
    out << "\n} // " << namespace_name << "\n"; // close enum
    out << "\n\n#endif // " << corelib::text::ToUpper(namespace_name) << "\n"; // close header
}
void LLHeader::createNamespace(std::ostringstream &out, std::string namespace_name) const {
    out << "namespace " << namespace_name << " {\n";
}
void LLHeader::createTypes(std::ostringstream &out, std::string namespace_name) const {
    const auto ns = corelib::text::ToUpper(namespace_name);

    out << "\tusing str_t = " << ns << "_STR_TYPE;\n";
    out << "\tusing num_t = " << ns << "_NUM_TYPE;\n";
    out << "\tusing bool_t = " << ns << "_BOOL_TYPE;\n";
    out << "\tusing any_t = " << ns << "_ANY_TYPE;\n";
    out << "\ttemplate<typename T>\n";
    out << "\tusing arr_t = " << ns << "_ARR_TYPE<T>;\n";
    out << "\ttemplate<typename Key, typename Value>\n";
    out << "\tusing obj_t = " << ns << "_OBJ_TYPE<Key, Value>;\n";
}

void LLHeader::writeEnum(std::ostringstream& out, const std::vector<std::vector<std::string>>& enm) const {
    out << "\t\t";
    for (auto it = enm.begin(); it != enm.end() - 1; it++) {
        out << corelib::text::join(*it, "_") << ", ";
    }
    out << corelib::text::join(*(enm.end() - 1), "_");
}

void LLHeader::createTokensEnum(std::ostringstream &out, const std::vector<std::vector<std::string>>& tokens) const {
    out << "\tenum class Tokens {\n";
    writeEnum(out, tokens);
    out << "\n\t};\n";
}

void LLHeader::createRulesEnum(std::ostringstream &out, const std::vector<std::vector<std::string>>& rules) const {
    out << "\tenum class Rules {\n";
    writeEnum(out, rules);
    out << "\n\t};\n";
}
void LLHeader::getTypesFromStdlib(std::ostringstream& out) const {
    out << "\tusing Rule = ISPA_STD::Node<Rules>;\n";
    out << "\tusing Rule_res = ISPA_STD::match_result<Rules>;\n";
    out << "\tusing Token = ISPA_STD::Node<Tokens>;\n";
    out << "\tusing Token_res = ISPA_STD::match_result<Tokens>;\n";
    out << "\tusing TokenFlow = ISPA_STD::TokenFlow<Tokens>;\n";
    out << "\tusing Tree = ISPA_STD::Tree<Rules>;\n";
}

void LLHeader::createToStringFunction(std::ostringstream &out) const {
    out << "\tstd::string TokensToString(Tokens token);\n";
    out << "\tstd::string RulesToString(Rules rule);\n";
}
void LLHeader::addStandardFunctions(std::ostringstream &out) const {
    out << R"(
            /**
             * @param os the output stream
             * Print the tokens into an output stream
             */
            void printTokens(std::ostream& os);
            /**
             * @param os the output stream
             * @param token the token to print
             * Prints a single token into an output stream
             */
            void printToken(std::ostream& os, const Token& token);)";
    out << "\n";
}
void LLHeader::convert_inclosed_map(std::ostringstream &out, LLIR::inclosed_map map) const {
    for (auto [key, value] : map) {
        auto [expr, type] = value;
        out << "\t\t\t" << convert_var_type(type.type, type.templ) << " " << key << ";\n";
    }
}
void LLHeader::convert_single_assignment_data(std::ostringstream &out, LLIR::var_type type, std::string name) const {
    out << "\t\tusing " << name << "_data = " << convert_var_type(type.type, type.templ) << ";\n";
}
void LLHeader::write_data_block(std::ostringstream &out, data_block_t dtb) const {
    for (auto [name, block] : dtb) {
        if (block.is_inclosed_map) {
            out << "\t\tstruct " + name + "_data {\n";
            convert_inclosed_map(out, std::any_cast<LLIR::inclosed_map>(block.value.data));
            out << "\t\t};\n";
        } else {
            convert_single_assignment_data(out, block.assign_type, name);
        }
    }
}
void LLHeader::createTypesNamespace(std::ostringstream &out, const data_block_t &data_block_tokens, const data_block_t &data_block_rules) const {
    out << "\tnamespace Types {\n"; 
    write_data_block(out, data_block_tokens); 
    write_data_block(out, data_block_rules); 
    out << "\t}\n";
}
void LLHeader::create_lexer_header(std::ostringstream &out, const std::vector<std::vector<std::string>> &tokens) const {
    out << "\tclass Lexer : public ISPA_STD::Lexer_base<Tokens> {\n"
        << "\t\tpublic:\n"
        << "\t\t\tToken makeToken(const char*& pos);\n";
    addStandardFunctions(out);
    addConstructorsLexer(out);
    out << "\t\tprivate:\n";
    for (auto name : tokens) {
        out << "\t\t\tToken_res " << corelib::text::join(name, "_") << "(const char*);\n";
    }
    out << "\t};\n";
}
void LLHeader::addConstructorsLexer(std::ostringstream &out) const {
    out << "\t\t"<< R"(Lexer(const std::string& in) : Lexer_base(in) {}
        Lexer(char*& in) : Lexer_base(in) {}
        Lexer(const char*& in) : Lexer_base(in) {}
        Lexer(TokenFlow &tokens) : Lexer_base(tokens) {}
        Lexer() {})";
    out << "\n";
}
void LLHeader::close_parser_header(std::ostringstream &out) const {
    out << "\t};\n";
}
void LLHeader::create_parser_header(std::ostringstream &out) const {
    out << "\tclass Parser : public ISPA_STD::LLParser_base<Tokens, Rules> {\n"
        << "\t\tRule_res getRule(Lexer::lazy_iterator&);\n"
        << "\t\tRule_res getRule(Lexer::iterator&);\n"
        << "\t\tvoid parseFromTokens();\n"
        << "\t\tvoid lazyParse();\n";
}
void LLHeader::create_get_namespace(std::ostringstream &out, std::string namespace_name, const data_block_t &data_block_tokens, const data_block_t &data_block_rules) const {
    out << "\n\tnamespace get {\n";
    for (auto [name, block] : data_block_tokens) {
        out << "\t\t::" << namespace_name << "::" << "Types::" << name << "_data " << name << "(::" << namespace_name << "::Token &token);\n";
    }
    for (auto [name, block] : data_block_rules) {
        out << "\t\t::" << namespace_name << "::" << "Types::" << name << "_data " << name << "(::" << namespace_name << "::Rule &rule);\n";
    }
    out << "\t}\n";
}
