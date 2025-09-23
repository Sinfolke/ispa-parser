export module LLIR.API;
import hash;
import dstd;
import std;

// forward declarations
export namespace LLIR {
    class RValue;
    struct ExpressionValue;
    struct Expression;
    struct Statement;
    struct Statements;
    struct Declaration;
    struct Declarations;
    struct ConditionalElement;
}
// Default: no promotion
template<typename T>
struct promote_to {
    using type = void;
    static constexpr bool can_promote = false;
};

// Specializations
template<> struct promote_to<LLIR::RValue> {
    using type = LLIR::ExpressionValue;
    static constexpr bool can_promote = true;
};
template<> struct promote_to<LLIR::ExpressionValue> {
    using type = LLIR::Expression;
    static constexpr bool can_promote = true;
};
template<> struct promote_to<LLIR::Expression> {
    using type = LLIR::Statement;
    static constexpr bool can_promote = true;
};
template<> struct promote_to<LLIR::Statement> {
    using type = LLIR::Statements;
    static constexpr bool can_promote = true;
};
template<> struct promote_to<LLIR::Statements> {
    using type = LLIR::Declaration;
    static constexpr bool can_promote = true;
};
template<> struct promote_to<LLIR::Declaration> {
    using type = LLIR::Declarations;
    static constexpr bool can_promote = true;
};

