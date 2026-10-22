#include <ispastdlib/parser_ll.hpp>
#include <gtest/gtest.h>

namespace {
struct Leaf {};
struct Other {};
struct Space {};
using Token = ISPA_STD::RawToken<Leaf, Other, Space>;
struct Iter {
    const Token* tokens;
    std::size_t index = 0;
    std::size_t distance() const { return index; }
    bool isEnd() const { return tokens[index].empty(); }
    const Token& operator*() const { return tokens[index]; }
    const Token* operator->() const { return &tokens[index]; }
    Iter& operator++() { ++index; return *this; }
};
struct Parser : ISPA_STD::LLParser<Leaf, Token> {
    using LLParser::optional;
    using LLParser::required;
    using LLParser::range;
    using LLParser::range_optional;
    int failures = 0;
    void parseFromTokens() override {}
    void lazyParse() override {}
    auto leaf(Iter pos) -> ISPA_STD::MatchResult<Leaf, Iter> {
        auto node = required<Leaf>(pos, [this](Iter&) { ++failures; });
        return {true, node, pos};
    }
    auto pair(Iter pos) -> ISPA_STD::MatchResult<Leaf, Iter> {
        leafToken(pos);
        auto node = leafToken(pos);
        return {true, node, pos};
    }
    auto leafToken(Iter& pos) -> ISPA_STD::Node<Leaf> {
        return required<Leaf>(pos, [this](Iter&) { ++failures; });
    }
};

struct RecoveryParser : Parser {
    const Token* input = nullptr;
    void lazyParse() override {
        Iter pos{input};
        required<Leaf>(pos, [](Iter& cursor, ISPA_STD::Recovery::State& state) {
            const ISPA_STD::Recovery::Plan plan{
                .rule = "entry", .expected = {1},
                .allow_insertion = false, .allow_replacement = false
            };
            return ISPA_STD::Recovery::recover(cursor, state, plan, [](const Token& token) {
                return token.holds<Leaf>() ? 1u : 2u;
            });
        });
    }
    void run(const Token* tokens) {
        input = tokens;
        parse("test input");
    }
    auto skipped() const { return recovery_state_.total_skipped; }
    void setErrorBudget(std::size_t limit) { recovery_state_.max_errors = limit; }
    auto errorBudget() const { return recovery_state_.max_errors; }
};

struct AnchorParser : Parser {
    using LLParser::recovery_frame;
    using LLParser::recovery_at;
    using LLParser::recovery_state_;
};
}

TEST(LLRuntime, PanicRetriesExpectedTerminalBeyondOneTokenLookahead) {
    const Token tokens[]{Token{{}, Other{}}, Token{{}, Other{}},
                         Token{{}, Leaf{}}, Token{}};
    Iter pos{tokens};
    Parser parser;
    ISPA_STD::Recovery::State state;
    const auto fail = [&](Iter& cursor, ISPA_STD::Recovery::State&) {
        return ISPA_STD::Recovery::recover(cursor, state, {
            .rule = "entry", .expected = {1},
            .allow_insertion = false, .allow_replacement = false
        }, [](const Token& token) { return token.holds<Leaf>() ? 1u : 2u; });
    };
    EXPECT_FALSE(parser.required<Leaf>(pos, fail).empty());
    EXPECT_EQ(pos.index, 3u);
    ASSERT_EQ(state.diagnostics.size(), 1u);
    EXPECT_EQ(state.diagnostics.front().decision.skipped, 2u);
}

TEST(LLRuntime, NestedRecoveryPreservesEnclosingProductionAnchor) {
    const Token tokens[]{Token{{0, nullptr, nullptr, 0, 0, 0, 2}, Other{}},
                         Token{{0, nullptr, nullptr, 0, 0, 0, 2}, Other{}},
                         Token{{0, nullptr, nullptr, 0, 0, 0, 3}, Space{}}, Token{}};
    Iter pos{tokens};
    AnchorParser parser;
    auto outer = parser.recovery_frame("outer");
    parser.recovery_at<ISPA_STD::Recovery::Tokens<3>>("nested", "later_nested_terminal");
    {
        auto inner = parser.recovery_frame("inner");
        parser.recovery_at<ISPA_STD::Recovery::Tokens<1>>("Leaf", "Leaf");
        auto fail = ISPA_STD::Recovery::handler<ISPA_STD::Recovery::Tokens<1>,
            ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::EmptyTokens,
            ISPA_STD::Recovery::EmptyTokens, ISPA_STD::Recovery::Policy<false, false, false>>(
                "inner", "Leaf");
        EXPECT_TRUE(parser.required<Leaf>(pos, fail).empty());
        EXPECT_EQ(pos.index, 2u);
        ASSERT_EQ(parser.getErrors().size(), 1u);
        EXPECT_NE(parser.getErrors().front().message.find("expected Leaf"), std::string::npos);
    }
    EXPECT_EQ(parser.recovery_state_.anchors.size(), 1u);
}

TEST(LLRuntime, GetErrorsExposesRecoveredDiagnosticsThroughConstParser) {
    const Token tokens[]{Token{{}, Other{}}, Token{{}, Leaf{}}, Token{}};
    RecoveryParser parser;
    EXPECT_TRUE(parser.getErrors().empty());
    parser.run(tokens);
    const auto& errors = std::as_const(parser).getErrors();
    ASSERT_EQ(errors.size(), 1u);
    EXPECT_EQ(errors.front().rule, "entry");
    EXPECT_EQ(errors.front().unexpected, 2u);
    EXPECT_EQ(errors.front().expected, (std::vector<ISPA_STD::Recovery::TokenId>{1}));
    EXPECT_EQ(errors.front().decision.mode, ISPA_STD::Recovery::Mode::Delete);
    EXPECT_EQ(parser.skipped(), 1u);
}

