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
        not 
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
#include <string>
#include <unordered_map>

// Define the function to convert Rules enum to string
std::string RulesToString(::Parser::Rules rule) {
    using Rules = ::Parser::Rules;
    static const std::unordered_map<::Parser::Rules, std::string> rulesToString{
        {Rules::NONE, "NONE"},
        {Rules::Import_path, "Import_path"},
        {Rules::Import_ext, "Import_ext"},
        {Rules::Import_file, "Import_file"},
        {Rules::Import_general_dir, "Import_general_dir"},
        {Rules::Import_rulespecific, "Import_rulespecific"},
        {Rules::use_unit, "use_unit"},
        {Rules::Rule_rule, "Rule_rule"},
        {Rules::Rule_op, "Rule_op"},
        {Rules::Rule_qualifier, "Rule_qualifier"},
        {Rules::Rule_group, "Rule_group"},
        {Rules::Rule_csequence, "Rule_csequence"},
        {Rules::Rule_csequence_symbol, "Rule_csequence_symbol"},
        {Rules::Rule_csequence_escape, "Rule_csequence_escape"},
        {Rules::Rule_csequence_diapason, "Rule_csequence_diapason"},
        {Rules::Rule_data_block, "Rule_data_block"},
        {Rules::Rule_data_block_key, "Rule_data_block_key"},
        {Rules::Rule_data_block_inclosed_map, "Rule_data_block_inclosed_map"},
        {Rules::Rule_nested_rule, "Rule_nested_rule"},
        {Rules::Rule_hex, "Rule_hex"},
        {Rules::Rule_bin, "Rule_bin"},
        {Rules::cll_type_abstract, "cll_type_abstract"},
        {Rules::expr_variable_value, "expr_variable_value"},
        {Rules::expr_compare, "expr_compare"},
        {Rules::expr_compare_side, "expr_compare_side"},
        {Rules::expr_logical, "expr_logical"},
        {Rules::expr_parenthesed, "expr_parenthesed"},
        {Rules::expr_parenthesed_variable_assignment, "expr_parenthesed_variable_assignment"},
        {Rules::expr_not, "expr_not"},
        {Rules::end, "end"},
        {Rules::strict_end, "strict_end"},
        {Rules::newline, "newline"},
        {Rules::spacemode, "spacemode"},
        {Rules::linear_comment, "linear_comment"},
        {Rules::id, "id"},
        {Rules::Import, "Import"},
        {Rules::use, "use"},
        {Rules::Rule, "Rule"},
        {Rules::accessors_group, "accessors_group"},
        {Rules::accessors_element, "accessors_element"},
        {Rules::accessors_char, "accessors_char"},
        {Rules::string, "string"},
        {Rules::number, "number"},
        {Rules::boolean, "boolean"},
        {Rules::array, "array"},
        {Rules::object, "object"},
        {Rules::any_data, "any_data"},
        {Rules::cll_block, "cll_block"},
        {Rules::cll_spaced_block, "cll_spaced_block"},
        {Rules::op, "op"},
        {Rules::assignment_op, "assignment_op"},
        {Rules::compare_op, "compare_op"},
        {Rules::logical_op, "logical_op"},
        {Rules::logical_and, "logical_and"},
        {Rules::logical_or, "logical_or"},
        {Rules::logical_andr, "logical_andr"},
        {Rules::cll_template_typename, "cll_template_typename"},
        {Rules::cll_template_int, "cll_template_int"},
        {Rules::cll_template_bool, "cll_template_bool"},
        {Rules::cll_template_str, "cll_template_str"},
        {Rules::cll_template_arr, "cll_template_arr"},
        {Rules::cll_template_obj, "cll_template_obj"},
        {Rules::cll_template_any_data, "cll_template_any_data"},
        {Rules::cll_template_all, "cll_template_all"},
        {Rules::cll_template, "cll_template"},
        {Rules::cll_csupport_types, "cll_csupport_types"},
        {Rules::cll_type, "cll_type"},
        {Rules::cll_if, "cll_if"},
        {Rules::cll_ternary, "cll_ternary"},
        {Rules::expr, "expr"},
        {Rules::function_body_call, "function_body_call"},
        {Rules::function_body_decl, "function_body_decl"},
        {Rules::function_arguments, "function_arguments"},
        {Rules::function_parameters, "function_parameters"},
        {Rules::cll_function_call, "cll_function_call"},
        {Rules::function_decl, "function_decl"},
        {Rules::function_value, "function_value"},
        {Rules::method_call, "method_call"},
        {Rules::copiable_method_call, "copiable_method_call"},
        {Rules::cll_var, "cll_var"},
        {Rules::cll, "cll"}
    };

    auto it = rulesToString.find(rule);
    return it != rulesToString.end() ? it->second : "Unknown Rule";
}
void printTabs(int tabs) {
    if (tabs > 0) {
        for (int i = 0; i < tabs; ++i)
            printf("\t");
    }
}
void printRuleData(const ::Parser::Rule& rule, int tabs = 0) {
    // Helper function to print indentation
    auto printTabs = [](int count) {
        while (count-- > 0) printf("\t");
    };

    // Print the rule name
    printTabs(tabs);
    printf("Name: %s\n", RulesToString(rule.name).c_str());

    // Extract the rule's data
    const std::any& dt = rule.data;
    if (!dt.has_value()) { // Check if std::any contains a value
        printTabs(tabs);
        printf("No data\n");
        return;
    }

    printTabs(tabs);

    // Handle the different possible types of data
    if (dt.type() == typeid(::Parser::Rule)) {
        // Recursively print nested rule
        printRuleData(std::any_cast<::Parser::Rule>(dt), tabs + 1);
    } 
    else if (dt.type() == typeid(std::unordered_map<std::string, std::any>)) {
        // Iterate over the map and handle keys/values
        const auto& map = std::any_cast<std::unordered_map<std::string, std::any>>(dt);
        for (const auto& [key, value] : map) {
            printTabs(tabs + 1);
            printf("%s: ", key.c_str());

            if (value.type() == typeid(::Parser::Rule)) {
                printRuleData(std::any_cast<::Parser::Rule>(value), tabs + 2);
            } 
            else if (value.type() == typeid(std::string)) {
                printf("%s\n", std::any_cast<std::string>(value).c_str());
            } 
            else if (value.type() == typeid(const char*)) {
                printf("%s\n", std::any_cast<const char*>(value));
            } 
            else {
                printf("Unknown data type\n");
            }
        }
    } else if (dt.type() == typeid(std::unordered_map<const char*, std::any>)) {
        // Iterate over the map and handle keys/values
        const auto& map = std::any_cast<std::unordered_map<const char*, std::any>>(dt);
        for (const auto& [key, value] : map) {
            printTabs(tabs + 1);
            printf("%s: ", key);

            if (value.type() == typeid(::Parser::Rule)) {
                printRuleData(std::any_cast<::Parser::Rule>(value), tabs + 2);
            } 
            else if (value.type() == typeid(std::string)) {
                printf("%s\n", std::any_cast<std::string>(value).c_str());
            } 
            else if (value.type() == typeid(const char*)) {
                printf("%s\n", std::any_cast<const char*>(value));
            } 
            else {
                printf("Unknown data type\n");
            }
        }
    } 
    else if (dt.type() == typeid(std::string)) {
        printf("%s\n", std::any_cast<std::string>(dt).c_str());
    } 
    else if (dt.type() == typeid(const char*)) {
        printf("%s\n", std::any_cast<const char*>(dt));
    } 
    else {
        printf("Unknown data type\n");
    }
}

