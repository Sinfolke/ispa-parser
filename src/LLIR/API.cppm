export module LLIR.API;

import LangAPI;
import hash;
import dstd;

export namespace LLIR {
    using inclosed_map = std::unordered_map<std::string, std::pair<LangAPI::Expression, LangAPI::Type>>;
    using regular_data_block = std::pair<LangAPI::Expression, LangAPI::Type>;
    struct DataBlock {
        std::variant<std::monostate, regular_data_block, inclosed_map> value;
        bool is_inclosed_map() const { return std::holds_alternative<inclosed_map>(value); };
        bool is_regular_data_block() const { return std::holds_alternative<regular_data_block>(value); };
        bool empty() const { return std::holds_alternative<std::monostate>(value); };
        regular_data_block &getRegularDataBlock() { return std::get<regular_data_block>(value); };
        inclosed_map &getInclosedMap() { return std::get<inclosed_map>(value); };
        const regular_data_block &getRegularDataBlock() const { return std::get<regular_data_block>(value); };
        const inclosed_map &getInclosedMap() const { return std::get<inclosed_map>(value); };
    };
    struct ExportsAfterBuild {
        LangAPI::Variable svar;
        LangAPI::Variable uvar;
        LangAPI::Variable var;
        LangAPI::Variable shadow_var;
        char quantifier;
    };
    struct Production {
        DataBlock block;
        stdu::vector<std::string> name;
        LangAPI::Statements members;
    };
    using DataBlockList = utype::unordered_map<stdu::vector<std::string>, DataBlock>;
}