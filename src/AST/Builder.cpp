module AST.Builder;
import AST.types;
import AST.Tree;
import cpuf.printf;
import corelib;
import logging;
import dstd;
import std;
import UAST.Python;

namespace {
    template<typename T>
    const T& payload(const T& value) {
        return value;
    }

    template<typename T>
    const T& payload(const std::shared_ptr<T>& value) {
        if (!value) {
            throw std::runtime_error("Null parser AST node");
        }
        return *value;
    }

    template<typename T>
    decltype(auto) payload(const UAST::Node<T>& node) {
        return payload(node.data());
    }
    // LR literal captures are characters; the LL bootstrap keeps token nodes.
    char captureMarker(char value) { return value; }
    template<class... T>
    char captureMarker(const std::variant<T...>& value) {
        return std::visit([](const auto& token) -> char {
            using Token = std::decay_t<decltype(token)>;
            if constexpr (std::is_same_v<Token, UAST::Node<UAST::COMMERCIAL_AT>>) return '@';
            else if constexpr (std::is_same_v<Token, UAST::Node<UAST::PERCENT_SIGN>>) return '%';
            else if constexpr (std::is_same_v<Token, char>) return token;
            else throw std::runtime_error("Missing capture marker");
        }, value);
    }
    std::string id(const UAST::Node<UAST::ID>& node) {
        return payload(node).value;
    }
    stdu::vector<std::string> qualifiedName(const UAST::name& n) {
        stdu::vector<std::string> result;
        result.push_back(id(n.primary));
        for (const auto& segment : n.nested) result.push_back(id(segment));
        return result;
    }
    // The generated nodes know offset/length/line/column but not the file name;
    // Builder::build() publishes it here for the duration of the conversion.
    thread_local const std::string* currentFile = nullptr;
    struct FileScope {
        const std::string* previous;
        explicit FileScope(const std::string& file) : previous(currentFile) { currentFile = &file; }
        ~FileScope() { currentFile = previous; }
    };
    template<class T> UAST::SourcePosition where(const UAST::Node<T>& node) {
        static const std::string none;
        return UAST::positionOf(node, currentFile ? *currentFile : none);
    }
    AST::SourcePosition position(const UAST::SourcePosition& p) {
        return {p.file, p.offset, p.length, p.line, p.column};
    }
    template<class T> AST::SourcePosition position(const UAST::Node<T>& node) {
        return position(where(node));
    }
    AST::PythonNode python(const UAST::PythonNode& n) {
        AST::PythonNode out{n.kind, n.field, n.scalar, position(n.position), n.absent, {}};
        for (const auto& child : n.children) out.children.push_back(python(child));
        return out;
    }

    // Typed Python AST (UAST::py) -> AST::PythonNode. Each typed node becomes one
    // PythonNode: kind = node type ("BinaryExpr", "If", ...), children carry the
    // struct's field names, scalar holds the identifier / operator / literal text.
    namespace pylower {
        namespace py = UAST::py;
        using PN = AST::PythonNode;
        using Pos = UAST::SourcePosition;
        constexpr std::string_view kCtx[] = {"Load", "Store", "Del"};
        constexpr std::string_view kBool[] = {"And", "Or"};
        constexpr std::string_view kBin[] = {"Add", "Sub", "Mult", "MatMult", "Div", "Mod", "Pow", "LShift", "RShift", "BitOr", "BitXor", "BitAnd", "FloorDiv"};
        constexpr std::string_view kUnary[] = {"Invert", "Not", "UAdd", "USub"};
        constexpr std::string_view kCmp[] = {"Eq", "NotEq", "Lt", "LtE", "Gt", "GtE", "Is", "IsNot", "In", "NotIn"};
        constexpr std::string_view kConst[] = {"None", "Bool", "Int", "Float", "Str"};
        template<class E> std::string name(const std::string_view* table, E e) { return std::string(table[static_cast<std::size_t>(e)]); }

