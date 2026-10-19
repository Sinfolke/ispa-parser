module AST.BackendGuard;
import std;

namespace {
[[noreturn]] void reject(const AST::SourcePosition& p, const char* feature) {
    throw std::runtime_error(p.file + ":" + std::to_string(p.line) + ":" +
        std::to_string(p.column) + ": feature " + feature +
        " is not yet supported by the C++ backend");
}

void check(const AST::FrontendFeature& feature) {
    std::visit([](const auto& node) {
        using T = std::decay_t<decltype(node)>;
        const char* name;
        if constexpr (std::is_same_v<T, AST::PythonAction>) name = "Python action";
        else if constexpr (std::is_same_v<T, AST::FailBlock>) name = "fail block";
        else if constexpr (std::is_same_v<T, AST::FailBinding>) name = "rule fail binding";
        else if constexpr (std::is_same_v<T, AST::FailMarker>) name = "fail marker";
        else if constexpr (std::is_same_v<T, AST::RegionCapture>) name = "region capture";
        else if constexpr (std::is_same_v<T, AST::DynamicPattern>) name = "dynamic pattern";
        else if constexpr (std::is_same_v<T, AST::Counter>) name = "bounded counter";
        else if constexpr (std::is_same_v<T, AST::SharedCounterRegistration>) name = "shared counter registration";
        else if constexpr (std::is_same_v<T, AST::VariableCapture>) name = "variable capture";
        else if constexpr (std::is_same_v<T, AST::DeclarationSyntax>) name = "rule modifiers or parameters";
        else if constexpr (std::is_same_v<T, AST::SpacePattern>) name = "explicit whitespace pattern";
        else name = "advanced rule";
        reject(node.position, name);
    }, feature);
}

void check(const AST::RuleMember& member) {
    for (const auto& f : member.features) check(f);
    if (member.isGroup())
        for (const auto& child : member.getGroup().values) check(*child);
    if (member.isOp())
        for (const auto& child : member.getOp().options) check(*child);
}
}

void AST::requireCppSupport(const Tree& tree) {
    for (const auto& fail : tree.getFailBlocks()) reject(fail.position, "fail block");
    for (const auto& [name, rule] : tree.getTreeMap()) {
        for (const auto& feature : rule.features) check(feature);
        for (const auto& member : rule.rule_members) check(*member);
    }
}
