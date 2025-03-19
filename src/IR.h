#pragma once
#include <parser.h>
#include <internal_types.h>
#include <any>
#include <list>
#include <algorithm>
#include <unordered_set>
namespace IR {
    enum class types {
        NONE, RULE, TOKEN, RULE_END, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
        METHOD_CALL, FUNCTION_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
        ASSIGN_VARIABLE, INCREASE_POS_COUNTER, SKIP_SPACES, DATA_BLOCK, PUSH_POS_COUNTER, POP_POS_COUNTER, INSIDE_LOOP
    };
    enum class condition_types {
        GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
        HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
        LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND, BITWISE_OR, BITWISE_ANDR,
        ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO,  
        CHARACTER, CURRENT_CHARACTER, PREV_CHARACTER, CURRENT_TOKEN, NUMBER, HEX, BIN, STRING, STRNCMP,
        VARIABLE, SUCCESS_CHECK, ANY_DATA, METHOD_CALL, FUNCTION_CALL
    };
    enum class var_types {
        UNDEFINED, STRING, BOOLEAN, NUMBER, ARRAY, OBJECT, FUNCTION, ANY, Rule, Token, Rule_result, Token_result,
        CHAR, UCHAR, SHORT, USHORT, INT, UINT, LONG, ULONG, LONGLONG, ULONGLONG
    };
    enum class var_assign_values {
        NONE, _TRUE, _FALSE, NUMBER, BOOLEAN, STRING, ARRAY, OBJECT, VARIABLE, PROPERTY, VAR_REFER, ACCESSOR, 
        UCHAR, CHAR, USHORT, SHORT, UINT, INT, ULONG, LONG, ULONGLONG, LONGLONG, CURRENT_POS,
        CURRENT_POS_COUNTER, CURRENT_POS_SEQUENCE, CURRENT_TOKEN, TOKEN_SEQUENCE, FUNCTION_CALL, EXPR, INCLOSED_MAP
    };
    enum class var_assign_types {
        ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO, BITWISE_AND, BITWISE_OR, BITWISE_ANDR, BITWISE_RIGHTSHFT, BITWISE_LEFTSHIFT, ASSIGN,
        ASSIGN_ADD, ASSIGN_SUBSTR, ASSIGN_MULTIPLY, ASSIGN_DIVIDE, ASSIGN_MODULO, 
        ASSIGN_BITWISE_AND, ASSIGN_BITWISE_OR, ASSIGN_BITWISE_ANDR, ASSIGN_BITWISE_RIGHTSHFT, ASSIGN_BITWISE_LEFTSHIFT
    };
    struct var_type {
        var_types type = IR::var_types::UNDEFINED;
        arr_t<var_type> templ = {};
    };
    struct member {
        types type = types::NONE;
        std::any value = {};
    };
    struct assign {
        var_assign_values kind;
        std::any data;
    };
    struct function_call {
        std::string name;
        arr_t<assign> params;
    };
    struct method_call {
        std::string var_name;
        std::vector<function_call> calls;
    };
    struct property {
        std::string obj;
        std::list<std::string> properties;
    };
    struct var_refer {        
        bool pre_increament;
        bool post_increament;
        std::string name;
    };
    struct current_token {
        condition_types op;
        std::string name;
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
        std::string name = "";
        var_type type = {var_types::UNDEFINED};
        assign value = {var_assign_values::NONE};
        std::list<std::string> property_access = {};
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
    struct strncmp {
        bool is_string;
        IR::variable value;
    };
    using inclosed_map = std::unordered_map<std::string, std::pair<arr_t<IR::expr>, var_type>>;
    struct data_block {
        assign value;
        IR::var_type assign_type;
        bool is_inclosed_map;
    };
    class ir {
        public:
        arr_t<member> elements;
        void add(ir repr);
        void add(arr_t<member> repr);
        void push(member member);
        void push_begin(member member);
        void pop_begin();
        void pop();
        size_t size();
        bool empty();
    };
    struct node_ret_t {
        IR::variable svar;
        IR::variable var;
        IR::variable shadow_var = {};
    };
    struct var_group {
        IR::variable var;
        size_t begin;
        size_t end;
    };
    using var_elements = std::vector<IR::variable>;
    using variables = std::list<IR::variable>;
    using groups = std::vector<var_group>;
    using nested_rule_name = std::vector<std::pair<std::string, std::string>>;
};
void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, int &variable_count, bool isToken, IR::nested_rule_name nested_rule_name, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, std::string &fullname, IR::node_ret_t &success_var, char custom_qualifier = -1);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, arr_t<IR::node_ret_t> &success_vars, int &variable_count);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, arr_t<IR::node_ret_t> &success_vars);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop, int &variable_count);
IR::ir rulesToIr(arr_t<Parser::Rule> rules, std::string &rule_name, bool isToken, IR::nested_rule_name &nested_rule_names, IR::var_elements &elements, IR::groups &groups, IR::variables &vars, bool &insideLoop);
IR::ir treeToIr(Parser::Tree &tree, std::string nested_name, IR::nested_rule_name &nested_rule_names);