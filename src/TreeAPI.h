#pragma once

#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <variant>
namespace TreeAPI {
    // forward declarations
    struct CllType;
    struct CllExpr;
    struct CllStmt;
    struct CllFunctionArguments;
    struct CllFunctionParameters;
    struct CllExprCompare;
    struct CllExprArithmetic;
    struct CllExprTerm;
    struct CllExprValue;
    struct rvalue;
    struct RuleMember;
    using CllFunctionBodyCall = CllFunctionArguments;
    using CllFunctionBodyDecl = CllFunctionParameters;
    using CllExprGroup = CllExpr;
    using CllExpr = CllExprLogical;
    struct String {
        std::string value;
        static size_t count_strlen(const std::string &str);
        static std::string format_str(std::string str);
        size_t String::count_strlen();
        std::string format_str();
    };
    struct Number {
        char sign = '\0';
        std::string main;
        std::string dec;
        std::string getFull();
        bool hasDec();
        bool hasSign();
        double getFullNumber();
        unsigned getMain();
        unsigned getDecimal();
    };
    struct Boolean {
        std::string value;
        bool getBoolean();
    };
    struct Array {
        std::vector<rvalue> value;
    };
    struct Object {
        std::unordered_map<std::string, rvalue> value;
    };
    struct At {};
    struct ID {
        std::string value;
    };
    struct rvalue {
        std::variant<String, Number, Boolean, Array, Object> value;
        bool isString();
        bool isNumber();
        bool isBoolean();
        bool isArray();
        bool isObject();
        bool isAt();
        bool isID(); 
        String& getString();
        Number& getNumber();
        Boolean& getBoolean();
        Array& getArray();
        Object& getObject();
        std::string& getID();
    };
    // cll
    struct CllAssignmentOp {
        char op;
    };
    struct CllCompareOp {
        std::string op;
    };
    /*holds only boolean value isAnd. If true it is And, if not it is Or*/
    struct CllLogicalOp {
        bool isAnd;
    };
    struct CllTemplate {
        std::vector<CllType> value;
    };
    struct CllType {
        std::string type;
        CllTemplate templ;
    };
    struct CllIf {
        CllExpr expr;
        CllStmt stmt;
    };
    struct CllVariable {
        bool pre_increament;
        bool post_increament;
        std::string name;
        CllExpr braceExpression;
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

