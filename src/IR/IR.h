#pragma once
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
#include <TreeAPI.h>
#include <hash.h>
class Tree;
class LLIR {
    public:
        enum class types {
            NONE, RULE, TOKEN, RULE_END, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
            METHOD_CALL, FUNCTION_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
            ASSIGN_VARIABLE, INCREASE_POS_COUNTER, INCREASE_POS_COUNTER_BY_TOKEN_LENGTH, RESET_POS_COUNTER, 
            SKIP_SPACES, DATA_BLOCK, PUSH_POS_COUNTER, POP_POS_COUNTER, INSIDE_LOOP, ERR, EMPTY
        };
        enum class condition_types {
            GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL, 
            HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
            LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND, BITWISE_OR, BITWISE_ANDR,
            ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO,  
            CHARACTER, CURRENT_CHARACTER, CURRENT_TOKEN, TOKEN_SEQUENCE, NUMBER, HEX, BIN, STRING, STRNCMP, STRNCMP_PREV,
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
            std::size_t operator()(const std::vector<std::string>& key) const {
                std::size_t h = 0;
                std::hash<std::string> hasher;
                for (const auto& s : key) {
                    h ^= hasher(s) + 0x9e3779b9 + (h << 6) + (h >> 2);
                }
                return h;
            }
        };
        struct member {
            types type = types::NONE;
            std::any value = {};
        };
        struct assign {
            var_assign_values kind;
            std::any data;
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
        struct expr {
            condition_types id;
            std::any value = {};
        };
        using array = std::vector<std::vector<expr>>;
        using object = std::unordered_map<std::string, std::vector<expr>>;
        struct function_call {
            std::string name;
            std::vector<std::vector<expr>> params;
        };
        struct method_call {
            std::string var_name;
            std::vector<function_call> calls;
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
        struct strncmp {
            bool is_string;
            LLIR::variable value;
        };
        using inclosed_map = std::unordered_map<std::string, std::pair<std::vector<LLIR::expr>, var_type>>;
        using regular_data_block = std::pair<std::vector<LLIR::expr>, var_type>;
        struct data_block {
            std::variant<std::monostate, regular_data_block, inclosed_map> value;
            bool is_inclosed_map() const;
            bool is_raw_expr() const;
            regular_data_block &getExpr();
            inclosed_map &getInclosedMap();
            const regular_data_block &getExpr() const;
            const inclosed_map &getInclosedMap() const;
        };
        struct ConvertionResult {
            LLIR::variable svar;
            LLIR::variable uvar;
            LLIR::variable var;
            LLIR::variable shadow_var;
            char qualifier;
        };
        struct var_group {
            LLIR::variable var;
            size_t begin;
            size_t end;
        };
        using DataBlockList = std::unordered_map<std::vector<std::string>, LLIR::data_block, LLIR::var_type>;
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

        // helper functions
        auto createEmptyVariable(std::string name) -> LLIR::variable;
        auto processExitStatements(std::vector<LLIR::member> &values) -> void;
        auto createSuccessVariable() -> LLIR::variable;
        auto addPostLoopCheck(const TreeAPI::RuleMember &rule, const LLIR::variable &var, bool addError = true) -> void;
        auto handle_plus_qualifier(const TreeAPI::RuleMember &rule, LLIR::condition loop, bool addError = true) -> void;
        auto replaceToPrevChar(std::vector<LLIR::member> &elements, int i) -> void;
        auto createDefaultBlock(const LLIR::variable &var, const LLIR::variable &svar) -> std::vector<LLIR::member>;
        auto createDefaultBlock(const LLIR::variable &svar) -> std::vector<LLIR::member>;
        auto createDefaultBlock() -> std::vector<LLIR::member>;
        auto getEscapedChar(char in) -> char;
        auto createDefaultCall(std::vector<LLIR::member> &block, LLIR::variable var, const std::string &name, std::vector<LLIR::expr> &expr) -> LLIR::member;
        auto add_shadow_variable(std::vector<LLIR::member> &block, const LLIR::variable &var) -> LLIR::variable;
        auto pushBasedOnQualifier(const TreeAPI::RuleMember &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, char quantifier, bool add_shadow_var = true) -> LLIR::variable;
        auto pushBasedOnQualifier_Rule_name(const TreeAPI::RuleMember &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, const LLIR::member &call, char quantifier, bool add_shadow_var = false) -> LLIR::variable;
        auto affectIrByQuantifier(const TreeAPI::RuleMember &rule, const LLIR::variable &var, char quantifier) -> LLIR::variable;
        auto compare_templ(const std::vector<LLIR::var_type>& templ1, const std::vector<LLIR::var_type>& templ2) -> bool;
        
