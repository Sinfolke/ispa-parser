module AST;
import ASTPass;
import logging;
import TreeAPI;
import LLIRBuilder;
import LLIRBuilderDataWrapper;
import LLIRRuleMemberBuilder;
import LLIRBuilderData;
import cpuf.printf;
import std;
import std.compat;
void AST::constructor(const Parser::Rule &mod) {
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
std::string &AST::getName() {
    return name;
}
AST::SpacemodeStates &AST::getSpacemode() {
    return spacemode;
}
std::vector<TreeAPI::RuleMember> &AST::getRules() {
    return newRules;
}
TreeAPI::Array AST::createArray(const Parser::Rule &array) {
    TreeAPI::Array arr;
    auto data = Parser::get::array(array);
    for (auto el : data) {
        arr.value.push_back(createCllExpr(el));
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
            value.value = TreeAPI::At {};
            break;
        case Parser::Tokens::ID:
            value.value = TreeAPI::ID {Parser::get::ID(dt)};
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
    const auto &data = Parser::get::cll_function_call(rule);
    TreeAPI::CllFunctionCall new_function_call;
    new_function_call.name = Parser::get::ID(data.name);
    new_function_call.body = createCllFunctionArguments(data.body);
    return new_function_call;
}

TreeAPI::CllVariable AST::createCllVariable(const Parser::Rule &rule) {
    TreeAPI::CllVariable newVar;
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

TreeAPI::CllCompareOp AST::createCllCompareOp(const Parser::Token &token) {
    return TreeAPI::CllCompareOp {Parser::get::cll_COMPARE_OP(token)};
}

TreeAPI::CllLogicalOp AST::createCllLogicalOp(const Parser::Token &token) {
    TreeAPI::CllLogicalOp result;
    result.isAnd = token.name() == Parser::Tokens::cll_LOGICAL_AND;
    return result;
}

TreeAPI::CllExprValue AST::createCllExprValue(const Parser::Rule &logical) {
    auto data = Parser::get::cll_expr_value(logical);
    TreeAPI::CllExprValue result;
    switch (data.name())
    {
    case Parser::Rules::cll_expr_group:
        result.value = std::make_shared<TreeAPI::CllExprGroup>(TreeAPI::CllExprGroup {createCllExpr(Parser::get::cll_expr(data))});
        break;
    case Parser::Rules::cll__variable:
        result.value = std::make_shared<TreeAPI::CllVariable>(createCllVariable(data));
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

TreeAPI::CllExprTerm AST::createCllExprTerm(const Parser::Rule &term) {
    auto data = Parser::get::cll_expr_term(term);
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

TreeAPI::CllExprAddition AST::createCllExprAddition(const Parser::Rule &addition) {
    auto data = Parser::get::cll_expr_arithmetic(addition);
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

TreeAPI::CllExprCompare AST::createCllExprCompare(const Parser::Rule &compare) {
    auto data = Parser::get::cll_expr_compare(compare);
    TreeAPI::CllExprCompare result;

    result.value = createCllExprAddition(data.first);
    for (size_t i = 0; i < data.operators.size(); i++) {
        result.rights.push_back(std::make_pair(createCllCompareOp(data.operators[i]), createCllExprAddition(data.sequence[i])));
    }
    return result;
}

TreeAPI::CllExprLogical AST::createCllExprLogical(const Parser::Rule &logical) {
    auto data = Parser::get::cll_expr_logical(logical);
    TreeAPI::CllExprLogical result;
    result.value = createCllExprCompare(data.left);
    for (size_t i = 0; i < data.op.size(); i++) {
        result.rights.push_back(std::make_pair(createCllLogicalOp(data.op[i]), createCllExprCompare(data.right[i])));
    }
    return result;
}

TreeAPI::CllExpr AST::createCllExpr(const Parser::Rule &expr) {
    return TreeAPI::CllExpr {createCllExprLogical(Parser::get::cll_expr(expr)) };
}

TreeAPI::CllIf AST::createCllIf(const Parser::Rule &cond) {
    TreeAPI::CllIf newCond;
    auto data = Parser::get::cll__if(cond);
    newCond.expr = createCllExpr(data.expr);
    AST newAst(Parser::get::cll_stmt(data.stmt), nested_rule_names, false);
    newCond.stmt = newAst.getRules();
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
    auto data = Parser::get::cll__var(var);
    newVar.name = Parser::get::ID(data.id);
    newVar.type = createCllType(data.type);
    newVar.op = Parser::get::cll_ASSIGNMENT_OP(data.op);
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
void AST::flushOpSequence() {
    if (!ops.empty()) {
        TreeAPI::RuleMemberOp op{ops};
        newRules.push_back(TreeAPI::RuleMember{
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
void AST::createRuleMember(const Parser::Rule &rule) {
    TreeAPI::RuleMember member;
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
                member.value = TreeAPI::String {Parser::get::STRING(token)};
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
                member.value = TreeAPI::RuleMemberNospace();
                break;
            // temporary solution
            case Parser::Tokens::DOT:
                member.value = TreeAPI::RuleMemberAny();
                break;
            case Parser::Tokens::rule_CSEQUENCE:
            {
                TreeAPI::RuleMemberCsequence newCsequence;
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
                member.value = TreeAPI::RuleMemberEscaped(Parser::get::rule_ESCAPED(token));
                break;
            case Parser::Tokens::rule_HEX:
                member.value = TreeAPI::RuleMemberHex{Parser::get::rule_HEX(token)};
                break;
            case Parser::Tokens::rule_BIN:
                member.value = TreeAPI::RuleMemberBin{Parser::get::rule_BIN(token)};
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

            std::vector<std::string> rule_name;
            auto res = std::find_if(nested_rule_names.begin(), nested_rule_names.end(), [&data](const  std::pair<std::string, std::vector<std::string>> &p) {
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
            member.value = TreeAPI::RuleMemberName {rule_name};
            break;
        }
        case Parser::Rules::rule_group:
        {
            auto data = Parser::get::rule_group(rule);
            AST group_ast(data, nested_rule_names, false);
            member.value = TreeAPI::RuleMemberGroup {group_ast.getRules()};
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
void AST::createRuleMembers(const std::vector<Parser::Rule> &rules) {
    for (const auto &rule : rules) {
        createRuleMember(rule);
    }
    if (!ops.empty())
        flushOpSequence();
}
void AST::getNestedRuleNames(const Parser::Types::rule &rule) {
    for (const auto &el : rule.nested_rules) {
        const auto &nested_r = Parser::get::rule_nested_rule(el);
        const auto &r = Parser::get::rule(nested_r);
        const auto &name = Parser::get::ID(r.name);
        auto new_name = fullname;
        new_name.push_back(name);
        nested_rule_names.emplace_back(name, new_name);
    }
}
TreeAPI::DataBlock AST::createDataBlock(const Parser::Rule &rule) {
    TreeAPI::DataBlock data_block;
    if (rule.empty())
        return {};

    auto data = Parser::get::rule_data_block(rule);

    switch (data.name()) {
        case Parser::Rules::rule_data_block_regular_datablock: {
            if (data.data().type() == typeid(Parser::Rule)) {
                const auto &dt = std::any_cast<const Parser::Rule&>(data.data());
                if (dt.empty())
                    return {};
                data_block.value = TreeAPI::RegularDataBlock{
                    createCllExpr(dt)
                };
            } else {
                // key-based data block
                TreeAPI::RegularDataBlockWKeys result;
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
            TreeAPI::TemplatedDataBlock result;
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
void AST::createRules(const Parser::Types::rule &rule) {
    TreeAPI::Rule newRule;
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

// helper functions
auto AST::getFirstSet() -> First & {
    if (first.empty())
        constructFirstSet();
    return first;
}
auto AST::getFollowSet() -> Follow & {
    if (follow.empty())
        constructFollowSet();
    return follow;
}
auto AST::getRawFirstSet() -> First & {
    return first;
}
auto AST::getRawFollowSet() -> Follow & {
    return follow;
}


auto AST::getTerminals() -> std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> set;
    for (const auto &[name, value] : tree_map) {
        if (corelib::text::isUpper(name.back()))
            set.push_back(name);
    }
    return set;
}
auto AST::getNonTerminals() -> std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> set;
    for (const auto &[name, value] : tree_map) {
        if (corelib::text::isLower(name.back()))
            set.push_back(name);
    }
    return set;
}
void AST::getUsePlacesTable(const std::vector<TreeAPI::RuleMember> &members, const std::vector<std::string> &name) {
    for (const auto &member : members) {
        if (member.isGroup()) {
            getUsePlacesTable(member.getGroup().values, name);
        } else if (member.isOp()) {
            getUsePlacesTable(member.getOp().options, name);
        } else if (member.isName()) {
            use_places[member.getName().name].push_back(name);
        }
    }
}
auto AST::createUsePlacesTable() -> UsePlaceTable& {
    for (const auto &[name, value] : tree_map) {
        getUsePlacesTable(value.rule_members, name);
    }
    return use_places;
}
auto AST::getUsePlacesTable() -> UsePlaceTable& {
    if (use_places.empty())
        createUsePlacesTable();
    return use_places;
}
auto AST::compute_group_length(const std::vector<TreeAPI::RuleMember> &group) -> size_t {
    size_t count = 0;
    for (auto &rule : group) {
        if (rule.isGroup() && rule.quantifier == '\0') {
            count += compute_group_length(rule.getGroup().values);
        } else count++;
    }
    return count;
};
void AST::transform_helper(
    std::vector<TreeAPI::RuleMember> &members,
    const std::vector<std::string> &fullname,
    utype::unordered_map<std::vector<std::string>, std::pair<char, std::vector<std::string>>> &replacements
) {
    for (size_t i = 0; i < members.size(); ++i) {
        auto &member = members[i];

        if (member.isGroup()) {
            auto data = member.getGroup();
            transform_helper(data.values, fullname, replacements);  // recursive call

            if (member.quantifier == '\0') {
                // Inline group content directly
                members.erase(members.begin() + i);
                members.insert(members.begin() + i, data.values.begin(), data.values.end());
                i += data.values.size() - 1;
                continue;
            }

            // Create a rule for the quantified group
            std::string quant_rule_name = "__grp" + std::to_string(i);
            auto quant_fullname = fullname;
            quant_fullname.back() = quant_rule_name;

            // Replace the group with a reference to the new rule
            members[i] = TreeAPI::RuleMember {
                .value = TreeAPI::RuleMemberName {.name = quant_fullname},
                .quantifier = '\0'
            };

            std::vector<std::vector<TreeAPI::RuleMember>> new_alts;

            switch (member.quantifier) {
                case '?':
                    new_alts.push_back({});
                    new_alts.push_back(data.values);
                    break;

                case '+': {
                    std::string tail_name = quant_rule_name + "_tail";
                    auto tail_fullname = quant_fullname;
                    tail_fullname.back() = tail_name;

                    auto base = data.values;
                    base.push_back(TreeAPI::RuleMember {
                        .value = TreeAPI::RuleMemberName {.name = tail_fullname}
                    });
                    new_alts.push_back(base);

                    std::vector<std::vector<TreeAPI::RuleMember>> tail_alts = {
                        {},
                        data.values
                    };
                    tail_alts[1].push_back(TreeAPI::RuleMember {
                        .value = TreeAPI::RuleMemberName {.name = tail_fullname}
                    });

                    for (auto &alt : tail_alts)
                        initial_item_set[tail_fullname].push_back(TreeAPI::Rule {.rule_members = alt});
                    break;
                }

                case '*': {
                    new_alts.push_back({});
                    auto recur = data.values;
                    recur.push_back(TreeAPI::RuleMember {
                        .value = TreeAPI::RuleMemberName {.name = quant_fullname}
                    });
                    new_alts.push_back(recur);
                    break;
                }
            }

            for (auto &alt : new_alts) {
                initial_item_set[quant_fullname].push_back(TreeAPI::Rule {.rule_members = alt});
            }

            continue;
        }

        if (member.isOp()) {
            auto data = member.getOp();
            transform_helper(data.options, fullname, replacements);

            std::string rule_name = "__rop" + std::to_string(i);
            auto new_fullname = fullname;
            new_fullname.back() = rule_name;

            members[i] = TreeAPI::RuleMember {
                .value = TreeAPI::RuleMemberName {.name = new_fullname}
            };

            for (auto &opt : data.options) {
                initial_item_set[new_fullname].push_back(TreeAPI::Rule {.rule_members = {opt}});
            }

            continue;
        }

        // Handle standalone quantifier case (e.g., id?, id+, id*)
        if (member.quantifier != '\0') {
            auto find = replacements.find(fullname);
            if (find != replacements.end() && find->second.first == member.quantifier) {
                members[i] = TreeAPI::RuleMember {
                    .value = TreeAPI::RuleMemberName {.name = find->second.second},
                    .quantifier = '\0'
                };
                continue;
            }

            std::string quant_rule_name = fullname.size() == 1
                ? fullname.back() + "__q" + std::to_string(i)
                : "__q" + std::to_string(i);

            auto quant_fullname = fullname;
            quant_fullname.back() = quant_rule_name;

            TreeAPI::RuleMember replaced = member;
            replaced.quantifier = '\0';

            members[i] = TreeAPI::RuleMember {
                .value = TreeAPI::RuleMemberName {.name = quant_fullname},
                .quantifier = '\0'
            };

            std::vector<std::vector<TreeAPI::RuleMember>> new_alts;
            switch (member.quantifier) {
                case '?':
                    new_alts.push_back({});
                    new_alts.push_back({replaced});
                    break;
                case '+': {
                    std::string tail_name = quant_rule_name + "_tail";
                    auto tail_fullname = quant_fullname;
                    tail_fullname.back() = tail_name;

                    new_alts.push_back({
                        replaced,
                        TreeAPI::RuleMember {
                            .value = TreeAPI::RuleMemberName {.name = tail_fullname}
                        }
                    });

                    std::vector<std::vector<TreeAPI::RuleMember>> tail_alts = {
                        {},
                        {
                            replaced,
                            TreeAPI::RuleMember {
                                .value = TreeAPI::RuleMemberName {.name = tail_fullname}
                            }
                        }
                    };
                    for (auto &alt : tail_alts) {
                        initial_item_set[tail_fullname].push_back(TreeAPI::Rule {.rule_members = alt});
                    }
                    break;
                }
                case '*':
                    new_alts.push_back({});
                    new_alts.push_back({
                        replaced,
                        TreeAPI::RuleMember {
                            .value = TreeAPI::RuleMemberName {.name = quant_fullname}
                        }
                    });
                    break;
            }

            for (auto &alt : new_alts) {
                initial_item_set[quant_fullname].push_back(TreeAPI::Rule {.rule_members = alt});
            }
        }
    }
}
void AST::transform() {
    std::vector<std::vector<std::string>> keys;
    for (const auto &pair : initial_item_set) {
        keys.push_back(pair.first);
    }

    utype::unordered_map<std::vector<std::string>, std::pair<char, std::vector<std::string>>> replacement;

    for (const auto &name : keys) {
        cpuf::printf("Processing rule: {}", name);
        if (corelib::text::isUpper(name.back()))
            continue;
        auto it = initial_item_set.find(name);
        if (it == initial_item_set.end())
            throw Error("Previous key dissappeared");
        transform_helper(it->second[0].rule_members, name, replacement);
    }
}
void AST::createInitialItemSet() {
    if (!initial_item_set.empty())
        return;
    for (auto &[name, value] : tree_map) {
        initial_item_set[name] = {value};
    }
    transform();
}
auto AST::getInitialItemSet() -> InitialItemSet & {
    return initial_item_set;
}
auto AST::getInitialItemSet() const -> const InitialItemSet & {
    return initial_item_set;
}

enum class Types {
    string, Rule_escaped, Rule_csequence, Rule_bin, Rule_hex, Rule_any, cll, name, group, nospace, op, empty
};
Types getTypes(const TreeAPI::String&) { return Types::string; }
Types getTypes(const TreeAPI::RuleMemberEscaped &) { return Types::Rule_escaped; }
Types getTypes(const TreeAPI::RuleMemberCsequence &) { return Types::Rule_csequence; }
Types getTypes(const TreeAPI::RuleMemberBin&) { return Types::Rule_bin; }
Types getTypes(const TreeAPI::RuleMemberHex&) { return Types::Rule_hex; }
Types getTypes(const TreeAPI::RuleMemberAny&) { return Types::Rule_any; }
Types getTypes(const TreeAPI::Cll&) { return Types::cll; }
// never meet types
Types getTypes(const TreeAPI::RuleMemberName&) { return Types::name; };
Types getTypes(const TreeAPI::RuleMemberGroup&) { return Types::group; }
Types getTypes(const TreeAPI::RuleMemberNospace&) {return Types::nospace; }
Types getTypes(const TreeAPI::RuleMemberOp&) { return Types::op; }
Types getTypes(const std::monostate&) { return Types::empty; }
void AST::constructFirstSet(const std::vector<TreeAPI::Rule>& options, const std::vector<std::string> &nonterminal, bool &changed) {
    for (const auto &option : options) {
        bool nullable_prefix = true;
        for (const auto &member : option.rule_members) {
            if (member.isNospace())
                continue;
            std::visit([&](const auto &f) -> bool {
                cpuf::printf("type: {}", (int) getTypes(f));
                cpuf::printf("f: {}", typeid(f).name());
                return 0;
            }, member.value);
            if (!member.isName())
                throw Error("Non-RuleMemberName class, rule {}", nonterminal);
            const auto &rule = member.getName();
            auto &currentFirst = first[nonterminal];
            if (rule.name == nonterminal) {
                continue;
            }
            if (corelib::text::isLower(rule.name.back())) {
                // Nonterminal: take FIRST(rule.fullname)
                // cpuf::printf("[nonterminal %$] ", rule.fullname);
                auto find = first.find(rule.name);
                const auto &otherFirst = first[rule.name];
                // cpuf::printf("FIRST(%$) = ", rule.fullname);
                for (const auto& el : otherFirst) {
                    // cpuf::printf("%$, ", el);
                }
                auto currentFirst_size = currentFirst.size();
                currentFirst.insert(otherFirst.begin(), otherFirst.end());
                if (currentFirst_size > currentFirst.size()) {
                    changed = true;
                    // cpuf::printf("(changed), ");
                } else {
                    // cpuf::printf("(not changed), ");
                }
                // Check if nullable
                bool isNullable = false;
                auto &rules = initial_item_set[rule.name];
                for (const auto &r : rules) {
                    bool break_this = false;
                    for (const auto &member : r.rule_members) {
                        if (member.empty()) {
                            isNullable = true;
                            break_this = true;
                            break;
                        }
                    }
                    if (break_this)
                        break;
                }

                if (!isNullable) {
                    nullable_prefix = false;
                    break;
                }

            } else {
                // Terminal: add directly
                // cpuf::printf("[terminal %$] ", rule.fullname);
                if (first[nonterminal].insert(rule.name).second) {
                    // cpuf::printf("(added), ");
                    changed = true;
                }

                nullable_prefix = false;
                break;
            }
        }
        // cpuf::printf("\n");
        // If all symbols in this production were nullable
        if (nullable_prefix) {
            if (first[nonterminal].insert({"ε"}).second)
                changed = true;
        }
    }
}
void AST::constructFirstSet() {
    if (!first.empty())
        return;
    createInitialItemSet();
    bool changed;
    do {
        changed = false;
        for (const auto &[nonterminal, productions] : initial_item_set) {
            // cpuf::printf("constructing first set for %$ -> ", nonterminal);
            if (corelib::text::isUpper(nonterminal.back()))
                continue;
            constructFirstSet(productions, nonterminal, changed);
        }
    } while (changed);
}

void AST::constructFollowSet() {
    if (!follow.empty())
        return;
    createInitialItemSet();
    follow[{"__start"}] = {{"$"}};
    bool hasChanges;
    bool prevDependedChanged;
    std::vector<std::vector<std::string>> prev_depend;
    std::vector<std::vector<std::string>> changed;
    do {
        hasChanges = false;
        prevDependedChanged = false;
        prev_depend.clear();
        changed.clear();
        for (const auto &[name, options] : initial_item_set) {
            bool is_left_recursive = false;
            if (corelib::text::isUpper(name.back()))
                continue;
            for (const auto &rules : options) {
                if (!rules.rule_members[0].isName())
                    throw Error("Not RuleMemberName");
                if (rules.rule_members.size() > 0 && name == rules.rule_members[0].getName().name) {
                    is_left_recursive = true;
                }
                for (auto it = rules.rule_members.begin(); it != rules.rule_members.end(); it++) {
                    if (!it->isName()) {
                        throw Error("Not RuleMemberName");
                    }
                    auto current = it->getName();

                    if (corelib::text::isUpper(current.name.back())) {
                        continue;
                    }
                    if (name == current.name) {
                        // include first(name)
                        auto f = first[name];
                        for (auto &e : f) {
                            if (e == std::vector<std::string>{"ε"}) {
                                continue;
                            }
                            if (follow[name].insert(e).second)
                                hasChanges = true;
                        }
                        prev_depend.push_back(name);
                    } else if (is_left_recursive && corelib::text::isLower(current.name.back())) {
                        auto prev_size = follow[current.name].size();
                        follow[current.name].insert(follow[name].begin(), follow[name].end());
                        if (prev_size != follow[current.name].size())
                            hasChanges = true;
                        prev_depend.push_back(current.name);
                    }
                    if (it + 1 == rules.rule_members.end()) {
                        // Add FOLLOW of LHS (the left-hand-side nonterminal)
                        auto &f_lhs = follow[name];
                        for (auto &sym : f_lhs) {
                            if (follow[current.name].insert(sym).second)
                                hasChanges = true;
                        }
                    } else {
                        auto next = (it + 1)->getName();
                        if (corelib::text::isUpper(next.name.back())) {
                            // terminal, just push
                            if (follow[current.name].insert(next.name).second)
                                hasChanges = true;
                        } else {
                            // non-terminal, insert it's first
                            auto f = first[next.name];
                            bool has_epsilon = false;
                            for (auto &e : f) {
                                if (e == std::vector<std::string>{"ε"}) {
                                    has_epsilon = true;
                                    continue;
                                }
                                if (follow[current.name].insert(e).second)
                                    hasChanges = true;
                            }
                            if (has_epsilon) {
                                // if ε in FIRST(next), add FOLLOW of LHS
                                auto &f_lhs = follow[name];
                                for (auto &sym : f_lhs) {
                                    if (follow[current.name].insert(sym).second)
                                        hasChanges = true;
                                }
                            }
                            prev_depend.push_back(next.name);
                        }
                    }
                }

            }
            if (hasChanges) {
                changed.push_back(name);
            }
        }
        if (!hasChanges) {
            // slight optimization: perform check only if this could be last iteration
            for (auto change_symbol : changed) {
                if (std::find(prev_depend.begin(), prev_depend.end(), change_symbol) != prev_depend.end()) {
                    prevDependedChanged = true;
                    break;
                }
            }
        }
    } while(hasChanges || prevDependedChanged);
}
auto AST::getCodeForLexer() -> lexer_code {
    TreeAPI::RuleMemberOp options;
    for (const auto &[name, value] : tree_map) {
        if (corelib::text::isLower(name.back()))
            continue;
        auto find_it = use_places.find(name);
        if (find_it != use_places.end() && name != std::vector<std::string>{"__WHITESPACE"}) {
            bool to_add = false;
            for (const auto &use_name : find_it->second) {
                if (corelib::text::isLower(use_name.back())) {
                    to_add = true;
                    break;
                }
            }
            if (to_add) {
                // add this token
                options.options.push_back(TreeAPI::RuleMember { .value = TreeAPI::RuleMemberName { name } });
            }
        } else if (name == std::vector<std::string> { "__WHITESPACE" }) {
            options.options.push_back(TreeAPI::RuleMember { .value = TreeAPI::RuleMemberName { name } });
        } else {
            printf("Not found %s in use_places\n", name.back().c_str());
        }
        // if not found, do not add this means the token is never used
    }
    ASTPass::sortByPriority(*this, options);
    TreeAPI::RuleMember resultRule = { .value = options };
    // get lexer code
    LLIR::BuilderData bd(*this);
    LLIR::BuilderDataWrapper wrapper(bd);
    LLIR::MemberBuilder code(wrapper, resultRule);
    code.build();
    const auto &return_vars = code.getReturnVars();
    code.pop(); // remove space skip
    if (return_vars.empty())
        throw Error("Empty success var\n");
    return std::make_pair(code.getData(), return_vars[0].var);
}