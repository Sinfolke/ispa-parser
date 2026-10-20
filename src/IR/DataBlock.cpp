module LLIR.API;
import Parser.Base;
import std;
namespace LLIR {
auto dataBlock(const AST::DataBlock& block) -> DataBlock {
    DataBlock result;
    if (block.type) result.value = regular_data_block{{}, Parser::ParserBase::dataType(*block.type)};
    else if (!block.fields.empty()) {
        inclosed_map fields;
        for (const auto& [name, type] : block.fields)
            fields.emplace(name, regular_data_block{{}, Parser::ParserBase::dataType(type)});
        result.value = std::move(fields);
    }
    return result;
}
}
