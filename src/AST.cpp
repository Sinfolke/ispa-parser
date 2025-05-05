#include <AST.h>
void AST::constructor(const Parser::Rule &mod) {
    // pass through tree to get name, spacemode, use and TreeMap
    const auto &entrise = Parser::get::main(mod);
    for (auto entry : entrise) {
        if (entry.type() == typeid(Parser::Rule)) {
            auto t = std::any_cast<Parser::Rule&>(entry);
            if (t.name() == Parser::Rules::Rule) {
                auto data = Parser::get::Rule(std::any_cast<Parser::Rule&>(entry));
                createRules(data);
            } else if (t.name() == Parser::Rules::use) {
                // accamulate use here
            } else {
                throw Error("Undefined tree member");
            }
        } else if (entry.type() == typeid(Parser::Token)) {
            // is token
            auto t = std::any_cast<Parser::Token&>(entry);
            if (t.name() == Parser::Tokens::SPACEMODE) {
                // handle spacemode
            } else if (t.name() == Parser::Tokens::NAME) {
                // handle name
            } else 
                throw Error("Undefined tree member");
        } else {
            throw Error("Undefined type for entry");
        }
    }
}
void AST::constructor(const std::vector<Parser::Rule> &modules) {
    for (const auto &mod : modules) {
        constructor(mod);
    }
}
AST::TreeMap& AST::getTreeMap() {
    return tree_map;
}
AST::Use& AST::getUse() {
    return use;
}
TreeAPI::Array AST::createArray(const Parser::Rule &array) {
    TreeAPI::Array arr;
    auto data = Parser::get::array(array);
    for (auto el : data) {
        arr.value.push_back(createRvalue(el));
    }
    return arr;
}
TreeAPI::Object AST::createObject(const Parser::Rule &object) {
    TreeAPI::Object obj;
    // todo
    // auto data = Parser::get::object(object);
    // obj.value[data.key]
    return obj;
}
TreeAPI::String AST::createString(const Parser::Token &token) {
    return TreeAPI::String {Parser::get::STRING(token)};
}
TreeAPI::Number AST::createNumber(const Parser::Token &number) {
    TreeAPI::Number num;
    auto data = Parser::get::NUMBER(number);
    num.dec = data.dec;
    num.main = data.main;
    if (!data.sign.empty()) {
        num.sign = data.sign[0];
    }
    return num;
}

TreeAPI::Boolean AST::createBoolean(const Parser::Token boolean) {
    return TreeAPI::Boolean {Parser::get::BOOLEAN(boolean)};
}

TreeAPI::rvalue AST::createRvalue(const Parser::Rule &rule) {
    TreeAPI::rvalue value;
    auto data = Parser::get::any_data(rule);
    if (data.type() == typeid(Parser::Rule)) {
        auto dt = std::any_cast<Parser::Rule&>(data);
        switch (dt.name())
        {
        case Parser::Rules::array:
            value.value = createArray(dt);
            break;
        case Parser::Rules::object:
            value.value = createObject(dt);
            break;
        default:
            throw Error("Undefined rule in any_data");
            break;
        }
    } else {
        auto dt = std::any_cast<Parser::Token&>(data);
        switch (dt.name())
        {
        case Parser::Tokens::STRING:
            value.value = createString(dt);
            break;
        case Parser::Tokens::NUMBER:
            value.value = createNumber(dt);
            break;
        case Parser::Tokens::BOOLEAN:
            value.value = createBoolean(dt);
            break;
        case Parser::Tokens::AT:
            value.value = TreeAPI::At {};
            break;
        default:
            throw Error("Undefined token in any_data");
            break;
        }
    }
    return value;
}

TreeAPI::CllFunctionArguments AST::createCllFunctionArguments(const Parser::Rule &rule) {
    TreeAPI::CllFunctionArguments arguments;
    // implement later
    // auto data = Parser::get::cll_function_arguments(rule);
    // arguments.expr = {createCllExpr(data.first)};
    // for (auto el : data.second) {
    //     arguments.expr.push_back();
    // }
    return arguments;
}

TreeAPI::CllFunctionCall AST::createCllFunctionCall(const Parser::Rule &rule) {
    const auto &data = Parser::get::cll_cll_function_call(rule);
    TreeAPI::CllFunctionCall new_function_call;
    new_function_call.name = Parser::get::ID(data.name);
    new_function_call.body = createCllFunctionArguments(data.body);
    return new_function_call;
}

