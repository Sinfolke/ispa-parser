#include <gtest/gtest.h>
#include <ispa/parser.h>
import Algorithm.API;
import Algorithm.Cache;
import AST.Builder;
import AST.Pass;
import AST.Tree;
import AST.types;
import LangAPI;
import LangRepr.Converter;
import LexerBuilder;
import ParserIR.IR;
import ParserIR.API;
import Dump;
import args;
import cpuf.dlib;
import std;

namespace {
auto pluginGrammar(const char* source) -> AST::Tree {
    IspaParser parser;
    AST::Builder builder(parser.parse(source), "plugin.isc");
    builder.build();
    auto tree = builder.get();
    AST::TreePass pass(tree);
    pass.work();
    return tree;
}
auto convert(const Algorithm::Descriptor& algorithm, AST::Tree& tree,
             Algorithm::Metadata& metadata,
             const std::filesystem::path& output = {}) -> std::string {
    static Args settings{};
    dumper.setArgsPointer(&settings);
    AST::TreeMap changed;
    auto result = algorithm.build({tree, changed}, metadata);
    if (!result.output || !result.to_lang_repr) throw std::runtime_error("Missing conversion");
    LexerBuilder lexer(tree);
    lexer.build();
    const std::string name = "PluginTest";
    Algorithm::ConversionRequest request{lexer, tree, LangAPI::Language::Cpp, name};
    auto holder = result.to_lang_repr(result.output.get(), request);
    LangRepr::Converter converter(holder, "cpp", name, false);
    converter.init();
    converter.construct();
    std::string text;
    for (const auto& [file, content] : converter.get()) {
        text += file + '\n' + content;
        if (!output.empty()) {
            const auto path = output / file;
            std::filesystem::create_directories(path.parent_path());
            std::ofstream(path) << content;
        }
    }
    return text;
}
}

TEST(AlgorithmPlugin, LLRepeatedRulesAndTokensAcceptWhitespaceSeparators) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto tree = pluginGrammar(
        "A:'a'; B:'b'; main: @ item+ B @ A* '!' @{rules, tokens}; item: @ A {@};");
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-repeat-spaces-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup {
        std::filesystem::path path;
        ~Cleanup() { std::filesystem::remove_all(path); }
    } cleanup{directory};
    Algorithm::Metadata metadata;
    convert(*descriptor, tree, metadata, directory);
    std::ofstream(directory / "run.cpp") << R"(
#include "PluginTest.h"
int main() {
    PluginTest::Parser parser;
    const auto& multiple = parser.parse("a a\nb a\na !");
    if (multiple.rules.size() != 2 || multiple.tokens.size() != 2) return 1;
    const auto& single = parser.parse("a b !");
    if (single.rules.size() != 1 || !single.tokens.empty()) return 2;
}
)";
    const auto command = std::string("clang++ -std=c++23 -I\"") +
        std::string(ROOT_DIR) + "/parser/stdlibs\" -I\"" + directory.string() +
        "\" \"" + (directory / "PluginTest.cpp").string() + "\" \"" +
        (directory / "run.cpp").string() + "\" \"" + std::string(ROOT_DIR) +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (directory / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (directory / "run").string() + '"').c_str()), 0);
}

TEST(AlgorithmPlugin, LLAdvancedContextsExecuteAndReturnTheirAst) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto tree = pluginGrammar(R"(
A: 'a'; B: 'b'; X: 'x';
main: @ item {@};
item {
    ctx.ast.total = 1
    match A -> first;
    ctx.ast.first = first
    saved = ctx.pos
    ctx.pos = ctx.start_pos
    ctx.ast.total += 2
    match A;
    ctx.pos = saved
    match %oops>(first) B;
    ctx.ast.total += 4
    return ctx.ast
    ctx.ast.total = 999
}
fail oops>(previous) {
    ctx.ast.failed = ctx.failed_rule
    ctx.ast.owner = ctx.rule
    ctx.ast.recovered = True
    ctx.ast.had_previous = not previous.empty()
    ctx.pos += 1
}
regular: @ A suffix @{token} %{missing};
suffix: B;
fail missing {
    ctx.ast.saw_token = not ctx.ast.token.empty()
    ctx.ast.expected = ctx.failed_rule
}
starts: @ start_failure {@};
optional_rule: @ start_failure? {@};
start_failure {
    match %at_start A;
    ctx.ast.finished = True
}
fail at_start {
    ctx.ast.recovered = True
    ctx.pos += 1
}
)");
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-action-context-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup { std::filesystem::path path; ~Cleanup() { std::filesystem::remove_all(path); } } cleanup{directory};
    Algorithm::Metadata metadata;
    const auto generated = convert(*descriptor, tree, metadata, directory);
    EXPECT_NE(generated.find("fail_context("), std::string::npos);
    std::ofstream(directory / "run.cpp") << R"(
