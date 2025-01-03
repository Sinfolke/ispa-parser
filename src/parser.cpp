#include <parser.h>
#include <parser_defs.h>
Rule(id) {
    const char* pos = in;
    std::string val;
    ISC_STD::skip_spaces(pos);
    while (isdigit(*pos)) {
        val += *pos++;
    }
    if (!isalpha(*pos) && *pos != '_') {
        return {};
    }
    do {
        val += *pos++;
    } while (isalnum(*pos) || *pos == '_');
    // construct result as valid
    // extract full string from the first group
    RULE_SUCCESSD(in, pos, id, val);
}
Rule(spacemode)
{
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    std::string val;
    if (strncmp(pos, "spacemode", sizeof("spacemode") - 1))
        return {};
    pos += sizeof("spacemode") - 1;
    ISC_STD::skip_spaces(pos);
    if (!strncmp(pos, "mixed", sizeof("mixed") - 1)) {
        val = "mixed";
        pos += sizeof("mixed") - 1;
    } else if (!strncmp(pos, "skipped", sizeof("skipped") - 1)) {
        val = "skipped";
        pos += sizeof("skipped") - 1;
    } else if (!strncmp(pos, "allowed", sizeof("allowed") - 1)) {
        val = "allowed";
        pos += sizeof("allowed") - 1;
    } else {
        return {};
    }
    RULE_SUCCESSD(in, pos, spacemode, val);
}
Rule(linear_comment) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "//", 2))
        return {};
    while(*pos != '\n') pos++;
    RULE_SUCCESS(in, pos, linear_comment);
}
Rule(Import_path) {    
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    std::string v;
    while (
        ! 
        (
            *pos == '"' ||
            *pos == '<' ||
            *pos == '>' ||
            *pos == '|' ||
            *pos == ':' ||
            *pos == '?' ||
            *pos == '.'
        )
    ) v += *pos++;
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Import_path, v);
};
Rule(Import_ext) {    
    auto pos = in;
    std::vector<::Parser::Rule> data;
    ISC_STD::skip_spaces(pos);
    while(true) {
        if (*pos == '.') {
            ++pos;
            ISC_STD::skip_spaces(pos);
            auto match_res = id(pos);
            if (match_res.result) {
                data.push_back(match_res.token);
                pos += match_res.token.length();
                continue;
            }
            --pos; // dot is skipped
        }
        break;
    }
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Import_ext, data);
};
Rule(Import_file) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto path_res = Import_path(pos);
    if (!path_res.result) return {};
    pos += path_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto ext_res = Import_ext(pos);
    if (!ext_res.result) return {};
    pos += ext_res.token.length();
    // join
    std::string joined;
    for (auto obj : TO(std::vector<::Parser::Rule>, ext_res.token.data)) {
        joined += TO(std::string, obj.data);
    }
    std::unordered_map<const char*, std::any> data = {
        { "path", path_res },
        { "ext", TO(std::vector<Rule_result>, ext_res.token.data).back() },
        { "fullext", ext_res },
        { "fullpath", std::string( TO(std::string, path_res.token.data )) + joined }
    };
    RULE_SUCCESSD(in, pos, Import_file, data);
}
Rule(Import_general_dir) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '[')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto path_res = Import_path(pos);
    if (!path_res.result) return {};
    pos += path_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ']')
        return {};
    
    auto _local_start = ++pos;
    std::vector<::Parser::Rule> files;
    while(true) {
        int v = ISC_STD::skip_spaces(pos);
        auto file_res = Import_file(pos);
        if (!file_res.result)
            pos -= v; //! to not include spaces into result token length
            break;
        pos += file_res.token.length();
        files.push_back(file_res.token);
    }
    if (pos == _local_start)
        return {}; // zero match
    std::unordered_map<const char*, std::any> data {
        { "path", path_res.token },
        { "files", files }
    };
    RULE_SUCCESSD(in, pos, Import_general_dir, files);
}
Rule(Import_rulespecific) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto file_res = Import_file(pos);
    if (!file_res.result)
        return {};
    pos += file_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != '{')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto _local_start = pos;
    std::vector<::Parser::Rule> rules;
    std::vector<::Parser::Rule> rules_current_name;
    while (true) {
        ISC_STD::skip_spaces(pos);
        auto id_res = id(pos);
        if (!id_res.result)
            break;
        rules.push_back(id_res.token);
        pos += id_res.token.length();
        ISC_STD::skip_spaces(pos);
        if (*pos == '=') {
            ++pos;
            ISC_STD::skip_spaces(pos);
            auto id2_res = id(pos);
            if (!id2_res.result)
                break;
            rules_current_name.push_back(id2_res.token);
        }
    }
    if (_local_start == pos)
        return {}; // zero match
    std::unordered_map<const char*, std::any> data {
        { "path", file_res.token },
        { "tokens", rules },
        { "tokens_current_name", rules_current_name }
    };
    RULE_SUCCESSD(in, pos, Import_rulespecific, data);
}
Rule(Import) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "import", sizeof("import") - 1))
        return {};
    pos += sizeof("import") - 1;
    ISC_STD::skip_spaces(pos);
    auto first_rule_res = Import_file(pos);
    if (!first_rule_res.result) {
        first_rule_res = Import_general_dir(pos);
        if (!first_rule_res.result) {
            first_rule_res = Import_rulespecific(pos);
            if (!first_rule_res.result)
                return {};
        }
    }
    pos += first_rule_res.token.length();
    ISC_STD::skip_spaces(pos);
    std::vector<::Parser::Rule> additional_paths;
    while (*pos == ',') {
        ++pos;
        ISC_STD::skip_spaces(pos);
        auto result = Import_file(pos);
        if (!result.result) {
            result = Import_general_dir(pos);
            if (!result.result) {
                result = Import_rulespecific(pos);
                if (!result.result)
                    break;
            }
        }
        pos += result.token.length();
        additional_paths.push_back(result.token);
    }
    using obj_type = std::unordered_map<const char*, std::any>;
    std::vector<::Parser::Rule> data = {
        first_rule_res.token
    };
    // push remaining arguments inlining the array
    data.insert(data.end(), additional_paths.begin(), additional_paths.end());
    for (const auto obj : additional_paths) {
        data.push_back( obj );
    }
    RULE_SUCCESSD(in, pos, Import, data);
}
Rule(use) {
    auto pos = in;  // Start parsing from 'in'
    std::vector<::Parser::Rule> data;  // Use std::vector to store parsed data
    
    // Skip leading spaces
    ISC_STD::skip_spaces(pos);
    
    // Check if the input starts with "use"
    if (strncmp(pos, "use", 3) != 0) {
        return {};  // Return empty result if "use" is not found
    }
    pos += 3;  // Move position past "use"
    ISC_STD::skip_spaces(pos);  // Skip spaces after "use"
    
    // Parse the first unit
    auto use_unit_res = use_unit(pos);
    if (!use_unit_res.result) {
        return {};
    }
    pos += use_unit_res.token.length();
    data.push_back(use_unit_res.token);
    
    ISC_STD::skip_spaces(pos);
    
    while (*pos == ',') {
        pos++; 
        ISC_STD::skip_spaces(pos);
        
        auto use_unit_res = use_unit(pos);
        if (!use_unit_res.result) {
            break;
        }
        pos += use_unit_res.token.length();
        data.push_back(use_unit_res.token);
        ISC_STD::skip_spaces(pos);
    }
    // Finalize the rule and return the result
    RULE_SUCCESSD(in, pos, use, data);
}
Rule(use_unit) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    ::Parser::Rule dt;
    if (*pos == ':') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto res = any_data(pos);
        if (!res.result)
            return {};
        pos += res.token.length();
        dt = res.token;
    }
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "value", dt }
    };
    RULE_SUCCESSD(in, pos, use_unit, data);
}
#undef Rule
#undef Token
size_t Parser::Parser::getCurrentPos(const char* pos) {
    return pos - text;
}