::Parser::Tree Parser::Parser::parse() {
    auto len = strlen(text);
    Tree tree;
    auto in = text;
    size_t rule_count = 0;
    for (;*in;) {
        printf("entering rule %zu\n", rule_count++);
        ISC_STD::skip_spaces(in);
        auto comment_res = linear_comment(in);
        if (comment_res.result) {
            // found a comment in begin, go to the end and continue loop
            in += comment_res.token.length();
            printf("found comment - skipping\n");
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
                        if (*in == '\0')
                            printf("EOF\n");
                        else 
                            printf("Stopped at rule\n");
                        break;
                    }
                } else {
                    require_end = false;
                }
            }
        }
        std::cout << "Token length: " << res.token.length() << "\n";
        in += res.token.length();
        // match end
        ISC_STD::skip_spaces(in);
        printf("matching end at %ld, in: %c", in - text, *in);
        if (require_end) {
            auto end_res = end(in);
            if (!end_res.result) {
                printf("Unmatched end of rule\n");
                break;
            }
            in += end_res.token.length();
        }
        tree.push_back(res.token);
        printf("Stopped at %ld\n", in - text);
    }
    // for (auto el : tree) {
    //     printRuleData(el);
    // }
    // int count = 0;
    // ::Parser::Rules prevName = ::Parser::Rules::NONE;
    // for (auto el : tree) {
    //     if (prevName == el.name) {
    //         count++;
    //         continue;
    //     } else if (prevName != ::Parser::Rules::NONE) {
    //         printf(" [%d]\n", count + 1);
    //         count = 0;
    //     } else {
    //         printf("\n");
    //     }
    //     prevName = el.name;
    //     std::cout << "Token: " << RulesToString(el.name);
    // }
    // if (count != 0)
    //     printf(" [%d]\n", count + 1);
    return tree;
}