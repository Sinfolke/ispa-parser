module MemLower;
import logging;
import corelib;
import constants;
import std;

namespace {
    // Redirects fun_ctx.statements into `target` for the lifetime of the scope.
    struct StatementsScope {
        FunctionCtx &ctx;
        LangAPI::Statements *saved;
        StatementsScope(FunctionCtx &ctx, LangAPI::Statements &target) : ctx(ctx), saved(ctx.statements) {
            ctx.statements = &target;
        }
        ~StatementsScope() { ctx.statements = saved; }
        StatementsScope(const StatementsScope &) = delete;
        StatementsScope &operator=(const StatementsScope &) = delete;
    };

    auto appendExpr(LangAPI::Expression &dst, const LangAPI::Expression &src) -> void {
        dst.insert(dst.end(), src.begin(), src.end());
    }

    auto op(LangAPI::ExpressionElement e) -> LangAPI::ExpressionValue {
        return LangAPI::ExpressionValue {e};
    }

    auto notExpr(const std::string &var) -> LangAPI::Expression {
        return LangAPI::Expression {
            op(LangAPI::ExpressionElement::Not),
            LangAPI::Symbol::createExpressionValue(LangAPI::Symbol {var})
        };
    }

    auto setBool(const std::string &var, bool value) -> LangAPI::Statement {
        return LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
            .name = LangAPI::Symbol {var},
            .value = LangAPI::Bool::createExpression(LangAPI::Bool {.value = value})
        });
    }

    auto joinTokens(const std::vector<AST::LLkToken> &tokens) -> std::string {
        std::string out;
        for (const auto &token : tokens) {
            if (!out.empty()) out += ", ";
            out += corelib::text::join(token, ".");
        }
        return out;
    }
}

// ---------------------------------------------------------------- helpers ----

auto MemLower::push(const LangAPI::Statement &stmt) -> void {
    fun_ctx->statements->push_back(stmt);
}

auto MemLower::comment(const AST::RuleMember &mem, const std::string &meaning) -> void {
    std::ostringstream out;
    out << mem;
    push(LangAPI::Comment::createStatement(
        LangAPI::Comment {.value = "grammar `" + out.str() + "`: " + meaning}));
}

auto MemLower::createValueAssignment(const std::string &name, const LangAPI::Expression &expr) -> LangAPI::VariableAssignment {
    return LangAPI::VariableAssignment {
        .name = LangAPI::Symbol {name},
        .value = expr
    };
}

// Hoists a declaration to the top of the function. Returns false when the type
// is unknown (Undef): the caller must then declare it in place instead.
auto MemLower::declare(const std::string &name, const LangAPI::Type &type) -> bool {
    if (type == LangAPI::ValueType::Undef) return false;
    LangAPI::Variable var;
    var.name = name;
    var.type = type;
    fun_ctx->declarations.push_back(LangAPI::Variable::createStatement(var));
    return true;
}

// Declares `name` (hoisted when its type is known) and assigns `value` at the
// current emission point.
auto MemLower::bind(const std::string &name, const LangAPI::Type &type, const LangAPI::Expression &value) -> LangAPI::Variable {
    LangAPI::Variable var;
    var.name = name;
    var.type = type;
    if (declare(name, type)) {
        push(LangAPI::VariableAssignment::createStatement(createValueAssignment(name, value)));
    } else {
        var.value = value;
        push(LangAPI::Variable::createStatement(var));
    }
    return var;
}

auto MemLower::hasValue(const Parser::LowerMeta &meta) -> bool {
    return !meta.value.name.empty() || !meta.value_list.name.empty();
}

auto MemLower::isWhitespaceRef(const AST::RuleMember &mem) -> bool {
    return mem.isName() && mem.getName().name == constants::whitespace;
}

auto MemLower::tokenIdSymbol(const AST::LLkToken &token) -> LangAPI::Symbol {
    LangAPI::Symbol sym {token};
    sym.path.insert(sym.path.begin(), std::string {"Tokens"});
    sym.path.emplace_back(std::string {"id"});
    return sym;
}

// `(*pos).kind` of the current lookahead cursor
auto MemLower::kindOfCurrent() -> LangAPI::Expression {
    return LangAPI::StorageSymbol::createExpression(LangAPI::StorageSymbol {
        LangAPI::Pos::createExpression(LangAPI::Pos {.dereference = true}),
        stdu::vector<LangAPI::StorageSymbol::PathPart> {LangAPI::Property {"kind"}}
    });
}

