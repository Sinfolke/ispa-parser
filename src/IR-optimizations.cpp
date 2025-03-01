#include <IR.h>
#include <cpuf/printf.h>
void getVariablesToTable(std::vector<IR::member>& elements, size_t &i, std::list<IR::member>& table) {
    for (; i < elements.size(); i++) {
        auto el = elements[i];
        if (el.type == IR::types::RULE_END) {
            i++;
            return;
        }
        if (el.type == IR::types::VARIABLE) {
            table.push_back(el);
            elements.erase(elements.begin() + i);
            i--;
        } else if (el.type == IR::types::IF || el.type == IR::types::WHILE || el.type == IR::types::DOWHILE) {
            auto block = std::any_cast<IR::condition>(el.value);
            size_t block_begin = 0;
            size_t else_block_begin = 0;
            getVariablesToTable(block.block, block_begin, table);
            getVariablesToTable(block.else_block, else_block_begin, table);
            elements[i].value = block;
        }
    }
}

size_t getBegin(arr_t<IR::member>& elements, size_t& i) {
    for (;i < elements.size(); i++) {
        if (elements[i].type == IR::types::RULE) {
            return i + 1;
        }
    }
    return std::string::npos;
}

void insertVariablesOnTop(arr_t<IR::member>& elements, std::list<IR::member>& table, size_t i) {
    for (auto& el : table) {
        cpuf::printf("inserting %s\n", std::any_cast<IR::variable>(el.value).name);
        elements.insert(elements.begin() + i++, el);
    }
}

void raiseVarsTop(IR::ir &ir) {
    std::list<IR::member> table;

    for (size_t i = 0; i < ir.elements.size(); i++) {
        auto begin = getBegin(ir.elements, i);
        if (begin == std::string::npos) break;
        getVariablesToTable(ir.elements, i, table);
        insertVariablesOnTop(ir.elements, table, begin);
        table.clear();
    }
}
