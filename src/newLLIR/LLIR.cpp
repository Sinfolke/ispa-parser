module;
#include <vector>
module LLIR;
auto LLIR::begin() -> ::std::vector<Data>::iterator {
    return data.begin();
}
auto LLIR::end() -> std::vector<Data>::iterator {
    return data.end();
}
auto LLIR::cbegin() -> std::vector<Data>::const_iterator {
    return data.cbegin();
}
auto LLIR::cend() -> std::vector<Data>::const_iterator {
    return data.cend();
}
auto LLIR::size() -> size_t {
    return data.size();
}
auto LLIR::empty() -> bool {
    return data.empty();
}
auto LLIR::operator[](size_t index) const -> const Data& {
    return data[index];
}