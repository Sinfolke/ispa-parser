
module LLIRBuilder;
import LLIRRuleBuilder;
import LLIRRuleMemberBuilder;
import LLIRBuilderDataWrapper;
import corelib;
LLIR::Builder::Builder(AST &tree, int tokensOnly) {
    for (const auto &[name, value] : tree.getTreeMap()) {
        if (tokensOnly != -1) {
            if (corelib::text::isUpper(name.back()) && !tokensOnly)
                continue;
            if (corelib::text::isLower(name.back()) && tokensOnly)
                continue;
        }
        LLIR::RuleBuilder builder(tree, name, value);
        data.push_back(builder.getData());
    }
}
auto LLIR::Builder::get() -> IR {
    return IR(data);
}
auto LLIR::Builder::getRawData() -> std::vector<Data> & {
    return data;
}
auto LLIR::Builder::getRawData() const -> const std::vector<Data> & {
    return data;
}

