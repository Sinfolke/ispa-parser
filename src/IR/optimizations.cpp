#include <IR/IR.h>
#include <cstdint>
#include <cpuf/printf.h>
void LLIR::getVariablesToTable(std::vector<LLIR::member> &data, size_t &i, std::list<LLIR::member>& table) {
    for (; i < data.size(); i++) {
        auto el = data[i];
        if (el.type == LLIR::types::RULE_END) {
            i++;
            return;
        }
        if (el.type == LLIR::types::VARIABLE) {
            table.push_back(el);
            data.erase(data.begin() + i);
            i--;
        } else if (el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) {
            auto block = std::any_cast<LLIR::condition>(el.value);
            size_t block_begin = 0;
            size_t else_block_begin = 0;
            getVariablesToTable(block.block, block_begin, table);
            getVariablesToTable(block.else_block, else_block_begin, table);
            data[i].value = block;
        }
    }
}

size_t LLIR::getBegin(size_t& i) {
    for (;i < data.size(); i++) {
        if (data[i].type == LLIR::types::RULE || data[i].type == LLIR::types::TOKEN) {
            return i + 1;
        }
    }
    return UINT64_MAX;
}

void LLIR::insertVariablesOnTop(std::list<LLIR::member>& table, size_t begin) {
    for (auto& el : table) {
        data.insert(data.begin() + begin++, el);
    }
}

void LLIR::raiseVarsTop() {
    std::list<LLIR::member> table;

    for (size_t i = 0; i < data.size(); i++) {
        auto begin = getBegin(i);
        if (begin == UINT64_MAX) break;
        getVariablesToTable(data, i, table);
        insertVariablesOnTop(table, begin);
        table.clear();
    }
}