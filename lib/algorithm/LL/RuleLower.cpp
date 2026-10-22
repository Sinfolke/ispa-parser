module RuleLower;

import MemLower;
import LangAPI.Context;
import corelib;
import std;

auto RuleLower::register_function(const LangAPI::Function &fun) -> void {
    decls.push_back(fun);
}

void RuleLower::build(const std::vector<std::string> name, const AST::Rule &rule) {
    LangAPI::Function fun;
    fun.name = fun_name(name);

    FunctionCtx fun_ctx;
    fun_ctx.statements = &fun.statements;
    fun_ctx.rule_name = AST::LLkToken(name.begin(), name.end());

    LangAPI::Variable frame;
    frame.name = "recovery_scope";
    frame.type = LangAPI::Type{LangAPI::Symbol{"auto"}};
    frame.value = recoveryFrame(fun_ctx.rule_name);
    fun.statements.push_back(LangAPI::Variable::createStatement(frame));

    std::size_t idx = 0;
    for (const auto &rule_member : rule.rule_members) {
        LangAPI::Statements member_statements;
        fun_ctx.statements = &member_statements;
        member_statements.push_back(LangAPI::Expression::createStatement(
            recoverySite(*tree, fun_ctx.rule_name, idx)));
        MemLower lower(ctx, fun_ctx, *tree, idx);
        lower.build(*rule_member);
        LangAPI::Expression condition{LangAPI::ExpressionValue{LangAPI::ExpressionElement::Not}};
        const auto call = LangAPI::FunctionCall::createExpression(LangAPI::FunctionCall{
            .name = std::make_shared<LangAPI::Symbol>("unwinding")});
        condition.insert(condition.end(), call.begin(), call.end());
        fun.statements.push_back(LangAPI::If::createStatement(
            LangAPI::If{condition, std::move(member_statements)}));
        ++idx;
    }
    fun_ctx.statements = &fun.statements;

    // Member lowering hoists every value variable so that values produced
    // inside optional / repeated / chosen blocks stay visible to later members
    // and to the data block.
    fun.statements.insert(fun.statements.begin(),
                          fun_ctx.declarations.begin(), fun_ctx.declarations.end());
    register_function(fun);
    lowered_functions.insert_or_assign(name, LoweredFunction {
        .function = std::move(fun), .exports = std::move(fun_ctx.exports),
        .captures = std::move(fun_ctx.captures)
    });
}

void RuleLower::build(const AST::Tree &tree) {
    for (const auto &[name, rule] : tree.getTreeMap()) {
        if (corelib::text::isUpper(name.back())) {
            continue;
        }
        build(name, rule);
    }
}
