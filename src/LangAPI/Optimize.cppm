export module LangAPI.Optimize;

import std;
import LangAPI;
import LangAPI.Traverse;
import LangAPI.Context;
import LangAPI.Rewrite;
import LangAPI.Analysis;
import LangAPI.Pass;

export namespace LangAPI::Optimize {

// Intentionally narrow: trivial scalar literal initializers are side-effect
// free; class constructors, casts, calls, array allocations, volatile access,
// and arbitrary expressions are NOT assumed pure.
[[nodiscard]] inline bool isTrivialScalar(const Type& type) {
    if (!type.isValueType() || !type.template_parameters.empty()) return false;
    switch (std::get<ValueType>(type.type)) {
        case ValueType::Char:
        case ValueType::Int:
        case ValueType::LargeUInt:
        case ValueType::Bool:
        case ValueType::Float: return true;
        default: return false;
    }
}

[[nodiscard]] inline bool isScalarLiteral(const ExpressionValue& value) {
    const auto* rval = std::get_if<RValue>(&value.value);
    if (!rval) return false;
    const auto& v = rval->get();
    return std::holds_alternative<Char>(v) ||
           std::holds_alternative<Int>(v) ||
           std::holds_alternative<Bool>(v) ||
           std::holds_alternative<Float>(v);
}

[[nodiscard]] inline bool isPureInitializer(const Variable& v) {
    if (!isTrivialScalar(v.type) || !v.set.empty()) return false;
    if (v.value.empty()) return true;
    // Even arithmetic over constants can throw, overflow, or be overloaded;
    // accept a single direct literal only.
    return v.value.size() == 1 && isScalarLiteral(v.value.front());
}

[[nodiscard]] inline bool isNoop(const Statement& stmt,
                                 bool remove_comments) {
    if (std::holds_alternative<std::monostate>(stmt.value)) return true;
    if (const auto* expr = std::get_if<Expression>(&stmt.value)) {
        return expr->empty() ||
            (expr->size() == 1 && isScalarLiteral(expr->front()));
    }
    return remove_comments && std::holds_alternative<Comment>(stmt.value);
}

[[nodiscard]] inline bool terminatesBlock(const Statement& stmt) {
    if (std::holds_alternative<Throw>(stmt.value)) return true;
    const auto* expr = std::get_if<Expression>(&stmt.value);
    if (!expr || expr->size() != 1) return false;
    const auto& value = expr->front().value;
    return std::holds_alternative<Return>(value) ||
           std::holds_alternative<Break>(value) ||
           std::holds_alternative<Continue>(value);
}

// Delete unreachable suffixes after an unconditional return/throw/break/
// continue in the same Statements container. Also discard empty or trivially
// side-effect-free expression statements. Never attempts cross-branch CFG DCE.
class RemoveDeadStatements final : public Passes::Pass {
    bool remove_comments_;
public:
    explicit RemoveDeadStatements(bool remove_comments = false)
        : remove_comments_(remove_comments) {}

    [[nodiscard]] std::string_view name() const noexcept override {
        return "RemoveDeadStatements";
    }

    Passes::PassResult run(Context& ctx) override {
        std::size_t removed = 0;
        Rewrite::postOrder(ctx.root(), [&](auto& node) {
            using T = std::remove_cvref_t<decltype(node)>;
            if constexpr (std::same_as<T, Statements>) {
                auto end = node.end();
                for (auto it = node.begin(); it != node.end(); ++it) {
                    if (terminatesBlock(*it)) {
                        end = std::next(it);
                        break;
                    }
                }
                removed += static_cast<std::size_t>(std::distance(end, node.end()));
                node.erase(end, node.end());
                auto it = std::remove_if(node.begin(), node.end(), [&](const Statement& s) {
                    return isNoop(s, remove_comments_);
                });
                removed += static_cast<std::size_t>(std::distance(it, node.end()));
                node.erase(it, node.end());
            }
        });
        if (removed) ctx.markModified();
        return {removed};
    }
};

// Removes local variable declarations only when all of the following hold:
// - trivial scalar type and no side-effectful initializer;
// - no syntactic mentions of the name elsewhere in its enclosing body;
// - no unparseable/dynamic Symbol path in that body.
// Uses deliberately over-approximate symbol occurrences rather than trying
// to infer lexical scopes without a symbol table; ambiguity means *keep*.
class RemoveUnusedLocals final : public Passes::Pass {
    static std::size_t process(Statements& body) {
        const auto index = Analysis::references(std::as_const(body));
        if (index.opaque) return 0;
        const auto old_size = body.size();
        auto new_end = std::remove_if(body.begin(), body.end(), [&](const Statement& stmt) {
            const auto* var = std::get_if<Variable>(&stmt.value);
            return var && !var->name.empty() && isPureInitializer(*var) &&
                !index.mentionsName(var->name);
        });
        body.erase(new_end, body.end());
        return old_size - body.size();
    }

public:
    [[nodiscard]] std::string_view name() const noexcept override {
        return "RemoveUnusedLocals";
    }
    Passes::PassResult run(Context& ctx) override {
        std::size_t removed = 0;
        // A Statements node is the unit of lexical filtering. Recursive
        // subblocks are processed independently, from deepest to outermost.
        Rewrite::postOrder(ctx.root(), [&](auto& node) {
            if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, Statements>) {
                removed += process(node);
            }
        });
        if (removed) ctx.markModified();
        return {removed};
    }
};

