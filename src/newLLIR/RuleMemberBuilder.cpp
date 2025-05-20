module LLIRRuleMemberBuilder;
import CllBuilder;
import logging;
import corelib;
import std;
// constructors

LLIR::MemberBuilder::MemberBuilder(LLIR::BuilderData &data, const std::vector<TreeAPI::RuleMember> &rules) : LLIR::BuilderBase(data) {
    for (const auto &mem : rules) {
        rule = &mem;
        build();
    }
}
LLIR::MemberBuilder::MemberBuilder(LLIR::BuilderData &data, const std::vector<TreeAPI::RuleMember> &rules, bool &addSpaceSkipFirst) : LLIR::BuilderBase(data) {
    bool isFirst = true;
    for (const auto &mem : rules) {
        rule = &mem;
        build();
        if (isFirst) {
            addSpaceSkipFirst = addSpaceSkip;
        }
        isFirst = false;
    }
}

// helper functions
void LLIR::GroupBuilder::pushBasedOnQuantifier(
    MemberBuilder &builder,
    const TreeAPI::RuleMember &rule,
    LLIR::variable &shadow_var,
    LLIR::variable &uvar, const
    LLIR::variable &var,
    char quantifier
    ) {

    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_var);
        push({LLIR::types::VARIABLE, uvar});
    }
    if (quantifier == '*' || quantifier == '+') {
        LLIR::condition loop = { { { LLIR::condition_types::NUMBER, (long long) 1 } }, {} };
        loop.block = builder.getData();
        builder.getData().clear();
        processExitStatements(loop.block);
        // raiseVarsTop(data, loop.block, true, false, false);
        // raiseVarsTop(data, loop.else_block, true, false, false);
        if (quantifier == '+') {
            handle_plus_qualifier(rule, loop, uvar, var, shadow_var);
        } else {
            push({LLIR::types::WHILE, loop});
        }
    } else if (quantifier == '?') {
        LLIR::condition loop = { { {LLIR::condition_types::NUMBER, (long long) 0} } };
        loop.block = builder.getData();
        builder.getData().clear();
        processExitStatements(loop.block);
        push({ LLIR::types::DOWHILE, loop });
    }
}



