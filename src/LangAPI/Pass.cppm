export module LangAPI.Pass;

import std;
import LangAPI.Context;

// Passes operate on the *same* AST owned by the calling build session.
// A pass should use LangAPI.Rewrite (or call Context::markModified after
// directly mutating the AST) so downstream analyses can detect changes.
export namespace LangAPI::Passes {

struct PassResult {
    std::size_t changes = 0; // Count of removed/replaced/modified AST nodes
    [[nodiscard]] bool changed() const noexcept { return changes != 0; }
};

class Pass {
public:
    virtual ~Pass() = default;
    [[nodiscard]] virtual std::string_view name() const noexcept = 0;
    virtual PassResult run(Context& context) = 0;
};

struct PassExecution {
    std::string name;
    std::size_t changes = 0;
    std::uint64_t revision_before = 0;
    std::uint64_t revision_after = 0;
    std::size_t round = 0;
};

struct PassReport {
    std::vector<PassExecution> executions;
    std::size_t total_changes = 0;
    std::size_t rounds = 0;

    [[nodiscard]] bool changed() const noexcept { return total_changes != 0; }
};

class PassManager {
    std::vector<std::unique_ptr<Pass>> passes_;

public:
    template<class T, class... Args>
        requires std::derived_from<T, Pass> && std::constructible_from<T, Args...>
    T& add(Args&&... args) {
        auto pass = std::make_unique<T>(std::forward<Args>(args)...);
        T& ref = *pass;
        passes_.push_back(std::move(pass));
        return ref;
    }

    void clear() noexcept { passes_.clear(); }
    [[nodiscard]] std::size_t size() const noexcept { return passes_.size(); }

    // max_rounds=1 runs each pass once. Repeated rounds allow passes such as
    // unused-local elimination to discover new opportunities after another pass.
    // The caller explicitly controls the maximum: passes might not converge.
    [[nodiscard]] PassReport run(Context& ctx, std::size_t max_rounds = 1) {
        PassReport report;
        for (std::size_t round = 0; round < max_rounds && !passes_.empty(); ++round) {
            std::size_t round_changes = 0;
            for (auto& pass : passes_) {
                const auto before = ctx.revision();
                const auto result = pass->run(ctx);
                // Accommodate passes which perform direct AST edits and return
                // a change count, while Rewrite-based passes already bump it.
                if (result.changed() && ctx.revision() == before)
                    ctx.markModified();
                report.executions.push_back(PassExecution{
                    std::string(pass->name()), result.changes,
                    before, ctx.revision(), round
                });
                round_changes += result.changes;
            }
            ++report.rounds;
            report.total_changes += round_changes;
            if (!round_changes) break;
        }
        return report;
    }
};

} // namespace LangAPI::Passes
