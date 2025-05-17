#pragma once
#include <any>
#include <list>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <hash.cppm>
#include <TreeAPI.cppm>
class ASTPass;
class LLIR_old {
    public:
        enum class types {
            NONE, RULE, TOKEN, RULE_END, VARIABLE, IF, WHILE, DOWHILE, ACCESSOR,
            METHOD_CALL, FUNCTION_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
            ASSIGN_VARIABLE, INCREASE_POS_COUNTER, INCREASE_POS_COUNTER_BY_TOKEN_LENGTH, RESET_POS_COUNTER,
            SKIP_SPACES, DATA_BLOCK, PUSH_POS_COUNTER, POP_POS_COUNTER, INSIDE_LOOP, ERR, JUMP, JUMP_FROM_VARIABLE, EMPTY
        };
        enum class condition_types {
            GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL,
            HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
            LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND, BITWISE_OR, BITWISE_ANDR,
            ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO,
            CHARACTER, ESCAPED_CHARACTER, CURRENT_CHARACTER, CURRENT_TOKEN, TOKEN_NAME, TOKEN, TOKEN_SEQUENCE, NUMBER, HEX, BIN, STRING, STRNCMP,
            VARIABLE, SUCCESS_CHECK, RVALUE, METHOD_CALL, FUNCTION_CALL
        };
        enum class var_types {
            UNDEFINED, STRING, BOOLEAN, NUMBER, ARRAY, OBJECT, FUNCTION, ANY, Rule, Token, Rule_result, Token_result,
            CHAR, UCHAR, SHORT, USHORT, INT, UINT, LONG, ULONG, LONGLONG, ULONGLONG
        };
        enum class var_assign_values {
            NONE, True, False, NUMBER, BOOLEAN, STRING, ARRAY, OBJECT, VAR_REFER, ACCESSOR,
            UCHAR, CHAR, USHORT, SHORT, UINT, INT, ULONG, LONG, ULONGLONG, LONGLONG, CURRENT_POS,
            CURRENT_POS_COUNTER, CURRENT_POS_SEQUENCE, CURRENT_CHARACTER, CURRENT_TOKEN, TOKEN_SEQUENCE, FUNCTION_CALL, EXPR, INCLOSED_MAP
        };
        enum class var_assign_types {
            ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO, BITWISE_AND, BITWISE_OR, BITWISE_ANDR, BITWISE_RIGHTSHFT, BITWISE_LEFTSHIFT, ASSIGN,
            ASSIGN_ADD, ASSIGN_SUBSTR, ASSIGN_MULTIPLY, ASSIGN_DIVIDE, ASSIGN_MODULO,
            ASSIGN_BITWISE_AND, ASSIGN_BITWISE_OR, ASSIGN_BITWISE_ANDR, ASSIGN_BITWISE_RIGHTSHFT, ASSIGN_BITWISE_LEFTSHIFT
        };
        struct var_type {
            var_types type = LLIR_old::var_types::UNDEFINED;
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
        struct current_token {
            condition_types op;
            std::string name;
        };
        struct expr {
            condition_types id;
            std::any value = {};
        };

        struct variable {
            std::string name;
            var_type type = {var_types::UNDEFINED};
            assign value = {var_assign_values::NONE};
            std::vector<std::string> property_access = {};
        };
        struct var_refer {
            std::optional<char> pre_increament;
            std::optional<char> post_increament;
            variable var;
            std::vector<LLIR_old::expr> brace_expression;
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

        struct variable_assign {
            std::string name;
            var_assign_types assign_type = var_assign_types::ASSIGN;
            assign value = {var_assign_values::NONE};
        };
        struct strncmp {
            bool is_string;
            LLIR_old::variable value;
            size_t begin = 0;
        };
        using inclosed_map = std::unordered_map<std::string, std::pair<std::vector<LLIR_old::expr>, var_type>>;
        using regular_data_block = std::pair<std::vector<LLIR_old::expr>, var_type>;
        struct DataBlock {
            std::variant<std::monostate, regular_data_block, inclosed_map> value;
            bool is_inclosed_map() const;
            bool is_raw_expr() const;
            bool empty() const;
            regular_data_block &getRegularDataBlock();
            inclosed_map &getInclosedMap();
            const regular_data_block &getRegularDataBlock() const;
            const inclosed_map &getInclosedMap() const;
        };
        struct ConvertionResult {
            LLIR_old::variable svar;
            LLIR_old::variable uvar;
            LLIR_old::variable var;
            LLIR_old::variable shadow_var;
            char qualifier;
        };
        struct var_group {
            LLIR_old::variable var;
            size_t begin;
            size_t end;
        };
        struct Data {
            DataBlock block;
            std::vector<std::string> name;
            std::vector<LLIR_old::member> members;
        };
        using DataBlockList = std::unordered_map<std::vector<std::string>, LLIR_old::DataBlock>;