struct DeadDeclarationOptions {
    // Must explicitly opt into the closed-world assumption: unknown external
    // consumers may reference otherwise apparently unused exported symbols.
    bool closed_world = false;
    std::vector<std::string> entry_points; // e.g. {"Parser::parseFromTokens"}
    bool remove_functions = true;
    bool remove_classes = true;
    bool remove_variables = true;
    bool remove_aliases_and_enums = true;
    bool remove_empty_namespaces = true;
    bool preserve_class_members = true;
};

// Removes unreachable declarations using a conservative name-based graph.
// No deletion is performed unless closed_world=true, at least one named
// entry point exists, and EVERY entry point matches a declaration.
class RemoveUnusedDeclarations final : public Passes::Pass {
    DeadDeclarationOptions options_;

    [[nodiscard]] bool mayErase(const Declaration& decl) const {
        return std::visit([&](const auto& value) -> bool {
            using T = std::remove_cvref_t<decltype(value)>;
            if constexpr (std::same_as<T, Namespace>) return options_.remove_empty_namespaces;
            else if constexpr (std::same_as<T, Function>) return options_.remove_functions;
            else if constexpr (std::same_as<T, Class> ||
                               std::same_as<T, ForwardDeclaredClass>) return options_.remove_classes;
            else if constexpr (std::same_as<T, Variable>) return options_.remove_variables && isPureInitializer(value);
            else return options_.remove_aliases_and_enums;
        }, decl.value);
    }

public:
    explicit RemoveUnusedDeclarations(DeadDeclarationOptions opts)
        : options_(std::move(opts)) {}

    [[nodiscard]] std::string_view name() const noexcept override {
        return "RemoveUnusedDeclarations";
    }

    Passes::PassResult run(Context& ctx) override {
        if (!options_.closed_world || options_.entry_points.empty()) return {};
        const Analysis::DependencyGraph graph(std::as_const(ctx.root()));
        for (const auto& root : options_.entry_points)
            if (!graph.matchesRoot(root)) return {}; // fail closed

        std::vector<std::string> roots = options_.entry_points;
        // Top-level or class-member static initialization can have observable
        // behavior even when there is no explicit symbol reference.
        for (const auto& n : graph.nodes()) {
            // A declaration that the policy refuses to remove must keep
            // every declaration on which its implementation depends.
            if (!mayErase(*n.declaration))
                roots.push_back(n.qualified_name);
            // Do not silently delete unnameable declarations.
            if (n.name.empty()) return {};
        }

        const auto live = graph.reachable(roots, options_.preserve_class_members);
        // A reachable declaration with a dynamic/unparseable symbolic path
        // may refer indirectly to any generated declaration. Don't prune.
        for (const auto id : live)
            if (graph.nodes()[id].opaque) return {};

        std::unordered_set<const Declaration*> removable;
        for (std::size_t i = 0; i < graph.nodes().size(); ++i) {
            if (!live.contains(i) && mayErase(*graph.nodes()[i].declaration))
                removable.insert(graph.nodes()[i].declaration);
        }

        std::size_t removed = Rewrite::eraseDeclarationsIf(ctx,
            [&](const Declaration& decl) {
                // Namespace deletion is handled only when the namespace has
                // become empty, to preserve unremovable descendants.
                if (const auto* ns = std::get_if<Namespace>(&decl.value)) {
                    return options_.remove_empty_namespaces &&
                        ns->declarations.empty() && removable.contains(&decl);
                }
                return removable.contains(&decl);
            });
        return {removed};
    }
};

struct PipelineOptions {
    bool remove_comments = false;
    bool remove_dead_statements = true;
    bool remove_unused_locals = true;
    DeadDeclarationOptions declarations;
};

// Add passes in an order where dead-statement cleanup runs before reference
// analysis; run multiple rounds to reach a fixed point for chained dead locals.
inline void configure(Passes::PassManager& manager, PipelineOptions options = {}) {
    if (options.remove_dead_statements)
        manager.add<RemoveDeadStatements>(options.remove_comments);
    if (options.remove_unused_locals)
        manager.add<RemoveUnusedLocals>();
    manager.add<RemoveUnusedDeclarations>(std::move(options.declarations));
}

} // namespace LangAPI::Optimize