auto MemLower::tokenKindIs(const AST::LLkToken &token) -> LangAPI::Expression {
    auto expr = kindOfCurrent();
    expr.push_back(op(LangAPI::ExpressionElement::Equal));
    appendExpr(expr, LangAPI::Symbol::createExpression(tokenIdSymbol(token)));
    return expr;
}

auto MemLower::getMatchSymbol(char quantifier) -> LangAPI::StdlibExports {
    switch (quantifier) {
        case '\0': return LangAPI::StdlibExports::ParserRequired;
        case '?':  return LangAPI::StdlibExports::ParserOptional;
        case '+':  return LangAPI::StdlibExports::ParserRange;
        case '*':  return LangAPI::StdlibExports::ParserRangeOptional;
        default:
            throw Error("Undefined quantifier: {}", quantifier);
    }
}

auto MemLower::ismemberOptional(char quantifier) -> bool {
    return quantifier == '?' || quantifier == '*';
}

// Node type argument of the stdlib combinators.
auto MemLower::nodeType(const AST::RuleMemberName &name) -> LangAPI::Type {
    return LangAPI::Type {LangAPI::Symbol {"Types", name.name}};
}

// ------------------------------------------------------------- entry point ----

auto MemLower::build(const AST::RuleMember &mem) -> void {
    // ParserBase keeps its own copy of Ctx, so the per-function name counters
    // are loaded from / stored back to the FunctionCtx around each member.
    ctx.variables_lowered = fun_ctx->variables_lowered;
    lower(mem);
    fun_ctx->variables_lowered = ctx.variables_lowered;
}

auto MemLower::lower(const AST::RuleMember &mem) -> Parser::LowerMeta {
    const auto capture_begin = fun_ctx->captures.size();
    Parser::LowerMeta meta;
    if (isWhitespaceRef(mem)) {
        // Inserted by TreePass::addSpaceToken between members. Same effect as
        // optional<__WS>, without creating a value.
        push(LangAPI::SkipSpaces::createStatement(LangAPI::SkipSpaces {.isToken = false}));
        return meta;
    }
    if (mem.isName()) {
        meta = lowerName(mem);
    } else if (mem.isGroup()) {
        meta = lowerGroup(mem);
    } else if (mem.isOp()) {
        meta = lowerOp(mem);
    } else if (mem.empty()) {
        throw Error("Empty member in rule {}", fun_ctx->rule_name);
    } else {
        throw Error("Unsupported member in LL rule {}: literals and character sets must be lexer tokens", fun_ctx->rule_name);
    }
    if (hasValue(meta)) {
        fun_ctx->exports.push_back(LoweredExport {
            .prefix = mem.prefix, .meta = meta, .quantifier = mem.quantifier,
            .member_index = mem_idx, .depth = depth
        });
        if (!mem.prefix.empty()) {
            // Capturing a whole member replaces its descendants' captures.
            fun_ctx->captures.resize(capture_begin);
            fun_ctx->captures.push_back(fun_ctx->exports.back());
        }
    }
    return meta;
}

// -------------------------------------------------------------------- names ----

// Only '\0' and '+' can fail: for '?' and '*' "not present" is a valid result.
auto MemLower::failureHandler(const AST::RuleMember &mem) -> LangAPI::Expression {
    if (hasCustomFailure(mem)) {
        auto handler = mem.failure_handler.name;
        if (handler.empty()) {
            handler = mem.getName().name;
            if (const auto it = ctx.variables_lowered.find(handler); it != ctx.variables_lowered.end() && it->second)
                handler.push_back(std::to_string(it->second));
            handler.push_back("failure_handler");
        }
        return LangAPI::Symbol::createExpression(LangAPI::Symbol {fun_name(handler)});
    }
    return recoveryHandler(*tree, fun_ctx->rule_name, mem_idx, {
        .allow_insertion = true,
        .allow_deletion = true,
        .allow_replacement = true,
        .max_skip = 32
    });
}

