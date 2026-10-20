export module LangAPI.Rewrite;

import std;
import LangAPI;
import LangAPI.Traverse;
import LangAPI.Context;

// Explicit structural edits. Do not erase/reallocate owning containers from
// callbacks run by Traverse::walk or Query::forEach; use these operations.
export namespace LangAPI::Rewrite {

// Postorder is important: child edits finish before the owning parent can be
// replaced or erased. Never change an ancestor/container while visiting a child.
template<Traverse::AstNode Root, class Visitor>
void postOrder(Root& root, Visitor&& visitor) {
    auto&& callback = visitor;
    auto recurse = [&](auto&& self, auto& node) -> void {
        Traverse::forEachChild(node, [&](auto& child) {
            self(self, child);
        });
        std::invoke(callback, node);
    };
    recurse(recurse, root);
}

// Field-only edit. Action must NOT change the topology (sizes, variant
// alternatives, ownership) of the AST during traversal.
template<class Target, Traverse::AstNode Root, class Action>
    requires std::invocable<Action&, Target&>
std::size_t edit(Root& root, Action&& action) {
    std::size_t changed = 0;
    postOrder(root, [&](auto& node) {
        if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, Target>) {
            std::invoke(action, node);
            ++changed;
        }
    });
    return changed;
}

// Replaces an object with the SAME concrete node type, after visiting its
// children. May invalidate pointers/references to descendants of that node.
// New descendants are not visited until a later pass.
template<class Target, Traverse::AstNode Root, class Predicate, class Factory>
    requires std::predicate<Predicate&, const Target&> &&
             std::invocable<Factory&, const Target&> &&
             std::constructible_from<Target,
                 std::invoke_result_t<Factory&, const Target&>> &&
             std::assignable_from<Target&, Target>
std::size_t transform(Root& root, Predicate&& predicate, Factory&& factory) {
    std::size_t changed = 0;
    postOrder(root, [&](auto& node) {
        if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, Target>) {
            if (std::invoke(predicate, std::as_const(node))) {
                Target replacement(std::invoke(factory, std::as_const(node)));
                node = std::move(replacement);
                ++changed;
            }
        }
    });
    return changed;
}

namespace detail {
    template<class Container, class Predicate>
    std::size_t eraseElements(Container& values, Predicate& predicate) {
        const auto before = values.size();
        auto newEnd = std::remove_if(values.begin(), values.end(), std::ref(predicate));
        values.erase(newEnd, values.end());
        return before - values.size();
    }
}

// AST declaration slots are owned by Declarations::vector and Class::data.
// This reaches both, including classes and namespaces nested in either.
// Predicate receives a const Declaration&, NOT a pointer to a concrete
// variant alternative. This prevents accidentally erasing non-owning refs.
template<Traverse::AstNode Root, class Predicate>
    requires std::predicate<Predicate&, const Declaration&>
std::size_t eraseDeclarationsIf(Root& root, Predicate&& predicate) {
    std::size_t removed = 0;
    postOrder(root, [&](auto& node) {
        using N = std::remove_cvref_t<decltype(node)>;
        if constexpr (std::same_as<N, Declarations>) {
            removed += detail::eraseElements(node, predicate);
        } else if constexpr (std::same_as<N, Class>) {
            auto drop = [&](const auto& entry) {
                return entry.first &&
                    std::invoke(predicate, std::as_const(*entry.first));
            };
            removed += detail::eraseElements(node.data, drop);
        }
    });
    return removed;
}

// Nested statement containers: function bodies, if/loop bodies, lambdas, etc.
template<Traverse::AstNode Root, class Predicate>
    requires std::predicate<Predicate&, const Statement&>
std::size_t eraseStatementsIf(Root& root, Predicate&& predicate) {
    std::size_t removed = 0;
    postOrder(root, [&](auto& node) {
        if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, Statements>)
            removed += detail::eraseElements(node, predicate);
    });
    return removed;
}

// Token-level expression editing. Callers must preserve expression validity.
template<Traverse::AstNode Root, class Predicate>
    requires std::predicate<Predicate&, const ExpressionValue&>
std::size_t eraseExpressionValuesIf(Root& root, Predicate&& predicate) {
    std::size_t removed = 0;
    postOrder(root, [&](auto& node) {
        if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, Expression>)
            removed += detail::eraseElements(node, predicate);
    });
    return removed;
}

// Replace whole wrapper slots (including with a different variant choice).
// Unlike transform<T>(), these allow replacing Function with Class, or
// Return with RValue, when the respective wrapper permits it.
template<Traverse::AstNode Root, class Predicate, class Factory>
    requires std::predicate<Predicate&, const Declaration&> &&
             std::invocable<Factory&, const Declaration&> &&
             std::constructible_from<Declaration,
                 std::invoke_result_t<Factory&, const Declaration&>>
