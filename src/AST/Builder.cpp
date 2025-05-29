module AST.Builder;
import AST.types;
import AST.Tree;
import cpuf.printf;
import logging;
import dstd;
import std;
import std.compat;
void AST::Builder::constructor(const Parser::Rule &mod) {
    // pass through tree to get name, spacemode, use and TreeMap
    const auto &entries = Parser::get::main(mod);
    for (auto entry : entries) {
        if (entry.type() == typeid(Parser::Rule)) {
            auto t = std::any_cast<const Parser::Rule&>(entry);
            if (t.name() == Parser::Rules::rule) {
                const auto &data = Parser::get::rule(std::any_cast<const Parser::Rule&>(entry));
                createRules(data);
            } else if (t.name() == Parser::Rules::_use) {
                // accamulate use here
                const auto & use = Parser::get::_use(t);
                const auto &first_key = Parser::get::_use_unit(use.first);
                this->use[Parser::get::ID(first_key.name)] = createRvalue(first_key.value);
                for (const auto key : use.second) {
                    const auto &k = Parser::get::_use_unit(key);
                    this->use[Parser::get::ID(k.name)] = createRvalue(k.value);
                }
            } else {
                throw Error("Undefined tree member");
            }
        } else if (entry.type() == typeid(Parser::Token)) {
            // is token
            auto t = std::any_cast<const Parser::Token&>(entry);
            if (t.name() == Parser::Tokens::SPACEMODE) {
                // handle spacemode
                const auto &spacemode = Parser::get::SPACEMODE(t);
                if (spacemode == "mixed") {
                    this->spacemode = SpacemodeStates::MIXED;
                }
                // todo: add other spacemode modes
            } else if (t.name() == Parser::Tokens::NAME) {
                // handle name
                const auto &name = Parser::get::NAME(t);
                const auto &name_str = Parser::get::ID(name);
                this->name = name_str;
            } else 
                throw Error("Undefined tree member");
        } else {
            throw Error("Undefined type for entry");
        }
    }
}
void AST::Builder::constructor(const stdu::vector<Parser::Rule> &modules) {
    for (const auto &mod : modules) {
        constructor(mod);
    }
}
AST::Array AST::Builder::createArray(const Parser::Rule &array) {
    AST::Array arr;
    auto data = Parser::get::array(array);
    for (auto el : data) {
        arr.value.push_back(createCllExpr(el));
    }
    return arr;
}
AST::Object AST::Builder::createObject(const Parser::Rule &object) {
    AST::Object obj;
    // todo
    // auto data = Parser::get::object(object);
    // obj.value[data.key]
    return obj;
}
AST::String AST::Builder::createString(const Parser::Token &token) {
    return AST::String {Parser::get::STRING(token)};
}
AST::Number AST::Builder::createNumber(const Parser::Token &number) {
    AST::Number num;
    auto data = Parser::get::NUMBER(number);
    num.dec = data.dec;
    num.main = data.main;
    if (!data.sign.empty()) {
        num.sign = data.sign[0];
    }
    return num;
}

AST::Boolean AST::Builder::createBoolean(const Parser::Token boolean) {
    return AST::Boolean {Parser::get::BOOLEAN(boolean)};
}

AST::rvalue AST::Builder::createRvalue(const Parser::Rule &rule) {
    AST::rvalue value;
    if (rule.data().type() == typeid(Parser::Rule)) {
        const auto &dt = std::any_cast<const Parser::Rule&>(rule.data());
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
        const auto &dt = std::any_cast<const Parser::Token&>(rule.data());
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
            value.value = AST::At {};
            break;
        case Parser::Tokens::ID:
            value.value = AST::ID {Parser::get::ID(dt)};
            break;
        default:
            throw Error("Undefined token in any_data");
            break;
        }
    }
    return value;
}

AST::CllFunctionArguments AST::Builder::createCllFunctionArguments(const Parser::Rule &rule) {
    AST::CllFunctionArguments arguments;
    // implement later
    // auto data = Parser::get::cll_function_arguments(rule);
    // arguments.expr = {createCllExpr(data.first)};
    // for (auto el : data.second) {
    //     arguments.expr.push_back();
    // }
    return arguments;
}

