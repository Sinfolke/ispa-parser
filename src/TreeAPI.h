#pragma once

#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <variant>
#include <memory>
#include <type_traits>
#include <optional>
#include <Parser.h>
#include <logging.h>
#include <hash.h>
namespace TreeAPI {
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
        std::vector<CllExpr> &getArray();
        std::unordered_map<std::string, CllExpr> &getObject();
        std::string &getID();
        const String& getString() const;
        const Number& getNumber() const;
        const Boolean& getBoolean() const;
        const std::vector<CllExpr>& getArray() const;
        const std::unordered_map<std::string, CllExpr>& getObject() const;
        const std::string& getID() const;
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
        bool is_key_value;
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
        RuleMemberEscaped(char c) : c(c) {}
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
        decltype(RuleMemberGroup::values)& getGroup();
        decltype(RuleMemberOp::options)& getOp();
        RuleMemberCsequence& getCsequence();
        decltype(RuleMemberEscaped::c)& getEscaped();
        RuleMemberHex& getHex();
        RuleMemberBin& getBin();
        Cll& getCll();

        // Const overloads
        const String& getString() const;
        const RuleMemberName& getName() const;
        const decltype(RuleMemberGroup::values)& getGroup() const;
        const decltype(RuleMemberOp::options)& getOp() const;
        const RuleMemberCsequence& getCsequence() const;
        const decltype(RuleMemberEscaped::c)& getEscaped() const;
        const RuleMemberHex& getHex() const;
        const RuleMemberBin& getBin() const;
        const Cll& getCll() const;
        bool fullCompare(const RuleMember &second);
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
    bool operator==(const RegularDataBlockWKeys &lhs, const RegularDataBlockWKeys &rhs);
    bool operator==(const TemplatedDataBlock &lhs, const TemplatedDataBlock &rhs);
    bool operator==(const DataBlock &lhs, const DataBlock &rhs);
    bool operator==(const Rule &lhs, const Rule &rhs);
};