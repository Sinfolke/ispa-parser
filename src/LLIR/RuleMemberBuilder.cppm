export module LLIRRuleMemberBuilder;

import LLIRBuilderBase;
import LLIRBuilderDataWrapper;
import TreeAPI;
import LLIR;
import types;
import std;
import std.compat;

export namespace LLIR {
    class MemberBuilder : public BuilderBase {
        vector<TreeAPI::RuleMember> rules;
        bool *addSpaceSkipFirst = nullptr;
        void buildMember(const TreeAPI::RuleMember &member);
    public:
        void build() override;
        MemberBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule, bool has_symbol_follow = true) : BuilderBase(data), rules(vector<TreeAPI::RuleMember> {rule}) {
            *this->has_symbol_follow = has_symbol_follow;
        }
        MemberBuilder(BuilderDataWrapper &data, const vector<TreeAPI::RuleMember> &rules, bool has_symbol_follow = true) : BuilderBase(data), rules(rules) {
            *this->has_symbol_follow = has_symbol_follow;
        }
        MemberBuilder(BuilderDataWrapper &data, const vector<TreeAPI::RuleMember> &rules, bool has_symbol_follow, bool &addSpaceSkipFirst) :
            BuilderBase(data), rules(rules), addSpaceSkipFirst(&addSpaceSkipFirst) {
            *this->has_symbol_follow = has_symbol_follow;
        }

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
        GroupBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class CsequenceBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        CsequenceBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class StringBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        StringBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class HexBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        HexBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class BinBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        BinBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class NameBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
        auto pushBasedOnQualifier(
            const TreeAPI::RuleMember &rule,
            vector<LLIR::expr> &expr,
            vector<LLIR::member> &block,
            LLIR::variable &uvar,
            const LLIR::variable &var,
            const LLIR::variable &svar,
            const LLIR::member &call,
            char quantifier,
            bool add_shadow_var = false
        ) -> LLIR::variable;

    public:
        void build() override;
        NameBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class NospaceBuilder : public BuilderBase {
    public:
        void build() override;
        NospaceBuilder(BuilderDataWrapper &data) : BuilderBase(data) {}
    };

    class EscapedBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        EscapedBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class AnyBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
    public:
        void build() override;
        AnyBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };

    class OpBuilder : public BuilderBase {
        const TreeAPI::RuleMember *rule;
        auto createBlock(
            const vector<TreeAPI::RuleMember> &rules,
            size_t index,
            LLIR::variable &var,
            LLIR::variable &svar
        ) -> vector<LLIR::member>;
    public:
        void build() override;
        OpBuilder(BuilderDataWrapper &data, const TreeAPI::RuleMember &rule) : BuilderBase(data), rule(&rule) {}
    };
}
