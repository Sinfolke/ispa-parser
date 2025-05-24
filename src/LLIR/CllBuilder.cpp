module CllBuilder;
import LLIR;
import LLIRRuleMemberBuilder;
import RvalueBuilder;
import logging;
import std;
// get functions
auto LLIR::CllExprBuilder::get() -> Expression {
    return result;
}

auto LLIR::CllFunctionBuilder::get() -> function_call {
    return result;
}
auto LLIR::CllMethodCallBuilder::get() -> method_call {
    return result;
}

auto LLIR::CllExprBuilder::CllExprGroupToIR(const TreeAPI::CllExpr &group) -> Expression {
    vector<LLIR::expr> expr;
    auto expression = CllExprLogicalToIR(group.value);
    expr.push_back({LLIR::condition_types::GROUP_OPEN});
    expr.insert(expr.end(), expression.begin(), expression.end());
    expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    return expr;
}
auto LLIR::CllExprBuilder::CllExprValueToIR(const TreeAPI::CllExprValue &value) -> Expression {
    vector<LLIR::expr> expr;
    if (value.isGroup()) {
        expr = CllExprGroupToIR(value.getGroup().expr);
    } else if (value.isMethodCall()) {
        CllMethodCallBuilder builder(*this, value.getMethodCall());
        builder.build();
        expr.push_back({LLIR::condition_types::METHOD_CALL, builder.get()});
    } else if (value.isFunctionCall()) {
        CllFunctionBuilder builder(*this, value.getFunctionCall());
        builder.build();
        expr.push_back({LLIR::condition_types::FUNCTION_CALL, builder.get()});
    } else if (value.isVariable()) {
        LLIR::var_refer refer;
        const auto &v = value.getVariable();
        refer.var = { .name = v.name };
        refer.pre_increament = v.pre_increament;
        refer.post_increament = v.post_increament;
        if (v.braceExpression.has_value()) {
            CllExprBuilder builder(*this, v.braceExpression.value());
            builder.build();
            refer.brace_expression = builder.get();
        }
        expr.push_back({LLIR::condition_types::VARIABLE, refer});
    } else if (value.isrvalue()) {
        RvalueBuilder builder(*this, value.getrvalue());
        builder.build();
        expr.push_back({LLIR::condition_types::RVALUE, builder.get()});
    } else throw Error("Undefined expression");
    return expr;
}
auto LLIR::CllExprBuilder::CllExprTermToIR(const TreeAPI::CllExprTerm &term) -> Expression {
    // if (rule.name == Parser::Rules::cll_function_call)
    vector<LLIR::expr> cond = CllExprValueToIR(term.value);
    for (int i = 0; i < term.rights.size(); i++) {
        cond.push_back(BuilderBase::CllOpToExpr(term.rights[i].first));
        auto res = CllExprValueToIR(term.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
auto LLIR::CllExprBuilder::CllExprAdditionToIR(const TreeAPI::CllExprAddition &addition) -> Expression {
    // if (rule.name == Parser::Rules::cll_function_call)
    vector<LLIR::expr> cond = CllExprTermToIR(addition.value);
    for (int i = 0; i < addition.rights.size(); i++) {
        cond.push_back(BuilderBase::CllOpToExpr(addition.rights[i].first));
        auto res = CllExprTermToIR(addition.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
auto LLIR::CllExprBuilder::CllExprCompareToIR(const TreeAPI::CllExprCompare &compare) -> Expression {
    vector<LLIR::expr> cond = CllExprAdditionToIR(compare.value);
    for (int i = 0; i < compare.rights.size(); i++) {
        cond.push_back(BuilderBase::CllCompareOpToExpr(compare.rights[i].first));
        auto res = CllExprAdditionToIR(compare.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
auto LLIR::CllExprBuilder::CllExprLogicalToIR(const TreeAPI::CllExprLogical &logical) -> Expression {
    vector<LLIR::expr> cond = CllExprCompareToIR(logical.value);
    for (int i = 0; i < logical.rights.size(); i++) {
        cond.push_back({BuilderBase::CllLogicalOpToIR(logical.rights[i].first)});
        auto res = CllExprCompareToIR(logical.rights[i].second);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
auto LLIR::CllExprBuilder::deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) -> LLIR::var_type {
    if (value.isFunctionCall()) {
        // todo - get function call type
    } else if (value.isGroup()) {
        return CllExprBuilder(*this, value.getGroup().expr).deduceType();
    } else if (value.isMethodCall()) {
        // todo - get method call type
    } else if (value.isVariable()) {
        auto find_it = std::find_if(vars->begin(), vars->end(), [&value](const LLIR::variable &var) { return var.name == value.getVariable().name; });
        if (find_it == vars->end())
            throw Error("Not found variable to deduce type from expr");
        if (find_it->type.type == LLIR::var_types::Rule_result)
            return {LLIR::var_types::Rule};
        if (find_it->type.type == LLIR::var_types::Token_result)
            return {LLIR::var_types::Token};
        return find_it->type;
    } else if (value.isrvalue()) {
        RvalueBuilder rvalue(*this, value.getrvalue());
        return (rvalue.deduceType());
    } else
        throw Error("Undefined expr value member");
    return {};
}
auto LLIR::CllExprBuilder::deduceTypeFromExprTerm(const TreeAPI::CllExprTerm &term) -> LLIR::var_type {
    // type is explicitly based on value. We may not check others in addition
    return deduceTypeFromExprValue(term.value);
}
auto LLIR::CllExprBuilder::deduceTypeFromExprAddition(const TreeAPI::CllExprAddition &addition) -> LLIR::var_type{
    // same as with term
    return deduceTypeFromExprTerm(addition.value);
}
auto LLIR::CllExprBuilder::deduceTypeFromExprCompare(const TreeAPI::CllExprCompare &compare) -> LLIR::var_type {
    // if any comparasion exists it is boolean
    if (compare.rights.size() != 0)
        return {LLIR::var_types::BOOLEAN};
    return deduceTypeFromExprAddition(compare.value);
}
auto LLIR::CllExprBuilder::deduceTypeFromExprLogical(const TreeAPI::CllExprLogical &logical) -> LLIR::var_type {
    // if &&/|| exists it is always boolean
    if (logical.rights.size() != 0)
        return {LLIR::var_types::BOOLEAN};
    return deduceTypeFromExprCompare(logical.value);
}
auto LLIR::CllExprBuilder::deduceType() -> LLIR::var_type {
    return deduceTypeFromExprLogical(expr->value);
}
auto LLIR::CllFunctionBuilder::FunctionBodyCallToIR(const TreeAPI::CllFunctionBodyCall &body) -> vector<Expression> {
    vector<Expression> newExpr;
    for (const auto &expr : body.expr) {
        CllExprBuilder builder(*this, expr);
        builder.build();
        newExpr.push_back(builder.get());
    }
    return newExpr;
}


void LLIR::CllBuilder::build() {
    *addSpaceSkip = false;
    std::unique_ptr<LLIR::BuilderBase> builder = nullptr;

    if (cll->isVar()) {
        builder = std::make_unique<CllVarBuilder>(*this, cll->getVar());
    } else if (cll->isIf()) {
        builder = std::make_unique<CllIfBuilder>(*this, cll->getIf());
    } else {
        throw Error("Undefined cll entry");
    }

    builder->build();
    data.insert(data.end(), builder->getData().begin(), builder->getData().end());
}
void LLIR::CllVarBuilder::build() {
    // get data section
    LLIR::var_type ir_type;
    LLIR::var_assign_types assign_types;
    LLIR::assign assign;
    if (!var->type.type.empty())
        ir_type = CllTypeToIR(var->type);
    if (var->op != '\0') {
        assign_types = CllOpToIR(var->op);
        CllExprBuilder builder(*this, var->value);
        builder.build();
        assign = {LLIR::var_assign_values::EXPR, builder.get()};
    }
    if (!var->type.type.empty()) {
        LLIR::variable v = {var->name, ir_type, assign};
        push({LLIR::types::VARIABLE, v});
        vars->push_back(v);
    } else {
        push({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var->name, assign_types, assign}});
    }
}
void LLIR::CllIfBuilder::build() {
    MemberBuilder rules_builder(*this, cond->stmt);
    CllExprBuilder expr_builder(*this, cond->expr);
    rules_builder.build();
    expr_builder.build();
    LLIR::condition condition;
    condition.expression = expr_builder.get();
    condition.block = rules_builder.getData();
}

void LLIR::CllExprBuilder::build() {
    result = CllExprLogicalToIR(expr->value);
}
void LLIR::CllFunctionBuilder::build() {
    result.name = call->name;
    result.params = FunctionBodyCallToIR(call->body);
}
void LLIR::CllMethodCallBuilder::build() {
    result.var_name = call->name;
    CllFunctionBuilder fun(*this, call->body);
    fun.build();
    result.calls = {fun.get()};
}