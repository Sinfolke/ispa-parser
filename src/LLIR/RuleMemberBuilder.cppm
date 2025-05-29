export module LLIR.Rule.MemberBuilder;

import LLIR.Builder.Base;
import LLIR.Builder.DataWrapper;
import AST.API;
import LLIR;
import dstd;
import std;
import std.compat;

export namespace LLIR {
    class MemberBuilder : public BuilderBase {
        stdu::vector<AST::RuleMember> rules;
        bool *addSpaceSkipFirst = nullptr;
        void buildMember(const AST::RuleMember &member);
    public:
        void build() override;
        MemberBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule, bool has_symbol_follow = true) : BuilderBase(data), rules(stdu::vector<AST::RuleMember> {rule}) {
            *this->has_symbol_follow = has_symbol_follow;
        }
        MemberBuilder(BuilderDataWrapper &data, const stdu::vector<AST::RuleMember> &rules, bool has_symbol_follow = true) : BuilderBase(data), rules(rules) {
            *this->has_symbol_follow = has_symbol_follow;
        }
        MemberBuilder(BuilderDataWrapper &data, const stdu::vector<AST::RuleMember> &rules, bool has_symbol_follow, bool &addSpaceSkipFirst) :
            BuilderBase(data), rules(rules), addSpaceSkipFirst(&addSpaceSkipFirst) {
            *this->has_symbol_follow = has_symbol_follow;
        }

    };

    class GroupBuilder : public BuilderBase {
        const AST::RuleMember *rule;
        void pushBasedOnQuantifier(
            MemberBuilder &builder,
            const AST::RuleMember &rule,
            LLIR::variable &shadow_var,
            LLIR::variable &uvar,
            const LLIR::variable &var,
            char quantifier
        );
    public:
        void build() override;
        GroupBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class CsequenceBuilder : public BuilderBase {
        const AST::RuleMember *rule;
    public:
        void build() override;
        CsequenceBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class StringBuilder : public BuilderBase {
        const AST::RuleMember *rule;
    public:
        void build() override;
        StringBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class HexBuilder : public BuilderBase {
        const AST::RuleMember *rule;
    public:
        void build() override;
        HexBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class BinBuilder : public BuilderBase {
        const AST::RuleMember *rule;
    public:
        void build() override;
        BinBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class NameBuilder : public BuilderBase {
        const AST::RuleMember *rule;
        auto pushBasedOnQualifier(
            const AST::RuleMember &rule,
            stdu::vector<LLIR::expr> &expr,
            stdu::vector<LLIR::member> &block,
            LLIR::variable &uvar,
            const LLIR::variable &var,
            const LLIR::variable &svar,
            const LLIR::member &call,
            char quantifier,
            bool add_shadow_var = false
        ) -> LLIR::variable;

    public:
        void build() override;
        NameBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class NospaceBuilder : public BuilderBase {
    public:
        void build() override;
        NospaceBuilder(BuilderDataWrapper &data) : BuilderBase(data) {}
    };

    class EscapedBuilder : public BuilderBase {
        const AST::RuleMember *rule;
    public:
        void build() override;
        EscapedBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class AnyBuilder : public BuilderBase {
        const AST::RuleMember *rule;
    public:
        void build() override;
        AnyBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class OpBuilder : public BuilderBase {
        const AST::RuleMember *rule;
        auto createBlock(
            const stdu::vector<AST::RuleMember> &rules,
            size_t index,
            LLIR::variable &var,
            LLIR::variable &svar
        ) -> stdu::vector<LLIR::member>;
    public:
        void build() override;
        OpBuilder(BuilderDataWrapper &data, const AST::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };
}
