#include <ispa/parser.h>
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
import UAST;
import Modules;
import External.Exports;
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

int generate(Args args);

// Plan external packages from the same discovered grammar sources, then run
// each package through the ordinary generator with its own namespace/cache.
// No generated parser implementation is folded into its consumer.
void generateDependencies(Args& args) {
    namespace fs = std::filesystem;
    const auto discovered = Modules::discover(args.dir, args.files);
    if (!discovered.modular) return;
    std::map<Modules::Path, const Modules::Source*> sources;
    for (const auto& source : discovered.sources)
        if (!sources.emplace(source.name, &source).second)
            throw std::runtime_error("Duplicate module: " + Modules::spelling(source.name));
    std::map<std::string, std::string> dependencies;
    for (const auto& [name, prefix] : args.dependencies)
        if (!dependencies.emplace(name, prefix).second)
            throw std::runtime_error("Duplicate --dep binding: " + name);
    const Modules::Source* root = nullptr;
    if (!args.files.empty()) root = &discovered.source(fs::canonical(args.files.front()).string());
    else {
        for (const auto& source : discovered.sources)
            if (source.name == Modules::Path{"main"}) { root = &source; break; }
        if (!root)
        for (const auto& source : discovered.sources) {
            if (source.entry || source.declarations.contains({"main"})) {
                if (root) throw std::runtime_error("Multiple module entries; specify the root source file explicitly");
                root = &source;
            }
        }
    }
    if (!root && discovered.sources.size() == 1) root = &discovered.sources.front();
    if (!root) throw std::runtime_error("--no-dep requires a root grammar source");

    auto closure = [&](const std::set<Modules::Path>& roots) {
        std::set<Modules::Path> visited;
        auto visit = [&](auto& self, const Modules::Path& name) -> void {
            if (!visited.insert(name).second) return;
            const auto found = sources.find(name);
            if (found == sources.end()) throw std::runtime_error("Dependency grammar module not found: " + Modules::spelling(name));
            for (const auto& imp : found->second->imports)
                if (imp.external.empty()) self(self, imp.source);
        };
        for (const auto& name : roots) visit(visit, name);
        return visited;
    };
    const auto host = closure({root->name});
    std::map<std::string, std::set<Modules::Path>> packages;
    auto collect = [&](const std::set<Modules::Path>& modules) {
        bool changed = false;
        for (const auto& module : modules)
            for (const auto& imp : sources.at(module)->imports)
                if (!imp.external.empty() && !dependencies.contains(imp.external))
                    changed |= packages[imp.external].insert(imp.source).second;
        return changed;
    };
    collect(host);
    for (bool changed = true; changed;) {
        changed = false;
        const auto snapshot = packages;
        for (const auto& [name, roots] : snapshot) changed |= collect(closure(roots));
    }
    const auto output_dir = fs::path(args.output).has_parent_path() ? fs::path(args.output).parent_path() : fs::path(".");
    const auto host_name = fs::path(args.output).filename().string();
    std::set<std::string> visiting, built;
    auto build = [&](auto& self, const std::string& name) -> void {
        if (built.contains(name)) return;
        if (!visiting.insert(name).second) throw std::runtime_error("Cyclic external parser dependency: " + name);
        if (name == host_name) throw std::runtime_error("Dependency output collides with host parser: " + name);
        const auto modules = closure(packages.at(name));
        for (const auto& module : modules)
            for (const auto& imp : sources.at(module)->imports)
                if (!imp.external.empty() && packages.contains(imp.external)) self(self, imp.external);
        Args child = args;
        child.no_dep = false;
        child.dependency_build = true;
        child.dir.clear();
        child.files.clear();
        for (const auto& module : modules) child.files.push_back(sources.at(module)->file);
        child.output = (output_dir / name).string();
        child.dependencies.assign(dependencies.begin(), dependencies.end());
        if (generate(std::move(child)) != 0) throw std::runtime_error("Failed to generate external parser: " + name);
        dependencies.emplace(name, (output_dir / name).string());
        visiting.erase(name);
        built.insert(name);
    };
    for (const auto& [name, roots] : packages) build(build, name);
    args.dependencies.assign(dependencies.begin(), dependencies.end());
    args.dir.clear();
    args.files = {root->file};
    for (const auto& module : host) if (module != root->name) args.files.push_back(sources.at(module)->file);
}

