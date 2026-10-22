#include <gtest/gtest.h>
#include <ispa/parser.h>
#include <ispa_dep_scanner/parser.h>
import Modules;
import UAST;
import dstd;
import AST.Builder;
import AST.API;
import AST.Tree;
import AST.Pass;
import Algorithm.API;
import LexerBuilder;
import LangAPI;
import LangRepr.Converter;
import cpuf.dlib;
import Dump;
import args;
import std;

namespace {
struct ModuleFiles {
    std::filesystem::path root;
    ModuleFiles() {
        static std::atomic<unsigned> serial = 0;
        root = std::filesystem::temp_directory_path() / ("ispa-modules-" +
            std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()) + "-" + std::to_string(serial++));
        std::filesystem::create_directories(root);
    }
    ~ModuleFiles() { std::error_code error; std::filesystem::remove_all(root, error); }
    std::string write(const std::string& name, const std::string& text) {
        const auto path = root / name;
        std::filesystem::create_directories(path.parent_path());
        std::ofstream(path) << text;
        return path.string();
    }
    Modules::Project preprocess(const std::vector<std::string>& files = {}) const {
        return Modules::preprocess({root.string()}, files);
    }
};
AST::Tree build(const Modules::Project& project) {
    UAST::main input;
    std::vector<std::string> files;
    for (auto& source : project.sources) {
        IspaParser parser;
        const auto& syntax = parser.parse(source.grammar.c_str()).value.data();
        input.value.insert(input.value.end(), syntax.value.begin(), syntax.value.end());
        files.insert(files.end(), syntax.value.size(), source.file);
    }
    AST::Builder builder(input);
    builder.setSourceFiles(std::move(files));
    builder.setModules(project);
    builder.build();
    return builder.get();
}
auto name(const Modules::Path& path) { return stdu::vector<std::string>(path.begin(), path.end()); }
const Modules::Source& module(const Modules::Project& project, const Modules::Path& path) {
    for (const auto& source : project.sources) if (source.name == path) return source;
    throw std::runtime_error("test module not found");
}
void references(const AST::RuleMember& member, std::vector<Modules::Path>& out) {
    if (member.isName()) out.emplace_back(member.getName().name.begin(), member.getName().name.end());
    else if (member.isGroup()) for (auto& child : member.getGroup().values) references(*child, out);
    else if (member.isOp()) for (auto& child : member.getOp().options) references(*child, out);
}
std::vector<Modules::Path> references(const AST::Rule& rule) {
    std::vector<Modules::Path> out;
    for (auto& member : rule.rule_members) references(*member, out);
    return out;
}
const std::string cpp = R"(
cpp_constexpr: 'constexpr';
feature cpp_constexpr { cpp_constexpr };
declaration: cpp_constexpr? 'x';
required: cpp_constexpr 'y';
caller: required;
choice: required | declaration;
)";
}

