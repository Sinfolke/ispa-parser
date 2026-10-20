export module UAST.Python;
export import UAST;
import std;
export namespace UAST {
    // Typed Python AST for an embedded expression / statement block.
    // `position` is where the Python source starts in the host file.
    py::ExprPtr parsePythonExpr(const std::string& source, const SourcePosition& position);
    py::Module parsePythonModule(const std::string& source, const SourcePosition& position);

    // Lossless, generic view of the raw parser output (node kinds, field names,
    // variants, absent nodes). Debugging aid only; the typed AST is built from it.
    PythonNode parsePythonSnapshot(const std::string& source, const SourcePosition& position, bool expression);

    namespace py {
        // S-expression dumps of the typed tree, for tests and debugging.
        std::string dump(const Expr& expr);
        std::string dump(const Stmt& stmt);
        std::string dump(const Module& m);
    }
}
