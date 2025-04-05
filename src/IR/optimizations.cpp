#include <IR/IR.h>
#include <cstdint>
#include <cpuf/printf.h>
void IR::getVariablesToTable(std::vector<IR::member> &data, size_t &i, std::list<IR::member>& table) {
    for (; i < data.size(); i++) {
        auto el = data[i];
        if (el.type == IR::types::RULE_END) {
            i++;
            return;
        }
        if (el.type == IR::types::VARIABLE) {
            table.push_back(el);
            data.erase(data.begin() + i);
            i--;
        } else if (el.type == IR::types::IF || el.type == IR::types::WHILE || el.type == IR::types::DOWHILE) {
            auto block = std::any_cast<IR::condition>(el.value);
            size_t block_begin = 0;
            size_t else_block_begin = 0;
            getVariablesToTable(block.block, block_begin, table);
            getVariablesToTable(block.else_block, else_block_begin, table);
            data[i].value = block;
        }
    }
}

size_t IR::getBegin(size_t& i) {
    for (;i < data.size(); i++) {
        if (data[i].type == IR::types::RULE || data[i].type == IR::types::TOKEN) {
            return i + 1;
        }
    }
    return UINT64_MAX;
}

void IR::insertVariablesOnTop(std::list<IR::member>& table, size_t begin) {
    for (auto& el : table) {
        data.insert(data.begin() + begin++, el);
    }
}

void IR::raiseVarsTop() {
    std::list<IR::member> table;

    for (size_t i = 0; i < data.size(); i++) {
        auto begin = getBegin(i);
        if (begin == UINT64_MAX) break;
        getVariablesToTable(data, i, table);
        insertVariablesOnTop(table, begin);
        table.clear();
    }
}