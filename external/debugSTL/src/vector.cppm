export module dstd.vector;
import std;
import std.compat;
export namespace dstd {

template<typename T, class Allocator = std::allocator<T>>
class vector {
    T* element = nullptr;
    size_t sz = 0;
    size_t cap = 0;
    size_t modification_count = 0;
    Allocator allocator;

    void destroy_elements(size_t from, size_t to) {
        if (from > to || to > sz) {
            throw std::out_of_range("destroy_elements: invalid range");
        }
        for (size_t i = from; i < to; ++i) {
            std::destroy_at(element + i);
        }
    }

    void destroy_all() {
        if (element) {
            try {
                destroy_elements(0, sz);
            } catch (...) {
                // Fail-safe: if destruction throws, we still attempt to deallocate
            }
            try {
                allocator.deallocate(element, cap);
            } catch (...) {
                // If deallocation throws, we're already in an unrecoverable state
            }
            element = nullptr;
            sz = 0;
            cap = 0;
        }
    }

    void reallocate(size_t new_cap) {
        T* new_data = allocator.allocate(new_cap); // throws if allocation fails
        size_t i = 0;
        try {
            for (; i < sz; ++i) {
                std::construct_at(new_data + i, std::move_if_noexcept(element[i])); // may throw
            }
        } catch (...) {
            // Clean up partially constructed new_data
            for (size_t j = 0; j < i; ++j) {
                std::destroy_at(new_data + j);
            }
            allocator.deallocate(new_data, new_cap);
            throw;
        }

        // Old data is safe to destroy after successful move
        destroy_elements(0, sz);
        if (element) {
            allocator.deallocate(element, cap);
        }
        element = new_data;
        cap = new_cap;
    }

    void grow_if_needed(size_t min_cap) {
        if (cap < min_cap) {
            size_t new_cap = cap == 0 ? 1 : cap * 2;
            if (new_cap < min_cap) new_cap = min_cap;
            reallocate(new_cap); // already exception-safe
        }
    }

    void check_index(size_t index) const {
        if (index == std::string::npos) {
            throw std::out_of_range("check_index: index is npos");
        }
        if (index >= sz) {
            throw std::out_of_range("check_index: index out of range");
        }
    }
    template<typename Pointer, typename Reference>
    class reverse_iterator_base {
    protected:
        Pointer ptr;
        const vector<T>* vec = nullptr;
        size_t modification_count = 0;

        void invalidation_check() const {
            if (vec && vec->modification_count != modification_count) {
                throw std::runtime_error("iterator invalidated");
            }
        }

        void position_check() const {
            if (!vec) return;
            if (ptr < vec->element || ptr > vec->element + vec->sz) {
                throw std::out_of_range("reverse_iterator out of bounds");
            }
        }

        void dereference_check() const {
            if (!vec) return;
            if (ptr <= vec->element || ptr > vec->element + vec->sz) {
                throw std::out_of_range("reverse_iterator dereferencing out of bounds");
            }
        }

        void check(bool pos) const {
            if (vec == nullptr)
                return;
            invalidation_check();
            pos ? position_check() : dereference_check();
        }

    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = Pointer;
        using reference         = Reference;
        /*
         * NOTE !!! USING THIS ITERATOR WITHOUT A VECTOR WILL LEAD TO ITERATOR INVALIDATION NOT CATCH
         * USING ITERATOR WITH A VECTOR IS AN EXTENSION AND WON't WORK WITH STD::VECTOR
         */
        reverse_iterator_base() : ptr(nullptr) {}
        /*
         * NOTE !!! USING THIS ITERATOR WITHOUT A VECTOR WILL LEAD TO ITERATOR INVALIDATION NOT CATCH
         * USING ITERATOR WITH A VECTOR IS AN EXTENSION AND WON't WORK WITH STD::VECTOR
         */
        explicit reverse_iterator_base(Pointer p) : ptr(p) {}
        /*
         * USING ITERATOR WITH A VECTOR IS AN EXTENSION AND WON't WORK WITH STD::VECTOR
         */
        explicit reverse_iterator_base(const vector<T>& v, Pointer p)
            : ptr(p), vec(&v), modification_count(v.modification_count) {}

        reference operator*() const {
            check(false);
            return *(ptr - 1);
        }

        pointer operator->() const {
            check(false);
            return ptr - 1;
        }

        reverse_iterator_base& operator++() {
            check(true);
            --ptr;
            return *this;
        }

        reverse_iterator_base operator++(int) {
            check(true);
            reverse_iterator_base tmp = *this;
            --ptr;
            return tmp;
        }