std::size_t replaceDeclarationsIf(Root& root, Predicate&& predicate,
                                  Factory&& factory) {
    std::size_t changed = 0;
    postOrder(root, [&](auto& node) {
        if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, Declaration>) {
            if (std::invoke(predicate, std::as_const(node))) {
                Declaration replacement(std::invoke(factory, std::as_const(node)));
                node = std::move(replacement);
                ++changed;
            }
        }
    });
    return changed;
}

template<Traverse::AstNode Root, class Predicate, class Factory>
    requires std::predicate<Predicate&, const Statement&> &&
             std::invocable<Factory&, const Statement&> &&
             std::constructible_from<Statement,
                 std::invoke_result_t<Factory&, const Statement&>>
std::size_t replaceStatementsIf(Root& root, Predicate&& predicate,
                                Factory&& factory) {
    std::size_t changed = 0;
    postOrder(root, [&](auto& node) {
        if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, Statement>) {
            if (std::invoke(predicate, std::as_const(node))) {
                Statement replacement(std::invoke(factory, std::as_const(node)));
                node = std::move(replacement);
                ++changed;
            }
        }
    });
    return changed;
}

template<Traverse::AstNode Root, class Predicate, class Factory>
    requires std::predicate<Predicate&, const ExpressionValue&> &&
             std::invocable<Factory&, const ExpressionValue&> &&
             std::constructible_from<ExpressionValue,
                 std::invoke_result_t<Factory&, const ExpressionValue&>>
std::size_t replaceExpressionValuesIf(Root& root, Predicate&& predicate,
                                      Factory&& factory) {
    std::size_t changed = 0;
    postOrder(root, [&](auto& node) {
        if constexpr (std::same_as<std::remove_cvref_t<decltype(node)>, ExpressionValue>) {
            if (std::invoke(predicate, std::as_const(node))) {
                ExpressionValue replacement(std::invoke(factory, std::as_const(node)));
                node = std::move(replacement);
                ++changed;
            }
        }
    });
    return changed;
}

// Context overloads automatically bump the revision when a pass changes nodes.
// Mutations made directly through ctx.root() or AST pointers must manually
// call ctx.markModified() if users cache analyses keyed by revision.
template<class Target, class Action>
std::size_t edit(Context& ctx, Action&& action) {
    const auto count = edit<Target>(ctx.root(), std::forward<Action>(action));
    if (count) ctx.markModified();
    return count;
}

template<class Target, class Predicate, class Factory>
std::size_t transform(Context& ctx, Predicate&& predicate, Factory&& factory) {
    const auto count = transform<Target>(ctx.root(),
        std::forward<Predicate>(predicate), std::forward<Factory>(factory));
    if (count) ctx.markModified();
    return count;
}

template<class Predicate>
std::size_t eraseDeclarationsIf(Context& ctx, Predicate&& predicate) {
    const auto count = eraseDeclarationsIf(ctx.root(), std::forward<Predicate>(predicate));
    if (count) ctx.markModified();
    return count;
}

template<class Predicate>
std::size_t eraseStatementsIf(Context& ctx, Predicate&& predicate) {
    const auto count = eraseStatementsIf(ctx.root(), std::forward<Predicate>(predicate));
    if (count) ctx.markModified();
    return count;
}

template<class Predicate>
std::size_t eraseExpressionValuesIf(Context& ctx, Predicate&& predicate) {
    const auto count = eraseExpressionValuesIf(ctx.root(), std::forward<Predicate>(predicate));
    if (count) ctx.markModified();
    return count;
}

template<class Predicate, class Factory>
std::size_t replaceDeclarationsIf(Context& ctx, Predicate&& predicate,
                                  Factory&& factory) {
    const auto count = replaceDeclarationsIf(ctx.root(),
        std::forward<Predicate>(predicate), std::forward<Factory>(factory));
    if (count) ctx.markModified();
    return count;
}

template<class Predicate, class Factory>
std::size_t replaceStatementsIf(Context& ctx, Predicate&& predicate,
                                Factory&& factory) {
    const auto count = replaceStatementsIf(ctx.root(),
        std::forward<Predicate>(predicate), std::forward<Factory>(factory));
    if (count) ctx.markModified();
    return count;
}

template<class Predicate, class Factory>
std::size_t replaceExpressionValuesIf(Context& ctx, Predicate&& predicate,
                                      Factory&& factory) {
    const auto count = replaceExpressionValuesIf(ctx.root(),
        std::forward<Predicate>(predicate), std::forward<Factory>(factory));
    if (count) ctx.markModified();
    return count;
}

} // namespace LangAPI::Rewrite
