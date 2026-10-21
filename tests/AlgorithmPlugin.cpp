#include <gtest/gtest.h>
#include <output/Parser.h>
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
    Parser::Parser parser;
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
        "@ (A B) @ ('x' | 'y') (B @ A)* @{pair, kind, nested}; item:@ A {@};");
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