TEST(LLRuntime, ErrorsSurviveExceptionsAndResetBeforeEachParse) {
    const Token bad[]{Token{{}, Other{}}, Token{}};
    const Token good[]{Token{{}, Leaf{}}, Token{}};
    RecoveryParser parser;
    parser.setErrorBudget(7);
    EXPECT_THROW(parser.run(bad), std::logic_error);
    ASSERT_EQ(parser.getErrors().size(), 1u);
    EXPECT_EQ(parser.skipped(), 1u);
    EXPECT_THROW(parser.run(bad), std::logic_error);
    EXPECT_EQ(parser.getErrors().size(), 1u);
    EXPECT_EQ(parser.skipped(), 1u);
    parser.run(good);
    EXPECT_TRUE(parser.getErrors().empty());
    EXPECT_EQ(parser.skipped(), 0u);
    EXPECT_EQ(parser.errorBudget(), 7u);
}

TEST(LLRuntime, AbsentOptionalDescendantDoesNotRecoverOrAdvance) {
    const Token tokens[]{Token{{}, Other{}}, Token{}};
    Iter pos{tokens};
    Parser parser;
    EXPECT_TRUE(parser.optional<Leaf>(pos, [&](Iter cursor) { return parser.leaf(cursor); }).empty());
    EXPECT_EQ(pos.index, 0);
    EXPECT_EQ(parser.failures, 0);
    EXPECT_THROW(parser.required<Leaf>(pos, [&](Iter&) { ++parser.failures; }), std::logic_error);
    EXPECT_EQ(parser.failures, 1);
}

TEST(LLRuntime, CommittedOptionalFailureStillRecoversAndRestoresProbeState) {
    const Token tokens[]{Token{{}, Leaf{}}, Token{{}, Other{}}, Token{}};
    Iter pos{tokens};
    Parser parser;
    EXPECT_THROW(parser.optional<Leaf>(pos, [&](Iter cursor) { return parser.pair(cursor); }), std::logic_error);
    EXPECT_EQ(parser.failures, 1);
    ++pos;
    EXPECT_THROW(parser.required<Leaf>(pos, [&](Iter&) { ++parser.failures; }), std::logic_error);
    EXPECT_EQ(parser.failures, 2);
}

TEST(LLRuntime, NullableRuleDoesNotRepeatWithoutProgress) {
    const Token tokens[]{Token{{}, Other{}}, Token{}};
    Iter pos{tokens};
    Parser parser;
    auto empty = [](Iter cursor) -> ISPA_STD::MatchResult<Leaf, Iter> {
        ISPA_STD::Node<Leaf> node;
        node.set_data(Leaf{});
        return {true, node, cursor};
    };
    EXPECT_EQ(parser.range<Leaf>(pos, empty, [](Iter&) {}).size(), 1);
    EXPECT_TRUE(parser.range_optional<Leaf>(pos, empty).empty());
    EXPECT_EQ(pos.index, 0);
}

TEST(LLRuntime, CommittedUnsuccessfulResultIsNotTreatedAsAbsent) {
    const Token tokens[]{Token{{}, Leaf{}}, Token{{}, Other{}}, Token{}};
    Iter pos{tokens};
    Parser parser;
    auto incomplete = [&](Iter cursor) -> ISPA_STD::MatchResult<Leaf, Iter> {
        parser.leafToken(cursor);
        return {false, {}, cursor};
    };
    EXPECT_THROW(parser.optional<Leaf>(pos, incomplete), std::logic_error);
}

TEST(LLRuntime, RepetitionsSkipSeparatorsOnlyForSuccessfulIterations) {
    const Token tokens[]{Token{{}, Leaf{}}, Token{{}, Space{}}, Token{{}, Leaf{}},
                         Token{{}, Space{}}, Token{{}, Other{}}, Token{}};
    for (const bool required : {false, true}) {
        for (const bool recursive : {false, true}) {
            Iter pos{tokens};
            Parser parser;
            auto rec = [&](Iter cursor) { return parser.leaf(cursor); };
            auto fail = [&](Iter&) { ++parser.failures; };
            const auto nodes = recursive
                ? (required ? parser.range<Leaf, Space>(pos, rec, fail)
                            : parser.range_optional<Leaf, Space>(pos, rec))
                : (required ? parser.range<Leaf, Space>(pos, fail)
                            : parser.range_optional<Leaf, Space>(pos));
            EXPECT_EQ(nodes.size(), 2u);
            EXPECT_EQ(pos.index, 3u); // trailing space still belongs to the parent
            EXPECT_EQ(parser.failures, 0);
        }
    }
}

TEST(LLRuntime, RepetitionPreservesInitialAndExplicitNoSpaceBoundaries) {
    const Token tokens[]{Token{{}, Space{}}, Token{{}, Leaf{}},
                         Token{{}, Space{}}, Token{{}, Leaf{}}, Token{}};
    Iter pos{tokens};
    Parser parser;
    auto initial = parser.range_optional<Leaf, Space>(pos);
    EXPECT_TRUE(initial.empty());
    EXPECT_EQ(pos.index, 0u);
    ++pos;
    auto adjacent = parser.range<Leaf>(pos, [](Iter&) {});
    EXPECT_EQ(adjacent.size(), 1u);
    EXPECT_EQ(pos.index, 2u);
}
