
#include <list>
#include <IR/IR.h>
#include <string>
#include <list>
#include <any>
#include <logging.h>
#include <converter.h>
#include <unordered_map>

void Converter::createLibrary(std::ostringstream& out) {
    std::unordered_map<std::string, std::string> macros = {
        {"BOOL_TYPE", "bool"},
        {"NUM_TYPE", "double"},
        {"STR_TYPE", "std::string"},
        {"ANY_TYPE", "std::any"},
        {"ARR_TYPE", "std::list"},
        {"OBJ_TYPE", "std::unordered_map"}
    };
    
    std::unordered_map<std::string, std::string> push_methods {
        { "std::stack", "push" },
        { "std::queue", "push" },
        { "std::priority_queue", "push" },
    };

    out << "#pragma once\n";
    out << "#ifndef " << corelib::text::ToUpper(namespace_name) << "\n";
    out << "#define " << corelib::text::ToUpper(namespace_name) << "\n\n";

    out << "#include <string>\n";
    out << "#include <list>\n";
    out << "#include <unordered_map>\n";
    out << "#include <iscstdlibc++.h>\n";
    out << "#include <fstream>\n";
    out << "#include <iterator>\n\n";

    for (auto [macro, deftype] : macros) {
        auto actual_name = corelib::text::ToUpper(namespace_name) + "_" + macro;
        
        out << "#ifndef " << actual_name << "\n";
        out << "#define " << actual_name << " " << deftype << "\n";
        out << "#endif\n";
    }
}

void Converter::close_library(std::ostringstream &out) {
    out << "\n} // " << namespace_name << "\n"; // close enum
    out << "\n\n#endif // " << corelib::text::ToUpper(namespace_name) << "\n"; // close header
}
void Converter::createNamespace(std::ostringstream &out) {
    out << "namespace " << namespace_name << " {\n";
}
void Converter::createTypes(std::ostringstream &out) {
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

void Converter::writeEnum(std::ostringstream& out, const std::vector<std::string>& enm) {
    out << "\t\tNONE";

    for (const auto& el : enm) {
        out << ", " << el;
    }
}

void Converter::createTokensEnum(std::ostringstream &out) {
    out << "\tenum class Tokens {\n";
    writeEnum(out, tokens);
    out << "\n\t};\n";
}

void Converter::createRulesEnum(std::ostringstream &out) {
    out << "\tenum class Rules {\n";
    writeEnum(out, rules);
    out << "\n\t};\n";
}
void Converter::getTypesFromStdlib(std::ostringstream& out) {
    out << "\tusing Rule = ISPA_STD::node<Rules>;\n";
    out << "\tusing Rule_res = ISPA_STD::match_result<Rules>;\n";
    out << "\tusing Token = ISPA_STD::node<Tokens>;\n";
    out << "\tusing Token_res = ISPA_STD::match_result<Tokens>;\n";
    out << "\tusing TokenFlow = ISPA_STD::TokenFlow<Tokens>;\n";
    out << "\tusing Tree = ISPA_STD::Tree<Rules>;\n";
}

void Converter::createToStringFunction(std::ostringstream &out) {
    out << "\tstd::string TokensToString(Tokens token);\n";
    out << "\tstd::string RulesToString(Rules rule);\n";
}
void Converter::addStandardFunctions(std::ostringstream &out) {
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
void Converter::convert_inclosed_map(std::ostringstream &out, IR::inclosed_map map) {
    for (auto [key, value] : map) {
        auto [expr, type] = value;
        out << "\t\t\t" << convert_var_type(type.type, type.templ) << " " << key << ";\n";
    }
}
void Converter::convert_single_assignment_data(std::ostringstream &out, IR::var_type type, std::string name) {
    out << "\t\tusing " << name << "_data = " << convert_var_type(type.type, type.templ) << ";\n";
}
void Converter::write_data_block(std::ostringstream &out, data_block_t dtb) {
    for (auto [name, block] : dtb) {
        if (block.is_inclosed_map) {
            out << "\t\tstruct " + name + "_data {\n";
            convert_inclosed_map(out, std::any_cast<IR::inclosed_map>(block.value.data));
            out << "\t\t};\n";
        } else {
            convert_single_assignment_data(out, block.assign_type, name);
        }
    }
}
void Converter::createTypesNamespace(std::ostringstream &out) {
    out << "\tnamespace Types {\n"; 
    write_data_block(out, data_block_tokens); 
    write_data_block(out, data_block_rules); 
    out << "\t}\n";
}
void Converter::create_lexer_header(std::ostringstream &out) {
    out << "\tclass Lexer : public ISPA_STD::Lexer_base<Tokens> {\n"
        << "\t\tpublic:\n"
        << "\t\t\tToken makeToken(const char*& pos);\n";
    addStandardFunctions(out);
    out << "\t\tprivate:\n";
    for (auto name : tokens) {
        out << "\t\t\tToken_res " << name << "(const char*);\n";
    }
    out << "\t};\n";
}
void Converter::create_parser_header(std::ostringstream &out) {
    out << "\tclass Parser : public ISPA_STD::Parser_base<Tokens, Rules> {\n"
        << "\t\tprivate:\n"
        << "\t\t\tRule_res getRule();\n";
    for (auto name : rules) {
        out << "\t\t\tRule_res " << name << "(::" << namespace_name << "::TokenFlow::iterator pos);\n";
    }
    out << "\t};\n";
}
void Converter::create_get_namespace(std::ostringstream &out) {
    out << "\n\tnamespace get {\n";
    for (auto [name, block] : data_block_tokens) {
        out << "\t\t::" << namespace_name << "::" << "Types::" << name << "_data " << name << "(::" << namespace_name << "::Token &token);\n";
    }
    for (auto [name, block] : data_block_rules) {
        out << "\t\t::" << namespace_name << "::" << "Types::" << name << "_data " << name << "(::" << namespace_name << "::Rule &rule);\n";
    }
    out << "\t}\n";
}
void Converter::outputHeader(std::ostringstream &out) {
    std::string res;
    createLibrary(out);
    createNamespace(out);
    createTypes(out);
    createTokensEnum(out);
    createRulesEnum(out);
    getTypesFromStdlib(out);
    createToStringFunction(out);
    createTypesNamespace(out);
    create_get_namespace(out);
    create_lexer_header(out);
    create_parser_header(out);
    close_library(out);
}