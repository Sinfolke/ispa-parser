export module LLIR.API;
import hash;
import dstd;
import std;

// forward declarations
export namespace LLIR {
    struct RValue;
    struct ExpressionValue;
    struct Expression;
    struct Statement;
    struct Statements;
}
// Promotion trait
template<typename T>
struct promote_to {
    using type = T; // default: no promotion
};

// Specializations for your hierarchy
template<> struct promote_to<LLIR::RValue> { using type = LLIR::ExpressionValue; };
template<> struct promote_to<LLIR::ExpressionValue> { using type = LLIR::Expression; };
template<> struct promote_to<LLIR::Expression> { using type = LLIR::Statement; };
template<> struct promote_to<LLIR::Statement> { using type = LLIR::Statements; };

template<typename Target, typename T>
auto promote_or_construct(T&& value) {
    if constexpr (std::is_constructible_v<Target, T>) {
        return Target{ std::forward<T>(value) };
    } else {
        using Next = typename promote_to<T>::type;
        static_assert(!std::is_same_v<Next, T>, "Type is not constructible");
        return promote_or_construct<Target>(Next{ std::forward<T>(value) });
    }
}

export namespace LLIR {
    enum class ExpressionElement {
        GroupOpen, GroupClose, SquareBraceOpen, SquareBraceClose,
        And, Or, Not, Equal, NotEqual,
        Higher, Lower, HigherOrEqual, LowerOrEqual,
        Add, Minus, Multiply, Divide, Modulo,
        PlusPlus, MinusMinus
    };
    enum class OperatorType {
        Assign, Add, Minus, Multiply, Divide, Modulo
    };
    enum class ValueType {
        Undef, Char, Int, Bool, Float, String, Array, Map, Symbol, StorageSymbol, Token, Rule, TokenResult, RuleResult, Any
    };
    enum class ArrayMethods {
        Push, Pop
    };
    enum class ObjectMethods {};
    struct StatementsLevel {
        template<typename T>
        static auto createStatements(T&& v) {
            return promote_or_construct<LLIR::Statements>(std::forward<T>(v));
        }
    };
    struct StatementLevel : StatementsLevel {
        template<typename T>
        static auto createStatement(T&& v) {
            return promote_or_construct<LLIR::Statement>(std::forward<T>(v));
        }
    };
    struct ExpressionLevel : StatementLevel {
        template<typename T>
        static auto createExpression(T&& v) {
            return promote_or_construct<LLIR::Expression>(std::forward<T>(v));
        }
    };
    struct ExpressionValueLevel : ExpressionLevel {
        template<typename T>
        static auto createExpressionValue(T&& v) {
            return promote_or_construct<LLIR::ExpressionValue>(std::forward<T>(v));
        }
    };
    struct RValueLevel : ExpressionValueLevel {
        template<typename T>
        static auto createRValue(T&& v) {
            return promote_or_construct<LLIR::RValue>(std::forward<T>(v));
        }
    };
    struct Char : RValueLevel {
        char value;
        bool escaped = false;
    };
    struct Int : RValueLevel {
        long long value;
    };
    struct Bool : RValueLevel {
        bool value;
    };
    struct Float : RValueLevel {
        double value;
    };
    struct String : RValueLevel {
        std::string value;
    };
    struct Array : RValueLevel {
        stdu::vector<stdu::vector<ExpressionValue>> values;
    };
    struct Map : RValueLevel {
        stdu::vector<std::variant<Int, String>> keys;
        stdu::vector<RValue> values;
        template<typename T>
        requires std::is_convertible_v<std::variant<Int, String>, T>
        auto areKeysJustT() -> bool {
            for (const auto &key : keys) {
                if (!std::holds_alternative<T>(key))
                    return false;
            }
            return true;
        };
    };
    struct Pos : RValueLevel {
        std::size_t offset;
        bool dereference = true;
        bool sequence = false;
    };
    struct FunctionCall : RValueLevel {
        std::string name;
        stdu::vector<Expression> args;
    };
    struct ArrayMethodCall : RValueLevel {
        ArrayMethods method;
        stdu::vector<Expression> args;
    };
    struct Symbol : RValueLevel {
        stdu::vector<std::variant<FunctionCall, std::string>> path;
    };
    // a symbol having storage reserved
    struct StorageSymbol : RValueLevel {
        stdu::vector<ExpressionValue> what;
        stdu::vector<std::variant<FunctionCall, ArrayMethodCall, std::string>> path;
    };
    struct Token : RValueLevel {};
    struct Rule : RValueLevel {};
    struct TokenResult {};
    struct RuleResult {};
    struct Type {
        ValueType type;
        stdu::vector<Type> template_parameters;
    };
    class RValue : public ExpressionValueLevel {
        std::variant<std::monostate, Char, Int, Bool, Float, String, Array, Map, Symbol, StorageSymbol, Token, Rule, TokenResult, RuleResult> value;
        void set_by_index(std::size_t index) {
            // generate a table of lambdas for each index
            static constexpr auto table = []<std::size_t... Is>(std::index_sequence<Is...>) {
                return std::array {
                    +[](decltype(value) &v) { v.emplace<Is>(); }...
                };
            }(std::make_index_sequence<std::variant_size_v<decltype(value)>>{});

            if (index < table.size())
                table[index](value);
            else
                throw std::out_of_range("invalid variant index");
        }
    public:
        RValue() {}
        template<typename T>
        requires std::is_constructible_v<decltype(value), T> && (!std::is_same_v<T, std::monostate>)
        RValue(T &&value) : value(std::move(value)) {}

