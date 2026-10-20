export module LangAPI.Query;

import std;
import LangAPI;
import LangAPI.Traverse;

export namespace LangAPI::Query {

// A non-owning, lazy typed query over a LangAPI AST subtree.
// The root must outlive the query and its returned pointers.
// Queries do not cache node pointers: each terminal operation traverses again.
template<class Target, class Root>
    requires Traverse::AstNode<std::remove_cvref_t<Root>>
class Selection {
public:
    using node_type = Target;
    using pointer = std::conditional_t<std::is_const_v<Root>,
                                       const Target*, Target*>;
    using reference = std::conditional_t<std::is_const_v<Root>,
                                         const Target&, Target&>;

private:
    Root* root_;
    std::vector<std::function<bool(const Target&)>> predicates_;

    bool matches(const Target& node) const {
        for (const auto& predicate : predicates_)
            if (!predicate(node)) return false;
        return true;
    }

public:
    explicit Selection(Root& root) : root_(&root) {}

    // Composable filtering. Predicate must be copy-constructible and must
    // accept a const Target& (queries never mutate while matching).
    template<class Predicate>
        requires std::copy_constructible<std::decay_t<Predicate>> &&
                 std::predicate<std::decay_t<Predicate>&, const Target&>
    Selection where(Predicate&& predicate) const {
        Selection result = *this;
        result.predicates_.emplace_back(std::forward<Predicate>(predicate));
        return result;
    }

    // Only available when this LangAPI node has a string-comparable `name`.
    Selection named(std::string name) const
        requires requires(const Target& node, const std::string& n) {
            { node.name == n } -> std::convertible_to<bool>;
        }
    {
        return where([name = std::move(name)](const Target& node) {
            return node.name == name;
        });
    }

    // Matches direct `type` representation, not aliases/resolved types.
    template<class TypeValue>
    Selection whereType(TypeValue type) const
        requires requires(const Target& node, const TypeValue& t) {
            { node.type == t } -> std::convertible_to<bool>;
        } && std::copy_constructible<TypeValue>
    {
        return where([type = std::move(type)](const Target& node) {
            return node.type == type;
        });
    }

    // Callback sees Target& or const Target&, according to root constness.
    template<class Callback>
        requires std::invocable<Callback&, reference>
    void forEach(Callback&& callback) const {
        Traverse::forEach<Target>(*root_, [&](auto& node) {
            if (matches(node)) std::invoke(callback, node);
        });
    }

    [[nodiscard]] std::vector<pointer> collect() const {
        std::vector<pointer> result;
        forEach([&](auto& node) { result.push_back(&node); });
        return result;
    }

    // Note: existing Traverse::forEach cannot interrupt a walk, so first()
    // and exists() still scan the tree, but only keep the first match.
    [[nodiscard]] pointer first() const {
        pointer result = nullptr;
        forEach([&](auto& node) {
            if (!result) result = &node;
        });
        return result;
    }

    [[nodiscard]] bool exists() const {
        return first() != nullptr;
    }

    [[nodiscard]] std::size_t count() const {
        std::size_t n = 0;
        forEach([&](auto&) { ++n; });
        return n;
    }

    [[nodiscard]] bool empty() const { return !exists(); }

    // Search below a specific subtree, preserving the target type.
    template<class ChildRoot>
        requires Traverse::AstNode<std::remove_cvref_t<ChildRoot>> &&
                 (std::is_const_v<Root> || !std::is_const_v<ChildRoot>)
    auto within(ChildRoot& subtree) const {
        Selection<Target, ChildRoot> result(subtree);
        for (const auto& pred : predicates_)
            result = result.where(pred);
        return result;
    }
};

// Direct typed query: Query::getAll<Variable>(ast).
template<class Target, class Root>
    requires Traverse::AstNode<std::remove_cvref_t<Root>>
[[nodiscard]] auto getAll(Root& root) {
    return Selection<Target, Root>(root);
}

// Fluent entry point: Query::from(ast).getAll<Variable>().
template<class Root>
    requires Traverse::AstNode<std::remove_cvref_t<Root>>
class Source {
    Root* root_;
public:
    explicit Source(Root& root) : root_(&root) {}

    template<class Target>
    [[nodiscard]] auto getAll() const {
        return Selection<Target, Root>(*root_);
    }
};

template<class Root>
    requires Traverse::AstNode<std::remove_cvref_t<Root>>
[[nodiscard]] auto from(Root& root) {
    return Source<Root>(root);
}

} // namespace LangAPI::Query

// Optional short spelling: LangAPI::query(ast).getAll<Variable>()
export namespace LangAPI {
    template<class Root>
        requires Traverse::AstNode<std::remove_cvref_t<Root>>
    [[nodiscard]] auto query(Root& root) {
        return Query::from(root);
    }
}
