module LLIR.API;
import std;

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