        void clear() {
            value = std::monostate {};
        }
        template<typename T>
        requires std::is_constructible_v<decltype(value), T> && (!std::is_same_v<T, std::monostate>)
        void set(T &&value)  {this->value = std::move(value); }


        bool isChar()    const { return std::holds_alternative<Char>(value); }
        bool isInt()     const { return std::holds_alternative<Int>(value); }
        bool isBool()    const { return std::holds_alternative<Bool>(value); }
        bool isFloat()   const { return std::holds_alternative<Float>(value); }
        bool isString()  const { return std::holds_alternative<String>(value); }
        bool isArray()   const { return std::holds_alternative<Array>(value); }
        bool isMap()     const { return std::holds_alternative<Map>(value); }
        bool isSymbol()  const { return std::holds_alternative<Symbol>(value); }
        bool isStorageSymbol()  const { return std::holds_alternative<StorageSymbol>(value); }
        bool isToken()  const { return std::holds_alternative<Token>(value); }
        bool isRule()  const { return std::holds_alternative<Rule>(value); }
        bool isTokenResult()  const { return std::holds_alternative<TokenResult>(value); }
        bool isRuleResult()  const { return std::holds_alternative<RuleResult>(value); }
        bool isUndef() const { return std::holds_alternative<std::monostate>(value); }
        bool empty() const { return std::holds_alternative<std::monostate>(value); }

        Char&           getChar()    { return std::get<Char>(value); }
        Int&            getInt()     { return std::get<Int>(value); }
        Bool&           getBool()    { return std::get<Bool>(value); }
        Float&          getFloat()   { return std::get<Float>(value); }
        String&         getString()  { return std::get<String>(value); }
        Array&          getArray()   { return std::get<Array>(value); }
        Map&            getMap()     { return std::get<Map>(value); }
        Symbol&         getSymbol()  { return std::get<Symbol>(value); }
        StorageSymbol&  getStorageSymbol()  { return std::get<StorageSymbol>(value); }
        Token&          getToken()  { return std::get<Token>(value); }
        Rule&           getRule()  { return std::get<Rule>(value); }
        TokenResult&    getTokenResult()  { return std::get<TokenResult>(value); }
        RuleResult&     getRuleResult()  { return std::get<RuleResult>(value); }

        const Char&           getChar()   const { return std::get<Char>(value); }
        const Int&            getInt()    const { return std::get<Int>(value); }
        const Bool&           getBool()   const { return std::get<Bool>(value); }
        const Float&          getFloat()  const { return std::get<Float>(value); }
        const String&         getString() const { return std::get<String>(value); }
        const Array&          getArray()  const { return std::get<Array>(value); }
        const Map&            getMap()    const { return std::get<Map>(value); }
        const Symbol&         getSymbol() const { return std::get<Symbol>(value); }
        const StorageSymbol&  getStorageSymbol() const { return std::get<StorageSymbol>(value); }
        const Token&          getToken()  const { return std::get<Token>(value); }
        const Rule&           getRule()  const { return std::get<Rule>(value); }
        const TokenResult&    getTokenResult()  const { return std::get<TokenResult>(value); }
        const RuleResult&     getRuleResult()  const { return std::get<RuleResult>(value); }

