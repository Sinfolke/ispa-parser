module fcdt;
import corelib;
import logging;
import cpuf.printf;
import dstd;
import std;
void FCDT::skipNospace(stdu::vector<AST::RuleMember>::iterator &it, const stdu::vector<AST::RuleMember>::iterator &end) {
    while (it != end) {
        if (it->isNospace()) {
            it++;
            continue;
        }
        break;
    };
}


auto FCDT::determineFirstCharacter(const AST::RuleMember &mem) -> std::unordered_set<char> {
    if (mem.isGroup()) {
        auto it = mem.getGroup().values.begin();
        skipNospace(it, mem.getGroup().values.end());
        return determineFirstCharacter(*it);
    }
    if (mem.isOp()) {
        std::unordered_set<char> chars;
        for (const auto &option :  mem.getOp().options) {
            auto it = mem.getOp().options.begin();
            skipNospace(it, mem.getOp().options.end());
            auto result = determineFirstCharacter(*it);
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
    if (mem.isName()) {
        return determineFirstCharacter(ast[mem.getName().name].rule_members[0]);
    }
    throw Error("Unexpected member");

}
void FCDT::build() {
    for (const auto &rule : ast) {
        if (corelib::text::isLower(rule.first.back()))
            continue;
        auto it = rule.second.rule_members.begin();
        skipNospace(it, rule.second.rule_members.end());
        for (const auto &c : determineFirstCharacter(*it)) {
            table[c].insert(rule.first);
        }
    }
    cpuf::printf("fcdt table size: {}", table.size());
}


auto FCDT::get() -> Table& {
    return table;
}
auto FCDT::get() const -> const Table & {
    return table;
}

