module;
#include <vector>
export module LLIRRuleMemberBuilder;

import LLIRBuilderBase;
import LLIRBuilderData;
import TreeAPI;
import LLIR;
export namespace LLIR {
    class MemberBuilder : public BuilderBase {
        void build() override;
    public:
        MemberBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
        MemberBuilder(BuilderData &data, const std::vector<TreeAPI::RuleMember> &rules);
        MemberBuilder(BuilderData &data, const std::vector<TreeAPI::RuleMember> &rules, bool &addSpaceSkipFirst);
    };

    class GroupBuilder : public BuilderBase {
        void build() override;
        const TreeAPI::RuleMember *rule;
        void pushBasedOnQuantifier(
            MemberBuilder &builder,
            const TreeAPI::RuleMember &rule,
            LLIR::variable &shadow_var,
            LLIR::variable &uvar, const
            LLIR::variable &var,
            char quantifier
            );
    public:
        GroupBuilder(BuilderData &data, const TreeAPI::RuleMember &rule);
    };
    class CsequenceBuilder : public BuilderBase {
        void build() override;
    public:
        CsequenceBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class StringBuilder : public BuilderBase {
        void build() override;
    public:
        StringBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class HexBuilder : public BuilderBase {
        void build() override;
    public:
        HexBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class BinBuilder : public BuilderBase {
        void build() override;
    public:
        BinBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class NameBuilder : public BuilderBase {
        void build() override;
    public:
        NameBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class NospaceBuilder : public BuilderBase {
        void build() override;
    public:
        NospaceBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class EscapedBuilder : public BuilderBase {
        void build() override;
    public:
        EscapedBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class AnyBuilder : public BuilderBase {
        void build() override;
    public:
        AnyBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
    class OpBuilder : public BuilderBase {
        void build() override;
        auto createBlock(const std::vector<TreeAPI::RuleMember> &rules, size_t index, LLIR::variable &var, LLIR::variable &svar) -> std::vector<LLIR::member>;
    public:
        OpBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data, rule) {}
    };
}