// Define the function to convert Rules enum to string
std::string Parser::RulesToString(::Parser::Rules rule) {
    switch (rule) {
        case Rules::NONE: return "NONE";
        case Rules::Import_path: return "Import_path";
        case Rules::Import_ext: return "Import_ext";
        case Rules::Import_file: return "Import_file";
        case Rules::Import_general_dir: return "Import_general_dir";
        case Rules::Import_rulespecific: return "Import_rulespecific";

        case Rules::use_unit: return "use_unit";

        case Rules::Rule_rule: return "Rule_rule";
        case Rules::Rule_other: return "Rule_other";
        case Rules::Rule_op: return "Rule_op";
        case Rules::Rule_qualifier: return "Rule_qualifier";
        case Rules::Rule_group: return "Rule_group";
        case Rules::Rule_csequence: return "Rule_csequence";
        case Rules::Rule_csequence_symbol: return "Rule_csequence_symbol";
        case Rules::Rule_csequence_escape: return "Rule_csequence_escape";
        case Rules::Rule_csequence_diapason: return "Rule_csequence_diapason";
        case Rules::Rule_data_block: return "Rule_data_block";
        case Rules::Rule_data_block_key: return "Rule_data_block_key";
        case Rules::Rule_data_block_inclosed_map: return "Rule_data_block_inclosed_map";
        case Rules::Rule_escaped: return "Rule_escaped";
        case Rules::Rule_any: return "Rule_any";
        case Rules::Rule_nested_rule: return "Rule_nested_rule";
        case Rules::Rule_hex: return "Rule_hex";
        case Rules::Rule_bin: return "Rule_bin";

        case Rules::cll_type_abstract: return "cll_type_abstract";

        case Rules::end: return "end";
        case Rules::strict_end: return "strict_end";
        case Rules::newline: return "newline";
        case Rules::spacemode: return "spacemode";
        case Rules::linear_comment: return "linear_comment";
        case Rules::id: return "id";
        case Rules::Import: return "Import";
        case Rules::use: return "use";
        case Rules::Rule: return "Rule";

        case Rules::accessors_group: return "accessors_group";
        case Rules::accessors_element: return "accessors_element";
        case Rules::accessors_char: return "accessors_char";
        case Rules::accessor_all: return "accessor_all";
        case Rules::accessor: return "accessor";

        case Rules::string: return "string";
        case Rules::number: return "number";
        case Rules::boolean: return "boolean";
        case Rules::array: return "array";
        case Rules::object: return "object";
        case Rules::any_data: return "any_data";

        case Rules::cll_block: return "cll_block";
        case Rules::cll_spaced_block: return "cll_spaced_block";
        case Rules::op: return "op";
        case Rules::assignment_op: return "assignment_op";
        case Rules::compare_op: return "compare_op";
        case Rules::logical_op: return "logical_op";
        case Rules::logical_and: return "logical_and";
        case Rules::logical_or: return "logical_or";
        case Rules::logical_andr: return "logical_andr";
        case Rules::op_not: return "op_not";

        case Rules::cll_template_typename: return "cll_template_typename";
        case Rules::cll_template_int: return "cll_template_int";
        case Rules::cll_template_bool: return "cll_template_bool";
        case Rules::cll_template_str: return "cll_template_str";
        case Rules::cll_template_arr: return "cll_template_arr";
        case Rules::cll_template_obj: return "cll_template_obj";
        case Rules::cll_template_any_data: return "cll_template_any_data";
        case Rules::cll_template_all: return "cll_template_all";
        case Rules::cll_template: return "cll_template";

        case Rules::cll_csupport_types: return "cll_csupport_types";
        case Rules::cll_type: return "cll_type";

        case Rules::cll_if: return "cll_if";

        case Rules::cll_ternary: return "cll_ternary";

        case Rules::expr: return "expr";

        case Rules::expr_logical: return "expr_logical";
        case Rules::expr_compare: return "expr_compare";
        case Rules::expr_arithmetic: return "expr_arithmetic";
        case Rules::expr_group: return "expr_group";
        case Rules::expr_copiable_method_call: return "expr_copiable_method_call";
        case Rules::expr_for_arithmetic: return "expr_for_arithmetic";
        case Rules::function_body_call: return "function_body_call";
        case Rules::function_body_decl: return "function_body_decl";
        case Rules::function_arguments: return "function_arguments";
        case Rules::function_parameters: return "function_parameters";
        case Rules::cll_function_call: return "cll_function_call";
        case Rules::function_decl: return "function_decl";
        case Rules::function_value: return "function_value";

        case Rules::method_call: return "method_call";
        case Rules::copiable_method_call: return "copiable_method_call";
        case Rules::loop_while: return "loop_while";
        case Rules::loop_for: return "loop_for";
        case Rules::cll_var: return "cll_var";
        case Rules::cll_var_assign: return "cll_var_assign";
        case Rules::var_refer: return "var_refer";

        case Rules::cll: return "cll";

        default: return "Unknown Rule";
    }
}
void printTabs(int tabs) {
    if (tabs > 0) {
        for (int i = 0; i < tabs; ++i)
            printf("\t");
    }
}
void printData(const char* data, int tabs);
void printData(const std::string data, int tabs);
void printData(const ::Parser::Rule data, int tabs);
void printData(const std::unordered_map<const char*, std::any> data, int tabs);
void printData(const std::unordered_map<std::string, std::any> data, int tabs);


