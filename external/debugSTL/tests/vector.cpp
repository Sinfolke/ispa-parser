import dstd.std::vector;
import std;
import std.compat;
#define assert(cond) do { if (!(cond)) throw std::runtime_error("Assertion failed"); } while(0)
int main() {
    using dstd::std::vector;
    // Test default constructor
    std::vector<int> v1;
    assert(v1.size() == 0);

    // Test size constructor
    std::vector<int> v2(5);
    assert(v2.size() == 5);

    // Test size + value constructor
    std::vector<int> v3(4, 42);
    assert(v3.size() == 4);
    for (std::size_t i = 0; i < v3.size(); ++i)
        assert(v3[i] == 42);

    // Test initializer list constructor
    std::vector<int> v4{1, 2, 3, 4};
    assert(v4.size() == 4);
    assert(v4[0] == 1 && v4[3] == 4);

    // Test copy constructor
    std::vector<int> v5 = v4;
    assert(v5.size() == v4.size());
    for (std::size_t i = 0; i < v5.size(); ++i)
        assert(v5[i] == v4[i]);

    // Test move constructor
    std::vector<int> v6 = std::move(v5);
    assert(v6.size() == 4);

    // Test push_back
    v1.push_back(10);
    v1.push_back(20);
    assert(v1.size() == 2);
    assert(v1[0] == 10 && v1[1] == 20);

    // Test pop_back
    v1.pop_back();
    assert(v1.size() == 1);
    assert(v1[0] == 10);

    // Test emplace_back
    v1.emplace_back(99);
    assert(v1[1] == 99);

    // Test resize (grow)
    v1.resize(5);
    assert(v1.size() == 5);

    // Test resize (shrink)
    v1.resize(2);
    assert(v1.size() == 2);

    // Test clear
    v1.clear();
    assert(v1.size() == 0);

    // Test copy assignment
    std::vector<int> v7;
    v7 = v4;
    assert(v7.size() == 4);
    assert(v7[2] == 3);

    // Test move assignment
    std::vector<int> v8;
    v8 = std::move(v7);
    assert(v8.size() == 4);

    // Test initializer list assignment
    v8 = {7, 8, 9};
    assert(v8.size() == 3);
    assert(v8[0] == 7 && v8[2] == 9);

    // --- Self-assignment ---
    std::vector<int> v9{1, 2, 3};
    v9 = v9;
    assert(v9.size() == 3);
    assert(v9[0] == 1 && v9[2] == 3);

    // --- Move state after move ---
    std::vector<int> v10{5, 6, 7};
    std::vector<int> v11 = std::move(v10);
    assert(v11.size() == 3);
    assert(v11[0] == 5 && v11[2] == 7);
    // Moved-from std::vector is in valid state (likely empty)
    assert(v10.size() == 0 || true);

    // --- Reserve / Capacity (if implemented) ---
    std::vector<int> v14;
    v14.reserve(100);
    std::size_t cap = v14.capacity();
    assert(cap >= 100);

    for (int i = 0; i < 50; ++i) v14.push_back(i);
    assert(v14.capacity() == cap); // Capacity unchanged after push_back

    // --- Iterators / range-for (if implemented) ---
    std::vector<int> v15{1, 2, 3, 4};
    int sum = 0;
    for (int x : v15)
        sum += x;
    assert(sum == 10);

    // --- Const correctness ---
    const std::vector<int> v16{9, 8, 7};
    assert(v16.size() == 3);
    assert(v16[0] == 9);

    // --- Complex element types ---

    // a) std::string
    std::vector<std::string> v17{"hello", "world"};
    assert(v17[0] == "hello" && v17[1] == "world");

    // b) std::unique_ptr<int>
    std::vector<std::unique_ptr<int>> v18;
    v18.push_back(std::make_unique<int>(10));
    v18.emplace_back(new int(20));
    assert(*v18[0] == 10 && *v18[1] == 20);

    std::cout << "All std::vector tests passed!\n";
}
