export module LangAPI.Context;

import std;
import LangAPI;
import LangAPI.Query;
import LangAPI.Traverse;

// Build-session state, NOT a second owner of LangAPI declarations.
// Context borrows a Declarations root. Its typed registry owns only auxiliary
// data (e.g. parser-rule analyses), indexed by stable caller-provided keys.
export namespace LangAPI {

class Context;
template<class T, class Ctx> class StoredSelection;

class Context {
    struct BucketBase {
        virtual ~BucketBase() = default;
    };

    template<class T>
    struct Bucket final : BucketBase {
        // std::map gives deterministic enumeration order. The T objects stay
        // at stable addresses on insertion (until their key is erased).
        std::map<std::string, std::unique_ptr<T>, std::less<>> entries;
    };

    Declarations* root_;
    std::map<std::type_index, std::unique_ptr<BucketBase>> buckets_;
    std::uint64_t revision_ = 0;

    template<class T>
    Bucket<T>* bucketIfPresent() {
        auto it = buckets_.find(std::type_index(typeid(T)));
        return it == buckets_.end() ? nullptr :
            static_cast<Bucket<T>*>(it->second.get());
    }

    template<class T>
    const Bucket<T>* bucketIfPresent() const {
        auto it = buckets_.find(std::type_index(typeid(T)));
        return it == buckets_.end() ? nullptr :
            static_cast<const Bucket<T>*>(it->second.get());
    }

    template<class T>
    Bucket<T>& bucket() {
        auto [it, inserted] = buckets_.try_emplace(
            std::type_index(typeid(T)), nullptr);
        if (inserted)
            it->second = std::make_unique<Bucket<T>>();
        return *static_cast<Bucket<T>*>(it->second.get());
    }

public:
    explicit Context(Declarations& root) noexcept : root_(&root) {}
    Context(const Context&) = delete;
    Context& operator=(const Context&) = delete;
    Context(Context&&) = delete;
    Context& operator=(Context&&) = delete;

    [[nodiscard]] Declarations& root() noexcept { return *root_; }
    [[nodiscard]] const Declarations& root() const noexcept { return *root_; }

    // AST node types query the borrowed AST; auxiliary types query the keyed
    // metadata registry. This is a compile-time distinction, never a copy of
    // LangAPI AST declarations into the metadata store.
    // Mutable AST queries must not change container topology during traversal.
    template<class T>
    [[nodiscard]] auto query() {
        if constexpr (Traverse::AstNode<T>)
            return Query::getAll<T>(*root_);
        else
            return StoredSelection<T, Context>(*this);
    }

    template<class T>
    [[nodiscard]] auto query() const {
        if constexpr (Traverse::AstNode<T>)
            return Query::getAll<T>(std::as_const(*root_));
        else
            return StoredSelection<T, const Context>(*this);
    }

    template<class T, Traverse::AstNode Subtree>
    [[nodiscard]] static auto queryIn(Subtree& subtree) {
        return Query::getAll<T>(subtree);
    }

    // Track structural changes made through Rewrite (or by user code that
    // calls markModified()). This is an invalidation stamp, NOT an AST index.
    [[nodiscard]] std::uint64_t revision() const noexcept { return revision_; }
    void markModified() noexcept { ++revision_; }

    // Typed, keyed, auxiliary data. Keys are unique WITHIN each T bucket.
    // A duplicate key is an error; use find<T>() to update an existing entry.
    template<class T, class... Args>
        requires std::is_object_v<T> &&
                 std::constructible_from<T, Args...>
    T& emplace(std::string key, Args&&... args) {
        auto& entries = bucket<T>().entries;
        if (entries.contains(key))
            throw std::invalid_argument("LangAPI::Context: duplicate metadata key");

        auto value = std::make_unique<T>(std::forward<Args>(args)...);
        T& ref = *value;
        entries.emplace(std::move(key), std::move(value));
        return ref;
    }

    template<class T>
    [[nodiscard]] T* find(std::string_view key) {
        auto* b = bucketIfPresent<T>();
        if (!b) return nullptr;
        auto it = b->entries.find(key);
        return it == b->entries.end() ? nullptr : it->second.get();
    }

    template<class T>
    [[nodiscard]] const T* find(std::string_view key) const {
        auto* b = bucketIfPresent<T>();
        if (!b) return nullptr;
        auto it = b->entries.find(key);
        return it == b->entries.end() ? nullptr : it->second.get();
    }