// Argument order: pos, [rec], [fail]
auto MemLower::combinatorArgs(const AST::RuleMember &mem) -> stdu::vector<LangAPI::Expression> {
    const auto &name = mem.getName();
    stdu::vector<LangAPI::Expression> args;
    args.push_back(LangAPI::Pos::createExpression(LangAPI::Pos {.dereference = false, .offset = 0}));
    if (name.isNonterminal())    // rule calls pass the rule function as `rec`
        args.push_back(LangAPI::Symbol::createExpression(LangAPI::Symbol {fun_name(name.name)}));
    if (!ismemberOptional(mem.quantifier))
        args.push_back(failureHandler(mem));
    return args;
}

auto MemLower::lowerName(const AST::RuleMember &mem) -> Parser::LowerMeta {
    const auto &name = mem.getName();
    const bool is_list = mem.quantifier == '*' || mem.quantifier == '+';

    Parser::LowerMeta meta;
    const auto vname = var_name(name.name, is_list);

    LangAPI::IspaLibFunctionCall call = {
        .symbol = LangAPI::IspaLibSymbol {.exports = getMatchSymbol(mem.quantifier)},
        .args = combinatorArgs(mem),
        .template_parameters = {std::make_shared<LangAPI::Type>(nodeType(name))}
    };
    if (is_list && tree->getTreeMap().contains(constants::whitespace))
        call.template_parameters.push_back(std::make_shared<LangAPI::Type>(
            LangAPI::Type{LangAPI::Symbol{"Types", constants::whitespace}}));
    auto var = bind(vname, deduceVarTypeByRuleMember(mem), LangAPI::IspaLibFunctionCall::createExpression(call));
    (is_list ? meta.value_list : meta.value) = var;
    // var_name already advances the per-name counter.
    return meta;
}

// ------------------------------------------------------------------- groups ----

auto MemLower::lowerGroup(const AST::RuleMember &mem) -> Parser::LowerMeta {
    return mem.quantifier == '\0' ? lowerSequence(mem) : lowerQuantified(mem);
}

auto MemLower::lowerOp(const AST::RuleMember &mem) -> Parser::LowerMeta {
    return mem.quantifier == '\0' ? lowerDispatch(mem) : lowerQuantified(mem);
}

auto MemLower::lowerBody(const AST::RuleMember &mem) -> Parser::LowerMeta {
    return mem.isGroup() ? lowerSequence(mem) : lowerDispatch(mem);
}

auto MemLower::lowerSequence(const AST::RuleMember &mem) -> Parser::LowerMeta {
    std::vector<Parser::LowerMeta> parts;
    ++depth;
    for (const auto &child : mem.getGroup().values) {
        auto meta = lower(*child);
        if (hasValue(meta)) parts.push_back(std::move(meta));
    }
    --depth;
    return composeValue(mem, parts);
}

// A sequence's value: nothing, the single child's value, or a tuple.
auto MemLower::composeValue(const AST::RuleMember &mem, const std::vector<Parser::LowerMeta> &parts) -> Parser::LowerMeta {
    if (parts.empty()) return {};
    if (parts.size() == 1) return parts.front();

    LangAPI::MakeTuple tuple;
    for (const auto &part : parts) {
        const auto &var = part.value.name.empty() ? part.value_list : part.value;
        tuple.args.push_back(LangAPI::Symbol::createExpression(LangAPI::Symbol {var.name}));
    }
    LangAPI::Type type{LangAPI::ValueType::Tuple};
    for (const auto& part : parts)
        type.template_parameters.emplace_back(
            (part.value.name.empty() ? part.value_list : part.value).type);
    Parser::LowerMeta meta;
    meta.value = bind("group" + std::to_string(fun_ctx->uid()), type,
                      LangAPI::MakeTuple::createExpression(std::move(tuple)));
    return meta;
}

// ---------------------------------------------- quantified group / choice ----

// FIRST_1 of the member's body (quantifier ignored). A body that can match the
// empty input cannot guard a loop: that is a grammar error, not an LL decision.
auto MemLower::firstTokens(const AST::RuleMember &mem) -> std::vector<AST::LLkToken> {
    AST::RuleMember base = mem;
    base.quantifier = '\0';

    std::set<AST::LLkToken> tokens;
    for (const auto &seq : tree->getAlternativeLookahead(base, fun_ctx->rule_name, 1)) {
        if (seq.empty())
            throw Error("Rule {}: quantified member can match empty input, it cannot be guarded by lookahead", fun_ctx->rule_name);
        tokens.insert(seq.front());
    }
    if (tokens.empty())
        throw Error("Rule {}: empty FIRST set for quantified member", fun_ctx->rule_name);
    return {tokens.begin(), tokens.end()};
}

