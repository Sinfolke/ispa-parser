export module LLIRRuleMemberBuilder;

import LLIRBuilderBase;
import LLIRBuilderData;
import TreeAPI;
import LLIR;
import std;
import std.compat;

export namespace LLIR {
    class MemberBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        MemberBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
        MemberBuilder(BuilderData &data, const std::vector<TreeAPI::RuleMember> &rules);
        MemberBuilder(BuilderData &data, const std::vector<TreeAPI::RuleMember> &rules, bool &addSpaceSkipFirst);
    };

    class GroupBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
        void pushBasedOnQuantifier(
            MemberBuilder &builder,
            const TreeAPI::RuleMember &rule,
            LLIR::variable &shadow_var,
            LLIR::variable &uvar,
            const LLIR::variable &var,
            char quantifier
        );
    public:
        void build() override;
        GroupBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class CsequenceBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        CsequenceBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class StringBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        StringBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class HexBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        HexBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class BinBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        BinBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class NameBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
        auto pushBasedOnQualifier(
            const TreeAPI::RuleMember &rule,
            std::vector<LLIR::expr> &expr,
            std::vector<LLIR::member> &block,
            LLIR::variable &uvar,
            const LLIR::variable &var,
            const LLIR::variable &svar,
            const LLIR::member &call,
            char quantifier,
            bool add_shadow_var = false
        ) -> LLIR::variable;

    public:
        void build() override;
        NameBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class NospaceBuilder : public BuilderBase {
    public:
        void build() override;
        NospaceBuilder(BuilderData &data) : BuilderBase(data) {}
    };

    class EscapedBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        EscapedBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class AnyBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        AnyBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class OpBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
        auto createBlock(
            const std::vector<TreeAPI::RuleMember> &rules,
            size_t index,
            LLIR::variable &var,
            LLIR::variable &svar
        ) -> std::vector<LLIR::member>;
    public:
        void build() override;
        OpBuilder(BuilderData &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };
}
