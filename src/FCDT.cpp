module fcdt;
import corelib;
import logging;
import dstd;
import std;
auto FCDT::determineFirstCharacter(const AST::RuleMember &mem) -> std::unordered_set<char> {
    if (mem.isGroup()) {
        return determineFirstCharacter(mem.getGroup().values[0]);
    }
    if (mem.isOp()) {
        std::unordered_set<char> chars;
        for (const auto &option :  mem.getOp().options) {
            auto result = determineFirstCharacter(option);
            chars.insert(result.begin(), result.end());
        }
        return chars;
    }
    if (mem.isString()) {
        return {mem.getString().value[0]};
    }
    if (mem.isEscaped()) {
        return {corelib::text::getEscapedFromChar(mem.getEscaped().c)};
    }
    if (mem.isCsequence()) {
        std::unordered_set<char> chars;
        const auto &csequence = mem.getCsequence();
        for (const auto c : csequence.characters) {
            chars.insert(c);
        }
        for (const auto &c : csequence.escaped) {
            chars.insert(corelib::text::getEscapedFromChar(c));
        }
        for (auto [from, to] : csequence.diapasons) {
            for (; from <= to; from++) {
                chars.insert(from);
            }
        }
        return chars;
    }
    if (mem.isAny()) {
        std::unordered_set<char> chars;
        for (char c = 0; c < std::numeric_limits<char>::max(); c++) {
            chars.insert(c);
        }
        return chars;
    }
    throw Error("Unexpected member");

}
void FCDT::build() {
    for (const auto &rule : ast) {
        if (corelib::text::isLower(rule.first.back()))
            continue;
        auto it = rule.second.rule_members.begin();
        while (it != rule.second.rule_members.end()) {
            if (it->isNospace()) {
                it++;
                continue;
            }
            break;
        };
        for (const auto &c : determineFirstCharacter(*it)) {
            table[c].insert(rule.first);
        }
    }
}


auto FCDT::get() -> Table {
    return table;
}
