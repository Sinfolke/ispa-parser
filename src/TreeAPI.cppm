module;
#include <string>
#include <unordered_map>
#include <variant>
#include <any>
export module TreeAPI;
import logging;
import hash;
export namespace TreeAPI {
    // forward declarations
    struct CllType;
    struct CllFunctionArguments;
    struct CllFunctionParameters;
    struct CllExpr;
    struct CllExprGroup;
    struct CllExprCompare;
    struct CllExprAddition;
    struct CllExprTerm;
    struct CllExprValue;
    struct CllExprLogical;
    struct CllExprLogicalPart;
    struct CllVariable;
    struct rvalue;
    struct RuleMember;
    using CllFunctionBodyCall = CllFunctionArguments;
    using CllFunctionBodyDecl = CllFunctionParameters;

    struct String {
        std::string value;
        static size_t count_strlen(const std::string &str);
        static std::string format_str(std::string str);
        size_t count_strlen() const;
        std::string format_str() const;
    };

    struct Number {
        char sign = '\0';
        std::string main;
        std::string dec;
        std::string getFull() const;
        bool hasDec() const;
        bool hasSign() const;
        double getFullNumber() const;
        unsigned getMain() const;
        unsigned getDecimal() const;
    };

    struct Boolean {
        std::string value;
        bool getBoolean() const;
    };

    struct Array {
        std::vector<CllExpr> value;
    };

    struct Object {
        std::unordered_map<std::string, CllExpr> value;
    };

    struct At {};

    struct ID {
        std::string value;
    };

    struct rvalue {
        std::variant<String, Number, Boolean, Array, Object, At, ID> value;
        bool isString() const;
        bool isNumber() const;
        bool isBoolean() const;
        bool isArray() const;
        bool isObject() const;
        bool isAt() const;
        bool isID() const;
        String &getString();
        Number &getNumber();
        Boolean &getBoolean();
        Array &getArray();
        Object &getObject();
        ID &getID();
        const String& getString() const;
        const Number& getNumber() const;
        const Boolean& getBoolean() const;
        const Array& getArray() const;
        const Object& getObject() const;
        const ID& getID() const;
    };

    struct CllCompareOp {
        std::string op;
    };

    struct CllLogicalOp {
        bool isAnd;
    };

    struct CllType {
        std::string type;
        std::vector<CllType> templ;
    };

    struct CllFunctionArguments {
        std::vector<CllExpr> expr;
    };

    struct CllFunctionParameters {
        std::vector<std::string> names;
    };

    struct CllFunctionCall {
        std::string name;
        CllFunctionBodyCall body;
    };

    struct CllFunctionDecl {
        std::string name;
        CllFunctionBodyDecl body;
    };
    struct CllMethodCall {
        std::string name;
        CllFunctionCall body;
    };
    struct CllExprValue {
        std::any value;
        bool isGroup() const;
        bool isVariable() const;
        bool isFunctionCall() const;
        bool isMethodCall() const;
        bool isrvalue() const;
        CllExprGroup &getGroup();
        CllVariable &getVariable();
        CllFunctionCall &getFunctionCall();
        CllMethodCall &getMethodCall();
        rvalue &getrvalue();
        const CllExpr &getGroup() const;
        const CllVariable &getVariable() const;
        const CllFunctionCall &getFunctionCall() const;
        const CllMethodCall &getMethodCall() const;
        const rvalue &getrvalue() const;
    };

    struct CllExprTerm {
        CllExprValue value;
        std::vector<std::pair<char, CllExprValue>> rights;
    };

    struct CllExprAddition {
        CllExprTerm value;
        std::vector<std::pair<char, CllExprTerm>> rights;
    };

    struct CllExprCompare {
        CllExprAddition value;
        std::vector<std::pair<CllCompareOp, CllExprAddition>> rights;
    };

    struct CllExprLogical {
        CllExprCompare value;
        std::vector<std::pair<CllLogicalOp, CllExprCompare>> rights;
    };

