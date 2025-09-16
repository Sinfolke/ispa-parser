export module Rope.Tree;
import Rope.Node;
import std;

export namespace Rope {
    constexpr std::size_t max_root_size = 512;
    template<typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    class Tree {
        using CurrentNode = Node<CharT, Traits, Allocator>;
        std::vector<std::shared_ptr<CurrentNode>> roots;
        std::vector<std::size_t> sizes;
        Allocator allocator;
        void insertAfter(CurrentNode* leaf, std::shared_ptr<CurrentNode> new_leaf) {
            new_leaf->right = leaf->right;
            leaf->right = new_leaf;

            // Update roots if necessary
            if (sizes.back() + new_leaf->str.size() >= max_root_size) {
                roots.push_back(new_leaf);
                sizes.push_back(new_leaf->str.size());
            } else {
                sizes.back() += new_leaf->str.size();
            }
        }
    public:
        Tree() {
            roots.push_back(std::make_shared<CurrentNode>("", allocator));
            sizes.push_back(0);
        }
        Tree(Allocator allocator) : allocator(allocator) {
            roots.push_back(std::make_shared<CurrentNode>("", allocator));
            sizes.push_back(0);
        }
        void push(const std::basic_string<CharT, Traits, Allocator> &str) { *roots.back() += str; };
        void insert(std::size_t index, const std::basic_string<CharT, Traits, Allocator> &str) {
            std::size_t offset = 0;
            CurrentNode* leaf = nullptr;
            for (std::size_t i = 0; i < roots.size(); ++i) {
                if (index < offset + sizes[i]) {
                    leaf = roots[i]->getLeafByIndex(index - offset);
                    break;
                }
                offset += sizes[i];
            }
            if (!leaf) {
                push(str);
                return;
            }

            // Insert into leaf
            leaf->str.insert(leaf->str.begin() + index, str.begin(), str.end());

            // Split leaf if too big
            while (leaf->str.size() > max_leaf_size) {
                std::string right_part(leaf->str.begin() + max_leaf_size, leaf->str.end());
                leaf->str.erase(leaf->str.begin() + max_leaf_size, leaf->str.end());

                auto new_leaf = std::make_shared<CurrentNode>(right_part, allocator);

                // Insert new_leaf after leaf
                insertAfter(leaf, new_leaf);

                // Update weights
                leaf->weight = leaf->str.size() + (leaf->left ? leaf->left->size() : 0);
                new_leaf->weight = new_leaf->str.size();

                leaf = new_leaf.get(); // continue if right_part is still too big
            }
        }
        auto size() { return std::accumulate(sizes.begin(), sizes.end(), 0); }
        void clear() { roots = { std::make_shared<CurrentNode>("", allocator) }; sizes = {0}; }
        auto get_allocator() -> Allocator {
            return allocator;
        }
        auto getRoots() { return roots; }
        auto getSizes() { return sizes; }
    };
}
