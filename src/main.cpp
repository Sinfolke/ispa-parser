#include <ispa/parser.h>
#include <ispa_dep_scanner/parser.h>
import cpuf.color;
import cpuf.printf;
import cpuf.op;
import cpuf.dlib;
import CLI;
import init;
import args;
import corelib;
import logging;
import Dump;
import AST.API;
import AST.types;
import AST.Tree;
import AST.BackendGuard;
import AST.Builder;
import AST.Pass;
import Semantic;
import LangRepr.Converter;
import Algorithm.API;
import Algorithm.Cache;
import hash;
import AST.Builder;
import LexerBuilder;
import DFA;
import dstd;

void printHelp() {
    cpuf::printf(R"(
usage:
    [parameters] [individual files]
    -help show this help message
    -version show version
    --dir specify the directories where to locate sources
    --lang specify target language to generate to. Use --help-lang to see all languages
    )", color::yellow, color::reset);
    cpuf::printf("\n");
}
stdu::vector<const char*> parameters_required { "lang" };
stdu::vector<const char*> parameters_with_arguments { "lang", "a" };
std::unordered_map<std::string_view, int> parameters_with_fixes_arguments_amount {
    { "lang", 1 },
    { "a", 1 }
};

namespace {
    // --- generic "key \t hash" manifest, shared by the rule-cache and
    // the output-content-cache below (same file format, different keys) ---
    auto loadKeyHashMap(const std::filesystem::path &path) -> std::unordered_map<std::string, std::size_t> {
        std::unordered_map<std::string, std::size_t> map;
        std::ifstream in(path);
        std::string line;
        while (std::getline(in, line)) {
            const auto tab = line.find('\t');
            if (tab == std::string::npos) continue;
            map[line.substr(0, tab)] = std::stoull(line.substr(tab + 1));
        }
        return map;
    }
    auto saveKeyHashMap(const std::filesystem::path &path, const std::unordered_map<std::string, std::size_t> &map) -> void {
        std::ofstream out(path, std::ios::trunc);
        for (const auto &[key, hash] : map)
            out << key << '\t' << hash << '\n';
    }

    // --- write generated files, skipping unchanged content (so mtimes and
    // downstream build graphs stay untouched), then prune incremental/
    // files this run no longer produced ---
    struct WriteResult {
        std::unordered_map<std::string, std::size_t> hashes;
        std::size_t updated = 0;
    };
    auto writeGeneratedFiles(
        const std::filesystem::path &dir_path,
        const std::vector<std::pair<std::string, std::string>> &files,
        const std::unordered_map<std::string, std::size_t> &previous_hashes
    ) -> WriteResult {
        WriteResult result;
        std::unordered_set<std::string> expected;

        for (const auto &[rel_path, content] : files) {
            const auto path = dir_path / rel_path;
            if (rel_path.starts_with("incremental/"))
                std::filesystem::create_directories(path.parent_path());

            expected.insert(rel_path);
            const std::size_t content_hash = std::hash<std::string>{}(content);
            result.hashes[rel_path] = content_hash;

            const auto previous = previous_hashes.find(rel_path);
            if (previous != previous_hashes.end() &&
                previous->second == content_hash &&
                std::filesystem::exists(path)) {
                continue; // unchanged — leave the file and its mtime alone
            }

            std::ofstream out(path, std::ios::binary | std::ios::trunc);
            if (!out)
                throw std::runtime_error("Cannot write: " + path.string());
            out.exceptions(std::ios::badbit | std::ios::failbit);
            out << content;
            ++result.updated;
        }

        for (const auto &[key, hash] : previous_hashes) {
            if (!key.starts_with("incremental/") || expected.contains(key)) continue;
            if (std::filesystem::remove(dir_path / key))
                cpuf::printf("removed stale -> {}\n", (dir_path / key).string());
        }
        return result;
    }
}

