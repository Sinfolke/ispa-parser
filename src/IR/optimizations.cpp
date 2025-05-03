#include <IR/IR.h>
#include <cstdint>
#include <cpuf/printf.h>
void LLIR::getVariablesToTable(std::vector<LLIR::member> &data, size_t &i, std::vector<LLIR::member>& table, std::string var_name, bool retain_value, bool recursive) {
    auto block_begin = i;
    for (; i < data.size(); i++) {
        auto el = data[i];
        if (el.type == LLIR::types::RULE_END) {
            i++;
            return;
        }
        if (el.type == LLIR::types::VARIABLE) {
            auto variable = std::any_cast<LLIR::variable>(el.value);
            if (!var_name.empty() && var_name != variable.name)
                continue;
            table.push_back(el);

            if (variable.value.kind != LLIR::var_assign_values::NONE && retain_value) {
                // insert before block_begin, and adjust i to account for shift
                data.insert(data.begin() + block_begin, LLIR::member {
                    LLIR::types::ASSIGN_VARIABLE,
                    LLIR::variable_assign {variable.name, LLIR::var_assign_types::ASSIGN, variable.value}
                });

                if (i >= block_begin) i++; // shift forward due to insert
            }

            // erase current element
            data.erase(data.begin() + i);
            if (var_name != "")
                break;
            --i; // step back to stay at correct index after erase
        } else if ((el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) && recursive) {
            auto block = std::any_cast<LLIR::condition>(el.value);
            size_t block_begin = 0;
            size_t else_block_begin = 0;
            getVariablesToTable(block.block, block_begin, table, var_name, retain_value, recursive);
            getVariablesToTable(block.else_block, else_block_begin, table, var_name, retain_value, recursive);
            data[i].value = block;
        }
    }
}

size_t LLIR::getBegin(size_t& i) {
    for (;i < data.size(); i++) {
        if (data[i].type == LLIR::types::RULE || data[i].type == LLIR::types::TOKEN) {
            return ++i;
        }
    }
    return UINT64_MAX;
}

void LLIR::insertVariablesOnTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member>& table, size_t begin) {
    for (auto& el : table) {
        insertPlace.insert(insertPlace.begin() + begin++, el);
    }
}

void LLIR::raiseVarsTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member> &readPlace, std::string var_name, bool all_rule, bool retain_value, bool recursive) {
    std::vector<LLIR::member> table;
    if (all_rule) {
        size_t i = 0;
        getVariablesToTable(readPlace, i, table, var_name, retain_value, recursive);
        insertVariablesOnTop(insertPlace, table, 0);
    }
    for (size_t i = 0; i < readPlace.size(); i++) {
        auto begin = getBegin(i);
        if (begin == UINT64_MAX) break;
        getVariablesToTable(readPlace, i, table, var_name, retain_value, recursive);
        insertVariablesOnTop(insertPlace, table, begin);
        table.clear();
    }
}