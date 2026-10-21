/**
 * ispastdlib/parser.hpp - LLParser_base
 * Part of the split ISPA std lib; include <ispastdlib.hpp> for everything.
 */
#pragma once
#include <ispastdlib/core.hpp>
#include <ispastdlib/node.hpp>
#include <ispastdlib/lexer.hpp>
#include <ispastdlib/raw_token.hpp>
#include <ispastdlib/token_flow.hpp>
#include <ispastdlib/traits.hpp>

#include <ispastdlib/parser_base.hpp>
#include <ispastdlib/ispa_recovery.hpp>
#include <ispastdlib/ispa_recovery_context.hpp>

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace ISPA_STD {
    /* PARSER */
    template<typename MainNode, typename Token>
    class LLParser : public Parser_base<MainNode, Token> {
    public:
        using Parser_base<MainNode, Token>::parse;

        // Diagnostics from the current/last parse, including a parse that threw.
        // A new parse clears them; callers control how they are displayed.
        [[nodiscard]] const std::vector<Recovery::Diagnostic>& getErrors() const noexcept {
            return recovery_state_.diagnostics;
        }
        // Diagnostics produced by hierarchical (context) recovery.
        [[nodiscard]] const std::vector<Recovery::ContextDiagnostic>& getContextErrors() const noexcept {
            return context_errors_;
        }

    protected:
        Recovery::State recovery_state_;

        // ---------------------------------------------------------------
        // Hierarchical (context) recovery
        //
        // Every rule function owns a Frame (recovery_frame). Before each child
        // member, generated code calls recovery_at<Sets...>(expected, names...),
        // which records the *claims* of that frame at this point: the productions
        // / terminals the rule could still accept (the member itself if repeated,
        // plus the suffix up to the first required member).
        //
        // On a committed failure that local repair cannot fix, the parser scans
        // ahead and finds the earliest token claimed by any active frame
        // (innermost first), skips to it, and unwinds to the owning frame. The
        // owner's own loop/sequence then parses the construct normally.
        //
        // ASSUMPTION: every Set type passed to recovery_at provides
        //     static bool matches(const Token&)
        // ---------------------------------------------------------------
        struct Frame {
            std::string_view rule;
            std::string_view expecting;
            std::vector<Recovery::ContextClaim> claims;
        };
        std::vector<Frame> frames_;
        std::size_t unwind_ = 0;                       // frames still to abandon
        static constexpr std::size_t npos_ = static_cast<std::size_t>(-1);
        std::size_t last_resume_pos_ = npos_;          // progress guard
        bool recovering_ = false;                      // suppress cascading reports
        std::size_t context_max_skip_ = 64;
        std::vector<Recovery::ContextDiagnostic> context_errors_;

        void reset_recovery() {
            recovery_state_.diagnostics.clear();
            recovery_state_.total_skipped = 0;
            frames_.clear();
            unwind_ = 0;
            last_resume_pos_ = npos_;
            recovering_ = false;
            context_errors_.clear();
        }
        MainNode& parse() override {
            reset_recovery();
            return Parser_base<MainNode, Token>::parse();
        }
        MainNode& parseLazy() override {
            reset_recovery();
            return Parser_base<MainNode, Token>::parseLazy();
        }

        struct NoMatch {};
        struct RuleProbe {
            LLParser& parser;
            RuleProbe* previous;
            std::size_t start;
            bool committed = false;
            RuleProbe(LLParser& parser, std::size_t start)
                : parser(parser), previous(parser.probe_), start(start) { parser.probe_ = this; }
            ~RuleProbe() { parser.probe_ = previous; }
            RuleProbe(const RuleProbe&) = delete;
            RuleProbe& operator=(const RuleProbe&) = delete;
        };
        RuleProbe* probe_ = nullptr;

        template<typename IT>
        static auto cursor_position(const IT& pos) -> std::size_t {
            if constexpr (requires { pos.distance(); }) return pos.distance();
            else return reinterpret_cast<std::size_t>(std::addressof(*pos));
        }

        // ----- frames -----
        template<typename Set>
        static bool claim_matches(const void* tok) {
            return Set::matches(*static_cast<const Token*>(tok));
        }

        struct FrameGuard {
            LLParser& p;
            FrameGuard(LLParser& parser, std::string_view rule) : p(parser) {
                p.frames_.push_back(Frame{rule, {}, {}});
            }
            // Abandoned frames count down the unwind request; the frame that
            // is the resume target is the first one that sees it reach zero.
            ~FrameGuard() {
                p.frames_.pop_back();
                if (p.unwind_) --p.unwind_;
            }
            FrameGuard(const FrameGuard&) = delete;
            FrameGuard& operator=(const FrameGuard&) = delete;
        };
        [[nodiscard]] FrameGuard recovery_frame(std::string_view rule) {
            return FrameGuard(*this, rule);
        }

        // Emitted before each child member of the current rule.
        template<typename... Sets, typename... Names>
        void recovery_at(std::string_view expecting, Names... names) {
            static_assert(sizeof...(Sets) == sizeof...(Names),
                          "recovery_at: one claim name per claim set");
            if (frames_.empty()) return;
            auto& frame = frames_.back();
            frame.expecting = expecting;
            frame.claims.clear();
            const std::string_view n[] = {std::string_view(names)..., std::string_view{}};
            std::size_t i = 0;
            (frame.claims.push_back({n[i++], &LLParser::claim_matches<Sets>}), ...);
            (void)i; (void)n;
        }

        [[nodiscard]] bool unwinding() const noexcept { return unwind_ != 0; }

        template<typename IT>
        static std::string describe_token(const IT& pos) {
            if (pos.isEnd()) return "end of input";
            [[maybe_unused]] const auto& tok = *pos;
            if constexpr (requires { tok.meta().start(); tok.meta().length(); }) {
                if (tok.meta().start())
                    return "'" + std::string(std::string_view(tok.meta().start(),
                                                              tok.meta().length())) + "'";
            }
            return "<token>";
        }

        [[nodiscard]] std::string breadcrumb() const {
            std::string out;
            for (const auto& f : frames_) {
                if (!out.empty()) out += " > ";
                out += f.rule;
            }
            return out;
        }

        struct Resume {
            std::size_t skip;
            std::size_t frame;
            const Recovery::ContextClaim* claim;   // null when resuming at end of input
        };

        // Earliest token (within max_skip) claimed by any frame; ties go to the
        // innermost frame. If an identical spot already failed, the innermost frame
        // is not allowed to claim the current token again (guarantees progress).
        template<typename IT>
        std::optional<Resume> resolve_context(IT pos, std::size_t max_skip) const {
            const bool repeat_spot = cursor_position(pos) == last_resume_pos_;
            std::size_t k = 0;
            for (; k <= max_skip && !pos.isEnd(); ++k, ++pos) {
                const void* tok = std::addressof(*pos);
                for (std::size_t f = frames_.size(); f-- > 0;) {
                    if (k == 0 && repeat_spot && f + 1 == frames_.size()) continue;
                    for (const auto& c : frames_[f].claims)
                        if (c.matches && c.matches(tok))
                            return Resume{k, f, &c};
                }
            }
            if (pos.isEnd() && !frames_.empty())
                return Resume{k, 0, nullptr};
            return std::nullopt;
        }

        template<typename IT>
        void report_context(const IT& pos, Recovery::ContextKind kind, const Resume& r) {
            const auto& inner = frames_.back();
            const auto& target = frames_[r.frame];
            Recovery::ContextDiagnostic d;
            d.kind = kind;
            d.position = cursor_position(pos);
            d.skipped = r.skip;
            d.rule = std::string(inner.rule);
            d.resume_rule = std::string(target.rule);
            d.claim = r.claim ? std::string(r.claim->name) : std::string{};

            const std::string tok = describe_token(pos);
            const std::string where = breadcrumb();
            const std::string expected = inner.expecting.empty()
                ? std::string{} : "; expected " + std::string(inner.expecting);

            switch (kind) {
            case Recovery::ContextKind::Misplaced:
                d.message = "'" + d.claim + "' (at " + tok + ") cannot be nested within '" +
                            d.rule + "'" + expected + "; closing '" + d.rule +
                            "' and continuing in '" + d.resume_rule + "'";
                break;
            case Recovery::ContextKind::Stray:
                d.message = "unexpected " + tok + " in " + where +
                            "; no enclosing rule accepts it here; skipped " +
                            std::to_string(r.skip) + " token(s)" +
                            (r.claim ? "; resuming at '" + d.claim + "' of '" + d.resume_rule + "'"
                                     : std::string("; reached end of input"));
                break;
            case Recovery::ContextKind::Mismatch:
            default:
                d.message = "unexpected " + tok + " in " + where + expected;
                if (r.skip)
                    d.message += "; skipped " + std::to_string(r.skip) + " token(s)";
                d.message += r.claim
                    ? "; resuming at '" + d.claim + "' of '" + d.resume_rule + "'"
                    : std::string("; reached end of input");
                break;
            }
            context_errors_.push_back(std::move(d));
        }

        // Local repair already failed (or does not apply). Find a recovery point
        // in the enclosing frames, skip to it, and request unwinding.
        template<typename IT>
        bool recover_at_context(IT& pos, Recovery::ContextKind kind) {
            if (frames_.empty()) return false;
            auto r = resolve_context(pos, context_max_skip_);
            if (!r) return false;
            const bool innermost = r->frame + 1 == frames_.size();
            if (!innermost && r->skip == 0 && r->claim)
                kind = Recovery::ContextKind::Misplaced;
            if (!recovering_ || kind == Recovery::ContextKind::Misplaced)
                report_context(pos, kind, *r);
            for (std::size_t i = 0; i < r->skip && !pos.isEnd(); ++i) ++pos;
            last_resume_pos_ = cursor_position(pos);
            unwind_ = frames_.size() - 1 - r->frame;
            recovering_ = true;
            return true;
        }

        // A loop ended on a token that no active frame can accept: report here,
        // where the mistake is, rather than at the next required member.
        template<typename IT>
        void sync_loop(IT& pos) {
            if (pos.isEnd() || frames_.empty() || unwinding()) return;
            const void* tok = std::addressof(*pos);
            bool any_claims = false;
            for (const auto& f : frames_) {
                for (const auto& c : f.claims) {
                    any_claims = true;
                    if (c.matches && c.matches(tok)) return;   // someone owns it
                }
            }
            if (!any_claims) return;
            recover_at_context(pos, Recovery::ContextKind::Stray);
        }

        void reject_absent_rule() {
            if (probe_ && !probe_->committed)
                throw NoMatch{};
        }
        template<typename IT>
        void commit_rule(const IT& pos) {
            for (auto* probe = probe_; probe; probe = probe->previous)
                if (cursor_position(pos) != probe->start) probe->committed = true;
        }
        void note_match() noexcept { recovering_ = false; }

        // Use these only at committed required matches; unlike the legacy
        // required() they return an explicit Missing/Boundary result on repair.
        template<typename NodeStruct, typename IT, typename Fail>
        auto required_recovering(IT& pos, Fail&& fail) {
            using NodeT = decltype(pos->template to_node<NodeStruct>());
            using Result = Recovery::RequiredResult<NodeT>;
            std::size_t retries = 0;
            while (true) {
                if (pos->template holds<NodeStruct>()) {
                    auto node = pos->template to_node<NodeStruct>();
                    ++pos;
                    commit_rule(pos);
                    note_match();
                    return Result{Recovery::RequiredStatus::Matched,
                                  std::move(node), {}};
                }
                reject_absent_rule();
                auto decision = fail(pos, recovery_state_);
                switch (decision.mode) {
                case Recovery::Mode::Delete:
                    if (++retries <= 2) continue;
                    break;
                case Recovery::Mode::Retry:
                    if (++retries <= 1) continue;
                    break;
                case Recovery::Mode::Insert:
                case Recovery::Mode::Replace:
                    return Result{Recovery::RequiredStatus::Missing,
                                  std::nullopt, decision};
                case Recovery::Mode::Abort:
                    return Result{Recovery::RequiredStatus::Aborted,
                                  std::nullopt, decision};
                default:
                    break;
                }
                // Local repair did not work: look for a recovery point in the
                // enclosing frames (may skip tokens and request unwinding).
                recover_at_context(pos, Recovery::ContextKind::Mismatch);
                return Result{Recovery::RequiredStatus::Boundary,
                              std::nullopt, decision};
            }
        }

        template<typename IT, typename Recursive, typename Fail>
        auto required_rule_recovering(IT& pos, Recursive&& rec, Fail&& fail) {
            using NodeT = std::decay_t<decltype(rec(pos).node)>;
            using Result = Recovery::RequiredResult<NodeT>;
            std::size_t retries = 0;
            while (true) {
                // Recursive alternatives may advance their input argument
                // before failing. Never let a failed probe mutate pos.
                IT attempt = pos;
                auto match = rec(attempt);
                if (match.status) {
                    pos = match.it;
                    commit_rule(pos);
                    note_match();
                    return Result{Recovery::RequiredStatus::Matched,
                                  std::move(match.node), {}};
                }
                if (unwinding()) {
                    // The child abandoned itself for an outer frame; do not
                    // repair here, just propagate.
                    return Result{Recovery::RequiredStatus::Boundary,
                                  std::nullopt, {}};
                }
                reject_absent_rule();
                auto decision = fail(pos, recovery_state_);
                // We cannot synthesize an arbitrary nonterminal from one token.
                if ((decision.mode == Recovery::Mode::Retry ||
                     decision.mode == Recovery::Mode::Delete) && ++retries <= 2)
                    continue;
                if (decision.mode != Recovery::Mode::Abort)
                    recover_at_context(pos, Recovery::ContextKind::Mismatch);
                return Result{
                    decision.mode == Recovery::Mode::Abort
                        ? Recovery::RequiredStatus::Aborted
                        : Recovery::RequiredStatus::Boundary,
                    std::nullopt, decision
                };
            }
        }

        // skip spaces for tokens
        template <typename SpaceTokenType, typename IT>
        void skip_spaces(IT& pos) {
            if ((*pos).template holds<SpaceTokenType>())
                ++pos;
        }
        void raise_error(const Token& node, const std::string& message) {
            // if constexpr (is_raw_token_v<Token>) {
            //     // Error path: report from the shared metadata only. Printing the payload would
            //     // need a visitor over every alternative, i.e. exactly the instantiation cost
            //     // RawToken exists to avoid. The source slice is the token's text.
            //     if (node.empty() && node.meta().start() == nullptr)
            //         return;
            //     const auto& m = node.meta();
            //     std::cerr << "Error at token " << (int) m.name() << "(at position " << m.startpos() << ")" << ": " << message << std::endl;
            //     if (m.start())
            //         std::cerr << "Token: \n" << std::string_view(m.start(), m.length()) << std::endl;
            // } else {
            //     std::visit([&](auto&& arg) {
            //         using T = std::decay_t<decltype(arg)>;
            //         if constexpr (!std::is_same_v<T, std::monostate>) {
            //             std::cerr << "Error at token " << (int) arg.name() << "(at position " << arg.startpos() << ")" << ": " << message << std::endl;
            //             std::cerr << "Token: \n" << arg << std::endl;
            //         }
            //     }, node);
            // }
        }
        template<typename NodeStruct, typename IT, typename FailFunc>
        auto required(IT &pos, FailFunc&& fail) {
            if constexpr (std::is_invocable_v<FailFunc&, IT&, Recovery::State&>) {
                auto result = required_recovering<NodeStruct>(pos, fail);
                if (result.node) return std::move(*result.node);
            } else {
                if (pos->template holds<NodeStruct>()) {
                    auto node = pos->template to_node<NodeStruct>();
                    ++pos;
                    commit_rule(pos);
                    return node;
                }
                reject_absent_rule();
                fail(pos);
            }
            throw std::logic_error("ISPA required(): required token could not be recovered");
        }
        // All rule combinators take (pos, rec, [fail]), matching LL lowering.
        template<typename NodeStruct, typename IT, typename Recursive, typename FailFunc>
        auto required(IT &pos, Recursive&& rec, FailFunc&& fail) {
            if constexpr (std::is_invocable_v<FailFunc&, IT&, Recovery::State&>) {
                auto result = required_rule_recovering(pos, rec, fail);
                if (result.node) return std::move(*result.node);
            } else {
                auto match = rec(pos);
                if (match.status) {
                    pos = match.it;
                    commit_rule(pos);
                    return std::move(match.node);
                }
                reject_absent_rule();
                fail(pos);
            }
            throw std::logic_error("ISPA required(): required rule could not be recovered");
        }
        template<typename NodeStruct, typename IT>
        auto optional(IT &pos) {
            if (pos->template holds<NodeStruct>()) {
                auto node = pos->template to_node<NodeStruct>();
                ++pos;
                commit_rule(pos);
                return node;
            }
            return Node<NodeStruct>{};
        }
        // NOTE: a rule that abandons itself during unwinding must still return
        // status == true (a partial match) or the committed-probe check below
        // will throw.
        template<typename NodeStruct, typename IT, typename Recursive>
        auto optional(IT &pos, Recursive&& rec) {
            auto attempt = pos;
            RuleProbe probe(*this, cursor_position(pos));
            try {
                if (auto match = rec(attempt); match.status) {
                    pos = match.it;
                    commit_rule(pos);
                    return std::move(match.node);
                }
                if (probe.committed)
                    throw std::logic_error("ISPA optional(): rule failed after consuming input");
            } catch (const NoMatch&) {
                // A required descendant did not start. Only the optional
                // caller handles this signal; recovery has not run.
            }
            return Node<NodeStruct>{};
        }
        // Separators belong to a successful next iteration, not to the end
        // of the list. Leave pos (including whitespace) intact on absence.
        template<typename SpaceToken, typename IT, typename Match>
        auto repeat_optional(IT& pos, Match&& match, bool separated = true) {
            auto attempt = pos;
            if constexpr (!std::is_void_v<SpaceToken>) {
                if (separated) skip_spaces<SpaceToken>(attempt);
            }
            const auto start = cursor_position(attempt);
            auto node = match(attempt);
            if (node.empty() || cursor_position(attempt) == start)
                return decltype(node){};
            pos = attempt;
            return node;
        }

        template<typename NodeStruct, typename SpaceToken = void, typename IT, typename FailFunc>
        auto range(IT &pos, FailFunc&& fail) {
            std::vector<Node<NodeStruct>> result;
            if constexpr (std::is_invocable_v<FailFunc&, IT&, Recovery::State&>) {
                auto first = required_recovering<NodeStruct>(pos, fail);
                if (!first.node) return result;   // repaired/unwound: nothing consumed
                result.push_back(std::move(*first.node));
            } else {
                result.push_back(required<NodeStruct>(pos, fail));
            }
            if (unwinding()) return result;
            while (!pos.isEnd() && !unwinding()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt);
                });
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            sync_loop(pos);
            return result;
        }
        template<typename NodeStruct, typename SpaceToken = void, typename IT, typename Recursive, typename FailFunc>
        auto range(IT &pos, Recursive&& rec, FailFunc&& fail) {
            const auto start = cursor_position(pos);
            std::vector<Node<NodeStruct>> result;
            if constexpr (std::is_invocable_v<FailFunc&, IT&, Recovery::State&>) {
                auto first = required_rule_recovering(pos, rec, fail);
                if (!first.node) return result;   // repaired/unwound: nothing consumed
                result.push_back(std::move(*first.node));
            } else {
                result.push_back(required<NodeStruct>(pos, rec, fail));
            }
            if (cursor_position(pos) == start || unwinding()) return result;
            while (!pos.isEnd() && !unwinding()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt, rec);
                });
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            sync_loop(pos);
            return result;
        }
        template<typename NodeStruct, typename SpaceToken = void, typename IT>
        auto range_optional(IT &pos) {
            std::vector<Node<NodeStruct>> result;
            while (!pos.isEnd() && !unwinding()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt);
                }, !result.empty());
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            sync_loop(pos);
            return result;
        }
        template<typename NodeStruct, typename SpaceToken = void, typename IT, typename Recursive>
        auto range_optional(IT &pos, Recursive&& rec) {
            std::vector<Node<NodeStruct>> result;
            while (!pos.isEnd() && !unwinding()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt, rec);
                }, !result.empty());
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            sync_loop(pos);
            return result;
        }
    };
} // namespace ISPA_STD
