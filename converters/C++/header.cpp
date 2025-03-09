
#include <list>
#include <IR.h>
#include <string>
#include <list>
#include <any>
#include <logging.h>
#include <converter.h>
#include <unordered_map>
std::string createLibrary() {
    std::string res;
    std::unordered_map<std::string, std::string> macros = {
        {"ISPA_BOOLEAN_TYPE", "bool"},
        {"ISPA_NUM_TYPE", "double"},
        {"ISPA_STR_TYPE", "std::string"},
        {"ISPA_ANY_TYPE", "std::any"},
        {"ISPA_ARRAY_TYPE", "std::list"},
        {"ISPA_OBJECT_TYPE", "std::unordered_map"}
    };
    res += "#pragma once\n";
    res += "#include <string>\n";
    res += "#include <list>\n";
    res += "#include <unordered_map>\n";
    res += "#include <iscstdlibc++.h>\n";
    for (auto [macro, deftype] : macros) {
        res += "#ifndef " + macro + "\n";
        res += "#define " + macro + " " + deftype + "\n";
        res += "#endif\n";
    }
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
    res += "\tusing str_t = ISPA_STR_TYPE;\n";
    res += "\tusing num_t = ISPA_NUM_TYPE;\n";
    res += "\tusing bool_t = ISPA_BOOLEAN_TYPE;\n";
    res += "\tusing any_t = ISPA_ANY_TYPE;\n";
    res += "\ttemplate<typename T>\n";
    res += "\tusing arr_t = ISPA_ARRAY_TYPE<T>;\n";
    res += "\ttemplate<typename Key, typename Value>\n";
    res += "\tusing obj_t = ISPA_OBJECT_TYPE<Key, Value>;\n";
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
    res += "\tusing Rule = ISC_STD::_return<Rules>;\n";
    res += "\tusing Rule_res = ISC_STD::match_result<Rules>;\n";
    res += "\tusing Token = ISC_STD::_return<Tokens>;\n";
    res += "\tusing Token_res = ISC_STD::match_result<Tokens>;\n";
    res += "\tusing Tree = ISC_STD::Tree<Rules>;\n";
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
    std::string res = "\tclass Tokenizator {\n\t\tprivate:\t\t\tconst char* str\n\t\tpublic:\n";
    res += write_data_block(dtb);
    for (auto name : tokens) {
        res += "\t\t\tToken_res " + name + "(const char*&);\n";
    }
    res += "\t};\n";
    return res;
}
std::string create_parser_header(std::list<std::string> tokens, std::list<std::pair<IR::data_block, std::string>> dtb) {
    std::string res = "\tclass Parser {\n\t\tpublic:\n";
    res += write_data_block(dtb);
    for (auto name : tokens) {
        res += "\t\t\tRule_res " + name + "(Token*&);\n";
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
    res += create_tokenizator_header(tokens, datablocks_tokens);
    res += create_parser_header(rules, datablocks_rules);
    res += "\n}"; // close enum
    return res;
}