TEST(Modules, RecursiveCaptureDeduplicatesAndRestrictsImports) {
    ModuleFiles files;
    files.write("lib/expr.isc", "expr: NUMBER; NUMBER: [0-9]+; unused: 'u';");
    const auto main = files.write("main.isc", "import {expr} from lib.expr;\nmain: expr;");
    auto project = Modules::preprocess({files.root.string(), (files.root / "lib").string()}, {main});
    ASSERT_TRUE(project.modular);
    ASSERT_EQ(project.sources.size(), 2u);
    const auto& scope = module(project, {"main"});
    EXPECT_EQ(scope.allowed_symbols.at({"expr"}), (Modules::Path{"lib", "expr", "expr"}));
    EXPECT_FALSE(scope.allowed_symbols.contains({"NUMBER"}));
    auto tree = build(project);
    EXPECT_EQ(references(tree.getTreeMap().at(name({"modules", "main", "main"}))).front(),
              (Modules::Path{"modules", "lib", "expr", "expr"}));
    EXPECT_TRUE(tree.getTreeMap().contains(name({"modules", "lib", "expr", "NUMBER"})));
    EXPECT_FALSE(tree.getTreeMap().contains(name({"modules", "lib", "expr", "unused"})));
}
TEST(Modules, AliasesAndNestedRuleScopes) {
    ModuleFiles files;
    files.write("lib.isc", "main: inner #inner: 'x'; ;");
    files.write("main.isc", "import lib as syntax; main: syntax;");
    auto project = files.preprocess();
    auto tree = build(project);
    EXPECT_EQ(references(tree.getTreeMap().at(name({"modules", "main", "main"}))).front(),
              (Modules::Path{"modules", "lib", "main"}));
    EXPECT_EQ(references(tree.getTreeMap().at(name({"modules", "lib", "main"}))).front(),
              (Modules::Path{"modules", "lib", "main", "inner"}));
}
TEST(Modules, UnusedDiscoveredModulesDoNotRequireExternalDependencies) {
    ModuleFiles files;
    const auto main = files.write("main.isc", "module main; main: 'x';");
    const auto optional = files.write("optional.isc",
        "import extern foreign expression; main: expression;");
    auto project = files.preprocess({main});
    ASSERT_EQ(project.sources.size(), 1u);
    EXPECT_NO_THROW(build(project));
    EXPECT_THROW(files.preprocess({main, optional}), std::runtime_error);

    files.write("main.isc", "import optional; main: optional;");
    EXPECT_THROW(files.preprocess({main}), std::runtime_error);
    files.write("middle.isc", "import optional; main: optional;");
    files.write("main.isc", "import middle; main: middle;");
    EXPECT_THROW(files.preprocess({main}), std::runtime_error);
}
TEST(Modules, ImportErrorsAreReportedAtTheirSource) {
    ModuleFiles files;
    files.write("lib.isc", "rule: 'x';");
    const auto main = files.write("main.isc", "\nimport {missing} from lib; main: 'm';");
    try { files.preprocess(); FAIL() << "expected missing import"; }
    catch (const std::exception& e) { EXPECT_NE(std::string(e.what()).find(main + ":2:1:"), std::string::npos); }
    files.write("main.isc", "import absent; main: 'x';");
    EXPECT_THROW(files.preprocess(), std::runtime_error);
    files.write("main.isc", "import {rule} from lib; rule: 'y'; main: rule;");
    EXPECT_THROW(files.preprocess(), std::runtime_error);
    files.write("main.isc", "main: lib.rule;");
    files.write("lib.isc", "module lib; rule: 'x';");
    EXPECT_THROW(build(files.preprocess()), std::runtime_error);
}
TEST(Modules, MissingDelimiterReportsExpectedCloserAndOpeningLine) {
    ModuleFiles files;
    const auto file = files.write("main.isc", "A: 'a';\nmain: ( A ;\n");
    try { files.preprocess(); FAIL() << "expected missing delimiter"; }
    catch (const std::exception& error) {
        const std::string message = error.what();
        EXPECT_NE(message.find(file + ":3:1:"), std::string::npos) << message;
        EXPECT_NE(message.find("expected ')'"), std::string::npos) << message;
        EXPECT_NE(message.find("opened at line 2"), std::string::npos) << message;
    }
}
TEST(Modules, CyclicImportsResolveRulesAndFeatures) {
    ModuleFiles files;
    files.write("a.isc", "import {two} from b; one: 'a' two?; feature recursion {two};");
    files.write("b.isc", "import {one, recursion} from a; two: 'b' one?;");
    files.write("main.isc", "import {one} from a; main: one;");
    auto project = files.preprocess();
    EXPECT_EQ(module(project, {"b"}).allowed_features.at({"recursion"}),
              (std::vector<Modules::Path>{{"b", "two"}}));
    auto tree = build(project);
    EXPECT_EQ(references(tree.getTreeMap().at(name({"modules", "a", "one"}))).front(),
              (Modules::Path{"modules", "b", "two"}));
    EXPECT_EQ(references(tree.getTreeMap().at(name({"modules", "b", "two"}))).front(),
              (Modules::Path{"modules", "a", "one"}));
}
TEST(Modules, CyclicImportsSupportLocalFeatureDetach) {
    ModuleFiles files;
    files.write("a.isc", "import {two} from b; one: 'a' two?; feature recursion {two};");
    files.write("b.isc", "import {one} from a; two: 'b' one?;");
    files.write("main.isc", "import * from a; detach feature recursion; main: one;");
    auto tree = build(files.preprocess());
    auto target = references(tree.getTreeMap().at(name({"modules", "main", "main"}))).front();
    EXPECT_TRUE(references(tree.getTreeMap().at(name(target))).empty());
}
TEST(Modules, DetachPropagatesThroughRequiredCallersAndPrunesAlternatives) {
    ModuleFiles files;
    files.write("cpp.isc", cpp);
    files.write("main.isc", "import * from cpp; detach cpp_constexpr; main: declaration;");
    auto project = files.preprocess();
    EXPECT_FALSE(module(project, {"main"}).allowed_symbols.contains({"cpp_constexpr"}));
    auto tree = build(project);
    const auto target = references(tree.getTreeMap().at(name({"modules", "main", "main"}))).front();
    const auto& declaration = tree.getTreeMap().at(name(target));
    EXPECT_TRUE(references(declaration).empty());
    ASSERT_EQ(declaration.rule_members.size(), 1u);
    EXPECT_EQ(declaration.rule_members.front()->getString().value, "x");
    for (const auto& [path, rule] : tree.getTreeMap()) {
        EXPECT_NE(path.back(), "cpp_constexpr");
        EXPECT_NE(path.back(), "required");
        EXPECT_NE(path.back(), "caller");
        if (path.back() == "choice") EXPECT_EQ(references(rule).size(), 1u);
    }
}
TEST(Modules, DetachFeaturesAreLocalToEachImporter) {
    ModuleFiles files;
    files.write("cpp.isc", cpp);
    files.write("full.isc", "import {declaration} from cpp; main: declaration;");
    files.write("lean.isc", "import * from cpp; detach feature cpp_constexpr; main: declaration;");
    files.write("main.isc", "import full as full; import lean as lean; main: full '|' lean;");
    auto tree = build(files.preprocess());
    const auto full = references(tree.getTreeMap().at(name({"modules", "full", "main"}))).front();
    const auto lean = references(tree.getTreeMap().at(name({"modules", "lean", "main"}))).front();
    EXPECT_NE(full, lean);
    EXPECT_FALSE(references(tree.getTreeMap().at(name(full))).empty());
    EXPECT_TRUE(references(tree.getTreeMap().at(name(lean))).empty());
    EXPECT_TRUE(tree.getTreeMap().contains(name({"modules", "cpp", "cpp_constexpr"})));
}
TEST(Modules, RemovingEntryReportsAnErrorAndOptionalOnlyRulesRemainEpsilon) {
    ModuleFiles files;
    files.write("cpp.isc", "feature optional { optional }; optional: 'x'; empty: optional?;");
    files.write("main.isc", "import * from cpp; detach feature optional; main: empty;");
    auto tree = build(files.preprocess());
    AST::TreePass pass(tree);
    pass.work();
    bool empty = false;
    for (const auto& [path, rule] : tree.getTreeMap()) if (path.back() == "empty") {
        EXPECT_TRUE(rule.rule_members.empty()); empty = true;
    }
    EXPECT_TRUE(empty);
    files.write("main.isc", "import * from cpp; detach optional; main: optional;");
    EXPECT_THROW(build(files.preprocess()), std::runtime_error);
}
TEST(Modules, StringsCommentsAndPythonDoNotCreateDependencies) {
    ModuleFiles files;
    files.write("main.isc", R"(module example -> main;
// import missing;
/* detach main; */
main: 'import absent; detach main;' [import]*;
action { text = "import missing;" }
)");
    auto project = files.preprocess();
    const auto& source = module(project, {"example"});
    EXPECT_TRUE(source.imports.empty());
    EXPECT_TRUE(source.detach.empty());
    EXPECT_EQ(source.declarations.at({"main"}).line, 4u);
    EXPECT_EQ(source.grammar.find("main:"), std::string("module example -> main;\n// import missing;\n/* detach main; */\n").size());
}
TEST(Modules, SourcesWithoutDirectivesKeepSharedLegacyScope) {
    ModuleFiles files;
    files.write("a.isc", "main: TOKEN;");
    files.write("b.isc", "TOKEN: 'x';");
    auto project = files.preprocess();
    EXPECT_FALSE(project.modular);
    auto tree = build(project);
    EXPECT_TRUE(tree.getTreeMap().contains(name({"main"})));
    EXPECT_EQ(references(tree.getTreeMap().at(name({"main"}))).front(), (Modules::Path{"TOKEN"}));
}

