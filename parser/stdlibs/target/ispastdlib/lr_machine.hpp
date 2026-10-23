#pragma once
#include <ispastdlib/parser_base.hpp>
#include <any>
#include <ispastdlib/traits.hpp>
#include <tuple>
#include <limits>
#include <stdexcept>
#include <vector>

namespace ISPA_STD {
// Generated callbacks use a signed action: shift = state+1, reduce = -rule-1,
// accept = 0. Missing cells throw before any stack mutation.
template<class MainNode, class Token>
class LRParser : public Parser_base<MainNode, Token> {
protected:
    // Synthetic grammar symbols carry captures, never user-visible AST nodes.
    struct LRTokenValue { std::any node; std::string text; };
    template<class T>
    static std::any lr_token(T node) {
        std::string text;
        if (node.start() && node.length() != std::string::npos) text.assign(node.start(), node.length());
        return LRTokenValue{std::any(std::move(node)), std::move(text)};
    }
    struct LRCaptures { std::vector<std::vector<std::any>> columns; bool repeated = false; };

    static std::any lr_pack(const std::vector<std::any>& values,
                            const std::vector<std::size_t>& indices,
                            const std::vector<std::size_t>& offsets,
                            const std::vector<std::size_t>& splice, std::size_t count, bool repeated = false) {
        LRCaptures result{std::vector<std::vector<std::any>>(count), repeated};
        for (std::size_t i = 0; i < indices.size(); ++i) {
            const auto& value = values.at(indices[i]);
            if (splice[i]) {
                const auto& child = std::any_cast<const LRCaptures&>(value);
                for (std::size_t c = 0; c < child.columns.size(); ++c) {
                    auto& column = result.columns.at(offsets[i] + c);
                    column.insert(column.end(), child.columns[c].begin(), child.columns[c].end());
                }
            } else result.columns.at(offsets[i]).push_back(value);
        }
        return result;
    }
    template<class T>
    static bool lr_convert(T& target, const std::any& value) {
        if (const auto* token = std::any_cast<LRTokenValue>(&value)) {
            if constexpr (std::is_same_v<T, char>) {
                if (token->text.size() != 1) return false;
                target = token->text.front(); return true;
            } else if constexpr (std::is_same_v<T, std::string>) {
                target = token->text; return true;
            } else if constexpr (!is_variant_v<T>) return lr_convert(target, token->node);
            // A variant may contain a literal char/string alternative as well
            // as typed nodes. Keep the token text until alternatives are tried.
        }
        if (const auto* exact = std::any_cast<T>(&value)) { target = *exact; return true; }
        if constexpr (is_node_v<T>) {
            using Storage = typename T::data_type;
            if constexpr (is_shared_ptr<Storage>::value) {
                using Plain = Node<typename is_shared_ptr<Storage>::element_type>;
                if (const auto* plain = std::any_cast<Plain>(&value)) { target = T(*plain); return true; }
            }
        }
        if (const auto* captures = std::any_cast<LRCaptures>(&value)) {
            bool empty = true;
            for (const auto& column : captures->columns) if (!column.empty()) empty = false;
            if (empty) { target = T{}; return true; }
            if constexpr (is_vector_v<T>) {
                target.clear();
                if (captures->repeated && captures->columns.size() > 1) {
                    const auto rows = captures->columns.front().size();
                    for (const auto& column : captures->columns) if (column.size() != rows) return false;
                    for (std::size_t row = 0; row < rows; ++row) {
                        LRCaptures item;
                        for (const auto& column : captures->columns) item.columns.push_back({column[row]});
                        typename T::value_type element{};
                        if (!lr_convert(element, std::any(item))) return false;
                        target.push_back(std::move(element));
                    }
                    return true;
                }
                for (const auto& column : captures->columns) for (const auto& item : column) {
                    typename T::value_type element{};
                    if (lr_convert(element, item)) target.push_back(std::move(element));
                    else {
                        T nested;
                        if (!lr_convert(nested, item)) return false;
                        target.insert(target.end(), nested.begin(), nested.end());
                    }
                }
                return true;
            } else if constexpr (requires { std::tuple_size<T>::value; } && !is_variant_v<T>) {
                if (captures->columns.size() != std::tuple_size_v<T>) return false;
                return [&]<std::size_t... I>(std::index_sequence<I...>) {
                    return (lr_convert(std::get<I>(target), std::any(LRCaptures{{captures->columns[I]}})) && ...);
                }(std::make_index_sequence<std::tuple_size_v<T>>{});
            } else {
                const std::any* selected = nullptr;
                for (const auto& column : captures->columns) for (const auto& item : column) {
                    if (selected) return false;
                    selected = &item;
                }
                if (!selected) { target = T{}; return true; }
                return lr_convert(target, *selected);
            }
        }
        if constexpr (is_variant_v<T>) {
            return [&]<std::size_t... I>(std::index_sequence<I...>) {
                return ([&] {
                    std::variant_alternative_t<I, T> alternative{};
                    if (!lr_convert(alternative, value)) return false;
                    target.template emplace<I>(std::move(alternative));
                    return true;
                }() || ...);
            }(std::make_index_sequence<std::variant_size_v<T>>{});
        }
        return false;
    }
    template<class T>
    static void lr_capture_assign(T& target, const std::vector<std::any>& values,
                                  std::size_t index, std::size_t column) {
        const auto& value = values.at(index);
        if (column == std::numeric_limits<std::size_t>::max()) {
            if (lr_convert(target, value)) return;
        } else {
            const auto& captures = std::any_cast<const LRCaptures&>(value);
            if (lr_convert(target, std::any(LRCaptures{{captures.columns.at(column)}, captures.repeated}))) return;
        }
        throw std::runtime_error("LR capture payload does not match its declared AST field type: " + std::string{typeid(T).name()});
    }
    template<class T>
    static Node<T> lr_get(const std::vector<std::any>& values, std::size_t index) {
        return std::any_cast<Node<T>>(values.at(index));
    }
    template<class T>
    static Node<T> lr_node(T value) {
        Node<T> node;
        node.set_data(std::move(value));
        return node;
    }
    template<class Generated, class IT>
    MatchResult<MainNode, IT> lr_parse(IT pos) {
        std::vector<std::size_t> states{0};
        std::vector<std::any> values;
        struct RuleSpan {
            std::size_t begin, end;
            bool leading = false, trailing = false, empty = true;
        };
        std::vector<RuleSpan> spans;
        std::size_t cursor = 0;
        auto skip = [](IT& it, std::size_t* offset) {
            if constexpr (requires { Generated::lr_is_space(*it); }) {
                while (!it.isEnd() && Generated::lr_is_space(*it)) {
                    ++it;
                    if (offset) ++*offset;
                }
            }
        };
        auto gap = [](std::size_t rule, std::size_t index) {
            if constexpr (requires { Generated::lr_space(rule, index); })
                return Generated::lr_space(rule, index);
            else return false;
        };
        for (;;) {
            skip(pos, &cursor);
            auto peek = pos;
            std::vector<std::size_t> window;
            for (std::size_t i = 0; i < Generated::lr_k(); ++i) {
                skip(peek, nullptr);
                const bool end = peek.isEnd();
                window.push_back(end ? std::numeric_limits<std::size_t>::max() : (*peek).kind());
                if (!end) ++peek;
            }
            const auto action = Generated::lr_action(states.back(), window);
            if (action == 0) {
                if (values.size() != 1 || !pos.isEnd())
                    throw std::runtime_error("Invalid LR accept stack");
                if ((spans.back().begin && !spans.back().leading) ||
                    (cursor > spans.back().end && !spans.back().trailing))
                    throw std::runtime_error("Whitespace is not allowed at the input boundary");
                return {true, std::any_cast<Node<MainNode>>(std::move(values.back())), pos};
            }
            if (action > 0) {
                if (pos.isEnd()) throw std::runtime_error("LR shift past end of input");
                values.push_back(Generated::lr_shift(*pos));
                spans.push_back(RuleSpan{cursor, cursor + 1, false, false, false});
                ++cursor;
                states.push_back(static_cast<std::size_t>(action - 1));
                ++pos;
            } else {
                const auto rule = static_cast<std::size_t>(-action - 1);
                const auto count = Generated::lr_length(rule);
                if (count > values.size()) throw std::runtime_error("LR stack underflow");
                const auto begin = values.size() - count;
                std::vector<std::any> rhs;
                rhs.reserve(count);
                for (auto i = begin; i < values.size(); ++i) rhs.push_back(std::move(values[i]));
                RuleSpan span{cursor, cursor};
                bool allowed = gap(rule, 0);
                for (std::size_t i = 0; i < count; ++i) {
                    const auto& child = spans[begin + i];
                    if (child.empty) allowed = allowed || child.leading || child.trailing;
                    else {
                        if (span.empty) {
                            span.begin = child.begin;
                            span.leading = allowed || child.leading;
                        } else if (child.begin > span.end && !(allowed || child.leading)) {
                            throw std::runtime_error("Whitespace is not allowed between these rule members");
                        }
                        span.empty = false;
                        span.end = child.end;
                        allowed = child.trailing;
                    }
                    allowed = allowed || gap(rule, i + 1);
                }
                span.trailing = allowed;
                if (span.empty) span.leading = allowed;
                auto value = Generated::lr_reduce(rule, rhs);
                values.resize(begin);
                spans.resize(begin);
                states.resize(begin + 1);
                const auto next = Generated::lr_goto(states.back(), Generated::lr_lhs(rule));
                values.push_back(std::move(value));
                spans.push_back(span);
                states.push_back(next);
            }
        }
    }
};
}
