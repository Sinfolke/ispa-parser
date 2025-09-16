export module AST.Builder;
import AST.types;
import AST.API;
import AST.Tree;
import Parser;
import dstd;
import hash;
import std;
export namespace AST {
    class Builder {
    private:
        TreeMap tree_map;
        SpacemodeStates spacemode = SpacemodeStates::MIXED;
        std::string name;
        Use use;
        const stdu::vector<Parser::Rule> *modules = nullptr;
        const Parser::Rule *md = nullptr;
        bool isModule = true;
        bool isModuleConstructor = false;
        void constructor(const stdu::vector<Parser::Rule> &modules);
        void constructor(const Parser::Rule &mod);
    protected:
        // convertion functions & variables
        stdu::vector<AST::RuleMember> newRules;
        bool in_op = false;
        bool prev_op = false;
        bool add_prev = false;
        stdu::vector<std::string> fullname;
        stdu::vector<std::pair<std::string, stdu::vector<std::string>>> nested_rule_names;
        AST::RulePrefix ops_prefix;
        stdu::vector<AST::RuleMember> ops;
        AST::Array createArray(const Parser::Rule &array);
        AST::Object createObject(const Parser::Rule &object);
        AST::String createString(const Parser::Token &token);
        AST::Number createNumber(const Parser::Token &number);
        AST::Boolean createBoolean(const Parser::Token boolean);
        AST::rvalue createRvalue(const Parser::Rule &rule);
        AST::CllFunctionArguments createCllFunctionArguments(const Parser::Rule &rule);
        AST::CllFunctionCall createCllFunctionCall(const Parser::Rule &rule);
        AST::CllVariableMention createCllVariable(const Parser::Rule &rule);
        AST::CllCompareOp createCllCompareOp(const Parser::Token &token);
        AST::CllLogicalOp createCllLogicalOp(const Parser::Token &token);
        AST::CllExprValue createCllExprValue(const Parser::Rule &value);
        AST::CllExprTerm createCllExprTerm(const Parser::Rule &term);
        AST::CllExprAddition createCllExprAddition(const Parser::Rule &addition);
        AST::CllExprCompare createCllExprCompare(const Parser::Rule &compare);
        AST::CllExprLogical createCllExprLogical(const Parser::Rule &logical);
        AST::CllExpr createCllExpr(const Parser::Rule &expr);
        AST::CllIf createCllIf(const Parser::Rule &cond);
        AST::CllType createCllType(const Parser::Token &rule);
        AST::CllVar createCllVar(const Parser::Rule &var);
        AST::Cll convertCll(const Parser::Rule &cll);
        void createRuleMember(const Parser::Rule &rule);
        void createRuleMembers(const stdu::vector<Parser::Rule> &rules);
        AST::DataBlock createDataBlock(const Parser::Rule &rule);

        // helper
        void getNestedRuleNames(const Parser::Types::rule &rule);
        void flushOpSequence();
        // build Tree API from AST
        void createRules(const Parser::Types::rule &rule);
        void build(const Parser::Rule &mod);
        void build(const stdu::vector<Parser::Rule> &modules);
        Builder(const stdu::vector<Parser::Rule> &modules, const stdu::vector<std::pair<std::string, stdu::vector<std::string>>> &nested_rule_names, bool isModule) :
            modules(&modules), nested_rule_names(nested_rule_names), isModule(isModule), isModuleConstructor(true) {}
    public:
        Builder(const stdu::vector<Parser::Rule> &modules) : modules(&modules) {}
        Builder(const Parser::Rule &mod) : md(&mod) {}
        ~Builder() = default;
        void build();
        auto get() -> Tree { return {std::move(name), std::move(spacemode), std::move(use), std::move(tree_map)}; }
    };
}