export module Rope.Node;

import std;
export namespace Rope {
    constexpr std::size_t max_leaf_size = 128;
    template<typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    struct Node {
        std::basic_string<CharT, Traits, Allocator> str;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::size_t weight = 0;
        Node(const std::basic_string<CharT, Traits, Allocator> &str, Allocator allocator) : str(str, allocator) {}

        auto size() const -> std::size_t {
            std::size_t size = str.size();
            if (left.use_count()) {
                size += left->size();
            }
            if (right.use_count()) {
                size += right->size();
            }
            return size;
        }
        auto getLeafByIndex(std::size_t &index) const -> Node* {
            if (!this) throw std::runtime_error("leaf is unintentionally empty");

            // if leaf node
            if (!left && !right) {
                return const_cast<Node*>(this);
            }

            if (left && index < left->weight) {
                return left->getLeafByIndex(index);
            } else if (right) {
                if (left)
                    index -= left->weight;
                return right->getLeafByIndex(index);
            }

            return nullptr; // index out of range
        }


        void operator+=(const std::string &append_str) {
            if (str.size() + append_str.size() > 128) {
                if (right)
                    *right.get() += append_str;
                else {
                    right = std::make_shared<Node>(append_str, str.get_allocator());
                }
            } else {
                str += append_str;
            }
            weight = str.size() + (left ? left->size() : 0);
            if (right) weight += right->size();
        }
    };
}