#include <parser.h>
#include <internal_types.h>
namespace IR {
    enum class types {
        RULE, GROUP, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
        METHOD_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
        ASSIGN_VARIABLE
    };
    enum class condition_types {
        GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
        HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
        LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND,
        CHARACTER, CURRENT_CHARACTER, NUMBER, STRING, STRNCMP,
        VARIABLE
    };
    enum class var_type {
        UNDEFINED, STRING, BOOLEAN
    };
    enum class var_assign_types {
        NONE, TRUE, FALSE, CURRENT_POS_COUNTER
    };
    struct member {
        types type;
        std::any value = {};
    };
    struct method_call {
        std::string var_name; 
    };
    struct expr {
        condition_types id;
        std::any value = {};
    };
    struct condition {
        arr_t<expr> expression;
        arr_t<member> block; 
    };
    struct variable {
        var_type type;
        std::string name;
        var_assign_types value;
        int assign_next_rules = 0;
    };
    struct variable_assign {
        std::string name;
        var_assign_types value;
    };
    class ir {
        public:
        arr_t<member> elements;
        void add(ir repr);
        void push(member member);
        size_t size();
    };
    // struct element_count {
    //     size_t in_rule_index;
    //     size_t in_ir_index;
    // };
    struct element_count {
        size_t index_in_ir;
        size_t index_in_rule;
    };
};

void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, arr_t<IR::element_count> &elements, int &variable_count);
IR::ir rulesToIr(arr_t<Parser::Rule> rules);
IR::ir treeToIr(Parser::Tree &tree);