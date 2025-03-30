
#include <list>
#include <IR.h>
#include <string>
#include <list>
#include <any>
#include <logging.h>
#include <converter.h>
#include <unordered_map>
namespace global
{
    extern std::string namespace_name;
}

std::string createLibrary() {
    std::string res;
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
    res += "#pragma once\n";
    res += "#ifndef " + corelib::text::ToUpper(global::namespace_name) + "\n";
    res += "#define " + corelib::text::ToUpper(global::namespace_name) + "\n";
    res += "\n";
    res += "#include <string>\n";
    res += "#include <list>\n";
    res += "#include <unordered_map>\n";
    res += "#include <iscstdlibc++.h>\n";
    res += "#include <fstream>\n";
    res += "#include <iterator>\n";
    for (auto [macro, deftype] : macros) {
        auto actual_name = corelib::text::ToUpper(global::namespace_name) + "_" + macro;
        
        res += "#ifndef " + actual_name + "\n";
        res += "#define " + actual_name + " " + deftype + "\n";
        res += "#endif\n";
    }
    return res;
}
std::string close_library() {
    std::string res;
    res += "\n} // " + global::namespace_name + "\n"; // close enum
    res += "\n\n#endif // " + corelib::text::ToUpper(global::namespace_name) + "\n"; // close header
    return res;
}
std::string createNamespace(use_prop_t use) {
    std::string res = "namespace ";
    res += std::any_cast<std::string>(use["name"].data);
    res += " {\n";
    return res;
}
std::string createTypes() {
    std::string res;
    res += "\tusing str_t = " + corelib::text::ToUpper(global::namespace_name) + "_STR_TYPE;\n";
    res += "\tusing num_t = " + corelib::text::ToUpper(global::namespace_name) + "_NUM_TYPE;\n";
    res += "\tusing bool_t = " + corelib::text::ToUpper(global::namespace_name) + "_BOOL_TYPE;\n";
    res += "\tusing any_t = " + corelib::text::ToUpper(global::namespace_name) + "_ANY_TYPE;\n";
    res += "\ttemplate<typename T>\n";
    res += "\tusing arr_t = " + corelib::text::ToUpper(global::namespace_name) + "_ARR_TYPE<T>;\n";
    res += "\ttemplate<typename Key, typename Value>\n";
    res += "\tusing obj_t = " + corelib::text::ToUpper(global::namespace_name) + "_OBJ_TYPE<Key, Value>;\n";
    return res;
}
void writeEnum(std::string &res, std::list<std::string> enm) {
    res += "\t\tNONE, ";
    for (auto el : enm) {
        res += el;
        res += ", ";
    }
    if (res.size())
        res.erase(res.size() - 2);

    res += "\n\t};\n";
}
std::string createTokensEnum(std::list<std::string> tokens) {
    std::string res = "\tenum class Tokens {\n";
    writeEnum(res, tokens);
    return res;
}
std::string createRulesEnum(std::list<std::string> rules) {
    std::string res = "\tenum class Rules {\n";
    writeEnum(res, rules);
    return res;
}
std::string getTypesFromStdlib() {
    std::string res;
    // res += "\ttypedef ISC_STD::_return<Rules> Rule;\n";
    // res += "\ttypedef ISC_STD::match_result<Rules> Rule_res;\n";
    // res += "\ttypedef ISC_STD::_return<Tokens> Token;\n";
    // res += "\ttypedef ISC_STD::match_result<Tokens> Token_res;\n";
    // res += "\ttypedef ISC_STD::Tree<Rules> Tree;\n";
    res += "\tusing Rule = ISPA_STD::node<Rules>;\n";
    res += "\tusing Rule_res = ISPA_STD::match_result<Rules>;\n";
    res += "\tusing Token = ISPA_STD::node<Tokens>;\n";
    res += "\tusing Token_res = ISPA_STD::match_result<Tokens>;\n";
    res += "\tusing TokenFlow = arr_t<Token>;\n";
    res += "\tusing Tree = arr_t<Rules>;\n";
    return res;
}
std::string createToStringFunction() {
    std::string res;
    res += "\tstd::string TokensToString(Tokens token);\n";
    return res;
}
std::string addStandardFunctions() {
    std::string res;
    res += R"(
            /**
             * @param os the output stream
             * @param sensitiveInfo - whether print such info as line number and position in line. These methods require the start pointer to be valid
             * Print the tokens into an output stream
             */
            void printTokens(std::ostream& os, bool sentitiveInfo = false);
            /**
             * @param os the output stream
             * @param token the token to print
             * @param sensitiveInfo - whether print such info as line number and position in line. These methods require the start pointer to be valid
             * Prints a single token into an output stream
             */
            void printToken(std::ostream& os, const Token& token, bool sensitiveInfo = false);)";
    res += "\n";
    return res;
}
std::string convert_inclosed_map(IR::inclosed_map map) {
    std::string res;
    for (auto [key, value] : map) {
        auto [expr, type] = value;
        res += "\t\t\t\t" + convert_var_type(type.type, type.templ) + " " + key + ";\n";
    }
    return res;
}
std::string convert_single_assignment_data(IR::var_type type, std::string name) {
    return "\t\t\tusing " + name + "_data = " + convert_var_type(type.type, type.templ) + ";\n";
}
std::string write_data_block(std::list<std::pair<IR::data_block, std::string>> &dtb) {
    std::string res;
    for (auto [block, name] : dtb) {
        if (block.is_inclosed_map) {
            res += "\t\t\tstruct " + name + "_data {\n";
            res += convert_inclosed_map(std::any_cast<IR::inclosed_map>(block.value.data));
            res += "\t\t\t};\n";
        } else {
            res += convert_single_assignment_data(block.assign_type, name);
        }
    }
    return res;
}
std::string create_tokenizator_header(std::list<std::string> tokens, std::list<std::pair<IR::data_block, std::string>> dtb) {
    std::string res = "\tclass Lexer : public ISPA_STD::Lexer_base<Tokens> {\n";
    res += "\t\tpublic:\n";
    res += "\t\t\tToken makeToken(const char*& pos);\n";
    res += addStandardFunctions();
    res += "\t\tprivate:\n";
    res += write_data_block(dtb);
    for (auto name : tokens) {
        res += "\t\t\tToken_res " + name + "(const char*);\n";
    }
    res += "\t};\n";
    return res;
}
std::string create_parser_header(std::list<std::string> tokens, std::list<std::pair<IR::data_block, std::string>> dtb) {
    std::string res = "\tclass Parser : public ISPA_STD::Parser_base<Tokens, Rules> {\n";
    res += "\t\tpublic:\n";
    res += "\t\t\tRule_res getRule();\n";
    res += "\t\tprivate:\n";
    res += write_data_block(dtb);
    for (auto name : tokens) {
        res += "\t\t\tRule_res " + name + "(::" + global::namespace_name + "::TokenFlow::iterator pos);\n";
    }
    res += "\t};\n";
    return res;
}

extern "C" std::string convert_header(std::list<std::string> tokens, std::list<std::string> rules, std::list<std::pair<IR::data_block, std::string>> datablocks_tokens, std::list<std::pair<IR::data_block, std::string>> datablocks_rules, use_prop_t use) {
    std::string res;
    res += createLibrary();
    res += createNamespace(use);
    res += createTypes();
    res += createTokensEnum(tokens);
    res += createRulesEnum(rules);
    res += getTypesFromStdlib();
    res += createToStringFunction();
    res += create_tokenizator_header(tokens, datablocks_tokens);
    res += create_parser_header(rules, datablocks_rules);
    res += close_library();
    return res;
}