#include "PluginTest.h"
struct Harness : PluginTest::Parser {
    auto parseRegular(const char* text) {
        PluginTest::Lexer lexer;
        return regular(PluginTest::Lexer::lazy_iterator(lexer, text));
    }
    auto parseStarts(const char* text) {
        PluginTest::Lexer lexer;
        return starts(PluginTest::Lexer::lazy_iterator(lexer, text));
    }
    auto parseOptional(const char* text) {
        PluginTest::Lexer lexer;
        return optional_rule(PluginTest::Lexer::lazy_iterator(lexer, text));
    }
};
int main() {
    PluginTest::Parser parser;
    const auto& good = parser.parse("ab").value.data();
    if (good.total != 7 || good.first.empty() || !good.failed.empty()) return 1;
    const auto& repaired = parser.parse("axb").value.data();
    if (repaired.total != 7 || !repaired.recovered || !repaired.had_previous || repaired.failed != "B" || repaired.owner != "item") return 2;
    const auto& again = parser.parse("ab").value.data();
    if (again.total != 7 || !again.failed.empty()) return 3;
    PluginTest::Lexer lexer;
    lexer.setInput("axb");
    lexer.makeTokens();
    if (parser.parse(lexer).value.data().total != 7) return 4;
    Harness harness;
    const auto partial = harness.parseRegular("a");
    if (!partial.status || !partial.node.data().saw_token || partial.node.data().expected != "suffix") return 5;
    const auto initial = harness.parseStarts("xa");
    if (!initial.status || !initial.node.data().value.data().recovered || !initial.node.data().value.data().finished) return 6;
    const auto absent = harness.parseOptional("b");
    if (!absent.status || !absent.node.data().value.empty()) return 7;
}
)";
    const auto command = std::string("clang++ -std=c++23 -I\"") + ROOT_DIR +
        "/parser/stdlibs\" -I\"" + directory.string() + "\" \"" + (directory / "PluginTest.cpp").string() +
        "\" \"" + (directory / "run.cpp").string() + "\" \"" + ROOT_DIR +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (directory / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (directory / "run").string() + '"').c_str()), 0);
}

TEST(AlgorithmPlugin, CapturedLiteralChoiceRetainsRuleAndTokenPayloads) {
    for (const std::string name : {"LL", "LR", "LALR"}) {
        SCOPED_TRACE(name);
        dlib library("libispa-algorithm-" + name);
        const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
        auto tree = pluginGrammar("main: @ unpack | ';' {@}; unpack: 'x'; other: ';';");
        const auto directory = std::filesystem::temp_directory_path() /
            ("ispa-literal-choice-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
        struct Cleanup {
            std::filesystem::path path;
            ~Cleanup() { std::filesystem::remove_all(path); }
        } cleanup{directory};
        Algorithm::Metadata metadata;
        convert(*descriptor, tree, metadata, directory);
        std::ofstream(directory / "run.cpp") << R"(
#include "PluginTest.h"
int main() {
    PluginTest::Parser parser;
    using Unpack = ISPA_STD::Node<PluginTest::Types::unpack>;
    using Semicolon = ISPA_STD::Node<PluginTest::Types::SEMICOLON>;
    if (!std::holds_alternative<Unpack>(parser.parse("x").value)) return 1;
    const auto& result = parser.parse(";").value;
    if (!std::holds_alternative<Semicolon>(result)) return 2;
    if (std::get<Semicolon>(result).empty()) return 3;
}
)";
        const auto command = std::string("clang++ -std=c++23 -I\"") +
            std::string(ROOT_DIR) + "/parser/stdlibs\" -I\"" + directory.string() +
            "\" \"" + (directory / "PluginTest.cpp").string() + "\" \"" +
            (directory / "run.cpp").string() + "\" \"" + std::string(ROOT_DIR) +
            "/parser/stdlibs/src/core.cpp\" -o \"" + (directory / "run").string() + "\"";
        ASSERT_EQ(std::system(command.c_str()), 0);
        EXPECT_EQ(std::system(('"' + (directory / "run").string() + '"').c_str()), 0);
    }
}

