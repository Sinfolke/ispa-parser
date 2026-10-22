module Parser.Base;
import UAST.PyAST;
import std;

namespace Parser {
namespace {
namespace py = UAST::py;
namespace la = LangAPI;
// Dots occur only in synthetic names bound by Python.Imports. Keep namespace
// paths in the language-neutral symbol rather than embedding C++ spelling.
la::Symbol pythonSymbol(const std::string& name) {
    la::Symbol result;
    std::size_t begin = 0;
    do {
        const auto end = name.find('.', begin);
        result.path.emplace_back(name.substr(begin, end - begin));
        if (end == std::string::npos) break;
        begin = end + 1;
    } while (true);
    return result;
}
[[noreturn]] void unsupported(const UAST::SourcePosition& p, std::string_view what) {
    throw std::invalid_argument(p.file + ":" + std::to_string(p.line) + ":" +
        std::to_string(p.column) + ": Python conversion: " + std::string(what));
}
struct PythonConverter {
    std::set<std::string> locals;
    bool action_context = false, failure_context = false;
    std::string localName(const std::string& name) const {
        return action_context && locals.contains(name) ? "ispa_action_" + name : name;
    }
    std::size_t block_depth = 0, loop_depth = 0;
    la::Statements nested(const py::StmtList& list, bool loop = false) {
        ++block_depth;
        loop_depth += loop;
        auto out = body(list);
        loop_depth -= loop;
        --block_depth;
        return out;
    }
    la::Expression expr(const py::ExprPtr& p) {
        if (!p) throw std::invalid_argument("Python conversion: missing expression");
        return expr(*p);
    }
    la::Expression group(la::Expression e) {
        e.insert(e.begin(), la::ExpressionElement::GroupOpen);
        e.emplace_back(la::ExpressionElement::GroupClose);
        return e;
    }
    la::Expression binary(la::Expression left, la::ExpressionElement op, la::Expression right) {
        auto out = group(std::move(left));
        out.emplace_back(op);
        auto rhs = group(std::move(right));
        out.insert(out.end(), rhs.begin(), rhs.end());
        return group(std::move(out));
    }
    la::ExpressionElement binop(py::BinOp op, const UAST::SourcePosition& p) {
        switch (op) {
            case py::BinOp::Add: return la::ExpressionElement::Add;
            case py::BinOp::Sub: return la::ExpressionElement::Minus;
            case py::BinOp::Mult: return la::ExpressionElement::Multiply;
            case py::BinOp::Div: return la::ExpressionElement::Divide;
            case py::BinOp::Mod: return la::ExpressionElement::Modulo;
            default: unsupported(p, "operator has no LangAPI representation");
        }
    }
    la::Type type(const py::ExprPtr& p) {
        if (!p) return la::Type{la::ValueType::Undef};
        if (auto n = p->template get<py::Name>()) {
            if (n->id == "int") return la::Type{la::ValueType::Int};
            if (n->id == "float") return la::Type{la::ValueType::Float};
            if (n->id == "bool") return la::Type{la::ValueType::Bool};
            if (n->id == "str") return la::Type{la::ValueType::String};
            return la::Type{la::Symbol{n->id}};
        }
        if (auto c = p->template get<py::Constant>(); c && c->kind == py::ConstantKind::None)
            return la::Type{la::ValueType::Void};
        unsupported(p->pos, "unsupported type annotation");
    }
    std::variant<la::Symbol, la::StorageSymbol> target(const py::ExprPtr& p) {
        if (action_context) {
            const py::Expr* root = p.get();
            const py::Attribute* property = nullptr;
            while (root) {
                if (auto a = root->get<py::Attribute>()) { property = a; root = a->value.get(); }
                else if (auto s = root->get<py::Subscript>()) root = s->value.get();
                else break;
            }
            if (root) if (auto n = root->get<py::Name>(); n && n->id == "ctx") {
                if (!property || (property->attr != "pos" && property->attr != "ast"))
                    unsupported(p->pos, "ctx and its metadata are read-only; only ctx.pos and ctx.ast are writable");
            }
        }
        auto e = expr(p);
        if (e.size() == 1 && e.front().isRvalue()) {
            auto& r = e.front().getRValue();
            if (r.isSymbol()) return r.getSymbol();
            if (r.isStorageSymbol()) return r.getStorageSymbol();
        }
        unsupported(p->pos, "assignment target must be a name, attribute or subscript");
    }
    la::Expression expr(const py::Expr& e) {
        return std::visit([&](const auto& x) -> la::Expression {
            using T = std::decay_t<decltype(x)>;
            if constexpr (std::is_same_v<T, py::Name>) return la::Symbol::createExpression(pythonSymbol(localName(x.id)));
            else if constexpr (std::is_same_v<T, py::Constant>) {
                switch (x.kind) {
                    case py::ConstantKind::Bool: return la::Bool::createExpression(la::Bool{.value = x.value == "True"});
                    case py::ConstantKind::Int: {
                        auto text = x.value;
                        std::erase(text, '_');
                        std::size_t end;
                        int base = 10;
                        if (text.size() > 2 && text[0] == '0') {
                            switch (text[1]) {
                                case 'x': case 'X': base = 16; break;
                                case 'o': case 'O': base = 8; break;
                                case 'b': case 'B': base = 2; break;
                            }
                            if (base != 10) text.erase(0, 2);
                        }
                        long long value;
                        try { value = std::stoll(text, &end, base); }
                        catch (const std::exception&) { unsupported(e.pos, "integer literal is invalid or exceeds LangAPI range"); }
                        if (end != text.size()) unsupported(e.pos, "invalid integer literal");
                        return la::Int::createExpression(la::Int{.value = value});
                    }
                    case py::ConstantKind::Float: {
                        auto text = x.value;
                        std::erase(text, '_');
                        std::size_t end;
                        double value;
                        try { value = std::stod(text, &end); }
                        catch (const std::exception&) { unsupported(e.pos, "float literal is invalid or exceeds LangAPI range"); }
                        if (end != text.size()) unsupported(e.pos, "invalid float literal");
                        return la::Float::createExpression(la::Float{.value = value});
                    }
                    case py::ConstantKind::Str: {
                        // LangAPI strings contain escaped target literal contents.
                        // Preserve Python escapes and protect quotes from single-quoted literals.
                        std::string value;
                        bool escaped = false;
                        for (char c : x.value) {
                            if (c == '"' && !escaped) value += '\\';
                            value += c;
                            if (c == '\\') escaped = !escaped;
                            else escaped = false;
                        }
                        return la::String::createExpression(la::String{.value = value});
                    }
                    default: unsupported(e.pos, "None has no LangAPI value representation");
                }
            } else if constexpr (std::is_same_v<T, py::Attribute> || std::is_same_v<T, py::Subscript>) {
                if constexpr (std::is_same_v<T, py::Attribute>) {
                    if (action_context && x.value) if (auto n = x.value->template get<py::Name>(); n && n->id == "ctx") {
                        if (x.attr != "pos" && x.attr != "ast" && x.attr != "start_pos" && x.attr != "rule" &&
                            !(failure_context && x.attr == "failed_rule"))
                            unsupported(e.pos, "unknown ctx property: " + x.attr);
                    }
                }
                la::StorageSymbol s;
                s.what = group(expr(x.value));
                if constexpr (std::is_same_v<T, py::Attribute>) s.path.emplace_back(x.attr);
                else s.path.emplace_back(la::StorageOffset{.offset = expr(x.slice)});
                return la::StorageSymbol::createExpression(s);
            } else if constexpr (std::is_same_v<T, py::Call>) {
                if (!x.keywords.empty()) unsupported(e.pos, "keyword arguments are unsupported");
                if (action_context) if (auto method = x.func ? x.func->template get<py::Attribute>() : nullptr) {
                    if (auto owner = method->value ? method->value->template get<py::Name>() : nullptr; owner && owner->id == "ctx") {
                        const auto& name = method->attr;
                        const bool argument = name == "error" || name == "at";
                        if (!failure_context || (!argument && name != "sync" && name != "skip" && name != "insert" &&
                            name != "replace" && name != "retry" && name != "abort"))
                            unsupported(e.pos, "unknown context method: " + name);
                        if (name == "sync") {
                            if (x.args.empty()) unsupported(e.pos, "ctx.sync requires at least one boundary");
                            for (const auto& arg : x.args) {
                                auto literal = arg ? arg->template get<py::Constant>() : nullptr;
                                if (!literal || literal->kind != py::ConstantKind::Str || literal->value.empty())
                                    unsupported(e.pos, "ctx.sync boundaries must be nonempty string literals");
                            }
                        } else if (x.args.size() != (argument ? 1u : 0u)) unsupported(e.pos, "wrong argument count for ctx." + name);
                        if (name == "at" && x.args.size() == 1) {
                            // Bare and dotted token names are strings in this API;
                            // ordinary bound variables remain ordinary expressions.
                            std::function<std::string(const py::ExprPtr&)> tokenName = [&](const py::ExprPtr& arg) -> std::string {
                                if (!arg) return {};
                                if (auto n = arg->template get<py::Name>())
                                    return locals.contains(n->id) || n->id == "ctx" ? "" : n->id;
                                if (auto a = arg->template get<py::Attribute>()) {
                                    auto prefix = tokenName(a->value);
                                    return prefix.empty() ? "" : prefix + "." + a->attr;
                                }
                                return {};
                            };
                            const auto token = tokenName(x.args.front());
                            if (!token.empty()) {
                                la::FunctionCall call;
                                call.name = std::make_shared<la::Symbol>("at");
                                call.args = {la::String::createExpression(la::String{.value = token})};
                                la::StorageSymbol storage;
                                storage.what = group(expr(method->value));
                                storage.path.emplace_back(call);
                                return la::StorageSymbol::createExpression(storage);
                            }
                        }
                    }
                }
                la::FunctionCall call;
                for (const auto& a : x.args) call.args.push_back(expr(a));
                if (auto n = x.func ? x.func->template get<py::Name>() : nullptr) {
                    call.name = std::make_shared<la::Symbol>(pythonSymbol(localName(n->id)));
                    return la::FunctionCall::createExpression(call);
                }
                if (auto a = x.func ? x.func->template get<py::Attribute>() : nullptr) {
                    call.name = std::make_shared<la::Symbol>(a->attr);
                    la::StorageSymbol s;
                    s.what = group(expr(a->value));
                    s.path.emplace_back(call);
                    return la::StorageSymbol::createExpression(s);
                }
                unsupported(e.pos, "call target must be a name or method");
            } else if constexpr (std::is_same_v<T, py::BinaryExpr>) return binary(expr(x.left), binop(x.op, e.pos), expr(x.right));
            else if constexpr (std::is_same_v<T, py::UnaryExpr>) {
                la::Expression out;
                switch (x.op) {
                    case py::UnaryOp::Not: out.emplace_back(la::ExpressionElement::Not); break;
                    case py::UnaryOp::UAdd: out.emplace_back(la::ExpressionElement::Add); break;
                    case py::UnaryOp::USub: out.emplace_back(la::ExpressionElement::Minus); break;
                    default: unsupported(e.pos, "bitwise invert is unsupported");
                }
                auto operand = group(expr(x.operand));
                out.insert(out.end(), operand.begin(), operand.end());
                return group(out);
            } else if constexpr (std::is_same_v<T, py::BoolExpr>) {
                if (x.values.empty()) unsupported(e.pos, "empty boolean expression");
                auto out = expr(x.values.front());
                for (std::size_t i = 1; i < x.values.size(); ++i)
                    out = binary(out, x.op == py::BoolOp::And ? la::ExpressionElement::And : la::ExpressionElement::Or, expr(x.values[i]));
                return out;
            } else if constexpr (std::is_same_v<T, py::Compare>) {
                if (x.ops.size() != 1 || x.comparators.size() != 1)
                    unsupported(e.pos, "chained comparison requires single-evaluation lowering");
                la::ExpressionElement op;
                switch (x.ops[0]) {
                    case py::CmpOp::Eq: op = la::ExpressionElement::Equal; break;
                    case py::CmpOp::NotEq: op = la::ExpressionElement::NotEqual; break;
                    case py::CmpOp::Lt: op = la::ExpressionElement::Lower; break;
                    case py::CmpOp::LtE: op = la::ExpressionElement::LowerOrEqual; break;
                    case py::CmpOp::Gt: op = la::ExpressionElement::Higher; break;
                    case py::CmpOp::GtE: op = la::ExpressionElement::HigherOrEqual; break;
                    default: unsupported(e.pos, "identity and membership comparisons are unsupported");
                }
                return binary(expr(x.left), op, expr(x.comparators[0]));
            } else if constexpr (std::is_same_v<T, py::Tuple>) {
                la::MakeTuple out;
                for (auto& item : x.elts) out.args.push_back(expr(item));
                return la::MakeTuple::createExpression(out);
            } else if constexpr (std::is_same_v<T, py::List>) {
                la::Array out;
                for (auto& item : x.elts) out.values.push_back(expr(item));
                return la::Array::createExpression(out);
            } else if constexpr (std::is_same_v<T, py::Dict>) {
                if (x.keys.size() != x.values.size()) unsupported(e.pos, "invalid dictionary");
                la::Map out;
                for (std::size_t i = 0; i < x.keys.size(); ++i) {
                    auto key = expr(x.keys[i]);
                    if (key.size() != 1 || !key.front().isRvalue()) unsupported(e.pos, "dictionary keys must be integer or string literals");
                    const auto& r = key.front().getRValue();
                    if (r.isInt()) out.keys.emplace_back(r.getInt());
                    else if (r.isString()) out.keys.emplace_back(r.getString());
                    else unsupported(e.pos, "dictionary keys must be integer or string literals");
                    out.values.push_back(expr(x.values[i]));
                }
                return la::Map::createExpression(out);
            } else unsupported(e.pos, "conditional expression is unsupported");
        }, e.kind);
    }
    la::Statements body(const py::StmtList& list) {
        la::Statements out;
        for (const auto& p : list) {
            if (!p) throw std::invalid_argument("Python conversion: missing statement");
            auto part = stmt(*p);
            out.insert(out.end(), part.begin(), part.end());
        }
        return out;
    }
    la::Statements stmt(const py::Stmt& s) {
        return std::visit([&](const auto& x) -> la::Statements {
            using T = std::decay_t<decltype(x)>;
            if constexpr (std::is_same_v<T, py::Pass>) return {};
            else if constexpr (std::is_same_v<T, py::ExprStmt>) return la::Statements{la::Statement{expr(x.value)}};
            else if constexpr (std::is_same_v<T, py::Return>) {
                if (!action_context) return la::Return::createStatements(la::Return{.value = x.value ? expr(x.value) : la::Expression{}});
                if (failure_context && x.value) unsupported(s.pos, "fail blocks use a bare return");
                la::FunctionCall call;
                call.name = std::make_shared<la::Symbol>(failure_context ? "custom_failure_decision" : "action_result");
                if (failure_context) call.args = {la::Symbol::createExpression(la::Symbol{"before_failure"}), la::Symbol::createExpression(la::Symbol{"failed_pos"}), la::Symbol::createExpression(la::Symbol{"ctx"})};
                else {
                    la::StorageSymbol ast{"ast"}, pos{"pos"};
                    ast.what = pos.what = la::Symbol::createExpression(la::Symbol{"ctx"});
                    call.args = {x.value ? expr(x.value) : la::StorageSymbol::createExpression(ast), la::StorageSymbol::createExpression(pos)};
                }
                return la::Return::createStatements(la::Return{.value = la::FunctionCall::createExpression(call)});
            }
            else if constexpr (std::is_same_v<T, py::Break>) {
                if (!loop_depth) unsupported(s.pos, "break outside loop");
                return la::Break::createStatements(la::Break{});
            }
            else if constexpr (std::is_same_v<T, py::Continue>) {
                if (!loop_depth) unsupported(s.pos, "continue outside loop");
                return la::Continue::createStatements(la::Continue{});
            }
            else if constexpr (std::is_same_v<T, py::If>) return la::Statements{la::If{expr(x.test), nested(x.body), nested(x.orelse)}};
            else if constexpr (std::is_same_v<T, py::While>) {
                if (!x.orelse.empty()) unsupported(s.pos, "loop else is unsupported");
                return la::Statements{la::While{expr(x.test), nested(x.body, true)}};
            } else if constexpr (std::is_same_v<T, py::Assign>) {
                if (x.targets.size() != 1) unsupported(s.pos, "multiple assignment targets are unsupported");
                auto value = expr(x.value);
                if (auto n = x.targets[0] ? x.targets[0]->template get<py::Name>() : nullptr; n && !locals.contains(n->id)) {
                    if (action_context && n->id == "ctx") unsupported(s.pos, "ctx cannot be rebound");
                    if (block_depth) unsupported(s.pos, "declare local before entering a branch or loop");
                    locals.insert(n->id);
                    return la::Statements{la::Variable{.name = localName(n->id), .type = la::Type{la::ValueType::Undef}, .value = value}};
                }
                return la::VariableAssignment::createStatements(la::VariableAssignment{.name = target(x.targets[0]), .value = value});
            } else if constexpr (std::is_same_v<T, py::AnnAssign>) {
                auto n = x.target ? x.target->template get<py::Name>() : nullptr;
                if (!n && action_context) {
                    const auto destination = target(x.target);
                    if (!x.value) return {};
                    return la::VariableAssignment::createStatements(la::VariableAssignment{.name = destination, .value = expr(x.value)});
                }
                if (!n) unsupported(s.pos, "annotated target must be a name");
                if (action_context && n->id == "ctx") unsupported(s.pos, "ctx cannot be rebound");
                if (block_depth || locals.contains(n->id)) unsupported(s.pos, "annotated declaration must introduce a local outside branches and loops");
                locals.insert(n->id);
                return la::Statements{la::Variable{.name = localName(n->id), .type = type(x.annotation), .value = x.value ? expr(x.value) : la::Expression{}}};
            } else if constexpr (std::is_same_v<T, py::AugAssign>) {
                la::OperatorType op;
                switch (x.op) {
                    case py::BinOp::Add: op = la::OperatorType::Add; break;
                    case py::BinOp::Sub: op = la::OperatorType::Minus; break;
                    case py::BinOp::Mult: op = la::OperatorType::Multiply; break;
                    case py::BinOp::Div: op = la::OperatorType::Divide; break;
                    case py::BinOp::Mod: op = la::OperatorType::Modulo; break;
                    default: unsupported(s.pos, "augmented operator is unsupported");
                }
                return la::VariableAssignment::createStatements(la::VariableAssignment{.name = target(x.target), .type = op, .value = expr(x.value)});
            } else if constexpr (std::is_same_v<T, py::Raise>) {
                if (x.cause) unsupported(s.pos, "raise from is unsupported");
                return la::Statements{la::Throw{.throw_value = x.exc ? expr(x.exc) : la::Expression{}}};
            } else unsupported(s.pos, "statement has no LangAPI representation (use declaration conversion for definitions)");
        }, s.kind);
    }
    la::Declaration declaration(const py::Stmt& s) {
        if (auto f = s.get<py::FunctionDef>()) {
            if (f->is_async || !f->decorators.empty()) unsupported(s.pos, "async functions and decorators are unsupported");
            PythonConverter scope;
            la::Function out;
            out.name = f->name;
            out.type = type(f->returns);
            for (auto& p : f->params) {
                if (p.default_value) unsupported(p.pos, "default parameters are unsupported");
                out.parameters.emplace_back(type(p.annotation), p.name);
                scope.locals.insert(p.name);
            }
            out.statements = scope.body(f->body);
            return la::Declaration{out};
        }
        if (auto c = s.get<py::ClassDef>()) {
            if (!c->decorators.empty() || !c->keywords.empty()) unsupported(s.pos, "class decorators and keywords are unsupported");
            la::Class out;
            out.name = la::Symbol{c->name};
            for (auto& b : c->bases) {
                auto n = b ? b->template get<py::Name>() : nullptr;
                if (!n) unsupported(s.pos, "base class must be a name");
                out.inherit_members.emplace_back(la::Visibility::Public, la::Symbol{n->id});
            }
            PythonConverter scope;
            for (auto& member : c->body) {
                if (!member) unsupported(s.pos, "missing class member");
                if (member->template get<py::Pass>()) continue;
                out.data.emplace_back(std::make_shared<la::Declaration>(scope.declaration(*member)), la::Visibility::Public);
            }
            return la::Declaration{out};
        }
        auto statements = stmt(s);
        if (statements.size() == 1 && statements.front().isVariable()) return la::Declaration{statements.front().getVariable()};
        unsupported(s.pos, "expected a function, class or variable declaration");
    }
};
}
auto ParserBase::convertPython(const UAST::py::Expr& e) -> LangAPI::Expression { return PythonConverter{}.expr(e); }
auto ParserBase::convertPython(const UAST::py::Stmt& s, const std::set<std::string>& variables) -> LangAPI::Statements { return PythonConverter{variables}.stmt(s); }
auto ParserBase::convertPython(const UAST::py::Module& m, const std::set<std::string>& variables) -> LangAPI::Statements { return PythonConverter{variables}.body(m.body); }
auto ParserBase::convertPythonDeclaration(const UAST::py::Stmt& s) -> LangAPI::Declaration { return PythonConverter{}.declaration(s); }
auto ParserBase::convertPythonDeclarations(const UAST::py::Module& m) -> LangAPI::Declarations {
    PythonConverter converter;
    LangAPI::Declarations out;
    for (auto& s : m.body) {
        if (!s) unsupported(m.pos, "missing declaration");
        if (s->template get<UAST::py::Pass>()) continue;
        out.push_back(converter.declaration(*s));
    }
    return out;
}
auto ParserBase::convertPythonAction(const AST::PythonAction& action, std::set<std::string>& variables, bool failure) -> LangAPI::Statements {
    PythonConverter converter{variables, true, failure};
    auto result = std::visit([&](const auto& code) -> LangAPI::Statements {
        using T = std::decay_t<decltype(code)>;
        if constexpr (std::is_same_v<T, UAST::py::Module>) return converter.body(code.body);
        else if constexpr (std::is_same_v<T, UAST::py::Expr>) return {LangAPI::Statement{converter.expr(code)}};
        else throw std::invalid_argument("Python action has no executable syntax");
    }, action.code);
    variables = std::move(converter.locals);
    return result;
}
}