    struct CllExpr {
        CllExprLogical value;
    };
    struct CllExprGroup {
        CllExpr expr;
    };
    struct CllVariable {
        std::optional<char> pre_increament;
        std::optional<char> post_increament;
        std::string name;
        std::optional<CllExpr> braceExpression;
    };

    struct CllIf {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    };

    struct CllVar {
        CllType type;
        std::string name;
        char op = '\0';
        CllExpr value;
    };

    struct CllLoopWhile {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    };

    struct CllLoopFor {};

    struct Cll {
        std::variant<CllVar, CllIf, CllExpr> value;
        bool isVar() const;
        bool isIf() const;
        bool isExpr() const;
        CllVar &getVar();
        CllIf &getIf();
        CllExpr &getExpr();
        const CllVar &getVar() const;
        const CllIf &getIf() const;
        const CllExpr &getExpr() const;
    };

    struct RulePrefix {
        bool is_key_value = false;
        std::string name;
        void clear();
        bool empty() const;
    };

    struct RuleMemberName {
        std::vector<std::string> name;
        bool isAutoGenerated = false;
    };

    struct RuleMemberGroup {
        std::vector<RuleMember> values;
    };

    struct RuleMemberOp {
        std::vector<RuleMember> options;
    };

    struct RuleMemberCsequence {
        bool negative = false;
        std::vector<char> characters;
        std::vector<char> escaped;
        std::vector<std::pair<char, char>> diapasons;
    };

    struct RuleMemberAny {};

    struct RuleMemberNospace {};

    struct RuleMemberEscaped {
        char c;
    };

    struct RuleMemberHex {
        std::string hex_chars;
        std::string::iterator begin();
        std::string::iterator end();
    };

    struct RuleMemberBin {
        std::string bin_chars;
        std::string::iterator begin();
        std::string::iterator end();
    };

    struct RuleMember {
        RulePrefix prefix;
        char quantifier = '\0';
        bool isAutoGenerated = false;
        bool isInline = false;
        std::variant<std::monostate, String, RuleMemberName, RuleMemberGroup, RuleMemberOp, RuleMemberCsequence, RuleMemberAny, RuleMemberNospace, RuleMemberEscaped, RuleMemberHex, RuleMemberBin, Cll> value;

        bool isString() const;
        bool isName() const;
        bool isGroup() const;
        bool isOp() const;
        bool isCsequence() const;
        bool isAny() const;
        bool isNospace() const;
        bool isEscaped() const;
        bool isHex() const;
        bool isBin() const;
        bool isCll() const;
        bool emptyQuantifier() const;
        bool empty() const;
        // Non-const overloads
        String& getString();
        RuleMemberName& getName();
        RuleMemberGroup& getGroup();
        RuleMemberOp& getOp();
        RuleMemberCsequence& getCsequence();
        RuleMemberEscaped& getEscaped();
        RuleMemberHex& getHex();
        RuleMemberBin& getBin();
        Cll& getCll();

        // Const overloads
        const String& getString() const;
        const RuleMemberName& getName() const;
        const RuleMemberGroup& getGroup() const;
        const RuleMemberOp& getOp() const;
        const RuleMemberCsequence& getCsequence() const;
        const RuleMemberEscaped& getEscaped() const;
        const RuleMemberHex& getHex() const;
        const RuleMemberBin& getBin() const;
        const Cll& getCll() const;
        bool fullCompare(const RuleMember &second);
    };
    struct RuleMemberKey {
        RuleMember base;
    };
    struct RegularDataBlockWKeys {
        std::unordered_map<std::string, CllExpr> value;

        bool empty() const;
        std::unordered_map<std::string, CllExpr>::iterator begin();
        std::unordered_map<std::string, CllExpr>::iterator end();
        CllExpr &operator[](const std::string &name);
    };

    using RegularDataBlock = CllExpr;

