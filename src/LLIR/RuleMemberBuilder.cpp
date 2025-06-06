module LLIR.Rule.MemberBuilder;
import ErrorIR;
import LLIR.CllBuilder;
import logging;
import corelib;
import cpuf.hex;
import cpuf.printf;
import DFA;
import std;
// helper functions
void LLIR::GroupBuilder::pushBasedOnQuantifier(
    MemberBuilder &builder,
    const AST::RuleMember &rule,
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

auto LLIR::NameBuilder::pushBasedOnQualifier(
    const AST::RuleMember &rule,
    stdu::vector<LLIR::expr> &expr,
    stdu::vector<LLIR::member> &block,
    LLIR::variable &uvar,
    const LLIR::variable &var,
    const LLIR::variable &svar,
    const LLIR::member &call,
    char quantifier,
    bool add_shadow_var
) -> LLIR::variable {
       //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    LLIR::variable shadow_variable;

    if (*insideLoop|| quantifier == '+' || quantifier == '*') {
        shadow_variable = add_shadow_variable(block, var);
        add_shadow_var = false;
    }
    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_variable);
        push({LLIR::types::VARIABLE, uvar});
    }
    switch (quantifier) {
        case '+':
            block.push_back(call);
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            handle_plus_qualifier(rule, LLIR::condition {expr, block}, uvar, var, shadow_variable);
            break;
        case '*': {
            block.push_back(call);
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            push({LLIR::types::WHILE, LLIR::condition{expr, block}});
            break;
        }
        case '?':
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            push({LLIR::types::IF, LLIR::condition{expr, block}});
            break;
        default:
        {
            // add the negative into condition
            block.push_back(createAssignUvarBlock(uvar, var, shadow_variable));
            expr.insert(expr.begin(), {LLIR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {LLIR::condition_types::GROUP_OPEN});
            expr.push_back({LLIR::condition_types::GROUP_CLOSE});
            // add exit statement
            stdu::vector<LLIR::member> blk;
            if (*has_symbol_follow) {
                ErrorIR::IR error(tree, rule, *symbol_follow, isFirst);
                blk = {error.lowerToLLIR(*variable_count)};
            } else {
                blk = {{LLIR::types::EXIT}};
                if (!isFirst) {
                    blk.insert(blk.begin(), {LLIR::types::ERR, getErrorName(rule)});
                }
            }

            if (!isFirst) {
                blk.insert(blk.begin(), {LLIR::types::ERR, getErrorName(rule)});
            }
            push({LLIR::types::IF, LLIR::condition{expr, blk}});
            add(block);
            break;
        }
    }
    return shadow_variable;
}
void LLIR::MemberBuilder::buildMember(const AST::RuleMember &member) {
    *addSpaceSkip = true;
    std::unique_ptr<BuilderBase> builder = nullptr;
    if (member.isGroup()) {
        builder = std::make_unique<GroupBuilder>(*this, member);
    } else if (member.isCsequence()) {
        builder = std::make_unique<CsequenceBuilder>(*this, member);
    } else if (member.isString()) {
        builder = std::make_unique<StringBuilder>(*this, member);
    } else if (member.isHex()) {
        builder = std::make_unique<HexBuilder>(*this, member);
    } else if (member.isBin()) {
        builder = std::make_unique<BinBuilder>(*this, member);
    } else if (member.isName()) {
        builder = std::make_unique<NameBuilder>(*this, member);
    } else if (member.isEscaped()) {
        builder = std::make_unique<EscapedBuilder>(*this, member);
    } else if (member.isNospace()) {
        builder = std::make_unique<NospaceBuilder>(*this);
    } else if (member.isOp()) {
        builder = std::make_unique<OpBuilder>(*this, member);
    } else if (member.isAny()) {
        builder = std::make_unique<AnyBuilder>(*this, member);
    } else if (member.isCll()) {
        builder = std::make_unique<CllBuilder>(*this, member.getCll());
    } else if (member.empty()) {
        throw Error("Empty rule");
    } else throw Error("Undefined rule");
    builder->build();
    return_vars.insert(return_vars.end(), builder->getReturnVars().begin(), builder->getReturnVars().end());
    data.insert(data.end(), builder->getData().begin(), builder->getData().end());
    *isFirst = false;
    if (*addSpaceSkip)
        push({LLIR::types::SKIP_SPACES, *isToken});
}
auto LLIR::MemberBuilder::build() -> void {
    bool isFirst = true;
    size_t pos = 0;
    for (const auto &mem : rules) {
        if (mem.isName() && *has_symbol_follow) {
            *symbol_follow = getLookaheadTerminals(mem, *fullname);
            symbol_follow->emplace_back(stdu::vector<std::string>{}, getNextTerminal(rules, pos));
        }
        buildMember(mem);
        if (isFirst && addSpaceSkipFirst != nullptr) {
            *addSpaceSkipFirst = *addSpaceSkip;
        }
        isFirst = false;
        pos++;
    }
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
    bool addSpaceSkipFirst = false;
    MemberBuilder builder(*this, group, false, addSpaceSkipFirst);
    builder.build();
    return_vars.insert(return_vars.end(), builder.getReturnVars().begin(), builder.getReturnVars().end());
    *insideLoop = prev_insideLoop;
    // remove the previous space skip if there was \s0
    if (addSpaceSkipFirst) {
        removePrevSpaceSkip();
    }

    var.type = {deduceVarTypeByProd(*rule)};
    if ((quantifier == '*' || quantifier == '+') && var.type.type != LLIR::var_types::UNDEFINED && var.type.type != LLIR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR::var_types::ARRAY;
    }
    stdu::vector<LLIR::member> var_members;
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
                    LLIR::variable_assign {var.name, LLIR::var_assign_types::ASSIGN, LLIR::assign { LLIR::var_assign_values::VAR_REFER,  LLIR::var_refer {.var = builder.getReturnVars()[0].var}}}
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
    stdu::vector<LLIR::expr> svar_expr = {};
    stdu::vector<std::string> used_vars;
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    if (!builder.getReturnVars().empty()) {
        bool first = true;
        for (auto el : builder.getReturnVars()) {
            if (el.quantifier == '*' || el.quantifier == '?' || el.svar.name.empty())
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
    stdu::vector<LLIR::member> svar_cond;
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
    // maybe implement later
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
    pushConvResult(*rule, var, uvar, svar, shadow_var, rule->quantifier);
}
void LLIR::CsequenceBuilder::build() {
    //cpuf::printf("csequence\n");
    const auto &csequence = rule->getCsequence();

    auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    stdu::vector<LLIR::expr> expr;

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
        if (rule->quantifier == '+' || rule->quantifier == '*')
            expr.insert(expr.end(), {
                {LLIR::condition_types::AND}, {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0}, {LLIR::condition_types::NOT_EQUAL}, {LLIR::condition_types::ESCAPED_CHARACTER, '0'},
            });
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    if (rule->quantifier == '\0')
        var.type = {LLIR::var_types::CHAR};
    else
        var.type = {LLIR::var_types::STRING};
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto block = createDefaultBlock(var, svar);
    auto shadow_var = pushBasedOnQualifier(*rule, expr, block, uvar, var, svar, rule->quantifier, false);
    pushConvResult(*rule, var, uvar, svar, shadow_var, rule->quantifier);
}
void LLIR::StringBuilder::build() {
    const auto &str = rule->getString();
    const auto &value = str.value;
    auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    stdu::vector<LLIR::expr> expr;
    if (value.size() == 0)
        return;
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
    stdu::vector<LLIR::member> block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    pushBasedOnQualifier(*rule, expr, block, uvar, var, svar, rule->quantifier, false);
    pushConvResult(*rule, var, uvar, svar, {}, rule->quantifier);
}
void LLIR::HexBuilder::build() {
    //cpuf::printf("hex\n");
    auto data = rule->getHex().hex_chars;
    stdu::vector<LLIR::expr> expr = {};
    auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    stdu::vector<LLIR::member> block = createDefaultBlock(var, svar);
    bool is_first = true, is_negative = false;
    if (rule->quantifier == '\0') {
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
    auto shadow_var = pushBasedOnQualifier(*rule, expr, block, uvar, var, svar, rule->quantifier, false);
    pushConvResult(*rule, var, uvar, svar, shadow_var, rule->quantifier);
}
void LLIR::BinBuilder::build() {
    //cpuf::printf("hex\n");
    auto data = rule->getBin().bin_chars;
    stdu::vector<LLIR::expr> expr = {};
    auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    stdu::vector<LLIR::member> block = {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR::types::INCREASE_POS_COUNTER},
    };
    bool is_first = true, is_negative = false;
    if (rule->quantifier == '\0') {
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
    auto shadow_var = pushBasedOnQualifier(*rule, expr, block, uvar, var, svar, rule->quantifier, false);
    pushConvResult(*rule, var, uvar, svar, shadow_var, rule->quantifier);
}
void LLIR::NameBuilder::build() {
    //cpuf::printf("Rule_other");
    auto name = rule->getName().name;
    //cpuf::printf(", name: %s\n", name_str);
    auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    LLIR::variable shadow_var;
    bool isCallingToken = corelib::text::isUpper(name.back());
    if (*has_symbol_follow) {
        symbol_follow->back().first = name;
    }
    if (!*isToken && isCallingToken) {
        var.type.type = LLIR::var_types::Token;
    } else {
        var.type = isCallingToken ? LLIR::var_type {LLIR::var_types::Token_result} : LLIR::var_type {LLIR::var_types::Rule_result};
    }
    auto block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    if (*isToken) {
        // if (!isCallingToken)
        //     throw Error("Cannot call rule from token");
        // remove variable assignemnt
        block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
        block.back().value = var.name;
        var.property_access = {"node"};
        block.erase(block.begin());
        stdu::vector<LLIR::expr> expr;
        auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
        push(call);
        shadow_var = pushBasedOnQualifier(*rule, expr, block, uvar, var, svar, call, rule->quantifier, true);

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
            stdu::vector<LLIR::expr> expr = {
                {LLIR::condition_types::CURRENT_TOKEN, LLIR::current_token {LLIR::condition_types::EQUAL, corelib::text::join(name, "_")}},
            };
            shadow_var = BuilderBase::pushBasedOnQualifier(*rule, expr, block, uvar, var, svar, rule->quantifier, true);
        } else {
            block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
            block.back().value = var.name;
            var.property_access = {"node"};
            block.erase(block.begin()); // remove variable assignment
            stdu::vector<LLIR::expr> expr;
            auto call = createDefaultCall(block, var, corelib::text::join(name, "_"), expr);
            push(call);
            shadow_var = pushBasedOnQualifier(*rule, expr, block, uvar, var, svar, call, rule->quantifier);

        }

    }
    pushConvResult(*rule, var, uvar, svar, shadow_var, rule->quantifier);
}
void LLIR::NospaceBuilder::build() {
    *addSpaceSkip = false;
    removePrevSpaceSkip();
}
void LLIR::EscapedBuilder::build() {
    //cpuf::printf("Rule_escaped\n");
    const auto &escaped_c = rule->getEscaped();

    stdu::vector<LLIR::expr> expression;
    switch (escaped_c.c) {
        case 's':
            // do not add skip of spaces
            *addSpaceSkip = false;
            removePrevSpaceSkip();
            //cpuf::printf("ON_EXPRESSION\n");
            expression = {
                {LLIR::condition_types::CURRENT_CHARACTER, (size_t) 0},
                {LLIR::condition_types::NOT_EQUAL},
                {LLIR::condition_types::CHARACTER, ' '}
            };
            break;
        default:
            throw Error("Undefined char");

    }
    //cpuf::printf("escaped_open\n");
    auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::CHAR};
    stdu::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        block.insert(block.begin(), {LLIR::types::ERR, getErrorName(*rule)});
    }
    auto block_after = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(*rule, expression, block, uvar, var, svar, rule->quantifier, true);
    push({LLIR::types::IF, LLIR::condition{expression, block}});
    add(block_after);
    //cpuf::printf("escaped_close\n");
    pushConvResult(*rule, var, uvar, svar, shadow_var, rule->quantifier);
}
void LLIR::AnyBuilder::build() {
    //cpuf::printf("Rule_any\n");
    auto var = rule->prefix.name.empty() ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule->prefix.name);
    auto svar = createSuccessVariable();
    var.type = {isToken ? LLIR::var_types::CHAR : LLIR::var_types::Token};
    stdu::vector<LLIR::expr> expression;
    stdu::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        auto rm = AST::RuleMember {.value = AST::RuleMemberAny() };
        block.insert(block.begin(), LLIR::member {LLIR::types::ERR, getErrorName(rm)});
    }
    stdu::vector<LLIR::member> block_after = createDefaultBlock(var, svar);
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
    pushConvResult(*rule, var, {}, svar, {}, rule->quantifier);
}
/*
 * build PEG style parser. Right now DFA based is preffered
 * But may come back later
 */

