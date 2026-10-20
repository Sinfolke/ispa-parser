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

#include "parser_base.hpp"

namespace ISPA_STD {
    /* PARSER */
    template<typename MainNode, typename Token>
    class LLParser : public Parser_base<MainNode, Token> {
    protected:
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
        auto required(IT &pos, FailFunc &fail) {
            if (pos->template holds<NodeStruct>()) {
                auto res = pos->template to_node<NodeStruct>();
                ++pos;
                return res;
            }
            fail(pos);
        }
        template<typename IT, typename Recursive, typename FailFunc>
        auto required(IT &pos, FailFunc &fail, Recursive &rec) {
            if (auto match_result = rec(pos); match_result.status) {
                pos = match_result.it;
                return match_result.node;
            }
            fail(pos);
        }
        template<typename NodeStruct, typename IT>
        auto optional(IT &pos) {
            if (pos->template holds<NodeStruct>()) {
                auto node = pos->template to_node<NodeStruct>();
                ++pos;
                return node;
            }
            return Node<NodeStruct> {};
        }
        template<typename NodeStruct, typename IT, typename Recursive>
        auto optional(IT &pos, Recursive &rec) {
            if (auto match_result = rec(pos); match_result.status) {
                pos = match_result.it;
                return match_result.node;
            }
            return Node<NodeStruct> {};
        }
        template<typename NodeStruct, typename IT, typename FailFunc>
        auto range(IT &pos, FailFunc &fail) {
            std::vector<NodeStruct> result {required<NodeStruct, IT, FailFunc>(pos, fail)};
            while (!pos->isEnd()) {
                auto v = optional<NodeStruct>(pos, fail);
                if (v.empty()) {
                    break;
                }
                result.push_back(v);
            }
            return result;
        }
        template<typename NodeStruct, typename IT, typename Recursive, typename FailFunc>
        auto range(IT &pos, Recursive &rec, FailFunc &fail) {
            std::vector<NodeStruct> result {required<NodeStruct, IT, Recursive, FailFunc>(pos, rec, fail)};
            while (!pos->isEnd()) {
                auto v = optional<NodeStruct>(pos, rec, fail);
                if (v.empty()) {
                    break;
                }
                result.push_back(v);
            }
            return result;
        }
        template<typename NodeStruct, typename IT, typename FailFunc>
        auto range_optional(IT &pos, FailFunc &fail) {
            std::vector<NodeStruct> result;
            while (!pos->isEnd()) {
                auto v = optional<NodeStruct>(pos);
                if (v.empty()) {
                    break;
                }
                result.push_back(v);
            };
            return result;
        }
        template<typename NodeStruct, typename IT, typename Recursive, typename FailFunc>
        auto range_optional(IT &pos, Recursive &rec, FailFunc &fail) {
            std::vector<NodeStruct> result;
            while (!pos->isEnd()) {
                auto v = optional<NodeStruct>(pos, rec, fail);
                if (v.empty()) {
                    break;
                }
                result.push_back(v);
            };
            return result;
        }
    };
} // namespace ISPA_STD
