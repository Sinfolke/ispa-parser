#pragma once

#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <variant>
#include <memory>
#include <Parser.h>
#include <logging.h>
#include <type_traits>
namespace TreeAPI {
    // forward declarations
    struct CllType;
    struct CllFunctionArguments;
    struct CllFunctionParameters;
    struct CllExpr;
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
        String &getString();
        Number &getNumber();
        Boolean &getBoolean();
        std::vector<rvalue> &getArray();
        std::unordered_map<std::string, rvalue> &getObject();
        std::string &getID();
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

    struct CllExprValue {
        std::any value;
        bool isGroup();
        bool isVariable();
        bool isFunctionCall();
        bool isrvalue();
        CllExpr &getGroup();
        CllVariable &getVariable();
        CllFunctionCall &getFunctionCall();
        rvalue &getrvalue();
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
        std::string op;
        CllExpr value;
    };

    struct CllLoopWhile {
        CllExpr expr;
        std::vector<RuleMember> stmt;
    };

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
        bool isAutoGenerated = false;
        bool isInline = false;
        std::variant<String, RuleMemberName, RuleMemberGroup, RuleMemberOp, RuleMemberCsequence, RuleMemberAny, RuleMemberNospace, RuleMemberEscaped, RuleMemberHex, RuleMemberBin, Cll> value;

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
        String &getString();
        decltype(RuleMemberName::name) &getName();
        decltype(RuleMemberGroup::values) &getGroup();
        decltype(RuleMemberOp::options) &getOp();
        RuleMemberCsequence &getCsequence();
        decltype(RuleMemberEscaped::c) &getEscaped();
        RuleMemberHex &getHex();
        RuleMemberBin &getBin();
        Cll &getCll();
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
        std::variant<RegularDataBlock, RegularDataBlockWKeys, TemplatedDataBlock> value;
        bool isRegularDataBlock();
        bool isWithKeys();
        bool isTemplatedDataBlock();
        RegularDataBlock &getRegDataBlock();
        RegularDataBlockWKeys &getRegDataBlockWKeys();
        TemplatedDataBlock &getTemplatedDataBlock();
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
// hash functions for these structures
namespace std {

    // Helper function to combine hash values
    inline void hash_combine(std::size_t &seed, std::size_t hash) {
        seed ^= hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    
    // Hash function for String
    template <>
    struct hash<TreeAPI::String> {
        std::size_t operator()(const TreeAPI::String &str) const {
            return std::hash<std::string>()(str.value);
        }
    };
    
    // Hash function for Number
    template <>
    struct hash<TreeAPI::Number> {
        std::size_t operator()(const TreeAPI::Number &num) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<char>()(num.sign));
            hash_combine(seed, std::hash<std::string>()(num.main));
            hash_combine(seed, std::hash<std::string>()(num.dec));
            return seed;
        }
    };
    
    // Hash function for Boolean
    template <>
    struct hash<TreeAPI::Boolean> {
        std::size_t operator()(const TreeAPI::Boolean &boolean) const {
            return std::hash<std::string>()(boolean.value);
        }
    };
    
    // Hash function for Array
    template <>
    struct hash<TreeAPI::Array> {
        std::size_t operator()(const TreeAPI::Array &array) const {
            std::size_t seed = 0;
            for (const auto &value : array.value) {
                hash_combine(seed, std::hash<TreeAPI::rvalue>()(value));
            }
            return seed;
        }
    };
    
    // Hash function for Object
    template <>
    struct hash<TreeAPI::Object> {
        std::size_t operator()(const TreeAPI::Object &object) const {
            std::size_t seed = 0;
            for (const auto &pair : object.value) {
                hash_combine(seed, std::hash<std::string>()(pair.first));
                hash_combine(seed, std::hash<TreeAPI::rvalue>()(pair.second));
            }
            return seed;
        }
    };
    
    // Hash function for At
    template <>
    struct hash<TreeAPI::At> {
        std::size_t operator()(const TreeAPI::At &) const {
            return 0; // At has no state, so return a constant hash
        }
    };
    
