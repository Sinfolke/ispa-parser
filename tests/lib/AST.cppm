export module Tests.AST;

import AST.Tree;

export namespace AST::Test {
    auto get(const char* file) -> AST::Tree;
}