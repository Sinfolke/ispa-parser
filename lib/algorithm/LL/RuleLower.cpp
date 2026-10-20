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
    FunctionCtx fun_ctx {.statements = &fun.statements};
    std::size_t idx = 0;
    for (const auto &rule_member : rule.rule_members) {
        MemLower lower(ctx, fun_ctx, *tree, idx);
        lower.build(*rule_member);
        ++idx;
    }
    register_function(fun);
}

void RuleLower::build(const AST::Tree &tree) {
    for (const auto &[name, rule] : tree.getTreeMap()) {
        if (corelib::text::isUpper(name.back())) {
            continue;
        }
        build(name, rule);
    }
}