// Recursive promotion or construction
template<typename whatToConstruct, typename fromWhatToConstruct>
auto promote_or_construct(fromWhatToConstruct&& value) -> whatToConstruct {
    if constexpr (std::is_constructible_v<whatToConstruct, fromWhatToConstruct>) {
        return whatToConstruct{ std::forward<fromWhatToConstruct>(value) };
    } else if constexpr (requires { typename std::decay_t<fromWhatToConstruct>::promote_to; }) {
        using P = typename std::decay_t<fromWhatToConstruct>::promote_to;
        return promote_or_construct<whatToConstruct>(P{std::forward<fromWhatToConstruct>(value)});
    } else {
        return void {};
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
        Undef, Char, Int, Bool, Float, String, Array, FixedSizeArray, Map, Symbol, StorageSymbol, Inheritance, Token, Rule, TokenResult, RuleResult, Any
    };
    enum class ArrayMethods {
        Push, Pop
    };
    enum class Visibility {
        Private, Public
    };
    enum class Inherit {
        Lexer, Parser
    };
    enum class ObjectMethods {};
    struct DeclarationsLevel {
        using promote_to = Declarations;
        template<typename T>
        static auto createDeclarations(T&& v) {
            return promote_or_construct<LLIR::Declarations>(std::forward<T>(v));
        }
    };
    struct DeclarationLevel : DeclarationsLevel {
        using promote_to = Declaration;
        template<typename T>
        static auto createDeclaration(T&& v) {
            return promote_or_construct<LLIR::Declaration>(std::forward<T>(v));
        }
    };
    struct StatementsLevel : DeclarationLevel {
        using promote_to = Statements;
        template<typename T>
        static auto createStatements(T&& v) {
            return promote_or_construct<LLIR::Statements>(std::forward<T>(v));
        }
    };
    struct StatementLevel : StatementsLevel {
        using promote_to = Statement;
        template<typename T>
        static auto createStatement(T&& v) {
            return promote_or_construct<LLIR::Statement>(std::forward<T>(v));
        }
    };
    struct ExpressionLevel : StatementLevel {
        using promote_to = Expression;
        template<typename T>
        static auto createExpression(T&& v) {
            return promote_or_construct<LLIR::Expression>(std::forward<T>(v));
        }
    };
    struct ExpressionValueLevel : ExpressionLevel {
        using promote_to = ExpressionValue;
        template<typename T>
        requires std::is_constructible_v<ExpressionValue, std::decay_t<T>>
        static auto createExpressionValue(T&& v) {
            return promote_or_construct<LLIR::ExpressionValue>(std::forward<T>(v));
        }
    };
    struct RValueLevel : ExpressionValueLevel {
        using promote_to = RValue;
        template<typename T>
        static auto createRValue(T&& v) {
            return promote_or_construct<LLIR::RValue>(std::forward<T>(v));
        }
    };
    struct Declarations : stdu::vector<Declaration> {
        using vector::vector;
    };
    struct Statements : stdu::vector<Statement> {
        using vector::vector;
    };
    struct Expression : stdu::vector<ExpressionValue>, StatementLevel {
        using vector::vector;
    };
    struct Char : RValueLevel {
        char value;
        bool escaped = false;

        bool operator==(const Char& c) const {
            return value == c.value && escaped == c.escaped;
        }
        bool operator!=(const Char& c) const {
            return !(*this == c);
        }
    };

    struct Int : RValueLevel {
        long long value;

        bool operator==(const Int& other) const { return value == other.value; }
        bool operator!=(const Int& other) const { return !(*this == other); }
    };

    struct Bool : RValueLevel {
        bool value;

        bool operator==(const Bool& other) const { return value == other.value; }
        bool operator!=(const Bool& other) const { return !(*this == other); }
    };

    struct Float : RValueLevel {
        double value;

        bool operator==(const Float& other) const { return value == other.value; }
        bool operator!=(const Float& other) const { return !(*this == other); }
    };

    struct String : RValueLevel {
        std::string value;

        bool operator==(const String& other) const { return value == other.value; }
        bool operator!=(const String& other) const { return !(*this == other); }
    };

    struct Array : RValueLevel {
        stdu::vector<Expression> values;

        bool operator==(const Array& other) const { return values == other.values; }
        bool operator!=(const Array& other) const { return !(*this == other); }
    };

    struct FixedSizeArray : Array {
        std::size_t size;

        bool operator==(const FixedSizeArray& other) const {
            return size == other.size && static_cast<const Array&>(*this) == static_cast<const Array&>(other);
        }
        bool operator!=(const FixedSizeArray& other) const { return !(*this == other); }
    };

    struct Map : RValueLevel {
        stdu::vector<std::variant<Int, String>> keys;
        stdu::vector<Expression> values;

        bool operator==(const Map& other) const {
            return keys == other.keys && values == other.values;
        }
        bool operator!=(const Map& other) const { return !(*this == other); }
    };

    struct Pos : RValueLevel {
        bool dereference = true;
        bool sequence = false;
        std::size_t offset;

        bool operator==(const Pos& other) const {
            return offset == other.offset &&
                   dereference == other.dereference &&
                   sequence == other.sequence;
        }
        bool operator!=(const Pos& other) const { return !(*this == other); }
    };

    struct FunctionCall : RValueLevel {
        std::string name;
        stdu::vector<Expression> args;

        bool operator==(const FunctionCall& other) const {
            return name == other.name && args == other.args;
        }
        bool operator!=(const FunctionCall& other) const { return !(*this == other); }
    };

    struct ArrayMethodCall : RValueLevel {
        ArrayMethods method;
        stdu::vector<Expression> args;

        bool operator==(const ArrayMethodCall& other) const {
            return method == other.method && args == other.args;
        }
        bool operator!=(const ArrayMethodCall& other) const { return !(*this == other); }
    };

    struct Symbol : RValueLevel {
        using PathPart = std::variant<FunctionCall, std::string>;
        stdu::vector<PathPart> path;

        template<typename... Args>
        requires (std::constructible_from<PathPart, Args> && ...)
        Symbol(Args&&... args) {
            (path.emplace_back(std::forward<Args>(args)), ...);
        }
        Symbol(const stdu::vector<PathPart> &path) : path(std::move(path)) {}
        bool operator==(const Symbol& other) const { return path == other.path; }
        bool operator!=(const Symbol& other) const { return !(*this == other); }
    };

    struct StorageSymbol : RValueLevel {
        stdu::vector<ExpressionValue> what;
        stdu::vector<std::variant<FunctionCall, ArrayMethodCall, std::string>> path;

        bool operator==(const StorageSymbol& other) const {
            return what == other.what && path == other.path;
        }
        bool operator!=(const StorageSymbol& other) const { return !(*this == other); }
    };

    struct Inheritance : RValueLevel {
        Symbol name;
        stdu::vector<Expression> args;

        bool operator==(const Inheritance& other) const {
            return name == other.name && args == other.args;
        }
        bool operator!=(const Inheritance& other) const { return !(*this == other); }
    };

    struct Token : RValueLevel {
        bool operator==(const Token&) const { return true; }
        bool operator!=(const Token&) const { return false; }
    };

    struct Rule : RValueLevel {
        bool operator==(const Rule&) const { return true; }
        bool operator!=(const Rule&) const { return false; }
    };

    struct TokenResult {
        bool operator==(const TokenResult&) const { return true; }
        bool operator!=(const TokenResult&) const { return false; }
    };

    struct RuleResult {
        bool operator==(const RuleResult&) const { return true; }
        bool operator!=(const RuleResult&) const { return false; }
    };
    class RValue : public ExpressionValueLevel {
        std::variant<std::monostate, Char, Int, Bool, Float, String, Array, Map, Pos, Symbol, StorageSymbol, Inheritance, Token, Rule, TokenResult, RuleResult> value;
    public:
        using promote_to = ExpressionValue;
        RValue() {}
        template<typename T>
        requires std::is_constructible_v<decltype(value), std::decay_t<T>> && (!std::is_same_v<std::decay_t<T>, std::monostate>)
        RValue(const T &value) : value(std::move(value)) {}
        template<typename T>
        requires std::is_constructible_v<decltype(value), std::decay_t<T>> && (!std::is_same_v<std::decay_t<T>, std::monostate>)
        RValue(T &&value) : value(std::move(value)) {}

        void clear() {
            value = std::monostate {};
        }
        template<typename T>
        requires std::is_constructible_v<decltype(value), std::decay_t<T>> && (!std::is_same_v<std::decay_t<T>, std::monostate>)
        void set(T &&value)  {this->value = std::move(value); }
        template<typename T>
        requires std::is_constructible_v<decltype(value), std::decay_t<T>> && (!std::is_same_v<std::decay_t<T>, std::monostate>)
        void set(const T &value)  {this->value = std::move(value); }

        bool operator==(const RValue& other) const {
            return value == other.value;
        }
        bool operator!=(const RValue& other) const { return !(*this == other); }
        bool isChar()    const { return std::holds_alternative<Char>(value); }
        bool isInt()     const { return std::holds_alternative<Int>(value); }
        bool isBool()    const { return std::holds_alternative<Bool>(value); }
        bool isFloat()   const { return std::holds_alternative<Float>(value); }
        bool isString()  const { return std::holds_alternative<String>(value); }
        bool isArray()   const { return std::holds_alternative<Array>(value); }
        bool isMap()     const { return std::holds_alternative<Map>(value); }
        bool isSymbol()  const { return std::holds_alternative<Symbol>(value); }
        bool isStorageSymbol()  const { return std::holds_alternative<StorageSymbol>(value); }
        bool isInheritance()  const { return std::holds_alternative<Inheritance>(value); }
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
        Inheritance&  getInheritance()  { return std::get<Inheritance>(value); }
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
        const Inheritance&  getInheritance() const  { return std::get<Inheritance>(value); }
        const Token&          getToken()  const { return std::get<Token>(value); }
        const Rule&           getRule()  const { return std::get<Rule>(value); }
        const TokenResult&    getTokenResult()  const { return std::get<TokenResult>(value); }
        const RuleResult&     getRuleResult()  const { return std::get<RuleResult>(value); }

        ValueType type() const { return static_cast<ValueType>(value.index()); }
        auto get() const { return value; }

        // equality
        bool operator==(const RValue& rhs) {
            return value == rhs.value;
        }

        bool operator!=(const RValue& rhs) {
            return value != rhs.value;
        }

    };
    struct Type {
        std::variant<ValueType, Symbol> type;
        stdu::vector<std::variant<Type, RValue>> template_parameters;
        template<typename TypeOrPath, typename ...Templates>
        requires (std::is_same_v<std::decay_t<TypeOrPath>, ValueType> || std::is_same_v<std::decay_t<TypeOrPath>, Symbol>)
        Type(TypeOrPath vtype, Templates&& ...templates) {
            type = vtype;
            (template_parameters.push_back(templates), ...);
        }
        Type() = default;
        bool isValueType() const {
            return std::holds_alternative<ValueType>(type);
        }
        bool isSymbol() const {
            return std::holds_alternative<Symbol>(type);
        }
        auto &getValueType() {
            return std::get<ValueType>(type);
        }
        auto &getSymbol() {
            return std::get<Symbol>(type);
        }
        auto &getValueType() const {
            return std::get<ValueType>(type);
        }
        auto &getSymbol() const {
            return std::get<Symbol>(type);
        }
        bool operator==(const ValueType &v) const {
            return std::holds_alternative<ValueType>(type) && std::get<ValueType>(type) == v;
        }
        bool operator!=(const ValueType &v) const {
            return !(*this == v);
        }
        bool operator==(const Symbol &v) const {
            return std::holds_alternative<Symbol>(type) && std::get<Symbol>(type) == v;
        }
        bool operator!=(const Symbol &v) const {
            return !(*this == v);
        }
        bool operator==(const Type& other) const {
            if (type != other.type)
                return false;
            const auto templ1 = template_parameters;
            const auto templ2 = other.template_parameters;
            if (templ1.size() != templ2.size()) return false;

            for (std::size_t i = 0; i < templ1.size(); ++i) {
                if (templ1[i].index() != templ2[i].index()) return false;
                if (std::holds_alternative<Type>(templ1[i])) {
                    const auto &first = std::get<Type>(templ1[i]);
                    const auto &second = std::get<Type>(templ2[i]);
                    return first == second;
                } else {
                    const auto &first = std::get<RValue>(templ1[i]);
                    const auto &second = std::get<RValue>(templ2[i]);
                    return first == second;
                }
            }
            return true;
        }
        bool operator!=(const Type &other) const {
            return !(*this == other);
        }
    };

    struct Class : DeclarationLevel {
        std::string name;
        stdu::vector<std::pair<Declarations, Visibility>> data;
        Inherit inherit;
        bool operator==(const Class& other) const {
            return name == other.name && data == other.data && inherit == other.inherit;
        }
        bool operator!=(const Class& other) const {
            return !(*this == other);
        }
    };
    struct Struct : DeclarationLevel {
        std::string name;
        stdu::vector<std::pair<Declarations, Visibility>> data;
        bool operator==(const Struct& other) const {
            return name == other.name && data == other.data;
        }
    };
    struct Namespace : DeclarationLevel {
        std::string name;
        Declarations declarations;
        bool operator==(const Namespace& other) const {
            return name == other.name && declarations == other.declarations;
        }
        bool operator!=(const Namespace& other) const {
            return !(*this == other);
        }
    };
    struct Function : DeclarationLevel {
        std::string name;
        Statements statements;
        bool operator==(const Function& other) const {
            return name == other.name && statements == other.statements;
        }
        bool operator!=(const Function& other) const {
            return !(*this == other);
        }
    };
    struct TypeAlias : DeclarationLevel {
        std::string name;
        Type type;
        bool operator==(const TypeAlias& other) const {
            return name == other.name && type == other.type;
        }
        bool operator!=(const TypeAlias& other) const {
            return !(*this == other);
        }
    };
    struct Variable : ExpressionValueLevel {
        std::string name;
        Type type;
        Expression value;
        bool operator==(const Variable& other) const {
            return name == other.name && type == other.type && value == other.value;
        }
        bool operator!=(const Variable& other) const {
            return !(*this == other);
        }
        // Variable(const std::string &&n, const RValue &&v) : name(std::move(n)), value(std::move(v)) {}
        // Variable(const std::string &n, const RValue &v) : name(n), value(v)) {}
        auto empty() { return name.empty(); }
    };
    struct Declaration : DeclarationsLevel {
        using promote_to = Declarations;
        std::variant<Class, Struct, Namespace, Function, TypeAlias, Variable> value;

        Declaration() {};
        template<typename T>
        requires std::is_constructible_v<decltype(value), T>
        Declaration(T value) : value(value) {}

        bool operator==(const Declaration& other) const {
            return value == other.value;
        }
        bool operator!=(const Declaration& other) const {
            return value != other.value;
        }
        // Is functions
        bool isClass() const { return std::holds_alternative<Class>(value); }
        bool isStruct() const { return std::holds_alternative<Struct>(value); }
        bool isNamespace() const { return std::holds_alternative<Namespace>(value); }
        bool isFunction() const { return std::holds_alternative<Function>(value); }
        bool isTypeAlias() const { return std::holds_alternative<TypeAlias>(value); }

        // Get functions
        auto& getClass() { return std::get<Class>(value); }
        const auto& getClass() const { return std::get<Class>(value); }

        auto& getStruct() { return std::get<Struct>(value); }
        const auto& getStruct() const { return std::get<Struct>(value); }

        auto& getNamespace() { return std::get<Namespace>(value); }
        const auto& getNamespace() const { return std::get<Namespace>(value); }

        auto& getFunction() { return std::get<Function>(value); }
        const auto& getFunction() const { return std::get<Function>(value); }

        auto& getTypeAlias() { return std::get<TypeAlias>(value); }
        const auto& getTypeAlias() const { return std::get<TypeAlias>(value); }
    };
    struct Break : ExpressionValueLevel {
        bool operator==(const Break&) const { return true; }
        bool operator!=(const Break&) const { return false; }
    };
    struct Continue : ExpressionValueLevel {
        bool operator==(const Continue&) const { return true; }
        bool operator!=(const Continue&) const { return false; }
    };
    struct Return : ExpressionValueLevel {
        Expression value;
        bool operator==(const Return& ret) const { return value == ret.value; }
        bool operator!=(const Return& ret) const { return !(*this == ret); }
    };
    struct StringCompare : ExpressionValueLevel {
        bool operator==(const StringCompare& s) const { return str == s.str && is_string == s.is_string;  }
        bool operator!=(const StringCompare& s) const { return !(*this == s); }
        String str;
        bool is_string;
    };
    struct Hex : ExpressionValueLevel {
        bool operator==(const Hex& h) const { return hex == h.hex; }
        bool operator!=(const Hex& h) const { return !(*this == h); }
        std::string hex;
    };
    struct VariableAssignment : ExpressionValueLevel {
        bool operator==(const VariableAssignment& v) const { return name == v.name && type == v.type && value == v.value; }
        bool operator!=(const VariableAssignment& v) const { return !(*this == v); }
        std::string name;
        OperatorType type = OperatorType::Assign;
        Expression value;
    };
    // possibly will be removed *
    struct CounterIncreament : ExpressionValueLevel {
        bool operator==(const CounterIncreament& c) const { return true; }
        bool operator!=(const CounterIncreament& c) const { return !(*this == c); }
    };
    struct CounterIncreamentByLength : ExpressionValueLevel {
        bool operator==(const CounterIncreamentByLength& n) const { return name == n.name; }
        bool operator!=(const CounterIncreamentByLength& n) const { return !(*this == n); }
        std::string name;
    };
    struct ResetPosCounter : ExpressionValueLevel {
        bool operator==(const ResetPosCounter& c) const { return true; }
        bool operator!=(const ResetPosCounter& c) const { return !(*this == c); }
    };
    struct PushPosCounter : ExpressionValueLevel {
        bool operator==(const PushPosCounter& c) const { return name == c.name; }
        bool operator!=(const PushPosCounter& c) const { return !(*this == c); }
        std::string name;
    };
    struct PopPosCounter : ExpressionValueLevel {
        bool operator==(const PopPosCounter& c) const { return true; }
        bool operator!=(const PopPosCounter& c) const { return !(*this == c); }
    };
    //                         *
    struct SkipSpaces : ExpressionValueLevel {
        bool operator==(const SkipSpaces& s) const { return isToken == s.isToken; }
        bool operator!=(const SkipSpaces& s) const { return !(*this == s); }
        bool isToken;
    };
    struct DfaLookup : ExpressionValueLevel {
        bool operator==(const DfaLookup &d) const { return output_name == d.output_name && dfa_count == d.dfa_count; }
        bool operator!=(const DfaLookup &d) const { return !(*this == d); }
        std::size_t dfa_count;
        std::string output_name;
    };
    struct ReportError : ExpressionValueLevel {
        bool operator==(const ReportError& e) const { return message == e.message; }
        bool operator!=(const ReportError& e) const { return !(*this == e); }
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
            DfaLookup,
            ReportError
        > value;
        ExpressionValue() {};
        template<typename T>
        requires std::is_constructible_v<decltype(value), T>
        ExpressionValue(const T &t) : value(t) {}
        template<typename T>
        requires std::is_constructible_v<decltype(value), T>
        ExpressionValue(T &&t) : value(t) {}
        bool operator==(const ExpressionValue& other) const {
            return value == other.value;
        }
        bool operator!=(const ExpressionValue& other) const {
            return !(*this == other);
        }

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
    // made for if, while, do-while
    struct ConditionalElement {
        bool operator==(const ConditionalElement& other) const {
            return expr == other.expr && stmt == other.stmt;
        }
        bool operator!=(const ConditionalElement& other) const {
            return !(*this == other);
        }
        Expression expr;
        Statements stmt;
    };
    struct If : ConditionalElement, StatementLevel {
        Statements else_stmt;
        bool operator==(const If& other) const {
            return static_cast<ConditionalElement>(*this) == other && else_stmt == other.else_stmt;
        }
        bool operator!=(const If& other) const {
            return !(*this == other);
        }
        If(const Expression &e, const Statements &s, const Statements &else_stmt) : ConditionalElement {.expr = e, .stmt = s}, else_stmt(else_stmt) {}
        If(const Expression &e, const Statements &s) : ConditionalElement {.expr = e, .stmt = s} {}
        If(const Expression &e) : ConditionalElement {.expr = e} {}
        If(Expression &&e, Statements &&s, Statements &&else_stmt) : ConditionalElement {.expr = std::move(e), .stmt = std::move(s)}, else_stmt(else_stmt) {}
        If(Expression &&e, Statements &&s) : ConditionalElement {.expr = std::move(e), .stmt = std::move(s)} {}
        If(Expression &&e) : ConditionalElement {.expr = std::move(e)} {}
        If() {};
    };
    struct While : ConditionalElement, StatementLevel {
        While(const Expression &e, const Statements &s) : ConditionalElement {.expr = e, .stmt = s} {}
        While(const Expression &e) : ConditionalElement {.expr = e} {}
        While() {}
    };
    struct DoWhile : ConditionalElement, StatementLevel {
        DoWhile(const Expression &e, const Statements &s) : ConditionalElement {.expr = e, .stmt = s} {}
        DoWhile(const Expression &e) : ConditionalElement {.expr = e} {}
        DoWhile() {}
    };
    struct Switch : StatementLevel {
        bool operator==(const Switch& other) const { return expression == other.expression && cases == other.cases; }
        bool operator!=(const Switch& other) const { return !(*this == other); }
        Expression expression;
        stdu::vector<std::pair<RValue, Statements>> cases;
    };
    struct Statement : StatementsLevel {
        std::variant<Variable, If, While, DoWhile, Switch, Expression> value;

        template<typename T>
        requires std::is_constructible_v<decltype(value), T>
        Statement(T value) : value(value) {}
        Statement(const ConditionalElement &value) : value(While {value.expr, value.stmt}) {}
        bool operator==(const Statement& other) const { return value == other.value; }
        bool operator!=(const Statement& other) const { return !(*this == other); }

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
    using inclosed_map = std::unordered_map<std::string, std::pair<Expression, Type>>;
    using regular_data_block = std::pair<Expression, Type>;
    struct DataBlock {
        std::variant<std::monostate, regular_data_block, inclosed_map> value;
        bool is_inclosed_map() const { return std::holds_alternative<inclosed_map>(value); };
        bool is_raw_expr() const { return std::holds_alternative<regular_data_block>(value); };
        bool empty() const { return std::holds_alternative<std::monostate>(value); };
        regular_data_block &getRegularDataBlock() { return std::get<regular_data_block>(value); };
        inclosed_map &getInclosedMap() { return std::get<inclosed_map>(value); };
        const regular_data_block &getRegularDataBlock() const { return std::get<regular_data_block>(value); };
        const inclosed_map &getInclosedMap() const { return std::get<inclosed_map>(value); };
    };
    struct ExportsAfterBuild {
        Variable svar;
        Variable uvar;
        Variable var;
        Variable shadow_var;
        char quantifier;
    };
    struct Production {
        DataBlock block;
        stdu::vector<std::string> name;
        Statements members;
    };
    using DataBlockList = utype::unordered_map<stdu::vector<std::string>, DataBlock>;
}