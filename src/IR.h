#pragma once
#include <parser.h>
#include <internal_types.h>
#include <any>
namespace IR {
    enum class types {
        NONE, RULE, GROUP, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
        METHOD_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
        ASSIGN_VARIABLE, INCREASE_POS_COUNTER
    };
    enum class condition_types {
        GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
        HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
        LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND,
        CHARACTER, CURRENT_CHARACTER, CURRENT_TOKEN, NUMBER, STRING, STRNCMP,
        VARIABLE
    };
    enum class var_type {
        UNDEFINED, STRING, BOOLEAN, NUMBER, ARRAY, OBJECT, FUNCTION, ANY, Rule, Token
    };
    enum class var_assign_values {
        NONE, _TRUE, _FALSE, CURRENT_POS_COUNTER, CURRENT_POS_SEQUENCE
    };
    enum class var_assign_types {
        ASSIGN, ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO
    };
    struct member {
        types type = types::NONE;
        std::any value = {};
    };
    struct method_call {
        std::string var_name;
        std::string method_name;
    };
    struct expr {
        condition_types id;
        std::any value = {};
    };
    struct condition {
        arr_t<expr> expression;
        arr_t<member> block; 
    };
    struct assign {
        var_assign_values value;
        std::any data;
    };
    struct variable {
        var_type type = var_type::UNDEFINED;
        std::string name = "";
        assign value = {var_assign_values::NONE};
        int assign_next_rules = 0;
    };
    struct variable_assign {
        std::string name;
        var_assign_types assign_type = var_assign_types::ASSIGN;
        assign value = {var_assign_values::NONE};
    };
    struct accessor {
        arr_t<Parser::Rule> elements;
        char qualifier;
    };
    class ir {
        public:
        arr_t<member> elements;
        void add(ir repr);
        void add(arr_t<member> repr);
        void push(member member);
        size_t size();
        bool empty();
    };
    // struct element_count {
    //     size_t in_rule_index;
    //     size_t in_ir_index;
    // };
    struct element_count {
        size_t index_in_ir;
        size_t index_in_rule;
    };
    using node_ret_t = std::string; 
};

void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, int &variable_count, bool isToken, IR::node_ret_t &success_var);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken, arr_t<IR::node_ret_t> &success_vars, int &variable_count);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken, arr_t<IR::node_ret_t> &success_vars);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken, int &variable_count);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken);
IR::ir treeToIr(Parser::Tree &tree);