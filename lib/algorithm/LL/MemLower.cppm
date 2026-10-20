export module MemLower;

import AST.API;
import AST.Tree;
import Parser.Base;
import hash;
import LangAPI;
import RuleLower;
import std;
export class MemLower : Parser::ParserBase {
    FunctionCtx *fun_ctx;
    AST::Tree *tree;
    std::size_t mem_idx;
    auto buildTokenCall(const AST::RuleMember &member, const std::vector<std::string> &name) -> void;
    auto createValueAssignment(const std::string &name, const LangAPI::Expression &expr) -> LangAPI::VariableAssignment;
    auto getMatchSymbol(char quantifier) -> LangAPI::StdlibExports;
    auto ismemberOptional(char quantifier) -> bool;
public:
    MemLower(const Parser::Ctx &ctx, FunctionCtx &fun_ctx, AST::Tree &tree, std::size_t mem_idx) : ParserBase(ctx), fun_ctx(&fun_ctx), tree(&tree), mem_idx(mem_idx) {}
    // build( const std::vector<std::string> &name, const AST::RuleMember &mem)
    auto build(const AST::RuleMember& mem) -> void;
};