        reverse_iterator_base& operator--() {
            check(true);
            ++ptr;
            return *this;
        }

        reverse_iterator_base operator--(int) {
            check(true);
            reverse_iterator_base tmp = *this;
            ++ptr;
            return tmp;
        }

        reverse_iterator_base operator+(difference_type n) const {
            return reverse_iterator_base(ptr - n);
        }

        reverse_iterator_base& operator+=(difference_type n) {
            check(true);
            ptr -= n;
            return *this;
        }

        reverse_iterator_base operator-(difference_type n) const {
            return reverse_iterator_base(ptr + n);
        }

        reverse_iterator_base& operator-=(difference_type n) {
            check(true);
            ptr += n;
            return *this;
        }

        difference_type operator-(const reverse_iterator_base& other) const {
            return other.ptr - ptr;
        }

        reference operator[](difference_type n) const {
            check(false);
            return *(*this + n);
        }

        bool operator==(const reverse_iterator_base& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const reverse_iterator_base& other) const {
            return ptr != other.ptr;
        }

        bool operator<(const reverse_iterator_base& other) const {
            return ptr > other.ptr;
        }

        bool operator>(const reverse_iterator_base& other) const {
            return ptr < other.ptr;
        }

        bool operator<=(const reverse_iterator_base& other) const {
            return ptr >= other.ptr;
        }

        bool operator>=(const reverse_iterator_base& other) const {
            return ptr <= other.ptr;
        }
    };
    template<typename Pointer, typename Reference>
    class iterator_base {
        Pointer ptr;
        const vector<T> *vec = nullptr;
        size_t modification_count = 0;
        void invalidation_check() const {
            if (vec->modification_count != modification_count) {
                throw std::runtime_error("iterator invalidated");
            }
        }
        void out_of_bounds_check() const {
            if (ptr < vec->element || ptr > vec->element + vec->sz) {
                throw std::out_of_range("iterator out of bounds");
            }
        }
        void check() const {
            if (vec == nullptr)
                return;
            invalidation_check();
            out_of_bounds_check();
        }
    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = Pointer;
        using reference         = Reference;

        iterator_base() : ptr(nullptr) {}
        /*
         * NOTE !!! USING THIS ITERATOR WITHOUT A VECTOR WILL LEAD TO ITERATOR INVALIDATION NOT CATCH
         * USING ITERATOR WITH A VECTOR IS AN EXTENSION AND WON't WORK WITH STD::VECTOR
         */
        explicit iterator_base(Pointer p) : ptr(p) {}
        /*
         * USING ITERATOR WITH A VECTOR WILL IS AN EXTENSION AND WON't WORK WITH STD::VECTOR
         */
        explicit iterator_base(const vector<T> &vec, Pointer p) : ptr(p), vec(&vec), modification_count(vec.modification_count) {}
        iterator_base(const iterator_base &it) : ptr(it.ptr), vec(it.vec), modification_count(it.modification_count) {}

        reference operator*() const {
            check();
            return *ptr;
        }
        pointer operator->() const {
            check();
            return ptr;
        }

        iterator_base& operator++() {
            check();
            ++ptr;
            return *this;
        }
        iterator_base operator++(int) {
            check();
            iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        iterator_base& operator--() {
            check();
            --ptr;
            return *this;
        }
        iterator_base operator--(int) {
            check();
            iterator_base tmp = *this;
            --ptr;
            return tmp;
        }

        iterator_base operator+(difference_type n) const {
            check();
            return iterator_base(ptr + n);
        }
        iterator_base& operator+=(difference_type n) {
            check();
            ptr += n;
            return *this;
        }

        iterator_base operator-(difference_type n) const {
            check();
            return iterator_base(ptr - n);
        }

        iterator_base& operator-=(difference_type n) {
            check();
            ptr -= n;
            return *this;
        }

        difference_type operator-(const iterator_base& other) const {
            check();
            return ptr - other.ptr;
        }

        reference operator[](difference_type n) const {
            check();
            return *(ptr + n);
        }

        bool operator==(const iterator_base& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator_base& other) const {
            return ptr != other.ptr;
        }

        bool operator<(const iterator_base& other) const {
            return ptr < other.ptr;
        }

        bool operator>(const iterator_base& other) const {
            return ptr > other.ptr;
        }

        bool operator<=(const iterator_base& other) const {
            return ptr <= other.ptr;
        }

        bool operator>=(const iterator_base& other) const {
            return ptr >= other.ptr;
        }
    };
public:
    using value_type        = T;
    using allocator_type    = Allocator;
    using size_type         = size_t;
    using difference_type   = ptrdiff_t;
    using reference         = T&;
    using const_reference   = const T&;
    using pointer           = T*;
    using const_pointer     = const T*;
    using iterator          = iterator_base<T*, T&>;
    using const_iterator    = iterator_base<const T*, const T&>;
    using reverse_iterator  = reverse_iterator_base<T*, T&>;
    using const_reverse_iterator = reverse_iterator_base<const T*, const T&>;
    vector() = default;

