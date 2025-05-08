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
    size_t String::count_strlen() const {
        return count_strlen(value);
    }
    std::string String::format_str() const {
        return format_str(value);
    }
    bool Number::hasDec() const {
        return dec.empty();
    }
    bool Number::hasSign() const {
        return sign == '\0';
    };
    std::string Number::getFull() const {
        std::string full;
        if (sign != '\0')
            full += sign;
        full += main + '.' + dec;
        return full;
    }
    double Number::getFullNumber() const {
        return std::stod(main + '.' + dec);
    };
    unsigned Number::getMain() const {
        return std::stoul(main);
    }
    unsigned Number::getDecimal() const {
        return std::stoul(dec);
    }
    bool Boolean::getBoolean() const {
        return value == "true";
    }
    bool rvalue::isString() const {
        return std::holds_alternative<String>(value);
    }
    bool rvalue::isNumber() const {
        return std::holds_alternative<Number>(value);
    }
    bool rvalue::isBoolean() const {
        return std::holds_alternative<Boolean>(value);
    }
    bool rvalue::isArray() const {
        return std::holds_alternative<Array>(value);
    }
    bool rvalue::isObject() const {
        return std::holds_alternative<Object>(value);
    };
    bool rvalue::isAt() const {
        return std::holds_alternative<At>(value);
    }
    bool rvalue::isID() const {
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
    std::vector<CllExpr>& rvalue::getArray() {
        return std::get<Array>(value).value;
    }
    std::unordered_map<std::string, CllExpr>& rvalue::getObject() {
        return std::get<Object>(value).value;
    }
    std::string& rvalue::getID() {
        return std::get<ID>(value).value;
    }
    const String& rvalue::getString() const {
        return std::get<String>(value);
    }
    
    const Number& rvalue::getNumber() const {
        return std::get<Number>(value);
    }
    
    const Boolean& rvalue::getBoolean() const {
        return std::get<Boolean>(value);
    }
    
    const std::vector<CllExpr>& rvalue::getArray() const {
        return std::get<Array>(value).value;
    }
    
    const std::unordered_map<std::string, CllExpr>& rvalue::getObject() const {
        return std::get<Object>(value).value;
    }
    
    const std::string& rvalue::getID() const {
        return std::get<ID>(value).value;
    }    
    bool CllExprValue::isGroup() const {
        return value.type() == typeid(CllExpr);
    }
    bool CllExprValue::isVariable() const {
        return value.type() == typeid(CllVariable);
    }
    bool CllExprValue::isFunctionCall() const {
        return value.type() == typeid(CllFunctionCall);
    }
    bool CllExprValue::isMethodCall() const {
        return value.type() == typeid(CllMethodCall);
    }
    bool CllExprValue::isrvalue() const {
        return value.type() == typeid(CllExprValue);
    }
    CllExprGroup& CllExprValue::getGroup() {
        return std::any_cast<CllExprGroup&>(value);
    }
    CllVariable& CllExprValue::getVariable() {
        return std::any_cast<CllVariable&>(value);
    }
    CllFunctionCall& CllExprValue::getFunctionCall() {
        return std::any_cast<CllFunctionCall&>(value);
    }
    CllMethodCall& CllExprValue::getMethodCall() {
        return std::any_cast<CllMethodCall&>(value);
    }
    rvalue& CllExprValue::getrvalue() {
        return std::any_cast<rvalue&>(value);
    };
    const CllExpr& CllExprValue::getGroup() const {
        return std::any_cast<const CllExpr&>(value);
    }
    
    const CllVariable& CllExprValue::getVariable() const {
        return std::any_cast<const CllVariable&>(value);
    }
    
    const CllFunctionCall& CllExprValue::getFunctionCall() const {
        return std::any_cast<const CllFunctionCall&>(value);
    }
    const CllMethodCall& CllExprValue::getMethodCall() const {
        return std::any_cast<const CllMethodCall&>(value);
    }    
    const rvalue& CllExprValue::getrvalue() const {
        return std::any_cast<const rvalue&>(value);
    }    
    bool TreeAPI::Cll::isVar() const {
        return std::holds_alternative<CllVar>(value);
    }
    
    bool TreeAPI::Cll::isIf() const {
        return std::holds_alternative<CllIf>(value);
    }
    
    bool TreeAPI::Cll::isExpr() const {
        return std::holds_alternative<CllExpr>(value);
    }
    TreeAPI::CllVar &TreeAPI::Cll::getVar() {
        return std::get<CllVar>(value);
    }
    
    TreeAPI::CllIf &TreeAPI::Cll::getIf() {
        return std::get<CllIf>(value);
    }
    
    const TreeAPI::CllExpr &TreeAPI::Cll::getExpr() const {
        return std::get<CllExpr>(value);
    }
    const TreeAPI::CllVar &TreeAPI::Cll::getVar() const {
        return std::get<CllVar>(value);
    }
    
    const TreeAPI::CllIf &TreeAPI::Cll::getIf() const {
        return std::get<CllIf>(value);
    }
    
    TreeAPI::CllExpr &TreeAPI::Cll::getExpr() {
        return std::get<CllExpr>(value);
    }
    std::string::iterator RuleMemberHex::begin() {
        return hex_chars.begin();
    }
    std::string::iterator RuleMemberHex::end() {
        return hex_chars.end();
    }
    std::string::iterator RuleMemberBin::begin() {
        return bin_chars.begin();
    }
    std::string::iterator RuleMemberBin::end() {
        return bin_chars.end();
    }
    void RulePrefix::clear() {
        name = "";
        is_key_value = false;
    }
    bool RulePrefix::empty() const {
        return name.empty();
    }
    bool RuleMember::isString() const {
        return std::holds_alternative<String>(value);
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
    bool RuleMember::isCll() const {
        return std::holds_alternative<Cll>(value);
    }
    bool RuleMember::emptyQuantifier() const {
        return quantifier == '\0';
    }
    bool RuleMember::empty() const {
        return std::holds_alternative<std::monostate>(value);
    }
    String& RuleMember::getString() {
        return std::get<String>(value);
    }
    RuleMemberName& RuleMember::getName() {
        return std::get<RuleMemberName>(value);
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
    Cll& RuleMember::getCll() {
        return std::get<Cll>(value);
    }
    const String& RuleMember::getString() const {
        return std::get<String>(value);
    }
    
    const RuleMemberName& RuleMember::getName() const {
        return std::get<RuleMemberName>(value);
    }
    
    const decltype(RuleMemberGroup::values)& RuleMember::getGroup() const {
        return std::get<RuleMemberGroup>(value).values;
    }
    
    const decltype(RuleMemberOp::options)& RuleMember::getOp() const {
        return std::get<RuleMemberOp>(value).options;
    }
    
    const RuleMemberCsequence& RuleMember::getCsequence() const {
        return std::get<RuleMemberCsequence>(value);
    }
    
    const decltype(RuleMemberEscaped::c)& RuleMember::getEscaped() const {
        return std::get<RuleMemberEscaped>(value).c;
    }
    
    const RuleMemberHex& RuleMember::getHex() const {
        return std::get<RuleMemberHex>(value);
    }
    
    const RuleMemberBin& RuleMember::getBin() const {
        return std::get<RuleMemberBin>(value);
    }
    
    const Cll& RuleMember::getCll() const {
        return std::get<Cll>(value);
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
    
    bool DataBlock::isRegularDataBlock() const {
        return std::holds_alternative<RegularDataBlock>(value) || std::holds_alternative<RegularDataBlockWKeys>(value);
    }
    
    bool DataBlock::isWithKeys() const {
        return std::holds_alternative<RegularDataBlockWKeys>(value);
    }
    
    bool DataBlock::isTemplatedDataBlock() const {
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
    const RegularDataBlock& DataBlock::getRegDataBlock() const {
        return std::get<RegularDataBlock>(value);
    }
    
    const RegularDataBlockWKeys& DataBlock::getRegDataBlockWKeys() const {
        return std::get<RegularDataBlockWKeys>(value);
    }
    
    const TemplatedDataBlock& DataBlock::getTemplatedDataBlock() const {
        return std::get<TemplatedDataBlock>(value);
    }
    // operator== for rules
        
    bool operator==(const String &first, const String &second) {
        return first.value == second.value;
    }
    // Comparison operator for Number
    bool operator==(const TreeAPI::Number &lhs, const TreeAPI::Number &rhs) {
        return lhs.sign == rhs.sign &&
            lhs.main == rhs.main &&
            lhs.dec == rhs.dec;
    }

    // Comparison operator for Boolean
    bool operator==(const TreeAPI::Boolean &lhs, const TreeAPI::Boolean &rhs) {
        return lhs.value == rhs.value;
    }

    // Comparison operator for Array
    bool operator==(const TreeAPI::Array &lhs, const TreeAPI::Array &rhs) {
        return lhs.value == rhs.value;
    }

    // Comparison operator for Object
    bool operator==(const TreeAPI::Object &lhs, const TreeAPI::Object &rhs) {
        return lhs.value == rhs.value;
    }

    // Comparison operator for ID
    bool operator==(const TreeAPI::ID &lhs, const TreeAPI::ID &rhs) {
        return lhs.value == rhs.value;
    }

    // Comparison operator for rvalue
    bool operator==(const TreeAPI::rvalue &lhs, const TreeAPI::rvalue &rhs) {
        return lhs.value == rhs.value;
    }

    // Comparison operator for CllCompareOp
    bool operator==(const TreeAPI::CllCompareOp &lhs, const TreeAPI::CllCompareOp &rhs) {
        return lhs.op == rhs.op;
    }

    // Comparison operator for CllLogicalOp
    bool operator==(const TreeAPI::CllLogicalOp &lhs, const TreeAPI::CllLogicalOp &rhs) {
        return lhs.isAnd == rhs.isAnd;
    }

    bool operator==(const CllType &lhs, const CllType &rhs) {
        return lhs.type == rhs.type && lhs.templ == rhs.templ;
    }
    
    bool operator==(const CllFunctionArguments &lhs, const CllFunctionArguments &rhs) {
        return lhs.expr == rhs.expr;
    }
    
    bool operator==(const CllFunctionParameters &lhs, const CllFunctionParameters &rhs) {
        return lhs.names == rhs.names;
    }
    
    // Comparison operator for CllFunctionCall
    bool operator==(const TreeAPI::CllFunctionCall &lhs, const TreeAPI::CllFunctionCall &rhs) {
        return lhs.name == rhs.name &&
            lhs.body == rhs.body;
    }

    // Comparison operator for CllFunctionDecl
    bool operator==(const TreeAPI::CllFunctionDecl &lhs, const TreeAPI::CllFunctionDecl &rhs) {
        return lhs.name == rhs.name &&
            lhs.body == rhs.body;
    }
    bool operator==(const CllExpr &lhs, const CllExpr &rhs) {
        return lhs.value == rhs.value;
    }
    
    bool operator==(const CllExprLogical &lhs, const CllExprLogical &rhs) {
        return lhs.value == rhs.value && lhs.rights == rhs.rights;
    }
    
    bool operator==(const CllExprCompare &lhs, const CllExprCompare &rhs) {
        return lhs.value == rhs.value && lhs.rights == rhs.rights;
    }
    
    bool operator==(const CllExprAddition &lhs, const CllExprAddition &rhs) {
        return lhs.value == rhs.value && lhs.rights == rhs.rights;
    }
    
    bool operator==(const CllExprTerm &lhs, const CllExprTerm &rhs) {
        return lhs.value == rhs.value && lhs.rights == rhs.rights;
    }
    
    bool operator==(const CllExprValue &lhs, const CllExprValue &rhs) {
        return lhs.value.type() == rhs.value.type() && lhs == rhs;
    }
    
    bool operator==(const CllVariable &lhs, const CllVariable &rhs) {
        return lhs.pre_increament == rhs.pre_increament &&
               lhs.post_increament == rhs.post_increament &&
               lhs.name == rhs.name &&
               lhs.braceExpression == rhs.braceExpression;
    }
    
    bool operator==(const CllIf &lhs, const CllIf &rhs) {
        return lhs.expr == rhs.expr && lhs.stmt == rhs.stmt;
    }
    
    bool operator==(const CllVar &lhs, const CllVar &rhs) {
        return lhs.type == rhs.type && lhs.name == rhs.name && lhs.op == rhs.op && lhs.value == rhs.value;
    }
    
    bool operator==(const CllLoopWhile &lhs, const CllLoopWhile &rhs) {
        return lhs.expr == rhs.expr && lhs.stmt == rhs.stmt;
    }
    
    bool operator==(const DataBlock &lhs, const DataBlock &rhs) {
        return lhs.value == rhs.value;
    }
    
    bool operator==(const RegularDataBlockWKeys &lhs, const RegularDataBlockWKeys &rhs) {
        return lhs.value == rhs.value;
    }
    
    bool operator==(const TemplatedDataBlock &lhs, const TemplatedDataBlock &rhs) {
        return lhs.names == rhs.names;
    }
    
    bool operator==(const Rule &lhs, const Rule &rhs) {
        return lhs.members == rhs.members && lhs.data_block == rhs.data_block;
    }

    bool operator==(const RulePrefix &first, const RulePrefix &second) {
        return first.is_key_value == second.is_key_value && first.name == second.name;
    }

    bool operator==(const Cll &first, const Cll &second) {
        return std::visit([](auto &&first, auto &&second) -> bool {
            if constexpr (std::is_same_v<decltype(first), decltype(second)>) {
                return first == second;
            } else {
                return false;
            }
        }, first.value, second.value);
    }

    bool operator==(const RuleMemberName &first, const RuleMemberName &second) {
        return first.name == second.name;
    }
    
    bool operator==(const RuleMemberGroup &first, const RuleMemberGroup &second) {
        return first.values == second.values;
    }
    
    bool operator==(const RuleMemberOp &first, const RuleMemberOp &second) {
        return first.options == second.options;
    }
    
    bool operator==(const RuleMemberCsequence &first, const RuleMemberCsequence &second) {
        // Compare independently of character position in csequence
        if (first.negative != second.negative || 
            first.characters.size() != second.characters.size() || 
            first.escaped.size() != second.escaped.size() || 
            first.diapasons.size() != second.diapasons.size()) {
            return false;
        }
        for (size_t i = 0; i < first.characters.size(); i++) {
            if (std::find(second.characters.begin(), second.characters.end(), first.characters[i]) == second.characters.end()) {
                return false;
            }
        }
        for (size_t i = 0; i < first.escaped.size(); i++) {
            if (std::find(second.escaped.begin(), second.escaped.end(), first.escaped[i]) == second.escaped.end()) {
                return false;
            }
        }
        for (size_t i = 0; i < first.diapasons.size(); i++) {
            if (std::find_if(second.diapasons.begin(), second.diapasons.end(), 
                             [&first, i](const std::pair<char, char> &pair) {
                                 return pair.first == first.diapasons[i].first && pair.second == first.diapasons[i].second;
                             }) == second.diapasons.end()) {
                return false;
            }
        }
        return true;
    }
    
    bool operator==(const RuleMemberAny &first, const RuleMemberAny &second) {
        return true; // Always equal
    }
    
    bool operator==(const RuleMemberNospace &first, const RuleMemberNospace &second) {
        return true; // Always equal
    }
    
    bool operator==(const RuleMemberEscaped &first, const RuleMemberEscaped &second) {
        return first.c == second.c;
    }
    
    bool operator==(const RuleMemberHex &first, const RuleMemberHex &second) {
        return first.hex_chars == second.hex_chars;
    }
    
    bool operator==(const RuleMemberBin &first, const RuleMemberBin &second) {
        return first.bin_chars == second.bin_chars;
    }
    
    bool operator==(const RuleMember &first, const RuleMember &second) {
        return std::visit([](auto &&lhs, auto &&rhs) -> bool {
                if constexpr (std::is_same_v<decltype(lhs), decltype(rhs)>) {
                    return lhs == rhs;
                } else {
                    return false;
                }
            }, first.value, second.value);
    }
    
    bool RuleMember::fullCompare(const RuleMember &second) {
        return *this == second && quantifier == second.quantifier && prefix == second.prefix && isAutoGenerated == second.isAutoGenerated && isInline == second.isInline;
    }
};