TEST(AlgorithmPlugin, EverySupportedAlgorithmSuppliesItsOwnConversion) {
    for (const std::string name : {"LL", "LR", "LALR"}) {
        SCOPED_TRACE(name);
        dlib library("libispa-algorithm-" + name);
        const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
        ASSERT_NE(descriptor, nullptr);
        EXPECT_EQ(descriptor->version, Algorithm::interface_version);
        EXPECT_EQ(descriptor->id, name);
        auto tree = pluginGrammar("A:'a'; main: A;");
        Algorithm::Metadata metadata;
        EXPECT_FALSE(convert(*descriptor, tree, metadata).empty());
    }
}

TEST(AlgorithmPlugin, LLRestoresCacheAndRebuildsChangedOrCorruptInput) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto first = pluginGrammar("A:'a'; B:'b'; main: A;");
    Algorithm::Metadata metadata;
    const auto cold = convert(*descriptor, first, metadata);
    ASSERT_FALSE(metadata.cache.empty());
    EXPECT_EQ(convert(*descriptor, first, metadata), cold);
    auto changed = pluginGrammar("A:'a'; B:'b'; main: B;");
    const auto rebuilt = convert(*descriptor, changed, metadata);
    EXPECT_NE(rebuilt, cold);
    metadata.cache.at("productions") = "truncated";
    EXPECT_EQ(convert(*descriptor, changed, metadata), rebuilt);
}

TEST(AlgorithmPlugin, HostPersistsOpaqueBinaryMetadataAndPrunesRemovedKeys) {
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-plugin-cache-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup {
        std::filesystem::path path;
        ~Cleanup() { std::filesystem::remove_all(path); }
    } cleanup{directory};
    Algorithm::Metadata metadata{{{"first", std::string("a\0b", 3)}, {"second", "old"}}};
    Algorithm::saveMetadata(directory, metadata);
    EXPECT_EQ(Algorithm::loadMetadata(directory).cache, metadata.cache);
    metadata.cache.erase("second");
    metadata.cache["first"] = "updated";
    Algorithm::saveMetadata(directory, metadata);
    EXPECT_EQ(Algorithm::loadMetadata(directory).cache, metadata.cache);
    EXPECT_FALSE(std::filesystem::exists(directory / "second"));
    metadata.cache["../escape"] = "invalid";
    EXPECT_THROW(Algorithm::saveMetadata(directory, metadata), std::invalid_argument);
}

TEST(AlgorithmPlugin, LRFamilyPersistsTablesAndRegeneratesSemanticOutput) {
    for (const std::string name : {"LR", "LALR"}) {
        SCOPED_TRACE(name);
        dlib library("libispa-algorithm-" + name);
        const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
        auto tree = pluginGrammar("A:'a'; main:@ A {@};");
        Algorithm::Metadata metadata;
        const auto cold = convert(*descriptor, tree, metadata);
        ASSERT_TRUE(metadata.cache.contains("tables"));
        EXPECT_FALSE(metadata.cache.at("tables").empty());
        EXPECT_EQ(convert(*descriptor, tree, metadata), cold);
        auto edited = pluginGrammar("A:'a'; main:@ A @{renamed};");
        const auto incremental = convert(*descriptor, edited, metadata);
        Algorithm::Metadata fresh;
        EXPECT_EQ(incremental, convert(*descriptor, edited, fresh));
        EXPECT_NE(incremental, cold);
        metadata.cache["tables"] = "corrupt";
        EXPECT_EQ(convert(*descriptor, edited, metadata), incremental);
    }
}