        inline PN make(std::string kind, std::string field, const Pos& p, std::string scalar = {}, std::vector<PN> children = {}) {
            PN out{std::move(kind), std::move(field), std::move(scalar), position(p), false, {}};
            for (auto& c : children) out.children.push_back(std::move(c));
            return out;
        }
        inline PN absentNode(std::string field, const Pos& p) {
            PN out{"absent", std::move(field), {}, position(p), true, {}};
            return out;
        }

        struct Lower {
            PN expr(const py::ExprPtr& e, std::string f, const Pos& fb) const {
                if (!e) return absentNode(std::move(f), fb);
                return std::visit([&](const auto& k) { return node(k, std::move(f), e->pos); }, e->kind);
            }
            PN stmt(const py::StmtPtr& s, std::string f, const Pos& fb) const {
                if (!s) return absentNode(std::move(f), fb);
                return std::visit([&](const auto& k) { return node(k, std::move(f), s->pos); }, s->kind);
            }
            PN exprs(const std::vector<py::ExprPtr>& v, std::string f, const Pos& p) const {
                std::vector<PN> c; for (const auto& e : v) c.push_back(expr(e, {}, p));
                return make("sequence", std::move(f), p, {}, std::move(c));
            }
            PN stmts(const std::vector<py::StmtPtr>& v, std::string f, const Pos& p) const {
                std::vector<PN> c; for (const auto& s : v) c.push_back(stmt(s, {}, p));
                return make("sequence", std::move(f), p, {}, std::move(c));
            }
            PN keywords(const std::vector<py::Keyword>& v, std::string f, const Pos& p) const {
                std::vector<PN> c;
                for (const auto& k : v) c.push_back(make("keyword", {}, k.pos, k.arg, {expr(k.value, "value", k.pos)}));
                return make("sequence", std::move(f), p, {}, std::move(c));
            }
            PN aliases(const std::vector<py::Alias>& v, std::string f, const Pos& p) const {
                std::vector<PN> c;
                for (const auto& a : v) c.push_back(make("alias", {}, a.pos, a.name, {make("asname", "asname", a.pos, a.asname)}));
                return make("sequence", std::move(f), p, {}, std::move(c));
            }
            PN strings(const std::vector<std::string>& v, std::string f, const Pos& p) const {
                std::vector<PN> c; for (const auto& s : v) c.push_back(make("string", {}, p, s));
                return make("sequence", std::move(f), p, {}, std::move(c));
            }
            PN module(const py::Module& m) const { return make("Module", {}, m.pos, {}, {stmts(m.body, "body", m.pos)}); }

