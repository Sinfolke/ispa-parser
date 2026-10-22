module Python.Imports;
import UAST.Python;
import Parser.Base;
import std;

namespace Python {
namespace {
namespace py = UAST::py;
[[noreturn]] void fail(const UAST::SourcePosition& p, const std::string& message) {
    throw std::invalid_argument(p.file + ":" + std::to_string(p.line) + ":" +
        std::to_string(p.column) + ": Python import: " + message);
}
// Walk the typed syntax, including nested suites, without reparsing Python text.
template<class T, class Visitor> void walk(T& value, Visitor& visitor) {
    if constexpr (std::is_same_v<T, py::Expr>) visitor.expression(value);
    else if constexpr (std::is_same_v<T, py::Stmt>) visitor.statement(value);
    else if constexpr (requires { std::visit([](auto&) {}, value); }) {
        std::visit([&](auto& item) { walk(item, visitor); }, value);
    } else if constexpr (requires { value.get(); *value; }) {
        if (value) walk(*value, visitor);
    } else if constexpr (requires { value.members(); }) {
        std::apply([&](auto&... items) { (walk(items, visitor), ...); }, value.members());
    } else if constexpr (std::ranges::range<T> && !std::is_same_v<T, std::string>) {
        for (auto& item : value) walk(item, visitor);
    }
}
struct Validate {
    void expression(py::Expr& e) { walk(e.kind, *this); }
    void statement(py::Stmt& s) {
        if (s.get<py::ClassDef>()) fail(s.pos, "classes are not supported");
        if (s.get<py::Import>() || s.get<py::ImportFrom>())
            fail(s.pos, "Python imports inside imported files are not supported");
        walk(s.kind, *this);
    }
};
std::string path(const py::Expr& e) {
    if (auto n = e.get<py::Name>()) return n->id;
    if (auto a = e.get<py::Attribute>(); a && a->value) {
        auto prefix = path(*a->value);
        if (!prefix.empty()) return prefix + "." + a->attr;
    }
    return {};
}
struct Locals {
    std::set<std::string> names;
    void expression(py::Expr& e) {
        if (auto n = e.get<py::Name>(); n && n->ctx == py::ExprContext::Store) names.insert(n->id);
        walk(e.kind, *this);
    }
    void statement(py::Stmt& s) { walk(s.kind, *this); }
};
template<class Bindings> struct Bind {
    const Bindings& bindings;
    std::set<std::string> locals;
    bool reserve_imports = false;
    void expression(py::Expr& e) {
        const auto name = path(e);
        const auto first = name.substr(0, name.find('.'));
        if (!locals.contains(first)) {
            if (auto found = bindings.find(name); found != bindings.end()) {
                if (reserve_imports) if (auto n = e.get<py::Name>(); n && n->ctx != py::ExprContext::Load)
                    fail(e.pos, "cannot rebind imported name " + name);
                e.kind = py::Name{found->second.qualified};
                return;
            }
            for (const auto& [binding, target] : bindings)
                if (name == binding.substr(0, binding.find('.')) || name.starts_with(binding.substr(0, binding.find('.')) + "."))
                    fail(e.pos, "unknown imported declaration " + name);
        }
        walk(e.kind, *this);
        if (auto call = e.get<py::Call>(); call && call->func) {
            const auto target = path(*call->func);
            for (const auto& [binding, item] : bindings) if (item.qualified == target) {
                if (!item.arity) fail(e.pos, "imported variable is not callable: " + binding);
                if (!call->keywords.empty() || call->args.size() != *item.arity)
                    fail(e.pos, binding + " expects " + std::to_string(*item.arity) + " positional arguments");
            }
        }
    }
    void statement(py::Stmt& s) {
        if (s.get<py::ClassDef>()) fail(s.pos, "classes are not supported");
        walk(s.kind, *this);
    }
};
void annotation(const py::ExprPtr& e, const UAST::SourcePosition& at, bool returns = false) {
    if (!e) fail(at, "function parameters and returns require type annotations");
    if (auto n = e->get<py::Name>(); n && (n->id == "int" || n->id == "float" || n->id == "bool" || n->id == "str")) return;
    if (returns) if (auto c = e->get<py::Constant>(); c && c->kind == py::ConstantKind::None) return;
    fail(e->pos, "supported types are int, float, bool, str, and None for returns");
}
}

Imports::Imports(const Modules::Project* project) {
    if (project) for (const auto& source : project->sources)
        for (const auto& imp : source.python_imports) load(source, imp);
}
void Imports::load(const Modules::Source& source, const Modules::PythonImport& imp) {
    namespace fs = std::filesystem;
    const auto at = UAST::SourcePosition{imp.position.file, imp.position.offset, 0, imp.position.line, imp.position.column};
    auto file = fs::path(source.file).parent_path();
    for (const auto& part : imp.source) file /= part;
    file += ".py";
    std::error_code error;
    const auto canonical = fs::canonical(file, error);
    if (error || !fs::is_regular_file(canonical)) fail(at, "cannot read " + file.string());
    const auto name = Modules::spelling(imp.source);
    const auto local = imp.alias.empty() ? name : imp.alias;
    if (local == "ctx") fail(at, "ctx is reserved for the action context");
    const auto [alias, inserted] = aliases.emplace(std::make_pair(source.file, local), name);
    if (!inserted && alias->second != name) fail(at, "ambiguous import " + local);
    if (paths.contains(name) && paths.at(name) != canonical)
        fail(at, "module " + name + " resolves to different Python files");
    if (!paths.contains(name)) {
        std::ifstream input(canonical, std::ios::binary);
        if (!input) fail(at, "cannot read " + canonical.string());
        const std::string text(std::istreambuf_iterator<char>{input}, {});
        auto syntax = UAST::parsePythonModule(text, {canonical.string(), 0, text.size(), 1, 1});
        Validate validate;
        walk(syntax, validate);
        Bindings symbols;
        for (const auto& statement : syntax.body) {
            std::string symbol;
            std::optional<std::size_t> arity;
            if (auto f = statement->get<py::FunctionDef>()) {
                symbol = f->name;
                arity = f->params.size();
                annotation(f->returns, statement->pos, true);
                for (const auto& p : f->params) annotation(p.annotation, p.pos);
            } else if (auto a = statement->get<py::AnnAssign>(); a && a->target) {
                if (auto n = a->target->get<py::Name>()) symbol = n->id;
                annotation(a->annotation, statement->pos);
                if (!a->value) fail(statement->pos, "module variables require an initializer");
            } else if (auto a = statement->get<py::Assign>(); a && a->targets.size() == 1 && a->targets[0]) {
                if (auto n = a->targets[0]->get<py::Name>()) symbol = n->id;
            } else if (statement->get<py::Pass>()) continue;
            else if (auto e = statement->get<py::ExprStmt>(); e && e->value) {
                // Plain Python module docstrings do not generate declarations.
                if (auto c = e->value->get<py::Constant>(); c && c->kind == py::ConstantKind::Str) continue;
            }
            if (symbol.empty()) fail(statement->pos, "expected a function or initialized module variable");
            if (!symbols.emplace(symbol, Export{"python." + name + "." + symbol, arity}).second)
                fail(statement->pos, "duplicate declaration " + symbol);
        }
        LangAPI::Declarations lowered;
        for (auto& statement : syntax.body) {
            if (auto f = statement->get<py::FunctionDef>()) {
                Locals local;
                for (const auto& p : f->params) local.names.insert(p.name);
                walk(f->body, local);
                Bind bind{symbols, std::move(local.names)};
                walk(f->body, bind);
            } else if (auto a = statement->get<py::AnnAssign>()) {
                Bind bind{symbols};
                walk(a->value, bind);
            } else if (auto a = statement->get<py::Assign>()) {
                Bind bind{symbols};
                walk(a->value, bind);
            } else continue;
            auto declaration = Parser::ParserBase::convertPythonDeclaration(*statement);
            if (declaration.isFunction() && declaration.getFunction().statements.empty()) {
                auto& function = declaration.getFunction();
                if (function.type != LangAPI::ValueType::Void)
                    fail(statement->pos, "a non-None function requires an executable body");
                function.statements.push_back(LangAPI::Return::createStatement(LangAPI::Return{}));
            }
            if (declaration.isVariable() && declaration.getVariable().type == LangAPI::ValueType::Undef) {
                const auto* assignment = statement->get<py::Assign>();
                const auto* literal = assignment && assignment->value ? assignment->value->get<py::Constant>() : nullptr;
                if (!literal) fail(statement->pos, "nonliteral module variables require a type annotation");
                auto& type = declaration.getVariable().type;
                switch (literal->kind) {
                    case py::ConstantKind::Int: type = LangAPI::ValueType::Int; break;
                    case py::ConstantKind::Float: type = LangAPI::ValueType::Float; break;
                    case py::ConstantKind::Bool: type = LangAPI::ValueType::Bool; break;
                    case py::ConstantKind::Str: type = LangAPI::ValueType::String; break;
                    default: fail(statement->pos, "module variables require a supported type annotation");
                }
            }
            lowered.push_back(std::move(declaration));
        }
        for (auto it = imp.source.rbegin(); it != imp.source.rend(); ++it) {
            LangAPI::Namespace ns;
            ns.name = *it;
            ns.declarations = std::move(lowered);
            lowered.clear();
            lowered.emplace_back(std::move(ns));
        }
        declarations.insert(declarations.end(), lowered.begin(), lowered.end());
        paths.emplace(name, canonical);
        exports.emplace(name, std::move(symbols));
    }
    auto& bindings = files[source.file];
    for (const auto& [symbol, item] : exports.at(name)) {
        const auto key = local + "." + symbol;
        const auto [found, inserted] = bindings.emplace(key, item);
        if (!inserted && found->second.qualified != item.qualified) fail(at, "ambiguous import " + local);
    }
}
void Imports::bind(py::Expr& expression, const std::string& file) const {
    if (auto found = files.find(file); found != files.end()) {
        Bind bind{found->second, {}, true};
        walk(expression, bind);
    }
}
void Imports::bind(py::Module& module, const std::string& file) const {
    if (auto found = files.find(file); found != files.end()) {
        Bind bind{found->second, {}, true};
        walk(module, bind);
    }
}
}
