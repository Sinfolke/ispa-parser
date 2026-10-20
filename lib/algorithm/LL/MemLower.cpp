module MemLower;
import logging;
import corelib;
import std;
auto MemLower::createValueAssignment(const std::string &name, const LangAPI::Expression &expr) -> LangAPI::VariableAssignment {
    return LangAPI::VariableAssignment {
        .name = LangAPI::Symbol {name},
        .value = expr
    };
}

auto MemLower::getMatchSymbol(char quantifier) -> LangAPI::StdlibExports {
    switch (quantifier) {
        case '\0':
            return LangAPI::StdlibExports::ParserRequired;
        case '?':
            return LangAPI::StdlibExports::ParserOptional;
        case '+':
            return LangAPI::StdlibExports::ParserRange;
        case '*':
            return LangAPI::StdlibExports::ParserRangeOptional;
        default:
            throw Error("Undefined quantifier: {}", quantifier);
    }
}
auto MemLower::ismemberOptional(char quantifier) -> bool {
    return quantifier == '?' || quantifier == '*';
}
auto MemLower::buildTokenCall(const AST::RuleMember &member, const std::vector<std::string> &name) -> void {
    Parser::LowerMeta meta;
    meta.value = LangAPI::Variable {.name = var_name(name, false)};
    if (member.quantifier == '*' || member.quantifier == '+') {
        meta.value_list = LangAPI::Variable {.name = var_name(name, true)};
    }
    AST::FailBlock failure_handler = member.failure_handler;
    if (member.failure_handler.name.empty()) {
        failure_handler.name = name;
        if (ctx.variables_lowered[name]) {
            failure_handler.name.push_back(std::to_string(ctx.variables_lowered[name]));
        }
        failure_handler.name.push_back("failure_handler");
    }
    LangAPI::IspaLibFunctionCall match_call = {
        .symbol = LangAPI::IspaLibSymbol {.exports = getMatchSymbol(member.quantifier)},
        .args = {LangAPI::Pos::createExpression(LangAPI::Pos {})},
        .template_parameters = {std::make_shared<LangAPI::Type>(LangAPI::Type {LangAPI::Symbol {"Tokens", name}})}
    };
    auto assignment = createValueAssignment(meta.value.name, LangAPI::IspaLibFunctionCall::createExpression(match_call));
    fun_ctx->statements->push_back(LangAPI::VariableAssignment::createExpression(assignment));

}

auto MemLower::build(const AST::RuleMember &mem) -> void {
    if (mem.isName()) {
        const auto &name = mem.getName();
        if (name.isTerminal()) {
            buildTokenCall(mem, name.name);
        } else if (name.isNonterminal()) {

        }
    }

}