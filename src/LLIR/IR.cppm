export module LLIR;
import hash;
import dstd;
import std;
import std.compat;
export namespace LLIR {
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
        var_types type = var_types::UNDEFINED;
        stdu::vector<var_type> templ = {};
        std::size_t operator()(const stdu::vector<std::string>& key) const {
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
        stdu::vector<std::string> properties;
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
        stdu::vector<std::string> property_access = {};
    };
    struct var_refer {
        std::optional<char> pre_increament;
        std::optional<char> post_increament;
        variable var;
        stdu::vector<expr> brace_expression;
    };
    using array = stdu::vector<stdu::vector<expr>>;
    using object = std::unordered_map<std::string, stdu::vector<expr>>;
    struct function_call {
        std::string name;
        stdu::vector<stdu::vector<expr>> params;
    };
    struct method_call {
        std::string var_name;
        stdu::vector<function_call> calls;
    };
    struct condition {
        stdu::vector<expr> expression;
        stdu::vector<member> block;
        stdu::vector<member> else_block = {};
    };

    struct variable_assign {
        std::string name;
        var_assign_types assign_type = var_assign_types::ASSIGN;
        assign value = {var_assign_values::NONE};
    };
    struct strncmp {
        bool is_string;
        variable value;
        size_t begin = 0;
    };
    using inclosed_map = std::unordered_map<std::string, std::pair<stdu::vector<expr>, var_type>>;
    using regular_data_block = std::pair<stdu::vector<expr>, var_type>;
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
        variable svar;
        variable uvar;
        variable var;
        variable shadow_var;
        char quantifier;
    };
    struct var_group {
        variable var;
        size_t begin;
        size_t end;
    };
    struct Data {
        DataBlock block;
        stdu::vector<std::string> name;
        stdu::vector<member> members;
    };
    using DataBlockList = utype::unordered_map<stdu::vector<std::string>, DataBlock>;
    using Nodes = stdu::vector<member>;
    using Expression = stdu::vector<expr>;
    class IR {
        auto getDataBlocks(bool isToken) -> DataBlockList;
    protected:
        std::string convert_var_type(var_types type);
        std::string convert_var_assing_values(var_assign_values value, std::any data);
        std::string convert_var_assing_types(var_assign_types type);
        std::string conditionTypesToString(condition_types type, std::any data);
        std::string convertFunctionCall(function_call call);
        std::string convertAssign(assign asgn);
        void convertVariable(variable var, std::ostream& out);
        std::string convertExpression(LLIR::Expression expression, bool with_braces);
        void convertBlock(LLIR::Nodes block, std::ostream& out);
        void convertCondition(condition cond, std::ostream& out);
        void convertAssignVariable(variable_assign var, std::ostream &out);
        std::string convertMethodCall(method_call method);
        std::string convertDataBlock(const DataBlock &dtb);
        void convertMember(const member& mem, std::ostream& out);
        void convertMembers(const LLIR::Nodes &members, std::ostream& out);
        void convertData(const LLIR::Data &data, std::ostream& out);
        void printIR(std::ostream& out);
        stdu::vector<Data> data;
        // output functions
        std::stack<std::string> current_pos_counter;
        size_t indentLevel = 0;
    public:
        explicit IR(const stdu::vector<Data> &data) : data(data) {}
        IR() = default;
        auto getData() const -> const stdu::vector<Data>&;
        auto operator[](size_t pos) const -> const Data&;
        auto begin() -> stdu::vector<Data>::iterator;
        auto end() -> stdu::vector<Data>::iterator;
        auto cbegin() -> stdu::vector<Data>::const_iterator;
        auto cend() -> stdu::vector<Data>::const_iterator;
        auto size() -> size_t;
        auto empty() -> bool;
        auto clear() -> void;
        auto getDataBlocksTerminals() -> DataBlockList;
        auto getDataBlocksNonTerminals() -> DataBlockList;

        // print function
        void outputIRToFile(std::string filename);
        void outputIRToConsole();
    };
    using lexer_code = std::pair<IR, variable>;
}