// auto LLIR::OpBuilder::createBlock(const stdu::vector<AST::RuleMember> &rules, size_t index, LLIR::variable &var, LLIR::variable &svar) -> stdu::vector<LLIR::member> {
//     //[[assume(rules.size() >= 2)]];
//     if (index >= rules.size()) {
//         return {{LLIR::types::EXIT}};
//     }
//
//     LLIR::ConvertionResult success_var;
//     stdu::vector<stdu::vector<LLIR::member>> blocks;
//     stdu::vector<stdu::vector<LLIR::expr>> conditions;
//     auto rule = rules[index++];
//     std::unique_ptr<LLIR::MemberBuilder> builder = nullptr;
//     if (rule.isGroup()) {
//         char new_qualifier;
//         if (rule.quantifier == '+')
//             new_qualifier = '*';
//         else if (rule.quantifier == '\0')
//             new_qualifier = '?';
//         auto prev_quantifier = rule.quantifier;
//         rule.quantifier = new_qualifier;
//         builder = std::make_unique<LLIR::MemberBuilder>(*this, rule);
//         builder->build();
//         rule.quantifier = prev_quantifier;
//     }
//     else {
//         builder = std::make_unique<LLIR::MemberBuilder>(*this, rule);
//         builder->build();
//     }
//     builder->getData();
//     stdu::vector<int> erase_indices;
//     stdu::vector<int> push_indices;
//     if (rule.isGroup()) {
//         builder->getData().back().type = LLIR::types::RESET_POS_COUNTER; // remove space skip
//         auto cond = LLIR::condition {
//             stdu::vector<LLIR::expr> {
//                 {LLIR::condition_types::NOT}, {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = success_var.svar}}
//             },
//             createBlock(rules, index, var, svar),
//         };
//         auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
//         auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
//         if (!v.name.empty() && v.type.type != LLIR::var_types::UNDEFINED) {
//             cond.else_block = {{
//                 LLIR::types::ASSIGN_VARIABLE,
//                 LLIR::variable_assign
//                 {
//                     var.name,
//                     LLIR::var_assign_types::ASSIGN,
//                     LLIR::assign {
//                         LLIR::var_assign_values::VAR_REFER,
//                         LLIR::var_refer {.var = v }
//                     }
//                 }
//             }};
//         }
//         push({LLIR::types::IF, cond});
//     } else {
//         for (int i = 0; i < builder->getData().size(); i++) {
//             auto &el = builder->getData()[i];
//             if (el.type == LLIR::types::IF) {
//                 auto val = std::any_cast<LLIR::condition>(el.value);
//                 // get recursively nested block
//                 val.block = createBlock(rules, index, var, svar);
//                 // change condition and remove it's content into else blocks
//                 for (int j = i + 1; j < builder->getData().size(); j++) {
//                     auto el = builder->getData()[j];
//                     erase_indices.push_back(j);
//                     if (el.type != LLIR::types::SKIP_SPACES) {
//                         if (el.type == LLIR::types::ASSIGN_VARIABLE) {
//                             auto assignment = std::any_cast<LLIR::variable_assign>(el.value);
//                             assignment.assign_type = LLIR::var_assign_types::ASSIGN;
//                             el.value = assignment;
//                         }
//                         val.else_block.push_back(el);
//                     }
//                 }
//                 // push into else block an assignment to variable
//                 if (var.type.type == LLIR::var_types::ARRAY) {
//                     val.else_block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { var.name, {LLIR::function_call {"push", {stdu::vector<stdu::vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = success_var.var}}}}}}}}});
//                 } else {
//                     auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
//                     auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
//                     val.else_block.push_back({
//                         LLIR::types::ASSIGN_VARIABLE,
//                         LLIR::variable_assign
//                         {
//                             var.name,
//                             LLIR::var_assign_types::ASSIGN,
//                             LLIR::assign {
//                                 LLIR::var_assign_values::VAR_REFER,
//                                 LLIR::var_refer {.var = v}
//                             }
//                         }
//                     });
//                 }
//
//                 // update the value
//                 el.value = val;
//             }
//         }
//     }
//
//     for (auto it = erase_indices.rbegin(); it != erase_indices.rend(); ++it) {
//         builder->getData().erase(builder->getData().begin() + *it);
//     }
//     return builder->getData();
// }
//
// void LLIR::OpBuilder::build() {
//     // cpuf::printf("Rule_op\n");
//     auto &rules = rule->getOp();
//     auto uvar = !rule->prefix.name.empty() ? createEmptyVariable(rule->prefix.name) : createEmptyVariable("");
//     auto var = createEmptyVariable(generateVariableName());
//     auto svar = createSuccessVariable();
//     auto block = createDefaultBlock(var, svar);
//     // cpuf::printf("op prefix: %$\n", rule.prefix);
//     // Add success variable
//     var.type = {deduceVarTypeByProd(*rule)};
//     if (insideLoop && var.type.type != LLIR::var_types::STRING) {
//         var.type.templ = {{var.type.type}};
//         var.type.type = LLIR::var_types::ARRAY;
//     }
//     if (var.type.type != LLIR::var_types::UNDEFINED) {
//         push({LLIR::types::VARIABLE, var});
//     }
//     push({LLIR::types::VARIABLE, svar});
//     if (!uvar.name.empty()) {
//         uvar.type = var.type;
//         push({LLIR::types::VARIABLE, uvar});
//     }
//     const auto res = createBlock(rules.options, 0, var, svar);
//     add(res);
//     block.erase(block.begin()); // remove variable assignment (it is done in else blocks)
//     block.erase(block.end() - 1);
//     // Append default block
//     add(block);
//     const auto shadow_var = createEmptyVariable("");
//     if (!uvar.name.empty())
//         push(createAssignUvarBlock(uvar, var, shadow_var));
//     pushConvResult(*rule, var, uvar, svar, shadow_var, rule->quantifier);
// }
void LLIR::OpBuilder::build() {
    auto DFA = std::move(DFABuilder(*tree, *rule).get());

}
