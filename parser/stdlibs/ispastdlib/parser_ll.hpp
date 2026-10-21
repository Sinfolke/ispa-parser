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
    protected:
        Recovery::State recovery_state_;

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
                    return Result{Recovery::RequiredStatus::Matched,
                                  std::move(node), {}};
                }
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
                    return Result{Recovery::RequiredStatus::Matched,
                                  std::move(match.node), {}};
                }
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
                    return node;
                }
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
                    return std::move(match.node);
                }
                fail(pos);
            }
            throw std::logic_error("ISPA required(): required rule could not be recovered");
        }
        template<typename NodeStruct, typename IT>
        auto optional(IT &pos) {
            if (pos->template holds<NodeStruct>()) {
                auto node = pos->template to_node<NodeStruct>();
                ++pos;
                return node;
            }
            return Node<NodeStruct>{};
        }
        template<typename NodeStruct, typename IT, typename Recursive>
        auto optional(IT &pos, Recursive&& rec) {
            auto attempt = pos;
            if (auto match = rec(attempt); match.status) {
                pos = match.it;
                return std::move(match.node);
            }
            return Node<NodeStruct>{};
        }
        template<typename NodeStruct, typename IT, typename FailFunc>
        auto range(IT &pos, FailFunc&& fail) {
            std::vector<Node<NodeStruct>> result{required<NodeStruct>(pos, fail)};
            while (!pos.isEnd()) {
                auto node = optional<NodeStruct>(pos);
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
        template<typename NodeStruct, typename IT, typename Recursive, typename FailFunc>
        auto range(IT &pos, Recursive&& rec, FailFunc&& fail) {
            std::vector<Node<NodeStruct>> result{required<NodeStruct>(pos, rec, fail)};
            while (!pos.isEnd()) {
                auto node = optional<NodeStruct>(pos, rec);
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
        template<typename NodeStruct, typename IT>
        auto range_optional(IT &pos) {
            std::vector<Node<NodeStruct>> result;
            while (!pos.isEnd()) {
                auto node = optional<NodeStruct>(pos);
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
        template<typename NodeStruct, typename IT, typename Recursive>
        auto range_optional(IT &pos, Recursive&& rec) {
            std::vector<Node<NodeStruct>> result;
            while (!pos.isEnd()) {
                auto node = optional<NodeStruct>(pos, rec);
                if (node.empty()) break;
                result.push_back(std::move(node));
            }
            return result;
        }
    };
} // namespace ISPA_STD