TEST(Modules, PythonImportsAreErasedWithoutChangingSourcePositions) {
    ModuleFiles files;
    const std::string text = "import py package.helpers as h;\nmain: 'x';";
    files.write("main.isc", text);
    const auto project = files.preprocess();
    const auto& source = module(project, {"main"});
    ASSERT_EQ(source.python_imports.size(), 1u);
    EXPECT_EQ(source.python_imports.front().source, (Modules::Path{"package", "helpers"}));
    EXPECT_EQ(source.python_imports.front().alias, "h");
    EXPECT_TRUE(source.imports.empty());
    EXPECT_EQ(source.grammar.size(), text.size());
    EXPECT_EQ(source.grammar.find("main:"), text.find("main:"));
    EXPECT_EQ(source.declarations.at({"main"}).line, 2u);
}

TEST(Modules, PythonImportsRejectClassesAndUnsupportedModulesAtTheirSource) {
    ModuleFiles files;
    files.write("main.isc", "import py helpers; main: 'x';");
    const auto python = files.write("helpers.py", "class Box:\n    pass\n");
    for (const auto* code : {
        "class Box:\n    pass\n",
        "def helper() -> int:\n    class Box:\n        pass\n    return 1\n",
        "import math\n",
        "def helper(value):\n    return value\n",
        "def helper(value: int = 1) -> int:\n    return value\n",
        "value = [1, 2]\n"}) {
        files.write("helpers.py", code);
        try { build(files.preprocess()); FAIL() << code; }
        catch (const std::exception& error) {
            EXPECT_NE(std::string(error.what()).find(python + ":"), std::string::npos) << error.what();
            if (std::string_view(code).find("class Box") != std::string_view::npos)
                EXPECT_NE(std::string(error.what()).find("classes are not supported"), std::string::npos);
        }
    }
}

