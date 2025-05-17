module;
#include <TreeAPI.cppm>
export module LLIRRuleBuilder;
import LLIRBuilderData;
import LLIRBuilderBase;
export class LLIRRuleBuilder : protected LLIRBuilderData, public LLIRBuilderBase {
    void build();
public:
    LLIRRuleBuilder(const LLIRBuilderData &data, TreeAPI::Rule rule) : LLIRBuilderData(data) {
        build();
    }
};