        // static functions
        static auto createEmptyVariable(std::string name) -> LLIR_old::variable;
        static auto processExitStatements(std::vector<LLIR_old::member> &values) -> void;
    private:
        void clear_thread();
        // output functions:
        std::string convert_var_type(var_types type);
        std::string convert_var_assing_values(var_assign_values value, std::any data);
        std::string convert_var_assing_types(var_assign_types type);
        std::string conditionTypesToString(condition_types type, std::any data);
        std::string convertFunctionCall(function_call call);
        std::string convertAssign(assign asgn);
        void convertVariable(variable var, std::ostream& out);
        std::string convertExpression(std::vector<expr> expression, bool with_braces);
        void convertBlock(std::vector<LLIR_old::member> block, std::ostream& out);
        void convertCondition(condition cond, std::ostream& out);
        void convertAssignVariable(variable_assign var, std::ostream &out);
        std::string convertMethodCall(method_call method);
        std::string convertDataBlock(const DataBlock &dtb);
        void convertMember(const member& mem, std::ostream& out);
        void convertMembers(const std::vector<member> &members, std::ostream& out);
        void convertData(const LLIR_old::Data &data, std::ostream& out);
        void printIR(std::ostream& out);

        // helper functions
        auto generateVariableName() -> std::string;
        auto createSuccessVariable() -> LLIR_old::variable;
        auto createAssignUvarBlock(const LLIR_old::variable uvar, const LLIR_old::variable var, const LLIR_old::variable &shadow_var) -> LLIR_old::member;
        auto addPostLoopCheck(const TreeAPI::RuleMember &rule, const LLIR_old::variable &var, bool addError = true) -> void;
        auto handle_plus_qualifier(const TreeAPI::RuleMember &rule, LLIR_old::condition loop, const LLIR_old::variable &uvar, const LLIR_old::variable &var, LLIR_old::variable &shadow_var, bool addError = true) -> void;
        static auto createDefaultBlock(const LLIR_old::variable &var, const LLIR_old::variable &svar) -> std::vector<LLIR_old::member>;
        static auto createDefaultBlock(const LLIR_old::variable &svar) -> std::vector<LLIR_old::member>;
        static auto createDefaultBlock() -> std::vector<LLIR_old::member>;
        auto getEscapedChar(char in) -> char;
        auto createDefaultCall(std::vector<LLIR_old::member> &block, LLIR_old::variable var, const std::string &name, std::vector<LLIR_old::expr> &expr) -> LLIR_old::member;
        auto add_shadow_variable(std::vector<LLIR_old::member> &block, const LLIR_old::variable &var) -> LLIR_old::variable;
        auto pushBasedOnQualifier(const TreeAPI::RuleMember &rule, std::vector<LLIR_old::expr> &expr, std::vector<LLIR_old::member> &block, LLIR_old::variable &uvar, const LLIR_old::variable &var, const LLIR_old::variable &svar, char quantifier, bool add_shadow_var = true) -> LLIR_old::variable;
        auto pushBasedOnQualifier_Rule_name(const TreeAPI::RuleMember &rule, std::vector<LLIR_old::expr> &expr, std::vector<LLIR_old::member> &block, LLIR_old::variable &uvar, const LLIR_old::variable &var, const LLIR_old::variable &svar, const LLIR_old::member &call, char quantifier, bool add_shadow_var = false) -> LLIR_old::variable;
        auto affectIrByQuantifier(const TreeAPI::RuleMember &rule, LLIR_old::variable &uvar, const LLIR_old::variable &var, char quantifier) -> LLIR_old::variable;
        auto compare_templ(const std::vector<LLIR_old::var_type>& templ1, const std::vector<LLIR_old::var_type>& templ2) -> bool;

