module;
#include <vector>
#include <string>
#include <unordered_map>
#include <Parser.h>
export module AST;
import TreeAPI;
import Parser;
/*
    class to perfrom native pass through AST and convert into TreeAPI
*/
export class AST {
    public:        
        enum class SpacemodeStates {
            MIXED, MANUAL, SKIPPED 
        };
        using TreeMap = std::unordered_map<std::vector<std::string>, TreeAPI::Rule>;
        using Use = std::unordered_map<std::string, TreeAPI::rvalue>;
    private:
        TreeMap tree_map;
        Use use;
        std::string name;
        SpacemodeStates spacemode = SpacemodeStates::MIXED;
        void constructor(const std::vector<Parser::Rule> &modules);
        void constructor(const Parser::Rule &mod);
    
    protected:
        // convertion functions & variables
        std::vector<TreeAPI::RuleMember> newRules;
        bool in_op;
        bool prev_op;
        bool add_prev;
        std::vector<std::string> fullname;
        std::vector<std::pair<std::string, std::vector<std::string>>> nested_rule_names;
        TreeAPI::RulePrefix ops_prefix;
        std::vector<TreeAPI::RuleMember> ops;

        TreeAPI::Array createArray(const Parser::Rule &array);
        TreeAPI::Object createObject(const Parser::Rule &object);
        TreeAPI::String createString(const Parser::Token &token);
        TreeAPI::Number createNumber(const Parser::Token &number);
        TreeAPI::Boolean createBoolean(const Parser::Token boolean);
        TreeAPI::rvalue createRvalue(const Parser::Rule &rule);
        TreeAPI::CllFunctionArguments createCllFunctionArguments(const Parser::Rule &rule);
        TreeAPI::CllFunctionCall createCllFunctionCall(const Parser::Rule &rule);
        TreeAPI::CllVariable createCllVariable(const Parser::Rule &rule);
        TreeAPI::CllCompareOp createCllCompareOp(const Parser::Token &token);
        TreeAPI::CllLogicalOp createCllLogicalOp(const Parser::Token &token);
        TreeAPI::CllExprValue createCllExprValue(const Parser::Rule &value);
        TreeAPI::CllExprTerm createCllExprTerm(const Parser::Rule &term);
        TreeAPI::CllExprAddition createCllExprAddition(const Parser::Rule &addition);
        TreeAPI::CllExprCompare createCllExprCompare(const Parser::Rule &compare);
        TreeAPI::CllExprLogical createCllExprLogical(const Parser::Rule &logical);
        TreeAPI::CllExpr createCllExpr(const Parser::Rule &expr);
        TreeAPI::CllIf createCllIf(const Parser::Rule &cond);
        TreeAPI::CllType createCllType(const Parser::Token &rule);
        TreeAPI::CllVar createCllVar(const Parser::Rule &var);
        TreeAPI::Cll convertCll(const Parser::Rule &cll);
        void createRuleMember(const Parser::Rule &rule);
        void createRuleMembers(const std::vector<Parser::Rule> &rules);
        TreeAPI::DataBlock createDataBlock(const Parser::Rule &rule);

        // helper
        void getNestedRuleNames(const Parser::Types::rule &rule);
        void flushOpSequence();
        // build Tree API from AST
        void createRules(const Parser::Types::rule &rule);
        AST(const std::vector<Parser::Rule> &modules, const  std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names, bool isModule) {
            this->nested_rule_names = nested_rule_names;
            if (isModule)
                constructor(modules);
            else {
                createRuleMembers(modules);
            }
        }
        std::vector<TreeAPI::RuleMember> &getRules();
    public:
        TreeMap &getTreeMap();
        Use &getUse();
        std::string &getName();
        SpacemodeStates &getSpacemode();
        AST(const std::vector<Parser::Rule> &modules) {
            constructor(modules);\
        }
        AST(const Parser::Rule &mod) {
            constructor(mod);
        }
};