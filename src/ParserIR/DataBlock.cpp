module;
#include <tsl/ordered_map.h>
module ParserIR.API;
import Parser.Base;
import std;
import UAST.PyAST;
namespace ParserIR {
auto dataBlock(const AST::DataBlock& block) -> DataBlock {
    DataBlock result;
    if (block.type) result.value = regular_data_block{{}, Parser::ParserBase::dataType(*block.type)};
    else if (!block.fields.empty()) {
        inclosed_map fields;
        for (const auto& [name, type] : block.fields)
            fields.emplace(name, regular_data_block{{}, Parser::ParserBase::dataType(type)});
        result.value = std::move(fields);
    }
    // Preserve explicit Python initializers through to the code generator.
    if (const auto* regular = std::get_if<AST::RegularDataBlock>(&block.value)) {
        if (const auto* expression = std::get_if<UAST::py::Expr>(regular)) {
            auto value = Parser::ParserBase::convertPython(*expression);
            if (!result.is_regular_data_block())
                result.value = regular_data_block{std::move(value), LangAPI::Type{LangAPI::ValueType::Undef}};
            else result.getRegularDataBlock().first = std::move(value);
        }
    } else if (const auto* keyed = std::get_if<AST::RegularDataBlockWKeys>(&block.value)) {
        if (!result.is_inclosed_map()) result.value = inclosed_map{};
        auto& fields = result.getInclosedMap();
        for (const auto& [name, expression] : keyed->value) {
            auto value = Parser::ParserBase::convertPython(expression);
            auto it = fields.find(name);
            if (it == fields.end()) fields.emplace(name, regular_data_block{std::move(value), LangAPI::Type{LangAPI::ValueType::Undef}});
            else fields.at(name).first = std::move(value);
        }
    }
    return result;
}
}