    struct TemplatedDataBlock {
        std::vector<std::string> names;

        bool empty() const;
        std::vector<std::string>::iterator begin();
        std::vector<std::string>::iterator end();
    };

    struct DataBlock {
        std::variant<std::monostate, RegularDataBlock, RegularDataBlockWKeys, TemplatedDataBlock> value;
        bool isRegularDataBlock() const;
        bool isWithKeys() const;
        bool isTemplatedDataBlock() const;
        bool empty() const;
        RegularDataBlock &getRegDataBlock();
        RegularDataBlockWKeys &getRegDataBlockWKeys();
        TemplatedDataBlock &getTemplatedDataBlock();
        const RegularDataBlock &getRegDataBlock() const;
        const RegularDataBlockWKeys &getRegDataBlockWKeys() const;
        const TemplatedDataBlock &getTemplatedDataBlock() const;
    };

    struct Rule {
        std::vector<TreeAPI::RuleMember> members;
        TreeAPI::DataBlock data_block;
    };

    // Define operator== outside structures
    bool operator==(const String &lhs, const String &rhs);
    bool operator==(const Number &lhs, const Number &rhs);
    bool operator==(const Boolean &lhs, const Boolean &rhs);
    bool operator==(const Array &lhs, const Array &rhs);
    bool operator==(const Object &lhs, const Object &rhs);
    bool operator==(const ID &lhs, const ID &rhs);
    bool operator==(const rvalue &lhs, const rvalue &rhs);
    bool operator==(const CllCompareOp &lhs, const CllCompareOp &rhs);
    bool operator==(const CllLogicalOp &lhs, const CllLogicalOp &rhs);
    bool operator==(const CllType &lhs, const CllType &rhs);
    bool operator==(const CllFunctionArguments &lhs, const CllFunctionArguments &rhs);
    bool operator==(const CllFunctionParameters &lhs, const CllFunctionParameters &rhs);
    bool operator==(const CllFunctionCall &lhs, const CllFunctionCall &rhs);
    bool operator==(const CllFunctionDecl &lhs, const CllFunctionDecl &rhs);
    bool operator==(const CllExprValue &lhs, const CllExprValue &rhs);
    bool operator==(const CllExprTerm &lhs, const CllExprTerm &rhs);
    bool operator==(const CllExprAddition &lhs, const CllExprAddition &rhs);
    bool operator==(const CllExprCompare &lhs, const CllExprCompare &rhs);
    bool operator==(const CllExprLogical &lhs, const CllExprLogical &rhs);
    bool operator==(const CllExpr &lhs, const CllExpr &rhs);
    bool operator==(const CllVariable &lhs, const CllVariable &rhs);
    bool operator==(const CllIf &lhs, const CllIf &rhs);
    bool operator==(const CllVar &lhs, const CllVar &rhs);
    bool operator==(const CllLoopWhile &lhs, const CllLoopWhile &rhs);
    bool operator==(const Cll &first, const Cll &second);
    bool operator==(const RulePrefix &lhs, const RulePrefix &rhs);
    bool operator==(const RuleMemberName &lhs, const RuleMemberName &rhs);
    bool operator==(const RuleMemberGroup &lhs, const RuleMemberGroup &rhs);
    bool operator==(const RuleMemberOp &lhs, const RuleMemberOp &rhs);
    bool operator==(const RuleMemberCsequence &lhs, const RuleMemberCsequence &rhs);
    bool operator==(const RuleMemberAny &lhs, const RuleMemberAny &rhs);
    bool operator==(const RuleMemberNospace &lhs, const RuleMemberNospace &rhs);
    bool operator==(const RuleMemberEscaped &lhs, const RuleMemberEscaped &rhs);
    bool operator==(const RuleMemberHex &lhs, const RuleMemberHex &rhs);
    bool operator==(const RuleMemberBin &lhs, const RuleMemberBin &rhs);
    bool operator==(const RuleMember &lhs, const RuleMember &rhs);
    bool operator==(const RuleMemberKey &lhs, const RuleMemberKey &rhs);
    bool operator==(const RegularDataBlockWKeys &lhs, const RegularDataBlockWKeys &rhs);
    bool operator==(const TemplatedDataBlock &lhs, const TemplatedDataBlock &rhs);
    bool operator==(const DataBlock &lhs, const DataBlock &rhs);
    bool operator==(const Rule &lhs, const Rule &rhs);
    std::ostream& operator<<(std::ostream& os, const RulePrefix& prefix);
    std::ostream& operator<<(std::ostream& os, const RuleMemberName& name);
    std::ostream& operator<<(std::ostream& os, const RuleMemberGroup& group);
    std::ostream& operator<<(std::ostream& os, const RuleMemberOp& op);
    std::ostream& operator<<(std::ostream& os, const RuleMemberCsequence& cs);
    std::ostream& operator<<(std::ostream& os, const RuleMemberAny& any);
    std::ostream& operator<<(std::ostream& os, const RuleMemberNospace& ns);
    std::ostream& operator<<(std::ostream& os, const RuleMemberEscaped& esc);
    std::ostream& operator<<(std::ostream& os, const RuleMemberHex& hex);
    std::ostream& operator<<(std::ostream& os, const RuleMemberBin& bin);
    std::ostream& operator<<(std::ostream& os, const String& str);
    std::ostream& operator<<(std::ostream& os, const Cll& str);
    std::ostream& operator<<(std::ostream& os, const RuleMember& member);
    std::ostream& operator<<(std::ostream& os, const RegularDataBlockWKeys& block);
    std::ostream& operator<<(std::ostream& os, const TemplatedDataBlock& block);
    std::ostream& operator<<(std::ostream& os, const DataBlock& block);
    std::ostream& operator<<(std::ostream& os, const Rule& rule);
    CllExpr make_expr_from_value(const TreeAPI::CllExprValue& val);
};