TEST(Modules, PythonImportsValidateFilesExportsAndCallArguments) {
    ModuleFiles files;
    files.write("helpers.py", "def scale(value: int) -> int:\n    return value * 2\n");
    files.write("other.py", "OTHER = 1\n");
    for (const auto* code : {
        "import py absent; main: 'x';",
        "import py helpers as h; main { ctx.ast.value = h.absent(1) }",
        "import py helpers as h; main { ctx.ast.value = h.scale() }",
        "import py helpers as h; import py other as h; main: 'x';",
        "import py helpers as ctx; main: 'x';",
        "import py helpers as h; main { h = 1 }"}) {
        files.write("main.isc", code);
        EXPECT_THROW(build(files.preprocess()), std::invalid_argument) << code;
    }
}

TEST(Modules, PythonImportsResolveDottedPathsRelativeToTheirGrammarAndDeduplicateAliases) {
    ModuleFiles files;
    files.write("nested/main.isc", "import py package.helpers; import py package.helpers as h; main: 'x';");
    files.write("nested/package/helpers.py", "def scale(value: int) -> int:\n    return value * 2\n");
    auto tree = build(files.preprocess());
    ASSERT_EQ(tree.getPythonDeclarations().size(), 1u);
    const auto& python = tree.getPythonDeclarations().front().getNamespace();
    ASSERT_EQ(python.declarations.size(), 1u);
    const auto& package = python.declarations.front().getNamespace();
    EXPECT_EQ(package.name, "package");
    ASSERT_EQ(package.declarations.size(), 1u);
    EXPECT_EQ(package.declarations.front().getNamespace().name, "helpers");
}