void printData(const char* data, int tabs = 0) {
    printTabs(tabs);
    printf("%s\n", data);
}
void printData(const std::string data, int tabs = 0) {
    printTabs(tabs);
    printf("%s\n", data.c_str());
}

void printData(const ::Parser::Rule data, int tabs = 0) {
    printTabs(tabs);
    printf("{\nname: %s\nvalue: ", RulesToString(data.name).c_str());
    auto dt = data.data;
    if (dt.type() == typeid(::Parser::Rule)) {
        printf("\n\n");
        printData(std::any_cast<::Parser::Rule>(dt), tabs + 1);
    } else if (dt.type() == typeid(std::string)) {
        printData(std::any_cast<std::string>(dt), 0);
    } else if (dt.type() == typeid(const char*)) {
        printData(std::any_cast<const char*>(dt), 0);
    } else if (dt.type() == typeid(std::unordered_map<const char*, std::any>)) {
        printData(std::any_cast<std::unordered_map<const char*, std::any>>(dt), tabs + 1);
    } else if (dt.type() == typeid(std::unordered_map<std::string, std::any>)) {
        printData(std::any_cast<std::unordered_map<std::string, std::any>>(dt), tabs + 1);
    } else {
        printf("Unknown data type\n");
    }
    printf("}\n");
}

