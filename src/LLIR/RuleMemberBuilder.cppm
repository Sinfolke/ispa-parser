export module LLIR.Rule.MemberBuilder;

import LLIR.Builder.Base;
import LLIR.Builder.DataWrapper;
import AST.API;
import LLIR.API;
import dstd;
import std;

export namespace LLIR {
    class MemberBuilder : public BuilderBase {
        const stdu::vector<AST::RuleMember> *rules = nullptr;
        const AST::RuleMember *rule = nullptr;
        bool addSpaceSkipFirst;
        void buildMember(const AST::RuleMember &member);
    public:
        void build() override;
        MemberBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
        MemberBuilder(BuilderDataWrapper &data, const stdu::vector<AST::RuleMember> &rules) : BuilderBase(data), rules(&rules) {}
        auto getAddSpaceSkipFirst() const -> bool { return addSpaceSkipFirst; }
    };

    class GroupBuilder : public BuilderBase {
        const AST::RuleMember &rule;
        void pushBasedOnQuantifier(
            MemberBuilder &builder,
            const AST::RuleMember &rule,
            Variable &shadow_var,
            Variable &uvar,
            const Variable &var,
            char quantifier
        );
    public:
        void build() override;
        GroupBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    };

    class CsequenceBuilder : public BuilderBase {
        const AST::RuleMember &rule;
    public:
        void build() override;
        CsequenceBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    };

    class StringBuilder : public BuilderBase {
        const AST::RuleMember &rule;
    public:
        void build() override;
        StringBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    };

    // class HexBuilder : public BuilderBase {
    //     const AST::RuleMember &rule;
    // public:
    //     void build() override;
    //     HexBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    // };
    //
    // class BinBuilder : public BuilderBase {
    //     const AST::RuleMember &rule;
    // public:
    //     void build() override;
    //     BinBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    // };

    class NameBuilder : public BuilderBase {
        const AST::RuleMember &rule;
        auto pushBasedOnQualifier(
            const AST::RuleMember &rule,
            Expression &expr,
            Statements &stmt,
            Variable &uvar,
            const Variable &var,
            const Variable &svar,
            const Statement &call,
            char quantifier,
            bool add_shadow_var = false
        ) -> Variable;

    public:
        void build() override;
        NameBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    };

    class NospaceBuilder : public BuilderBase {
    public:
        void build() override;
        NospaceBuilder(BuilderDataWrapper &data) : BuilderBase(data) {}
    };

    // class EscapedBuilder : public BuilderBase {
    //     const AST::RuleMember &rule;
    // public:
    //     void build() override;
    //     EscapedBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    // };

    class AnyBuilder : public BuilderBase {
        const AST::RuleMember &rule;
    public:
        void build() override;
        AnyBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    };

    class OpBuilder : public BuilderBase {
        const AST::RuleMember &rule;
        auto createBlock(
            const stdu::vector<AST::RuleMember> &rules,
            std::size_t index,
            Variable &var,
            Variable &svar
        ) -> Statements;
    public:
        void build() override;
        OpBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(rule) {}
    };
}
