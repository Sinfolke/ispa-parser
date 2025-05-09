#include <IR/IR.h>
#include <cstdint>
#include <cpuf/printf.h>
void LLIR::getVariablesToTable(std::vector<LLIR::member> &data, std::vector<LLIR::member>& table, std::string var_name, bool retain_value, bool recursive) {
    for (size_t i = 0; i < data.size(); i++) {
        auto el = data[i];
        if (el.type == LLIR::types::VARIABLE) {
            auto variable = std::any_cast<LLIR::variable>(el.value);
            if (!var_name.empty() && var_name != variable.name)
                continue;
            table.push_back(el);

            if (variable.value.kind != LLIR::var_assign_values::NONE && retain_value) {
                // insert before block_begin, and adjust i to account for shift
                data.insert(data.begin(), LLIR::member {
                    LLIR::types::ASSIGN_VARIABLE,
                    LLIR::variable_assign {variable.name, LLIR::var_assign_types::ASSIGN, variable.value}
                });

                if (i >= 0) i++; // shift forward due to insert
            }

            // erase current element
            data.erase(data.begin() + i);
            if (var_name.empty())
                break;
            --i; // step back to stay at correct index after erase
        } else if ((el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) && recursive) {
            auto block = std::any_cast<LLIR::condition>(el.value);
            getVariablesToTable(block.block, table, var_name, retain_value, recursive);
            getVariablesToTable(block.else_block, table, var_name, retain_value, recursive);
            data[i].value = block;
        }
    }
}

void LLIR::insertVariablesOnTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member>& table) {
    size_t i = 0;
    for (auto& el : table) {
        insertPlace.insert(insertPlace.begin() + i++, el);
    }
}

void LLIR::raiseVarsTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member> &readPlace, std::string var_name, bool all_rule, bool retain_value, bool recursive) {
    std::vector<LLIR::member> table;
    getVariablesToTable(readPlace, table, var_name, retain_value, recursive);
    insertVariablesOnTop(insertPlace, table);
}
void LLIR::optimizeIR() {
    if (data.empty()) {
        raiseVarsTop(members, members);
    } else {
        for (auto &d : data) {
            raiseVarsTop(d.members, d.members);
        }
    }
}