auto MemLower::firstGuard(const AST::RuleMember &mem) -> LangAPI::Expression {
    LangAPI::Expression guard;
    guard.push_back(op(LangAPI::ExpressionElement::GroupOpen));
    bool first = true;
    for (const auto &token : firstTokens(mem)) {
        if (!first) guard.push_back(op(LangAPI::ExpressionElement::Or));
        appendExpr(guard, tokenKindIs(token));
        first = false;
    }
    guard.push_back(op(LangAPI::ExpressionElement::GroupClose));
    return guard;
}

auto MemLower::lowerQuantified(const AST::RuleMember &mem) -> Parser::LowerMeta {
    const char q = mem.quantifier;
    const bool repeated = q == '*' || q == '+';

    auto guard = firstGuard(mem);

    LangAPI::Statements body;
    const auto capture_begin = fun_ctx->captures.size();
    Parser::LowerMeta item;
    {
        StatementsScope scope(*fun_ctx, body);
        ++depth;
        item = lowerBody(mem);
        --depth;
    }

    Parser::LowerMeta meta;
    if (repeated && hasValue(item)) {
        // Collect one value per iteration.
        const auto &element = item.value.name.empty() ? item.value_list : item.value;
        meta.value_list.name = "group_list" + std::to_string(fun_ctx->uid());
        meta.value_list.type = LangAPI::Type {LangAPI::ValueType::Array, element.type};
        declare(meta.value_list.name, meta.value_list.type);

        body.push_back(LangAPI::Statement {LangAPI::StorageSymbol::createExpression(LangAPI::StorageSymbol {
            LangAPI::Symbol::createExpression(LangAPI::Symbol {meta.value_list.name}),
            stdu::vector<LangAPI::StorageSymbol::PathPart> {LangAPI::ArrayMethodCall {
                .method = LangAPI::ArrayMethods::Push,
                .args = {LangAPI::Symbol::createExpression(LangAPI::Symbol {element.name})}
            }}
        })});
    } else if (q == '?') {
        meta = item;
    }

    if (repeated && mem.prefix.empty()) {
        // Nested captures belong to the repetition, so publish one collected
        // value per iteration rather than the final iteration's temporary.
        for (std::size_t i = capture_begin; i < fun_ctx->captures.size(); ++i) {
            auto& capture = fun_ctx->captures[i];
            const auto element = capture.meta.value.name.empty()
                ? capture.meta.value_list : capture.meta.value;
            LangAPI::Variable collection;
            collection.name = "capture_list" + std::to_string(fun_ctx->uid());
            collection.type = LangAPI::Type{LangAPI::ValueType::Array, element.type};
            declare(collection.name, collection.type);
            body.push_back(LangAPI::StorageSymbol::createStatement(LangAPI::StorageSymbol{
                LangAPI::Symbol::createExpression(LangAPI::Symbol{collection.name}),
                stdu::vector<LangAPI::StorageSymbol::PathPart>{LangAPI::ArrayMethodCall{
                    .method = LangAPI::ArrayMethods::Push,
                    .args = {LangAPI::Symbol::createExpression(LangAPI::Symbol{element.name})}
                }}
            }));
            capture.meta = Parser::LowerMeta{.value_list = std::move(collection)};
            capture.quantifier = mem.quantifier;
        }
    }

    // addSpaceToken only inserts ONE `__WS?` before the whole quantified member;
    // later iterations need their own whitespace skip before the guard is tested.
    if (repeated)
        body.push_back(LangAPI::SkipSpaces::createStatement(LangAPI::SkipSpaces {.isToken = false}));

    switch (q) {
        case '?':
            comment(mem, "optional; entered only when lookahead is in FIRST");
            push(LangAPI::If::createStatement(LangAPI::If {guard, body}));
            break;
        case '*':
            comment(mem, "repeat while lookahead is in FIRST");
            push(LangAPI::While::createStatement(LangAPI::While {guard, body}));
            break;
        case '+':
            comment(mem, "one required iteration, then repeat while lookahead is in FIRST");
            push(LangAPI::DoWhile::createStatement(LangAPI::DoWhile {guard, body}));
            break;
        default:
            throw Error("Undefined quantifier: {}", q);
    }
    return meta;
}

