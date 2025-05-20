
module LLIRBuilder;
import LLIRRuleBuilder;
import corelib;
LLIR::Builder::Builder(AST &tree, int tokensOnly) {
    for (const auto &[name, value] : tree.getTreeMap()) {
        if (tokensOnly != -1) {
            if (corelib::text::isUpper(name.back()) && !tokensOnly)
                continue;
            if (corelib::text::isLower(name.back()) && tokensOnly)
                continue;
        }
        LLIR::RuleBuilder builder(name, value);
        data.push_back(builder.getData());
    }
}