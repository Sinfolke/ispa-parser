#pragma once
#include <parser.h>
#include <any>
#include <list>
#include <algorithm>
#include <stack>
class IR {
    public:
        enum class types {
            NONE, RULE, TOKEN, RULE_END, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
            METHOD_CALL, FUNCTION_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
            ASSIGN_VARIABLE, INCREASE_POS_COUNTER, INCREASE_POS_COUNTER_BY_TOKEN_LENGTH, RESET_POS_COUNTER, 
            SKIP_SPACES, DATA_BLOCK, PUSH_POS_COUNTER, POP_POS_COUNTER, INSIDE_LOOP
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
            var_types type = IR::var_types::UNDEFINED;
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
            IR::variable value;
        };
        using inclosed_map = std::unordered_map<std::string, std::pair<std::vector<IR::expr>, var_type>>;
        struct data_block {
            assign value;
            IR::var_type assign_type;
            bool is_inclosed_map;
        };
        struct node_ret_t {
            IR::variable svar;
            IR::variable var;
            IR::variable shadow_var = {};
            char qualifier;
        };
        struct var_group {
            IR::variable var;
            size_t begin;
            size_t end;
        };
    private:
        void clear_thread();
        // output functions:
        std::string generateVariableName();
        std::string convert_var_type(var_types type);
        std::string convert_var_assing_values(var_assign_values value, std::any data, std::stack<std::string> &current_pos_counter);
        std::string convert_var_assing_types(var_assign_types type);
        std::string conditionTypesToString(condition_types type, std::any data, std::stack<std::string> &current_pos_counter);
        std::string convertFunctionCall(function_call call, std::stack<std::string> &current_pos_counter);
        std::string convertAssign(assign asgn, std::stack<std::string> &current_pos_counter);
        std::string convertAccessor(accessor acc, std::stack<std::string> &current_pos_counter);
        void convertVariable(variable var, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
        std::string convertExpression(std::vector<expr> expression, bool with_braces, std::stack<std::string> &current_pos_counter);
        void convertBlock(std::vector<IR::member> block, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
        void convertCondition(condition cond, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
        void convertAssignVariable(variable_assign var, std::ostream &out, int &indentLevel, std::stack<std::string> &current_pos_counter);
        std::string convertMethodCall(method_call method, std::stack<std::string> &current_pos_counter);
        std::string convertDataBlock(data_block dtb, int indentLevel, std::stack<std::string> &current_pos_counter);
        void convertMember(const member& mem, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
        void convertMembers(std::vector<member> members, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
        void convertMembers(std::deque<member> members, std::ostream& out, int &indentLevel, std::stack<std::string> &current_pos_counter);
        void printIR(std::ostream& out, int &indentLevel);
        // other functions
        std::string getErrorName(Parser::Rule rule);
        IR::variable createSuccessVariable();
        bool compare_templ(const std::vector<IR::var_type>& templ1, const std::vector<IR::var_type>& templ2);
        bool compare_types(std::list<IR::var_type> types);
        IR::variable getElementbyAccessor(IR::accessor &accessor, bool is_match_rule);
        void inlineExprAccessor(IR::assign &data);
        void inlineExprAccessor(std::vector<IR::expr> &expr);
        void inlineAccessors(std::vector<IR::member> &values);
        IR::var_type deduceTypeFromAnyData(const Parser::Rule &value);
        IR::var_type deduceTypeFromExpr(const Parser::Rule &expr);
        IR::data_block TreeDataBlockToIR(const Parser::Rule &rule);
        IR::var_type deduceVarTypeByValue(Parser::Rule mem);
        // convertion functions helpers
        void addPostLoopCheck(const IR::variable &var);
        void handle_plus_qualifier(IR::condition loop);
        IR::member createDefaultCall(std::vector<IR::member> &block, IR::variable var, const std::string &name, std::vector<IR::expr> &expr);
        IR::variable add_shadow_variable(std::vector<IR::member> &block, const IR::variable &var);
        IR::variable pushBasedOnQualifier(std::vector<IR::expr> &expr, std::vector<IR::member> &block, const IR::variable &var, const IR::variable &svar, bool add_shadow_var = true);
        IR::variable pushBasedOnQualifier_Rule_other(std::vector<IR::expr> &expr, std::vector<IR::member> &block, const IR::variable &var, const IR::variable &svar, const IR::member &call, bool add_shadow_var = false);
        IR::variable affectIrByQuantifier(const IR::variable &var);
        IR::assign TreeAnyDataToIR(const Parser::Rule &value);
        IR::function_call TreeFunctionToIR(const Parser::Rule &rule);
        IR::method_call TreeMethodCallToIR(const Parser::Rule &rule);
        IR::var_type cllTreeCsupportTypeToIR(const Parser::Rule &rule);
        IR::var_type cllTreeTypeToIR(const Parser::Rule &rule);
        IR::var_type cllTreeAbstactTypeToIR(const Parser::Rule &rule);
        IR::var_assign_types TreeOpToIR(const Parser::Rule &rule);
        IR::expr TreeOpToExpr(const Parser::Rule &rule);
        IR::expr TreeCompareOpToExpr(const Parser::Rule &rule);
        IR::expr TreeLogicalOpToIR(const Parser::Rule &rule);
        IR::var_assign_types TreeAssignmentOpToIR(const Parser::Rule &rule);
        IR::var_assign_types TreeOperatorsToIR(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprGroupToIR(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprArithmetic_forToIR(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprArithmeticToIR(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprCompareToIR_unit(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprCompareToIR(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprLogicalUnitToIR(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprLogicalToIR(const Parser::Rule &rule);
        std::vector<IR::expr> TreeExprToIR(const Parser::Rule &expr);
        std::vector<IR::member> convert_op_rule(std::vector<Parser::Rule> &rules, size_t index, IR::variable &var, IR::variable &svar);
        void process_cll_var(const Parser::Rule &rule);
        IR::condition process_cll_cond(const Parser::Rule &rule);
        // main convertion functions
        IR::node_ret_t processGroup(Parser::Rule rule);
        IR::node_ret_t processRuleCsequence(const Parser::Rule &rule);
        IR::node_ret_t processString(const Parser::Rule &rule);
        IR::node_ret_t process_Rule_hex(const Parser::Rule &rule);
        IR::node_ret_t process_Rule_bin(const Parser::Rule &rule);
        IR::node_ret_t processAccessor(const Parser::Rule &rule);
        IR::node_ret_t process_Rule_other(const Parser::Rule &rule);
        IR::node_ret_t process_Rule_escaped(const Parser::Rule &rule);
        IR::node_ret_t process_Rule_any(const Parser::Rule &rule);
        IR::node_ret_t process_Rule_op(const Parser::Rule &rule);
        IR::node_ret_t process_cll(const Parser::Rule &rule);
    protected:
        // data
        size_t variable_count = 0;
        bool isToken;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        char qualifier_char = '\0';
        std::vector<std::string> fullname;
        std::vector<IR::variable> elements;
        std::vector<var_group> groups;
        std::vector<IR::variable> vars;
        std::vector<IR::member> data;
        std::vector<node_ret_t> success_vars;
        const std::vector<Parser::Rule>* rules;
        Parser::Tree* tree;
        // helper functions
        void erase_begin();
        // convertion
        void ruleToIr(Parser::Rule &rule_rule, char custom_qualifier = -1);
        IR rulesToIr(std::vector<Parser::Rule> rules);
        IR treeToIr(Parser::Tree &tree, std::string nested_name, std::vector<std::string> &fullname_arr);
        void treeToIr(Parser::Tree &tree);
        // optimizations
        void getVariablesToTable(std::vector<IR::member> &data, size_t &i, std::list<IR::member>& table);
        size_t getBegin(size_t& i);
        void insertVariablesOnTop(std::list<IR::member>& table, size_t begin);
        void raiseVarsTop();
    public:
        IR(Parser::Tree &tree) : tree(&tree), rules(nullptr) {}
        IR(Parser::Tree *&tree) : tree(tree), rules(nullptr) {}
        IR(Parser::Tree &tree, const std::vector<Parser::Rule> &rules) : tree(&tree), rules(&rules) {}
        IR(Parser::Tree *&tree, const std::vector<Parser::Rule> &rules) : tree(tree), rules(&rules) {}
        IR(IR &ir) : tree(ir.tree), rules(nullptr), data(ir.data) {}
        IR& operator=(const IR&) = default;
        IR& operator=(IR&&) = default;
        ~IR() = default;
        // get functions
        auto getData() const -> const std::vector<IR::member>&;
        auto getDataRef() -> std::vector<IR::member>&;
        auto makeIR() -> std::vector<node_ret_t>;
        void optimizeIR();
        void outputIRToFile(std::string filename);
        void outputIRToConsole();
        void add(IR &repr);
        void add(std::vector<member> repr);
        void push(member member);
        void push_begin(member member);
        void proceed(IR& ir);
        void update(IR& ir);
        void pop_begin();
        void pop();
        size_t size();
        bool empty();
};
