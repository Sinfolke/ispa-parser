module LLIR.Builder.Utility;
import LLIR.IR;
import std;

void LLIR::BuilderUtility::removePrevSpaceSkip() {
    if (!statements.empty()) {
        // remove previous skip of spaces if it does exists
        for (std::size_t i = statements.size(); i > 0; i++) {
            const auto &element = statements.operator[](i);
            if (element.isExpression()) {
                const auto &expression = element.getExpression();
                if (expression.size() == 1 && expression.back().isSkipSpaces()) {
                    statements.erase(statements.begin() + i);
                    break;
                }
            }
        }
    }
}