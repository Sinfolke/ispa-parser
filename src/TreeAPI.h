#pragma once

#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <variant>
#include <memory>
#include <Parser.h>
#include <logging.h>
namespace TreeAPI {
    // forward declarations
    struct CllType;
    struct CllFunctionArguments;
    struct CllFunctionParameters;
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
    using CllExpr = CllExprLogical;
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
        std::variant<String, Number, Boolean, Array, Object, At, ID> value;
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
        std::vector<rvalue>& getArray();
        std::unordered_map<std::string, rvalue>& getObject();
        std::string& getID();
    };
    // cll
    struct CllCompareOp {
        std::string op;
    };
    /*holds only boolean value isAnd. If true it is And, if not it is Or*/
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
    
    struct CllExprValue {
        std::variant<CllExprLogical, CllVariable, CllFunctionCall, rvalue> value;
        bool isGroup();
        bool isVariable();
        bool isFunctionCall();
        bool isrvalue();
        CllExpr& getGroup();
        CllVariable& getVariable();
        CllFunctionCall& getFunctionCall();
        rvalue& getrvalue();
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
    struct CllVariable {
        char pre_increament = -1;
        char post_increament = -1;
        std::string name;
        std::optional<std::unique_ptr<CllExpr>> braceExpression;
    };
    struct CllIf {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    };
    struct CllVar {
        CllType type;
        std::string name;
        std::string op;
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
        bool isVar();
        bool isIf();
        bool isExpr();
        CllVar &getVar();
        CllIf &getIf();
        CllExpr &getExpr();
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
        std::variant<RuleMemberName, RuleMemberGroup, RuleMemberOp, RuleMemberCsequence, RuleMemberAny, RuleMemberNospace, RuleMemberEscaped, RuleMemberHex, RuleMemberBin, Cll> value;

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
        decltype(RuleMemberName::name)& getName();
        decltype(RuleMemberGroup::values)& getGroup();
        decltype(RuleMemberOp::options)& getOp();
        RuleMemberCsequence& getCsequence();
        decltype(RuleMemberEscaped::c)& getEscaped();
        RuleMemberHex& getHex();
        RuleMemberBin& getBin();
        Cll& getCll();
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
};