    explicit vector(size_t count) {
        element = allocator.allocate(count);
        modification_count++;
        for (size_t i = 0; i < count; ++i) {
            std::construct_at(element + i);
        }
        sz = count;
        cap = count;
    }

    vector(size_t count, const T& value) {
        element = allocator.allocate(count);
        modification_count++;
        for (size_t i = 0; i < count; ++i) {
            std::construct_at(element + i, value);
        }
        sz = count;
        cap = count;
    }

    // Range constructor
    template <typename InputIt, std::enable_if_t<!std::is_integral_v<InputIt>, int> = 0>
    vector(InputIt begin, InputIt end) {
        sz = std::distance(begin, end);
        cap = sz;
        element = allocator.allocate(cap);
        size_t i = 0;
        for (auto it = begin; it != end; ++it, ++i) {
            std::construct_at(element + i, *it);
        }
        modification_count++;
    }

    vector(const vector<T>& other) {
        element = allocator.allocate(other.sz);
        for (size_t i = 0; i < other.sz; ++i) {
            std::construct_at(element + i, other.element[i]);
        }
        modification_count++;
        sz = other.sz;
        cap = other.sz;
    }

    vector(vector<T>&& other) noexcept
        : element(other.element), sz(other.sz), cap(other.cap), allocator(std::move(other.allocator)) {
        modification_count++;
        other.element = nullptr;
        other.sz = 0;
        other.cap = 0;
    }
    // Copy constructor from std::vector<T>
    vector(const std::vector<T>& other)
        : sz(other.size()), cap(sz), element(nullptr), modification_count(0)
    {
        element = allocator.allocate(cap);
        size_t i = 0;
        try {
            for (; i < sz; ++i) {
                std::construct_at(element + i, other[i]);
            }
            modification_count++;
        } catch (...) {
            for (size_t j = 0; j < i; ++j)
                std::destroy_at(element + j);
            allocator.deallocate(element, cap);
            throw;
        }
    }

    // Move constructor from std::vector<T>
    vector(std::vector<T>&& other) {
        sz = other.size();
        cap = sz;
        element = allocator.allocate(cap);

        size_t i = 0;
        try {
            for (; i < sz; ++i) {
                std::construct_at(element + i, std::move(other[i]));
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j)
                std::destroy_at(element + j);
            allocator.deallocate(element, cap);
            throw;
        }

        modification_count++;
    }
    vector(std::initializer_list<T> il) : sz(il.size()), cap(il.size()) {
        element = allocator.allocate(cap);
        size_t i = 0;
        for (auto it = il.begin(); it != il.end(); ++it, ++i) {
            std::construct_at(element + i, *it);
        }
        modification_count++;
    }
    vector& operator=(const vector& other) {
        if (this != &other) {
            destroy_all();
            modification_count++;
            element = allocator.allocate(other.sz);
            for (size_t i = 0; i < other.sz; ++i) {
                std::construct_at(element + i, other.element[i]);
            }
            sz = other.sz;
            cap = other.sz;
        }
        return *this;
    }