        ValueType type() const { return static_cast<ValueType>(value.index()); }
        auto get() const { return value; }
    };
    struct Expression : stdu::vector<ExpressionValue>, StatementLevel {
        using vector::vector;
    };
    struct Break : ExpressionValueLevel {
    };
    struct Continue : ExpressionValueLevel {
    };
    struct Return : ExpressionValueLevel {
        Expression value;
    };
    struct StringCompare : ExpressionValueLevel {
        String str;
        bool is_string;
    };
    struct Hex : ExpressionValueLevel {
        std::string hex;
    };
    struct VariableAssignment : ExpressionValueLevel {
        std::string name;
        OperatorType type = OperatorType::Assign;
        Expression value;
    };
    struct Variable : ExpressionValueLevel {
        std::string name;
        Type type;
        Expression value;
        // Variable(const std::string &&n, const RValue &&v) : name(std::move(n)), value(std::move(v)) {}
        // Variable(const std::string &n, const RValue &v) : name(n), value(v)) {}
        auto empty() { return name.empty(); }
    };
    // possibly will be removed *
    struct CounterIncreament : ExpressionValueLevel {};
    struct CounterIncreamentByLength : ExpressionValueLevel {
        std::string name;
    };
    struct ResetPosCounter : ExpressionValueLevel {};
    struct PushPosCounter : ExpressionValueLevel {
        std::string name;
    };
    struct PopPosCounter : ExpressionValueLevel {};
    //                         *
    struct SkipSpaces : ExpressionValueLevel {
        bool isToken;
    };
    struct DfaLookup : ExpressionValueLevel {
        std::string output_name;
        std::size_t dfa_count;
    };
    struct ReportError : ExpressionValueLevel {
        std::string message;
    };
    struct ExpressionValue : ExpressionLevel {
        std::variant<
            std::monostate,
            RValue,
            ExpressionElement,
            FunctionCall,
            StringCompare,
            Return,
            Break,
            Continue,
            VariableAssignment,
            CounterIncreament,
            CounterIncreamentByLength,
            ResetPosCounter,
            PushPosCounter,
            PopPosCounter,
            SkipSpaces,
            DfaLookup
        > value;

        // ======= isXXX functions =======
        bool empty() const { return std::holds_alternative<std::monostate>(value); }
        bool isRvalue() const { return std::holds_alternative<RValue>(value); }
        bool isExpressionElement() const { return std::holds_alternative<ExpressionElement>(value); }
        bool isFunctionCall() const { return std::holds_alternative<FunctionCall>(value); }
        bool isStringCompare() const { return std::holds_alternative<StringCompare>(value); }
        bool isReturn() const { return std::holds_alternative<Return>(value); }
        bool isBreak() const { return std::holds_alternative<Break>(value); }
        bool isContinue() const { return std::holds_alternative<Continue>(value); }
        bool isVariableAssignment() const { return std::holds_alternative<VariableAssignment>(value); }
        bool isCounterIncreament() const { return std::holds_alternative<CounterIncreament>(value); }
        bool isCounterIncreamentByLength() const { return std::holds_alternative<CounterIncreamentByLength>(value); }
        bool isResetPosCounter() const { return std::holds_alternative<ResetPosCounter>(value); }
        bool isPushPosCounter() const { return std::holds_alternative<PushPosCounter>(value); }
        bool isPopPosCounter() const { return std::holds_alternative<PopPosCounter>(value); }
        bool isSkipSpaces() const { return std::holds_alternative<SkipSpaces>(value); }
        bool isDfaLookup() const { return std::holds_alternative<DfaLookup>(value); }

