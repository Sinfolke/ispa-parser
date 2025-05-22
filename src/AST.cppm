export module AST;
import TreeAPI;
import corelib;
import LLIR;
import Parser;
import hash;
import std;
/*
    class to perfrom native pass through AST and convert into TreeAPI
*/
export class AST {
    public:
        enum class SpacemodeStates {
            MIXED, MANUAL, SKIPPED 
        };
        using TreeMap = utype::unordered_map<std::vector<std::string>, TreeAPI::Rule>;
        using Use = utype::unordered_map<std::string, TreeAPI::rvalue>;
        using UsePlaceTable = utype::unordered_map<std::vector<std::string>, std::vector<std::vector<std::string>>>;
        using First = utype::unordered_map<std::vector<std::string>, std::set<std::vector<std::string>>>;
        using Follow = First;
        using lexer_code = std::pair<LLIR::Nodes, LLIR::variable>;
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

        UsePlaceTable use_places;
        First first;
        Follow follow;
        utype::unordered_map<std::vector<std::string>, bool> nullable;
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
        AST(const std::vector<Parser::Rule> &modules, const std::vector<std::pair<std::string, std::vector<std::string>>> &nested_rule_names, bool isModule) {
            this->nested_rule_names = nested_rule_names;
            if (isModule)
                constructor(modules);
            else {
                createRuleMembers(modules);
            }
        }
        auto getRules() -> std::vector<TreeAPI::RuleMember>&;
        void getUsePlacesTable(const std::vector<TreeAPI::RuleMember> &members, const std::vector<std::string> &name);
        void constructNullableSet();
        auto constructFirstSet(const std::vector<TreeAPI::RuleMember>& members, const std::vector<std::string> &nonterminal) -> utype::unordered_set<std::vector<std::string>>;
        void constructFirstSet();
        void constructFollowSet();
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
        auto getTerminals() -> std::vector<std::vector<std::string>>;
        auto getNonTerminals() -> std::vector<std::vector<std::string>>;
        auto getUsePlacesTable() -> UsePlaceTable&;
        auto createUsePlacesTable() -> UsePlaceTable&;
        auto getCodeForLexer() -> lexer_code;
        auto getFirstSet()-> First&;
        auto getFollowSet() -> Follow&;
};