namespace std {
    // Hash specialization for TreeAPI::CllCompareOp
    template<> struct hash<TreeAPI::CllCompareOp>;
    template<> struct hash<TreeAPI::CllLogicalOp>;
    template<> struct hash<TreeAPI::CllType>;
    template<> struct hash<TreeAPI::CllExpr>;
    template<> struct hash<TreeAPI::CllExprGroup>;
    template<> struct hash<TreeAPI::CllExprLogical>;
    template<> struct hash<TreeAPI::CllExprCompare>;
    template<> struct hash<TreeAPI::CllExprAddition>;
    template<> struct hash<TreeAPI::CllExprTerm>;
    template<> struct hash<TreeAPI::CllExprValue>;
    template<> struct hash<TreeAPI::CllVariable>;
    template<> struct hash<TreeAPI::CllIf>;
    template<> struct hash<TreeAPI::CllVar>;
    template<> struct hash<TreeAPI::CllLoopWhile>;
    template<> struct hash<TreeAPI::Cll>;
    template<> struct hash<TreeAPI::RulePrefix>;
    template<> struct hash<TreeAPI::RuleMemberName>;
    template<> struct hash<TreeAPI::RuleMemberOp>;
    template<> struct hash<TreeAPI::RuleMemberCsequence>;
    template<> struct hash<TreeAPI::RuleMemberEscaped>;
    template<> struct hash<TreeAPI::RuleMemberHex>;
    template<> struct hash<TreeAPI::RuleMemberBin>;
    template<> struct hash<TreeAPI::RuleMember>;
    template<> struct hash<TreeAPI::RegularDataBlockWKeys>;
    template<> struct hash<TreeAPI::TemplatedDataBlock>;
    template<> struct hash<TreeAPI::DataBlock>;
    template<> struct hash<TreeAPI::Rule>;
    template<> struct hash<TreeAPI::String>;
    template<> struct hash<TreeAPI::Number>;
    template<> struct hash<TreeAPI::Boolean>;
    template<> struct hash<TreeAPI::Array>;
    template<> struct hash<TreeAPI::Object>;
    template<> struct hash<TreeAPI::At>;
    template<> struct hash<TreeAPI::ID>;
    // Hash specialization for TreeAPI::CllCompareOp
    template <>
    struct hash<TreeAPI::CllCompareOp> {
        std::size_t operator()(const TreeAPI::CllCompareOp& op) const {
            std::size_t seed = 0;
            // Hash the 'op' string
            hash_combine(seed, std::hash<std::string>{}(op.op));
            return seed;
        }
    };