        // Error functions
        auto getNextTerminal(std::vector<TreeAPI::RuleMember> symbols, size_t pos) ->  std::set<std::vector<std::string>>;
        auto getErrorName(const TreeAPI::RuleMember &rule) -> std::string;

        // Convertion functions
        auto TreeRvalueToIR(const TreeAPI::rvalue &value) -> LLIR_old::assign;
        auto TreeFunctionBodyCallToIR(const TreeAPI::CllFunctionBodyCall &body) -> std::vector<std::vector<LLIR_old::expr>>;
        auto TreeFunctionToIR(const TreeAPI::CllFunctionCall &call) -> LLIR_old::function_call;
        auto TreeMethodCallToIR(const TreeAPI::CllMethodCall &method) -> LLIR_old::method_call;
        auto cllTreeTypeToIR(const TreeAPI::CllType &type) -> LLIR_old::var_type;
        auto TreeOpToIR(const char op) -> LLIR_old::var_assign_types;
        auto TreeOpToExpr(const char op) -> LLIR_old::expr;
        auto TreeCompareOpToExpr(const TreeAPI::CllCompareOp &op) -> LLIR_old::expr;
        auto TreeLogicalOpToIR(const TreeAPI::CllLogicalOp &lop) -> LLIR_old::expr;
        auto TreeAssignmentOpToIR(const char op) -> LLIR_old::var_assign_types;
        auto TreeExprGroupToIR(const TreeAPI::CllExpr &group) -> std::vector<LLIR_old::expr>;
        auto TreeExprValueToIR(const TreeAPI::CllExprValue &value) -> std::vector<LLIR_old::expr>;
        auto TreeExprTermToIR(const TreeAPI::CllExprTerm &term) -> std::vector<LLIR_old::expr>;
        auto TreeExprAdditionToIR(const TreeAPI::CllExprAddition &addition) -> std::vector<LLIR_old::expr>;
        auto TreeExprCompareToIR(const TreeAPI::CllExprCompare &compare) -> std::vector<LLIR_old::expr>;
        auto TreeExprLogicalToIR(const TreeAPI::CllExprLogical &logical) -> std::vector<LLIR_old::expr>;
        auto TreeExprToIR(const TreeAPI::CllExpr &expr) -> std::vector<LLIR_old::expr>;

        // deduce type functions
        auto deduceUvarType(const LLIR_old::variable &var, const LLIR_old::variable &shadow_var) -> LLIR_old::var_type;
        auto deduceVarTypeByProd(const TreeAPI::RuleMember &mem) -> LLIR_old::var_type;
        auto deduceTypeFromRvalue(const TreeAPI::rvalue &value) -> LLIR_old::var_type;
        auto deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) -> LLIR_old::var_type;
        auto deduceTypeFromExprTerm(const TreeAPI::CllExprTerm &term) -> LLIR_old::var_type;
        auto deduceTypeFromExprAddition(const TreeAPI::CllExprAddition &addition) -> LLIR_old::var_type;
        auto deduceTypeFromExprCompare(const TreeAPI::CllExprCompare &compare) -> LLIR_old::var_type;
        auto deduceTypeFromExprLogical(const TreeAPI::CllExprLogical &logical) -> LLIR_old::var_type;
        auto deduceTypeFromExpr(const TreeAPI::CllExpr &expr) -> LLIR_old::var_type;

