export module Parser;

import <unordered_map>;
import <cctype>;
import <vector>;
import <cstring>;
import <cstddef>;
#include <iscstdlibc++.h>
export namespace Parser {
    export enum class Rules {
    
    Import_path,
    Import_ext,
    Import_file,
    Import_general_dir,
    Import_rulespecific,

    use_unit,

    Rule_rule,
    Rule_op,
    Rule_qualifier,
    Rule_group,
    Rule_csequence,
    Rule_csequence_symbol,
    Rule_csequence_escape,
    Rule_csequence_diapason,
    Rule_data_block,
    Rule_data_block_key,
    Rule_nested_rule,
    Rule_hex,
    Rule_bin,

    cll_type_abstract,

    expr_variable_value,
    expr_compare,
    expr_compare_side,
    expr_logical,
    expr_parenthesed,
    expr_parenthesed_variable_assignment,
    expr_not,

    end,
    strict_end,
    newline,
    id,
    Import,
    use,
    Rule,

    string,
    number,
    boolean,
    array,
    object,
    any_data,

    cll_block,
    cll_spaced_block,
    op,
    assignment_op,
    compare_op,
    logical_op,
    logical_and,
    logical_or,
    logical_andr,

    cll_template_typename,
    cll_template_int,
    cll_template_bool,
    cll_template_str,
    cll_template_arr,
    cll_template_obj,
    cll_template_any_data,
    cll_template_all,
    cll_template_content_param1_t,

    cll_csupport_types,
    cll_type,

    cll_if,

    cll_ternary,

    expr,

    function_body_call,
    function_body_decl,
    function_arguments,
    function_parameters,
    cll_function_call,
    function_decl,

    method_call,
    copiable_method_call,

    cll_var,

    cll

    };
    using Rule_result = ISC_STD::_return<Rules>;
    export class Parser {
        private:
            const char* text;
            std::size_t getCurrentPos(const char* pos) {
                return text - pos;
            }
            #define Rule(x, ...) Rule_result x (const char* in, ##__VA_ARGS__);
            Rule(Import_path);
            Rule(Import_ext);
            Rule(Import_file);
            Rule(Import_general_dir);
            Rule(Import_rulespecific); 

            Rule(use_unit);

            Rule(Rule_rule);
            Rule(Rule_op);
            Rule(Rule_qualifier);
            Rule(Rule_group);
            Rule(Rule_csequence);
            Rule(Rule_csequence_symbol);
            Rule(Rule_csequence_escape);
            Rule(Rule_csequence_diapason);
            Rule(Rule_data_block);
            Rule(Rule_data_block_key);
            Rule(Rule_nested_rule);
            Rule(Rule_hex);
            Rule(Rule_bin);

            Rule(cll_type_abstract)

            Rule(expr_variable_value);
            Rule(expr_compare);
            Rule(expr_compare_side);
            Rule(expr_logical);
            Rule(expr_parenthesed);
            Rule(expr_parenthesed_variable_assignment)
            Rule(expr_not);

            size_t getCurrentPos(const char* pos);
            const char* text;
        public:
            Tree parse();

            // Rule methods
            Rule(end);
            Rule(strict_end);
            Rule(newline);
            Rule(id);
            Rule(Import);
            Rule(use);
            Rule(Rule)

            
            Rule(string);
            Rule(number);
            Rule(boolean);
            Rule(array);
            Rule(object);
            Rule(any_data);

            Rule(cll_block);
            Rule(cll_spaced_block);
            Rule(op);
            Rule(assignment_op);
            Rule(compare_op);
            Rule(logical_op);
            Rule(logical_and);
            Rule(logical_or);
            Rule(logical_andr);

            Rule(cll_template_typename);
            Rule(cll_template_int);
            Rule(cll_template_bool);
            Rule(cll_template_str);
            Rule(cll_template_arr);
            Rule(cll_template_obj);
            Rule(cll_template_any_data);
            Rule(cll_template_all)
            Rule(cll_template, cll_template_content_param1_t);

            Rule(cll_csupport_types);
            Rule(cll_type);

            Rule(cll_if);

            Rule(cll_ternary);