    vector& operator=(vector&& other) noexcept {
        if (this != &other) {
            destroy_all();
            modification_count++;
            element = other.element;
            sz = other.sz;
            cap = other.cap;
            allocator = std::move(other.allocator);

            other.element = nullptr;
            other.sz = 0;
            other.cap = 0;
        }
        return *this;
    }
    vector& operator=(const std::vector<T>& other) {
        if (this == &other)
            return *this;

        // Make a temporary copy of `other`, with strong exception safety
        vector temp;
        temp.sz = other.size();
        temp.cap = temp.sz;
        temp.element = temp.allocator.allocate(temp.cap);

        size_t i = 0;
        try {
            for (const auto& item : other) {
                std::construct_at(temp.element + i, item);
                ++i;
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j)
                std::destroy_at(temp.element + j);
            temp.allocator.deallocate(temp.element, temp.cap);
            throw;
        }

        // Destroy old contents
        for (size_t i = 0; i < sz; ++i)
            std::destroy_at(element + i);
        allocator.deallocate(element, cap);

        // Move from temp
        element = temp.element;
        sz = temp.sz;
        cap = temp.cap;

        temp.element = nullptr;  // prevent double free
        temp.sz = 0;
        temp.cap = 0;

        modification_count++;
        return *this;
    }
    vector& operator=(std::initializer_list<T> il) {
        if (il.size() > cap) {
            // Need new allocation
            T* new_element = allocator.allocate(il.size());
            size_t i = 0;
            for (auto it = il.begin(); it != il.end(); ++it, ++i)
                std::construct_at(new_element + i, *it);
            destroy_all();
            allocator.deallocate(element, cap);
            element = new_element;
            cap = sz = il.size();
        } else {
            size_t i = 0;
            for (; i < il.size(); ++i) {
                if (i < sz)
                    element[i] = *(il.begin() + i); // assignment
                else
                    std::construct_at(element + i, *(il.begin() + i));
            }
            for (size_t j = i; j < sz; ++j)
                std::destroy_at(element + j);
            sz = il.size();
        }

        modification_count++;
        return *this;
    }
    ~vector() {
        modification_count++;
        destroy_all();
    }

    void push_back(const T& value) {
        grow_if_needed(sz + 1);
        modification_count++;
        std::construct_at(element + sz, value);
        ++sz;
    }

    void push_back(T&& value) {
        grow_if_needed(sz + 1);
        std::construct_at(element + sz, std::move(value));
        ++sz;
    }

    template<class... Args>
    void emplace_back(Args&&... args) {
        grow_if_needed(sz + 1);
        modification_count++;
        std::construct_at(element + sz, std::forward<Args>(args)...);
        ++sz;
    }

    void pop_back() {
        if (sz == 0) {
            throw std::out_of_range("vector is empty");
        }
        --sz;
        modification_count++;
        std::destroy_at(element + sz);
    }

    void clear() {
        destroy_elements(0, sz);
        modification_count++;
        sz = 0;
        // Note: capacity remains the same, memory is not freed
    }

    void resize(size_t new_size) {
        if (new_size > cap) {
            grow_if_needed(new_size);
        }
        modification_count++;
        if (new_size > sz) {
            for (size_t i = sz; i < new_size; ++i) {
                std::construct_at(element + i);
            }
        } else if (new_size < sz) {
            destroy_elements(new_size, sz);
        }

        sz = new_size;
    }
    void reserve(size_t new_cap) {
        if (new_cap > cap) {
            reallocate(new_cap);
        }
    }
    iterator erase(iterator pos) {
        size_t index = pos - begin(); // get index from iterator
        check_index(index);

        // Destroy the element at pos
        std::destroy_at(element + index);

        // Shift elements left
        for (size_t i = index; i + 1 < sz; ++i) {
            std::construct_at(element + i, std::move_if_noexcept(element[i + 1]));
            std::destroy_at(element + i + 1);
        }

        --sz;
        return iterator(element + index);
    }
    iterator erase(iterator first, iterator last) {
        size_t index_first = first - begin();
        size_t index_last  = last - begin();

        if (index_first > index_last || index_last > sz) {
            throw std::out_of_range("erase: invalid range");
        }

        size_t erase_count = index_last - index_first;
        size_t move_count  = sz - index_last;

        if (index_first + move_count > cap) {
            // Should never happen if sz ≤ cap and erase range is valid
            throw std::runtime_error("erase: internal error - move destination out of bounds");
        }

        // Destroy elements in [first, last)
        for (size_t i = index_first; i < index_last; ++i) {
            std::destroy_at(element + i);
        }

        // Move trailing elements to fill the gap
        for (size_t i = 0; i < move_count; ++i) {
            std::construct_at(element + index_first + i, std::move_if_noexcept(element[index_last + i]));
            std::destroy_at(element + index_last + i);
        }

        sz -= erase_count;
        return iterator(element + index_first);
    }
    iterator insert(iterator pos, const T value) {
        size_t index = pos - begin(); // validate iterator in range
        if (index > sz) {
            throw std::out_of_range("insert position out of range");
        }

        grow_if_needed(sz + 1); // grow capacity if needed

        // Shift elements to the right
        for (size_t i = sz; i > index; --i) {
            std::construct_at(element + i, std::move(element[i - 1]));
            std::destroy_at(element + i - 1);
        }

        // Insert the new element
        std::construct_at(element + index, value);
        ++sz;
        ++modification_count;

        return begin() + index;
    }
    template<typename InputIt>
    iterator insert(iterator pos, InputIt first, InputIt last) {
        size_t index = pos - begin();
        size_t count = std::distance(first, last);

        if (index > sz) {
            throw std::out_of_range("insert position out of range");
        }

        grow_if_needed(sz + count);

        // Shift existing elements to the right
        for (size_t i = sz; i > index; --i) {
            if (i + count - 1 >= cap) continue; // prevent overrun (shouldn't happen if grow_if_needed is correct)
            std::construct_at(element + i + count - 1, std::move(element[i - 1]));
            std::destroy_at(element + i - 1);
        }

        // Insert new elements
        size_t insert_pos = index;
        for (; first != last; ++first, ++insert_pos) {
            std::construct_at(element + insert_pos, *first);
        }

        sz += count;
        ++modification_count;

        return begin() + index;
    }
    iterator insert(iterator pos, std::initializer_list<T> ilist) {
        return insert(pos, ilist.begin(), ilist.end());
    }
    // Replace content with 'count' copies of 'value'
    void assign(size_t count, const T& value) {
        // Destroy old data
        destroy_all();
        grow_if_needed(count);
        for (size_t i = 0; i < count; ++i) {
            std::construct_at(element + i, value);
        }
        sz = count;
        ++modification_count;
    }

