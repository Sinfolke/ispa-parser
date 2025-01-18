#include <parser.h>
#include <internal_types.h>
namespace IR {
    enum class types {
        RULE, GROUP, VARIABLE, IF
    };
    enum class condition {
        GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
        HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
        ACCESSOR, CHARACTER, STRING, STRNCMP
    };

    struct cond_unit {
        condition id;
        std::any value = {};
        Parser::Rules accessor_kind = Parser::Rules::NONE;
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

};
IR::ir ruleToIr(Parser::Rule rule_rule);
IR::ir rulesToIr(arr_t<Parser::Rule> rules);
IR::ir treeToIr(Parser::Tree &tree);