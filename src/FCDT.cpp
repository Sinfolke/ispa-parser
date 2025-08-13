module fcdt;
import corelib;
import logging;
import Dump;
import cpuf.printf;
import dstd;
import std;

void FCDT::skipNospace(stdu::vector<AST::RuleMember>::const_iterator &it, const stdu::vector<AST::RuleMember>::const_iterator &end) {
    while (it != end) {
        if (it->isNospace()) {
            ++it;
            continue;
        }
        break;
    };
}


auto FCDT::determineFirstCharacter(const AST::RuleMember &mem) -> std::unordered_set<char> {
    if (mem.isGroup()) {
        auto it = mem.getGroup().values.cbegin();
        skipNospace(it, mem.getGroup().values.cend());
        return determineFirstCharacter(*it);
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
        for (char c = 0; c < std::numeric_limits<unsigned char>::max(); c++) {
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
        if (corelib::text::isLower(rule.first.back()) || !ast.getUsePlacesTable().contains(rule.first))
            continue;
        const auto &use_places = ast.getUsePlacesTable();
        bool is_used_in_nonterminal = false;
        for (const auto &use_rule : use_places.at(rule.first)) {
            if (corelib::text::isLower(use_rule.back())) {
                is_used_in_nonterminal = true;
                break;
            }
        }
        if (!is_used_in_nonterminal) {
            continue;
        }
        auto it = rule.second.rule_members.cbegin();
        skipNospace(it, rule.second.rule_members.cend());
        for (const auto &c : determineFirstCharacter(*it)) {
            table[static_cast<unsigned char>(c)].push_back(rule.first);
        }
    }
}
void FCDT::print() {
    if (!dumper.shouldDump("fcdt"))
        return;
    std::ofstream dump_file(dumper.makeDumpPath("fcdt.txt"));
    unsigned char c = std::numeric_limits<unsigned char>::min();
    for (const auto &names : table) {
        dump_file << '\t' << corelib::text::getEscapedAsStr(c++, false) << " - " << names << '\n';
    }
}

auto FCDT::get() -> Table& {
    return table;
}
auto FCDT::get() const -> const Table & {
    return table;
}

