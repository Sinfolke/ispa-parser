module LLIR.RuleBuilder;
import LLIR.Rule.MemberBuilder;
import LLIR.CllBuilder;
import LLIR;
import logging;
import cpuf.printf;
import std;

auto LLIR::RuleBuilder::getData() -> LLIR::Production& {
    return data;
}

void LLIR::RuleBuilder::build() {
    BuilderDataWrapper builderData(*this);
    MemberBuilder builder(builderData, rule->rule_members);
    builder.build();
    builder.optimizeIR();
    data.members = builder.getData();
    data.block = createDataBlock(rule->data_block, false);
    data.name = fullname;

}


LLIR::inclosed_map LLIR::RuleBuilder::getInclosedMapFromKeyValueBinding() {
    inclosed_map map;
    for (const auto &[name, variable] : key_vars) {
        map.try_emplace(name, Symbol::createExpression(Symbol {.path = variable.name}));
    }
    return map;
}
LLIR::DataBlock LLIR::RuleBuilder::createDataBlock(const AST::DataBlock &data_block, bool ro) {
    LLIR::DataBlock stmt;
    if (data_block.empty()) {
        return stmt;
    }
    if (data_block.isRegularDataBlock()) {
        if (data_block.isWithKeys()) {
            LLIR::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
            const auto &key_based_data_block = data_block.getRegDataBlockWKeys();
            for (const auto &[name, expr] : key_based_data_block.value) {
                std::flush(std::cout);
                BuilderDataWrapper bd(*this);
                CllExprBuilder expr_builder(bd, expr);
                initial_map.try_emplace(name, expr_builder.get(), expr_builder.deduceType());
            }
            stmt.value = initial_map;
        } else {
            Assert(key_vars.empty(), "Key variable in expression-only data block");
            BuilderDataWrapper bd(*this);
            CllExprBuilder expr_builder(bd, data_block.getRegDataBlock());
            auto type = expr_builder.deduceType();
            if (type.type == ValueType::RuleResult) {
                type.type = ValueType::Rule;
            } else if (type.type == ValueType::TokenResult) {
                type.type = ValueType::Token;
            }
            expr_builder.build();
            stmt.value = std::make_pair(expr_builder.get(), type);
        }
    } else {
        // templated data block
        LLIR::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
        const auto &templated_datablock = data_block.getTemplatedDataBlock();
        for (const auto &name : templated_datablock.names) {
            if (unnamed_datablock_units.empty()) {
                throw Error("More keys than values: {}", name);
            }
            auto type = unnamed_datablock_units.front().type;
            if (type.type == ValueType::RuleResult) {
                type.type = ValueType::Rule;
            } else if (type.type == ValueType::TokenResult) {
                type.type = ValueType::Token;
            }
            initial_map.try_emplace(name, Symbol::createExpression(Symbol {.path = unnamed_datablock_units.front().name}));
            unnamed_datablock_units.erase(unnamed_datablock_units.begin());
        }
        stmt.value = initial_map;
    }
    return stmt;
}