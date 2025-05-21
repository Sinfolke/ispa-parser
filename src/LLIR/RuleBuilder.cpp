module;
#include <cpuf/operator.h>
module LLIRRuleBuilder;
import LLIRRuleMemberBuilder;
import logging;
import std;
import CllBuilder;

auto LLIR::RuleBuilder::getData() -> LLIR::Data {
    return data;
}

void LLIR::RuleBuilder::build() {
    BuilderDataWrapper builderData(*this);
    data.block = createDataBlock(rule->data_block);
    data.members = MemberBuilder(builderData, rule->rule_members).getData();
    data.name = *name;

}


LLIR::inclosed_map LLIR::RuleBuilder::getInclosedMapFromKeyValueBinding() {
    LLIR::inclosed_map map;
    for (const auto &[name, variable] : key_vars) {
        map.try_emplace(name, std::vector<LLIR::expr> {LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = variable}}}, variable.type);
    }
    return map;
}
LLIR::DataBlock LLIR::RuleBuilder::createDataBlock(const TreeAPI::DataBlock &data_block) {
    LLIR::DataBlock block;
    if (data_block.empty()) {
        return block;
    }
    if (data_block.isRegularDataBlock()) {
        if (data_block.isWithKeys()) {
            LLIR::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
            const auto &key_based_data_block = data_block.getRegDataBlockWKeys();
            for (const auto &[name, expr] : key_based_data_block.value) {
                BuilderDataWrapper bd(*this);
                CllExprBuilder expr_builder(bd, expr);
                initial_map.try_emplace(name, expr_builder.get(), expr_builder.deduceType());
            }
            block.value = initial_map;
        } else {
            Assert(key_vars.empty(), "Key variable in expression-only data block");
            BuilderDataWrapper bd(*this);
            CllExprBuilder expr_builder(bd, data_block.getRegDataBlock());
            auto type = expr_builder.deduceType();
            if (type.type == LLIR::var_types::Rule_result) {
                type.type = LLIR::var_types::Rule;
            } else if (type.type == LLIR::var_types::Token_result) {
                type.type = LLIR::var_types::Token;
            }
            block.value = std::make_pair(expr_builder.get(), type);
        }
    } else {
        // templated data block
        LLIR::inclosed_map initial_map = getInclosedMapFromKeyValueBinding();
        const auto &templated_datablock = data_block.getTemplatedDataBlock();
        for (const auto &name : templated_datablock.names) {
            Assert(!unnamed_datablock_units.empty(), "More keys than values");
            auto type = unnamed_datablock_units.front().type;
            if (type.type == LLIR::var_types::Rule_result) {
                type.type = LLIR::var_types::Rule;
            } else if (type.type == LLIR::var_types::Token_result) {
                type.type = LLIR::var_types::Token;
            }
            initial_map.try_emplace(name, std::vector<LLIR::expr> {LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = unnamed_datablock_units.front()}}}, type);
            unnamed_datablock_units.erase(unnamed_datablock_units.begin());
        }
        block.value = initial_map;
    }
    return block;
}