    // Hash function for ID
    template <>
    struct hash<TreeAPI::ID> {
        std::size_t operator()(const TreeAPI::ID &id) const {
            return std::hash<std::string>()(id.value);
        }
    };
    
    // Hash function for rvalue
    template <>
    struct hash<TreeAPI::rvalue> {
        std::size_t operator()(const TreeAPI::rvalue &value) const {
            return std::visit([](const auto &val) {
                return std::hash<std::decay_t<decltype(val)>>()(val);
            }, value.value);
        }
    };
    
    // Hash function for CllCompareOp
    template <>
    struct hash<TreeAPI::CllCompareOp> {
        std::size_t operator()(const TreeAPI::CllCompareOp &op) const {
            return std::hash<std::string>()(op.op);
        }
    };
    
    // Hash function for CllLogicalOp
    template <>
    struct hash<TreeAPI::CllLogicalOp> {
        std::size_t operator()(const TreeAPI::CllLogicalOp &op) const {
            return std::hash<bool>()(op.isAnd);
        }
    };
    
    // Hash function for CllFunctionCall
    template <>
    struct hash<TreeAPI::CllFunctionCall> {
        std::size_t operator()(const TreeAPI::CllFunctionCall &call) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<std::string>()(call.name));
            hash_combine(seed, std::hash<TreeAPI::CllFunctionArguments>()(call.body));
            return seed;
        }
    };
    
    // Hash function for CllFunctionDecl
    template <>
    struct hash<TreeAPI::CllFunctionDecl> {
        std::size_t operator()(const TreeAPI::CllFunctionDecl &decl) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<std::string>()(decl.name));
            hash_combine(seed, std::hash<TreeAPI::CllFunctionParameters>()(decl.body));
            return seed;
        }
    };
    template <>
    struct hash<TreeAPI::CllExprValue> {
        std::size_t operator()(const TreeAPI::CllExprValue &value) const {
            return std::hash<std::any>()(value.value);
        }
    };

    // Hash function for CllExprTerm
    template <>
    struct hash<TreeAPI::CllExprTerm> {
        std::size_t operator()(const TreeAPI::CllExprTerm &term) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::CllExprValue>()(term.value));
            for (const auto &pair : term.rights) {
                hash_combine(seed, std::hash<char>()(pair.first));
                hash_combine(seed, std::hash<TreeAPI::CllExprValue>()(pair.second));
            }
            return seed;
        }
    };

    // Hash function for CllExprAddition
    template <>
    struct hash<TreeAPI::CllExprAddition> {
        std::size_t operator()(const TreeAPI::CllExprAddition &addition) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::CllExprTerm>()(addition.value));
            for (const auto &pair : addition.rights) {
                hash_combine(seed, std::hash<char>()(pair.first));
                hash_combine(seed, std::hash<TreeAPI::CllExprTerm>()(pair.second));
            }
            return seed;
        }
    };

    // Hash function for CllExprCompare
    template <>
    struct hash<TreeAPI::CllExprCompare> {
        std::size_t operator()(const TreeAPI::CllExprCompare &compare) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::CllExprAddition>()(compare.value));
            for (const auto &pair : compare.rights) {
                hash_combine(seed, std::hash<TreeAPI::CllCompareOp>()(pair.first));
                hash_combine(seed, std::hash<TreeAPI::CllExprAddition>()(pair.second));
            }
            return seed;
        }
    };

    // Hash function for CllExprLogical
    template <>
    struct hash<TreeAPI::CllExprLogical> {
        std::size_t operator()(const TreeAPI::CllExprLogical &logical) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::CllExprCompare>()(logical.value));
            for (const auto &pair : logical.rights) {
                hash_combine(seed, std::hash<TreeAPI::CllLogicalOp>()(pair.first));
                hash_combine(seed, std::hash<TreeAPI::CllExprCompare>()(pair.second));
            }
            return seed;
        }
    };

    // Hash function for CllExpr
    template <>
    struct hash<TreeAPI::CllExpr> {
        std::size_t operator()(const TreeAPI::CllExpr &expr) const {
            return std::hash<TreeAPI::CllExprLogical>()(expr.value);
        }
    };

    // Hash function for CllVariable
    template <>
    struct hash<TreeAPI::CllVariable> {
        std::size_t operator()(const TreeAPI::CllVariable &variable) const {
            std::size_t seed = 0;
            if (variable.pre_increament) {
                hash_combine(seed, std::hash<char>()(*variable.pre_increament));
            }
            if (variable.post_increament) {
                hash_combine(seed, std::hash<char>()(*variable.post_increament));
            }
            hash_combine(seed, std::hash<std::string>()(variable.name));
            if (variable.braceExpression) {
                hash_combine(seed, std::hash<TreeAPI::CllExpr>()(*variable.braceExpression));
            }
            return seed;
        }
    };

    // Hash function for CllIf
    template <>
    struct hash<TreeAPI::CllIf> {
        std::size_t operator()(const TreeAPI::CllIf &cllIf) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::CllExpr>()(cllIf.expr));
            for (const auto &stmt : cllIf.stmt) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>()(stmt));
            }
            return seed;
        }
    };

    // Hash function for CllVar
    template <>
    struct hash<TreeAPI::CllVar> {
        std::size_t operator()(const TreeAPI::CllVar &var) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::CllType>()(var.type));
            hash_combine(seed, std::hash<std::string>()(var.name));
            hash_combine(seed, std::hash<std::string>()(var.op));
            hash_combine(seed, std::hash<TreeAPI::CllExpr>()(var.value));
            return seed;
        }
    };

    // Hash function for CllLoopWhile
    template <>
    struct hash<TreeAPI::CllLoopWhile> {
        std::size_t operator()(const TreeAPI::CllLoopWhile &loopWhile) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::CllExpr>()(loopWhile.expr));
            for (const auto &stmt : loopWhile.stmt) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>()(stmt));
            }
            return seed;
        }
    };

    // Hash function for Cll
    template <>
    struct hash<TreeAPI::Cll> {
        std::size_t operator()(const TreeAPI::Cll &cll) const {
            return std::visit([](const auto &val) {
                return std::hash<std::decay_t<decltype(val)>>()(val);
            }, cll.value);
        }
    };

    // Hash function for RulePrefix
    template <>
    struct hash<TreeAPI::RulePrefix> {
        std::size_t operator()(const TreeAPI::RulePrefix &prefix) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<bool>()(prefix.is_key_value));
            hash_combine(seed, std::hash<std::string>()(prefix.name));
            return seed;
        }
    };

    // Hash function for RuleMemberName
    template <>
    struct hash<TreeAPI::RuleMemberName> {
        std::size_t operator()(const TreeAPI::RuleMemberName &name) const {
            std::size_t seed = 0;
            for (const auto &str : name.name) {
                hash_combine(seed, std::hash<std::string>()(str));
            }
            return seed;
        }
    };

    // Hash function for RuleMemberGroup
    template <>
    struct hash<TreeAPI::RuleMemberGroup> {
        std::size_t operator()(const TreeAPI::RuleMemberGroup &group) const {
            std::size_t seed = 0;
            for (const auto &value : group.values) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>()(value));
            }
            return seed;
        }
    };
    // Hash function for RuleMemberOp
    template <>
    struct hash<TreeAPI::RuleMemberOp> {
        std::size_t operator()(const TreeAPI::RuleMemberOp &op) const {
            std::size_t seed = 0;
            for (const auto &option : op.options) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>()(option));
            }
            return seed;
        }
    };

    // Hash function for RuleMemberCsequence
    template <>
    struct hash<TreeAPI::RuleMemberCsequence> {
        std::size_t operator()(const TreeAPI::RuleMemberCsequence &csequence) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<bool>()(csequence.negative));
            for (const auto &character : csequence.characters) {
                hash_combine(seed, std::hash<char>()(character));
            }
            for (const auto &escaped : csequence.escaped) {
                hash_combine(seed, std::hash<char>()(escaped));
            }
            for (const auto &diapason : csequence.diapasons) {
                hash_combine(seed, std::hash<char>()(diapason.first));
                hash_combine(seed, std::hash<char>()(diapason.second));
            }
            return seed;
        }
    };

    // Hash function for RuleMemberAny
    template <>
    struct hash<TreeAPI::RuleMemberAny> {
        std::size_t operator()(const TreeAPI::RuleMemberAny &) const {
            return 0; // RuleMemberAny has no state, so return a constant hash
        }
    };

    // Hash function for RuleMemberNospace
    template <>
    struct hash<TreeAPI::RuleMemberNospace> {
        std::size_t operator()(const TreeAPI::RuleMemberNospace &) const {
            return 0; // RuleMemberNospace has no state, so return a constant hash
        }
    };

    // Hash function for RuleMemberEscaped
    template <>
    struct hash<TreeAPI::RuleMemberEscaped> {
        std::size_t operator()(const TreeAPI::RuleMemberEscaped &escaped) const {
            return std::hash<char>()(escaped.c);
        }
    };

    // Hash function for RuleMemberHex
    template <>
    struct hash<TreeAPI::RuleMemberHex> {
        std::size_t operator()(const TreeAPI::RuleMemberHex &hex) const {
            return std::hash<std::string>()(hex.hex_chars);
        }
    };

    // Hash function for RuleMemberBin
    template <>
    struct hash<TreeAPI::RuleMemberBin> {
        std::size_t operator()(const TreeAPI::RuleMemberBin &bin) const {
            return std::hash<std::string>()(bin.bin_chars);
        }
    };

    // Hash function for RuleMember
    template <>
    struct hash<TreeAPI::RuleMember> {
        std::size_t operator()(const TreeAPI::RuleMember &member) const {
            std::size_t seed = 0;
            hash_combine(seed, std::hash<TreeAPI::RulePrefix>()(member.prefix));
            hash_combine(seed, std::hash<char>()(member.quantifier));
            hash_combine(seed, std::hash<bool>()(member.isAutoGenerated));
            hash_combine(seed, std::hash<bool>()(member.isInline));
            hash_combine(seed, std::visit([](const auto &val) {
                return std::hash<std::decay_t<decltype(val)>>()(val);
            }, member.value));
            return seed;
        }
    };

    // Hash function for RegularDataBlockWKeys
    template <>
    struct hash<TreeAPI::RegularDataBlockWKeys> {
        std::size_t operator()(const TreeAPI::RegularDataBlockWKeys &block) const {
            std::size_t seed = 0;
            for (const auto &pair : block.value) {
                hash_combine(seed, std::hash<std::string>()(pair.first));
                hash_combine(seed, std::hash<TreeAPI::CllExpr>()(pair.second));
            }
            return seed;
        }
    };

    // Hash function for TemplatedDataBlock
    template <>
    struct hash<TreeAPI::TemplatedDataBlock> {
        std::size_t operator()(const TreeAPI::TemplatedDataBlock &block) const {
            std::size_t seed = 0;
            for (const auto &name : block.names) {
                hash_combine(seed, std::hash<std::string>()(name));
            }
            return seed;
        }
    };

    // Hash function for DataBlock
    template <>
    struct hash<TreeAPI::DataBlock> {
        std::size_t operator()(const TreeAPI::DataBlock &block) const {
            return std::visit([](const auto &val) {
                return std::hash<std::decay_t<decltype(val)>>()(val);
            }, block.value);
        }
    };

    // Hash function for Rule
    template <>
    struct hash<TreeAPI::Rule> {
        std::size_t operator()(const TreeAPI::Rule &rule) const {
            std::size_t seed = 0;
            for (const auto &member : rule.members) {
                hash_combine(seed, std::hash<TreeAPI::RuleMember>()(member));
            }
            hash_combine(seed, std::hash<TreeAPI::DataBlock>()(rule.data_block));
            return seed;
        }
    };
} // namespace std