            // expressions
            PN node(const py::Name& x, std::string f, const Pos& p) const { return make("Name", std::move(f), p, x.id, {make("ctx", "ctx", p, name(kCtx, x.ctx))}); }
            PN node(const py::Constant& x, std::string f, const Pos& p) const { return make("Constant", std::move(f), p, x.value, {make("kind", "kind", p, name(kConst, x.kind))}); }
            PN node(const py::Attribute& x, std::string f, const Pos& p) const { return make("Attribute", std::move(f), p, x.attr, {expr(x.value, "value", p), make("ctx", "ctx", p, name(kCtx, x.ctx))}); }
            PN node(const py::Subscript& x, std::string f, const Pos& p) const { return make("Subscript", std::move(f), p, {}, {expr(x.value, "value", p), expr(x.slice, "slice", p), make("ctx", "ctx", p, name(kCtx, x.ctx))}); }
            PN node(const py::Call& x, std::string f, const Pos& p) const { return make("Call", std::move(f), p, {}, {expr(x.func, "func", p), exprs(x.args, "args", p), keywords(x.keywords, "keywords", p)}); }
            PN node(const py::UnaryExpr& x, std::string f, const Pos& p) const { return make("UnaryExpr", std::move(f), p, name(kUnary, x.op), {expr(x.operand, "operand", p)}); }
            PN node(const py::BinaryExpr& x, std::string f, const Pos& p) const { return make("BinaryExpr", std::move(f), p, name(kBin, x.op), {expr(x.left, "left", p), expr(x.right, "right", p)}); }
            PN node(const py::BoolExpr& x, std::string f, const Pos& p) const { return make("BoolExpr", std::move(f), p, name(kBool, x.op), {exprs(x.values, "values", p)}); }
            PN node(const py::Compare& x, std::string f, const Pos& p) const {
                std::vector<PN> ops; for (auto o : x.ops) ops.push_back(make("op", {}, p, name(kCmp, o)));
                return make("Compare", std::move(f), p, {}, {expr(x.left, "left", p), make("sequence", "ops", p, {}, std::move(ops)), exprs(x.comparators, "comparators", p)});
            }
            PN node(const py::IfExpr& x, std::string f, const Pos& p) const { return make("IfExpr", std::move(f), p, {}, {expr(x.test, "test", p), expr(x.body, "body", p), expr(x.orelse, "orelse", p)}); }
            PN node(const py::Tuple& x, std::string f, const Pos& p) const { return make("Tuple", std::move(f), p, {}, {exprs(x.elts, "elts", p), make("ctx", "ctx", p, name(kCtx, x.ctx))}); }
            PN node(const py::List& x, std::string f, const Pos& p) const { return make("List", std::move(f), p, {}, {exprs(x.elts, "elts", p), make("ctx", "ctx", p, name(kCtx, x.ctx))}); }
            PN node(const py::Dict& x, std::string f, const Pos& p) const { return make("Dict", std::move(f), p, {}, {exprs(x.keys, "keys", p), exprs(x.values, "values", p)}); }

