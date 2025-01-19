#include <parser.h>
#include <internal_types.h>
namespace IR {
    enum class types {
        RULE, GROUP, VARIABLE, IF, ACCESSOR
    };
    enum class condition_types {
        GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
        HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
        LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND,
        CHARACTER, CURRENT_CHARACTER, NUMBER, STRING, STRNCMP
    };

    struct cond_unit {
        condition_types id;
        std::any value = {};

    };
    struct member {
        types type;
        std::any value = {};
        size_t assign_next_rules = 0;
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