module;
#include <vector>
module LLIR;
auto LLIR::IR::begin() -> ::std::vector<Data>::iterator {
    return data.begin();
}
auto LLIR::IR::end() -> std::vector<Data>::iterator {
    return data.end();
}
auto LLIR::IR::cbegin() -> std::vector<Data>::const_iterator {
    return data.cbegin();
}
auto LLIR::IR::cend() -> std::vector<Data>::const_iterator {
    return data.cend();
}
auto LLIR::IR::size() -> size_t {
    return data.size();
}
auto LLIR::IR::empty() -> bool {
    return data.empty();
}
auto LLIR::IR::operator[](size_t index) const -> const Data& {
    return data[index];
}