    // Hash specialization for TreeAPI::CllLogicalOp
    template <>
    struct hash<TreeAPI::CllLogicalOp> {
        std::size_t operator()(const TreeAPI::CllLogicalOp& op) const {
            std::size_t seed = 0;
            // Hash the 'isAnd' boolean value
            hash_combine(seed, std::hash<bool>{}(op.isAnd));
            return seed;
        }
    };
    template <>
    struct hash<TreeAPI::CllType> {
        std::size_t operator()(const TreeAPI::CllType& cll) const {
            std::size_t seed = 0;
            // Hash the type string
            hash_combine(seed, std::hash<std::string>{}(cll.type));

            // Hash the templ vector recursively
            for (const auto& t : cll.templ) {
                hash_combine(seed, std::hash<TreeAPI::CllType>{}(t));
            }

            return seed;
        }
    };
    template <>
    struct hash<TreeAPI::CllExprValue> {
        std::size_t operator()(const TreeAPI::CllExprValue& v) const {
            if (v.isGroup()) return std::hash<const void*>{}(static_cast<const void*>(&v.getGroup()));
            if (v.isVariable()) return std::hash<const void*>{}(static_cast<const void*>(&v.getVariable()));
            if (v.isFunctionCall()) return std::hash<const void*>{}(static_cast<const void*>(&v.getFunctionCall()));
            if (v.isMethodCall()) return std::hash<const void*>{}(static_cast<const void*>(&v.getMethodCall()));
            if (v.isrvalue()) return std::hash<const void*>{}(static_cast<const void*>(&v.getrvalue()));
            return 0;
        }
    };


    template <>
    struct hash<TreeAPI::CllExprTerm> {
        std::size_t operator()(const TreeAPI::CllExprTerm& t) const {
            std::size_t seed = std::hash<TreeAPI::CllExprValue>{}(t.value);
            for (const auto& [op, rhs] : t.rights) {
                hash_combine(seed, std::hash<char>{}(op),
                                   std::hash<TreeAPI::CllExprValue>{}(rhs));
            }
            return seed;
        }
    };


    template <>
    struct hash<TreeAPI::CllExprAddition> {
        std::size_t operator()(const TreeAPI::CllExprAddition& a) const {
            std::size_t seed = std::hash<TreeAPI::CllExprTerm>{}(a.value);
            for (const auto& [op, rhs] : a.rights) {
                hash_combine(seed, std::hash<char>{}(op),
                                   std::hash<TreeAPI::CllExprTerm>{}(rhs));
            }
            return seed;
        }
    };


