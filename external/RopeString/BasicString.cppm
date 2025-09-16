export module Rope.BasicString;

import Rope.Node;
import Rope.Tree;
import std;

template<typename CharT>
class iterator {
public:
    Iterator();
    ~Iterator();
};
template<typename CharT>
class reverse_iterator {
public:
    ReverseIterator();
    ~ReverseIterator();
};

export namespace Rope {
    template<typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    class BasicString {
    private:
        using StringType = std::basic_string<CharT, Traits, Allocator>;
        using NodeType = Node<CharT, Traits, Allocator>;
    public:
        using traits_type = Traits;
        using value_type = CharT;
        using allocator_type = Allocator;
        using size_type = std::allocator_traits<Allocator>::size_type;
        using difference_type = std::allocator_traits<Allocator>::difference_type;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = std::allocator_traits<Allocator>::pointer;
        using const_pointer = const std::allocator_traits<Allocator>::pointer;
        using iterator = ::iterator<CharT>;
        using const_iterator = ::iterator<const CharT>;
        using reverse_iterator = ::reverse_iterator<CharT>;
        using reverse_const_iterator = ::reverse_iterator<const CharT>;

        BasicString() {}
        BasicString(const Allocator &alloc) : tree(alloc) {}
        BasicString(size_type count, CharT ch, const Allocator& alloc = Allocator()) {
            tree.push(StringType(count, ch, alloc));
        }
        template<typename InputIt>
        BasicString(const InputIt first, InputIt last, Allocator alloc = Allocator()) {
            tree.push(StringType(first, last, alloc));
        }
#ifdef __cpp_lib_ranges
        template<std::ranges::range R>
        requires std::convertible_to<std::ranges::range_value_t<R>, CharT>
        BasicString(std::from_range_t, R&& rg, const Allocator& alloc = Allocator()) : tree(alloc) {
            for (auto&& c : rg) {
                tree.push(StringType(1, c, alloc));
            }
        }
#endif
        BasicString( const CharT* s, size_type count, const Allocator& alloc = Allocator() ) {
            tree.push(StringType(s, count, alloc));
        }
        BasicString( const CharT* s, const Allocator& alloc = Allocator() ) {
            tree.push(StringType(s, alloc));
        }
        BasicString(std::nullptr_t) = delete;
        template<typename StringViewLike>
        explicit BasicString( const StringViewLike& t, const Allocator& alloc = Allocator() ) {
            tree.push(StringType(t, alloc));
        }
        template<typename StringViewLike>
        BasicString(const StringViewLike& t, size_type pos, size_type count, const Allocator& alloc = Allocator() ) {
            tree.push(StringType(t, pos, count, alloc));
        }

        BasicString( const BasicString& other ) {
            tree = other.tree;
        }
        BasicString(BasicString &&other) noexcept {
            tree = std::move(other.tree);
        }
        BasicString( const BasicString& other, const Allocator &alloc) : tree(alloc){
            tree = other.tree;
        }
        BasicString(BasicString &&other, const Allocator &alloc) : tree(alloc) {
            tree = std::move(other.tree);
        }
        BasicString( const BasicString& other, size_type pos, const Allocator& alloc = Allocator() ) : tree(alloc) {
            tree.push(StringType(other, pos, alloc));
        };
        BasicString( const BasicString& other, size_type pos, size_type count, const Allocator& alloc = Allocator() ) : tree(alloc) {
            tree.push(StringType(other, pos, count, alloc));
        };
        BasicString(std::initializer_list<CharT> ilist, const Allocator& alloc = Allocator() ) : tree(alloc) {
            tree.push(StringType(ilist, alloc));
        }

        // (1) assign from const basic_string&
        auto assign(const BasicString& str) -> BasicString& {
            tree.clear();
            for (auto& root : str.tree.roots) {
                tree.push(root->str); // copy each root string
            }
            return *this;
        }

        // (2) assign from rvalue basic_string
        auto assign(BasicString&& str) noexcept -> BasicString& {
            tree = std::move(str.tree);
            return *this;
        }

        // (3) assign count copies of a char
        auto assign(size_type count, CharT ch) -> BasicString& {
            tree.clear();
            tree.push(StringType(count, ch));
            return *this;
        }

        // (4) assign from const CharT* with count
        auto assign(const CharT* s, size_type count) -> BasicString& {
            tree.clear();
            tree.push(StringType(s, count));
            return *this;
        }

        // (5) assign from const CharT* null-terminated
        auto assign(const CharT* s) -> BasicString& {
            tree.clear();
            tree.push(StringType(s));
            return *this;
        }

        // (6) assign from StringViewLike
        template<typename SV>
        auto assign(const SV& t) -> BasicString& {
            tree.clear();
            tree.push(StringType(t));
            return *this;
        }

        // (7) assign from StringViewLike with pos/count
        template<typename SV>
        auto assign(const SV& t, size_type pos, size_type count = npos) -> BasicString& {
            tree.clear();
            tree.push(StringType(t, pos, count));
            return *this;
        }

        // (8) assign from basic_string with pos/count
        auto assign(const BasicString& str, size_type pos, size_type count = npos) -> BasicString& {
            tree.clear();
            StringType tmp = str.tree.substr(pos, count);
            tree.push(tmp);
            return *this;
        }

        // (9) assign from input iterators
        template<typename InputIt>
        auto assign(InputIt first, InputIt last) -> BasicString& {
            tree.clear();
            tree.push(StringType(first, last));
            return *this;
        }

        // (10) assign from initializer_list
        auto assign(std::initializer_list<CharT> ilist) -> BasicString& {
            tree.clear();
            tree.push(StringType(ilist.begin(), ilist.end()));
            return *this;
        }
#ifdef __cpp_lib_ranges
        template<std::ranges::range R>
        requires std::convertible_to<std::ranges::range_value_t<R>, CharT>
        auto assign_range(R&& rg) -> BasicString& {
            for (auto&& c : rg) {
                tree.push(StringType(1, c, alloc));
            }
            return *this;
        }
#endif
        auto get_allocator() -> BasicString& {
            return tree.get_allocator();
        }
        auto at(size_type pos) -> CharT {
            auto &sizes = tree.getSizes();
            if (pos >= sizes.size() - 1 * max_root_size + sizes.back()) {
                throw std::out_of_range("Rope::BasicString::at");
            }
            return getAtPos(pos);
        }
        auto at(size_type pos) const -> const CharT {
            auto &sizes = tree.getSizes();
            if (pos >= sizes.size() - 1 * max_root_size + sizes.back()) {
                throw std::out_of_range("Rope::BasicString::at");
            }
            return getAtPos(pos);
        }
        auto operator[](size_type pos) -> CharT {
            return getAtPos(pos);
        }
        auto operator[](size_type pos) const -> const CharT {
            return getAtPos(pos);
        }
        auto front() -> CharT& {
            auto &roots = tree.getRoots();
            auto &sizes = tree.getSizes();
            // get root node this string is located
            NodeType *root = roots.front();
            // get leaf and index in it
            while (root->left) {
                root = root->left;
            }
            return root->str.front();
        }
        auto front() const -> const CharT {
            auto &roots = tree.getRoots();
            auto &sizes = tree.getSizes();
            // get root node this string is located
            NodeType *root = roots.front();
            // get leaf and index in it
            while (root->left) {
                root = root->left;
            }
            return root->str.front();
        }
        auto back() -> CharT& {
            auto &roots = tree.getRoots();
            auto &sizes = tree.getSizes();
            // get root node this string is located
            NodeType *root = roots.back();
            // get leaf and index in it
            while (root->right) {
                root = root->right;
            }
            return root->str.back();
        }
        auto back() const -> const CharT {
            auto &roots = tree.getRoots();
            auto &sizes = tree.getSizes();
            // get root node this string is located
            NodeType *root = roots.back();
            // get leaf and index in it
            while (root->right) {
                root = root->right;
            }
            return root->str.back();
        }
        /*
         * Return raw tree reference
         */
        auto data() const -> Tree& {
            return tree;
        }
        /*Get C String. Note to use output to print into stream instead */
        auto c_str() const -> std::unique_ptr<CharT[], std::function<void(CharT*)>> {
            using AllocTraits = std::allocator_traits<Allocator>;
            Allocator alloc;

            std::size_t len = tree.size();
            CharT* cstr = AllocTraits::allocate(alloc, len + 1);

            std::size_t pos = 0;
            for (auto& root : tree.getRoots()) {
                for (auto leaf = root; leaf; leaf = leaf->right.get()) {
                    std::copy(leaf->str.begin(), leaf->str.end(), cstr + pos);
                    pos += leaf->str.size();
                }
            }

            cstr[len] = CharT{};

            // wrap with unique_ptr and custom deleter
            return std::unique_ptr<CharT[], std::function<void(CharT*)>>(
                cstr,
                [alloc, len](CharT* p) mutable { AllocTraits::deallocate(alloc, p, len + 1); }
            );
        }
        auto begin() -> iterator {
            return iterator(tree);
        }
        auto end() -> iterator {
            return iterator(tree, tree.size());
        }
        auto cbegin() -> const_iterator {
            return const_iterator(tree, tree.size());
        }
        auto cend() -> const_iterator {
            return const_iterator(tree, tree.size());
        }
        auto rbegin() -> reverse_iterator {
            return reverse_iterator(tree, 0);
        }
        auto rend() -> reverse_iterator {
            return reverse_iterator(tree, tree.size());
        }
        auto crbegin() -> reverse_const_iterator {
            return reverse_const_iterator(tree, 0);
        }
        auto crend() -> reverse_const_iterator {
            return reverse_const_iterator(tree, tree.size());
        }
        auto empty() -> bool {
            return tree.getSizes().front() == 0;
        }
        auto size() -> size_type {
            return tree.size();
        }
        auto length() -> size_type {
            return size();
        }
        auto clear() -> void {
            tree.clear();
        }
        // (1) insert count copies of a char at index
        auto insert(size_type index, size_type count, CharT ch) -> BasicString& {
            for (size_type i = 0; i < count; ++i)
                tree.insert(index + i, StringType(1, ch));
            return *this;
        }

        // (2) insert null-terminated char array at index
        auto insert(size_type index, const CharT* s) -> BasicString& {
            tree.insert(index, StringType(s));
            return *this;
        }

        // (3) insert char array with count at index
        auto insert(size_type index, const CharT* s, size_type count) -> BasicString& {
            tree.insert(index, StringType(s, count));
            return *this;
        }

        // (4) insert whole BasicString at index
        auto insert(size_type index, const BasicString& str) -> BasicString& {
            for (auto& root : str.tree.getRoots())
                tree.insert(index, root->str);
            return *this;
        }

        // (5) insert part of BasicString [s_index, s_index+count) at index
        auto insert(size_type index, const BasicString& str, size_type s_index, size_type count = std::string::npos) -> BasicString& {
            StringType tmp = str.tree.substr(s_index, count);
            tree.insert(index, tmp);
            return *this;
        }

        // (6) insert single char at iterator position
        auto insert(iterator pos, CharT ch) -> iterator {
            size_type index = pos - begin();
            insert(index, 1, ch);
            return begin() + index;
        }

        // (7) insert count copies of char at iterator position
        auto insert(const_iterator pos, size_type count, CharT ch) -> iterator {
            size_type index = pos - cbegin();
            insert(index, count, ch);
            return begin() + index;
        }

        // (8) insert range [first, last) at iterator position
        template<typename InputIt>
        auto insert(const_iterator pos, InputIt first, InputIt last) -> iterator {
            size_type index = pos - cbegin();
            for (auto it = first; it != last; ++it) {
                tree.insert(index++, StringType(1, *it));
            }
            return begin() + (pos - cbegin());
        }

        // (9) insert initializer_list at iterator position
        auto insert(const_iterator pos, std::initializer_list<CharT> ilist) -> iterator {
            return insert(pos, ilist.begin(), ilist.end());
        }

        // (10) insert StringViewLike at index
        template<typename SV>
        auto insert(size_type index, const SV& t) -> BasicString& {
            tree.insert(index, StringType(t));
            return *this;
        }
        // (10b) insert part of StringViewLike at index
        template<typename SV>
        auto insert(size_type index, const SV& t, size_type t_index, size_type count = npos) -> BasicString& {
            tree.insert(index, StringType(t, t_index, count));
            return *this;
        }
#ifdef __cpp_lib_ranges
        template<std::ranges::range R>
        requires std::convertible_to<std::ranges::range_value_t<R>, CharT>
        auto insert_range(const_iterator pos, R&& rg) -> iterator {
            // compute index from iterator
            size_type index = pos - cbegin();

            // construct a temporary BasicString from the range
            BasicString tmp(std::from_range, std::forward<R>(rg), this->get_allocator());

            // insert it at index
            insert(index, tmp);

            // return iterator to the first inserted element
            return begin() + index;
        }
#endif
        auto erase(size_type index = 0, size_type count = StringType::npos) -> void {
            auto &roots = tree.getRoots();
            auto &sizes = tree.getSizes();

            std::size_t remaining = count;
            std::size_t global_index = index;

            while (remaining != 0 && global_index < tree.size()) {
                // find leaf and adjust index to local
                NodeType* leaf = nullptr;
                std::size_t local_index = global_index;
                for (auto& root : roots) {
                    leaf = root->getLeafByIndex(local_index);
                    if (leaf) break;
                }
                if (!leaf) break; // index out of range

                std::size_t erase_count = std::min(remaining, leaf->str.size() - local_index);
                leaf->str.erase(local_index, erase_count);

                remaining -= erase_count;
                global_index += erase_count;
            }
        }


        basic_string& erase( size_type index = 0, size_type count = npos );
        auto operator=(const BasicString& other) -> BasicString& {
            tree = other.tree;
            return *this;
        }
        auto operator=(const BasicString&& other) noexcept -> BasicString& {
            tree = std::move(other.tree);
            return *this;
        }
        auto operator=(const CharT *s) -> BasicString& {
            tree.clear();
            tree.push(StringType(s));
            return *this;
        }
        auto operator=(CharT ch) -> BasicString& {
            tree.clear();
            tree.push(StringType(1, ch));
            return *this;
        }
        auto operator=(std::initializer_list<CharT> ilist) {
            tree.clear();
            tree.push(StringType(ilist));
        }
        template<class StringViewLike>
        auto operator=(const StringViewLike& t) -> BasicString& {
            tree.clear();
            tree.push(StringType(t));
            return *this;
        }
        auto operator=(std::nullptr_t) -> BasicString& = delete;
    private:
        Tree<CharT, Traits, Allocator> tree;

        inline auto getAtPos(size_type pos) -> CharT& {
            auto &roots = tree.getRoots();
            auto &sizes = tree.getSizes();
            // get root node this string is located
            auto *root = roots.at(pos / max_root_size);
            // get leaf and index in it
            NodeType leaf = root->getLeafByIndex(pos);
            // return character at that index
            return leaf.str.at(pos);
        }
    };
}