        // Error functions
        std::string getErrorName(const TreeAPI::RuleMember &rule);

        // Convertion functions
        auto TreeRvalueToIR(const TreeAPI::rvalue &value) -> LLIR::assign;
        auto TreeFunctionBodyCallToIR(const TreeAPI::CllFunctionBodyCall &body) -> std::vector<std::vector<LLIR::expr>>;
        auto TreeFunctionToIR(const TreeAPI::CllFunctionCall &call) -> LLIR::function_call;
        auto TreeMethodCallToIR(const TreeAPI::CllMethodCall &method) -> LLIR::method_call;
        auto cllTreeTypeToIR(const TreeAPI::CllType &type) -> LLIR::var_type;
        auto TreeOpToIR(const char op) -> LLIR::var_assign_types;
        auto TreeOpToExpr(const char op) -> LLIR::expr;
        auto TreeCompareOpToExpr(const TreeAPI::CllCompareOp &op) -> LLIR::expr;
        auto TreeLogicalOpToIR(const TreeAPI::CllLogicalOp &lop) -> LLIR::expr;
        auto TreeAssignmentOpToIR(const char op) -> LLIR::var_assign_types;
        auto TreeExprGroupToIR(const TreeAPI::CllExpr &group) -> std::vector<LLIR::expr>;
        auto TreeExprValueToIR(const TreeAPI::CllExprValue &value) -> std::vector<LLIR::expr>;
        auto TreeExprTermToIR(const TreeAPI::CllExprTerm &term) -> std::vector<LLIR::expr>;
        auto TreeExprAdditionToIR(const TreeAPI::CllExprAddition &addition) -> std::vector<LLIR::expr>;
        auto TreeExprCompareToIR(const TreeAPI::CllExprCompare &compare) -> std::vector<LLIR::expr>;
        auto TreeExprLogicalToIR(const TreeAPI::CllExprLogical &logical) -> std::vector<LLIR::expr>;
        auto TreeExprToIR(const TreeAPI::CllExpr &expr) -> std::vector<LLIR::expr>;
        
        // deduce type functions
        auto deduceVarTypeByProd(const TreeAPI::RuleMember &mem) -> LLIR::var_type;
        auto deduceTypeFromRvalue(const TreeAPI::rvalue &value) -> LLIR::var_type;
        auto deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) -> LLIR::var_type;
        auto deduceTypeFromTerm(const TreeAPI::CllExprTerm &term) -> LLIR::var_type;
        auto deduceTypeFromAddition(const TreeAPI::CllExprAddition &addition) -> LLIR::var_type;
        auto deduceTypeFromCompare(const TreeAPI::CllExprCompare &compare) -> LLIR::var_type;
        auto deduceTypeFromLogical(const TreeAPI::CllExprLogical &logical) -> LLIR::var_type;
        auto deduceTypeFromExpr(const TreeAPI::CllExpr &expr) -> LLIR::var_type;
        
