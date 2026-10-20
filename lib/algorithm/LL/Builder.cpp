module LLIR.Builder;
import LLIR.RuleBuilder;
import LLIR.Rule.MemberBuilder;
import LLIR.Builder.DataWrapper;
import LLIR.Builder.Base;
import corelib;
import cpuf.printf;
import std;

namespace {
    // Collects rule names in sorted order rather than raw
    // tree.getTreeMap() iteration order. getTreeMap() is an
    // unordered_map, and some standard libraries (libc++ among them)
    // seed std::hash<std::string> per process for DoS resistance —
    // meaning iteration order over an identical rule set can differ
    // between separate runs of this program even with zero grammar
    // changes. Left unsorted, that would reorder Production entries
    // in `data`, reorder class members in the generated Parser.h, and
    // change its bytes with nothing actually having changed —
    // defeating the content-hash rebuild-skip downstream in main.cpp.
    auto sortedRuleNames(AST::Tree &tree, bool skip_upper)
        -> stdu::vector<stdu::vector<std::string>>
    {
        stdu::vector<stdu::vector<std::string>> keys;
        for (const auto &[name, value] : tree.getTreeMap()) {
            if (skip_upper && corelib::text::isUpper(name.back()))
                continue;
            keys.push_back(name);
        }
        std::sort(keys.begin(), keys.end());
        return keys;
    }
}

LLIR::Builder::Builder(AST::Tree &tree, int tokensOnly) {
    for (const auto &name : sortedRuleNames(tree, false)) {
        const auto &value = tree.getTreeMap().at(name);
        LLIR::RuleBuilder builder(tree, name, value, &dfas);
        builder.build();
        data.push_back(builder.getData());
    }
}

LLIR::Builder::Builder(
    AST::Tree &tree,
    AST::TreeMap &rules_to_build,
    const std::unordered_map<std::string, Production> &cache
) {
    for (const auto &name : sortedRuleNames(tree, true)) {
        const auto &value = tree.getTreeMap().at(name);
        const std::string key = corelib::text::join(name, ".");

        if (rules_to_build.contains(name)) {
            // Changed rule -> full rebuild
            LLIR::RuleBuilder builder(tree, name, value, &dfas, true);
            builder.build();
            data.push_back(builder.getData());
        } else if (const auto it = cache.find(key); it != cache.end()) {
            // Unchanged rule -> reuse exact cached Production as-is!
            data.push_back(it->second);
        } else {
            // Cache miss (new rule) -> full rebuild
            LLIR::RuleBuilder builder(tree, name, value, &dfas, true);
            builder.build();
            data.push_back(builder.getData());
        }
    }
}

auto LLIR::Builder::get() -> IR {
    return IR(std::move(data), false, std::move(dfas));
}
auto LLIR::Builder::getRawData() -> stdu::vector<Production> & {
    return data;
}
auto LLIR::Builder::getRawData() const -> const stdu::vector<Production> & {
    return data;
}