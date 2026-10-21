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

    std::size_t idx = 0;
    for (const auto &rule_member : rule.rule_members) {
        MemLower lower(ctx, fun_ctx, *tree, idx);
        lower.build(*rule_member);
        ++idx;
    }

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
