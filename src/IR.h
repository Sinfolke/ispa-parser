#include <parser.h>
#include <internal_types.h>
namespace IR {
    enum class types {
        RULE, GROUP, VARIABLE, IF
    };
    struct member {
        types type;
        size_t assign_next_rules = 0;
        std::any value = {};
    };
    class ir {
        public:
        arr_t<member> elements;
        void add(ir repr);
        void push(member member);
    };

};
IR::ir ruleToIr(Parser::Rule rule_rule);
IR::ir rulesToIr(arr_t<Parser::Rule> rules);
IR::ir treeToIr(Parser::Tree &tree);