    template<class T>
    [[nodiscard]] T& get(std::string_view key) {
        if (auto* value = find<T>(key)) return *value;
        throw std::out_of_range("LangAPI::Context: metadata key not found");
    }

    template<class T>
    [[nodiscard]] const T& get(std::string_view key) const {
        if (auto* value = find<T>(key)) return *value;
        throw std::out_of_range("LangAPI::Context: metadata key not found");
    }

    template<class T>
    [[nodiscard]] bool contains(std::string_view key) const {
        return find<T>(key) != nullptr;
    }

    template<class T>
    bool erase(std::string_view key) {
        auto* b = bucketIfPresent<T>();
        if (!b) return false;
        return b->entries.erase(std::string(key)) != 0;
    }

    template<class T>
    void clear() {
        buckets_.erase(std::type_index(typeid(T)));
    }

    void clearAllMetadata() noexcept { buckets_.clear(); }

    // Deterministic key order; references remain valid until individual
    // entries are erased, or the context is cleared/destroyed.
    template<class T, class F>
        requires std::invocable<F&, const std::string&, T&>
    void forEachStored(F&& f) {
        auto* b = bucketIfPresent<T>();
        if (!b) return;
        for (auto& [key, value] : b->entries)
            std::invoke(f, key, *value);
    }

    template<class T, class F>
        requires std::invocable<F&, const std::string&, const T&>
    void forEachStored(F&& f) const {
        auto* b = bucketIfPresent<T>();
        if (!b) return;
        for (const auto& [key, value] : b->entries)
            std::invoke(f, key, std::as_const(*value));
    }

    template<class T>
    [[nodiscard]] std::vector<T*> stored() {
        std::vector<T*> result;
        forEachStored<T>([&](const std::string&, T& value) {
            result.push_back(&value);
        });
        return result;
    }

    template<class T>
    [[nodiscard]] std::vector<const T*> stored() const {
        std::vector<const T*> result;
        forEachStored<T>([&](const std::string&, const T& value) {
            result.push_back(&value);
        });
        return result;
    }
};

// Non-owning, lazy query over context-owned metadata. Mirrors the subset of
// LangAPI.Query.Selection applicable to user-defined metadata types.
// Modifying the registry while iterating it is unsupported.
template<class T, class Ctx>
class StoredSelection {
    Ctx* ctx_;
    std::vector<std::function<bool(const T&)>> predicates_;

    [[nodiscard]] bool matches(const T& value) const {
        for (const auto& predicate : predicates_)
            if (!predicate(value)) return false;
        return true;
    }

public:
    using pointer = std::conditional_t<std::is_const_v<Ctx>, const T*, T*>;
    using reference = std::conditional_t<std::is_const_v<Ctx>, const T&, T&>;

    explicit StoredSelection(Ctx& ctx) noexcept : ctx_(&ctx) {}

    template<class Predicate>
        requires std::copy_constructible<std::decay_t<Predicate>> &&
                 std::predicate<std::decay_t<Predicate>&, const T&>
    [[nodiscard]] StoredSelection where(Predicate&& predicate) const {
        StoredSelection result = *this;
        result.predicates_.emplace_back(std::forward<Predicate>(predicate));
        return result;
    }

    [[nodiscard]] StoredSelection named(std::string name) const
        requires requires(const T& item, const std::string& expected) {
            { item.name == expected } -> std::convertible_to<bool>;
        }
    {
        return where([name = std::move(name)](const T& item) {
            return item.name == name;
        });
    }

    template<class Callback>
        requires std::invocable<Callback&, reference>
    void forEach(Callback&& callback) const {
        ctx_->template forEachStored<T>([&](const std::string&, reference value) {
            if (matches(value)) std::invoke(callback, value);
        });
    }

    [[nodiscard]] std::vector<pointer> collect() const {
        std::vector<pointer> result;
        forEach([&](reference value) { result.push_back(&value); });
        return result;
    }

    [[nodiscard]] pointer first() const {
        pointer result = nullptr;
        forEach([&](reference value) {
            if (!result) result = &value;
        });
        return result;
    }

    [[nodiscard]] bool exists() const { return first() != nullptr; }

    [[nodiscard]] std::size_t count() const {
        std::size_t result = 0;
        forEach([&](reference) { ++result; });
        return result;
    }

    [[nodiscard]] bool empty() const { return !exists(); }
};

} // namespace LangAPI
