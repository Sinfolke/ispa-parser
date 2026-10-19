export module AST.BackendGuard;
import AST.Tree;
import AST.API;
import std;

export namespace AST {
    // Called by the driver before passes, automata construction, or LLIR.
    void requireCppSupport(const Tree& tree);
}