            // statements and declarations
            PN node(const py::FunctionDef& x, std::string f, const Pos& p) const {
                std::vector<PN> params;
                for (const auto& a : x.params)
                    params.push_back(make("Param", {}, a.pos, a.name, {expr(a.annotation, "annotation", a.pos), expr(a.default_value, "default_value", a.pos)}));
                return make("FunctionDef", std::move(f), p, x.name, {make("sequence", "params", p, {}, std::move(params)), expr(x.returns, "returns", p),
                    stmts(x.body, "body", p), exprs(x.decorators, "decorators", p), make("bool", "is_async", p, x.is_async ? "true" : "false")});
            }
            PN node(const py::ClassDef& x, std::string f, const Pos& p) const {
                return make("ClassDef", std::move(f), p, x.name, {exprs(x.bases, "bases", p), keywords(x.keywords, "keywords", p), stmts(x.body, "body", p), exprs(x.decorators, "decorators", p)});
            }
            PN node(const py::Return& x, std::string f, const Pos& p) const { return make("Return", std::move(f), p, {}, {expr(x.value, "value", p)}); }
            PN node(const py::Delete& x, std::string f, const Pos& p) const { return make("Delete", std::move(f), p, {}, {exprs(x.targets, "targets", p)}); }
            PN node(const py::Assign& x, std::string f, const Pos& p) const { return make("Assign", std::move(f), p, {}, {exprs(x.targets, "targets", p), expr(x.value, "value", p)}); }
            PN node(const py::AugAssign& x, std::string f, const Pos& p) const { return make("AugAssign", std::move(f), p, name(kBin, x.op), {expr(x.target, "target", p), expr(x.value, "value", p)}); }
            PN node(const py::AnnAssign& x, std::string f, const Pos& p) const { return make("AnnAssign", std::move(f), p, {}, {expr(x.target, "target", p), expr(x.annotation, "annotation", p), expr(x.value, "value", p)}); }
            PN node(const py::For& x, std::string f, const Pos& p) const {
                return make("For", std::move(f), p, {}, {expr(x.target, "target", p), expr(x.iter, "iter", p), stmts(x.body, "body", p), stmts(x.orelse, "orelse", p), make("bool", "is_async", p, x.is_async ? "true" : "false")});
            }
            PN node(const py::While& x, std::string f, const Pos& p) const { return make("While", std::move(f), p, {}, {expr(x.test, "test", p), stmts(x.body, "body", p), stmts(x.orelse, "orelse", p)}); }
            PN node(const py::If& x, std::string f, const Pos& p) const { return make("If", std::move(f), p, {}, {expr(x.test, "test", p), stmts(x.body, "body", p), stmts(x.orelse, "orelse", p)}); }
            PN node(const py::With& x, std::string f, const Pos& p) const {
                std::vector<PN> items;
                for (const auto& i : x.items) items.push_back(make("WithItem", {}, i.pos, {}, {expr(i.context, "context", i.pos), expr(i.vars, "vars", i.pos)}));
                return make("With", std::move(f), p, {}, {make("sequence", "items", p, {}, std::move(items)), stmts(x.body, "body", p), make("bool", "is_async", p, x.is_async ? "true" : "false")});
            }
            PN node(const py::Raise& x, std::string f, const Pos& p) const { return make("Raise", std::move(f), p, {}, {expr(x.exc, "exc", p), expr(x.cause, "cause", p)}); }
            PN node(const py::Try& x, std::string f, const Pos& p) const {
                std::vector<PN> handlers;
                for (const auto& h : x.handlers) handlers.push_back(make("ExceptHandler", {}, h.pos, h.name, {expr(h.type, "type", h.pos), stmts(h.body, "body", h.pos)}));
                return make("Try", std::move(f), p, {}, {stmts(x.body, "body", p), make("sequence", "handlers", p, {}, std::move(handlers)), stmts(x.orelse, "orelse", p), stmts(x.finalbody, "finalbody", p)});
            }
            PN node(const py::Assert& x, std::string f, const Pos& p) const { return make("Assert", std::move(f), p, {}, {expr(x.test, "test", p), expr(x.msg, "msg", p)}); }
            PN node(const py::Import& x, std::string f, const Pos& p) const { return make("Import", std::move(f), p, {}, {aliases(x.names, "names", p)}); }
            PN node(const py::ImportFrom& x, std::string f, const Pos& p) const { return make("ImportFrom", std::move(f), p, x.module_name, {aliases(x.names, "names", p), make("level", "level", p, std::to_string(x.level))}); }
            PN node(const py::Global& x, std::string f, const Pos& p) const { return make("Global", std::move(f), p, {}, {strings(x.names, "names", p)}); }
            PN node(const py::Nonlocal& x, std::string f, const Pos& p) const { return make("Nonlocal", std::move(f), p, {}, {strings(x.names, "names", p)}); }
            PN node(const py::ExprStmt& x, std::string f, const Pos& p) const { return make("ExprStmt", std::move(f), p, {}, {expr(x.value, "value", p)}); }
            PN node(const py::Pass&, std::string f, const Pos& p) const { return make("Pass", std::move(f), p); }
            PN node(const py::Break&, std::string f, const Pos& p) const { return make("Break", std::move(f), p); }
            PN node(const py::Continue&, std::string f, const Pos& p) const { return make("Continue", std::move(f), p); }
        };
    }
    AST::PythonNode python(const UAST::py::ExprPtr& e, const UAST::SourcePosition& fallback) { return pylower::Lower{}.expr(e, {}, fallback); }
    AST::PythonNode python(const UAST::py::Module& m, const UAST::SourcePosition&) { return pylower::Lower{}.module(m); }
    template<class Params> stdu::vector<std::string> parameters(const Params& p) {
        stdu::vector<std::string> out;
        if (p.empty() || payload(p).value.empty()) return out;
        const auto& args = payload(payload(p).value);
        if (!args.first_p.empty()) out.push_back(id(args.first_p));
        for (const auto& arg : args.following_p) out.push_back(id(arg));
        return out;
    }
    // `code` is a Node<expr> or Node<stmt>: the generated parser keeps the Python
    // action as raw text, so it is parsed into the typed UAST::py tree here.
    // `at` is the node whose position labels the resulting action.
    template<class T, class At> AST::PythonAction action(const UAST::Node<T>& code, const At& at) {
        const auto& n = payload(code);
        auto body = where(n.value);      // text starts after the two-character opening delimiter
        body.offset += 2;
        body.column += 2;
        const auto& source = payload(n.value).value;
        auto tree = [&] {
            if constexpr (std::is_same_v<T, UAST::expr>) return python(UAST::parsePythonExpr(source, body), body);
            else return python(UAST::parsePythonModule(source, body), body);
        }();
        return AST::PythonAction{std::move(tree), {}, position(at)};
    }
    template<class T> AST::PythonAction action(const UAST::Node<T>& code) { return action(code, code); }
    [[noreturn]] void unsupported(const std::string& message) {
        throw std::runtime_error("ISPA bootstrap converter: unsupported " + message);
    }
    std::string unescapeString(std::string value) {
        // Lexer returns literal body, as in the original Builder. Preserve escape behavior.
        for (std::size_t i = 0; i < value.size(); ++i) {
            if (value[i] != '\\' || i + 1 == value.size()) continue;
            value.erase(i, 1);
            if (value[i] != '\'' && value[i] != '"')
                value[i] = corelib::text::getEscapedFromChar(value[i]);
        }
        return value;
    }
    AST::RuleMemberCsequence characterGroup(bool negative, const std::string& text) {
        AST::RuleMemberCsequence out;
        std::size_t i = 0;
        out.negative = negative;
        while (i < text.size()) {
            if (text[i] == '\\' && i + 1 < text.size()) {
                out.escaped.push_back(text[i + 1]); i += 2; continue;
            }
            if (i + 2 < text.size() && text[i + 1] == '-') {
                out.diapasons.push_back({text[i], text[i + 2]}); i += 3; continue;
            }
            out.characters.push_back(text[i++]);
        }
        return out;
    }

