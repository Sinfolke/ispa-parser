#include <IR/LLIR_old.h>
#include <cstdint>
#include <cpuf/printf.h>
void LLIR_old::getVariablesToTable(std::vector<LLIR_old::member>& data, std::vector<LLIR_old::member>& table, std::string& var_name, bool retain_value, bool recursive) {
    for (size_t i = 0; i < data.size(); /* manual increment */) {
        if (data[i].type == LLIR_old::types::VARIABLE) {
            auto variable = std::any_cast<LLIR_old::variable>(data[i].value);
            if (!var_name.empty() && var_name != variable.name) {
                ++i;
                continue;
            }

            // Optionally retain value
            if (variable.value.kind != LLIR_old::var_assign_values::NONE && retain_value) {
                data.insert(data.begin() + i, LLIR_old::member{
                    LLIR_old::types::ASSIGN_VARIABLE,
                    LLIR_old::variable_assign{variable.name, LLIR_old::var_assign_types::ASSIGN, variable.value}
                });
                ++i; // skip over inserted assignment
            }

            // Move variable declaration to table
            table.push_back(data[i]);
            data.erase(data.begin() + i); // do NOT increment i, stay at current index
            if (!var_name.empty())
                break;
        } else if ((data[i].type == LLIR_old::types::IF || data[i].type == LLIR_old::types::WHILE || data[i].type == LLIR_old::types::DOWHILE) && recursive) {
            auto block = std::any_cast<LLIR_old::condition>(data[i].value);
            getVariablesToTable(block.block, table, var_name, retain_value, recursive);
            getVariablesToTable(block.else_block, table, var_name, retain_value, recursive);
            data[i].value = block;
            ++i;
        } else {
            ++i;
        }
    }
}


void LLIR_old::insertVariablesOnTop(std::vector<LLIR_old::member> &insertPlace, std::vector<LLIR_old::member>& table) {
    size_t i = 0;
    // cpuf::printf("Raise vars on top : table size %$\n", table.size());
    for (auto& el : table) {
        insertPlace.insert(insertPlace.begin() + i++, el);
    }
}

void LLIR_old::raiseVarsTop(std::vector<LLIR_old::member> &insertPlace, std::vector<LLIR_old::member> &readPlace, std::string var_name, bool all_rule, bool retain_value, bool recursive) {
    std::vector<LLIR_old::member> table;
    getVariablesToTable(readPlace, table, var_name, retain_value, recursive);
    insertVariablesOnTop(insertPlace, table);
}
void LLIR_old::optimizeIR() {
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