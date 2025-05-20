export module TreeAPI;
import logging;
import hash;
import std;
import std.compat;
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

    struct String : Hashable {
        std::string value;
        static size_t count_strlen(const std::string &str);
        static std::string format_str(std::string str);
        size_t count_strlen() const;
        std::string format_str() const;
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct Number : Hashable {
        char sign = '\0';
        std::string main;
        std::string dec;
        std::string getFull() const;
        bool hasDec() const;
        bool hasSign() const;
        double getFullNumber() const;
        unsigned getMain() const;
        unsigned getDecimal() const;
    private:
        auto members() {
            return std::tie(sign, main, dec);
        }
    };

    struct Boolean : Hashable {
        std::string value;
        bool getBoolean() const;
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct Array : Hashable {
        std::vector<CllExpr> value;
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct Object : Hashable {
        std::unordered_map<std::string, CllExpr> value;
        auto members() {
            return std::tie(value);
        }
    };

    struct At : EmptyHashable {};

    struct ID : Hashable {
        std::string value;
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct rvalue : Hashable {
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
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct CllCompareOp : Hashable {
        std::string op;
    private:
        auto members() {
            return std::tie(op);
        }
    };

    struct CllLogicalOp : Hashable {
        bool isAnd;
    private:
        auto members() {
            return std::tie(isAnd);
        }
    };

    struct CllType : Hashable {
        std::string type;
        std::vector<CllType> templ;
    private:
        auto members() {
            return std::tie(type, templ);
        }
    };

    struct CllFunctionArguments : Hashable {
        std::vector<CllExpr> expr;
    private:
        auto members() {
            return std::tie(expr);
        }
    };

    struct CllFunctionParameters : Hashable {
        std::vector<std::string> names;
    private:
        auto members() {
            return std::tie(names);
        }
    };

    struct CllFunctionCall : Hashable {
        std::string name;
        CllFunctionBodyCall body;
    private:
        auto members() {
            return std::tie(name, body);
        }
    };

    struct CllFunctionDecl : Hashable {
        std::string name;
        CllFunctionBodyDecl body;
        auto members() {
            return std::tie(name, body);
        }
    };
    struct CllMethodCall : Hashable {
        std::string name;
        CllFunctionCall body;
    private:
        auto members() {
            return std::tie(name, body);
        }
    };
    struct CllExprValue : Hashable {
        std::variant<std::shared_ptr<CllExprGroup>, std::shared_ptr<CllVariable>, CllFunctionCall, CllMethodCall, rvalue> value;
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
        const CllExprGroup &getGroup() const;
        const CllVariable &getVariable() const;
        const CllFunctionCall &getFunctionCall() const;
        const CllMethodCall &getMethodCall() const;
        const rvalue &getrvalue() const;
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct CllExprTerm : Hashable {
        CllExprValue value;
        std::vector<std::pair<char, CllExprValue>> rights;
    private:
        auto members() {
            return std::tie(value, rights);
        }
    };

    struct CllExprAddition : Hashable {
        CllExprTerm value;
        std::vector<std::pair<char, CllExprTerm>> rights;
    private:
        auto members() {
            return std::tie(value, rights);
        }
    };

    struct CllExprCompare : Hashable {
        CllExprAddition value;
        std::vector<std::pair<CllCompareOp, CllExprAddition>> rights;
    private:
        auto members() {}
    };

    struct CllExprLogical : Hashable {
        CllExprCompare value;
        std::vector<std::pair<CllLogicalOp, CllExprCompare>> rights;
    private:
        auto members() {
            return std::tie(value, rights);
        }
    };

    struct CllExpr : Hashable {
        CllExprLogical value;
    private:
        auto members() {
            return std::tie(value);
        }
    };
    struct CllExprGroup : Hashable {
        CllExpr expr;
    private:
        auto members() {
            return std::tie(expr);
        }
    };
    struct CllVariable : Hashable {
        std::optional<char> pre_increament;
        std::optional<char> post_increament;
        std::string name;
        std::optional<CllExpr> braceExpression;
    private:
        auto members() {
            std::tie(pre_increament, post_increament, name, braceExpression);
        }
    };

    struct CllIf : Hashable {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    private:
        auto members() {
            return std::tie(expr, stmt);
        }
    };

    struct CllVar : Hashable {
        CllType type;
        std::string name;
        char op = '\0';
        CllExpr value;
    private:
        auto members() {
            return std::tie(type, name, op, value);
        }
    };

    struct CllLoopWhile : Hashable {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    private:
        auto members() {
            return std::tie(expr, stmt);
        }
    };

    struct CllLoopFor : EmptyHashable {};

    struct Cll : Hashable {
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
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct RulePrefix : Hashable {
        bool is_key_value = false;
        std::string name;
        void clear();
        bool empty() const;
    private:
        auto members() {
            return std::tie(is_key_value, name);
        }
    };

    struct RuleMemberName : Hashable {
        std::vector<std::string> name;
        bool isAutoGenerated = false;
    private:
        auto members() {
            return std::tie(name, isAutoGenerated);
        }
    };

    struct RuleMemberGroup : Hashable {
        std::vector<RuleMember> values;
    private:
        auto members() {
            return std::tie(values);
        }
    };

    struct RuleMemberOp : Hashable {
        std::vector<RuleMember> options;
    private:
        auto members() {
            return std::tie(options);
        }
    };

    struct RuleMemberCsequence : Hashable {
        bool negative = false;
        std::vector<char> characters;
        std::vector<char> escaped;
        std::vector<std::pair<char, char>> diapasons;
    private:
        auto members() {
            return std::tie(negative, characters, escaped, diapasons);
        }
    };

    struct RuleMemberAny : EmptyHashable {};

    struct RuleMemberNospace : EmptyHashable {};

    struct RuleMemberEscaped : Hashable {
        char c;
    private:
        auto members() {
            return std::tie(c);
        }
    };

    // these structure are hashable by begin and end methods
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

    struct RuleMember : Hashable {
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
    private:
        auto members() {
            return std::tie(value);
        }
    };
    struct RuleMemberKey : Hashable {
        RuleMember base;
    private:
        auto members() {
            return std::tie(base);
        }
    };
    struct RegularDataBlockWKeys : Hashable {
        std::unordered_map<std::string, CllExpr> value;

        bool empty() const;
        std::unordered_map<std::string, CllExpr>::iterator begin();
        std::unordered_map<std::string, CllExpr>::iterator end();
        CllExpr &operator[](const std::string &name);
    private:
        auto members() {
            return std::tie(value);
        }
    };

    using RegularDataBlock = CllExpr;

    struct TemplatedDataBlock {
        std::vector<std::string> names;

        bool empty() const;
        std::vector<std::string>::iterator begin();
        std::vector<std::string>::iterator end();
    };

    struct DataBlock : Hashable {
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
    private:
        auto members() {
            return std::tie(value);
        }
    };

    struct Rule : Hashable {
        std::vector<TreeAPI::RuleMember> rule_members;
        TreeAPI::DataBlock data_block;
    private:
        auto members() {
            return std::tie(rule_members, data_block);
        }
    };
    // helper functions
    CllExpr make_expr_from_value(const TreeAPI::CllExprValue& val);

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
    bool operator==(const CllMethodCall &lhs, const CllMethodCall &rhs);
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
};