auto LLIR::MemberBuilder::build() -> void {
    *addSpaceSkip = true;
    LLIR::ConvertionResult success_var;
    std::unique_ptr<BuilderBase> builder = nullptr;
    if (rule->isGroup()) {
        builder = std::make_unique<GroupBuilder>(*this, *rule);
    } else if (rule->isCsequence()) {
        builder = std::make_unique<CsequenceBuilder>(*this, *rule);
    } else if (rule->isString()) {
        builder = std::make_unique<StringBuilder>(*this, *rule);
    } else if (rule->isHex()) {
        builder = std::make_unique<HexBuilder>(*this, *rule);
    } else if (rule->isBin()) {
        builder = std::make_unique<BinBuilder>(*this, *rule);
    } else if (rule->isName()) {
        builder = std::make_unique<NameBuilder>(*this, *rule);
    } else if (rule->isEscaped()) {
        builder = std::make_unique<EscapedBuilder>(*this, *rule);
    } else if (rule->isNospace()) {
        builder = std::make_unique<NospaceBuilder>(*this, *rule);
    } else if (rule->isOp()) {
        builder = std::make_unique<OpBuilder>(*this, *rule);
    } else if (rule->isAny()) {
        builder = std::make_unique<AnyBuilder>(*this, *rule);
    } else if (rule->isCll()) {
        builder = std::make_unique<LLIR::CllBuilder>(rule->getCll());
    } else if (rule->empty()) {
        throw Error("Empty rule in %$", fullname);
    } else throw Error("Undefined rule");
    data = builder->getData();
    if (rule->prefix.is_key_value) {
        if (rule->prefix.name.empty()) {
            unnamed_datablock_units->push_back(success_var.uvar.name.empty() ? (success_var.shadow_var.name.empty() ? success_var.var : success_var.shadow_var) : success_var.uvar);
        } else {
            key_vars->emplace_back(rule->prefix.name, success_var.uvar);
        }
    }
    const auto insert_var = [this](const LLIR::variable &var) {
        if (!var.name.empty())
            vars->push_back(var);
    };
    insert_var(success_var.uvar);
    insert_var(success_var.svar);
    insert_var(success_var.var);
    insert_var(success_var.shadow_var);
    *isFirst = false;
    if (addSpaceSkip)
        push({LLIR::types::SKIP_SPACES, isToken});
    conv_res.push_back(success_var);
}
void LLIR::GroupBuilder::build() {
    auto var = createEmptyVariable(generateVariableName());
    auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
    auto svar = createSuccessVariable();
    auto prev_insideLoop = *insideLoop;
    const auto &quantifier = rule->quantifier;
    const auto &group = rule->getGroup().values;
    if (quantifier == '*' || quantifier == '+')
        *insideLoop = true;
    bool addSpaceSkipFirst;
    MemberBuilder builder(*this, group, addSpaceSkipFirst);
    *insideLoop = prev_insideLoop;
    // remove previous space skip it there was \s0
    if (addSpaceSkipFirst) {
        removePrevSpaceSkip();
    }

    var.type = {deduceVarTypeByProd(*rule)};
    if ((quantifier == '*' || quantifier == '+') && var.type.type != LLIR::var_types::UNDEFINED && var.type.type != LLIR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR::var_types::ARRAY;
    }
    std::vector<LLIR::member> var_members;
    switch (var.type.type == LLIR::var_types::ARRAY ? var.type.templ[0].type : var.type.type) {
        case LLIR::var_types::STRING:
            // it is a string so add all values
            for (const auto &v : builder.getReturnVars()) {
                if (v.var.name.empty())
                    continue;
                var_members.push_back(
                    {
                        LLIR::types::ASSIGN_VARIABLE,
                        LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::assign { LLIR::var_assign_values::VAR_REFER, LLIR::var_refer {.var = v.var} }}
                    }
                );
            }
            break;
        case LLIR::var_types::Token:
        case LLIR::var_types::Rule:
            // it is token so perform a single assign
            var_members.push_back( LLIR::member
                {
                    LLIR::types::ASSIGN_VARIABLE,
                    LLIR::variable_assign {var.name, LLIR::var_assign_types::ASSIGN, LLIR::assign { LLIR::var_assign_values::VAR_REFER,  LLIR::var_refer {.var = builder.conv_res[0].var}}}
                }
            );

            var.type = builder.getReturnVars()[0].var.type;
            if (var.type.type == LLIR::var_types::Rule_result)
                var.type.type = LLIR::var_types::Rule;
            else if (var.type.type == LLIR::var_types::Token_result)
                var.type.type = LLIR::var_types::Token;
            break;
        default:
            var.type = {LLIR::var_types::UNDEFINED};
            break;
    }
    std::string begin_var_name = "begin" + generateVariableName();
    std::vector<LLIR::expr> svar_expr = {};
    std::vector<std::string> used_vars;
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    if (!builder.getReturnVars().empty()) {
        bool first = true;
        for (auto el : builder.getReturnVars()) {
            if (el.qualifier == '*' || el.qualifier == '?' || el.svar.name.empty())
                continue;
            if (!first)
                svar_expr.push_back({LLIR::condition_types::AND});
            used_vars.push_back(el.svar.name);
            svar_expr.push_back({LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = el.svar}});
            first = false;
        }
    }
    // for (int i = 0; i < node_ret.size(); i++) {
    //     if (i != 0)
    //         svar_expr.push_back({LLIR::condition_types::AND});
    //     svar_expr.push_back({LLIR::condition_types::VARIABLE, node_ret[i].svar});
    // }

    if (!builder.getData().empty() && builder.getData().back().type == LLIR::types::SKIP_SPACES) {
        builder.pop();
    }
    builder.add(var_members);
    LLIR::variable shadow_var;
    if ((*insideLoop || quantifier == '*' || quantifier == '+') && (var.type.type != LLIR::var_types::UNDEFINED && var.type.type != LLIR::var_types::STRING)) {
        shadow_var = add_shadow_variable(builder.getData(), var);
    }
    std::vector<LLIR::member> svar_cond;
    if (svar_expr.empty()) {
        svar_cond = {
            {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
            createAssignUvarBlock(uvar, var, shadow_var),
            {LLIR::types::POP_POS_COUNTER}
        };
    } else {
        svar_cond = {{
            LLIR::types::IF,
            LLIR::condition {
                svar_expr,
                {
                    {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::True}},
                    createAssignUvarBlock(uvar, var, shadow_var),
                    {LLIR::types::POP_POS_COUNTER}
                }
            }
        }};
    }
    if (var.type.type != LLIR::var_types::UNDEFINED) {
        push({LLIR::types::VARIABLE, var});
    }
    push({LLIR::types::VARIABLE, svar});
    push({LLIR::types::PUSH_POS_COUNTER, begin_var_name});
    // maybe implemente later
    // if (!variable.empty() && variable.name == Parser::Rules::method_call)
    // {
    //     LLIR::method_call method_call = TreeMethodCallToLLIR::(std::any_cast<Parser::Rule>(variable.data));
    //     add(values);
    //     push({LLIR::types::METHOD_CALL, method_call});
    // } else {
        pushBasedOnQuantifier(builder, *rule, shadow_var, uvar, var, quantifier);
        for (const auto &svar : used_vars) {
            raiseVarsTop(data, data, svar, true, false, true);
        }
    // }
    add(svar_cond);
    if (uvar.type.type == LLIR::var_types::UNDEFINED)
        return LLIR::ConvertionResult {svar, {}, var, shadow_var, quantifier};
    return LLIR::ConvertionResult {svar, uvar, var, shadow_var, quantifier};
}
void LLIR::CsequenceBuilder::build() {
    //cpuf::printf("csequence\n");
    const auto &csequence = rule.getCsequence();

    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    std::vector<LLIR::expr> expr;

    if (csequence.negative) {
        expr = {
            {LLIR::condition_types::NOT},
            {LLIR::condition_types::GROUP_OPEN}
        };
    }

    bool first = true;
    size_t count = 0;
    for (const auto c : csequence.characters) {
        if (!first)
            expr.push_back({LLIR::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR::condition_types::EQUAL},
            {LLIR::condition_types::CHARACTER, c}
        });
        first = false;
    }
    for (const auto c : csequence.escaped) {
        if (!first)
            expr.push_back({LLIR::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR::condition_types::EQUAL},
            {LLIR::condition_types::ESCAPED_CHARACTER, c}
        });
        first = false;
    }
    for (const auto &[from, to] : csequence.diapasons) {
        if (!first)
            expr.push_back({LLIR::condition_types::OR});
        expr.insert(expr.end(), {
            {LLIR::condition_types::GROUP_OPEN},
            {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR::condition_types::HIGHER_OR_EQUAL},
            {LLIR::condition_types::CHARACTER, from},
            {LLIR::condition_types::AND},
            {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR::condition_types::LOWER_OR_EQUAL},
            {LLIR::condition_types::CHARACTER, to},
            {LLIR::condition_types::GROUP_CLOSE}
        });
        first = false;
    }
    if (csequence.negative) {
        if (rule.quantifier == '+' || rule.quantifier == '*')
            expr.insert(expr.end(), {
                {LLIR::condition_types::AND}, {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0}, {LLIR::condition_types::NOT_EQUAL}, {LLIR::condition_types::ESCAPED_CHARACTER, '0'},
            });
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    if (rule.quantifier == '\0')
        var.type = {LLIR::var_types::CHAR};
    else
        var.type = {LLIR::var_types::STRING};
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
}
void LLIR::StringBuilder::build() {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    const auto &str = rule.getString();
    const auto &value = str.value;
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    std::vector<LLIR::expr> expr;
    if (value.size() == 0)
        return {};
    if (str.count_strlen() == 1) {
        // micro optimization - compare as single character for single character strings
        expr = {
            {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR::condition_types::EQUAL},
            value[0] == '\\' ? LLIR::expr {LLIR::condition_types::ESCAPED_CHARACTER, value[1]} :  LLIR::expr {LLIR::condition_types::CHARACTER, value[0]}
        };
        var.type.type = LLIR::var_types::CHAR;
    } else {
        expr = {
            {LLIR::condition_types::STRNCMP, LLIR::strncmp{true, value}}
        };
        var.type = {LLIR::var_types::STRING};
    }
    if (corelib::text::isAllAlpha(value)) {
        // it is keyword, add conditional check that it is not start of ID
        expr.insert(expr.end(), {
            {LLIR::condition_types::AND},
            {LLIR::condition_types::NOT},
            {LLIR::condition_types::GROUP_OPEN},
                {LLIR::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR::condition_types::HIGHER_OR_EQUAL}, {LLIR::condition_types::CHARACTER, 'a'},
                {LLIR::condition_types::AND},
                {LLIR::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR::condition_types::LOWER_OR_EQUAL}, {LLIR::condition_types::CHARACTER, 'z'},
                {LLIR::condition_types::OR},
                {LLIR::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR::condition_types::HIGHER_OR_EQUAL}, {LLIR::condition_types::CHARACTER, 'A'},
                {LLIR::condition_types::AND},
                {LLIR::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR::condition_types::LOWER_OR_EQUAL}, {LLIR::condition_types::CHARACTER, 'Z'},
                {LLIR::condition_types::OR},
                {LLIR::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR::condition_types::HIGHER_OR_EQUAL}, {LLIR::condition_types::CHARACTER, '0'},
                {LLIR::condition_types::AND},
                {LLIR::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR::condition_types::LOWER_OR_EQUAL}, {LLIR::condition_types::CHARACTER, '9'},
                {LLIR::condition_types::OR},
                {LLIR::condition_types::CURRENT_CHARACTER, str.count_strlen()}, {LLIR::condition_types::EQUAL}, {LLIR::condition_types::CHARACTER, '_'},
            {LLIR::condition_types::GROUP_CLOSE},
        });
    }
    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
}
void LLIR::HexBuilder::build() {
    //cpuf::printf("hex\n");
    auto data = rule.getHex().hex_chars;
    std::vector<LLIR::expr> expr = {};
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    bool is_first = true, is_negative = false;
    if (rule.quantifier == '\0') {
        expr.push_back({LLIR::condition_types::NOT});
        expr.push_back({LLIR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    if (data.size() % 2 != 0)
        data.insert(data.begin(), '0');
    for (size_t i = 0; i < data.size(); i += 2) {
        std::string hex(data.data() + i, 2);
        if (!is_first)
            expr.push_back({LLIR::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR::condition_types::CURRENT_CHARACTER, i});
        expr.push_back({LLIR::condition_types::EQUAL});
        expr.push_back({LLIR::condition_types::HEX, hex});
    }
    if (is_negative) {
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    //cpuf::printf("hex_open\n");
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
}
void LLIR::BinBuilder::build() {
    //cpuf::printf("hex\n");
    auto data = rule.getBin().bin_chars;
    std::vector<LLIR::expr> expr = {};
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    std::vector<LLIR::member> block = {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR::types::INCREASE_POS_COUNTER},
    };
    bool is_first = true, is_negative = false;
    if (rule.quantifier == '\0') {
        expr.push_back({LLIR::condition_types::NOT});
        expr.push_back({LLIR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    while (data.size() % 8 != 0)
        data.insert(data.begin(), '0');
    for (size_t i = 0; i < data.size(); i += 8) {
        std::string bin(data.data() + i, 8);
        auto as_hex = hex::from_binary(bin);
        as_hex.erase(as_hex.begin(), as_hex.begin() + 2);
        if (!is_first)
            expr.push_back({LLIR::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR::condition_types::CURRENT_CHARACTER, i});
        expr.push_back({LLIR::condition_types::EQUAL});
        expr.push_back({LLIR::condition_types::HEX, as_hex});
    }
    if (is_negative) {
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
void LLIR::NameBuilder::build() {
    //cpuf::printf("Rule_other");
    auto name = rule.getName().name;
    //cpuf::printf(", name: %s\n", name_str);
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    LLIR::variable shadow_var;
    bool isCallingToken = corelib::text::isUpper(name.back());
    if (has_symbol_follow) {
        if (symbol_follow.empty())
            throw Error("empty symbol follow on rule %$\n", fullname);
        symbol_follow.back().first = name;
    }
    if (!isToken && isCallingToken) {
        var.type.type = LLIR::var_types::Token;
    } else {
        var.type = isCallingToken ? LLIR::var_type {LLIR::var_types::Token_result} : LLIR::var_type {LLIR::var_types::Rule_result};
    }
    auto block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    if (isToken) {
        if (!isCallingToken)
            throw Error("Cannot call rule from token");
        // remove variable assignemnt
        block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
        block.back().value = var.name;
        var.property_access = {"node"};
        block.erase(block.begin());
        std::vector<LLIR::expr> expr;
        auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
        push(call);
        shadow_var = pushBasedOnQualifier_Rule_name(rule, expr, block, uvar, var, svar, call, rule.quantifier);

    } else {
        if (isCallingToken) {
            block[0] = {
                LLIR::types::ASSIGN_VARIABLE,
                LLIR::variable_assign {
                    var.name,
                    LLIR::var_assign_types::ASSIGN,
                    LLIR::var_assign_values::CURRENT_TOKEN
                }
            };
            std::vector<LLIR::expr> expr = {
                {LLIR::condition_types::CURRENT_TOKEN, LLIR::current_token {LLIR::condition_types::EQUAL, corelib::text::join(name, "_")}},
            };
            shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier);
        } else {
            block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
            block.back().value = var.name;
            var.property_access = {"node"};
            block.erase(block.begin()); // remove variable assignment
            std::vector<LLIR::expr> expr;
            auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
            push(call);
            shadow_var = pushBasedOnQualifier_Rule_name(rule, expr, block, uvar, var, svar, call, rule.quantifier);

        }

    }
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
LLIR::NospaceBuilder::build() {
    addSpaceSkip = false;
    if (members.size() > 0) {
        // remove previous skip of spaces if it does exists
        for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
            if (rit->type == LLIR::types::SKIP_SPACES) {
                this->members.erase(rit.base());
                break;
            }
        }
    }
    return {};
}
void LLIR::EscapedBuilder::build() {
    //cpuf::printf("Rule_escaped\n");
    const auto &escaped_c = rule.getEscaped();

    std::vector<LLIR::expr> expression;
    switch (escaped_c.c) {
        case 's':
            // do not add skip of spaces
            addSpaceSkip = false;
            if (data.size() > 0) {
                // remove previous skip of spaces if it does exists
                for (auto rit = this->members.rbegin(); rit != this->members.rend(); rit++) {
                    if (rit->type == LLIR::types::SKIP_SPACES) {
                        this->members.erase(rit.base());
                        break;
                    }
                }
            }
            //cpuf::printf("ON_EXPRESSION\n");
            expression = {
                {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
                {LLIR::condition_types::NOT_EQUAL},
                {LLIR::condition_types::CHARACTER, ' '}
            };
            break;
        default:
            throw Error("Undefined char '%c'", escaped_c);

    }
    //cpuf::printf("escaped_open\n");
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::CHAR};
    std::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        block.insert(block.begin(), {LLIR::types::ERR, getErrorName(rule)});
    }
    auto block_after = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expression, block, uvar, var, svar, rule.quantifier);
    push({LLIR::types::IF, LLIR::condition{expression, block}});
    add(block_after);
    //cpuf::printf("escaped_close\n");
    return {svar, uvar, var, shadow_var, rule.quantifier};
}
void LLIR::AnyBuilder::build() {
    //cpuf::printf("Rule_any\n");
    auto var = prefix.name.empty() ? createEmptyVariable(generateVariableName()) : createEmptyVariable(prefix.name);
    auto svar = createSuccessVariable();
    var.type = {isToken ? LLIR::var_types::CHAR : LLIR::var_types::Token};
    std::vector<LLIR::expr> expression;
    std::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        auto rm = TreeAPI::RuleMember {.value = TreeAPI::RuleMemberAny() };
        block.insert(block.begin(), LLIR::member {LLIR::types::ERR, getErrorName(rm)});
    }
    std::vector<LLIR::member> block_after = createDefaultBlock(var, svar);
    if (isToken) {
        expression = {
            {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
            {LLIR::condition_types::EQUAL},
            isToken ?
            LLIR::expr {LLIR::condition_types::ESCAPED_CHARACTER, '0'}
            :
            LLIR::expr {LLIR::condition_types::CURRENT_TOKEN, "NONE"}
        };
    } else {

    }

    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    push({LLIR::types::IF, LLIR::condition{expression, block}});
    add(block_after);
    return {svar, {}, var};
}
auto OpBuilder::createBlock(const std::vector<TreeAPI::RuleMember> &rules, size_t index, LLIR::variable &var, LLIR::variable &svar) -> std::vector<LLIR::member> {
    //[[assume(rules.size() >= 2)]];
    if (index >= rules.size()) {
        return {{LLIR::types::EXIT}};
    }

    LLIR::ConvertionResult success_var;
    std::vector<std::vector<LLIR::member>> blocks;
    std::vector<std::vector<LLIR::expr>> conditions;
    auto rule = rules[index++];
    LLIR:: new_LLIR::(tree, -1, false);
    new_LLIR::.proceed(*this);

    if (rule.isGroup()) {
        char new_qualifier;
        if (rule.quantifier == '+')
            new_qualifier = '*';
        else if (rule.quantifier == '\0')
            new_qualifier = '?';
        auto prev_quantifier = rule.quantifier;
        rule.quantifier = new_qualifier;
        new_LLIR::.ruleToLLIR::(rule);
        rule.quantifier = prev_quantifier;
    }
    else {
        new_LLIR::.ruleToLLIR::(rule);
    }
    variable_count = new_LLIR::.variable_count;
    vars = new_LLIR::.vars;
    unnamed_datablock_units = new_LLIR::.unnamed_datablock_units;
    key_vars = new_LLIR::.key_vars;
    success_var = new_LLIR::.success_vars[0];
    std::vector<int> erase_indices;
    std::vector<int> push_indices;
    if (rule.isGroup()) {
        new_LLIR::.members.back().type = LLIR::types::RESET_POS_COUNTER; // remove space skip
        auto cond = LLIR::condition {
            std::vector<LLIR::expr> {
                {LLIR::condition_types::NOT}, {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = success_var.svar}}
            },
            convert_op_rule(rules, index, var, svar),
        };
        auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
        auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
        if (!v.name.empty() && v.type.type != LLIR::var_types::UNDEFINED) {
            cond.else_block = {{
                LLIR::types::ASSIGN_VARIABLE,
                LLIR::variable_assign
                {
                    var.name,
                    LLIR::var_assign_types::ASSIGN,
                    LLIR::assign {
                        LLIR::var_assign_values::VAR_REFER,
                        LLIR::var_refer {.var = v }
                    }
                }
            }};
        }
        new_LLIR::.push({LLIR::types::IF, cond});
    } else {
        for (int i = 0; i < new_LLIR::.members.size(); i++) {
            auto &el = new_LLIR::.members[i];
            if (el.type == LLIR::types::IF) {
                auto val = std::any_cast<LLIR::condition>(el.value);
                // get recursively nested block
                val.block = convert_op_rule(rules, index, var, svar);
                // change condition and remove it's content into else blocks
                for (int j = i + 1; j < new_LLIR::.members.size(); j++) {
                    auto el = new_LLIR::.members[j];
                    erase_indices.push_back(j);
                    if (el.type != LLIR::types::SKIP_SPACES) {
                        if (el.type == LLIR::types::ASSIGN_VARIABLE) {
                            auto assignment = std::any_cast<LLIR::variable_assign>(el.value);
                            assignment.assign_type = LLIR::var_assign_types::ASSIGN;
                            el.value = assignment;
                        }
                        val.else_block.push_back(el);
                    }
                }
                // push into else block an assignment to variable
                if (var.type.type == LLIR::var_types::ARRAY) {
                    val.else_block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { var.name, {LLIR::function_call {"push", {std::vector<std::vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = success_var.var}}}}}}}}});
                } else {
                    auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
                    auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
                    val.else_block.push_back({
                        LLIR::types::ASSIGN_VARIABLE,
                        LLIR::variable_assign
                        {
                            var.name,
                            LLIR::var_assign_types::ASSIGN,
                            LLIR::assign {
                                LLIR::var_assign_values::VAR_REFER,
                                LLIR::var_refer {.var = v}
                            }
                        }
                    });
                }

                // update the value
                el.value = val;
            }
        }
    }

    for (auto it = erase_indices.rbegin(); it != erase_indices.rend(); ++it) {
        new_IR::.members.erase(new_LLIR::.members.begin() + *it);
    }
    return new_IR::.members;
}