TreeAPI::CllVariable AST::createCllVariable(const Parser::Rule &rule) {
    TreeAPI::CllVariable newVar;
    const auto &var = Parser::get::cll_variable(rule);
    newVar.name = Parser::get::ID(var.name);
    newVar.braceExpression = std::make_optional(
        std::make_unique<TreeAPI::CllExpr>(createCllExpr(var.brace_expression))
    );
    
    if (!var.post.empty()) {
        newVar.post_increament = var.post.name() == Parser::Tokens::AUTO_10;
    }
    if (!var.pre.empty()) {
        newVar.pre_increament = var.pre.name() == Parser::Tokens::AUTO_10;
    }
    return newVar;
}

TreeAPI::CllCompareOp AST::createCllCompareOp(const Parser::Token &token) {
    return TreeAPI::CllCompareOp {Parser::get::cll_COMPARE_OP(token)};
}

TreeAPI::CllLogicalOp AST::createCllLogicalOp(const Parser::Token &token) {
    TreeAPI::CllLogicalOp result;
    result.isAnd = token.name() == Parser::Tokens::cll_LOGICAL_AND;
    return result;
}

TreeAPI::CllExprValue AST::createCllExprValue(const Parser::Rule logical) {
    auto data = Parser::get::cll_expr_value(logical);
    TreeAPI::CllExprValue result;

    switch (data.name())
    {
    case Parser::Rules::Rule_group:
        result.value = createCllExpr(Parser::get::cll_expr(data));
        break;
    case Parser::Rules::cll_variable:
        result.value = createCllVariable(data);
        break;
    case Parser::Rules::cll_cll_function_call:
        result.value = createCllFunctionCall(data);
        break;
    case Parser::Rules::any_data:
        result.value = createRvalue(data);
        break;
    default:
        throw Error("[AST] Undefined node in createCllValue");
        break;
    }
    return result;
}

TreeAPI::CllExprTerm AST::createCllExprTerm(const Parser::Rule logical) {
    auto data = Parser::get::cll_expr_term(logical);
    TreeAPI::CllExprTerm result;

    result.value = createCllExprValue(data.first);
    for (size_t i = 0; i < data.operators.size(); i++) {
        char op;
        if (data.operators[i].name() == Parser::Tokens::PLUS)
            op = '+';
        else
            op = '-';
        result.rights.push_back(std::pair<char, TreeAPI::CllExprValue> {op, createCllExprValue(data.sequence[i])});
    }
    return result;
}

TreeAPI::CllExprAddition AST::createCllExprAddition(const Parser::Rule logical) {
    auto data = Parser::get::cll_expr_arithmetic(logical);
    TreeAPI::CllExprAddition result;

    result.value = createCllExprTerm(data.first);
    for (size_t i = 0; i < data.operators.size(); i++) {
        char op;
        if (data.operators[i].name() == Parser::Tokens::PLUS)
            op = '+';
        else
            op = '-';
        result.rights.push_back({op, createCllExprTerm(data.sequence[i])});
    }
    return result;
}

TreeAPI::CllExprCompare AST::createCllCompare(const Parser::Rule logical) {
    auto data = Parser::get::cll_expr_compare(logical);
    TreeAPI::CllExprCompare result;

    result.value = createCllExprAddition(data.first);
    for (size_t i = 0; i < data.operators.size(); i++) {
        result.rights.push_back(std::make_pair(createCllCompareOp(data.operators[i]), createCllExprAddition(data.sequence[i])));
    }
    return result;
}

TreeAPI::CllExprLogical AST::createCllExprLogical(const Parser::Rule logical) {
    auto data = Parser::get::cll_expr_logical(logical);
    TreeAPI::CllExprLogical result;
    result.value = createCllCompare(data.left);
    for (size_t i = 0; i < data.op.size(); i++) {
        result.rights.push_back(std::make_pair(createCllLogicalOp(data.op[i]), createCllCompare(data.right[i])));
    }
    return result;
}

TreeAPI::CllExpr AST::createCllExpr(const Parser::Rule &expr) {
    return createCllExprLogical(Parser::get::cll_expr(expr));
}

TreeAPI::CllIf AST::createCllIf(const Parser::Rule &cond) {
    TreeAPI::CllIf newCond;
    auto data = Parser::get::cll_if(cond);
    newCond.expr = createCllExpr(data.expr);
    newCond.stmt = createRuleMembers(Parser::get::cll_block(data.block));
    return newCond;
}