int generate(Args args) {
    UAST::main modules;
    std::vector<std::string> source_files;
    if (args.no_dep) generateDependencies(args);
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

    Modules::Project module_project;
    try {
        std::map<std::string, std::string> resolve;
        for (const auto& [name, path] : args.dependencies)
            if (!resolve.emplace(name, path).second) throw std::runtime_error("Duplicate --dep binding: " + name);
        module_project = Modules::preprocess(args.dir, args.files, resolve);
        if (args.dependency_build) {
            module_project.root.reset();
            // A library module can export rules without declaring a default
            // entry. The generated parser class still needs an internal main.
            if (!module_project.entry) {
                for (const auto& source : module_project.sources) {
                    if (source.declarations.empty()) continue;
                    auto relative = source.entry.value_or(source.declarations.begin()->first);
                    auto entry = source.name;
                    entry.insert(entry.end(), relative.begin(), relative.end());
                    module_project.entry = std::move(entry);
                    if (source.entry) break;
                }
            }
        }
    } catch (const std::exception& error) {
        cpuf::printf("{}\n", error.what());
        return 1;
    }
    for (const auto& source : module_project.sources) {
        cpuf::printf("file: {}\n", source.file);
        IspaParser parser;
        const auto print_errors = [&] {
            for (const auto& e : parser.getErrors()) {
                const auto offset = std::min(e.offset, source.grammar.size());
                std::size_t line = 1, column = 1;
                for (std::size_t i = 0; i < offset; ++i) {
                    if (source.grammar[i] == '\n') { ++line; column = 1; }
                    else ++column;
                }
                cpuf::printf("{}:{}:{}: {}\n", source.file, line, column, e.message);
            }
            for (const auto& e : parser.getContextErrors())
                cpuf::printf("[{}] {}\n", source.file, e.message);
        };
        decltype(&parser.parse(source.grammar.c_str()).value.data()) syntax = nullptr;
        try {
            syntax = &parser.parse(source.grammar.c_str()).value.data();
        } catch (const std::exception& error) {
            print_errors();
            if (parser.getErrors().empty() && parser.getContextErrors().empty())
                cpuf::printf("{}: {}\n", source.file, error.what());
            return 1;
        }
        print_errors();
        if (!parser.getErrors().empty() || !parser.getContextErrors().empty()) return 1;
        modules.value.insert(modules.value.end(), syntax->value.begin(), syntax->value.end());
        source_files.insert(source_files.end(), syntax->value.size(), source.file);
    }

    if (dumper.shouldDump("NFA"))
        std::ofstream(dumper.makeDumpPath("NFA"), std::ios::trunc);
    if (dumper.shouldDump("DFA"))
        std::ofstream(dumper.makeDumpPath("DFA"), std::ios::trunc);

    AST::Builder ast_builder(modules);
    ast_builder.setSourceFiles(std::move(source_files));
    ast_builder.setModules(module_project);
    ast_builder.build();
    auto ast = ast_builder.get();
    AST::requireCppSupport(ast, args.algorithm == Args::Algorithm::LL);

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
    if (!ast.getName().empty() && !args.dependency_build) {
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

    const auto manifest_path = dir_path / (".codegen-manifest." + name);
    const auto previous_hashes = loadKeyHashMap(manifest_path);
    auto generated = converter.get();
    if (args.algorithm == Args::Algorithm::LL) {
        auto exports = External::exports(ast, module_project, name);
        for (auto& [file, code] : exports) {
            auto target = std::ranges::find_if(generated, [&](const auto& item) { return item.first == file; });
            if (target == generated.end()) generated.emplace_back(std::move(file), std::move(code));
            else target->second += code;
        }
    }
    const auto result = writeGeneratedFiles(dir_path, generated, previous_hashes);

    saveKeyHashMap(manifest_path, result.hashes);
    Algorithm::saveMetadata(cache_dir / "data", metadata);
    saveKeyHashMap(rule_manifest_path, new_rule_hashes);

    std::cout << "Updated " << result.updated << " file(s)\n";
    return 0;
}

int main(int argc, char** argv) {
    try { return generate(init(argc, argv)); }
    catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