    template <>
    struct hash<TreeAPI::CllExprCompare> {
        std::size_t operator()(const TreeAPI::CllExprCompare& c) const {
            std::size_t seed = std::hash<TreeAPI::CllExprAddition>{}(c.value);
            for (const auto& [op, rhs] : c.rights) {
                hash_combine(seed, std::hash<TreeAPI::CllCompareOp>{}(op),
                                   std::hash<TreeAPI::CllExprAddition>{}(rhs));
            }
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::CllExprLogical> {
        std::size_t operator()(const TreeAPI::CllExprLogical& l) const {
            std::size_t seed = std::hash<TreeAPI::CllExprCompare>{}(l.value);
            for (const auto& [op, rhs] : l.rights) {
                hash_combine(seed, std::hash<TreeAPI::CllLogicalOp>{}(op),
                                   std::hash<TreeAPI::CllExprCompare>{}(rhs));
            }
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::CllExpr> {
        std::size_t operator()(const TreeAPI::CllExpr& e) const {
            return std::hash<TreeAPI::CllExprLogical>{}(e.value);
        }
    };



    template <>
    struct hash<TreeAPI::CllExprGroup> {
        std::size_t operator()(const TreeAPI::CllExprGroup& g) const {
            return std::hash<TreeAPI::CllExpr>{}(g.expr);
        }
    };
    // Hash for RulePrefix
    template <>
    struct hash<TreeAPI::RulePrefix> {
        std::size_t operator()(const TreeAPI::RulePrefix& prefix) const {
            std::size_t seed = 0;
            hash_combine(seed, prefix.is_key_value);
            hash_combine(seed, std::hash<std::string>{}(prefix.name));
            return seed;
        }
    };

    // Hash for RuleMemberName
    template <>
    struct hash<TreeAPI::RuleMemberName> {
        std::size_t operator()(const TreeAPI::RuleMemberName& name) const {
            std::size_t seed = 0;
            for (const auto& n : name.name) {
                hash_combine(seed, std::hash<std::string>{}(n));
            }
            hash_combine(seed, name.isAutoGenerated);
            return seed;
        }
    };


    // Hash for RuleMemberCsequence
    template <>
    struct hash<TreeAPI::RuleMemberCsequence> {
        std::size_t operator()(const TreeAPI::RuleMemberCsequence& cseq) const {
            std::size_t seed = 0;
            hash_combine(seed, cseq.negative);
            for (const auto& character : cseq.characters) {
                hash_combine(seed, std::hash<char>{}(character));
            }
            for (const auto& escaped : cseq.escaped) {
                hash_combine(seed, std::hash<char>{}(escaped));
            }
            for (const auto& diapason : cseq.diapasons) {
                hash_combine(seed, std::hash<char>{}(diapason.first));
                hash_combine(seed, std::hash<char>{}(diapason.second));
            }
            return seed;
        }
    };

    // Hash for RuleMemberEscaped
    template <>
    struct hash<TreeAPI::RuleMemberEscaped> {
        std::size_t operator()(const TreeAPI::RuleMemberEscaped& escaped) const {
            return std::hash<char>{}(escaped.c);
        }
    };

    // Hash for RuleMemberHex
    template <>
    struct hash<TreeAPI::RuleMemberHex> {
        std::size_t operator()(const TreeAPI::RuleMemberHex& hex) const {
            std::size_t seed = 0;
            for (const auto& hex_char : hex.hex_chars) {
                hash_combine(seed, std::hash<char>{}(hex_char));
            }
            return seed;
        }
    };

    // Hash for RuleMemberBin
    template <>
    struct hash<TreeAPI::RuleMemberBin> {
        std::size_t operator()(const TreeAPI::RuleMemberBin& bin) const {
            std::size_t seed = 0;
            for (const auto& bin_char : bin.bin_chars) {
                hash_combine(seed, std::hash<char>{}(bin_char));
            }
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::String> {
        std::size_t operator()(const TreeAPI::String& s) const {
            return std::hash<std::string>{}(s.value);
        }
    };
    // Hash for RuleMember
    template <>
    struct hash<TreeAPI::RuleMember> {
        std::size_t operator()(const TreeAPI::RuleMember& member) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::RulePrefix>{}(member.prefix));
            hash_combine(seed, std::hash<char>{}(member.quantifier));
            hash_combine(seed, member.isAutoGenerated);
            hash_combine(seed, member.isInline);

            // Handle the variant
            if (member.isString()) {
                hash_combine(seed, std::hash<TreeAPI::String>{}(member.getString()));
            } else if (member.isName()) {
                hash_combine(seed, std::hash<TreeAPI::RuleMemberName>{}(member.getName()));
            } else if (member.isGroup()) {
                for (const auto& value : member.getGroup().values) {
                    hash_combine(seed, std::hash<TreeAPI::RuleMember>{}(value));
                }
            } else if (member.isOp()) {
                for (const auto& option : member.getOp().options) {
                    hash_combine(seed, std::hash<TreeAPI::RuleMember>{}(option));
                }
            } else if (member.isCsequence()) {
                hash_combine(seed, std::hash<TreeAPI::RuleMemberCsequence>{}(member.getCsequence()));
            } else if (member.isAny()) {
                // Hash nothing for RuleMemberAny as it doesn't have data
            } else if (member.isNospace()) {
                // Hash nothing for RuleMemberNospace as it doesn't have data
            } else if (member.isEscaped()) {
                hash_combine(seed, std::hash<TreeAPI::RuleMemberEscaped>{}(member.getEscaped()));
            } else if (member.isHex()) {
                hash_combine(seed, std::hash<TreeAPI::RuleMemberHex>{}(member.getHex()));
            } else if (member.isBin()) {
                hash_combine(seed, std::hash<TreeAPI::RuleMemberBin>{}(member.getBin()));
            } else if (member.isCll()) {
                const auto &cll = member.getCll();

                // Inlined Cll handling to keep hash consistent
                if (cll.isExpr()) {
                    hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(cll.getExpr()));
                } else if (cll.isIf()) {
                    const auto &i = cll.getIf();
                    hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(i.expr));
                    for (const auto& stmt : i.stmt) {
                        hash_combine(seed, std::hash<TreeAPI::RuleMember>{}(stmt));
                    }
                } else if (cll.isVar()) {
                    const auto &v = cll.getVar();
                    hash_combine(seed, std::hash<TreeAPI::CllType>{}(v.type));
                    hash_combine(seed, std::hash<std::string>{}(v.name));
                    hash_combine(seed, std::hash<char>{}(v.op));
                    hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(v.value));
                }
            }
            return seed;
        }
    };
    template <>
    struct hash<TreeAPI::RuleMemberKey> {
        size_t operator()(const TreeAPI::RuleMemberKey& key) const {
            TreeAPI::RuleMember copy = key.base;
            copy.quantifier = '\0';
            return std::hash<TreeAPI::RuleMember>{}(copy);
        }
    };
    // Hash for RuleMemberOp
    template <>
    struct hash<TreeAPI::RuleMemberOp> {
        std::size_t operator()(const TreeAPI::RuleMemberOp& op) const {
            std::size_t seed = 0;
            for (const auto& option : op.options) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>{}(option));
            }
            return seed;
        }
    };
    // Hash for RegularDataBlockWKeys
    template <>
    struct hash<TreeAPI::RegularDataBlockWKeys> {
        std::size_t operator()(const TreeAPI::RegularDataBlockWKeys& block) const {
            std::size_t seed = 0;
            for (const auto& [key, value] : block.value) {
                hash_combine(seed, std::hash<std::string>{}(key));
                hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(value));
            }
            return seed;
        }
    };

    // Hash for TemplatedDataBlock
    template <>
    struct hash<TreeAPI::TemplatedDataBlock> {
        std::size_t operator()(const TreeAPI::TemplatedDataBlock& block) const {
            std::size_t seed = 0;
            for (const auto& name : block.names) {
                hash_combine(seed, std::hash<std::string>{}(name));
            }
            return seed;
        }
    };

    // Hash for DataBlock
    template <>
    struct hash<TreeAPI::DataBlock> {
        std::size_t operator()(const TreeAPI::DataBlock& block) const {
            std::size_t seed = 0;
            if (block.isRegularDataBlock()) {
                hash_combine(seed, std::hash<TreeAPI::RegularDataBlock>{}(block.getRegDataBlock()));
            } else if (block.isWithKeys()) {
                hash_combine(seed, std::hash<TreeAPI::RegularDataBlockWKeys>{}(block.getRegDataBlockWKeys()));
            } else if (block.isTemplatedDataBlock()) {
                hash_combine(seed, std::hash<TreeAPI::TemplatedDataBlock>{}(block.getTemplatedDataBlock()));
            }
            return seed;
        }
    };

    // Hash for Rule
    template <>
    struct hash<TreeAPI::Rule> {
        std::size_t operator()(const TreeAPI::Rule& rule) const {
            std::size_t seed = 0;
            for (const auto& member : rule.members) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>{}(member));
            }
            hash_combine(seed, std::hash<TreeAPI::DataBlock>{}(rule.data_block));
            return seed;
        }
    };
    template <>
    struct hash<TreeAPI::CllVariable> {
        std::size_t operator()(const TreeAPI::CllVariable& v) const {
            std::size_t seed = 0;
            hash_combine(seed, v.pre_increament.has_value());
            hash_combine(seed, v.post_increament.has_value());
            hash_combine(seed, std::hash<std::string>{}(v.name));
            if (v.braceExpression) {
                hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(*v.braceExpression));
            }
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::CllIf> {
        std::size_t operator()(const TreeAPI::CllIf& i) const {
            std::size_t seed = std::hash<TreeAPI::CllExpr>{}(i.expr);
            for (const auto& stmt : i.stmt) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>{}(stmt));
            }
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::CllVar> {
        std::size_t operator()(const TreeAPI::CllVar& v) const {
            std::size_t seed = std::hash<TreeAPI::CllType>{}(v.type);
            hash_combine(seed, std::hash<std::string>{}(v.name));
            hash_combine(seed, std::hash<char>{}(v.op));
            hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(v.value));
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::CllLoopWhile> {
        std::size_t operator()(const TreeAPI::CllLoopWhile& lw) const {
            std::size_t seed = std::hash<TreeAPI::CllExpr>{}(lw.expr);
            for (const auto& stmt : lw.stmt) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>{}(stmt));
            }
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::Cll> {
        std::size_t operator()(const TreeAPI::Cll& c) const {
            std::size_t seed = 0;
            if (c.isVar()) {
                hash_combine(seed, std::hash<TreeAPI::CllVar>{}(c.getVar()));
            } else if (c.isIf()) {
                hash_combine(seed, std::hash<TreeAPI::CllIf>{}(c.getIf()));
            } else if (c.isExpr()) {
                hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(c.getExpr()));
            }
            return seed;
        }
    };


    template <>
    struct hash<TreeAPI::Number> {
        std::size_t operator()(const TreeAPI::Number& n) const {
            std::size_t seed = 0;
            hash_combine(seed, n.sign, n.main, n.dec);
            return seed;
        }
    };
    template <>
    struct hash<TreeAPI::Boolean> {
        std::size_t operator()(const TreeAPI::Boolean& b) const {
            return std::hash<std::string>{}(b.value);
        }
    };

    template <>
    struct hash<TreeAPI::Array> {
        std::size_t operator()(const TreeAPI::Array& a) const {
            std::size_t seed = 0;
            for (const auto& val : a.value)
                hash_combine(seed, std::hash<TreeAPI::CllExpr>{}(val));
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::Object> {
        std::size_t operator()(const TreeAPI::Object& o) const {
            std::size_t seed = 0;
            for (const auto& [k, v] : o.value)
                hash_combine(seed, std::hash<std::string>{}(k), std::hash<TreeAPI::CllExpr>{}(v));
            return seed;
        }
    };

    template <>
    struct hash<TreeAPI::At> {
        std::size_t operator()(const TreeAPI::At&) const {
            return 0x13371337;  // arbitrary constant
        }
    };

    template <>
    struct hash<TreeAPI::ID> {
        std::size_t operator()(const TreeAPI::ID& id) const {
            return std::hash<std::string>{}(id.value);
        }
    };

    
} // namespace std
