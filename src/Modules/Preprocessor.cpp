module;
#include <ispa_dep_scanner/parser.h>
module Modules;
import std;

namespace Modules {
std::string spelling(const Path& path) {
    std::string out;
    for (const auto& part : path) {
        if (!out.empty()) out += ".";
        out += part;
    }
    return out;
}
const Source& Project::source(const std::string& file) const {
    for (const auto& s : sources) if (s.file == file) return s;
    throw std::invalid_argument("Source is not in module project: " + file);
}
namespace {
[[noreturn]] void fail(const Position& p, const std::string& message) {
    throw std::runtime_error(p.file + ":" + std::to_string(p.line) + ":" +
        std::to_string(p.column) + ": " + message);
}
bool identifierStart(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'; }
bool identifierPart(char c) { return identifierStart(c) || (c >= '0' && c <= '9'); }
bool startsWith(const Path& path, const Path& prefix) {
    return path.size() >= prefix.size() && std::equal(prefix.begin(), prefix.end(), path.begin());
}
Path joined(Path a, const Path& b) { a.insert(a.end(), b.begin(), b.end()); return a; }
using Syntax = IspaDependency::Syntax;
using Common = DepParser::Types::modules::common;

template<class T> const T& data(const ISPA_STD::Node<T>& node) { return node.data(); }
template<class T> const T& data(const ISPA_STD::Node<std::shared_ptr<T>>& node) { return *node.data(); }

// A consumer of generated syntax, with no tokenization or grammar decisions.
class SourceSyntax {
    Source& out;
    std::vector<std::size_t> line_starts{0};
    std::vector<IspaDependency::Span> erased;
    bool explicit_module = false;

    Position position(std::size_t offset) const {
        offset = std::min(offset, out.grammar.size());
        const auto line = std::upper_bound(line_starts.begin(), line_starts.end(), offset) - line_starts.begin();
        return {out.file, offset, static_cast<std::size_t>(line), offset - line_starts[line - 1] + 1};
    }
    template<class T> Position position(const ISPA_STD::Node<T>& token) const {
        return position(token.startpos());
    }
    template<class Begin, class End> void erase(const Begin& begin, const End& end) {
        const auto finish = end.startpos() + end.length();
        if (begin.startpos() > finish || finish > out.grammar.size())
            throw std::runtime_error("invalid generated directive span");
        erased.push_back({begin.startpos(), finish - begin.startpos()});
        out.has_directives = true;
    }
    Path path(const Syntax::module_path& value) const {
        Path result{data(value.primary).value};
        for (const auto& part : value.nested) result.push_back(data(part).value);
        return result;
    }
    Path path(const Common::name<Common::rule_params>& value) const {
        Path result{data(value.primary).value};
        for (const auto& part : value.nested) result.push_back(data(part).value);
        return result;
    }
    Path path(const Syntax::source_name& value) const {
        return path(data(value.value));
    }
    Position namePosition(const Common::name<Common::rule_params>& value) const { return position(value.primary); }
    Position namePosition(const Syntax::source_name& value) const {
        return namePosition(data(value.value));
    }
    void visit(const Syntax::mod_module& value) {
        const auto at = position(value.begin);
        if (explicit_module) fail(at, "duplicate module declaration");
        explicit_module = true;
        if (!value.parameters.empty()) fail(at, "generic module parameters are not supported by preprocessing yet");
        out.name = path(data(value.name));
        if (!value.entry.empty()) out.entry = path(data(value.entry));
        erase(value.begin, value.end);
    }
    void visit(const Syntax::mod_import& value) {
        Import imp;
        imp.position = position(value.begin);
        if (!value.external.empty()) imp.external = data(data(value.external).value).value;
        std::visit([&](const auto& node) {
            using T = std::decay_t<decltype(node)>;
            if constexpr (!std::is_same_v<T, std::monostate>) {
                const auto& import = data(node);
                using D = std::decay_t<decltype(import)>;
                imp.source = path(data(import.source));
                if constexpr (std::is_same_v<D, Syntax::mod_import::import_value::module_import>) {
                    if (!import.alias.empty()) imp.alias = data(import.alias).value;
                } else {
                    std::visit([&](const auto& selection) {
                        using S = std::decay_t<decltype(selection)>;
                        if constexpr (!std::is_same_v<S, std::monostate>) {
                            using D = std::decay_t<decltype(data(selection))>;
                            if constexpr (std::is_same_v<D, Syntax::mod_import::import_value::from_import::selection::items>) {
                                imp.kind = Import::Kind::Selected;
                                imp.symbols.push_back(path(data(data(selection).first)));
                                for (const auto& item : data(selection).sequence) imp.symbols.push_back(path(data(item)));
                            } else imp.kind = Import::Kind::All;
                        }
                    }, data(import.sel).value);
                }
            }
        }, data(value.value).value);
        out.imports.push_back(std::move(imp));
        erase(value.begin, value.end);
    }
    void visit(const Syntax::mod_python_import& value) {
        PythonImport imp;
        imp.position = position(value.begin);
        imp.source = path(data(value.source));
        if (!value.alias.empty()) imp.alias = data(value.alias).value;
        out.python_imports.push_back(std::move(imp));
        erase(value.begin, value.end);
    }
    void visit(const Syntax::mod_detach& value) {
        Detach detached;
        detached.position = position(value.begin);
        std::visit([&](const auto& node) {
            using T = std::decay_t<decltype(node)>;
            if constexpr (!std::is_same_v<T, std::monostate>) {
                const auto& name = data(node);
                using D = std::decay_t<decltype(name)>;
                if constexpr (std::is_same_v<D, Syntax::source_name>) detached.name = path(name);
                else { detached.feature = true; detached.name = path(data(name.value)); }
            }
        }, data(value.value).value);
        out.detach.push_back(std::move(detached));
        erase(value.begin, value.end);
    }
    void visit(const Syntax::feature_decl& value) {
        std::vector<Path> symbols;
        if (!value.symbols.empty()) {
            const auto& list = data(value.symbols);
            symbols.push_back(path(data(list.first)));
            for (const auto& item : list.following) symbols.push_back(path(data(item)));
        }
        const auto name = path(data(value.name));
        if (!out.features.emplace(name, std::move(symbols)).second)
            fail(position(value.begin), "duplicate feature " + spelling(name));
        erase(value.begin, value.end);
    }
    void declaration(const Syntax::declaration& value, const Path& parent = {}) {
        const auto& form = data(value.value);
        const auto& name = data(form.name);
        const auto full = joined(parent, path(name));
        const auto at = namePosition(name);
        if (!out.declarations.emplace(full, at).second) fail(at, "duplicate rule " + spelling(full));
        std::visit([&](const auto& node) {
            using T = std::decay_t<decltype(node)>;
            if constexpr (!std::is_same_v<T, std::monostate>) {
                using D = std::decay_t<decltype(data(node))>;
                if constexpr (std::is_same_v<D, Syntax::body::regular>)
                    for (const auto& item : data(node).value) member(data(item), full);
            }
        }, data(form.body).value);
    }
    void member(const Syntax::member& value, const Path& parent) {
        std::visit([&](const auto& node) {
            using T = std::decay_t<decltype(node)>;
            if constexpr (!std::is_same_v<T, std::monostate>) {
                using D = std::decay_t<decltype(data(node))>;
                if constexpr (std::is_same_v<D, Syntax::nested_rule>) declaration(data(data(node).value), parent);
            }
        }, value.value);
    }
public:
    explicit SourceSyntax(Source& source) : out(source) {
        for (std::size_t j = 0; j < out.grammar.size(); ++j)
            if (out.grammar[j] == '\n') line_starts.push_back(j + 1);
    }
    void run() {
        IspaDepParser parser;
        try {
            const auto& syntax = parser.parse(out.grammar.c_str()).value.data();
            for (const auto& entry : syntax.value) std::visit([&](const auto& node) {
                using T = std::decay_t<decltype(node)>;
                if constexpr (!std::is_same_v<T, std::monostate>) {
                    using D = std::decay_t<decltype(data(node))>;
                    if constexpr (std::is_same_v<D, Syntax::declaration>) declaration(data(node));
                    else if constexpr (requires { data(node).begin; }) visit(data(node));
                }
            }, entry);
        } catch (const std::exception& error) {
            // Semantic diagnostics already carry their source label.
            if (std::string_view(error.what()).starts_with(out.file + ":")) throw;
            fail(position(parser.offset), error.what());
        }
        erased.insert(erased.end(), parser.comments.begin(), parser.comments.end());
        for (const auto& span : erased)
            for (auto i = span.offset; i < span.offset + span.length; ++i)
                if (out.grammar[i] != '\n' && out.grammar[i] != '\r') out.grammar[i] = ' ';
    }
};
}

Project discover(const std::vector<std::string>& directories, const std::vector<std::string>& files) {
    namespace fs = std::filesystem;
    Project project;
    std::map<fs::path, fs::path> discovered;
    for (const auto& directory : directories) {
        auto root = fs::canonical(directory);
        if (!fs::is_directory(root)) throw std::runtime_error("Not a module directory: " + directory);
        std::vector<fs::path> paths;
        for (const auto& item : fs::recursive_directory_iterator(root))
            if (item.is_regular_file() && item.path().extension() == ".isc") paths.push_back(fs::canonical(item.path()));
        std::sort(paths.begin(), paths.end());
        for (const auto& file : paths) discovered.try_emplace(file, file.lexically_relative(root));
    }
    for (const auto& input : files) {
        auto file = fs::canonical(input);
        if (!fs::is_regular_file(file)) throw std::runtime_error("Not a module source file: " + input);
        discovered.try_emplace(file, file.filename());
    }
    for (auto& [file, relative] : discovered) {
        Source source;
        source.file = file.string();
        auto module_path = relative;
        module_path.replace_extension();
        for (const auto& component : module_path) source.name.push_back(component.string());
        std::ifstream in(file, std::ios::binary);
        if (!in) throw std::runtime_error("Cannot read module: " + file.string());
        source.grammar.assign(std::istreambuf_iterator<char>(in), {});
        SourceSyntax(source).run();
        project.modular |= source.has_directives;
        project.sources.push_back(std::move(source));
    }
    return project;
}

Project preprocess(const std::vector<std::string>& directories, const std::vector<std::string>& files,
                   const std::map<std::string, std::string>& resolve) {
    namespace fs = std::filesystem;
    auto project = discover(directories, files);
    // Preserve the shared scope used by existing split grammars that contain
    // no module directives at all.
    if (!project.modular) return project;
    const Source* root = nullptr;
    if (!files.empty()) root = &project.source(fs::canonical(files.front()).string());
    else {
        for (const auto& source : project.sources)
            if (source.name == Path{"main"}) { root = &source; break; }
        if (!root) for (const auto& source : project.sources) {
            if (source.entry || source.declarations.contains(Path{"main"})) {
                if (root) throw std::runtime_error("Multiple module entries; specify the root source file explicitly");
                root = &source;
            }
        }
    }
    if (!root && project.sources.size() == 1) root = &project.sources.front();
    if (root) {
        project.root = root->name;
        auto entry = root->entry;
        if (!entry && root->declarations.contains(Path{"main"})) entry = Path{"main"};
        if (entry) project.entry = joined(root->name, *entry);
    }
    if (root) {
        // Directory discovery makes modules available; only imported modules
        // (and explicit inputs) need their external dependencies resolved.
        std::set<Path> needed;
        auto include = [&](auto& self, const Source& source) -> void {
            if (!needed.insert(source.name).second) return;
            for (const auto& imp : source.imports) {
                if (!imp.external.empty()) continue;
                for (const auto& candidate : project.sources)
                    if (candidate.name == imp.source) self(self, candidate);
            }
        };
        include(include, *root);
        for (const auto& file : files) include(include, project.source(fs::canonical(file).string()));
        std::erase_if(project.sources, [&](const Source& source) { return !needed.contains(source.name); });
    }
    std::map<Path, std::size_t> modules;
    for (std::size_t index = 0; index < project.sources.size(); ++index) {
        auto& source = project.sources[index];
        for (const auto& part : source.name)
            if (part.empty() || !identifierStart(part[0]) || !std::ranges::all_of(part, identifierPart))
                fail({source.file}, "module path is not an identifier: " + spelling(source.name));
        if (!modules.emplace(source.name, index).second)
            fail({source.file}, "duplicate module " + spelling(source.name));
        if (source.entry && !source.declarations.contains(*source.entry))
            fail({source.file}, "module entry does not exist: " + spelling(*source.entry));
        for (auto& [name, pos] : source.declarations)
            source.resolved_symbols.emplace(name, joined(source.name, name));
    }
    std::map<Path, std::string> declarations;
    for (const auto& source : project.sources) for (const auto& [name, position] : source.declarations) {
        auto full = joined(source.name, name);
        if (!declarations.emplace(full, source.file).second)
            fail(position, "module and nested rule paths collide: " + spelling(full));
    }
    auto bind = [](Source& source, const Path& local, const Path& canonical, const Position& p) {
        const auto [it, inserted] = source.resolved_symbols.emplace(local, canonical);
        if (!inserted && it->second != canonical) fail(p, "ambiguous imported symbol " + spelling(local));
    };
    auto bind_feature = [](Source& source, const Path& local, const std::vector<Path>& symbols, const Position& p) {
        const auto [it, inserted] = source.allowed_features.emplace(local, symbols);
        if (!inserted && it->second != symbols) fail(p, "ambiguous imported feature " + spelling(local));
    };
    auto prefix = [](const Import& imp) -> Path {
        return imp.kind == Import::Kind::Qualified ? (imp.alias.empty() ? imp.source : Path{imp.alias}) : Path{};
    };
    auto selected = [](const Import& imp, const Path& name) {
        return imp.kind != Import::Kind::Selected || std::ranges::any_of(imp.symbols,
            [&](const Path& item) { return startsWith(name, item); });
    };
    std::map<std::string, ExternalPackage> packages;
    std::map<std::pair<std::string, Path>, Path> external_names;
    // Every module's declarations are already registered. Bind imports without
    // traversing dependency edges: mutually recursive rules need no build order.
    for (auto& source : project.sources) {
        for (const auto& imp : source.imports) {
            if (!imp.external.empty()) {
                if (!resolve.contains(imp.external)) fail(imp.position, "external parser needs --dep " + imp.external + " OUTPUT_PREFIX (or --no-dep with its grammar sources)");
                if (!packages.contains(imp.external)) packages.emplace(imp.external, readExternal(resolve.at(imp.external)));
                const auto& package = packages.at(imp.external);
                const auto found = package.find(imp.source);
                if (found == package.end()) fail(imp.position, "external module not exported: " + spelling(imp.source));
                const auto& target = found->second;
                for (const auto& symbol : imp.symbols)
                    if (!target.symbols.contains(symbol)) fail(imp.position, "external symbol not exported: " + spelling(symbol));
                auto canonical = [&](const Path& symbol) {
                    const auto key = std::make_pair(imp.external, joined(imp.source, symbol));
                    if (!external_names.contains(key)) {
                        Path name{"__external", imp.external, "symbol_" + std::to_string(external_names.size())};
                        project.external_symbols.emplace(name, target.symbols.at(symbol));
                        external_names.emplace(key, std::move(name));
                    }
                    return external_names.at(key);
                };
                for (const auto& [name, symbol] : target.symbols)
                    if (selected(imp, name)) bind(source, joined(prefix(imp), name), canonical(name), imp.position);
                if (imp.kind == Import::Kind::Qualified && target.entry)
                    bind(source, prefix(imp), canonical(*target.entry), imp.position);
                continue;
            }
            auto found = modules.find(imp.source);
            if (found == modules.end()) fail(imp.position, "module not found: " + spelling(imp.source));
            const auto& target = project.sources[found->second];
            if (imp.kind == Import::Kind::Selected) {
                for (const auto& symbol : imp.symbols)
                    if (!target.declarations.contains(symbol) && !target.features.contains(symbol))
                        fail(imp.position, "symbol not declared by " + spelling(target.name) + ": " + spelling(symbol));
            }
            for (const auto& [name, pos] : target.declarations)
                if (selected(imp, name)) bind(source, joined(prefix(imp), name), joined(target.name, name), imp.position);
            if (imp.kind == Import::Kind::Qualified) {
                auto entry = target.entry;
                if (!entry && target.declarations.contains(Path{"main"})) entry = Path{"main"};
                if (entry) bind(source, prefix(imp), joined(target.name, *entry), imp.position);
            }
        }
    }
    // Features contain symbol paths, so their definitions can be resolved once
    // all rule bindings exist, before importing any feature values.
    for (auto& source : project.sources) {
        for (const auto& [name, symbols] : source.features) {
            std::vector<Path> canonical;
            for (const auto& symbol : symbols) {
                auto found = source.resolved_symbols.find(symbol);
                if (found == source.resolved_symbols.end()) fail({source.file}, "unknown feature symbol " + spelling(symbol));
                canonical.push_back(found->second);
            }
            bind_feature(source, name, canonical, Position{source.file});
        }
    }
    for (auto& source : project.sources) {
        for (const auto& imp : source.imports) {
            if (!imp.external.empty()) continue;
            const auto& target = project.sources[modules.at(imp.source)];
            for (const auto& [name, symbols] : target.features)
                if (selected(imp, name)) bind_feature(source, joined(prefix(imp), name), target.allowed_features.at(name), imp.position);
        }
        for (const auto& detached : source.detach) {
            if (detached.feature) {
                const auto found = source.allowed_features.find(detached.name);
                if (found == source.allowed_features.end()) fail(detached.position, "unknown feature " + spelling(detached.name));
                source.detached_symbols.insert(found->second.begin(), found->second.end());
            } else {
                const auto found = source.resolved_symbols.find(detached.name);
                if (found == source.resolved_symbols.end()) fail(detached.position, "unknown detached symbol " + spelling(detached.name));
                source.detached_symbols.insert(found->second);
            }
        }
        source.allowed_symbols = source.resolved_symbols;
        std::erase_if(source.allowed_symbols, [&](const auto& binding) {
            return std::ranges::any_of(source.detached_symbols, [&](const Path& removed) { return startsWith(binding.second, removed); });
        });
    }
    return project;
}
}
