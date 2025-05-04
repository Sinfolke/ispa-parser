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
        return std::stod(main + '.' + dec);
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
    bool RuleMember::emptyQuantifier() const {
        return quantifier == '\0';
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
    /*
        create RuleMember API from Rule_rule AST member
    */
    RuleMember createRuleMember(
        const Parser::Rule &rule, std::vector<RuleMember> newRules, bool &in_op, bool &prev_op, bool &add_prev, 
        const std::vector<std::string> &fullname, RulePrefix &ops_prefix, std::vector<RuleMember> &ops, 
        std::vector<std::string> &nested_rule_names
    ) {
        RuleMember member;
        bool addToOps;
        if (in_op) {
            addToOps = true;
        }
        const auto &rule_r = Parser::get::Rule_rule(rule);
        member.prefix.is_key_value = rule_r.prefix.name() == Parser::Rules::Rule_keyvalue;
        // get prefix
        if (rule_r.prefix.name() == Parser::Rules::Rule_keyvalue) {
            auto data = Parser::get::Rule_keyvalue(rule_r.prefix);
            member.prefix.name = Parser::get::ID(data);
        } else {
            auto data = Parser::get::Rule_value(rule_r.prefix);
            member.prefix.name = Parser::get::ID(data);
        }
        // get quantifier
        if (!rule_r.quantifier.empty()) {
            member.quantifier = std::any_cast<std::string>(Parser::get::Rule_quantifier(rule_r.quantifier))[0];
        }

        // get value
        if (rule_r.val.type() == typeid(Parser::Rule)) {
            const auto &token = std::any_cast<Parser::Token&>(rule_r.val);
            switch (token.name()) {
                case Parser::Tokens::Rule_OP:
                    if (!in_op) {
                        add_prev = true;
                        in_op = true;
                    }
                    addToOps = false;
                    prev_op = true;
                    break;
                case Parser::Tokens::Rule_NOSPACE:
                    member.value = RuleMemberNospace();
                    break;
                // temporary solution
                case Parser::Tokens::AUTO_18:
                    member.value = RuleMemberAny();
                    break;
                case Parser::Tokens::Rule_CSEQUENCE:
                {
                    RuleMemberCsequence newCsequence;
                    const auto &csequence_data = Parser::get::Rule_CSEQUENCE(token);
                    if (!csequence_data._not.empty()) {
                        newCsequence.negative = true;
                    }
                    for (const auto &data : csequence_data.val) {
                        switch (data.name())
                        {
                        case Parser::Tokens::Rule_CSEQUENCE_SYMBOL:
                            newCsequence.characters.push_back(Parser::get::Rule_CSEQUENCE_SYMBOL(data)[0]);
                            break;
                        case Parser::Tokens::Rule_CSEQUENCE_ESCAPE:
                            newCsequence.characters.push_back(Parser::get::Rule_CSEQUENCE_ESCAPE(data)[0]);
                            break;
                        case Parser::Tokens::Rule_CSEQUENCE_DIAPASON:
                        {
                            const auto &diapason = Parser::get::Rule_CSEQUENCE_DIAPASON(data);
                            newCsequence.diapasons.push_back({Parser::get::Rule_CSEQUENCE_SYMBOL(diapason[0])[0], Parser::get::Rule_CSEQUENCE_SYMBOL(diapason[1])[0]});
                            break;
                        }
                        default:
                            throw Error("Undefined CSEQUENCE type");
                            break;
                        }
                    }
                    member.value = newCsequence;
                    break;
                }
                case Parser::Tokens::Rule_ESCAPED:
                    member.value = RuleMemberEscaped(Parser::get::Rule_ESCAPED(token)[0]);
                    break;
                case Parser::Tokens::Rule_HEX:
                    member.value = RuleMemberHex{Parser::get::Rule_HEX(token)};
                    break;
                case Parser::Tokens::Rule_BIN:
                    member.value = RuleMemberBin{Parser::get::Rule_BIN(token)};
                    break;
                default:
                    throw Error("Undefined Rule_rule member");
            }
        } else {
            auto rule = std::any_cast<Parser::Rule>(rule_r.val);
            switch (rule.name())
            {
            case Parser::Rules::Rule_name:
            {
                auto data = Parser::get::Rule_name(rule);

                std::vector<std::string> rule_name;
                // if (is_nested)
                //     rule_name.assign(fullname.begin(), fullname.end());
                // rule_name.push_back(std::any_cast<std::string>(name.data));
                // for (auto &nested : nested_rule_names)
                //     rule_name.push_back(std::any_cast<std::string>(nested.data));
                
                auto res = std::find(nested_rule_names.begin(), nested_rule_names.end(), Parser::get::ID(data.name));
                if (res != nested_rule_names.end()) {
                    rule_name = std::vector<std::string>{*res};
                } else {
                    if (!data.is_nested.empty()) {
                        rule_name.assign(fullname.begin(), fullname.end());
                    }
                    rule_name.push_back(Parser::get::ID(data.name));
                }
                for (const auto &nested : data.nested_name) {
                    rule_name.push_back(Parser::get::ID(nested));
                }
                member.value = RuleMemberName {rule_name};
                break;
            }
            case Parser::Rules::Rule_group:
            {
                auto data = Parser::get::Rule_group(rule);
                member.value = RuleMemberGroup{createRuleMembers(data, fullname, nested_rule_names)};
            }
            default:
                throw Error("Undefined rule_rule member");
                break;
            }
        }
        if (addToOps) {
            if (!prev_op) {
                // flush
                RuleMemberOp op {ops};
                newRules.push_back(RuleMember {.prefix = ops_prefix, .value = op});
                in_op = false;
                ops.clear();
            } else {
                ops.push_back(member);
                prev_op = false;
            }

        }
        return member;
    }
    std::vector<RuleMember> createRuleMembers(const std::vector<Parser::Rule> rules, const std::vector<std::string> &fullname, std::vector<std::string> &nested_rule_names) {
        bool in_op = false, prev_op = false, add_prev = false;
        RulePrefix ops_prefix;
        std::vector<RuleMember> ops;
        std::vector<RuleMember> newRules;
        for (auto it = rules.begin(); it != rules.end(); it++) {
            auto member = createRuleMember(*it, newRules, in_op, prev_op, add_prev, fullname, ops_prefix, ops, nested_rule_names);
            if (add_prev) {
                in_op = true;
                prev_op = true;
                ops.push_back(newRules.back());
                newRules.pop_back();
                ops_prefix = ops.back().prefix;
                ops.back().prefix.clear();
            }
            newRules.push_back(member);
        }
        return newRules;
    }
    static std::vector<std::string> getNestedRuleNames(const Parser::Types::Rule_data &rule) {
        std::vector<std::string> names;
        for (auto el : rule.nested_rules) {
            auto nested_r = Parser::get::Rule(el);
            names.push_back(Parser::get::ID(nested_r.name));
        }
        return names;
    }
    // build Tree API from AST
    void createRules(const Parser::Types::Rule_data &rule, std::vector<std::string> &fullname, std::unordered_map<std::vector<std::string>, Rule> &TreeMap) {
        std::vector<Rule> result;
        Rule newRule;
        std::vector<std::string> nested_rule_names = getNestedRuleNames(rule);
        fullname.push_back(Parser::get::ID(rule.name));
        newRule.members = createRuleMembers(rule.rule, fullname, nested_rule_names);
        TreeMap[fullname] = newRule;
        for (auto nested : rule.nested_rules) {
            auto r = Parser::get::Rule(nested);
            createRules(r, fullname, TreeMap);
        }
        fullname.pop_back();
    }
    void createRules(const Parser::Types::Rule_data &rule, std::unordered_map<std::vector<std::string>, Rule> &TreeMap) {
        std::vector<std::string> fullname;
        createRules(rule, fullname, TreeMap);
    }
};