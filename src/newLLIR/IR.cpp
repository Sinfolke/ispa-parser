module;
#include <vector>
module LLIR;
import corelib;
import hash;
bool LLIR::DataBlock::is_inclosed_map() const {
    return std::holds_alternative<LLIR::inclosed_map>(value);
}
bool LLIR::DataBlock::is_raw_expr() const {
    return std::holds_alternative<LLIR::regular_data_block>(value);
}
bool LLIR::DataBlock::empty() const {
    return std::holds_alternative<std::monostate>(value);
}

LLIR::regular_data_block &LLIR::DataBlock::getRegularDataBlock() {
    return std::get<LLIR::regular_data_block>(value);
};
LLIR::inclosed_map &LLIR::DataBlock::getInclosedMap() {
    return std::get<LLIR::inclosed_map>(value);
};
const LLIR::regular_data_block &LLIR::DataBlock::getRegularDataBlock() const {
    return std::get<LLIR::regular_data_block>(value);
};
const LLIR::inclosed_map &LLIR::DataBlock::getInclosedMap() const {
    return std::get<LLIR::inclosed_map>(value);
};
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
auto LLIR::IR::clear() -> void {
    data.clear();
}
LLIR::DataBlockList LLIR::IR::getDataBlocks(bool isToken) {
    LLIR::DataBlockList list;
    for (const auto &[data_block, name, members] : data) {
        if (isToken) {
            if (corelib::text::isLower(name.back())) continue;
        } else {
            if (corelib::text::isUpper(name.back())) continue;
        }
        list[name] = {data_block};
    }
    return list;
}
LLIR::DataBlockList LLIR::IR::getDataBlocksTerminals() {
    return getDataBlocks(true);
}
LLIR::DataBlockList LLIR::IR::getDataBlocksNonTerminals() {
    return getDataBlocks(false);
}

auto LLIR::IR::operator[](size_t index) const -> const Data& {
    return data[index];
}