        // convertion functions helpers
        auto processGroup(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto processRuleCsequence(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto processString(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto process_Rule_hex(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto process_Rule_bin(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto process_Rule_name(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto process_Rule_nospace(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto process_Rule_escaped(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto process_Rule_any(const TreeAPI::RulePrefix &prefix) -> LLIR_old::ConvertionResult;
        auto convert_op_rule(const std::vector<TreeAPI::RuleMember> &rules, size_t index, LLIR_old::variable &var, LLIR_old::variable &svar) -> std::vector<LLIR_old::member>;
        auto process_Rule_op(const TreeAPI::RuleMember &rule) -> LLIR_old::ConvertionResult;
        auto process_cll_var(const TreeAPI::CllVar &var) -> void;
        auto process_cll_if(const TreeAPI::CllIf &cond) -> LLIR_old::condition;
        auto process_cll(const TreeAPI::Cll &cll) -> LLIR_old::ConvertionResult;
        auto createDataBlock(const TreeAPI::DataBlock &data_block) -> LLIR_old::DataBlock;
        auto getInclosedMapFromKeyValueBinding() -> LLIR_old::inclosed_map;

        // interaction functions
        auto getDataBlocks(bool isToken) -> DataBlockList;
    protected:
        // data
        size_t variable_count = 0;
        bool isToken;
        bool insideLoop = false;
        bool addSpaceSkip = false;
        bool isFirst = true;
        int tokensOnly = -1;
        std::vector<std::string> fullname;
        std::vector<LLIR_old::variable> vars;
        std::vector<Data> data;
        std::vector<member> members;
        std::vector<ConvertionResult> success_vars;
        const std::vector<TreeAPI::RuleMember> *rules = nullptr;
        std::vector<std::pair<std::string, LLIR_old::variable>> key_vars;
        std::vector<LLIR_old::variable> unnamed_datablock_units;
        ASTPass* tree;
        // follow symbols set for error handling
        std::vector<std::pair<std::vector<std::string>, std::set<std::vector<std::string>>>> symbol_follow;
        bool has_symbol_follow = true;
        // data for output
        std::stack<std::string> current_pos_counter;
        size_t indentLevel = 0;
        // helper functions
        void erase_begin();
        // convertion
        void ruleToIr(const TreeAPI::RuleMember &rule);
        auto rulesToIr(const std::vector<TreeAPI::RuleMember> &rules) -> LLIR_old;
        auto rulesToIr(const std::vector<TreeAPI::RuleMember> &rules, bool &addSpaceSkipFirst) -> LLIR_old;
        void treeToIr();
        // optimizations
        void getVariablesToTable(std::vector<LLIR_old::member> &data, std::vector<LLIR_old::member>& table, std::string &var_name, bool retain_value, bool recursive);
        void insertVariablesOnTop(std::vector<LLIR_old::member> &insertPlace, std::vector<LLIR_old::member>& table);
        void raiseVarsTop(std::vector<LLIR_old::member> &insertPlace, std::vector<LLIR_old::member> &readPlace, std::string var_name = "", bool all_rule = false, bool retain_value = true, bool recursive = true);
        void optimizeIR();
        LLIR_old(ASTPass *tree, int tokensOnly, bool buildImmediately) : tree(tree) {
            if (buildImmediately) {
                treeToIr();
                optimizeIR();
            }
        }
    public:
        LLIR_old(ASTPass &tree, int tokensOnly = -1) : tree(&tree) {
            treeToIr();
            optimizeIR();
        }
        LLIR_old(ASTPass *tree, int tokensOnly = -1) : tree(tree) {
            treeToIr();
            optimizeIR();
        };
        LLIR_old(ASTPass &tree, const TreeAPI::RuleMember &toConvert, const bool isToken) : tree(&tree), isToken(isToken) {
            has_symbol_follow = false;
            ruleToIr(toConvert);
            // call raiseVars manually to specify it is all single rule
            raiseVarsTop(members, members, "", true);
        }
        LLIR_old(ASTPass *tree, const TreeAPI::RuleMember &toConvert, const bool isToken) : tree(tree), isToken(isToken) {
            has_symbol_follow = false;
            ruleToIr(toConvert);
            raiseVarsTop(members, members, "", true);
        }

        // get functions
        auto getTree() const -> const ASTPass*;
        auto getData() const -> std::vector<Data>;
        auto getData() -> std::vector<LLIR_old::Data>&;
        auto getMembers() const -> const std::vector<member>&;
        auto getSuccessVars() const -> const std::vector<ConvertionResult>&;
        auto getFullName() const -> std::vector<std::string>;
        virtual void outputIRToFile(std::string filename);
        virtual void outputIRToConsole();
        void add(LLIR_old &repr);
        void add(std::vector<member> repr);
        void push(member member);
        void push_begin(member member);
        void proceed(const LLIR_old &ir);
        void update(LLIR_old& ir);
        void pop_begin();
        void pop();
        auto size() -> size_t;
        bool empty();
        auto getDataBlocksTerminals() -> DataBlockList;
        auto getDataBlocksNonTerminals() -> DataBlockList;
};