// ------------------------------------------------------------------ choice ----

static auto overlaps(const AST::LLkSeq &a, const AST::LLkSeq &b) -> bool {
    return std::equal(a.begin(), a.begin() + std::min(a.size(), b.size()), b.begin());
}

auto MemLower::resolveLookahead(const stdu::vector<std::shared_ptr<AST::RuleMember>> &alts) -> Resolution {
    std::string last_problem;
    for (std::size_t k = 1; k <= max_lookahead; ++k) {
        Resolution res;
        res.k = k;
        bool valid = !alts.empty();
        last_problem.clear();

        for (std::size_t i = 0; i < alts.size(); ++i) {
            auto la = tree->getAlternativeLookahead(*alts[i], fun_ctx->rule_name, k);
            std::set<AST::LLkSeq> seqs(la.begin(), la.end());
            if (seqs.empty()) {
                valid = false;
                last_problem = std::format("alternative {} has an empty lookahead set", i);
            }
            for (const auto &seq : seqs) {
                if (seq.empty()) {
                    valid = false;   // FOLLOW not resolved at this k
                    last_problem = std::format("alternative {} can match empty input", i);
                }
            }
            res.perAlt.push_back(std::move(seqs));
        }

        bool conflict = false;
        for (std::size_t i = 0; i < res.perAlt.size() && !conflict; ++i)
            for (std::size_t j = i + 1; j < res.perAlt.size() && !conflict; ++j)
                for (const auto &a : res.perAlt[i]) {
                    for (const auto &b : res.perAlt[j])
                        if (overlaps(a, b)) {
                            conflict = true;
                            last_problem = std::format("alternatives {} and {} share the lookahead prefix [{}]", i, j,
                                                       joinTokens(a.size() <= b.size() ? a : b));
                            break;
                        }
                    if (conflict) break;
                }

        if (valid && !conflict) return res;
    }
    throw Error("LL(k) conflict in rule {}: not resolved within k = {} ({}). Check common prefixes / left-factor the grammar.",
                fun_ctx->rule_name, max_lookahead, last_problem);
}

// Lookahead cursors: level L pushes a child cursor `la<op>_<L>`. Level > 1
// first advances it past one significant token. The chosen alternative is
// parsed with the cursor reset to the original position, so lookahead never
// consumes input by itself.
auto MemLower::decisionTree(
    const Resolution &res,
    const std::vector<LangAPI::Statements> &bodies,
    const std::vector<std::size_t> &candidates,
    std::size_t level,
    std::size_t op_id,
    const std::vector<AST::LLkToken> &path,
    const LangAPI::Variable &matched
) -> LangAPI::Statements {
    const auto cursor = [&](std::size_t l) { return "la" + std::to_string(op_id) + "_" + std::to_string(l); };
    const std::size_t index = level - 1;   // which lookahead token this level tests

    std::map<AST::LLkToken, std::set<std::size_t>> buckets;
    for (const auto alt : candidates) {
        for (const auto &seq : res.perAlt[alt]) {
            if (index >= seq.size()) continue;
            bool on_path = true;
            for (std::size_t i = 0; i < index; ++i)
                if (seq[i] != path[i]) { on_path = false; break; }
            if (on_path) buckets[seq[index]].insert(alt);
        }
    }

    LangAPI::Switch sw {.expression = kindOfCurrent()};
    for (const auto &[token, alts] : buckets) {
        sw.cases.emplace_back();
        auto &cs = sw.cases.back();
        cs.first = LangAPI::Symbol::createRValue(tokenIdSymbol(token));

        if (alts.size() == 1) {
            if (level > 1)
                cs.second.push_back(LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
                    .name = LangAPI::Symbol {cursor(level)},
                    .value = LangAPI::Symbol::createExpression(LangAPI::Symbol {cursor(1)})
                }));
            const auto &body = bodies[*alts.begin()];
            cs.second.insert(cs.second.end(), body.begin(), body.end());
            cs.second.push_back(setBool(matched.name, true));
        } else {
            if (level >= res.k)
                throw Error("Unresolved LL(k) decision at depth {} in rule {}", index, fun_ctx->rule_name);
            auto next_path = path;
            next_path.push_back(token);
            auto nested = decisionTree(res, bodies, {alts.begin(), alts.end()}, level + 1, op_id, next_path, matched);
            cs.second.insert(cs.second.end(), nested.begin(), nested.end());
        }
    }

    LangAPI::Statements out;
    out.push_back(LangAPI::PushPosCounter::createStatement(LangAPI::PushPosCounter {.name = cursor(level)}));
    if (level > 1) {
        out.push_back(LangAPI::CounterIncreament::createStatement(LangAPI::CounterIncreament {}));
        out.push_back(LangAPI::SkipSpaces::createStatement(LangAPI::SkipSpaces {.isToken = false}));
    }
    out.push_back(LangAPI::Switch::createStatement(std::move(sw)));
    if (level > 1) {
        // A nested level that selected nothing must not leave the cursor advanced.
        out.push_back(LangAPI::If::createStatement(LangAPI::If {
            notExpr(matched.name),
            LangAPI::VariableAssignment::createStatements(LangAPI::VariableAssignment {
                .name = LangAPI::Symbol {cursor(level)},
                .value = LangAPI::Symbol::createExpression(LangAPI::Symbol {cursor(level - 1)})
            })
        }));
    }
    out.push_back(LangAPI::PopPosCounter::createStatement(LangAPI::PopPosCounter {}));
    return out;
}

