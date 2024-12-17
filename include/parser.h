#pragma once
#include <unordered_map>
#include <cctype>
#include <vector>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iscstdlibc++.h>
namespace Parser {
    class Parser;
    enum class Rules {
    NONE,
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
    Rule_data_block_inclosed_map,
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
    spacemode,
    linear_comment,
    id,
    Import,
    use,
    Rule,

    accessors_group,
    accessors_element,
    accessors_char,
    accessor,

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
    cll_template,

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
    function_value,
    
    method_call,
    copiable_method_call,
    loop_while,
    loop_for,
    cll_var,
    cll_var_operator_post,
    cll_var_operator_pre,
    cll_var_operator,
    var_refer,
    
    cll
    };
    using Rule = ISC_STD::_return<::Parser::Rules>;
    using Rule_result = ISC_STD::match_result<::Parser::Rules>;
    using Tree = ISC_STD::Tree<::Parser::Rules>;
    using cll_template_content_param1_t = Rule_result (Parser::*)(const char*);
    class Parser {
        private:
            const char* text;
            std::size_t getCurrentPos(const char* pos);
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
            Rule(Rule_data_block_inclosed_map);
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

            Rule(cll_var_operator_post);
            Rule(cll_var_operator_pre);
        public:
            Tree parse();
            Parser(const char* text) : text(text) {}
            // Rule methods
            Rule(end);
            Rule(strict_end);
            Rule(newline);
            Rule(spacemode);
            Rule(linear_comment);
            Rule(id);
            Rule(Import);
            Rule(use);
            Rule(Rule);

            Rule(accessors_group);
            Rule(accessors_element);
            Rule(accessors_char);
            Rule(accessor_all);
            Rule(accessor);
            
            Rule(string);
            Rule(number);
            Rule(boolean);
            Rule(array);
            Rule(object);
            Rule(any_data);

            Rule(cll_block);
            Rule(cll_spaced_block, int spaces);
            Rule(op);
            Rule(assignment_op);
            Rule(compare_op);
            Rule(logical_op);
            Rule(logical_not);
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
            Rule(expr_no_compare);
            Rule(expr_no_logical);

            Rule(function_body_call);
            Rule(function_body_decl);
            Rule(function_arguments);
            Rule(function_parameters);
            Rule(cll_function_call);
            Rule(function_decl);
            Rule(function_value, int spaces);
            Rule(method_call);
            Rule(copiable_method_call);

            Rule(loop_while);
            Rule(loop_for);
            Rule(cll_var);
            Rule(cll_var_operator);
            Rule(var_refer);

            Rule(cll);
            #undef Rule
    };
};