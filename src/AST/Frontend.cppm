export module AST.Frontend;
import LangAPI.Accessor;
import UAST.PyAST;
import hash;
import dstd;
import std;


export namespace AST {
struct SourcePosition {
    std::string file{};
    std::size_t offset{};
    std::size_t length{};
    std::size_t line{};
    std::size_t column{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(file, offset, length, line, column); }
    auto members() { return std::tie(file, offset, length, line, column); }
};
struct PythonNode {
    std::string kind{};
    std::string field{};
    std::string scalar{};
    SourcePosition position{};
    bool absent{};
    stdu::vector<PythonNode> children{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(kind, field, scalar, position, absent, children); }
    auto members() { return std::tie(kind, field, scalar, position, absent, children); }
};
struct CaptureBinding {
    std::string name{};
    bool optional{};
    bool list{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(name, optional, list); }
    auto members() { return std::tie(name, optional, list); }
};
struct PythonAction {
    PythonNode python{};
    stdu::vector<CaptureBinding> bindings{};
    SourcePosition position{};
    std::string target{};
    // Keep executable syntax as well as the diagnostic/inspection snapshot.
    std::variant<std::monostate, UAST::py::Expr, UAST::py::Module> code{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(python, bindings, position, target, code); }
    auto members() { return std::tie(python, bindings, position, target, code); }
};
struct FailBlock {
    stdu::vector<std::string> name{};
    stdu::vector<std::string> parameters{};
    PythonAction action{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(name, parameters, action, position); }
    auto members() { return std::tie(name, parameters, action, position); }
};
struct FailBinding {
    stdu::vector<std::string> names{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(names, position); }
    auto members() { return std::tie(names, position); }
};
struct FailMarker {
    stdu::vector<std::string> name{};
    stdu::vector<std::string> parameters{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(name, parameters, position); }
    auto members() { return std::tie(name, parameters, position); }
};
struct RegionCapture {
    char capture{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(capture, position); }
    auto members() { return std::tie(capture, position); }
};
struct DynamicPattern {
    std::string name{};
    PythonAction expression{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(name, expression, position); }
    auto members() { return std::tie(name, expression, position); }
};
struct Counter {
    std::string kind{};
    std::string bound{};
    PythonAction expression{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(kind, bound, expression, position); }
    auto members() { return std::tie(kind, bound, expression, position); }
};
struct SharedCounterRegistration {
    std::string name{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(name, position); }
    auto members() { return std::tie(name, position); }
};
struct VariableCapture {
    std::string name{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(name, position); }
    auto members() { return std::tie(name, position); }
};
struct DeclarationSyntax {
    stdu::vector<std::string> modifiers{};
    stdu::vector<std::string> parameters{};
    stdu::vector<std::string> templateParameters{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(modifiers, parameters, templateParameters, position); }
    auto members() { return std::tie(modifiers, parameters, templateParameters, position); }
};
struct AdvancedRule {
    PythonNode syntax{};
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(syntax, position); }
    auto members() { return std::tie(syntax, position); }
};
struct SpacePattern {
    SourcePosition position{};
private:
    friend struct ::uhash;
    friend struct ::LangAPI::MembersAccess;
    auto members() const { return std::tie(position); }
    auto members() { return std::tie(position); }
};
using FrontendFeature = std::variant<PythonAction, FailBlock, FailBinding, FailMarker, RegionCapture, DynamicPattern, Counter, SharedCounterRegistration, VariableCapture, DeclarationSyntax, AdvancedRule, SpacePattern>;
}