    // The generated parser uses both Node<Rules, Value> and
    // Node<Rules, shared_ptr<Value>> for recursive rule values.
    // Keep conversion inside Builder through the supplied callback.
    template<typename T, typename Converter>
    auto convertValues(const std::vector<T>& values, Converter&& convert)
        -> stdu::vector<std::shared_ptr<AST::RuleMember>>
    {
        stdu::vector<std::shared_ptr<AST::RuleMember>> result;
        for (const auto& node : values) {
            result.push_back(std::make_shared<AST::RuleMember>(
                convert(payload(node))
            ));
        }
        return result;
    }
    static AST::RegularDataBlock makeAtDataBlock() {
        return AST::At{};
    }
}

AST::RuleMember AST::Builder::convertPattern(const Pattern& pattern) {
    AST::RuleMember output;
    std::visit([&](const auto& item) {
        using T = std::decay_t<decltype(item)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            unsupported("empty pattern");
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_STRING>>) {
            output.value = AST::String{unescapeString(payload(item).value)};
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_CGROUP>>) {
            output.value = characterGroup(payload(item).negative == '^', payload(item).v);
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_NOSPACE>>) {
            output.value = AST::RuleMemberNospace{};
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_SPACE>>) {
            output.features.push_back(AST::SpacePattern{position(item)});
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::name>>) {
            const auto& n = payload(item);
            if (!n.temp_params.empty() || !n.param.empty())
                output.features.push_back(AST::DeclarationSyntax{{}, parameters(n.param), parameters(n.temp_params), position(item)});
            // Resolve references after all declarations have been collected.
            auto path = qualifiedName(n);
            output.value = AST::RuleMemberName{path};
        } else if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_group>>>) {
            auto children = convertValues(payload(item).value, [this](const Value& v) { return convertValue(v); });
            output.value = AST::RuleMemberGroup{std::move(children)};
        }
        else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_value_ANY>>) {
            output.value = AST::RuleMemberAny{};
        }
        else {
            AST::DynamicPattern dynamic;
            dynamic.position = position(item);
            std::visit([&](const auto& n) {
                using D = std::decay_t<decltype(n)>;
                if constexpr (std::is_same_v<D, UAST::Node<UAST::ID>>) dynamic.name = id(n);
                else if constexpr (!std::is_same_v<D, std::monostate>) dynamic.expression = action(payload(n).value);
            }, payload(item).value);
            output.features.push_back(std::move(dynamic));
        }
    }, pattern.value);
    return output;
}

