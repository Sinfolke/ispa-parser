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

void check(const AST::RuleMember& member, bool token) {
    for (const auto& f : member.features) {
        if (const auto* counter = std::get_if<AST::Counter>(&f); counter && !token) {
            if (!(member.isName() || member.isString()) ||
                (member.quantifier != '*' && member.quantifier != '+'))
                reject(counter->position, "counter on a group, choice, or optional matcher");
            if (counter->kind == "name") continue;
            if (counter->kind == "number" && !counter->bound.empty() &&
                std::ranges::all_of(counter->bound, [](char c) { return c >= '0' && c <= '9'; })) {
                try { (void)std::stoll(counter->bound); }
                catch (...) { reject(counter->position, "counter outside the supported integer range"); }
                continue;
            }
        }
        if (!token && std::holds_alternative<AST::SharedCounterRegistration>(f) &&
            (member.isName() || member.isString())) continue;
        check(f);
    }
    if (member.isGroup())
        for (const auto& child : member.getGroup().values) check(*child, token);
    if (member.isOp())
        for (const auto& child : member.getOp().options) check(*child, token);
}
}

void AST::requireCppSupport(const Tree& tree) {
    for (const auto& fail : tree.getFailBlocks()) reject(fail.position, "fail block");
    for (const auto& [name, rule] : tree.getTreeMap()) {
        for (const auto& feature : rule.features) check(feature);
        const bool token = AST::RuleMemberName{.name = name}.isTerminal();
        for (const auto& member : rule.rule_members) check(*member, token);
    }
}
