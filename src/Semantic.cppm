export module Semantic;
import AST.Tree;
import dstd;
import std;

export class Semantic {
    AST::Tree tree;

    auto checkDependency(
        const stdu::vector<std::string> &dep,
        const stdu::vector<std::string> &check_dep,
        std::set<stdu::vector<std::string>> &visited
    ) -> bool;
public:
    Semantic(AST::Tree tree) : tree(tree) {}


    auto checkTokenRecursion() -> void;
    ~Semantic() {}
};
