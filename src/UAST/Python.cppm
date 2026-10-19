export module UAST.Python;
export import UAST;
import std;
export namespace UAST {
    PythonNode parsePython(const std::string& source, const SourcePosition& position, bool expression);
}
