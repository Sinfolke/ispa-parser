#pragma once
#include <parser.h>
#include <any>
#include <list>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <any>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <utility>
class LLIR {
    public:
        enum class types {
            NONE, RULE, TOKEN, RULE_END, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
            METHOD_CALL, FUNCTION_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
            ASSIGN_VARIABLE, INCREASE_POS_COUNTER, INCREASE_POS_COUNTER_BY_TOKEN_LENGTH, RESET_POS_COUNTER, 
            SKIP_SPACES, DATA_BLOCK, PUSH_POS_COUNTER, POP_POS_COUNTER, INSIDE_LOOP, ERR
        };
        enum class condition_types {
            GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
            HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
            LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND, BITWISE_OR, BITWISE_ANDR,
            ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO,  
            CHARACTER, CURRENT_CHARACTER, CURRENT_TOKEN, NUMBER, HEX, BIN, STRING, STRNCMP, STRNCMP_PREV,
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
            var_types type = LLIR::var_types::UNDEFINED;
            std::vector<var_type> templ = {};
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
            std::vector<assign> params;
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
            std::vector<expr> expression;
            std::vector<member> block;
            std::vector<member> else_block = {}; 
        };

        struct variable {
            std::string name = "";
            var_type type = {var_types::UNDEFINED};
            assign value = {var_assign_values::NONE};
            std::vector<std::string> property_access = {};
        };
        struct variable_assign {
            std::string name;
            var_assign_types assign_type = var_assign_types::ASSIGN;
            assign value = {var_assign_values::NONE};
        };
        struct accessor {
            std::vector<Parser::Rule> elements;
            char qualifier;
        };
        struct strncmp {
            bool is_string;
            LLIR::variable value;
        };
        using inclosed_map = std::unordered_map<std::string, std::pair<std::vector<LLIR::expr>, var_type>>;
        struct data_block {
            assign value;
            LLIR::var_type assign_type;
            bool is_inclosed_map;
        };
        struct node_ret_t {
            LLIR::variable svar;
            LLIR::variable var;
            LLIR::variable shadow_var = {};
            char qualifier;
        };
        struct var_group {
            LLIR::variable var;
            size_t begin;
            size_t end;
        };
    private:
        void clear_thread();
        // output functions:
        std::string generateVariableName();
        std::string convert_var_type(var_types type);
        std::string convert_var_assing_values(var_assign_values value, std::any data);
        std::string convert_var_assing_types(var_assign_types type);
        std::string conditionTypesToString(condition_types type, std::any data);
        std::string convertFunctionCall(function_call call);
        std::string convertAssign(assign asgn);
        std::string convertAccessor(accessor acc);
        void convertVariable(variable var, std::ostream& out);
        std::string convertExpression(std::vector<expr> expression, bool with_braces);
        void convertBlock(std::vector<LLIR::member> block, std::ostream& out);
        void convertCondition(condition cond, std::ostream& out);
        void convertAssignVariable(variable_assign var, std::ostream &out);
        std::string convertMethodCall(method_call method);
        std::string convertDataBlock(data_block dtb);
        void convertMember(const member& mem, std::ostream& out);
        void convertMembers(std::vector<member> members, std::ostream& out);
        void convertMembers(std::deque<member> members, std::ostream& out);
        void printIR(std::ostream& out);
        // other functions
        std::string getErrorName(Parser::Rule rule);
        LLIR::variable createSuccessVariable();
        bool compare_templ(const std::vector<LLIR::var_type>& templ1, const std::vector<LLIR::var_type>& templ2);
        bool compare_types(std::list<LLIR::var_type> types);
        LLIR::variable getElementbyAccessor(LLIR::accessor &accessor, bool is_match_rule);
        void inlineExprAccessor(LLIR::assign &data);
        void inlineExprAccessor(std::vector<LLIR::expr> &expr);
        void inlineAccessors(std::vector<LLIR::member> &values);
        LLIR::var_type deduceTypeFromAnyData(const Parser::Rule &value);
        LLIR::var_type deduceTypeFromExpr(const Parser::Rule &expr);
        LLIR::data_block TreeDataBlockToIR(const Parser::Rule &rule);
        LLIR::var_type deduceVarTypeByValue(Parser::Rule mem);
        // convertion functions helpers
        void addPostLoopCheck(const Parser::Rule &rule, const LLIR::variable &var, bool addError = true);
        void handle_plus_qualifier(const Parser::Rule &rule, LLIR::condition loop, bool addError = true);
        LLIR::member createDefaultCall(std::vector<LLIR::member> &block, LLIR::variable var, const std::string &name, std::vector<LLIR::expr> &expr);
        LLIR::variable add_shadow_variable(std::vector<LLIR::member> &block, const LLIR::variable &var);
        LLIR::variable pushBasedOnQualifier(const Parser::Rule &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, char quantifier, bool add_shadow_var = true);
        LLIR::variable pushBasedOnQualifier_Rule_other(const Parser::Rule &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, const LLIR::member &call, char quantifier, bool add_shadow_var = false);
        LLIR::variable affectIrByQuantifier(const Parser::Rule &rule, const LLIR::variable &var, char quantifier);
        LLIR::assign TreeAnyDataToIR(const Parser::Rule &value);
        LLIR::function_call TreeFunctionToIR(const Parser::Rule &rule);
        LLIR::method_call TreeMethodCallToIR(const Parser::Rule &rule);
        LLIR::var_type cllTreeCsupportTypeToIR(const Parser::Rule &rule);
        LLIR::var_type cllTreeTypeToIR(const Parser::Rule &rule);
        LLIR::var_type cllTreeAbstactTypeToIR(const Parser::Rule &rule);
        LLIR::var_assign_types TreeOpToIR(const Parser::Rule &rule);
        LLIR::expr TreeOpToExpr(const Parser::Rule &rule);
        LLIR::expr TreeCompareOpToExpr(const Parser::Rule &rule);
        LLIR::expr TreeLogicalOpToIR(const Parser::Rule &rule);
        LLIR::var_assign_types TreeAssignmentOpToIR(const Parser::Rule &rule);
        LLIR::var_assign_types TreeOperatorsToIR(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprGroupToIR(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprArithmetic_forToIR(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprArithmeticToIR(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprCompareToIR_unit(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprCompareToIR(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprLogicalUnitToIR(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprLogicalToIR(const Parser::Rule &rule);
        std::vector<LLIR::expr> TreeExprToIR(const Parser::Rule &expr);
        std::vector<LLIR::member> convert_op_rule(std::vector<Parser::Rule> &rules, size_t index, LLIR::variable &var, LLIR::variable &svar);
        void process_cll_var(const Parser::Rule &rule);
        LLIR::condition process_cll_cond(const Parser::Rule &rule);
        // main convertion functions
        LLIR::node_ret_t processGroup(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t processRuleCsequence(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t processString(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t process_Rule_hex(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t process_Rule_bin(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t processAccessor(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t process_Rule_other(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t process_Rule_escaped(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t process_Rule_any(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t process_Rule_op(const Parser::Rule &rule, char quantifier);
        LLIR::node_ret_t process_cll(const Parser::Rule &rule);
    protected:
        // data
        size_t variable_count = 0;
        bool isToken;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        std::vector<std::string> fullname;
        std::vector<LLIR::variable> elements;
        std::vector<var_group> groups;
        std::vector<LLIR::variable> vars;
        std::vector<LLIR::member> data;
        std::vector<node_ret_t> success_vars;
        const std::vector<Parser::Rule>* rules = nullptr;
        const Parser::Tree* tree;
        // data for output
        std::stack<std::string> current_pos_counter;
        size_t indentLevel = 0;
        // helper functions
        void erase_begin();
        // convertion
        void ruleToIr(const Parser::Rule &rule_rule, char custom_qualifier = -1);
        auto rulesToIr(const std::vector<Parser::Rule> &rules) -> LLIR;
        void treeToIr(const Parser::Tree &tree);
        // optimizations
        void getVariablesToTable(std::vector<LLIR::member> &data, size_t &i, std::list<LLIR::member>& table);
        size_t getBegin(size_t& i);
        void insertVariablesOnTop(std::list<LLIR::member>& table, size_t begin);
        void raiseVarsTop();
    public:
        LLIR(const Parser::Tree &tree);
        LLIR(const Parser::Tree *tree);
        LLIR(const Parser::Tree &tree, const std::vector<Parser::Rule>& rules);
        LLIR(const Parser::Tree *tree, const std::vector<Parser::Rule>& rules);
        LLIR(LLIR& ir);

        // get functions
        auto getData() const -> const std::vector<LLIR::member>&;
        auto getDataRef() -> std::vector<LLIR::member>&;
        auto getTree() -> const Parser::Tree*;
        auto makeIR() -> std::vector<node_ret_t>;
        void optimizeIR();
        virtual void outputIRToFile(std::string filename);
        virtual void outputIRToConsole();
        void add(LLIR &repr);
        void add(std::vector<member> repr);
        void push(member member);
        void push_begin(member member);
        void proceed(LLIR& ir);
        void update(LLIR& ir);
        void pop_begin();
        void pop();
        size_t size();
        bool empty();
        void setIsToken(bool isToken);
};
