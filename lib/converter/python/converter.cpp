module Python.Init;

import std;

namespace Python {
namespace {
    std::string trim(const std::string& text) {
        const auto b = text.find_first_not_of(" \t\r\n");
        if (b == std::string::npos) return {};
        const auto e = text.find_last_not_of(" \t\r\n");
        return text.substr(b, e - b + 1);
    }
    std::vector<std::string> split_path(const std::string& value) {
        std::vector<std::string> out;
        std::size_t begin = 0;
        while (begin <= value.size()) {
            const auto p = value.find('.', begin);
            out.push_back(value.substr(begin, p == std::string::npos ? p : p - begin));
            if (p == std::string::npos) break;
            begin = p + 1;
        }
        return out;
    }
    bool is_break(const LangAPI::Statement& s) {
        if (!s.isExpression()) return false;
        const auto& e = s.getExpression();
        return e.size() == 1 && e.front().type() == LangAPI::ExpressionValueType::Break;
    }
    std::string indent(const std::string& source, unsigned levels) {
        std::string out;
        std::istringstream in(source);
        std::string row;
        while (std::getline(in, row)) out += std::string(levels * 4, ' ') + row + '\n';
        return out;
    }
}
Construct::Construct(const LangAPI::Declarations* src, const char* name, bool incremental)
    : ConstructBase(src, name, incremental), core_(name) {
    core_.set_statement_writer([this](const LangAPI::Statements& s) {
        return statements_inline(s);
    });
}
void Construct::line(const std::string& text) {
    output_ += std::string(indentation_ * 4, ' ') + text + '\n';
}
void Construct::emit_pending_lambdas() {
    // Hoisted functions stay in the lexical suite which owns their captures.
    // Drain recursively because a lambda body may itself contain a lambda.
    for (const auto& lambda : core_.take_pending_lambdas()) {
        line("def " + lambda.name + "(" + lambda.params + "):");
        ++indentation_;
        bool wrote = false;
        std::istringstream lines(lambda.body);
        std::string row;
        while (std::getline(lines, row)) {
            // lambda.body already contains indentation relative to the body.
            line(row);
            wrote = true;
        }
        if (!wrote) line("pass");
        --indentation_;
    }
}
void Construct::comment(const std::string& value) {
    std::istringstream in(value);
    std::string part;
    while (std::getline(in, part)) line("# " + part);
}
std::string Construct::statements_inline(const LangAPI::Statements& s) {
    auto saved_output = std::move(output_);
    const auto saved_indentation = indentation_;
    // Lambdas queued by the enclosing expression must not be flushed into this body.
    auto saved_lambdas = core_.take_pending_lambdas();
    output_.clear();
    indentation_ = 0;
    statements(s);
    auto result = std::move(output_);
    output_ = std::move(saved_output);
    indentation_ = saved_indentation;
    core_.restore_pending_lambdas(std::move(saved_lambdas));
    return result;
}
void Construct::statements(const LangAPI::Statements& s) {
    for (const auto& statement_ : s) statement(statement_);
}
void Construct::body_or_pass(const LangAPI::Statements& s) {
    if (s.empty()) line("pass");
    else statements(s);
}
void Construct::if_stmt(const LangAPI::If& value) { if_chain(value, false); }
void Construct::if_chain(const LangAPI::If& value, bool elif) {
    // `else: if` towers hit Python's 100-level indentation limit on long chains: flatten to elif.
    auto expression = core_.expression(value.expr);
    bool nested = false;
    if (elif && core_.has_pending_lambdas()) {
        // A hoisted def cannot sit between `if` and `elif`; fall back to a nested if here.
        line("else:");
        ++indentation_;
        nested = true;
        elif = false;
    }
    if (!elif) emit_pending_lambdas();
    line(std::string(elif ? "elif " : "if ") + expression + ":");
    ++indentation_;
    body_or_pass(value.stmt);
    --indentation_;
    const auto& other = value.else_stmt;
    if (!other.empty()) {
        auto it = other.begin();
        if (std::next(it) == other.end() && it->isIf()) {
            if_chain(it->getIf(), true);
        } else {
            line("else:");
            ++indentation_;
            statements(other);
            --indentation_;
        }
    }
    if (nested) --indentation_;
}
void Construct::while_stmt(const LangAPI::While& value) {
    auto expression = core_.expression(value.expr);
    emit_pending_lambdas();
    line("while " + expression + ":");
    ++indentation_;
    body_or_pass(value.stmt);
    --indentation_;
}
void Construct::do_while_stmt(const LangAPI::DoWhile& value) {
    line("while True:");
    ++indentation_;
    statements(value.stmt);
    auto expression = core_.expression(value.expr);
    emit_pending_lambdas();
    line("if not (" + expression + "):");
    ++indentation_;
    line("break");
    --indentation_;
    --indentation_;
}
void Construct::switch_body(const LangAPI::Statements& s) {
    // A trailing C++ `break` ends the case; in an if/elif chain it would be a SyntaxError
    // (or would exit an enclosing loop), so it is dropped.
    std::vector<const LangAPI::Statement*> items;
    for (const auto& st : s) items.push_back(&st);
    if (!items.empty() && is_break(*items.back())) items.pop_back();
    if (items.empty()) line("pass");
    for (const auto* st : items) statement(*st);
}
void Construct::switch_stmt(const LangAPI::Switch& value) {
    // if/elif chains preserve the semantics of C++ switch in early Python 3.10.
    // The scrutinee is evaluated once, not once for each case.
    const auto temp = "_ispa_switch_" + std::to_string(++switch_counter_);
    auto scrutinee = core_.expression(value.expression);
    emit_pending_lambdas();
    line(temp + " = " + scrutinee);
    bool first = true;
    std::vector<std::string> tests;  // empty-bodied cases fall through into the next body
    const auto emit_case = [&](const LangAPI::Statements* body) {
        std::string condition;
        if (tests.size() == 1) condition = temp + " == " + tests.front();
        else {
            condition = temp + " in (";
            for (const auto& t : tests) condition += t + ", ";
            condition += ")";
        }
        line(std::string(first ? "if " : "elif ") + condition + ":");
        ++indentation_;
        if (body) switch_body(*body); else line("pass");
        --indentation_;
        first = false;
        tests.clear();
    };
    for (const auto& entry : value.cases) {
        auto test_value = core_.value(entry.first);
        emit_pending_lambdas();
        tests.push_back(std::move(test_value));
        if (entry.second.empty()) continue;
        emit_case(&entry.second);
    }
    if (!tests.empty()) emit_case(nullptr);
}
void Construct::statement(const LangAPI::Statement& stmt) {
    if (stmt.isExpression()) {
        const std::string expr = trim(core_.statement_expression(stmt.getExpression()));
        emit_pending_lambdas();
        if (!expr.empty()) line(expr);
    } else if (stmt.isIf()) if_stmt(stmt.getIf());
    else if (stmt.isWhile()) while_stmt(stmt.getWhile());
    else if (stmt.isDoWhile()) do_while_stmt(stmt.getDoWhile());
    else if (stmt.isSwitch()) switch_stmt(stmt.getSwitch());
    else if (stmt.isThrow()) {
        const auto expression = core_.expression(stmt.getThrow().throw_value);
        emit_pending_lambdas();
        line("raise " + expression);
    }
    else if (stmt.isComment()) comment(stmt.getComment().value);
    else if (stmt.isVariable()) variable(stmt.getVariable());
    else throw std::runtime_error("Python target: unsupported statement kind");
}
void Construct::variable(const LangAPI::Variable& var) {
    // Non-static C++ class fields are instance-specific. Class emission initializes
    // them from __init__ instead of creating shared class attributes here.
    if (class_context_ && !inside_function_ && !var.is_static) return;
    const bool default_init = var.value.empty() ||
        (var.value.size() == 1 && var.value.front().type() == LangAPI::ExpressionValueType::EmptyInitializer);
    std::string rhs;
    if (!default_init) rhs = core_.expression(var.value);
    else if (var.name == "match_result") rhs = "ispa_std.MatchResult()";
    else if (var.type.isSymbol() || var.type.isIspaLibSymbol()) rhs = core_.type(var.type) + "()";
    else if (var.type.isValueType()) {
        using V = LangAPI::ValueType;
        switch (var.type.getValueType()) {
            case V::Array: case V::FixedSizeArray: case V::Span: rhs = "[]"; break;
            case V::Map: rhs = "{}"; break;
            case V::Bool: rhs = "False"; break;
            case V::Int: case V::LargeUInt: rhs = "0"; break;
            default: rhs = "None"; break;
        }
    } else rhs = "None";
    if (class_context_ && !inside_function_ && var.is_static &&
        rhs.starts_with(Core::identifier(namespace_name) + ".FlatTypes.")) {
        deferred_aliases_.emplace_back(current_scope_ + "." + Core::identifier(var.name), rhs);
        return;
    }
    emit_pending_lambdas();
    line(Core::identifier(var.name) + " = " + rhs);
}
void Construct::alias(const LangAPI::TypeAlias& value) {
    if (!value.template_parameters.empty())
        comment("Generic alias type parameters erased on Python target");
    const auto rhs = core_.type(value.type);
    if (class_context_ && rhs.starts_with(Core::identifier(namespace_name) + ".FlatTypes.")) {
        deferred_aliases_.emplace_back(current_scope_ + "." + Core::identifier(value.name), rhs);
        return;
    }
    line(Core::identifier(value.name) + " = " + rhs);
}
void Construct::enumeration(const LangAPI::Enum& value) {
    line("class " + Core::identifier(value.name) + "(enum.IntEnum):");
    ++indentation_;
    if (value.value.empty()) line("pass");
    else {
        std::size_t i = 0;
        for (const auto& el : value.value) {
            line(Core::identifier(el) + " = " + std::to_string(i++));
        }
    }
    --indentation_;
}
void Construct::function(const LangAPI::Function& fn, bool ctor) {
    std::string name = ctor ? "__init__" : Core::identifier(fn.name);
    if (name == "operator<<") return; // C++ output operator maps to __str__ separately.
    // Namespace functions are static; class methods are instance-bound unless declared static.
    if (!ctor) {
        if (class_context_ && fn.is_static) line("@staticmethod");
        else if (namespace_context_ && !class_context_) line("@staticmethod");
        if (!overloaded_scopes_.empty() && overloaded_scopes_.back().contains(fn.name))
            line("@ispa_std.overload");  // dispatch cost is only paid where a name repeats
    }
    std::string args;
    const bool is_method = class_context_ && !fn.is_static;
    if (is_method || ctor) args = "self";
    for (const auto& param : fn.parameters) {
        if (!args.empty()) args += ", ";
        args += Core::identifier(param.second) + ": " + core_.type(param.first);
    }
    const auto result = ctor ? "" : " -> " + core_.type(fn.type);
    line("def " + name + "(" + args + ")" + result + ":");
    ++indentation_;
    const bool saved_inside_function = inside_function_;
    inside_function_ = true;
    if (is_method || ctor) core_.set_method_members(class_members_);
    bool emitted = false;
    if (ctor) {
        // Initialize every non-static member before custom constructor statements.
        // __init__ never shares mutable default arrays or dictionaries between instances.
        // This prelude is emitted by cls(), not here.
    }
    if (!fn.statements.empty()) {
        statements(fn.statements);
        emitted = true;
    }
    if (!emitted) line("pass");
    inside_function_ = saved_inside_function;
    core_.set_method_members({});
    --indentation_;
}
void Construct::cls(const LangAPI::Class& value) {
    const auto full_name = Core::symbol_path(core_.type(LangAPI::Type{value.name}));
    const auto path = split_path(full_name);
    auto name = path.empty() ? full_name : path.back();
    const bool qualified = path.size() > 1 && !class_context_;
    if (qualified) name = "_ispa_generated_class_" + std::to_string(++hidden_class_counter_);

    std::string bases;
    bool has_lib_base = false;  // Lexer/Parser subclass: its __init__ must chain to the runtime
    for (const auto& inherit : value.inherit_members) {
        if (!bases.empty()) bases += ", ";
        if (const auto* sym = std::get_if<LangAPI::Symbol>(&inherit.second)) {
            bases += Core::symbol_path(core_.type(LangAPI::Type{*sym}));
        } else {
            // ISPA lexer/parser inheritance is a real Python subclass.
            has_lib_base = true;
            bases += core_.type(LangAPI::Type{std::get<LangAPI::IspaLibSymbol>(inherit.second)});
        }
    }
    if (bases.empty()) bases = "object";
    line("class " + name + "(" + bases + "):");
    ++indentation_;
    const bool old_class = class_context_;
    const bool old_ns = namespace_context_;
    class_context_ = true;
    namespace_context_ = false;
    const auto saved_scope = current_scope_;
    current_scope_ = saved_scope.empty() ? name : saved_scope + "." + name;
    const auto saved_members = class_members_;
    class_members_.clear();
    for (const auto& [decl, access] : value.data) {
        if (decl->isVariable()) class_members_.insert(decl->getVariable().name);
        if (decl->isFunction()) class_members_.insert(decl->getFunction().name);
    }
    if (name == "Lexer") {
        class_members_.insert({"tokens", "lookup", "append_token", "source", "set_input"});
    } else if (name == "Parser") {
        class_members_.insert({"lexer", "tree", "errors", "required", "optional", "range", "counted",
            "range_optional", "skip_spaces", "recovery_frame", "recovery_at", "unwinding", "action_result"});
    }

    // Keep instance attributes independent even when initializer is a mutable value.
    std::vector<const LangAPI::Variable*> fields;
    for (const auto& [decl, access] : value.data) {
        if (decl->isVariable() && !decl->getVariable().is_static)
            fields.push_back(&decl->getVariable());
    }
    if (value.constructor || !fields.empty()) {
        if (value.constructor) {
            const auto& ctor = *value.constructor;
            std::string args = "self";
            for (const auto& param : ctor.parameters)
                args += ", " + Core::identifier(param.second) + ": " + core_.type(param.first);
            line("def __init__(" + args + "):");
            ++indentation_;
            // Locals declared in the constructor body are real variables, not class fields.
            const bool saved_inside = inside_function_;
            inside_function_ = true;
            core_.set_method_members(class_members_);
            if (has_lib_base) line("super().__init__()");
            for (const auto* f : fields) {
                const auto init = f->value.empty() ? std::string("None") : core_.expression(f->value);
                emit_pending_lambdas();  // def must precede the line that uses it
                line("self." + Core::identifier(f->name) + " = " + init);
            }
            if (ctor.statements.empty() && fields.empty() && !has_lib_base) line("pass");
            else statements(ctor.statements);
            inside_function_ = saved_inside;
            core_.set_method_members({});
            --indentation_;
        } else {
            // Python has no C++ aggregate initialization: provide both positional
            // and keyword field constructors without sharing mutable defaults.
            std::string params = "self";
            if (has_lib_base) params += ", *args";
            for (const auto* f : fields) params += ", " + Core::identifier(f->name) + " = _ISPA_UNSET";
            if (has_lib_base) params += ", **kwargs";
            line("def __init__(" + params + "):");
            ++indentation_;
            if (has_lib_base) line("super().__init__(*args, **kwargs)");
            core_.set_method_members(class_members_);
            for (const auto* f : fields) {
                const auto field = Core::identifier(f->name);
                const bool empty = f->value.empty() ||
                    (f->value.size() == 1 && f->value.front().type() == LangAPI::ExpressionValueType::EmptyInitializer);
                std::string def = empty ? std::string("None") : core_.expression(f->value);
                if (empty && f->type.isValueType()) {
                    switch (f->type.getValueType()) {
                        case LangAPI::ValueType::Array:
                        case LangAPI::ValueType::FixedSizeArray: def = "[]"; break;
                        case LangAPI::ValueType::Map: def = "{}"; break;
                        default: break;
                    }
                }
                emit_pending_lambdas();
                line("self." + field + " = " + def + " if " + field + " is _ISPA_UNSET else " + field);
            }
            core_.set_method_members({});
            --indentation_;
        }
    }

    bool any = value.constructor.has_value() || !fields.empty();
    {
        std::unordered_set<std::string> seen, repeated;
        for (const auto& [decl, access] : value.data)
            if (decl->isFunction() && !seen.insert(decl->getFunction().name).second)
                repeated.insert(decl->getFunction().name);
        overloaded_scopes_.push_back(std::move(repeated));
    }
    for (const auto& [decl, access] : value.data) {
        if (decl->isVariable() && !decl->getVariable().is_static) continue;
        declaration(*decl);
        any = true;
    }
    if (value.to_str_fun) {
        function(*value.to_str_fun);
        any = true;
    }
    overloaded_scopes_.pop_back();
    if (!any) line("pass");
    namespace_context_ = old_ns;
    class_context_ = old_class;
    class_members_ = saved_members;
    current_scope_ = saved_scope;
    --indentation_;
    if (qualified) {
        std::string target;
        for (std::size_t i = 0; i < path.size(); ++i) {
            if (i) target += ".";
            target += Core::identifier(path[i]);
        }
        deferred_aliases_.emplace_back(target, name);
    }
}
void Construct::ns(const LangAPI::Namespace& value) {
    // The outer C++ namespace is the Python module itself. A class with the
    // same name would hide the module alias and strand its nested declarations.
    if (!namespace_context_ && value.name == namespace_name) {
        declarations(value.declarations);
        return;
    }
    line("class " + Core::identifier(value.name) + ":");
    ++indentation_;
    const auto saved_scope = current_scope_;
    current_scope_ = saved_scope.empty() ? Core::identifier(value.name) : saved_scope + "." + Core::identifier(value.name);
    const bool saved_ns = namespace_context_;
    const bool saved_class = class_context_;
    namespace_context_ = true;
    class_context_ = false;
    if (value.declarations.empty()) line("pass");
    declarations(value.declarations);
    namespace_context_ = saved_ns;
    class_context_ = saved_class;
    current_scope_ = saved_scope;
    --indentation_;
    if (saved_scope.empty() && value.name == "FlatTypes") {
        for (const auto& [target, rhs] : deferred_aliases_) line(target + " = " + rhs);
        deferred_aliases_.clear();
    }
}
void Construct::declaration(const LangAPI::Declaration& d) {
    if (d.isNamespace()) ns(d.getNamespace());
    else if (d.isFunction()) function(d.getFunction());
    else if (d.isClass()) cls(d.getClass());
    else if (d.isEnum()) enumeration(d.getEnum());
    else if (d.isTypeAlias()) alias(d.getTypeAlias());
    else if (d.isVariable()) variable(d.getVariable());
    else if (d.isForwardDeclaredClass()) {
        // A Python name must exist, but its full definition may follow later.
        // Python's first-class classes cannot be forward-declared like C++.
    }
    else throw std::runtime_error("Python target: unsupported declaration");
}
void Construct::declarations(const LangAPI::Declarations& decls) {
    std::unordered_set<std::string> seen, repeated;
    for (const auto& d : decls)
        if (d.isFunction() && !seen.insert(d.getFunction().name).second)
            repeated.insert(d.getFunction().name);
    overloaded_scopes_.push_back(std::move(repeated));
    std::unordered_set<std::string> emitted_namespaces;
    for (const auto& d : decls) {
        if (!d.isNamespace()) {
            declaration(d);
            continue;
        }
        const auto& name = d.getNamespace().name;
        if (!emitted_namespaces.insert(name).second) continue;
        LangAPI::Namespace combined = d.getNamespace();
        for (const auto& other : decls) {
            if (&other == &d || !other.isNamespace() || other.getNamespace().name != name) continue;
            const auto& members = other.getNamespace().declarations;
            combined.declarations.insert(combined.declarations.end(), members.begin(), members.end());
        }
        ns(combined);
    }
    overloaded_scopes_.pop_back();
}
void Construct::construct() {
    output_.clear();
    files_.clear();
    indentation_ = 0;
    deferred_aliases_.clear();
    overloaded_scopes_.clear();
    hidden_class_counter_ = switch_counter_ = 0;
    class_context_ = namespace_context_ = inside_function_ = false;
    line("# Generated by ISPA Python target. Changes will be overwritten.");
    line("from __future__ import annotations");
    line("import enum");
    line("import sys as _sys");
    line("import typing");
    line("import ispa_std");
    line("_ISPA_UNSET = object()");
    line();
    line(Core::identifier(namespace_name) + " = _sys.modules[__name__]");
    line();
    rewritten_source_ = rewriter_.run(*source);
    declarations(rewritten_source_);
    line();
    line("Parser.lexer_type = Lexer");
    line("Parser.parser_ws_type = Types._ispa__WS");
    if (!deferred_aliases_.empty()) {
        line();
        line("# Qualified classes (e.g. Types.rule.STRING) defined after their parents");
        for (const auto& [target, alias_] : deferred_aliases_)
            line(target + " = " + alias_);
    }
    // Python is already module-incremental: avoid generating 800 import fragments.
    // The incremental flag is accepted so the host may use the same C ABI.
    files_.emplace_back(std::string(namespace_name) + ".py", std::move(output_));
}
}

extern "C" auto python_construct(const LangAPI::Declarations* tree, const char* module_name, bool incremental)
    -> Python::Construct* {
    return new Python::Construct(tree, module_name, incremental);
}
extern "C" auto python_construct_finish(Python::Construct* ptr) -> void {
    delete ptr;
}