auto MemLower::lowerDispatch(const AST::RuleMember &mem) -> Parser::LowerMeta {
    const auto &alts = mem.getOp().options;
    if (alts.empty()) throw Error("Empty choice in rule {}", fun_ctx->rule_name);

    AST::RuleMember base = mem;
    base.quantifier = '\0';
    const auto op_id = fun_ctx->uid();

    // Result variable (variant of the alternatives' values) and success flag.
    Parser::LowerMeta meta;
    const auto result_type = deduceVarTypeByRuleMember(base);
    const std::string result_name = "choice" + std::to_string(op_id);
    const bool has_result = declare(result_name, result_type);
    if (has_result) {
        meta.value.name = result_name;
        meta.value.type = result_type;
    }
    LangAPI::Variable matched;
    matched.name = "matched" + std::to_string(op_id);
    matched.type = LangAPI::Type {LangAPI::ValueType::Bool};
    declare(matched.name, matched.type);

    // Each alternative is lowered exactly once; decision-tree leaves copy the
    // statements, so alternatives with several FIRST tokens share variables.
    std::vector<LangAPI::Statements> bodies(alts.size());
    for (std::size_t i = 0; i < alts.size(); ++i) {
        StatementsScope scope(*fun_ctx, bodies[i]);
        ++depth;
        auto alt = lower(*alts[i]);
        --depth;
        if (has_result && hasValue(alt)) {
            const auto &src = alt.value.name.empty() ? alt.value_list : alt.value;
            push(LangAPI::VariableAssignment::createStatement(
                createValueAssignment(result_name, LangAPI::Symbol::createExpression(LangAPI::Symbol {src.name}))));
        }
    }

    const auto res = resolveLookahead(alts);

    comment(mem, "choice; alternative selected by LL(" + std::to_string(res.k) + ") lookahead");
    push(setBool(matched.name, false));
    std::vector<std::size_t> candidates(alts.size());
    std::iota(candidates.begin(), candidates.end(), 0);
    for (auto &stmt : decisionTree(res, bodies, candidates, 1, op_id, {}, matched))
        push(stmt);

    std::vector<AST::LLkToken> expected;
    for (const auto &seqs : res.perAlt)
        for (const auto &seq : seqs)
            if (!seq.empty() && std::find(expected.begin(), expected.end(), seq.front()) == expected.end())
                expected.push_back(seq.front());
    push(LangAPI::If::createStatement(LangAPI::If {
        notExpr(matched.name),
        LangAPI::Statements {
            LangAPI::ReportError::createStatement(LangAPI::ReportError {
                .message = "ISPA match failure: expected one of: " + joinTokens(expected)}),
            LangAPI::Return::createStatements(LangAPI::Return {}).front()
        }
    }));
    return meta;
}