TreeAPI::CllType AST::createCllType(const Parser::Token &rule) {
    TreeAPI::CllType newType;
    auto type = Parser::get::cll_TYPE(rule);
    auto templ = Parser::get::cll_TEMPLATE(type.templ);
    newType.type = type.type;
    if (!templ.first.empty()) {
        newType.templ = {createCllType(templ.first)};
        for (auto next : templ.second) {
            newType.templ.push_back(createCllType(next));
        }
    }
    return newType;
}

TreeAPI::CllVar AST::createCllVar(const Parser::Rule &var) {
    TreeAPI::CllVar newVar;
    auto data = Parser::get::cll_var(var);
    newVar.name = Parser::get::ID(data.id);
    newVar.type = createCllType(data.type);
    newVar.op = Parser::get::cll_OP(Parser::get::cll_ASSIGNMENT_OP(data.op));
    newVar.value = createCllExpr(data.value);
    return newVar;
}
TreeAPI::Cll AST::convertCll(const Parser::Rule &cll) {
    const auto &data = Parser::get::cll(cll);
    TreeAPI::Cll member;
    switch (data.name())
    {
    case Parser::Rules::cll_expr:
        member.value = createCllExpr(Parser::get::cll_expr(cll));
        break;
    case Parser::Rules::cll_if:
        member.value = createCllIf(data);
    case Parser::Rules::cll_var:
        member.value = createCllVar(data);
    default:
        throw Error("[AST] Undefined cll member");
        break;
    }
    return member;
}
/*
    create RuleMember API from Rule_rule AST member
*/
TreeAPI::RuleMember AST::createRuleMember(const Parser::Rule &rule) {
    TreeAPI::RuleMember member;
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
                member.value = TreeAPI::RuleMemberNospace();
                break;
            // temporary solution
            case Parser::Tokens::AUTO_18:
                member.value = TreeAPI::RuleMemberAny();
                break;
            case Parser::Tokens::Rule_CSEQUENCE:
            {
                TreeAPI::RuleMemberCsequence newCsequence;
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
                        throw Error("[AST] Undefined CSEQUENCE type");
                        break;
                    }
                }
                member.value = newCsequence;
                break;
            }
            case Parser::Tokens::Rule_ESCAPED:
                member.value = TreeAPI::RuleMemberEscaped(Parser::get::Rule_ESCAPED(token)[0]);
                break;
            case Parser::Tokens::Rule_HEX:
                member.value = TreeAPI::RuleMemberHex{Parser::get::Rule_HEX(token)};
                break;
            case Parser::Tokens::Rule_BIN:
                member.value = TreeAPI::RuleMemberBin{Parser::get::Rule_BIN(token)};
                break;
            default:
                throw Error("[AST] Undefined Rule_rule member");
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
            member.value = TreeAPI::RuleMemberName {rule_name};
            break;
        }
        case Parser::Rules::Rule_group:
        {
            auto data = Parser::get::Rule_group(rule);
            member.value = TreeAPI::RuleMemberGroup{createRuleMembers(data)};
            break;
        }
        case Parser::Rules::cll:
            // convert cll
            member.value = convertCll(rule);
        default:
            throw Error("[AST] Undefined rule_rule member");
            break;
        }
    }
    if (addToOps) {
        if (!prev_op) {
            // flush
            TreeAPI::RuleMemberOp op {ops};
            newRules.push_back(TreeAPI::RuleMember {.prefix = ops_prefix, .value = op});
            in_op = false;
            ops.clear();
        } else {
            ops.push_back(member);
            prev_op = false;
        }

    }
    return member;
}
std::vector<TreeAPI::RuleMember> AST::createRuleMembers(const std::vector<Parser::Rule> rules) {
    in_op = false;
    prev_op = false;
    add_prev = false;
    for (auto it = rules.begin(); it != rules.end(); it++) {
        auto member = createRuleMember(*it);
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
void AST::createRules(const Parser::Types::Rule_data &rule) {
    TreeAPI::Rule newRule;
    std::vector<std::string> nested_rule_names = getNestedRuleNames(rule);
    fullname.push_back(Parser::get::ID(rule.name));
    newRule.members = createRuleMembers(rule.rule);
    tree_map[fullname] = std::move(newRule);
    for (auto nested : rule.nested_rules) {
        auto r = Parser::get::Rule(nested);
        createRules(r);
    }
    fullname.pop_back();
}
// called every time after convertion
void clearCache() {}