TEST(AlgorithmPlugin, LLBuildsStructuredMembersAndCaptureMetadata) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    // Whitespace emits no assignment; groups and choices emit control flow.
    // Neither should require the Builder to find a parser call in a statement.
    for (const char* source : {
        "A:'a'; B:'b'; main:@ (A B) {@};",
        "A:'a'; B:'b'; main:@ (A | B) {@};",
        "A:'a'; main:@ A* {@};",
        "A:'a'; main:@ A? {@};",
        "A:'a'; main:@ (A)? {@};",
        "A:'a'; main:@ (A)* {@};",
        "A:'a'; main:@ item+ {@}; item:@ A {@};"
    }) {
        SCOPED_TRACE(source);
        auto tree = pluginGrammar(source);
        Algorithm::Metadata metadata;
        AST::TreeMap changed;
        auto built = descriptor->build({tree, changed}, metadata);
        const auto& ir = *static_cast<ParserIR::IR*>(built.output.get());
        const auto production_it = std::find_if(ir.getData().begin(), ir.getData().end(),
            [](const auto& value) { return value.name == std::vector<std::string>{"main"}; });
        ASSERT_NE(production_it, ir.getData().end());
        const auto& production = *production_it;
        ASSERT_TRUE(production.block.is_regular_data_block());
        const auto& capture = production.block.getRegularDataBlock().first;
        ASSERT_FALSE(capture.empty());
        ASSERT_TRUE(capture.front().isRvalue());
        ASSERT_TRUE(capture.front().getRValue().isSymbol());
        bool declared = false;
        for (const auto& statement : production.rule_members)
            if (statement.isVariable() &&
                LangAPI::Symbol{statement.getVariable().name} == capture.front().getRValue().getSymbol())
                declared = true;
        EXPECT_TRUE(declared);
        const auto cold = convert(*descriptor, tree, metadata);
        EXPECT_FALSE(cold.empty());
        EXPECT_EQ(cold.find("Recovery::handler<ISPA_STD::Recovery::Tokens,"), std::string::npos);
        EXPECT_EQ(cold.find("Recovery::Policy>"), std::string::npos);
        EXPECT_EQ(convert(*descriptor, tree, metadata), cold);
    }
}

TEST(AlgorithmPlugin, LLGeneratedRecoveryAndRuleCallbacksCompile) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto tree = pluginGrammar(
        "A:'a'; B:'b'; main: item item? item* item+ A+ B* "
        "@ (A B) @ ('x' | 'y') (B @ A)* @{pair, kind, nested}; item:@ A {@}; "
        "recursive: B recursive? A;");
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-ll-compile-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup {
        std::filesystem::path path;
        ~Cleanup() { std::filesystem::remove_all(path); }
    } cleanup{directory};
    Algorithm::Metadata metadata;
    convert(*descriptor, tree, metadata, directory);
    const auto command = std::string("clang++ -std=c++23 -fsyntax-only -I\"") +
        std::string(ROOT_DIR) + "/parser/stdlibs\" -I\"" + directory.string() +
        "\" \"" + (directory / "PluginTest.cpp").string() + "\"";
    EXPECT_EQ(std::system(command.c_str()), 0);
}

TEST(AlgorithmPlugin, LLRecoveryFindsNestedAndEnclosingTerminalsBeyondFollowOne) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto tree = pluginGrammar(
        "A:'a'; B:'b'; C:'c'; D:'d'; E:'e'; X:'x'; "
        "main: A item @ E {@}; item: B deep; deep: first | second; "
        "first: C D; second: '(' B ')';");
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-ll-recovery-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup {
        std::filesystem::path path;
        ~Cleanup() { std::filesystem::remove_all(path); }
    } cleanup{directory};
    Algorithm::Metadata metadata;
    convert(*descriptor, tree, metadata, directory);
    std::ofstream(directory / "run.cpp") << R"(
#include "PluginTest.h"
#include <iostream>
int main() {
    PluginTest::Parser parser;
    for (const char* input : {"axxcde", "axxde", "abxxe", "abcdxe", "abxx)e"}) {
        try {
            const auto& root = parser.parse(input);
            if (root.value.empty()) { std::cerr << "lost tail: " << input; return 1; }
            if (parser.getErrors().empty()) { std::cerr << "lost error: " << input; return 2; }
            if (parser.getErrors().front().message.find("expected") == std::string::npos) return 3;
            const auto offset = parser.getErrors().front().offset;
            if (offset >= std::char_traits<char>::length(input) || input[offset] != 'x') return 6;
        } catch (const std::exception& error) {
            std::cerr << input << ": " << error.what(); return 4;
        }
    }
    parser.parse("abcde");
    if (!parser.getErrors().empty() || !parser.getContextErrors().empty()) {
        for (const auto& error : parser.getErrors()) std::cerr << error.message << '\n';
        for (const auto& error : parser.getContextErrors()) std::cerr << error.message << '\n';
        return 5;
    }
}
)";
    const auto command = std::string("clang++ -std=c++23 -I\"") +
        std::string(ROOT_DIR) + "/parser/stdlibs\" -I\"" + directory.string() +
        "\" \"" + (directory / "PluginTest.cpp").string() + "\" \"" +
        (directory / "run.cpp").string() + "\" \"" + std::string(ROOT_DIR) +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (directory / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (directory / "run").string() + '"').c_str()), 0);
}