AST::CllFunctionCall AST::Builder::createCllFunctionCall(const Parser::Rule &rule) {
    const auto &data = Parser::get::cll_function_call(rule);
    AST::CllFunctionCall new_function_call;
    new_function_call.name = Parser::get::ID(data.name);
    new_function_call.body = createCllFunctionArguments(data.body);
    return new_function_call;
}

AST::CllVariable AST::Builder::createCllVariable(const Parser::Rule &rule) {
    AST::CllVariable newVar;
    const auto &var = Parser::get::cll__variable(rule);
    newVar.name = Parser::get::ID(var.name);
    if (!var.brace_expression.empty())
        newVar.braceExpression = std::make_optional(createCllExpr(var.brace_expression));

    if (!var.pos.empty()) {
        newVar.post_increament = var.pos.name() == Parser::Tokens::AUTO_10;
    }
    if (!var.pre.empty()) {
        newVar.pre_increament = var.pre.name() == Parser::Tokens::AUTO_10;
    }
    return newVar;
}

AST::CllCompareOp AST::Builder::createCllCompareOp(const Parser::Token &token) {
    return AST::CllCompareOp {Parser::get::cll_COMPARE_OP(token)};
}

AST::CllLogicalOp AST::Builder::createCllLogicalOp(const Parser::Token &token) {
    AST::CllLogicalOp result;
    result.isAnd = token.name() == Parser::Tokens::cll_LOGICAL_AND;
    return result;
}

AST::CllExprValue AST::Builder::createCllExprValue(const Parser::Rule &logical) {
    auto data = Parser::get::cll_expr_value(logical);
    AST::CllExprValue result;
    switch (data.name())
    {
    case Parser::Rules::cll_expr_group:
        result.value = std::make_shared<AST::CllExprGroup>(AST::CllExprGroup {createCllExpr(Parser::get::cll_expr(data))});
        break;
    case Parser::Rules::cll__variable:
        result.value = std::make_shared<AST::CllVariable>(createCllVariable(data));
        break;
    case Parser::Rules::cll_function_call:
        result.value = createCllFunctionCall(data);
        break;
    case Parser::Rules::rvalue:
        result.value = createRvalue(data);
        break;
    default:
        throw Error("[AST] Undefined node in createCllValue");
        break;
    }
    return result;
}

AST::CllExprTerm AST::Builder::createCllExprTerm(const Parser::Rule &term) {
    auto data = Parser::get::cll_expr_term(term);
    AST::CllExprTerm result;

    result.value = createCllExprValue(data.first);
    for (size_t i = 0; i < data.operators.size(); i++) {
        char op;
        if (data.operators[i].name() == Parser::Tokens::PLUS)
            op = '+';
        else
            op = '-';
        result.rights.push_back(std::pair<char, AST::CllExprValue> {op, createCllExprValue(data.sequence[i])});
    }
    return result;
}