int main(int argc, char** argv) {
    Parser::Types::main modules;
    std::vector<std::string> source_files;
    auto args = init(argc, argv);
    dumper.setArgsPointer(&args);
    dumper.setDumpDirectory(args.dump_dir);
    dumper.initDumpDirectory();
    logger.clearLogDirectory();
    if (args.version) {
        cpuf::printf("%$\n", PROGRAM_VERSION);
        return 0;
    }

    if (args.files.empty() && args.dir.empty())
        throw UError("No input files");

    for (const auto file : args.files) {
        cpuf::printf("file: {}\n", file);
        std::string fileContent;
        try {
            fileContent = corelib::file::readFile(std::string(file));
        } catch (std::exception &e) {
            throw UError("Failed read file: %s", e.what());
        }
        Parser::Parser parser;
        auto &main = parser.parse(fileContent.c_str());
        modules.value.insert(modules.value.end(), main.value.begin(), main.value.end());
        source_files.insert(source_files.end(), main.value.size(), file);
        // for (const auto &v : main.value) {
        //     modules.push_back(std::get<ISPA_STD::Node<Parser::Rules, Parser::Types::grammar>>(v));
        // }
    }
    for (const auto &dirPath : args.dir) {
        for (auto file : corelib::file::getFilesRecursively(dirPath, ".isc")) {
            cpuf::printf("file {}", file.c_str());
            std::string content = corelib::file::readFile(file);
            // lexer.makeTokens(content.c_str());
            Parser::Parser parser;
            auto &main = parser.parse(content.c_str());
            for (const auto &err : parser.getErrors()) {
                std::cout << "Expected " << err.expected_text << ", got " << Parser::TokensToString(err.unexpected) << std::endl;
            }
            modules.value.insert(modules.value.end(), main.value.begin(), main.value.end());
            source_files.insert(source_files.end(), main.value.size(), file);
        }
    }

    if (dumper.shouldDump("NFA"))
        std::ofstream(dumper.makeDumpPath("NFA"), std::ios::trunc);
    if (dumper.shouldDump("DFA"))
        std::ofstream(dumper.makeDumpPath("DFA"), std::ios::trunc);

    AST::Builder ast_builder(modules);
    ast_builder.setSourceFiles(std::move(source_files));
    ast_builder.build();
    auto ast = ast_builder.get();
    AST::requireCppSupport(ast);

    Semantic semantic(ast);
    semantic.checkTokenRecursion();
    AST::TreePass pass(ast);
    pass.work();
    {
        std::ofstream treeAPIO("treeAPI.txt");
        for (const auto &[name, value] : ast.getTreeMap())
            treeAPIO << "name<" << corelib::text::join(name, "_") << "> : " << value;
    }

    std::filesystem::path output_path = args.output;
    LexerBuilder lexer_data(ast);
    lexer_data.build();

    std::string name;
    if (!ast.getName().empty()) {
        name = ast.getName();
        output_path.append(ast.getName());
    } else {
        name = std::filesystem::path(args.output).filename().string();
        cpuf::printf("args.output: {} using filename: {}\n", args.output, name.c_str());
    }

    const auto dir_path = output_path.has_parent_path() ? output_path.parent_path() : std::filesystem::path{"."};
    std::filesystem::create_directories(dir_path);
    std::filesystem::create_directories(dir_path / "incremental");

    // Every algorithm uses the same entry point; output conversion belongs to it.
    const auto algorithm_name = to_string(args.algorithm);
    dlib algorithm_lib("libispa-algorithm-" + algorithm_name);
    const auto* algorithm = algorithm_lib.load<Algorithm::EntryFn*>("ispa_algorithm_v1")();
    if (!algorithm || algorithm->version != Algorithm::interface_version ||
        !algorithm->id || algorithm_name != algorithm->id || !algorithm->build)
        throw std::runtime_error("Incompatible algorithm module: " + algorithm_name);
    const auto cache_dir = dir_path / ".ispa-cache" / name /
        (algorithm_name + "-" + std::to_string(algorithm->cache_version)) /
        (args.language_str + "-" + std::to_string(args.auto_conflicts) + "-" +
         std::to_string(args.conflict_lookahead));
    std::filesystem::create_directories(cache_dir);
    auto metadata = Algorithm::loadMetadata(cache_dir / "data");
    const auto rule_manifest_path = cache_dir / "rule-hashes";
    const auto previous_rule_hashes = loadKeyHashMap(rule_manifest_path);

    const auto &tree_map = ast.getTreeMap();
    AST::TreeMap changed_rules;
    std::unordered_map<std::string, std::size_t> new_rule_hashes;
    for (const auto &[path, rule] : tree_map) {
        std::ostringstream oss;
        oss << rule; // reuses AST::Rule's existing operator<<
        const std::size_t rule_hash = std::hash<std::string>{}(oss.str());
        const auto key = corelib::text::join(path, ".");
        new_rule_hashes[key] = rule_hash;

        const auto prev = previous_rule_hashes.find(key);
        if (prev == previous_rule_hashes.end() || prev->second != rule_hash)
            changed_rules.emplace(path, rule);
    }
    cpuf::printf("{} of {} rules changed since last run\n", changed_rules.size(), tree_map.size());
    const Algorithm::BuildRequest build_request{ast, changed_rules,
        args.auto_conflicts, args.conflict_lookahead};
    auto built = algorithm->build(build_request, metadata);
    if (!built.output || !built.to_lang_repr)
        throw std::runtime_error("Algorithm returned no LangRepr converter: " + algorithm_name);
    Algorithm::ConversionRequest conversion_request{lexer_data, ast, args.language, name};
    auto holder = built.to_lang_repr(built.output.get(), conversion_request);

    // dlib-loads libispa-converter-<lang> and resolves "<lang>_construct"
    // (e.g. the extern "C" cpp_construct in converter.cpp) internally.
    LangRepr::Converter converter(holder, args.language_str, name, args.incremental);
    converter.init();
    converter.construct();

    const auto manifest_path = dir_path / ".codegen-manifest";
    const auto previous_hashes = loadKeyHashMap(manifest_path);
    const auto result = writeGeneratedFiles(dir_path, converter.get(), previous_hashes);

    saveKeyHashMap(manifest_path, result.hashes);
    Algorithm::saveMetadata(cache_dir / "data", metadata);
    saveKeyHashMap(rule_manifest_path, new_rule_hashes);

    std::cout << "Updated " << result.updated << " file(s)\n";
    return 0;
}