void printData(const std::unordered_map<const char*, std::any> data, int tabs = 0) {
    for (auto [key, value] : data) {
        printTabs(tabs);
        printf("%s: ", key);
        if (value.type() == typeid(::Parser::Rule)) {
            printData(std::any_cast<::Parser::Rule>(value), tabs + 1);
        } else if (value.type() == typeid(std::string)) {
            printf("%s\n", std::any_cast<std::string>(value).c_str());
        } else if (value.type() == typeid(const char*)) {
            printf("%s\n", std::any_cast<const char*>(value));
        } else {
            printf("Unknown data type\n");
        }
    }
}
void printData(const std::unordered_map<std::string, std::any> data, int tabs = 0) {
    for (auto [key, value] : data) {
        printTabs(tabs);
        printf("%s: ", key.c_str());
        if (value.type() == typeid(::Parser::Rule)) {
            printData(std::any_cast<::Parser::Rule>(value), tabs + 1);
        } else if (value.type() == typeid(std::string)) {
            printf("%s\n", std::any_cast<std::string>(value).c_str());
        } else if (value.type() == typeid(const char*)) {
            printf("%s\n", std::any_cast<const char*>(value));
        } else {
            printf("Unknown data type\n");
        }
    }
}


::Parser::Tree Parser::Parser::parse() {
    auto len = strlen(text);
    Tree tree;
    auto in = text;
    size_t rule_count = 0;
    for (;*in;) {
        ISC_STD::skip_spaces(in);
        auto comment_res = linear_comment(in);
        if (comment_res.result) {
            // found a comment in begin, go to the end and continue loop
            in += comment_res.token.length();
            continue;
        }
        bool require_end = true;
        auto res = Import(in);
        if (!res.result) {
            res = use(in);
            if (!res.result) {
                res = Rule(in);
                if (!res.result) {
                    res = spacemode(in);
                    if (!res.result)
                    {
                        printf("Stopped at %ld, in == '\\0': %s\n", in - text, (*in == '\0') ? "true" : "false");
                        break;
                    }
                } else {
                    require_end = false;
                }
            }
        }
        in += res.token.length();
        // match end
        ISC_STD::skip_spaces(in);
        if (require_end) {
            auto end_res = end(in);
            if (!end_res.result) {
                break;
            }
            in += end_res.token.length();
        }
        tree.push_back(res.token);
    }
    // for (auto el : tree) {
    //     printData(el);
    // }
    return tree;
}