
module LLIR.Builder;
import LLIR.RuleBuilder;
import LLIR.Rule.MemberBuilder;
import LLIR.Builder.DataWrapper;
import corelib;
import cpuf.printf;
LLIR::Builder::Builder(AST::Tree &tree, int tokensOnly) {
    isToken = tokensOnly == 1;
    for (const auto &[name, value] : tree.getTreeMap()) {
        if (tokensOnly != -1) {
            if (corelib::text::isUpper(name.back()) && !tokensOnly)
                continue;
            if (corelib::text::isLower(name.back()) && tokensOnly)
                continue;
        }
        LLIR::RuleBuilder builder(tree, name, value, dfas);
        data.push_back(builder.getData());
    }
}

auto LLIR::Builder::get() -> IR {
    return IR(std::move(data), isToken, std::move(dfas));
}
auto LLIR::Builder::getRawData() -> stdu::vector<Data> & {
    return data;
}
auto LLIR::Builder::getRawData() const -> const stdu::vector<Data> & {
    return data;
}

