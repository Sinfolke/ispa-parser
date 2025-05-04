#pragma once

#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <variant>
#include <Parser.h>
#include <logging.h>
namespace TreeAPI {
    // forward declarations
    struct CllType;
    struct CllStmt;
    struct CllFunctionArguments;
    struct CllFunctionParameters;
    struct CllExprCompare;
    struct CllExprArithmetic;
    struct CllExprTerm;
    struct CllExprValue;
    struct CllExprLogical;
    struct CllExprLogicalPart;
    struct rvalue;
    struct RuleMember;
    using CllFunctionBodyCall = CllFunctionArguments;
    using CllFunctionBodyDecl = CllFunctionParameters;
    using CllExpr = CllExprLogical;
    using CllExprGroup = CllExpr;
    struct String {
        std::string value;
        static size_t count_strlen(const std::string &str);
        static std::string format_str(std::string str);
        size_t count_strlen();
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
    struct CllExprTermPart {
        CllExprValue left;
        char op; // plus / minus
        CllExprValue right;
    };
    struct CllExprTerm {
        std::vector<CllExprLogicalPart> value;
    };
    struct CllExprArithmeticPart {
        CllExprTerm left;
        char op; // plus / minus
        CllExprTerm right;
    };
    struct CllExprArithmetic {
        std::vector<CllExprArithmeticPart> value;
    };
    struct CllExprComparePart {
        CllExprArithmetic left;
        CllCompareOp op;
        CllExprArithmetic right;
    };
    struct CllExprCompare {
        std::vector<CllExprComparePart> value;
    };
    struct CllExprLogicalPart {
        CllExprCompare left;
        CllLogicalOp op;
        CllExprCompare right;
    };
    struct CllExprLogical {
        std::vector<CllExprLogicalPart> value;
    };
    struct CllIf {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    };


    struct CllVar {
        CllType type;
        std::string name;
        CllAssignmentOp op;
        CllExpr value;
    };
    struct CllLoopWhile {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    };
    // todo
    struct CllLoopFor {};
    struct Cll {
        std::variant<CllVar, CllIf, CllExpr> value;
    };
    struct RulePrefix {
        bool is_key_value;
        std::string name;
        void clear();
    };
    struct RuleMemberName {
        std::vector<std::string> name;
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
        bool emptyQuantifier() const;
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
        std::vector<TreeAPI::RuleMember> members;
        TreeAPI::DataBlock data_block;
    };

    // convertion functions
    RuleMember createRuleMember(
        const Parser::Rule &rule, std::vector<RuleMember> newRules, bool &in_op, bool &prev_op, bool &add_prev, 
        const std::vector<std::string> &fullname, RulePrefix &ops_prefix, std::vector<RuleMember> &ops, 
        std::vector<std::vector<std::string>> &nested_rule_names
    );
    // build Tree API from AST
    void createRules(const Parser::Types::Rule_data &rule, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, Rule> &TreeMap);
    void createRules(const Parser::Types::Rule_data &rule, std::unordered_map<std::vector<std::string>, Rule> &TreeMap);
};