AST::RuleMember AST::Builder::convertValue(const Value& value) {
    return std::visit([this](const auto& n) -> AST::RuleMember {
        using T = std::decay_t<decltype(n)>;
        if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_one_capture>>>)
            return convertCapture(payload(n));
        else if constexpr (std::is_same_v<T, UAST::Node<std::shared_ptr<UAST::rule_value_mul_capture>>>) {
            AST::RuleMember out;
            out.position = position(n);
            AST::RuleMemberGroup group;
            for (const auto& c : payload(n).cap)
                group.values.push_back(std::make_shared<AST::RuleMember>(convertCapture(payload(c))));
            out.value = std::move(group);
            const char kind = captureMarker(payload(n).type);
            out.features.push_back(AST::RegionCapture{kind, out.position});
            return out;
        } else unsupported("absent rule value");
    }, value.value);
}

AST::RuleMember AST::Builder::convertCapture(const UAST::rule_value_one_capture& value) {
    AST::RuleMember output = convertPattern(payload(value.val));
    output.position = position(value.val);
    auto patternFeatures = std::move(output.features);
    output.features.clear();
    if (!value.registration.empty())
        output.features.push_back(AST::SharedCounterRegistration{id(payload(value.registration).value), position(value.registration)});
    if (!value.v_cap.empty())
        output.features.push_back(AST::VariableCapture{id(payload(value.v_cap).value), position(value.v_cap)});
    if (!value.fail_cap.empty()) {
        AST::FailMarker marker;
        marker.position = position(value.fail_cap);
        const auto& n = payload(value.fail_cap).value;
        if (!n.empty()) { marker.name = qualifiedName(payload(n)); marker.parameters = parameters(payload(n).param); }
        output.features.push_back(std::move(marker));
    }

    if (!value.ast_cap.empty()) {
        output.prefix.present = true;

        const auto& capture = payload(value.ast_cap);

        if (!capture.value.empty())
            output.prefix.name = id(capture.value);
    }
    if (!value.alts.empty()) {
        AST::RuleMemberOp alternatives;
        auto original = output;
        original.prefix.clear();
        original.features = std::move(patternFeatures);
        alternatives.options.push_back(std::make_shared<AST::RuleMember>(std::move(original)));
        for (const auto& alt : value.alts) {
            auto next = convertPattern(payload(payload(alt).value));
            alternatives.options.push_back(std::make_shared<AST::RuleMember>(std::move(next)));
        }
        output.value = std::move(alternatives);
    } else {
        output.features.insert(output.features.begin(), patternFeatures.begin(), patternFeatures.end());
    }

    if (!value.quantifier.empty()) {
        const auto& q = payload(value.quantifier);
        if (!q.repetitions.empty()) {
            AST::Counter counter;
            counter.position = position(q.repetitions);
            std::visit([&](const auto& n) {
                using T = std::decay_t<decltype(n)>;
                if constexpr (std::is_same_v<T, UAST::Node<UAST::ID>>) { counter.kind = "name"; counter.bound = id(n); }
                else if constexpr (std::is_same_v<T, UAST::Node<UAST::NUMBER>>) { counter.kind = "number"; counter.bound = payload(n).full; if (!payload(n).floating.empty()) counter.bound += "." + payload(n).floating; }
                else if constexpr (std::is_same_v<T, UAST::Node<UAST::expr>>) { counter.kind = "expression"; counter.expression = action(n); }
            }, payload(q.repetitions).value);
            output.features.push_back(std::move(counter));
        }
        if (!q.quantifier.empty()) output.quantifier = payload(q.quantifier).value;
    }
    return output;
}