void LLIR::OpBuilder::build() {
    // cpuf::printf("Rule_op\n");
    auto &rules = rule.getOp();
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    auto block = createDefaultBlock(var, svar);
    // cpuf::printf("op prefix: %$\n", rule.prefix);
    // Add success variable
    var.type = {deduceVarTypeByProd(rule)};
    if (insideLoop && var.type.type != LLIR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR::var_types::ARRAY;
    }
    if (var.type.type != LLIR::var_types::UNDEFINED) {
        push({LLIR::types::VARIABLE, var});
    }
    push({LLIR::types::VARIABLE, svar});
    if (!uvar.name.empty()) {
        uvar.type = var.type;
        push({LLIR::types::VARIABLE, uvar});
    }
    const auto res = convert_op_rule(rules.options, 0, var, svar);
    add(res);
    block.erase(block.begin()); // remove variable assignment (it is done in else blocks)
    block.erase(block.end() - 1);
    // Append default block
    add(block);
    const auto shadow_var = createEmptyVariable("");
    if (!uvar.name.empty())
        push(createAssignUvarBlock(uvar, var, shadow_var));
    return {svar, uvar, var, {}, rule.quantifier};
}
void LLIR::process_cll_var(const TreeAPI::CllVar &var) {
    // get data section
    LLIR::var_type LLIR::_type;
    LLIR::var_assign_types assign_types;
    LLIR::assign assign;
    if (!var.type.type.empty())
        LLIR::_type = cllTreeTypeToLLIR::(var.type);
    if (var.op != '\0') {
        assign_types = TreeOpToLLIR::(var.op);
        assign = {LLIR::var_assign_values::EXPR, TreeExprToLLIR::(var.value)};
    }
    if (!var.type.type.empty()) {
        LLIR::variable v = {var.name, LLIR::_type, assign};
        push({LLIR::types::VARIABLE, v});
        vars.push_back(v);
    } else {
        push({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, assign_types, assign}});
    }
}