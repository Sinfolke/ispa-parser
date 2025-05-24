export module AST;
import TreeAPI;
import corelib;
import LLIR;
import Parser;
import hash;
import types;
import std;
import std.compat;
/*
    class to perfrom native pass through AST and convert into TreeAPI
*/
export class AST {
    public:
        enum class SpacemodeStates {
            MIXED, MANUAL, SKIPPED 
        };
        using TreeMap = utype::unordered_map<vector<std::string>, TreeAPI::Rule>;
        using Use = utype::unordered_map<std::string, TreeAPI::rvalue>;
        using UsePlaceTable = utype::unordered_map<vector<std::string>, vector<vector<std::string>>>;
        using First = utype::unordered_map<vector<std::string>, std::set<vector<std::string>>>;
        using Follow = First;
        using lexer_code = std::pair<LLIR::Nodes, LLIR::variable>;
        using InitialItemSet = utype::unordered_map<vector<std::string>, vector<TreeAPI::Rule>>;
    private:
        TreeMap tree_map;
        InitialItemSet initial_item_set;
        Use use;
        std::string name;
        SpacemodeStates spacemode = SpacemodeStates::MIXED;
        void constructor(const vector<Parser::Rule> &modules);
        void constructor(const Parser::Rule &mod);
    
    protected:
        // convertion functions & variables
        vector<TreeAPI::RuleMember> newRules;
        bool in_op;
        bool prev_op;
        bool add_prev;
        vector<std::string> fullname;
        vector<std::pair<std::string, vector<std::string>>> nested_rule_names;
        TreeAPI::RulePrefix ops_prefix;
        vector<TreeAPI::RuleMember> ops;

        UsePlaceTable use_places;
        First first;
        Follow follow;
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
        void createRuleMembers(const vector<Parser::Rule> &rules);
        TreeAPI::DataBlock createDataBlock(const Parser::Rule &rule);

        // helper
        void getNestedRuleNames(const Parser::Types::rule &rule);
        void flushOpSequence();
        // build Tree API from AST
        void createRules(const Parser::Types::rule &rule);
        AST(const vector<Parser::Rule> &modules, const vector<std::pair<std::string, vector<std::string>>> &nested_rule_names, bool isModule) {
            this->nested_rule_names = nested_rule_names;
            if (isModule)
                constructor(modules);
            else {
                createRuleMembers(modules);
            }
        }
        static auto compute_group_length(const vector<TreeAPI::RuleMember> &group) -> size_t;
        auto getRules() -> vector<TreeAPI::RuleMember>&;
        void getUsePlacesTable(const vector<TreeAPI::RuleMember> &members, const vector<std::string> &name);
        void transform_helper(
            vector<TreeAPI::RuleMember> &members,
            const vector<std::string> &fullname,
            utype::unordered_map<vector<std::string>,
            std::pair<char, vector<std::string>>> &replacements
        );
        void transform();
        void createInitialItemSet();
        auto createUsePlacesTable() -> UsePlaceTable&;
        void constructFirstSet(const vector<TreeAPI::Rule>& options, const vector<std::string> &nonterminal, bool &changed);
        void constructFirstSet();
        void constructFollowSet();
        void formatFirstOrFollowSet(std::ostringstream &oss, AST::First &set);
    public:
        TreeMap &getTreeMap();
        Use &getUse();
        std::string &getName();
        SpacemodeStates &getSpacemode();

        AST(const vector<Parser::Rule> &modules) {
            constructor(modules);
        }
        AST(const Parser::Rule &mod) {
            constructor(mod);
        }
        auto getTerminals() -> vector<vector<std::string>>;
        auto getNonTerminals() -> vector<vector<std::string>>;
        auto getUsePlacesTable() -> UsePlaceTable&;
        auto getCodeForLexer() -> lexer_code;
        auto getFirstSet()-> First&;
        auto getFollowSet() -> Follow&;
        auto getRawFirstSet()-> First&;
        auto getRawFollowSet() -> Follow&;
        auto getInitialItemSet() -> InitialItemSet&;

        void printFirstSet(const std::string &fileName);
        void printFollowSet(const std::string &fileName);
};