AST::DataBlock AST::Builder::convertData(
    const UAST::Node<UAST::rule_ast>& data) {
    AST::DataBlock result;
    if (data.empty()) return result;
    const auto& d = payload(data);
    std::visit([&](const auto& item) {
        using T = std::decay_t<decltype(item)>;
        if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_ast_abbr>>) {
            AST::TemplatedDataBlock out;
            out.names.push_back(id(payload(item).f));
            for (const auto& v : payload(item).seq) out.names.push_back(id(v));
            result.value = std::move(out);
        } else if constexpr (std::is_same_v<T, UAST::Node<UAST::rule_ast_single_value>>) {
            const auto& single = payload(item);

            std::visit([&](const auto& value) {
                using Value = std::decay_t<decltype(value)>;
                if constexpr (std::is_same_v<Value, UAST::Node<UAST::COMMERCIAL_AT>>) {
                    result.value = makeAtDataBlock();
                } else if constexpr (std::is_same_v<Value, char>) {
                    if (value != '@') unsupported("invalid data block marker");
                    result.value = makeAtDataBlock();
                } else if constexpr (std::is_same_v<Value, UAST::Node<UAST::expr>>) {
                    rule_features.push_back(action(value));
                } else unsupported("absent data block value");
            }, single.value);
        } else if constexpr (std::is_same_v<
            T,
            UAST::Node<
                UAST::rule_ast_full
            >
        >) {
            for (const auto& part : payload(item).value) {
                auto a = action(payload(part).e, part);
                a.target = id(payload(part).key);
                rule_features.push_back(std::move(a));
            }
        } else if constexpr (std::is_same_v<T, std::monostate>) {
            // absent data block
        }
    }, d.value);
    return result;
}

void AST::Builder::convertRule(const Rule& rule) {
    AST::Rule output;
    output.rule_members = convertValues(rule.v, [this](const Value& v) { return convertValue(v); });
    output.data_block = convertData(rule.ast_pointer);
    output.features = std::move(rule_features);
    rule_features.clear();
    if (!rule.fail_pointer.empty()) {
        AST::FailBinding binding;
        binding.position = position(rule.fail_pointer);
        binding.names.push_back(id(payload(rule.fail_pointer).f));
        for (const auto& n : payload(rule.fail_pointer).seq) binding.names.push_back(id(n));
        output.features.push_back(std::move(binding));
    }
    output.isTopLevel = fullname.size() == 1;
    tree_map[fullname] = std::move(output);

    // convertGrammar() owns exactly one scope push/pop per declaration.
    for (const auto& nested : rule.nested) {
        const auto& grammar = payload(payload(nested).value);
        convertGrammar(grammar);
    }

}
void AST::Builder::convertGrammar(const Grammar& grammar) {
    const auto path = qualifiedName(payload(grammar.name));
    const auto scopeSize = fullname.size();
    fullname.insert(fullname.end(), path.begin(), path.end());

    AST::DeclarationSyntax declaration;
    declaration.position = position(grammar.name);
    declaration.parameters = parameters(payload(grammar.name).param);
    declaration.templateParameters = parameters(payload(grammar.name).temp_params);
    for (const auto& mod : grammar.mod) declaration.modifiers.push_back(payload(payload(mod).value).value);
    if (!declaration.modifiers.empty() || !declaration.parameters.empty() || !declaration.templateParameters.empty())
        rule_features.push_back(std::move(declaration));
    using OrdinaryNode = UAST::Node<std::shared_ptr<Rule>>;
    if (const auto* ordinary = std::get_if<OrdinaryNode>(&grammar.entry)) {
        convertRule(payload(*ordinary));
    } else {
        AST::Rule out;
        out.features = std::move(rule_features);
        rule_features.clear();
        const auto& advanced = std::get<UAST::Node<UAST::advanced_rule>>(grammar.entry);
        out.features.push_back(AST::AdvancedRule{python(UAST::describe(payload(advanced), where(advanced))), position(advanced)});
        for (const auto& entry : payload(advanced).body) {
            if (const auto* statement = std::get_if<UAST::Node<UAST::stmt>>(&entry))
                out.features.push_back(action(*statement));
        }
        tree_map[fullname] = std::move(out);
    }
    tree_map.at(fullname).position = position(grammar.name);
    fullname.resize(scopeSize);
}