        // convertion functions helpers
        auto processGroup(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto processRuleCsequence(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto processString(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto process_Rule_hex(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto process_Rule_bin(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto process_Rule_name(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto process_Rule_nospace(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto process_Rule_escaped(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto process_Rule_any(const TreeAPI::RulePrefix &prefix) -> LLIR::ConvertionResult;
        auto convert_op_rule(const std::vector<TreeAPI::RuleMember> &rules, size_t index, LLIR::variable &var, LLIR::variable &svar) -> std::vector<LLIR::member>;
        auto process_Rule_op(const TreeAPI::RuleMember &rule) -> LLIR::ConvertionResult;
        auto process_cll_var(const TreeAPI::CllVar &var) -> void;
        auto process_cll_if(const TreeAPI::CllIf &cond) -> LLIR::condition;
        auto process_cll(const TreeAPI::Cll &cll) -> LLIR::ConvertionResult;
        auto createDataBlock(const TreeAPI::DataBlock &data_block) -> LLIR::data_block;
        auto getInclosedMapFromKeyValueBinding() -> LLIR::inclosed_map;

        // interaction functions
        auto getDataBlocks(const LLIR::types begin_type) -> DataBlockList;
    protected:
        // data
        size_t variable_count = 0;
        bool isToken;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        int tokensOnly = -1;
        std::vector<std::string> fullname;
        std::vector<LLIR::variable> elements;
        std::vector<var_group> groups;
        std::vector<LLIR::variable> vars;
        std::vector<LLIR::member> data;
        std::vector<ConvertionResult> success_vars;
        const std::vector<TreeAPI::RuleMember> *rules = nullptr;
        std::vector<std::pair<std::string, LLIR::variable>> key_vars;
        std::vector<LLIR::variable> unnamed_datablock_units;
        Tree* tree;
        // data for output
        std::stack<std::string> current_pos_counter;
        size_t indentLevel = 0;
        // helper functions
        void erase_begin();
        // convertion
        void ruleToIr(const TreeAPI::RuleMember &rule);
        auto rulesToIr(const std::vector<TreeAPI::RuleMember> &rules) -> LLIR;
        auto rulesToIr(const std::vector<TreeAPI::RuleMember> &rules, bool &addSpaceSkipFirst) -> LLIR;
        void treeToIr();
        auto makeIR() -> std::vector<ConvertionResult>;
        // optimizations
        void getVariablesToTable(std::vector<LLIR::member> &data, size_t &i, std::vector<LLIR::member>& table, std::string var_name, bool retain_value, bool recursive);
        size_t getBegin(size_t& i);
        void insertVariablesOnTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member>& table, size_t begin);
        void raiseVarsTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member> &readPlace, std::string var_name = "", bool all_rule = false, bool retain_value = true, bool recursive = true);
        void optimizeIR();
    public:
        LLIR(Tree &tree, int tokensOnly = -1) : tree(&tree) {
            makeIR();
            optimizeIR();
        }
        LLIR(Tree *tree, int tokensOnly = -1) : tree(tree) {
            makeIR();
            optimizeIR();
        };
        LLIR(Tree &tree, const TreeAPI::RuleMember &toConvert, bool isToken, int tokensOnly = -1) : tree(&tree), isToken(isToken) {
            makeIR();
            // call raiseVars manually to specify it is all single rule
            raiseVarsTop(data, data, "", true);
        }
        LLIR(Tree *tree, const TreeAPI::RuleMember &toConvert, bool isToken, int tokensOnly = -1) : tree(tree), isToken(isToken) {
            makeIR();
            raiseVarsTop(data, data, "", true);
        }

        // get functions
        auto getTree() const -> const Tree*;
        auto getData() const -> const std::vector<LLIR::member>&;
        auto getData() -> std::vector<LLIR::member>&;
        auto getSuccessVars() const -> const std::vector<ConvertionResult>&;
        virtual void outputIRToFile(std::string filename);
        virtual void outputIRToConsole();
        void add(LLIR &repr);
        void add(std::vector<member> repr);
        void push(member member);
        void push_begin(member member);
        void proceed(const LLIR &ir);
        void update(LLIR& ir);
        void pop_begin();
        void pop();
        size_t size();
        bool empty();
        auto getDataBlocksTerminals() -> DataBlockList;
        auto getDataBlocksNonTerminals() -> DataBlockList;
};
