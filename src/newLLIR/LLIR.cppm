module;
#include <vector>
#include <string>
#include <any>
#include <optional>
#include <variant>
#include <unordered_map>

export module LLIR;

export class LLIR {
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
        std::vector<std::string> properties;
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
        std::vector<LLIR::expr> brace_expression;
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
        LLIR::variable value;
        size_t begin = 0;
    };
    using inclosed_map = std::unordered_map<std::string, std::pair<std::vector<LLIR::expr>, var_type>>;
    using regular_data_block = std::pair<std::vector<LLIR::expr>, var_type>;
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
    struct Data {
        DataBlock block;
        std::vector<std::string> name;
        std::vector<LLIR::member> members;
    };
    using DataBlockList = std::unordered_map<std::vector<std::string>, LLIR::DataBlock>;
    using Nodes = std::vector<LLIR::member>;
    using Expression = std::vector<LLIR::expr>;
    // static variables
    static auto createEmptyVariable(std::string name) -> LLIR::variable;
    static auto processExitStatements(std::vector<LLIR::member> &values) -> void;
protected:
    std::vector<Data> data;
public:
    auto getData() const -> const std::vector<Data>&;
    auto operator[](size_t pos) const -> const Data&;
    auto begin() -> std::vector<Data>::iterator;
    auto end() -> std::vector<Data>::iterator;
    auto cbegin() -> std::vector<Data>::const_iterator;
    auto cend() -> std::vector<Data>::const_iterator;
    auto size() -> size_t;
    auto empty() -> bool;
    auto clear() -> void;
};