TEST(AlgorithmPlugin, LLQuantifiedRulesSkipAbsentChildrenWithoutRecovery) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto tree = pluginGrammar(
        "A:'a'; B:'b'; C:'c'; D:'d'; "
        "main: item? B item* C item+ D; item: leaf; leaf: A;");
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-ll-optional-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup {
        std::filesystem::path path;
        ~Cleanup() { std::filesystem::remove_all(path); }
    } cleanup{directory};
    Algorithm::Metadata metadata;
    convert(*descriptor, tree, metadata, directory);
    std::ofstream(directory / "run.cpp") << R"(
#include "PluginTest.h"
int main() {
    for (const char* input : {"bcad", "abaacaad", "b c a d", "a b a a c a a d"}) {
        PluginTest::Parser parser;
        parser.parse(input);
        if (!std::as_const(parser).getErrors().empty()) return 1;
    }
    PluginTest::Parser parser;
    try { parser.parse("bca"); return 2; }
    catch (const std::logic_error&) {}
    if (parser.getErrors().empty()) return 3;
    parser.parse("bcad");
    if (!parser.getErrors().empty()) return 4;

    PluginTest::Lexer lexer;
    lexer.makeTokens("bca");
    try { parser.parse(lexer); return 5; }
    catch (const std::logic_error&) {}
    if (parser.getErrors().empty()) return 6;
    lexer.clearTokens();
    lexer.makeTokens("bcad");
    parser.parse(lexer);
    if (!parser.getErrors().empty()) return 7;
}

)";
    const auto command = std::string("clang++ -std=c++23 -I\"") +
        std::string(ROOT_DIR) + "/parser/stdlibs\" -I\"" + directory.string() +
        "\" \"" + (directory / "PluginTest.cpp").string() + "\" \"" +
        (directory / "run.cpp").string() + "\" \"" + std::string(ROOT_DIR) +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (directory / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (directory / "run").string() + '"').c_str()), 0);
}

TEST(AlgorithmPlugin, LLListCaptureStopsBeforeFollowingRuleWithSharedPrefix) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto tree = pluginGrammar(
        "A:'a'; B:'b'; main: @ item+ @ tail @{items, last}; "
        "item: @ plain | marked {@}; plain: '@'? @ A {@}; "
        "marked: '@' '=' @ A {@}; tail: '@' '{' @ B '}' {@};");
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-ll-list-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup {
        std::filesystem::path path;
        ~Cleanup() { std::filesystem::remove_all(path); }
    } cleanup{directory};
    Algorithm::Metadata metadata;
    convert(*descriptor, tree, metadata, directory);
    std::ofstream(directory / "run.cpp") << R"(
#include "PluginTest.h"
int main() {
    PluginTest::Parser parser;
    if (parser.parse("a@{b}").items.size() != 1) return 1;
    if (parser.parse("a@a@=a@{b}").items.size() != 3) return 2;
    if (parser.parse("a @a @=a @{b}").items.size() != 3) return 3;
}

)";
    const auto command = std::string("clang++ -std=c++23 -I\"") +
        std::string(ROOT_DIR) + "/parser/stdlibs\" -I\"" + directory.string() +
        "\" \"" + (directory / "PluginTest.cpp").string() + "\" \"" +
        (directory / "run.cpp").string() + "\" \"" + std::string(ROOT_DIR) +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (directory / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (directory / "run").string() + '"').c_str()), 0);
}


TEST(AlgorithmPlugin, LLCountedTokensAndProductionsShareCountsInBothIteratorModes) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto tree = pluginGrammar(
        "__WS:' '; NEWLINE:'\\n'; A:'a'; B:'b'; C:'c'; "
        "main: @ A=x ':' @ body @ NEWLINE @ B=2 '!' @{first, body, newline, last}; "
        "body: @ item=x {@}; item: @ C {@}; "
        "aligned: @ __WS=x 'header' NEWLINE @ line+ '!' @{spaces, lines}; "
        "line: @ __WS=x 'item' NEWLINE {@};");
    const auto directory = std::filesystem::temp_directory_path() /
        ("ispa-counted-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    struct Cleanup {
        std::filesystem::path path;
        ~Cleanup() { std::filesystem::remove_all(path); }
    } cleanup{directory};
    Algorithm::Metadata metadata;
    const auto cold = convert(*descriptor, tree, metadata, directory);
    EXPECT_EQ(convert(*descriptor, tree, metadata), cold);
    std::ofstream(directory / "run.cpp") << R"(