        // ======= getXXX functions =======
        RValue& getRvalue() { return std::get<RValue>(value); }
        ExpressionElement& getExpressionElement() { return std::get<ExpressionElement>(value); }
        FunctionCall& getFunctionCall() { return std::get<FunctionCall>(value); }
        StringCompare& getStringCompare() { return std::get<StringCompare>(value); }
        Return& getReturn() { return std::get<Return>(value); }
        Break& getBreak() { return std::get<Break>(value); }
        Continue& getContinue() { return std::get<Continue>(value); }
        VariableAssignment& getVariableAssignment() { return std::get<VariableAssignment>(value); }
        CounterIncreament& getCounterIncreament() { return std::get<CounterIncreament>(value); }
        CounterIncreamentByLength& getCounterIncreamentByLength() { return std::get<CounterIncreamentByLength>(value); }
        ResetPosCounter& getResetPosCounter() { return std::get<ResetPosCounter>(value); }
        PushPosCounter& getPushPosCounter() { return std::get<PushPosCounter>(value); }
        PopPosCounter& getPopPosCounter() { return std::get<PopPosCounter>(value); }
        SkipSpaces& getSkipSpaces() { return std::get<SkipSpaces>(value); }
        DfaLookup& getDfaLookup() { return std::get<DfaLookup>(value); }

        // const versions
        const RValue& getRvalue() const { return std::get<RValue>(value); }
        const ExpressionElement& getExpressionElement() const { return std::get<ExpressionElement>(value); }
        const FunctionCall& getFunctionCall() const { return std::get<FunctionCall>(value); }
        const StringCompare& getStringCompare() const { return std::get<StringCompare>(value); }
        const Return& getReturn() const { return std::get<Return>(value); }
        const Break& getBreak() const { return std::get<Break>(value); }
        const Continue& getContinue() const { return std::get<Continue>(value); }
        const VariableAssignment& getVariableAssignment() const { return std::get<VariableAssignment>(value); }
        const CounterIncreament& getCounterIncreament() const { return std::get<CounterIncreament>(value); }
        const CounterIncreamentByLength& getCounterIncreamentByLength() const { return std::get<CounterIncreamentByLength>(value); }
        const ResetPosCounter& getResetPosCounter() const { return std::get<ResetPosCounter>(value); }
        const PushPosCounter& getPushPosCounter() const { return std::get<PushPosCounter>(value); }
        const PopPosCounter& getPopPosCounter() const { return std::get<PopPosCounter>(value); }
        const SkipSpaces& getSkipSpaces() const { return std::get<SkipSpaces>(value); }
        const DfaLookup& getDfaLookup() const { return std::get<DfaLookup>(value); }
    };
    struct Statements : stdu::vector<Statement> {
        using vector::vector;
    };
    // made for if, while, do-while
    struct ConditionalElement : StatementLevel {
        Expression expr;
        Statements stmt;
    };
    struct If : ConditionalElement {
        Statements else_stmt;

        If(const Expression &e, const Statements &s, const Statements &else_stmt) : ConditionalElement {.expr = e, .stmt = s}, else_stmt(else_stmt) {}
        If(const Expression &e, const Statements &s) : ConditionalElement {.expr = e, .stmt = s} {}
        If(const Expression &e) : ConditionalElement {.expr = e} {}
        If() {}
    };
    struct While : ConditionalElement {
        While(const Expression &e, const Statements &s) : ConditionalElement {.expr = e, .stmt = s} {}
        While(const Expression &e) : ConditionalElement {.expr = e} {}
        While() {}
    };
    struct DoWhile : ConditionalElement {
        DoWhile(const Expression &e, const Statements &s) : ConditionalElement {.expr = e, .stmt = s} {}
        DoWhile(const Expression &e) : ConditionalElement {.expr = e} {}
        DoWhile() {}
    };
    struct Switch : StatementLevel {
        Expression expression;
        stdu::vector<std::pair<RValue, Statements>> cases;
    };
    struct Statement : StatementsLevel {
        std::variant<Variable, If, While, DoWhile, Switch, Expression> value;

        // ======= isXXX functions =======
        bool isVariable() const { return std::holds_alternative<Variable>(value); }
        bool isIf() const { return std::holds_alternative<If>(value); }
        bool isWhile() const { return std::holds_alternative<While>(value); }
        bool isDoWhile() const { return std::holds_alternative<DoWhile>(value); }
        bool isSwitch() const { return std::holds_alternative<Switch>(value); }
        bool isExpression() const { return std::holds_alternative<Expression>(value); }