            Rule(expr);

            Rule(function_body_call);
            Rule(function_body_decl);
            Rule(function_arguments);
            Rule(function_parameters);
            Rule(cll_function_call);
            Rule(function_decl);

            Rule(method_call);
            Rule(copiable_method_call);

            Rule(cll_var);
            
            Rule(cll);
            #undef Rule
    };
};
#include <parser_defs.h>
export import parser.Rule;
export import parser.dataTypes;
export import parser.end;
export import parser.cll;
Rule(id) {
    int c = 0;
    const char* pos = in;
    std::string val;
    ISC_STD::skipup(pos, " ");
    while (*pos >= '0' and *pos <= '9') {
        val += *pos++;
    }
    ISC_STD::skipup(pos, " ");
    if (
        not 
        (
        *pos >= 'a' and *pos <= 'f' || 
        *pos >= 'A' and *pos <= 'F' || 
        *pos == '_'
        )
    ) {
        return {};
    }
    val += *pos++;
    ISC_STD::skipup(pos, " ");
    while (
        *pos >= 'a' and *pos <= 'f' || 
        *pos >= 'A' and *pos <= 'F' || 
        *pos >= '0' and *pos <= '9' || 
        *pos == '_'
    ) {
        val += *pos++;
    }
    // construct result as valid
    // extract full string from the first group
    RULE_SUCCESSD(in, pos, id, val);
}
Rule(Import_path) {    
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    while (
        not 
        (
            *pos == '"' ||
            *pos == '<' ||
            *pos == '>' ||
            *pos == '|' ||
            *pos == ':' ||
            *pos == '?' ||
            *pos == '.' ||
        )
    ) ++pos;
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Priv_Import_path, string_part(in, pos));
};
Rule(Import_ext) {    
    auto pos = in;
    std::vector<Rule_result> data;
    ISC_STD::skipup(pos, " ");
    while(true) {
        if (*pos == '.') {
            ++pos;
            ISC_STD::skipup(pos, " ");
            auto match_res = id(pos);
            if (match_res.result) {
                data.push_back(match_res);
                pos += match_res.token.length();
                continue;
            }
            --pos; // dot is skipped
        }
        break;
    }
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Priv_Import_ext, data);
};
Rule(Import_file) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    auto path_res = Import_path(pos);
    if (!path_res.result) return {};
    pos += path_res.token.length();
    ISC_STD::skipup(pos, " ");
    auto ext_res = Import_ext(pos);
    if (!ext_res.result) return {};
    pos += ext_res.token.length();
    // join
    std::string joined;
    for (auto obj : ext_res) {
        joined += TO(std::string, obj.data);
    }
    std::unordered_map<const char*, std::any> data = {
        { "path", path_res },
        { "ext", TO(std::vector<Rule_result>, ext_res.token.data).back() },
        { "fullext", ext_res },
        { "fullpath", std::string( TO(std::string_part, path_res.token.data )) + joined }
    };
    RULE_SUCCESSD(in, pos, Priv_Import_file, data);
}
Rule(Import_general_dir) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    if (*pos != '[')
        return {};
    pos++;
    ISC_STD::skipup(pos, " ");
    auto path_res = Import_path(pos);
    if (!path_res.result) return {};
    pos += path_res.token.length();
    ISC_STD::skipup(pos, " ");
    if (*pos != ']')
        return {};
    
    auto _local_start = ++pos;
    std::vector<Rule> files;
    while(true) {
        int v = ISC_STD::skipup(pos, " ");
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
    RULE_SUCCESSD(in, pos, Priv_Import_general_dir, files);
}
Rule(Import_rule_specific) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    auto file_res = Import_file(pos);
    if (!file_res.result)
        return {};
    pos += file_res.token.length();
    ISC_STD::skipup(pos, " ");
    if (*pos != '{')
        return {};
    pos++;
    ISC_STD::skipup(pos, " ");
    auto _local_start = pos;
    std::vector<Token> tokens;
    std::vector<Token> tokens_current_name;
    while (true) {
        ISC_STD::skipup(pos, " ");
        auto id_res = id(pos);
        if (!id_res.result)
            break;
        tokens.push_back(id_res.token);
        pos += id_res.token.length();
        ISC_STD::skipup(pos, " ");
        if (*pos == '=') {
            ++pos;
            ISC_STD::skipup(pos, " ");
            auto id2_res = id(pos);
            if (!id2_res.result)
                break;
            tokens_current_name.push_back(id2_res.token);
        }
    }
    if (_local_start == pos)
        return {}; // zero match
    std::unordered_map<const char*, std::any> data {
        { "path", file_res.token },
        { "tokens", tokens },
        { "tokens_current_name", tokens_current_name }
    }
    RULE_SUCCESSD(in, pos, Priv_Import_rule_specific, data);
}
Rule(Import) {
    auto pos = in;
    ISC_STD::skipup(pos, " ");
    if (strncmp(pos, "import", sizeof("import") - 1))
        return {};
    pos += sizeof("import") - 1;
    ISC_STD::skipup(pos, " ");
    auto first_rule_res = Import_file(pos);
    if (!first_rule_res.result) {
        first_rule_res = Import_general_dir(pos);
        if (!first_rule_res.result) {
            first_rule_res = Import_rule_specific(pos);
            if (!first_rule_res.result)
                return {};
        }
    }
    pos += first_rule_res.token.length();
    ISC_STD::skipup(pos, " ");
    std::vector<Token> additional_paths;
    while (*pos == ',') {
        ++pos;
        ISC_STD::skipup(pos, " ");
        auto result = Import_file(pos);
        if (!result.result) {
            result = Import_general_dir(pos);
            if (!result.result) {
                result = Import_rule_specific(pos);
                if (!result.result)
                    break;
            }
        }
        pos += result.token.length();
        additional_paths.push_back(result.token);
    }
    using obj_type = std::unordered_map<const char*, std::any>;
    std::vector<obj_type> data = {
        first_rule_res.token
    };
    // push remaining arguments inlining the array
    data.insert(data.end(), additional_paths.begin(), additional_paths.end());
    for (const auto obj : additional_paths) {
        data.push_back( TO(obj_type, obj.data ) );
    }
    RULE_SUCCESSD(in, pos, Import, data);
}
Rule(use) {
    auto pos = in;
    std::unordered_map<const char*, std::string> data();
    ISC_STD::skipup(pos, " ");
    if (strncmp(pos, "use", 3)) {
        return {};
    }
    pos += 3;
    ISC_STD::skipup(pos, " ");
    auto use_unit_res = use_unit(pos);
    if (not use_unit_res.result)
        return {};
    pos += use_unit_res.token.length();
    ISC_STD::skipup(pos, " ");
    std::vector<Rule> use_unit_results_2(5); // generally no over 5 elements will be found & avoid extra allocations optimization
    ISC_STD::skipup(pos, " ");
    while(*pos == ',') {
        ISC_STD::skipup(pos, " ");
        auto use_unit_res = use_unit(pos + 1);
        if (not use_unit_res.result)
            break;
        pos += use_unit_res.token.length() + 1;
        use_unit_results_2.push_back(use_unit_res.token);
    }
    using map_t = std::unordered_map<const char*, const char*>;
    auto token = TO(map_t, use_unit_res.token.data);
    data[token["name"]] = token["value"];
    for (int i = 0; i < use_unti_results_2.size(); ++i) {
        token = TO (map_t, use_unit_results_2[i].data);
        data[token["name"]] = token["value"];
    }
    RULE_SUCCESSD(in, pos, use, data);
}
Rule(use_unit) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res)
        return {};
    pos += id_res.token.length();
    ISC_STD::skipup(pos, " ");
    std::string str;
    if (*pos == ':') {
        ISC_STD::skipup(pos, " ");
        auto string_res = string(++pos); // std::string
        if (string_res.result) {
            str = TO(std::string, string_res.token.data);
        } else {
            while(*pos != ',')
            {
                if (*pos != ' ') str += *pos;
            }
        }
    }
    std::unordered_map<const char*, std::any> data {
        { "name", id.token },
        { "value", str }
    };
    RULE_SUCCESSD(in, pos, use, data);
}
