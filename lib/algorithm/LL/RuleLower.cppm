export module RuleLower;
import AST.API;
import AST.Tree;
import Parser.Base;
import LangAPI;
import hash;
import std;
export struct FunctionCtx {
    LangAPI::Statements *statements;
};
export class RuleLower : Parser::ParserBase {
    utype::unordered_map<std::vector<std::string>, LangAPI::Function> lowered_functions;
    AST::Tree *tree;
    auto register_function(const LangAPI::Function &fun) -> void;
public:
    RuleLower(Parser::Ctx &ctx, AST::Tree &tree) : ParserBase(ctx), tree(&tree) {}
    const auto& declarations() const { return decls; }
    void build(std::vector<std::string> name, const AST::Rule &rule);
    void build(const AST::Tree &tree);
};