        // ======= getXXX functions =======
        Variable& getVariable() { return std::get<Variable>(value); }
        If& getIf() { return std::get<If>(value); }
        While& getWhile() { return std::get<While>(value); }
        DoWhile& getDoWhile() { return std::get<DoWhile>(value); }
        ConditionalElement &getWhileOrDoWhile() { return std::holds_alternative<While>(value) ? static_cast<ConditionalElement &>(std::get<While>(value)) : static_cast<ConditionalElement &>(std::get<DoWhile>(value)); }
        Switch& getSwitch() { return std::get<Switch>(value); }
        Expression& getExpression() { return std::get<Expression>(value); }
        // ======= const versions =======
        const Variable& getVariable() const { return std::get<Variable>(value); }
        const If& getIf() const { return std::get<If>(value); }
        const While& getWhile() const { return std::get<While>(value); }
        const DoWhile& getDoWhile() const { return std::get<DoWhile>(value); }
        const ConditionalElement& getWhileOrDoWhile() const { return std::holds_alternative<While>(value) ? static_cast<const ConditionalElement &>(std::get<While>(value)) : static_cast<const ConditionalElement &>(std::get<DoWhile>(value)); }
        const Switch& getSwitch() const { return std::get<Switch>(value); }
        const Expression& getExpression() const { return std::get<Expression>(value); }

        static auto createStatements(const RValue &value) -> stdu::vector<Statement>;
    };

    enum class types {
        NONE, VARIABLE, IF, WHILE, DOWHILE,
        METHOD_CALL, FUNCTION_CALL, INTERNAL_CALL, EXIT, BREAK_LOOP, CONTINUE_LOOP,
        ASSIGN_VARIABLE, INCREASE_POS_COUNTER, INCREASE_POS_COUNTER_BY_TOKEN_LENGTH, RESET_POS_COUNTER,
        SKIP_SPACES, DATA_BLOCK, PUSH_POS_COUNTER, POP_POS_COUNTER, ERR, JUMP, JUMP_FROM_VARIABLE, SWITCH, DFA_LOOKUP, EMPTY
    };
    enum class condition_types {
        GROUP_OPEN, GROUP_CLOSE, AND, OR, NOT, EQUAL, NOT_EQUAL,
        HIGHER, LOWER, HIGHER_OR_EQUAL, LOWER_OR_EQUAL,
        LEFT_BITWISE, RIGHT_BITWISE, BITWISE_AND, BITWISE_OR, BITWISE_ANDR,
        ADD, SUBSTR, MULTIPLY, DIVIDE, MODULO,
        CHARACTER, ESCAPED_CHARACTER, CURRENT_CHARACTER, CURRENT_TOKEN, TOKEN_NAME, TOKEN, TOKEN_SEQUENCE, NUMBER, HEX, BIN, STRING, STRNCMP,
        VARIABLE, SUCCESS_CHECK, RVALUE, METHOD_CALL, FUNCTION_CALL, DFA
    };
    enum class var_types {
        UNDEFINED, STRING, BOOLEAN, NUMBER, INT, ARRAY, OBJECT, FUNCTION, ANY, Rule, Token, Rule_result, Token_result, CHAR
    };
    enum class var_assign_values {
        NONE, True, False, NUMBER, BOOLEAN, STRING, ARRAY, OBJECT, VAR_REFER, ACCESSOR,
        UCHAR, CHAR, USHORT, SHORT, UINT, INT, ULONG, LONG, ULONGLONG, LONGLONG, CURRENT_POS,
        CURRENT_POS_COUNTER, CURRENT_POS_SEQUENCE, CURRENT_CHARACTER, CURRENT_TOKEN, TOKEN_SEQUENCE, TOKEN_NAME, FUNCTION_CALL, INTERNAL_FUNCTION_CALL, EXPR, INCLOSED_MAP
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
        std::size_t begin = 0;
    };
    struct switch_statement {
        struct unit {
            assign name;
            stdu::vector<member> block;
        };
        stdu::vector<expr> expression;
        stdu::vector<unit> cases;
    };
    using inclosed_map = std::unordered_map<std::string, std::pair<Expression, Type>>;
    using regular_data_block = std::pair<Expression, Type>;
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
    struct ExportsAfterBuild {
        Variable svar;
        Variable uvar;
        Variable var;
        Variable shadow_var;
        char quantifier;
    };
    struct var_group {
        variable var;
        std::size_t begin;
        std::size_t end;
    };
    struct Production {
        DataBlock block;
        stdu::vector<std::string> name;
        Statements members;
    };
    using DataBlockList = utype::unordered_map<stdu::vector<std::string>, DataBlock>;
    using Nodes = stdu::vector<member>;
}