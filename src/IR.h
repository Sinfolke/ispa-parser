#pragma once
#include <parser.h>
#include <internal_types.h>
#include <any>
namespace IR {
    enum class types {
        NONE, RULE, TOKEN, RULE_END, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
        METHOD_CALL, FUNCTION_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
        ASSIGN_VARIABLE, INCREASE_POS_COUNTER, SKIP_SPACES
    };
    enum class condition_types {
        GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
        HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
        LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND,
        CHARACTER, CURRENT_CHARACTER, CURRENT_TOKEN, NUMBER, HEX, BIN, STRING, STRNCMP,
        VARIABLE, SUCCESS_CHECK
    };
    enum class var_types {
        UNDEFINED, STRING, BOOLEAN, NUMBER, ARRAY, OBJECT, FUNCTION, ANY, Rule, Token,
        CHAR, UCHAR, SHORT, USHORT, INT, UINT, LONG, ULONG, LONGLONG, ULONGLONG
    };
    enum class var_assign_values {
        NONE, _TRUE, _FALSE, NUMBER, BOOLEAN, STRING, ARRAY, OBJECT, ID, 
        UCHAR, CHAR, USHORT, SHORT, UINT, INT, ULONG, LONG, ULONGLONG, LONGLONG,
        CURRENT_POS_COUNTER, CURRENT_POS_SEQUENCE, CURRENT_TOKEN, TOKEN_SEQUENCE, FUNCTION_CALL
    };
    enum class var_assign_types {
        ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO, BITWISE_AND, BITWISE_OR, BITWISE_ANDR, BITWISE_RIGHTSHFT, BITWISE_LEFTSHIFT, ASSIGN,
        ASSIGN_ADD, ASSIGN_SUBSTR, ASSIGN_MULTIPLY, ASSIGN_DIVIDE, ASSIGN_MODULO, 
        ASSIGN_BITWISE_AND, ASSIGN_BITWISE_OR, ASSIGN_BITWISE_ANDR, ASSIGN_BITWISE_RIGHTSHFT, ASSIGN_BITWISE_LEFTSHIFT
    };
    struct var_type {
        var_types type;
        arr_t<var_type> templ;
    };
    struct member {
        types type = types::NONE;
        std::any value = {};
    };
    struct assign {
        var_assign_values value;
        std::any data;
    };
    struct function_call {
        std::string name;
        arr_t<assign> params;
    };
    struct method_call {
        std::string var_name;
        function_call call;
    };
    using array = std::vector<assign>;
    using object = std::unordered_map<std::string, assign>;
    struct expr {
        condition_types id;
        std::any value = {};
    };
    struct condition {
        arr_t<expr> expression;
        arr_t<member> block;
        arr_t<member> else_block = {}; 
    };

    struct variable {
        var_type type = {var_types::UNDEFINED};
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
        void pop();
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
    struct node_ret_t {
        std::string svar;
        std::string var;
    }; 
};

void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, int &variable_count, bool isToken, IR::node_ret_t &success_var, char custom_qualifier = -1);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string rule_name, bool isToken, arr_t<IR::node_ret_t> &success_vars, int &variable_count, bool new_rule = false);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string rule_name, bool isToken, arr_t<IR::node_ret_t> &success_vars, bool new_rule = false);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken, int &variable_count);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string rule_name, bool isToken, bool new_rule = false);
IR::ir treeToIr(Parser::Tree &tree, std::string nested_name = "");