    struct CllExprLogicalPart {
        CllExprCompare left;
        CllLogicalOp op;
        CllExprCompare right;
    };
    struct CllExprLogical {
        std::vector<CllExprLogicalPart> value;
    };
    struct CllExprComparePart {
        CllExprArithmetic left;
        CllCompareOp op;
        CllExprArithmetic right;
    };
    struct CllExprCompare {
        std::vector<CllExprComparePart> value;
    };
    struct CllExprArithmeticPart {
        CllExprTerm left;
        char op; // plus / minus
        CllExprTerm right;
    };
    struct CllExprArithmetic {
        std::vector<CllExprArithmeticPart> value;
    };
    struct CllExprTermPart {
        CllExprValue left;
        char op; // plus / minus
        CllExprValue right;
    };
    struct CllExprTerm {
        std::vector<CllExprLogicalPart> value;
    };
    struct CllExprValue {
        std::variant<CllExprGroup, CllVariable, CllFunctionCall, rvalue> value;
        bool isGroup();
        bool isVariable();
        bool isFunctionCall();
        bool isrvalue();
        CllExprGroup& getGroup();
        CllVariable& getVariable();
        CllFunctionCall& getFunctionCall();
        rvalue& getrvalue();
    };
    struct CllVar {
        CllType type;
        std::string name;
        CllAssignmentOp op;
        CllExpr value;
    };
    struct CllStmt {
        std::vector<RuleMember> value;
    };
    struct CllLoopWhile {
        CllExpr expr;
        CllStmt stmt;
    };
    // todo
    struct CllLoopFor {};
    struct Cll {
        std::variant<CllVar, CllIf, CllExpr> value;
    };
    struct RulePrefix {
        RulePrefix(bool is_key_value, const std::string &name)
            : is_key_value(is_key_value), name(name) {}
        bool is_key_value;
        std::string name;
    };
    struct RuleQuantifier {
        RuleQuantifier(const char quantifier) : quantifier(quantifier) {}
        char quantifier = '\0';
        bool empty() const;
    };
    struct RuleMemberName {
        RuleMemberName(const std::vector<std::string> &name) : name(name) {}
        RuleMemberName(std::vector<std::string> &&name) : name(std::move(name)) {}
        std::vector<std::string> name;
    };
    struct RuleMemberGroup {
        RuleMemberGroup(const std::vector<RuleMember> values) : values(values) {}
        RuleMemberGroup(std::vector<RuleMember> &&values) : values(std::move(values)) {}
        std::vector<RuleMember> values;
    };
    struct RuleMemberOp {
        RuleMemberOp(const std::vector<RuleMember> &options) : options(options) {}
        RuleMemberOp(const std::vector<RuleMember> &&options) : options(std::move(options)) {}
        std::vector<RuleMember> options;
    };
    struct RuleMemberCsequence {
        RuleMemberCsequence(const std::vector<char> &characters, const std::vector<char> &escaped, const std::vector<std::pair<char, char>> &diapasons)
            : characters(characters), escaped(escaped), diapasons(diapasons) {}
        RuleMemberCsequence(const std::vector<char> &&characters, const std::vector<char> &&escaped, const std::vector<std::pair<char, char>> &&diapasons)
            : characters(std::move(characters)), escaped(std::move(escaped)), diapasons(std::move(diapasons)) {}
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
        RuleMemberHex(const std::string &hex_chars) : hex_chars(hex_chars) {}
        RuleMemberHex(const std::string &&hex_chars) : hex_chars(std::move(hex_chars)) {}
        std::string hex_chars;
        std::string::iterator begin();
        std::string::iterator end();
    };
    struct RuleMemberBin {
        RuleMemberBin(const std::vector<int> &bin_chars) : bin_chars(bin_chars) {}
        RuleMemberBin(const std::vector<int> &&bin_chars) : bin_chars(std::move(bin_chars)) {}
        std::vector<int> bin_chars;
        std::vector<int>::iterator begin();
        std::vector<int>::iterator end();
    };
    struct RuleMember {
        RulePrefix prefix;
        RuleQuantifier quantifier;
        std::variant<RuleMemberName, RuleMemberGroup, RuleMemberOp, RuleMemberCsequence, RuleMemberAny, RuleMemberNospace, RuleMemberEscaped, RuleMemberHex, RuleMemberBin> value;

        bool isName() const;
        bool isGroup() const;
        bool isOp() const;
        bool isCsequence() const;
        bool isAny() const;
        bool isNospace() const;
        bool isEscaped() const;
        bool isHex() const;
        bool isBin() const;
        decltype(RuleMemberName::name)& getName();
        decltype(RuleMemberGroup::values)& getGroup();
        decltype(RuleMemberOp::options)& getOp();
        RuleMemberCsequence& getCsequence();
        decltype(RuleMemberEscaped::c)& getEscaped();
        RuleMemberHex& getHex();
        RuleMemberBin& getBin();
    }; 
    struct RegularDataBlockWKeys {
        std::unordered_map<std::string, CllExpr> value;

        bool empty() const;
        std::unordered_map<std::string, CllExpr>::iterator begin();
        std::unordered_map<std::string, CllExpr>::iterator end();
        CllExpr& operator[](const std::string &name);
    };
    using RegularDataBlock = CllExpr;
    struct TemplatedDataBlock {
        std::vector<std::string> names;

        bool empty() const;
        std::vector<std::string>::iterator begin();
        std::vector<std::string>::iterator end();
    };
    struct DataBlock {
        std::variant<RegularDataBlock, RegularDataBlockWKeys, TemplatedDataBlock> value;
        bool isRegularDataBlock();
        bool isWithKeys();
        bool isTemplatedDataBlock();
        RegularDataBlock& getRegDataBlock();
        RegularDataBlockWKeys& getRegDataBlockWKeys();
        TemplatedDataBlock& getTemplatedDataBlock();
    };
    struct Rule {
        Rule(const std::vector<std::string> &name, const std::vector<TreeAPI::RuleMember> &members, const TreeAPI::DataBlock &data_block)
            : name(name), members(members), data_block(data_block) {}
        Rule(std::vector<std::string> &&name, std::vector<TreeAPI::RuleMember> &&members, TreeAPI::DataBlock &&data_block)
            : name(std::move(name)), members(std::move(members)), data_block(std::move(data_block)) {}
        std::vector<std::string> name;
        std::vector<TreeAPI::RuleMember> members;
        TreeAPI::DataBlock data_block;
    };
};