TEST(Modules, GeneratedParserCallsImportedPythonFunctionsAndVariables) {
    ModuleFiles files;
    files.write("helpers.py", R"py("""Helpers compiled into the generated parser."""
FACTOR = 2
OFFSET: int = 1
def add(value: int) -> int:
    return value + OFFSET
def scale(value: int) -> int:
    return add(value) * FACTOR
def local(value: int) -> int:
    FACTOR = 3
    return value * FACTOR
def noop() -> None:
    pass
)py");
    files.write("main.isc", R"isc(import py helpers as h;
import py helpers;
main {
    match 'x';
    h.noop()
    ctx.ast.result = h.scale(20)
    ctx.ast.again = helpers.scale(20)
    ctx.ast.local = h.local(4)
    ctx.ast.factor = h.FACTOR
}
)isc");
    auto tree = build(files.preprocess());
    ASSERT_EQ(tree.getPythonDeclarations().size(), 1u);
    AST::TreePass pass(tree);
    pass.work();
    static Args settings{};
    dumper.setArgsPointer(&settings);
    LexerBuilder lexer(tree);
    lexer.build();
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    Algorithm::Metadata metadata;
    auto result = descriptor->build({tree, {}}, metadata);
    Algorithm::ConversionRequest request{lexer, tree, LangAPI::Language::Cpp, "PythonRuntime"};
    auto holder = result.to_lang_repr(result.output.get(), request);
    LangRepr::Converter converter(holder, "cpp", "PythonRuntime", false);
    converter.init();
    converter.construct();
    for (const auto& [name, text] : converter.get()) files.write("generated/" + name, text);
    files.write("generated/run.cpp", R"cpp(
#include "PythonRuntime.h"
int main() {
    PythonRuntime::Parser parser;
    const auto& ast = parser.parse("x").value.data();
    if (ast.result != 42 || ast.again != 42 || ast.local != 12 || ast.factor != 2) return 1;
    if (python::helpers::scale(20) != 42) return 2;
    if (!parser.getErrors().empty()) return 3;
}
)cpp");
    const auto generated = files.root / "generated";
    const auto command = std::string("clang++ -std=c++23 -I\"") + ROOT_DIR +
        "/parser/stdlibs\" -I\"" + generated.string() + "\" \"" +
        (generated / "PythonRuntime.cpp").string() + "\" \"" +
        (generated / "run.cpp").string() + "\" \"" + ROOT_DIR +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (generated / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (generated / "run").string() + '"').c_str()), 0);
}

TEST(Modules, DetachingOptionalCapturesUpdatesDataFields) {
    ModuleFiles files;
    files.write("cpp.isc", "keyword: 'constexpr'; WORD: [a-z]+; declaration: @ keyword? @ WORD @{keyword, name};");
    files.write("main.isc", "import * from cpp; detach keyword; main: declaration;");
    auto tree = build(files.preprocess());
    auto target = references(tree.getTreeMap().at(name({"modules", "main", "main"}))).front();
    const auto& rule = tree.getTreeMap().at(name(target));
    ASSERT_EQ(rule.data_block.fields.size(), 1u);
    EXPECT_EQ(rule.data_block.fields.front().first, "name");
}

TEST(Modules, GeneratedParserKeepsFullAndDetachedVariants) {
    ModuleFiles files;
    files.write("cpp.isc", "import full; keyword: 'c'; feature constexpr {keyword}; declaration: keyword? 'x' full?;");
    files.write("full.isc", "import {declaration} from cpp; main: declaration;");
    files.write("lean.isc", "import * from cpp; detach feature constexpr; main: declaration;");
    files.write("main.isc", "import full; import lean; main: full '|' lean;");
    auto tree = build(files.preprocess());
    AST::TreePass pass(tree);
    pass.work();
    static Args settings{};
    dumper.setArgsPointer(&settings);
    LexerBuilder lexer(tree);
    lexer.build();
    dlib library("libispa-algorithm-LL");
    const auto* descriptor = library.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    Algorithm::Metadata metadata;
    auto result = descriptor->build({tree, {}}, metadata);
    Algorithm::ConversionRequest request{lexer, tree, LangAPI::Language::Cpp, "ModuleRuntime"};
    auto holder = result.to_lang_repr(result.output.get(), request);
    LangRepr::Converter converter(holder, "cpp", "ModuleRuntime", false);
    converter.init();
    converter.construct();
    for (const auto& [name, text] : converter.get()) files.write("generated/" + name, text);
    files.write("generated/run.cpp", R"driver(
#include "ModuleRuntime.h"
int main() {
    ModuleRuntime::Parser parser;
    for (const char* text : {"cx|x", "x|x", "cxcx|xx"}) {
        try { parser.parse(text); if (!parser.getErrors().empty()) return 1; }
        catch (...) { return 2; }
    }
    try { parser.parse("cx|cx"); if (parser.getErrors().empty()) return 3; }
    catch (...) { return 0; }
    return 0;
}
)driver");
    const auto generated = files.root / "generated";
    const auto command = std::string("clang++ -std=c++23 -I\"") + ROOT_DIR +
        "/parser/stdlibs\" -I\"" + generated.string() + "\" \"" +
        (generated / "ModuleRuntime.cpp").string() + "\" \"" +
        (generated / "run.cpp").string() + "\" \"" + ROOT_DIR +
        "/parser/stdlibs/src/core.cpp\" -o \"" + (generated / "run").string() + "\"";
    ASSERT_EQ(std::system(command.c_str()), 0);
    EXPECT_EQ(std::system(('"' + (generated / "run").string() + '"').c_str()), 0);
}

TEST(Modules, DetachRemovesRecursiveCyclesThatLoseTheirBaseAlternative) {
    ModuleFiles files;
    files.write("lib.isc", "base: 'b'; recursive: recursive | base; caller: recursive; safe: 's';");
    files.write("main.isc", "import * from lib; detach base; main: safe;");
    auto tree = build(files.preprocess());
    for (const auto& [path, rule] : tree.getTreeMap()) {
        EXPECT_NE(path.back(), "recursive");
        EXPECT_NE(path.back(), "caller");
        EXPECT_NE(path.back(), "base");
    }
    EXPECT_TRUE(tree.getTreeMap().contains(name({"modules", "lib", "safe"})));
}

TEST(Modules, CyclicDetachPropagatesToAnAlreadyVisitedRoot) {
    ModuleFiles files;
    files.write("a.isc", "import {caller} from b; base: 'x'; required: base; detach base;");
    const auto root = files.write("b.isc", "import {required} from a; caller: required; main: 'b' caller?;");
    auto project = files.preprocess({root});
    auto tree = build(project);
    EXPECT_TRUE(references(tree.getTreeMap().at(name({"modules", "b", "main"}))).empty());
    for (const auto& [path, rule] : tree.getTreeMap()) {
        EXPECT_NE(path.back(), "caller");
        EXPECT_NE(path.back(), "required");
        EXPECT_NE(path.back(), "base");
        for (const auto& ref : references(rule)) EXPECT_TRUE(tree.getTreeMap().contains(name(ref)));
    }
}

TEST(Modules, GeneratedDependencyParserCollectsNestedDeclarationsAndSpans) {
    ModuleFiles files;
    const std::string text = R"isc(module /* header */ app.front -> main;
feature optional { main.nested };
// import missing;
#[inline] main>(arg): (';' | [;#{}]) @{arg}
    #nested: 'x';
;
action { value = {"text": "import absent; #nested: ';';"}
# A Python comment with unmatched delimiters: } )
value = """ } import absent; """
}
)isc";
    files.write("main.isc", text);
    auto project = files.preprocess();
    const auto& source = module(project, {"app", "front"});
    EXPECT_EQ(source.entry, (std::optional<Modules::Path>{{"main"}}));
    EXPECT_TRUE(source.declarations.contains({"main"}));
    EXPECT_TRUE(source.declarations.contains({"main", "nested"}));
    EXPECT_TRUE(source.declarations.contains({"action"}));
    EXPECT_EQ(source.features.at({"optional"}), (std::vector<Modules::Path>{{"main", "nested"}}));
    EXPECT_TRUE(source.imports.empty());
    EXPECT_EQ(source.declarations.at({"main", "nested"}).line, 5u);
    EXPECT_EQ(source.grammar.size(), text.size());
    for (std::size_t i = 0; i < text.size(); ++i)
        if (text[i] == '\n') EXPECT_EQ(source.grammar[i], '\n');
    EXPECT_EQ(source.grammar.find("#[inline]"), text.find("#[inline]"));
    EXPECT_EQ(source.grammar.find("#nested:"), text.find("#nested:"));
    EXPECT_EQ(source.grammar.find("p{"), text.find("p{"));
}

TEST(Modules, GeneratedDependencyParserRejectsMalformedOrTruncatedSyntax) {
    ModuleFiles files;
    for (const auto* text : {"module app main;", "import {x from lib;", "feature x {main}; main: ('x';",
                             "main: 'x'; trailing", "main: 'unterminated;", "main: [unterminated;",
                             "main: 'x'; /* unterminated", "main: 'x'; 'unterminated",
                             "main: 'x'; [unterminated", "action { p{ value = { }"}) {
        files.write("main.isc", text);
        EXPECT_THROW(files.preprocess(), std::runtime_error) << text;
    }
}

TEST(Modules, DependencyLexerAndGeneratedParserSupportTokenizedInput) {
    const char* text = "module app.front -> main; /* comment */ main: 'x';";
    IspaDepLexer lexer;
    lexer.setInput(text);
    lexer.makeTokens();
    IspaDepParser parser;
    const auto& tree = parser.parse(lexer);
    EXPECT_EQ(tree.value.data().value.size(), 2u);
    EXPECT_EQ(lexer.comments.size(), 1u);
}

TEST(Modules, GeneratedDependencyParserDistinguishesDirectivesFromRuleNames) {
    ModuleFiles files;
    files.write("lib.isc", "feature_rule: 'x';");
    files.write("main.isc", R"(module app.front -> main;
import {feature_rule} from lib;
module_rule: 'm';
import_rule: 'i';
detach_rule: 'd';
feature optional {feature_rule};
detach feature optional;
main: module_rule import_rule detach_rule;
)");
    const auto project = files.preprocess();
    const auto& source = module(project, {"app", "front"});
    EXPECT_TRUE(source.declarations.contains({"module_rule"}));
    EXPECT_TRUE(source.declarations.contains({"import_rule"}));
    EXPECT_TRUE(source.declarations.contains({"detach_rule"}));
    EXPECT_EQ(source.imports.front().symbols, (std::vector<Modules::Path>{{"feature_rule"}}));
    EXPECT_TRUE(source.detach.front().feature);
    EXPECT_TRUE(source.detached_symbols.contains({"lib", "feature_rule"}));
}