#include "PluginTest.h"
#include <iostream>
struct Exposed : PluginTest::Parser { using PluginTest::Parser::aligned; };
int main() {
    PluginTest::Parser parser;
    for (const bool lazy : {true, false}) {
        const auto run = [&](const char* input) -> const PluginTest::Types::main& {
            if (lazy) return parser.parse(input);
            static PluginTest::Lexer lexer;
            lexer.clearTokens();
            lexer.makeTokens(input);
            return parser.parse(lexer);
        };
        for (const auto& [input, count] : {std::pair{"aa:cc\nbb!", 2u},
                                         std::pair{"a:c\nb b!", 1u},
                                         std::pair{":\nbb!", 0u}}) {
            const auto& root = run(input);
            if (!parser.getErrors().empty()) return 1;
            if (root.first.size() != count || root.body.data().value.size() != count ||
                root.last.size() != 2) return 2;
        }
        for (const char* input : {"aa:c\nbb!", "a:cc\nbb!", "a:c\nb!", "a:c\nbbb!", "a:c \nbb!"}) {
            try { run(input); if (parser.getErrors().empty()) { std::cerr << input; return 3; } }
            catch (const std::logic_error&) {}
        }
        run("aaa:ccc\nbb!");
        if (!parser.getErrors().empty()) return 4;
        Exposed aligned;
        PluginTest::Lexer indentation;
        const char* input = "  header\n  item\n  item\n!";
        if (lazy) {
            auto result = aligned.aligned(PluginTest::Lexer::lazy_iterator(indentation, input));
            if (!result.status || !result.it.isEnd() || result.node.data().lines.size() != 2) return 5;
        } else {
            indentation.makeTokens(input);
            auto result = aligned.aligned(PluginTest::Lexer::iterator(indentation));
            if (!result.status || !result.it.isEnd() || result.node.data().lines.size() != 2) return 6;
        }
        if (!aligned.getErrors().empty()) return 7;
    }
}
)";
    const auto command = std::string("clang++ -std=c++23 -I\"") +
        std::string(ROOT_DIR) + "/parser/stdlibs\" -I\"" + directory.string() +
        "\" \"" + (directory / "PluginTest.cpp").string() + "\" \"" +
        (directory / "run.cpp").string() + "\" \"" + std::string(ROOT_DIR) +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (directory / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (directory / "run").string() + '"').c_str()), 0);
}

TEST(AlgorithmPlugin, LLCounterChangesInvalidateCachedProductions) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    auto first = pluginGrammar("A:'a'; main: A=2 '!';");
    auto second = pluginGrammar("A:'a'; main: A=3 '!';");
    Algorithm::Metadata metadata;
    const auto old = convert(*descriptor, first, metadata);
    const auto updated = convert(*descriptor, second, metadata);
    EXPECT_NE(old, updated);
    EXPECT_EQ(convert(*descriptor, second, metadata), updated);
}

TEST(AlgorithmPlugin, LLFixedCountsHaveFiniteLookaheadIncludingZero) {
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    for (const char* source : {
        "A:'a'; B:'b'; main: small | large; small: A=2 B; large: A=3 B;",
        "A:'a'; B:'b'; main: empty | full; empty: A=0 B; full: A B;"
    }) {
        auto tree = pluginGrammar(source);
        Algorithm::Metadata metadata;
        EXPECT_FALSE(convert(*descriptor, tree, metadata).empty());
    }
}

TEST(AlgorithmPlugin, LRFamilyRejectsCountedRepetitions) {
    for (const std::string name : {"LR", "LALR"}) {
        dlib library("libispa-algorithm-" + name);
        const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
        auto tree = pluginGrammar("A:'a'; main: A=x '!';");
        Algorithm::Metadata metadata;
        EXPECT_THROW(convert(*descriptor, tree, metadata), std::invalid_argument);
    }
}