AST::CllExprAddition AST::Builder::createCllExprAddition(const Parser::Rule &addition) {
    auto data = Parser::get::cll_expr_arithmetic(addition);
    AST::CllExprAddition result;

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

AST::CllExprCompare AST::Builder::createCllExprCompare(const Parser::Rule &compare) {
    auto data = Parser::get::cll_expr_compare(compare);
    AST::CllExprCompare result;

    result.value = createCllExprAddition(data.first);
    for (size_t i = 0; i < data.operators.size(); i++) {
        result.rights.push_back(std::make_pair(createCllCompareOp(data.operators[i]), createCllExprAddition(data.sequence[i])));
    }
    return result;
}

AST::CllExprLogical AST::Builder::createCllExprLogical(const Parser::Rule &logical) {
    auto data = Parser::get::cll_expr_logical(logical);
    AST::CllExprLogical result;
    result.value = createCllExprCompare(data.left);
    for (size_t i = 0; i < data.op.size(); i++) {
        result.rights.push_back(std::make_pair(createCllLogicalOp(data.op[i]), createCllExprCompare(data.right[i])));
    }
    return result;
}

AST::CllExpr AST::Builder::createCllExpr(const Parser::Rule &expr) {
    return AST::CllExpr {createCllExprLogical(Parser::get::cll_expr(expr)) };
}

AST::CllIf AST::Builder::createCllIf(const Parser::Rule &cond) {
    AST::CllIf newCond;
    auto data = Parser::get::cll__if(cond);
    newCond.expr = createCllExpr(data.expr);
    Builder newAst(Parser::get::cll_stmt(data.stmt), nested_rule_names, false);
    newAst.build();
    newCond.stmt = newAst.newRules;
    return newCond;
}

AST::CllType AST::Builder::createCllType(const Parser::Token &rule) {
    AST::CllType newType;
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

AST::CllVar AST::Builder::createCllVar(const Parser::Rule &var) {
    AST::CllVar newVar;
    auto data = Parser::get::cll__var(var);
    newVar.name = Parser::get::ID(data.id);
    newVar.type = createCllType(data.type);
    newVar.op = Parser::get::cll_ASSIGNMENT_OP(data.op);
    newVar.value = createCllExpr(data.value);
    return newVar;
}
AST::Cll AST::Builder::convertCll(const Parser::Rule &cll) {
    const auto &data = Parser::get::cll(cll);
    AST::Cll member;
    switch (data.name())
    {
    case Parser::Rules::cll_expr:
        member.value = createCllExpr(Parser::get::cll_expr(cll));
        break;
    case Parser::Rules::cll__if:
        member.value = createCllIf(data);
    case Parser::Rules::cll__var:
        member.value = createCllVar(data);
    default:
        throw Error("[AST] Undefined cll member");
        break;
    }
    return member;
}
void AST::Builder::flushOpSequence() {
    if (!ops.empty()) {
        AST::RuleMemberOp op{ops};
        newRules.push_back(AST::RuleMember{
            .prefix = ops_prefix,
            .value = op
        });
        ops.clear();
        ops_prefix = {};
    }
    in_op = false;
    prev_op = false;

}

/*
    create RuleMember API from Rule_rule AST member
*/
void AST::Builder::createRuleMember(const Parser::Rule &rule) {
    AST::RuleMember member;
    const auto &rule_r = Parser::get::rule_member(rule);
    if (!rule_r.prefix.empty()) {
        member.prefix.is_key_value = rule_r.prefix.name() == Parser::Rules::rule_keyvalue;
        // get prefix
        if (rule_r.prefix.name() == Parser::Rules::rule_keyvalue) {
            auto data = Parser::get::rule_keyvalue(rule_r.prefix);
            if (!data.empty())
                member.prefix.name = Parser::get::ID(data);
        } else {
            auto data = Parser::get::rule_value(rule_r.prefix);
            member.prefix.name = Parser::get::ID(data);
        }
    }

    // get quantifier
    if (!rule_r.quantifier.empty()) {
        const auto &q = Parser::get::rule_quantifier(rule_r.quantifier);
        switch (q.name()) {
            case Parser::Tokens::PLUS:
                member.quantifier = '+';
                break;
            case Parser::Tokens::MULTIPLE:
                member.quantifier = '*';
                break;
            case Parser::Tokens::QUESTION_MARK:
                member.quantifier = '?';
                break;
            default:
                member.quantifier = '\0';
        }
    }

    // get value
    if (rule_r.val.type() == typeid(Parser::Token)) {
        const auto &token = std::any_cast<const Parser::Token&>(rule_r.val);
        switch (token.name()) {
            case Parser::Tokens::STRING:
                member.value = AST::String {Parser::get::STRING(token)};
                break;
            case Parser::Tokens::rule_OP:
                if (!in_op) {
                    in_op = true;
                    prev_op = true;

                    auto prev_member = newRules.back();
                    if (prev_member.empty())
                        throw Error("Empty previous member");
                    ops_prefix = prev_member.prefix;
                    prev_member.prefix.clear();
                    ops.push_back(prev_member);

                    newRules.pop_back();
                }
                prev_op = true;
                return; // skip adding this token to newRules
            case Parser::Tokens::rule_NOSPACE:
                if (!member.prefix.empty()) {
                    throw Error("Prefix and NOSPACE can't be used together");
                }
                member.value = AST::RuleMemberNospace();
                break;
            // temporary solution
            case Parser::Tokens::DOT:
                member.value = AST::RuleMemberAny();
                break;
            case Parser::Tokens::rule_CSEQUENCE:
            {
                AST::RuleMemberCsequence newCsequence;
                const auto &csequence_data = Parser::get::rule_CSEQUENCE(token);
                if (csequence_data._not == '^') {
                    newCsequence.negative = true;
                }
                for (const auto &data : csequence_data.val) {
                    switch (data.name())
                    {
                    case Parser::Tokens::rule_CSEQUENCE_SYMBOL:
                        newCsequence.characters.push_back(Parser::get::rule_CSEQUENCE_SYMBOL(data)[0]);
                        break;
                    case Parser::Tokens::rule_CSEQUENCE_ESCAPE:
                        newCsequence.characters.push_back(Parser::get::rule_CSEQUENCE_ESCAPE(data));
                        break;
                    case Parser::Tokens::rule_CSEQUENCE_DIAPASON:
                    {
                        const auto &diapason = Parser::get::rule_CSEQUENCE_DIAPASON(data);
                        newCsequence.diapasons.push_back({Parser::get::rule_CSEQUENCE_SYMBOL(diapason.from)[0], Parser::get::rule_CSEQUENCE_SYMBOL(diapason.to)[0]});
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
            case Parser::Tokens::rule_ESCAPED:
                member.value = AST::RuleMemberEscaped(Parser::get::rule_ESCAPED(token));
                break;
            case Parser::Tokens::rule_HEX:
                member.value = AST::RuleMemberHex{Parser::get::rule_HEX(token)};
                break;
            case Parser::Tokens::rule_BIN:
                member.value = AST::RuleMemberBin{Parser::get::rule_BIN(token)};
                break;
            case Parser::Tokens::LINEAR_COMMENT:
                break;
            default:
                throw Error("[AST] Undefined Rule_rule member");
        }
    } else {
        auto rule = std::any_cast<const Parser::Rule&>(rule_r.val);
        switch (rule.name())
        {
        case Parser::Rules::rule_name:
        {
            auto data = Parser::get::rule_name(rule);

            stdu::vector<std::string> rule_name;
            auto res = std::find_if(nested_rule_names.begin(), nested_rule_names.end(), [&data](const  std::pair<std::string, stdu::vector<std::string>> &p) {
                return p.first == Parser::get::ID(data.name);
            });
            if (res != nested_rule_names.end()) {
                rule_name = res->second;
            } else {
                if (!data.is_nested.empty()) {
                    rule_name.assign(fullname.begin(), fullname.end());
                }
                rule_name.push_back(Parser::get::ID(data.name));
            }
            for (const auto &nested : data.nested_name) {
                rule_name.push_back(Parser::get::ID(nested));
            }
            member.value = AST::RuleMemberName {rule_name};
            break;
        }
        case Parser::Rules::rule_group:
        {
            const auto &data = Parser::get::rule_group(rule);
            stdu::vector<Parser::Rule> ustd_c = data;
            Builder group_ast(ustd_c, nested_rule_names, false);
            group_ast.build();
            member.value = AST::RuleMemberGroup {group_ast.newRules};
            break;
        }
        case Parser::Rules::cll:
            // convert cll
            member.value = convertCll(rule);
            break;
        default:
            throw Error("[AST] Undefined rule_rule member");
            break;
        }
    }
    if (in_op) {
        if (prev_op) {
            ops.push_back(member);
            prev_op = false;
        } else {
            flushOpSequence();
            newRules.push_back(member);
        }
    } else {
        newRules.push_back(member);
    }
}
void AST::Builder::createRuleMembers(const stdu::vector<Parser::Rule> &rules) {
    for (const auto &rule : rules) {
        createRuleMember(rule);
    }
    if (!ops.empty())
        flushOpSequence();
}
void AST::Builder::getNestedRuleNames(const Parser::Types::rule &rule) {
    for (const auto &el : rule.nested_rules) {
        const auto &nested_r = Parser::get::rule_nested_rule(el);
        const auto &r = Parser::get::rule(nested_r);
        const auto &name = Parser::get::ID(r.name);
        auto new_name = fullname;
        new_name.push_back(name);
        nested_rule_names.emplace_back(name, new_name);
    }
}
AST::DataBlock AST::Builder::createDataBlock(const Parser::Rule &rule) {
    AST::DataBlock data_block;
    if (rule.empty())
        return {};

    auto data = Parser::get::rule_data_block(rule);

    switch (data.name()) {
        case Parser::Rules::rule_data_block_regular_datablock: {
            if (data.data().type() == typeid(Parser::Rule)) {
                const auto &dt = std::any_cast<const Parser::Rule&>(data.data());
                if (dt.empty())
                    return {};
                data_block.value = AST::RegularDataBlock{
                    createCllExpr(dt)
                };
            } else {
                // key-based data block
                AST::RegularDataBlockWKeys result;
                const auto &keys = std::any_cast<const Parser::arr_t<Parser::Rule>&>(data.data());
                for (const auto &k : keys) {
                    const auto &key = Parser::get::rule_data_block_regular_datablock_key(k);
                    result[Parser::get::ID(key.name)] = createCllExpr(key.dt);
                }
                data_block.value = result;
            }
            break;
        }
        case Parser::Rules::rule_data_block_templated_datablock: {
            AST::TemplatedDataBlock result;
            const auto &tdbd = Parser::get::rule_data_block_templated_datablock(data);
            result.names.push_back(Parser::get::ID(tdbd.first_name));
            for (const auto &name : tdbd.second_name) {
                result.names.push_back(Parser::get::ID(name));
            }
            data_block.value = result;
            break;
        }
        default:
            throw Error("Undefined data block");
    }

    return data_block;
}
// build Tree API from AST
void AST::Builder::createRules(const Parser::Types::rule &rule) {
    AST::Rule newRule;
    if (rule.rule.empty())
        return;
    fullname.push_back(Parser::get::ID(rule.name));
    size_t previous_size = nested_rule_names.size();
    getNestedRuleNames(rule);
    createRuleMembers(rule.rule);
    newRule.rule_members = newRules;
    newRule.data_block = createDataBlock(rule.data_block);
    tree_map[fullname] = newRule;
    newRules.clear();
    for (const auto &nested : rule.nested_rules) {
        const auto &nr = Parser::get::rule_nested_rule(nested);
        const auto &r = Parser::get::rule(nr);
        createRules(r);
    }
    if (!nested_rule_names.empty() && !rule.nested_rules.empty()) {
        nested_rule_names.erase(nested_rule_names.begin() + previous_size, nested_rule_names.end());
    }
    fullname.pop_back();
}
void AST::Builder::build(const Parser::Rule &mod) {
    // pass through tree to get name, spacemode, use and TreeMap
    const auto &entries = Parser::get::main(mod);
    for (auto entry : entries) {
        if (entry.type() == typeid(Parser::Rule)) {
            auto t = std::any_cast<const Parser::Rule&>(entry);
            if (t.name() == Parser::Rules::rule) {
                const auto &data = Parser::get::rule(std::any_cast<const Parser::Rule&>(entry));
                createRules(data);
            } else if (t.name() == Parser::Rules::_use) {
                // accamulate use here
                const auto & use = Parser::get::_use(t);
                const auto &first_key = Parser::get::_use_unit(use.first);
                this->use[Parser::get::ID(first_key.name)] = createRvalue(first_key.value);
                for (const auto key : use.second) {
                    const auto &k = Parser::get::_use_unit(key);
                    this->use[Parser::get::ID(k.name)] = createRvalue(k.value);
                }
            } else {
                throw Error("Undefined tree member");
            }
        } else if (entry.type() == typeid(Parser::Token)) {
            // is token
            auto t = std::any_cast<const Parser::Token&>(entry);
            if (t.name() == Parser::Tokens::SPACEMODE) {
                // handle spacemode
                const auto &spacemode = Parser::get::SPACEMODE(t);
                if (spacemode == "mixed") {
                    this->spacemode = SpacemodeStates::MIXED;
                }
                // todo: add other spacemode modes
            } else if (t.name() == Parser::Tokens::NAME) {
                // handle name
                const auto &name = Parser::get::NAME(t);
                const auto &name_str = Parser::get::ID(name);
                this->name = name_str;
            } else
                throw Error("Undefined tree member");
        } else {
            throw Error("Undefined type for entry");
        }
    }
}
void AST::Builder::build(const stdu::vector<Parser::Rule> &modules) {
    for (const auto &mod : modules) {
        constructor(mod);
    }
}
void AST::Builder::build() {
    if (isModuleConstructor) {
        if (isModule) {
            build(*modules);
        } else {
            createRuleMembers(*modules);
        }
    } else {
        if (modules != nullptr) {
            build(*modules);
        } else {
            build(*md);
        }
    }
}