    // Replace content with range [first, last)
    template<typename InputIt>
    void assign(InputIt first, InputIt last) {
        destroy_all();
        size_t count = std::distance(first, last);
        grow_if_needed(count);
        size_t i = 0;
        for (; first != last; ++first, ++i) {
            std::construct_at(element + i, *first);
        }
        sz = count;
        ++modification_count;
    }

    // Replace content with initializer_list
    void assign(std::initializer_list<T> ilist) {
        assign(ilist.begin(), ilist.end());
    }
    size_t size() const noexcept { return sz; }
    size_t capacity() const noexcept { return cap; }
    bool empty() const noexcept { return sz == 0; }
    T& front() {
        return *element;
    }
    T& back() {
        return *(element + sz - 1);
    }
    const T& front() const {
        return *element;
    }
    const T& back() const {
        return *(element + sz - 1);
    }
    T& operator[](size_t index) {
        // no bounds check, add if you want
        check_index(index);
        return element[index];
    }

    const T& operator[](size_t index) const {
        check_index(index);
        return element[index];
    }

    T& at(size_t index) {
        check_index(index);
        return element[index];
    }

    const T& at(size_t index) const {
        check_index(index);
        return element[index];
    }
    // iterators
    auto begin() const -> iterator {return iterator(*this, element); }
    auto end() const -> iterator {return iterator(*this, element + sz); }
    auto cbegin() const -> const_iterator {return const_iterator(*this, element); }
    auto cend() const -> const_iterator {return const_iterator(*this, element + sz); }
    auto rbegin() const -> reverse_iterator {return reverse_iterator(*this, element + sz); }
    auto rend() const -> reverse_iterator { return reverse_iterator(*this, element); }
    auto crbegin() const -> const_reverse_iterator {return const_reverse_iterator(*this, element + sz - 1); }
    auto crend() const -> const_reverse_iterator {return const_reverse_iterator(*this, element - 1); }

    bool operator==(const vector &other) const {
        if (sz != other.sz)
            return false;
        for (size_t i = 0; i < sz; ++i) {
            if (element[i] != other.element[i])
                return false;
        }
        return true;
    }
    bool operator!=(const vector &other) const {
        return !(*this == other);
    }
    bool operator==(const std::vector<T> &other) const {
        if (sz != other.size())
            return false;
        for (size_t i = 0; i < other.size(); ++i) {
            if (element[i] != other[i])
                return false;
        }
        return true;
    }
    bool operator!=(const std::vector<T> &other) const {
        return !(*this == other);
    }
    bool operator<(const vector &other) const {
        return sz < other.sz;
    }
    bool operator>(const vector &other) const {
        return sz > other.sz;
    }
    bool operator<=(const vector &other) const {
        return sz <= other.sz;
    }
    bool operator>=(const vector &other) const {
        return sz >= other.sz;
    }
    bool operator<(const std::vector<T> &other) const {
        return sz < other.size();
    }
    bool operator>(const std::vector<T> &other) const {
        return sz > other.size();
    }
    bool operator<=(const std::vector<T> &other) const {
        return sz <= other.size();
    }
    bool operator>=(const std::vector<T> &other) const {
        return sz >= other.size();
    }
};

}  // namespace dstd
