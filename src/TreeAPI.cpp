#include <TreeAPI.h>

namespace TreeAPI {
    size_t String::count_strlen(const std::string &str) {
        size_t count = 0;
        for (auto it = str.begin(); it != str.end(); it++) {
            if (*it == '\\') {
                it++;
                continue;
            }
            count++;
        }
        return count;
    }
    std::string String::format_str(std::string str) {
        std::string res;
        for (auto &c : str) {
            if (c == '"') {
                res += "\\\"";
                continue;
            }
            res += c;
        }
        return res;
    }
    size_t String::count_strlen() {
        return count_strlen(value);
    }
    std::string String::format_str() {
        return format_str(value);
    }
    bool Number::hasDec() {
        return dec.empty();
    }
    bool Number::hasSign() {
        return sign == '\0';
    };
    std::string Number::getFull() {
        std::string full;
        if (sign != '\0')
            full += sign;
        full += main + '.' + dec;
        return full;
    }
    double Number::getFullNumber() {
        std::stod(main + '.' + dec);
    };
    unsigned Number::getMain() {
        return std::stoul(main);
    }
    unsigned Number::getDecimal() {
        return std::stoul(dec);
    }
    bool Boolean::getBoolean() {
        return value == "true";
    }
    bool rvalue::isString() {
        return std::holds_alternative<String>(value);
    }
    bool rvalue::isNumber() {
        return std::holds_alternative<Number>(value);
    }
    bool rvalue::isBoolean() {
        return std::holds_alternative<Boolean>(value);
    }
    bool rvalue::isArray() {
        return std::holds_alternative<Array>(value);
    }
    bool rvalue::isObject() {
        return std::holds_alternative<Object>(value);
    };
    bool rvalue::isAt() {
        return std::holds_alternative<At>(value);
    }
    bool rvalue::isID() {
        return std::holds_alternative<ID>(value);
    }
    String& rvalue::getString() {
        return std::get<String>(value);
    }
    Number& rvalue::getNumber() {
        return std::get<Number>(value);
    }
    Boolean& rvalue::getBoolean() {
        return std::get<Boolean>(value);
    }
    Array& rvalue::getArray() {
        return std::get<Array>(value);
    }
    Object& rvalue::getObject() {
        return std::get<Object>(value);
    }
    std::string& rvalue::getID() {
        return std::get<ID>(value).value;
    }
    bool CllExprValue::isGroup() {
        return std::holds_alternative<CllExprGroup>(value);
    }
    bool CllExprValue::isVariable() {
        return std::holds_alternative<CllVariable>(value);
    }
    bool CllExprValue::isFunctionCall() {
        return std::holds_alternative<CllFunctionCall>(value);
    }

    bool CllExprValue::isrvalue() {
        return std::holds_alternative<CllExprValue>(value);
    }
    CllExprGroup& CllExprValue::getGroup() {
        return std::get<CllExprGroup>(value);
    }
    CllVariable& CllExprValue::getVariable() {
        return std::get<CllVariable>(value);
    }
    CllFunctionCall& CllExprValue::getFunctionCall() {
        return std::get<CllFunctionCall>(value);
    }
    rvalue& CllExprValue::getrvalue() {
        return std::get<rvalue>(value);
    };
    bool RuleQuantifier::empty() const {
        return quantifier == '\0';
    }
    std::string::iterator RuleMemberHex::begin() {
        return hex_chars.begin();
    }
    std::string::iterator RuleMemberHex::end() {
        return hex_chars.end();
    }
    std::vector<int>::iterator RuleMemberBin::begin() {
        return bin_chars.begin();
    }
    std::vector<int>::iterator RuleMemberBin::end() {
        return bin_chars.end();
    }
    bool RuleMember::isName() const {
        return std::holds_alternative<RuleMemberName>(value);
    }
    bool RuleMember::isGroup() const {
        return std::holds_alternative<RuleMemberGroup>(value);
    }
    bool RuleMember::isOp() const {
        return std::holds_alternative<RuleMemberOp>(value);
    }
    bool RuleMember::isCsequence() const {
        return std::holds_alternative<RuleMemberCsequence>(value);
    }
    bool RuleMember::isAny() const {
        return std::holds_alternative<RuleMemberAny>(value);
    }
    bool RuleMember::isNospace() const {
        return std::holds_alternative<RuleMemberNospace>(value);
    }
    bool RuleMember::isEscaped() const {
        return std::holds_alternative<RuleMemberEscaped>(value);
    }
    bool RuleMember::isHex() const {
        return std::holds_alternative<RuleMemberHex>(value);
    }
    bool RuleMember::isBin() const {
        return std::holds_alternative<RuleMemberBin>(value);
    }
    
    decltype(RuleMemberName::name)& RuleMember::getName() {
        return std::get<RuleMemberName>(value).name;
    }
    decltype(RuleMemberGroup::values)& RuleMember::getGroup() {
        return std::get<RuleMemberGroup>(value).values;
    }
    decltype(RuleMemberOp::options)& RuleMember::getOp() {
        return std::get<RuleMemberOp>(value).options;
    }
    RuleMemberCsequence& RuleMember::getCsequence() {
        return std::get<RuleMemberCsequence>(value);
    }
    decltype(RuleMemberEscaped::c)& RuleMember::getEscaped() {
        return std::get<RuleMemberEscaped>(value).c;
    }
    RuleMemberHex& RuleMember::getHex() {
        return std::get<RuleMemberHex>(value);
    }
    RuleMemberBin& RuleMember::getBin() {
        return std::get<RuleMemberBin>(value);
    }
    std::unordered_map<std::string, CllExpr>::iterator RegularDataBlockWKeys::begin() {
        return value.begin();
    }
    std::unordered_map<std::string, CllExpr>::iterator RegularDataBlockWKeys::end() {
        return value.end();
    }
    CllExpr& RegularDataBlockWKeys::operator[](const std::string &name) {
        return value[name];
    }
    bool TemplatedDataBlock::empty() const {
        return names.empty();
    }
    
    std::vector<std::string>::iterator TemplatedDataBlock::begin() {
        return names.begin();
    }
    
    std::vector<std::string>::iterator TemplatedDataBlock::end() {
        return names.end();
    }
    
    bool DataBlock::isRegularDataBlock() {
        return std::holds_alternative<RegularDataBlock>(value) || std::holds_alternative<RegularDataBlockWKeys>(value);
    }
    
    bool DataBlock::isWithKeys() {
        return std::holds_alternative<RegularDataBlockWKeys>(value);
    }
    
    bool DataBlock::isTemplatedDataBlock() {
        return std::holds_alternative<TemplatedDataBlock>(value);
    }
    
    RegularDataBlock& DataBlock::getRegDataBlock() {
        return std::get<RegularDataBlock>(value);
    }
    
    RegularDataBlockWKeys& DataBlock::getRegDataBlockWKeys() {
        return std::get<RegularDataBlockWKeys>(value);
    }
    
    TemplatedDataBlock& DataBlock::getTemplatedDataBlock() {
        return std::get<TemplatedDataBlock>(value);
    }
};