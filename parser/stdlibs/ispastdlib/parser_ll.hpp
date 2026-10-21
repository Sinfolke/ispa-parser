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

    protected:
        Recovery::State recovery_state_;

        void reset_recovery() {
            recovery_state_.diagnostics.clear();
            recovery_state_.total_skipped = 0;
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
        void reject_absent_rule() {
            if (probe_ && !probe_->committed)
                throw NoMatch{};
        }
        template<typename IT>
        void commit_rule(const IT& pos) {
            for (auto* probe = probe_; probe; probe = probe->previous)
                if (cursor_position(pos) != probe->start) probe->committed = true;
        }

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
                    return Result{Recovery::RequiredStatus::Matched,
                                  std::move(match.node), {}};
                }
                reject_absent_rule();
                auto decision = fail(pos, recovery_state_);
                // We cannot synthesize an arbitrary nonterminal from one token.
                if ((decision.mode == Recovery::Mode::Retry ||
                     decision.mode == Recovery::Mode::Delete) && ++retries <= 2)
                    continue;
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
            std::vector<Node<NodeStruct>> result{required<NodeStruct>(pos, fail)};
            while (!pos.isEnd()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt);
                });
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
        template<typename NodeStruct, typename SpaceToken = void, typename IT, typename Recursive, typename FailFunc>
        auto range(IT &pos, Recursive&& rec, FailFunc&& fail) {
            const auto start = cursor_position(pos);
            std::vector<Node<NodeStruct>> result{required<NodeStruct>(pos, rec, fail)};
            if (cursor_position(pos) == start) return result;
            while (!pos.isEnd()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt, rec);
                });
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
        template<typename NodeStruct, typename SpaceToken = void, typename IT>
        auto range_optional(IT &pos) {
            std::vector<Node<NodeStruct>> result;
            while (!pos.isEnd()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt);
                }, !result.empty());
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
        template<typename NodeStruct, typename SpaceToken = void, typename IT, typename Recursive>
        auto range_optional(IT &pos, Recursive&& rec) {
            std::vector<Node<NodeStruct>> result;
            while (!pos.isEnd()) {
                auto node = repeat_optional<SpaceToken>(pos, [&](auto& attempt) {
                    return optional<NodeStruct>(attempt, rec);
                }, !result.empty());
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
    };
} // namespace ISPA_STD
