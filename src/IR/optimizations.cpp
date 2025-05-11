#include <IR/IR.h>
#include <cstdint>
#include <cpuf/printf.h>
void LLIR::getVariablesToTable(std::vector<LLIR::member>& data, std::vector<LLIR::member>& table, std::string& var_name, bool retain_value, bool recursive) {
    for (size_t i = 0; i < data.size(); /* manual increment */) {
        if (data[i].type == LLIR::types::VARIABLE) {
            auto variable = std::any_cast<LLIR::variable>(data[i].value);
            if (!var_name.empty() && var_name != variable.name) {
                ++i;
                continue;
            }

            // Optionally retain value
            if (variable.value.kind != LLIR::var_assign_values::NONE && retain_value) {
                data.insert(data.begin() + i, LLIR::member{
                    LLIR::types::ASSIGN_VARIABLE,
                    LLIR::variable_assign{variable.name, LLIR::var_assign_types::ASSIGN, variable.value}
                });
                ++i; // skip over inserted assignment
            }

            // Move variable declaration to table
            table.push_back(data[i]);
            data.erase(data.begin() + i); // do NOT increment i, stay at current index
            if (!var_name.empty())
                break;
        } else if ((data[i].type == LLIR::types::IF || data[i].type == LLIR::types::WHILE || data[i].type == LLIR::types::DOWHILE) && recursive) {
            auto block = std::any_cast<LLIR::condition>(data[i].value);
            getVariablesToTable(block.block, table, var_name, retain_value, recursive);
            getVariablesToTable(block.else_block, table, var_name, retain_value, recursive);
            data[i].value = block;
            ++i;
        } else {
            ++i;
        }
    }
}


void LLIR::insertVariablesOnTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member>& table) {
    size_t i = 0;
    // cpuf::printf("Raise vars on top : table size %$\n", table.size());
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
    // cpuf::printf("Optimze IR\n");
    if (data.empty()) {
        raiseVarsTop(members, members);
    } else {
        // cpuf::printf("Optimze IR on non-empty data\n");
        for (auto &d : data) {
            raiseVarsTop(d.members, d.members);
        }
    }
}