void AST::Builder::convertMain(const UAST::main& main) {
    std::size_t source_index = 0;
    for (const auto& entry : main.value) {
        FileScope source_scope(source_files.empty() ? file : source_files.at(source_index));
        ++source_index;
        std::visit([&](const auto& value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, UAST::Node<UAST::grammar>>) {
                convertGrammar(payload(value));
            } else if constexpr (std::is_same_v<T, UAST::Node<UAST::fail_block>>) {
                const auto& block = payload(value);
                const auto& n = payload(block.name);
                fail_blocks.push_back(AST::FailBlock{qualifiedName(n), parameters(n.param), action(block.val), position(value)});
            }
        }, entry);
    }
}


namespace {
    void capturedTypes(const stdu::vector<std::shared_ptr<AST::RuleMember>>& members,
                       std::vector<AST::DataType>& types) {
        for (const auto& member : members) {
            if (!member->prefix.empty()) types.push_back(captureType(*member));
            else if (member->isGroup()) {
                std::vector<AST::DataType> nested;
                capturedTypes(member->getGroup().values, nested);
                for (auto& type : nested) {
                    if (member->quantifier == '*' || member->quantifier == '+')
                        type = AST::DataType{AST::DataType::Kind::Array, {}, {type}};
                    types.push_back(std::move(type));
                }
            }
            else if (member->isOp()) {
                std::optional<std::vector<AST::DataType>> first;
                for (const auto& option : member->getOp().options) {
                    std::vector<AST::DataType> current;
                    capturedTypes({option}, current);
                    if (!first) first = std::move(current);
                    else if (*first != current)
                        throw Error("AST: alternatives disagree on captured data types");
                }
                if (first) types.insert(types.end(), first->begin(), first->end());
            }
        }
    }

    void buildDataTypes(AST::Rule& rule) {
        auto& block = rule.data_block;
        if (block.empty()) return;
        std::vector<AST::DataType> captures;
        capturedTypes(rule.rule_members, captures);
        if (block.isRegularDataBlock() && !block.isWithKeys()) {
            if (captures.size() != 1)
                throw Error("AST: regular data block requires exactly one captured member, got {}", captures.size());
            block.type = captures.front();
        } else if (block.isTemplatedDataBlock()) {
            const auto& names = block.getTemplatedDataBlock().names;
            if (names.size() != captures.size())
                throw Error("AST: data block declares {} fields but has {} captures", names.size(), captures.size());
            for (std::size_t i = 0; i < names.size(); ++i)
                block.fields.emplace_back(names[i], captures[i]);
        }
    }
}

void AST::Builder::build() {
    tree_map.clear();
    fail_blocks.clear();
    rule_features.clear();
    fullname.clear();
    FileScope fileScope(file);

    convertMain(input);

    // Search the containing rule and then its enclosing scopes using the
    // entire reference path. Never fall back to a matching final segment:
    // rule.ast must not accidentally bind to a global ast declaration.
    for (auto& [scope, rule] : tree_map) {
        const auto resolve = [&](const auto& self, AST::RuleMember& member) -> void {
            if (member.isName()) {
                auto& reference = member.getName().name;
                for (std::size_t size = scope.size();; --size) {
                    stdu::vector<std::string> candidate(scope.begin(), scope.begin() + size);
                    candidate.insert(candidate.end(), reference.begin(), reference.end());
                    if (tree_map.contains(candidate)) {
                        reference = std::move(candidate);
                        break;
                    }
                    if (size == 0) break;
                }
            } else if (member.isGroup()) {
                for (auto& child : member.getGroup().values) self(self, *child);
            } else if (member.isOp()) {
                for (auto& child : member.getOp().options) self(self, *child);
            }
        };
        for (auto& member : rule.rule_members) resolve(resolve, *member);
        buildDataTypes(rule);
    }
}
