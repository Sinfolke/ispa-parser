module LLIR.Rule.MemberBuilder;
import LLIR.CllBuilder;
import logging;
import corelib;
import cpuf.hex;
import cpuf.op;
import cpuf.printf;
import Dump;
import NFA.IR;
import NFA.TNFA;
import DFA;
import constants;
import std;
// helper functions
// Use the generated stdlib compatibility conversion for collected arrays.
// This keeps the source type inferred from the grammar while allowing
// recursive AST fields to have boxed element representations.
namespace {
    LangAPI::Expression shadowCompatible(LangAPI::Expression target, LangAPI::Expression source) {
        return LangAPI::IspaLibFunctionCall::createExpression(LangAPI::IspaLibFunctionCall{
            .symbol = LangAPI::IspaLibSymbol {.exports = LangAPI::StdlibExports::AssignCompatible},
            .args = {target, source}
        });
    }
}

// Comments in generated code identify the original grammar member.
static auto grammarComment(const AST::RuleMember &rule, const std::string &meaning) -> LangAPI::Statement {
    std::ostringstream out;
    out << rule;
    return LangAPI::Comment::createStatement(
        LangAPI::Comment{.value = "grammar `" + out.str() + "`: " + meaning});
}
// Nested members of optional/repeated groups are speculative: a failed match
// terminates the attempt rather than constituting a parser error. Propagate
// this context across nested MemberBuilder/OpBuilder instances during codegen.
namespace {
    thread_local unsigned speculative_match_depth = 0;

    struct SpeculativeMatchScope {
        explicit SpeculativeMatchScope(bool enabled) : enabled(enabled) {
            if (enabled) ++speculative_match_depth;
        }
        ~SpeculativeMatchScope() {
            if (enabled) --speculative_match_depth;
        }
        SpeculativeMatchScope(const SpeculativeMatchScope&) = delete;
        SpeculativeMatchScope& operator=(const SpeculativeMatchScope&) = delete;
    private:
        bool enabled;
    };
}

// Diagnostics emitted into the generated parser (rather than the generator process).
// These are intentionally confined to required-match failure paths: expected
// failures ending '*' / '?' repetitions should not be reported as errors.
static auto parserFailure(const AST::RuleMember &rule, const std::string &reason)
    -> LangAPI::Statement {
    std::ostringstream text;
    text << rule;
    if (speculative_match_depth != 0) {
        // Keep the failure/rollback control flow; omit only the diagnostic.
        return LangAPI::Comment::createStatement(LangAPI::Comment{
            .value = "speculative match failed (diagnostic suppressed): " + text.str()
        });
    }
    return LangAPI::ReportError::createStatement(LangAPI::ReportError{
        .message = "ISPA match failure: " + reason + " | grammar: " + text.str()
    });
}

void LLIR::GroupBuilder::pushBasedOnQuantifier(
    MemberBuilder &builder,
    const AST::RuleMember &rule,
    LangAPI::Variable &shadow_var,
    LangAPI::Variable &uvar,
    const LangAPI::Variable &var,
    char quantifier
    ) {
    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_var);
        statements.push_back(LangAPI::Variable::createStatement(uvar));
    }
    if (quantifier == '*' || quantifier == '+') {
        LangAPI::While loop;
        loop.expr = LangAPI::Bool::createExpression(LangAPI::Bool { .value = true });
        loop.stmt = builder.getData();
        builder.getData().clear();
        // A repeated group whose first member is an LL(k) choice performs
        // its switch on the current token. Once the previous iteration ends,
        // the current token can be __WS (e.g. `rule: ...;  next{...}`).
        // Without a whitespace skip, the next iteration sees __WS in the
        // choice switch and stops, so only the first group item is captured.
        // Insert the skip INSIDE the loop and BEFORE the alternative's
        // lookahead; the group's position counter remains speculative until
        // the iteration succeeds, so the outer parser can still backtrack.
        const auto& members = rule.getGroup().values;
        if (!isToken && !members.empty() && members.front()->isOp()) {
            loop.stmt.insert(loop.stmt.begin(),
                LangAPI::SkipSpaces::createStatement(
                    LangAPI::SkipSpaces{.isToken = false}));
        }
        processExitStatements(loop.stmt);
        // raiseVarsTop(data, loop.block, true, false, false);
        // raiseVarsTop(data, loop.else_block, true, false, false);
        if (quantifier == '+') {
            handle_plus_qualifier(rule, std::move(loop), uvar, var, shadow_var);
        } else {
            statements.push_back(LangAPI::While::createStatement(loop));
        }
    } else if (quantifier == '?') {
        // Execute the optional body exactly once. Some LangAPI targets lower
        // DoWhile(false) as While(false), which makes the body unreachable.
        // A true-condition loop with an unconditional trailing break works
        // across those backends and preserves converted failure -> break paths.
        statements.push_back(grammarComment(rule, "optional group; try at most once"));
        LangAPI::While loop;
        loop.expr = LangAPI::Bool::createExpression(LangAPI::Bool { .value = true });
        loop.stmt = builder.getData();
        builder.getData().clear();
        processExitStatements(loop.stmt);
        loop.stmt.insert(loop.stmt.begin(), grammarComment(rule, "optional body; failed alternative leaves this group"));
        loop.stmt.push_back(LangAPI::Break::createStatements(LangAPI::Break{}).front());
        statements.push_back(LangAPI::While::createStatement(loop));
    }
}

auto LLIR::NameBuilder::pushBasedOnQualifier(
    const AST::RuleMember &rule,
    LangAPI::Expression &expr,
    LangAPI::Statements &stmt,
    LangAPI::Variable &uvar,
    const LangAPI::Variable &var,
    const LangAPI::Variable &svar,
    const LangAPI::Statement &call,
    char quantifier,
    stdu::vector<std::string> &name,
    bool add_shadow_var
) -> LangAPI::Variable {
    (void)name;
    (void)add_shadow_var;

    statements.insert(statements.end(), stmt.begin(), stmt.end());
    LangAPI::Variable shadow_variable;
    if (!uvar.name.empty()) {
        uvar.type = deduceUvarType(var, shadow_variable);
    }

    const bool repeated = quantifier == '*' || quantifier == '+';
    LangAPI::Variable extracted = uvar;
    if (insideLoop || repeated) {
        // Each repetition has a scalar value, not the array result.
        extracted = createEmptyVariable("element" + generateVariableName());
        extracted.type = deduceUvarType(var, {});
        statements.push_back(LangAPI::Variable::createStatement(extracted));
    }
    LangAPI::Statements shadow_append;
    if (insideLoop || repeated) {
        shadow_variable = add_shadow_variable(statements, shadow_append, extracted);
        if (repeated && !uvar.name.empty()) {
            // Export the collection for NAME* and NAME+, not the last NAME.
            uvar.type = shadow_variable.type;
        }
    }

    if (!uvar.name.empty())
        statements.push_back(LangAPI::Variable::createStatement(uvar));

    LangAPI::Statements successful;
    // FIX: a successful call must mark svar true. Without this, every
    // generated call site that later tests svar (e.g. OpBuilder's
    // "if (!selected.svar) return {};") fails unconditionally, even
    // when the called rule actually matched.
    successful.push_back(assignSvar(svar, true));
    successful.push_back(LangAPI::AssignCounter::createStatement(
        LangAPI::AssignCounter{
            .v = std::make_shared<LangAPI::Expression>(
                LangAPI::StorageSymbol::createExpression(
                    LangAPI::StorageSymbol{
                        LangAPI::Symbol::createExpression(
                            LangAPI::Symbol{var.name}),
                        stdu::vector<LangAPI::StorageSymbol::PathPart>{"it"}
                    }))
        }));
    createAssignUvarBlock(successful, extracted, var, {});
    successful.insert(successful.end(), shadow_append.begin(),
                      shadow_append.end());

    if (repeated) {
        statements.push_back(grammarComment(rule, "repeat named rule; collect every matched value"));
        LangAPI::Statements loop_body{call};
        LangAPI::Expression failed = expr;
        failed.insert(failed.begin(), LangAPI::ExpressionValue{
            LangAPI::ExpressionElement::Not});
        failed.insert(failed.begin() + 1, LangAPI::ExpressionValue{
            LangAPI::ExpressionElement::GroupOpen});
        failed.push_back(LangAPI::ExpressionValue{
            LangAPI::ExpressionElement::GroupClose});
        loop_body.push_back(LangAPI::If::createStatement(
            LangAPI::If{std::move(failed), LangAPI::Break::createStatements(LangAPI::Break{})}));
        loop_body.insert(loop_body.end(), successful.begin(), successful.end());
        auto loop = LangAPI::While{
            LangAPI::Bool::createExpression(LangAPI::Bool{.value = true}),
            std::move(loop_body)
        };
        if (quantifier == '+') {
            handle_plus_qualifier(rule, std::move(loop), uvar, var,
                                  shadow_variable);
        } else {
            statements.push_back(LangAPI::While::createStatement(loop));
        }
    } else {
        statements.push_back(call);
        LangAPI::Expression failed = expr;
        failed.insert(failed.begin(), LangAPI::ExpressionValue{
            LangAPI::ExpressionElement::Not});
        failed.insert(failed.begin() + 1, LangAPI::ExpressionValue{
            LangAPI::ExpressionElement::GroupOpen});
        failed.push_back(LangAPI::ExpressionValue{
            LangAPI::ExpressionElement::GroupClose});
        if (quantifier == '?') {
            statements.push_back(LangAPI::If::createStatement(
                LangAPI::If{expr, std::move(successful)}));
        } else {
            statements.push_back(LangAPI::If::createStatement(
                LangAPI::If{std::move(failed), LangAPI::Statements{
                    parserFailure(rule, "required named rule did not match"),
                    LangAPI::Return::createStatements(LangAPI::Return{}).front()
                }}));
            statements.insert(statements.end(), successful.begin(),
                              successful.end());
        }
    }
    if (repeated && !uvar.name.empty()) {
        statements.push_back(shadowCompatible(LangAPI::Symbol::createExpression(LangAPI::Symbol{uvar.name}), LangAPI::Symbol::createExpression(LangAPI::Symbol{shadow_variable.name})));
    }
    return shadow_variable;
}
auto LLIR::NameBuilder::createAssignUvarBlock(LangAPI::Statements &statements, const LangAPI::Variable &uvar, const LangAPI::Variable &var, const LangAPI::Variable &shadow_var) -> void {
    if (!uvar.name.empty()) {
        statements.push_back(LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
                .name = LangAPI::Symbol {uvar.name},
                .value = LangAPI::StorageSymbol::createExpression(LangAPI::StorageSymbol {
                    LangAPI::Symbol::createExpression(LangAPI::Symbol {var.name}), stdu::vector<LangAPI::StorageSymbol::PathPart> {LangAPI::IspaLibSymbol {.exports = LangAPI::StdlibExports::MatchResultValue}}
                })
            })
        );
    }
}
void LLIR::MemberBuilder::buildMember(const AST::RuleMember &member) {
    std::unique_ptr<BuilderBase> builder;
    if (member.isGroup()) {
        builder = std::make_unique<GroupBuilder>(*this, member);
    } else if (member.isCsequence()) {
        builder = std::make_unique<CsequenceBuilder>(*this, member);
    } else if (member.isString()) {
        builder = std::make_unique<StringBuilder>(*this, member);
    // } else if (member.isHex()) {
    //     builder = std::make_unique<HexBuilder>(*this, member);
    // } else if (member.isBin()) {
    //     builder = std::make_unique<BinBuilder>(*this, member);
    } else if (member.isName()) {
        builder = std::make_unique<NameBuilder>(*this, member);
    // } else if (member.isEscaped()) {
    //     builder = std::make_unique<EscapedBuilder>(*this, member);
    } else if (member.isNospace()) {
        builder = std::make_unique<NospaceBuilder>(*this);
    } else if (member.isOp()) {
        builder = std::make_unique<OpBuilder>(*this, member);
    } else if (member.isAny()) {
        builder = std::make_unique<AnyBuilder>(*this, member);
    } else if (member.isCll()) {
        builder = std::make_unique<CllBuilder>(*this, member.getCll());
    } else if (member.empty()) {
        throw Error("Empty rule");
    } else throw Error("Undefined rule");
    builder->build();
    exports_list.insert(exports_list.end(), builder->getReturnVars().begin(), builder->getReturnVars().end());
    statements.insert(statements.end(), builder->getData().begin(), builder->getData().end());
    isFirst = false;
}
auto LLIR::MemberBuilder::build() -> void {
    isToken = corelib::text::isUpper(fullname.back());
    if (rules == nullptr) {
        buildMember(*rule);
        return;
    }

    // Build one member's statements without merging them into
    // `this->statements` yet. Mirrors buildMember's dispatch, but lets
    // the caller decide where the result lands -- used below to splice a
    // whitespace skip into a following loop instead of emitting it as a
    // standalone statement.
    auto buildStandalone = [this](const AST::RuleMember &member) -> LangAPI::Statements {
        std::unique_ptr<BuilderBase> builder;
        if (member.isGroup()) {
            builder = std::make_unique<GroupBuilder>(*this, member);
        } else if (member.isCsequence()) {
            builder = std::make_unique<CsequenceBuilder>(*this, member);
        } else if (member.isString()) {
            builder = std::make_unique<StringBuilder>(*this, member);
        } else if (member.isName()) {
            builder = std::make_unique<NameBuilder>(*this, member);
        } else if (member.isNospace()) {
            builder = std::make_unique<NospaceBuilder>(*this);
        } else if (member.isOp()) {
            builder = std::make_unique<OpBuilder>(*this, member);
        } else if (member.isAny()) {
            builder = std::make_unique<AnyBuilder>(*this, member);
        } else if (member.isCll()) {
            builder = std::make_unique<CllBuilder>(*this, member.getCll());
        } else if (member.empty()) {
            throw Error("Empty rule");
        } else throw Error("Undefined rule");
        builder->build();
        exports_list.insert(exports_list.end(), builder->getReturnVars().begin(), builder->getReturnVars().end());
        isFirst = false;
        return builder->getData();
    };

    // AST::TreePass::addSpaceToken (run before codegen reaches this file)
    // inserts a single `{.quantifier='?', .value=RuleMemberName{.name=
    // {constants::whitespace}}}` sibling immediately before member i,
    // for every adjacent pair of members in a rule's flat member list.
    // That is correct when the member it precedes matches once. But when
    // that member is repeated (`*`/`+`), addSpaceToken has no notion of
    // "this slot repeats" -- it only ever inserts ONE whitespace-skip
    // sibling for the whole repeated slot, checked once before codegen's
    // loop starts, never between iterations. So only the first repetition
    // ever consumes its leading whitespace, and every later repetition's
    // lookahead check sees an un-skipped `__WS` token and fails
    // immediately, silently truncating the match. (E.g. `#alternative*`
    // matching `| b | c`: the second `|` is preceded by an un-skipped
    // `__WS`, so only `| b` is ever collected.)
    const auto isWhitespaceRef = [](const AST::RuleMember &member) {
        return member.quantifier == '?'
            && member.isName()
            && member.getName().name == constants::whitespace;
    };
    const auto isRepeated = [](const AST::RuleMember &member) {
        return member.quantifier == '*' || member.quantifier == '+';
    };

    for (std::size_t i = 0; i < rules->size(); ++i) {
        const AST::RuleMember &member = *(*rules)[i];

        if (isWhitespaceRef(member) &&
            i + 1 < rules->size() &&
            isRepeated(*(*rules)[i + 1])) {
            // Build the skip into a scratch buffer instead of emitting it
            // here, then splice it onto the front of the following
            // member's own loop body so it reruns every iteration.
            const AST::RuleMember &next_member = *(*rules)[i + 1];
            // Token repetitions generated by NameBuilder use a token predicate
            // as the *while condition*. If we put __WS inside that loop, the
            // predicate is evaluated before whitespace is skipped and ID+
            // fails immediately on inputs such as `-> ID`.
            //
            // Keep the first whitespace skip outside the token loop. This
            // preserves the first match; handling whitespace between further
            // token repetitions requires a separately guarded loop body.
            if (next_member.isName() &&
                corelib::text::isUpper(next_member.getName().name.back())) {
                buildMember(member);
                buildMember(next_member);
                ++i;
                continue;
            }

            auto ws_stmts = buildStandalone(member);
            auto next_stmts = buildStandalone(next_member);

            for (auto &stmt : next_stmts) {
                if (stmt.isWhile() || stmt.isDoWhile()) {
                    auto &loop = stmt.getWhileOrDoWhile();
                    // Each repetition attempt must be atomic, including the
                    // automatically inserted whitespace. PushPosCounter creates
                    // a child cursor initially equal to the parent cursor.
                    // A failed named-rule call breaks before PopPosCounter,
                    // leaving the parent cursor unchanged. A successful call
                    // reaches PopPosCounter and commits the child cursor.
                    //
                    // In particular, `rule.value+` must not consume the space
                    // before `->` when its final attempt fails.
                    const auto checkpoint_name =
                        "repeat_ws" + generateVariableName();
                    LangAPI::Statements transactional;
                    transactional.push_back(
                        LangAPI::PushPosCounter::createStatement(
                            LangAPI::PushPosCounter{.name = checkpoint_name}));
                    transactional.insert(transactional.end(),
                                         ws_stmts.begin(), ws_stmts.end());
                    transactional.insert(transactional.end(),
                                         loop.stmt.begin(), loop.stmt.end());
                    transactional.push_back(
                        LangAPI::PopPosCounter::createStatement(
                            LangAPI::PopPosCounter{}));
                    loop.stmt = std::move(transactional);
                }
            }

            statements.insert(statements.end(), next_stmts.begin(), next_stmts.end());
            ++i; // the following member was already built above
            continue;
        }

        buildMember(member);
    }
}

void LLIR::GroupBuilder::build() {
    const auto& quantifier = rule.quantifier;
    const auto& group = rule.getGroup().values;

    const bool is_repeated =
        quantifier == '*' || quantifier == '+';

    const bool was_inside_loop = insideLoop;
    const bool needs_shadow = was_inside_loop || is_repeated;

    auto var = createEmptyVariable(
        "group" + generateVariableName()
    );

    const bool uvar_is_named = !rule.prefix.name.empty();

    auto uvar = createEmptyVariable(
        uvar_is_named
            ? rule.prefix.name
            : "uvar" + generateVariableName()
    );

    auto svar = createSuccessVariable();

    // Build the group's members in the correct loop context.
    insideLoop = needs_shadow;

    // Child builders register @ captures in the shared datablock registry.
    // Remember where this group starts so earlier captures stay untouched.
    const auto capture_begin = unnamed_datablock_units.size();
    const auto keyed_capture_begin = key_vars.size();

    MemberBuilder builder(*this, group);
    {
        // '*/?' failures are normal, and '+' also makes one final unsuccessful
        // attempt to terminate after successful iterations.
        SpeculativeMatchScope speculative(
            quantifier == '?' || quantifier == '*' || quantifier == '+');
        builder.build();
    }

    insideLoop = was_inside_loop;

    const auto& return_vars = builder.getReturnVars();

    // A capture inside ( ... )+ / ( ... )* must accumulate across all
    // successful group iterations. Merely exporting the child's scalar
    // return variable exposes its final assignment only.
    auto group_capture_exports = return_vars;
    LangAPI::Statements group_capture_appends;
    if (is_repeated && rule.prefix.empty()) {
        for (auto& captured : group_capture_exports) {
            if (captured.var.name.empty() ||
                captured.var.type == LangAPI::ValueType::Undef ||
                captured.var.name.find("__WS") != std::string::npos)
                continue;

            // Return variables for named rules can still hold MatchResult<T>,
            // whereas a capture collection must contain Node<T>.  Do not
            // append MatchResult<T> to vector<Node<T>>: extract .node first.
            LangAPI::Variable element = captured.var;
            LangAPI::Statements extract_node;
            if (captured.var.type == LangAPI::ValueType::RuleResult ||
                captured.var.type == LangAPI::ValueType::TokenResult) {
                element = createEmptyVariable("group_capture" + generateVariableName());
                element.type = deduceUvarType(captured.var, {});
                statements.push_back(LangAPI::Variable::createStatement(element));
                extract_node.push_back(LangAPI::VariableAssignment::createStatement(
                    LangAPI::VariableAssignment{
                        .name = LangAPI::Symbol{element.name},
                        .value = LangAPI::StorageSymbol::createExpression(
                            LangAPI::StorageSymbol{
                                LangAPI::Symbol::createExpression(
                                    LangAPI::Symbol{captured.var.name}),
                                stdu::vector<LangAPI::StorageSymbol::PathPart>{
                                    LangAPI::IspaLibSymbol{
                                        .exports = LangAPI::StdlibExports::MatchResultValue}}
                            })
                    }));
            }

            LangAPI::Statements append_one;
            auto collected = add_shadow_variable(
                statements, append_one, element);
            if (collected.name.empty())
                continue;

            // Extract and append only after the entire iteration succeeds.
            group_capture_appends.insert(group_capture_appends.end(),
                extract_node.begin(), extract_node.end());
            group_capture_appends.insert(group_capture_appends.end(),
                append_one.begin(), append_one.end());
            // Downstream AST field selection uses ExportsAfterBuild::uvar
            // (the capture-facing value), not ::var (the parser's temporary).
            // Publish the accumulated collection through both fields.  The
            // original scalar variables remain in the generated statements
            // for use while matching each iteration.
            // AST construction reads the shared capture registries, *not*
            // ExportsAfterBuild. Replace only captures created by this group.
            // A group member may have both var (MatchResult) and uvar (Node),
            // so match against the original names before updating exports.
            const auto original_var = captured.var.name;
            const auto original_uvar = captured.uvar.name;
            const auto original_shadow = captured.shadow_var.name;
            const auto matches_capture = [&](const LangAPI::Variable& v) {
                return (!original_uvar.empty() && v.name == original_uvar) ||
                       (!original_var.empty() && v.name == original_var) ||
                       (!original_shadow.empty() && v.name == original_shadow);
            };
            for (std::size_t i = capture_begin;
                 i < unnamed_datablock_units.size(); ++i) {
                if (matches_capture(unnamed_datablock_units[i]))
                    unnamed_datablock_units[i] = collected;
            }
            for (std::size_t i = keyed_capture_begin;
                 i < key_vars.size(); ++i) {
                if (matches_capture(key_vars[i].second))
                    key_vars[i].second = collected;
            }

            captured.var = collected;
            captured.uvar = collected;
            captured.shadow_var = collected;
        }
    }


    // Remove an unnecessary trailing whitespace skip.
    if (!builder.getData().empty() &&
        builder.getData().back().isExpression()) {

        const auto& expr =
            builder.getData().back().getExpression();

        // if (expr.size() == 1 &&
        //     expr.back().isSkipSpaces()) {
        //     builder.pop();
        // }
    }

    // Deduce the actual value type before array promotion.
    var.type = deduceVarTypeByRuleMember(rule);

    LangAPI::Statements fetch_var_statements;

    // Keep element type and result type distinct.
    LangAPI::Type element_type = var.type;

    if (var.type == LangAPI::ValueType::Array &&
        !var.type.template_parameters.empty()) {
        element_type = std::get<LangAPI::Type>(
            var.type.template_parameters.front()
        );
    }

    switch (element_type.getValueType()) {
        case LangAPI::ValueType::String: {
            for (const auto& ret : return_vars) {
                if (ret.var.name.empty())
                    continue;

                fetch_var_statements.push_back(
                    LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
                        .name = LangAPI::Symbol{var.name},
                        .value = LangAPI::Symbol::createExpression(
                            LangAPI::Symbol{ret.var.name}
                        )
                    })
                );
            }
            break;
        }

        // case LangAPI::ValueType::Token:
        // case LangAPI::ValueType::Rule:
        // case LangAPI::ValueType::Variant:
        default: {
            // Never dereference an empty return list.
            if (return_vars.empty() ||
                return_vars.front().var.name.empty()) {
                var.type = {LangAPI::ValueType::Undef};
                break;
            }

            const auto& ret = return_vars.front();

            // Preserve a previously deduced array type.
            if (var.type != LangAPI::ValueType::Array) {
                var.type = ret.var.type;

                if (var.type.isValueType()) {
                    undoRuleResult(var.type.getValueType());
                }
            }

            fetch_var_statements.push_back(
                LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
                    .name = LangAPI::Symbol{var.name},
                    .value = LangAPI::Symbol::createExpression(
                        LangAPI::Symbol{ret.var.name}
                    )
                })
            );
            break;
        }
    }

    // Keep var as one iteration's value; shadow_var collects repeated values.
    if (var.type.getValueType() == LangAPI::ValueType::Undef) {
        var = {};
        uvar = {};
    } else {
        uvar.type = var.type;
    }
    // Assign the final type, not an intermediate one.

    // Construct group success expression.
    LangAPI::If group_success_condition{};

    stdu::vector<std::string> used_vars;

    bool first = true;

    for (const auto& ret : return_vars) {
        if (ret.quantifier == '*' ||
            ret.quantifier == '?' ||
            ret.svar.name.empty()) {
            continue;
        }

        if (!first) {
            group_success_condition.expr.push_back(
                LangAPI::ExpressionValue{
                    LangAPI::ExpressionElement::And
                }
            );
        }

        used_vars.push_back(ret.svar.name);

        group_success_condition.expr.push_back(
            LangAPI::Symbol::createExpressionValue(
                LangAPI::Symbol{ret.svar.name}
            )
        );

        first = false;
    }

    // Declare the result before emitting operations.
    if (var.type != LangAPI::ValueType::Undef) {
        statements.push_back(
            LangAPI::Variable::createStatement(var)
        );
    }

    statements.push_back(
        LangAPI::Variable::createStatement(svar)
    );

    // Shadow variables are needed for repeated/grouped values.
    LangAPI::Variable shadow_var;
    LangAPI::Statements shadow_var_assign_block;

    if (needs_shadow &&
        var.type != LangAPI::ValueType::Undef &&
        var.type != LangAPI::ValueType::String) {

        shadow_var = add_shadow_variable(
            statements,
            shadow_var_assign_block,
            var
        );
    }

    if (is_repeated && !shadow_var.name.empty()) {
        uvar.type = shadow_var.type;
    }

    const std::string pos_counter_name =
        "begin" + generateVariableName();

    statements.push_back(
        LangAPI::PushPosCounter::createStatement(LangAPI::PushPosCounter {
            .name = pos_counter_name
        })
    );

    // Repeated groups accumulate each successful iteration, not after the loop.
    if (is_repeated && (!shadow_var_assign_block.empty() ||
                        !group_capture_appends.empty())) {
        LangAPI::If iteration_success = group_success_condition;
        iteration_success.stmt = fetch_var_statements;
        iteration_success.stmt.insert(
            iteration_success.stmt.end(),
            shadow_var_assign_block.begin(),
            shadow_var_assign_block.end()
        );
        iteration_success.stmt.insert(
            iteration_success.stmt.end(),
            group_capture_appends.begin(),
            group_capture_appends.end()
        );
        if (iteration_success.expr.empty()) {
            builder.getData().insert(builder.getData().end(),
                iteration_success.stmt.begin(), iteration_success.stmt.end());
        } else {
            builder.getData().push_back(LangAPI::If::createStatement(iteration_success));
        }
    }

    // For + and *, the final attempt necessarily fails. The post-loop
    // success condition is based on the completed repetition, not on the
    // last attempted element. '+' is validated by handle_plus_qualifier.
    if (is_repeated) {
        group_success_condition.expr.clear();
    }

    // Optional groups can fail before a child sets its success flag.
    // Declarations are hoisted during optimizeIR(), and their initializers
    // may be stripped. Reset every child flag before any optional attempt so
    // the post-group success condition never reads an indeterminate bool.
    if (quantifier == '?') {
        std::set<std::string> initialized;
        for (const auto& ret : return_vars) {
            if (!ret.svar.name.empty() && initialized.insert(ret.svar.name).second) {
                statements.push_back(assignSvar(ret.svar, false));
            }
        }
    }

    // Emit the group's parsing operations.
    pushBasedOnQuantifier(
        builder,
        rule,
        shadow_var,
        uvar,
        var,
        quantifier
    );

    for (const auto& success_name : used_vars) {
        raiseVarsTop(
            statements,
            statements,
            success_name,
            true,
            false,
            true
        );
    }

    // Only perform value extraction after successful parsing.
    auto& success_statements = group_success_condition.stmt;

    // Fetch group values before reading the result variable.
    if (!is_repeated) {
        success_statements.insert(
            success_statements.end(),
            fetch_var_statements.begin(),
            fetch_var_statements.end()
        );
    }

    // Initialize/update shadow values before using them.
    if (!is_repeated) {
        success_statements.insert(
            success_statements.end(),
            shadow_var_assign_block.begin(),
            shadow_var_assign_block.end()
        );
    }

    success_statements.push_back(
        LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
            .name = LangAPI::Symbol{svar.name},
            .value = LangAPI::Bool::createExpression(LangAPI::Bool {
                .value = true
            })
        })
    );

    const bool has_assignable_value =
        var.type != LangAPI::ValueType::Undef ||
        !shadow_var.name.empty();

    if (has_assignable_value) {
        const auto& source_name =
            shadow_var.name.empty()
                ? var.name
                : shadow_var.name;

        success_statements.push_back(shadowCompatible(LangAPI::Symbol::createExpression(LangAPI::Symbol{uvar.name}), LangAPI::Symbol::createExpression(LangAPI::Symbol{source_name})));
    }
    if (quantifier != '?') {
        success_statements.push_back(
            LangAPI::PopPosCounter::createStatement(LangAPI::PopPosCounter {})
        );
    }

    if (group_success_condition.expr.empty()) {
        statements.insert(
            statements.end(),
            success_statements.begin(),
            success_statements.end()
        );
    } else {
        statements.push_back(
            LangAPI::If::createStatement(
                group_success_condition
            )
        );
    }

    if (quantifier == '?') {
        statements.push_back(grammarComment(rule, "optional group end; release saved position"));
        statements.push_back(LangAPI::PopPosCounter::createStatement(LangAPI::PopPosCounter {}));
    }

    pushConvResult(
        rule,
        is_repeated ? uvar : var,
        uvar,
        svar,
        shadow_var,
        quantifier
    );
    // A captured repetition is a single AST value (the collected array).
    // Do not leak the child alternative's scalar export: it would compete
    // with the group's vector in the enclosing capture/data-block selector.
    if (!(is_repeated && rule.prefix.is_key_value)) {
        exports_list.insert(exports_list.end(),
            group_capture_exports.begin(), group_capture_exports.end());
    }
}

void LLIR::CsequenceBuilder::build() {
    //cpuf::printf("csequence\n");
    const auto &csequence = rule.getCsequence();

    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    LangAPI::Expression expr;

    if (csequence.negative) {
        expr = {
            LangAPI::ExpressionValue { LangAPI::ExpressionElement::Not},
            LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupOpen}
        };
    }

    bool first = true;
    std::size_t count = 0;
    auto push_comparasion_with_character_to_expression = [&](LangAPI::Char c) {
        if (!first)
            expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Or });
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Equal });
        expr.push_back(LangAPI::Char::createExpressionValue(c));
    };
    for (const auto c : csequence.characters) {
        push_comparasion_with_character_to_expression(LangAPI::Char {.value = c});
        first = false;
    }
    for (const auto c : csequence.escaped) {
        push_comparasion_with_character_to_expression(LangAPI::Char {.value = c, .escaped = true});
        first = false;
    }
    for (const auto &[from, to] : csequence.diapasons) {
        if (!first)
            expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Or});
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupOpen});
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::HigherOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = from}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::And});
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::LowerOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = to}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupClose});
        first = false;
    }
    if (csequence.negative) {
        if (rule.quantifier == '+' || rule.quantifier == '*') {
            expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::LowerOrEqual});
            expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true}));
            expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::NotEqual});
            expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = '0', .escaped = true}));
        }
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupClose});
    }
    if (rule.quantifier == '\0')
        var.type = { LangAPI::ValueType::Char };
    else
        var.type = {LangAPI::ValueType::String};
    statements.push_back(LangAPI::Variable::createStatement(var));
    statements.push_back(LangAPI::Variable::createStatement(svar));
    auto stmt = createDefaultStatements(var, svar);
    auto shadow_var = pushBasedOnQualifier(rule, expr, stmt, uvar, var, svar, rule.quantifier, false);
    pushConvResult(rule, var, uvar, svar, shadow_var, rule.quantifier);
}
void LLIR::StringBuilder::build() {
    const auto &str = rule.getString();
    const auto &value = str.value;
    auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    LangAPI::Expression expr;
    if (value.size() == 0)
        return;
    if (str.count_strlen() == 1) {
        // micro optimization - compare as single character for single character strings
        expr = {
            LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true}),
            LangAPI::ExpressionValue { LangAPI::ExpressionElement::Equal},
            value[0] == '\\' ? LangAPI::Char::createExpressionValue(LangAPI::Char {.value = value[1]}) : LangAPI::Char::createExpressionValue(LangAPI::Char {.value = value[1], .escaped = true})
        };
        var.type.type = LangAPI::ValueType::Char;
    } else {
        expr = {
            LangAPI::StringCompare::createExpressionValue(LangAPI::StringCompare {.str = LangAPI::String { .value = value }, .is_string = true})
        };
        var.type = {LangAPI::ValueType::Char};
    }
    if (corelib::text::isAllAlpha(value)) {
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::And});
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Not});
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupOpen});

        // current >= 'a'
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = str.count_strlen()}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::HigherOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = 'a', .escaped = true}));

        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::And});

        // current <= 'z'
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = str.count_strlen()}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::LowerOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = 'z', .escaped = true}));

        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Or});

        // current >= 'A'
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = str.count_strlen()}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::HigherOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = 'A', .escaped = true}));

        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::And});

        // current <= 'Z'
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = str.count_strlen()}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::LowerOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = 'Z', .escaped = true}));

        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Or});

        // current >= '0'
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = str.count_strlen()}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::HigherOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = '0', .escaped = true}));

        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::And});

        // current <= '9'
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = str.count_strlen()}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::LowerOrEqual});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = '9', .escaped = true}));

        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Or});

        // current == '_'
        expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = str.count_strlen()}));
        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Equal});
        expr.push_back(LangAPI::Char::createExpressionValue(LangAPI::Char {.value = '_', .escaped = true}));

        expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupClose});
    }
    LangAPI::Statements block = createDefaultStatements(var, svar);
    statements.push_back(LangAPI::Variable::createStatement(var));
    statements.push_back(LangAPI::Variable::createStatement(svar));
    pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
    pushConvResult(rule, var, uvar, svar, {}, rule.quantifier);
}
// void LLIR::HexBuilder::build() {
//     //cpuf::printf("hex\n");
//     auto data = rule.getHex().hex_chars;
//     LangAPI::Expression expr = {};
//     auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
//     auto var = createEmptyVariable(generateVariableName());
//     auto svar = createSuccessVariable();
//     var.type = {LangAPI::ValueType::String};
//     LangAPI::Statements block = createDefaultStatements(var, svar);
//     bool is_first = true, is_negative = false;
//     if (rule.quantifier == '\0') {
//         expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Not});
//         expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupOpen});
//         is_negative = true;
//     }
//     if (data.size() % 2 != 0)
//         data.insert(data.begin(), '0');
//     for (std::size_t i = 0; i < data.size(); i += 2) {
//         std::string hex(data.data() + i, 2);
//         if (!is_first)
//             expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::And});
//         is_first = false;
//         expr.push_back(LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true, .offset = i}));
//         expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::Equal});
//         expr.push_back(Hex::createExpressionValue(Hex {.hex = hex}));
//     }
//     if (is_negative) {
//         expr.push_back(LangAPI::ExpressionValue { LangAPI::ExpressionElement::GroupClose});
//     }
//     //cpuf::printf("hex_open\n");
//     statements.push_back(LangAPI::Variable::createStatement(var));
//     statements.push_back(LangAPI::Variable::createStatement(svar));
//     auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
//     pushConvResult(rule, var, uvar, svar, shadow_var, rule.quantifier);
// }
// void LLIR::BinBuilder::build() {
//     //cpuf::printf("hex\n");
//     auto data = rule.getBin().bin_chars;
//     LangAPI::Expression expr = {};
//     auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
//     auto var = createEmptyVariable(generateVariableName());
//     auto svar = createSuccessVariable();
//     LangAPI::Statements block = {
//         {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
//         {LLIR::types::INCREASE_POS_COUNTER},
//     };
//     bool is_first = true, is_negative = false;
//     if (rule.quantifier == '\0') {
//         expr.push_back({LLIR::condition_types::NOT});
//         expr.push_back({LLIR::condition_types::GROUP_OPEN});
//         is_negative = true;
//     }
//     while (data.size() % 8 != 0)
//         data.insert(data.begin(), '0');
//     for (std::size_t i = 0; i < data.size(); i += 8) {
//         std::string bin(data.data() + i, 8);
//         auto as_hex = hex::from_binary(bin);
//         as_hex.erase(as_hex.begin(), as_hex.begin() + 2);
//         if (!is_first)
//             expr.push_back({LLIR::condition_types::AND});
//         is_first = false;
//         expr.push_back({LLIR::condition_types::CURRENT_CHARACTER, i});
//         expr.push_back({LLIR::condition_types::EQUAL});
//         expr.push_back({LLIR::condition_types::HEX, as_hex});
//     }
//     if (is_negative) {
//         expr.push_back({LLIR::condition_types::GROUP_CLOSE});
//     }
//     push({LLIR::types::VARIABLE, var});
//     push({LLIR::types::VARIABLE, svar});
//     auto shadow_var = pushBasedOnQualifier(rule, expr, block, uvar, var, svar, rule.quantifier, false);
//     pushConvResult(rule, var, uvar, svar, shadow_var, rule.quantifier);
// }
void LLIR::NameBuilder::build() {
    // cpuf::printf("Rule_other");
    auto name = rule.getName().name;
    //cpuf::printf(", name: %s\n", name_str);
    // A rule inside a repetition needs a value variable even when anonymous:
    // its extracted node is the element appended to the shadow array.
    auto uvar = createEmptyVariable(
        !rule.prefix.name.empty() ? rule.prefix.name :
        (insideLoop || rule.quantifier == '*' || rule.quantifier == '+')
            ? "uvar" + generateVariableName() : ""
    );
    auto var = createEmptyVariable(corelib::text::join(name, "_") + generateVariableName());
    auto svar = createSuccessVariable();
    LangAPI::Variable shadow_var;
    bool isCallingToken = corelib::text::isUpper(name.back());
    // if (*has_symbol_follow) {
    //     symbol_follow->back().first = name;
    // }
    LangAPI::Symbol type_name {name};
    if (isCallingToken) {
        var.type = { LangAPI::ValueType::Token, LangAPI::Type {type_name} };
        uvar.type = var.type;
    } else {
        var.type =  { isCallingToken ? LangAPI::ValueType::TokenResult : LangAPI::ValueType::RuleResult, LangAPI::Type { type_name } };
        uvar.type = { isCallingToken ? LangAPI::ValueType::Token : LangAPI::ValueType::Rule, LangAPI::Type { type_name } };
    }
    shadow_var.type.type = LangAPI::ValueType::Array;
    shadow_var.type.template_parameters = {uvar.type};
    LangAPI::Statements statements;
    statements.push_back(LangAPI::Variable::createStatement(var));
    statements.push_back(LangAPI::Variable::createStatement(svar));
    if (isCallingToken) {
        LangAPI::Symbol token_name{name};
        token_name.path.insert(token_name.path.begin(), "Types");
        LangAPI::Expression expr = {
            LangAPI::CheckVariant{
                .type = std::make_shared<LangAPI::Type>(
                    LangAPI::Type{LangAPI::ValueType::Token,
                                  LangAPI::Type{LangAPI::Symbol{token_name}}}),
                .sym = LangAPI::Pos::createExpression(
                    LangAPI::Pos{.dereference = true})
            }
        };

        const bool repeated_name = rule.quantifier == '*' || rule.quantifier == '+';
        if (repeated_name)
            uvar.type = shadow_var.type;
        // Variables must be declared once, outside the match condition.
        this->statements.insert(this->statements.end(),
                                statements.begin(), statements.end());
        if (!uvar.name.empty()) {
            this->statements.push_back(
                LangAPI::Variable::createStatement(uvar));
        }

        // Match body: capture current token, mark success and consume ONCE.
        // Never advance the input before evaluating CheckVariant.
        LangAPI::Statements body = createDefaultStatements(var, svar, name);

        LangAPI::Statements append_to_shadow;
        if (insideLoop || rule.quantifier == '*' || rule.quantifier == '+') {
            // The vector is declared outside the conditional/loop.  Only
            // successful matches append their captured token.
            shadow_var = add_shadow_variable(this->statements,
                                             append_to_shadow, var);
        }
        // Append once, after the current token was captured.
        body.insert(body.end(), append_to_shadow.begin(), append_to_shadow.end());
        if (rule.quantifier != '*' && rule.quantifier != '+')
            BuilderBase::createAssignUvarBlock(body, uvar, var, {});
        switch (rule.quantifier) {
            case '?':
                this->statements.push_back(LangAPI::If::createStatement(
                    LangAPI::If{expr, std::move(body)}));
                break;
            case '*':
                this->statements.push_back(LangAPI::While::createStatement(
                    LangAPI::While{expr, std::move(body)}));
                break;
            case '+':
                handle_plus_qualifier(rule,
                    LangAPI::ConditionalElement{.expr = expr,
                                                .stmt = std::move(body)},
                    uvar, var, shadow_var);
                break;
            default: {
                expr.insert(expr.begin(), LangAPI::ExpressionValue{
                    LangAPI::ExpressionElement::Not});
                expr.insert(expr.begin() + 1, LangAPI::ExpressionValue{
                    LangAPI::ExpressionElement::GroupOpen});
                expr.push_back(LangAPI::ExpressionValue{
                    LangAPI::ExpressionElement::GroupClose});
                this->statements.push_back(LangAPI::If::createStatement(
                    LangAPI::If{std::move(expr), LangAPI::Statements{
                         parserFailure(rule, "required token did not match"),
                         LangAPI::Return::createStatements(LangAPI::Return{}).front()
                     }}));
                this->statements.insert(this->statements.end(),
                                        body.begin(), body.end());
                break;
            }
        }
        if (repeated_name && !uvar.name.empty()) {
            this->statements.push_back(grammarComment(rule, "repeat token; export all matched elements"));
            this->statements.push_back(LangAPI::Expression::createStatement(
                shadowCompatible(LangAPI::Symbol::createExpression(LangAPI::Symbol{uvar.name}), LangAPI::Symbol::createExpression(LangAPI::Symbol{shadow_var.name}))
            ));
        }
    } else {
        LangAPI::Expression expr;
        // Keep declarations outside the quantifier/conditional.
        // createDefaultCall only constructs the invocation and status test.
        auto call = createDefaultCall(statements, var,
                                      corelib::text::join(name, "_"), expr);
        shadow_var = pushBasedOnQualifier(rule, expr, statements, uvar, var,
                                          svar, call, rule.quantifier, name);
    }
    pushConvResult(rule, var, uvar, svar, shadow_var, rule.quantifier);
}
void LLIR::NospaceBuilder::build() {
    addSpaceSkip = false;
    removePrevSpaceSkip();
}
// void LLIR::EscapedBuilder::build() {
//     //cpuf::printf("Rule_escaped\n");
//     const auto &escaped_c = rule.getEscaped();
//
//     LangAPI::Expression expression;
//     switch (escaped_c.c) {
//         case 's':
//             // do not add skip of spaces
//             addSpaceSkip = false;
//             removePrevSpaceSkip();
//             //cpuf::printf("ON_EXPRESSION\n")
//             expression = {
//                 LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true}),
//                 LangAPI::ExpressionValue { LangAPI::ExpressionElement::NotEqual},
//                 LangAPI::Char::createExpressionValue(LangAPI::Char {.value = ' '})
//             };
//             expression = {
//                 {LLIR::condition_types::CURRENT_CHARACTER, (std::size_t) 0},
//                 {LLIR::condition_types::NOT_EQUAL},
//                 {LLIR::condition_types::CHARACTER, ' '}
//             };
//             break;
//         default:
//             throw Error("Undefined char");
//
//     }
//     //cpuf::printf("escaped_open\n");
//     auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
//     auto var = createEmptyVariable(generateVariableName());
//     auto svar = createSuccessVariable();
//     var.type = {LLIR::var_types::CHAR};
//     LangAPI::Statements block = {{LLIR::types::EXIT}};
//     if (!isFirst) {
//         block.insert(block.begin(), {LLIR::types::ERR, getErrorName(rule)});
//     }
//     auto block_after = createDefaultStatements(var, svar);
//     push({LLIR::types::VARIABLE, var});
//     push({LLIR::types::VARIABLE, svar});
//     auto shadow_var = pushBasedOnQualifier(rule, expression, block, uvar, var, svar, rule.quantifier, true);
//     push({LLIR::types::IF, LLIR::condition{expression, block}});
//     add(block_after);
//     //cpuf::printf("escaped_close\n");
//     pushConvResult(rule, var, uvar, svar, shadow_var, rule.quantifier);
// }
void LLIR::AnyBuilder::build() {
    //cpuf::printf("Rule_any\n");
    if (!isToken)
        throw Error("AnyBuilder invoked on non-terminal: {}", fullname);
    auto var = rule.prefix.name.empty() ? createEmptyVariable(generateVariableName()) : createEmptyVariable(rule.prefix.name);
    auto svar = createSuccessVariable();
    var.type = {LangAPI::ValueType::Char};
    LangAPI::Statements stmt = LangAPI::Return::createStatements(LangAPI::Return {});;
    if (!isFirst) {
        auto rm = AST::RuleMember {.value = AST::RuleMemberAny() };
        // stmt.insert(stmt.begin(), LangAPI::ReportError::createStatement(LangAPI::ReportError {.message = getErrorName(rm)}));;
    }
    LangAPI::Statements stmt_after = createDefaultStatements(var, svar);
    LangAPI::Expression expression = {
        LangAPI::Pos::createExpressionValue(LangAPI::Pos {.dereference = true}),
        LangAPI::ExpressionValue { LangAPI::ExpressionElement::Equal },
        isToken ? LangAPI::Char::createExpressionValue(LangAPI::Char {.value = '0', .escaped = true}) : LangAPI::Symbol::createExpressionValue(LangAPI::Symbol {{"Tokens", "NONE"}}),
    };
    statements.push_back(LangAPI::Variable::createStatement(var));
    statements.push_back(LangAPI::Variable::createStatement(svar));
    statements.push_back(LangAPI::If::createStatement(LangAPI::If {expression, stmt}));;
    statements.insert(statements.end(), stmt_after.begin(), stmt_after.end());
    pushConvResult(rule, var, {}, svar, {}, rule.quantifier);
}
/*
 * build PEG style parser. Right now DFA based is preffered
 * But may come back later
 */

// auto LLIR::OpBuilder::createBlock(const stdu::vector<AST::RuleMember> &rules, std::size_t index, LLIR::variable &var, LLIR::variable &svar) -> LangAPI::Statements {
//     //[[assume(rules.size() >= 2)]];
//     if (index >= rules.size()) {
//         return {{LLIR::types::EXIT}};
//     }
//
//     LLIR::ConvertionResult success_var;
//     stdu::vector<LangAPI::Statements> blocks;
//     stdu::vector<LangAPI::Expression> conditions;
//     auto rule = rules[index++];
//     std::unique_ptr<LLIR::MemberBuilder> builder = nullptr;
//     if (rule.isGroup()) {
//         char new_qualifier;
//         if (rule.quantifier == '+')
//             new_qualifier = '*';
//         else if (rule.quantifier == '\0')
//             new_qualifier = '?';
//         auto prev_quantifier = rule.quantifier;
//         rule.quantifier = new_qualifier;
//         builder = std::make_unique<LLIR::MemberBuilder>(*this, rule);
//         builder->build();
//         rule.quantifier = prev_quantifier;
//     }
//     else {
//         builder = std::make_unique<LLIR::MemberBuilder>(*this, rule);
//         builder->build();
//     }
//     builder->getData();
//     stdu::vector<int> erase_indices;
//     stdu::vector<int> push_indices;
//     if (rule.isGroup()) {
//         builder->getData().back().type = LLIR::types::RESET_POS_COUNTER; // remove space skip
//         auto cond = LLIR::condition {
//             LangAPI::Expression {
//                 {LLIR::condition_types::NOT}, {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = success_var.svar}}
//             },
//             createBlock(rules, index, var, svar),
//         };
//         auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
//         auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
//         if (!v.name.empty() && v.type.type != LLIR::var_types::UNDEFINED) {
//             cond.else_block = {{
//                 LLIR::types::ASSIGN_VARIABLE,
//                 LLIR::variable_assign
//                 {
//                     var.name,
//                     LLIR::var_assign_types::ASSIGN,
//                     LLIR::assign {
//                         LLIR::var_assign_values::VAR_REFER,
//                         LLIR::var_refer {.var = v }
//                     }
//                 }
//             }};
//         }
//         push({LLIR::types::IF, cond});
//     } else {
//         for (int i = 0; i < builder->getData().size(); i++) {
//             auto &el = builder->getData()[i];
//             if (el.type == LLIR::types::IF) {
//                 auto val = std::any_cast<LLIR::condition>(el.value);
//                 // get recursively nested block
//                 val.block = createBlock(rules, index, var, svar);
//                 // change condition and remove it's content into else blocks
//                 for (int j = i + 1; j < builder->getData().size(); j++) {
//                     auto el = builder->getData()[j];
//                     erase_indices.push_back(j);
//                     if (el.type != LLIR::types::SKIP_SPACES) {
//                         if (el.type == LLIR::types::ASSIGN_VARIABLE) {
//                             auto assignment = std::any_cast<LLIR::variable_assign>(el.value);
//                             assignment.assign_type = LLIR::var_assign_types::ASSIGN;
//                             el.value = assignment;
//                         }
//                         val.else_block.push_back(el);
//                     }
//                 }
//                 // push into else block an assignment to variable
//                 if (var.type.type == LLIR::var_types::ARRAY) {
//                     val.else_block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { var.name, {LLIR::function_call {"push", {stdu::vector<LangAPI::Expression> {{LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = success_var.var}}}}}}}}});
//                 } else {
//                     auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
//                     auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
//                     val.else_block.push_back({
//                         LLIR::types::ASSIGN_VARIABLE,
//                         LLIR::variable_assign
//                         {
//                             var.name,
//                             LLIR::var_assign_types::ASSIGN,
//                             LLIR::assign {
//                                 LLIR::var_assign_values::VAR_REFER,
//                                 LLIR::var_refer {.var = v}
//                             }
//                         }
//                     });
//                 }
//
//                 // update the value
//                 el.value = val;
//             }
//         }
//     }
//
//     for (auto it = erase_indices.rbegin(); it != erase_indices.rend(); ++it) {
//         builder->getData().erase(builder->getData().begin() + *it);
//     }
//     return builder->getData();
// }
//
// void LLIR::OpBuilder::build() {
//     // cpuf::printf("Rule_op\n");
//     auto &rules = rule.getOp();
//     auto uvar = !rule.prefix.name.empty() ? createEmptyVariable(rule.prefix.name) : createEmptyVariable("");
//     auto var = createEmptyVariable(generateVariableName());
//     auto svar = createSuccessVariable();
//     auto block = createDefaultBlock(var, svar);
//     // cpuf::printf("op prefix: %$\n", rule.prefix);
//     // Add success variable
//     var.type = {deduceVarTypeByProd(rule)};
//     if (insideLoop && var.type.type != LLIR::var_types::STRING) {
//         var.type.templ = {{var.type.type}};
//         var.type.type = LLIR::var_types::ARRAY;
//     }
//     if (var.type.type != LLIR::var_types::UNDEFINED) {
//         push({LLIR::types::VARIABLE, var});
//     }
//     push({LLIR::types::VARIABLE, svar});
//     if (!uvar.name.empty()) {
//         uvar.type = var.type;
//         push({LLIR::types::VARIABLE, uvar});
//     }
//     const auto res = createBlock(rules.options, 0, var, svar);
//     add(res);
//     block.erase(block.begin()); // remove variable assignment (it is done in else blocks)
//     block.erase(block.end() - 1);
//     // Append default block
//     add(block);
//     const auto shadow_var = createEmptyVariable("");
//     if (!uvar.name.empty())
//         push(createAssignUvarBlock(uvar, var, shadow_var));
//     pushConvResult(rule, var, uvar, svar, shadow_var, rule.quantifier);
// }

// Alternative lookahead sets are computed and cached by AST::Tree.
bool LLIR::OpBuilder::checkLLkConflicts(
    const std::vector<std::set<LookaheadSeq>>& perAlt,
    std::vector<std::tuple<std::size_t, std::size_t, LookaheadSeq>>* conflicts
) {
    const auto overlaps = [](const LookaheadSeq& a, const LookaheadSeq& b) {
        return std::equal(a.begin(), a.begin() + std::min(a.size(), b.size()), b.begin());
    };

    bool ok = true;
    for (std::size_t i = 0; i < perAlt.size(); ++i) {
        for (std::size_t j = i + 1; j < perAlt.size(); ++j) {
            for (const auto& a : perAlt[i]) {
                std::cout << "preAlt: " << std::endl;
                for (const auto& b : perAlt[j]) {
                    if (!overlaps(a, b)) continue;
                    ok = false;
                    if (conflicts)
                        conflicts->emplace_back(i, j, a.size() <= b.size() ? a : b);

                    std::cerr
                        << "LL(k) conflict: alternative "
                        << i << " versus " << j
                        << ", lengths " << a.size()
                        << " and " << b.size()
                        << std::endl;
                }
            }
        }
    }
    return ok;
}

LangAPI::Statements LLIR::OpBuilder::buildDecisionTree(
    const std::vector<std::set<LookaheadSeq>>& perAlt,
    const std::vector<std::shared_ptr<AST::RuleMember>>& op,
    const std::vector<std::size_t>& candidates,
    std::size_t depth,
    std::size_t k,
    const LangAPI::Variable& result_var,
    const LangAPI::Variable& success_var
) {
    // `depth` selects which lookahead token this level of the decision
    // tree disambiguates on: depth 0 is the current token, depth 1 is one
    // token further ahead, etc. (`seq[depth]` below already buckets
    // alternatives by the right token.) The switch's own runtime check
    // must look at that SAME token -- `pos` offset by `depth` -- or every
    // recursive level ends up re-testing the current token instead of
    // advancing its lookahead, so no case at depth > 0 ever matches
    // whatever alternative actually needed k > 1 to disambiguate (e.g.
    // `main: rule | adv_rule`, where both start with ID and only diverge
    // on the second token).

    LangAPI::Switch ss {
        .expression = LangAPI::Cast::createExpression(
            LangAPI::Cast {
                .type = std::make_shared<LangAPI::Type>(LangAPI::Type {
                    LangAPI::Symbol {"Tokens"}
                }),
                .what = LangAPI::StorageSymbol::createExpression(LangAPI::StorageSymbol {
                    LangAPI::Pos::createExpression(LangAPI::Pos {.dereference = true}),
                    stdu::vector<LangAPI::StorageSymbol::PathPart> {LangAPI::IspaLibSymbol {.exports = LangAPI::StdlibExports::VariantIndex}}
                })
            }
        )
    };

    std::map<
        stdu::vector<std::string>,
        std::set<std::size_t>
    > buckets;

    for (const auto index : candidates) {
        for (const auto& seq : perAlt[index]) {
            if (depth < seq.size()) {
                buckets[seq[depth]].insert(index);
            }
        }
    }

    for (const auto& [symbol, alternatives] : buckets) {
        ss.cases.emplace_back();
        auto& cs = ss.cases.back();

        auto rv_sym = LangAPI::Symbol{corelib::text::join(symbol, "_")};
        rv_sym.path.insert(
            rv_sym.path.begin(), "Tokens"
        );

        cs.first = LangAPI::Cast::createRValue(rv_sym);

        if (alternatives.size() == 1) {
            const auto index = *alternatives.begin();

            MemberBuilder builder(*this, *op[index]);
            builder.build();

            cs.second = builder.getData();

            // Lookahead is speculative: the selected alternative must parse
            // from the original input position, not from the lookahead cursor.
            // At depth 0 this is harmless; at depth > 0 it is essential.
            // The surrounding position-counter scopes still propagate the
            // selected parser's final iterator after the branch completes.
            cs.second.insert(cs.second.begin(), LangAPI::VariableAssignment::createStatement(
                LangAPI::VariableAssignment{
                    .name = LangAPI::Symbol{
                        "lookahead_pos_" + std::to_string(nesting)
                    },
                    .value = LangAPI::Symbol::createExpression(
                        LangAPI::Symbol{"lookahead_pos_1"}
                    )
                }
            ));


            const auto& returns = builder.getReturnVars();

            if (returns.empty()) {
                throw Error(
                    "OpBuilder: alternative {} has no return value",
                    index
                );
            }

            const auto& selected = returns.front();

            if (selected.var.name.empty()) {
                throw Error(
                    "OpBuilder: alternative {} has an unnamed result",
                    index
                );
            }

            // A selected rule must have succeeded before its node is
            // assigned to the outer result variant.
            if (!selected.svar.name.empty()) {
                LangAPI::Expression failed = {
                    LangAPI::ExpressionValue{
                        LangAPI::ExpressionElement::Not
                    },
                    LangAPI::Symbol::createExpressionValue(
                        LangAPI::Symbol{selected.svar.name}
                    )
                };

                cs.second.push_back(
                    LangAPI::If::createStatement(
                        LangAPI::If{
                            std::move(failed),
                            [&]() -> LangAPI::Statements {
                                auto failure = insideLoop
                                    ? LangAPI::Break::createStatements(LangAPI::Break{})
                                    : LangAPI::Return::createStatements(LangAPI::Return{});
                                failure.insert(failure.begin(), parserFailure(
                                    *op[index], "selected LL(k) alternative failed"));
                                return failure;
                            }()
                        }
                    )
                );
            }

            LangAPI::Expression selected_value;

            const auto type = selected.var.type.getValueType();

            if (type == LangAPI::ValueType::RuleResult ||
                type == LangAPI::ValueType::TokenResult) {

                // MatchResult<...> -> Node<...>
                selected_value =
                    LangAPI::StorageSymbol::createExpression(
                        LangAPI::StorageSymbol{
                            LangAPI::Symbol::createExpression(
                                LangAPI::Symbol{selected.var.name}
                            ),
                            stdu::vector<
                                LangAPI::StorageSymbol::PathPart
                            >{
                                LangAPI::IspaLibSymbol{
                                    .exports =
                                        LangAPI::StdlibExports::MatchResultValue
                                }
                            }
                        }
                    );

                } else {
                    // Already a Node or another directly assignable value.
                    selected_value =
                        LangAPI::Symbol::createExpression(
                            LangAPI::Symbol{selected.var.name}
                        );
                }

            // Inside a quantified group, an unsuccessful branch ends the
            // speculative switch/iteration rather than the whole parser.
            if (insideLoop) {
                processExitStatements(cs.second);
            }

            // Store the selected alternative in the outer variant.
            cs.second.push_back(
                LangAPI::VariableAssignment::createStatement(
                    LangAPI::VariableAssignment{
                        .name = LangAPI::Symbol{result_var.name},
                        .value = std::move(selected_value)
                    }
                )
            );

            // Mark the alternative as successful.
            cs.second.push_back(
                LangAPI::VariableAssignment::createStatement(
                    LangAPI::VariableAssignment{
                        .name = LangAPI::Symbol{success_var.name},
                        .value = LangAPI::Bool::createExpression(
                            LangAPI::Bool{.value = true}
                        )
                    }
                )
            );
        } else {
            if (depth + 1 >= k) {
                throw Error(
                    "Unresolved LL(k) decision at depth {}",
                    depth
                );
            }

            std::vector<std::size_t> narrowed(
                alternatives.begin(),
                alternatives.end()
            );
            nesting++;
            auto nested_lookup_statements = buildDecisionTree(
                perAlt,
                op,
                narrowed,
                depth + 1,
                k,
                result_var,
                success_var
            );
            nesting--;
            cs.second.insert(cs.second.end(), nested_lookup_statements.begin(), nested_lookup_statements.end());
            // The nested tree handles rollback before its PopPosCounter.
            // Restoring here is too late: the child's cursor has already
            // propagated to this level.

        }
    }
    if (nesting == 1) {
        return LangAPI::Statements {LangAPI::PushPosCounter::createStatement(LangAPI::PushPosCounter {.name = "lookahead_pos_" + std::to_string(nesting)}), ss, LangAPI::PopPosCounter::createStatement(LangAPI::PopPosCounter {})};
    } else {
        // this is nested call => we need to increase pos counter
        return LangAPI::Statements {
            LangAPI::PushPosCounter::createStatement(LangAPI::PushPosCounter {.name = "lookahead_pos_" + std::to_string(nesting)}),
            LangAPI::CounterIncreament::createStatement(LangAPI::CounterIncreament {}),
            // LL(k) lookahead counts significant tokens. Skip insignificant
            // whitespace between lookahead positions just as the parser does.
            // This only affects the speculative lookahead cursor.
            LangAPI::SkipSpaces::createStatement(LangAPI::SkipSpaces{.isToken = isToken}),
            ss,
            // A failed nested choice must not consume lookahead tokens.
            // Restore the nested cursor BEFORE PopPosCounter propagates it.
            LangAPI::If::createStatement(LangAPI::If{
                LangAPI::Expression{
                    LangAPI::ExpressionValue{LangAPI::ExpressionElement::Not},
                    LangAPI::Symbol::createExpressionValue(LangAPI::Symbol{success_var.name})
                },
                LangAPI::VariableAssignment::createStatements(LangAPI::VariableAssignment{
                    .name = LangAPI::Symbol{"lookahead_pos_" + std::to_string(nesting)},
                    .value = LangAPI::Symbol::createExpression(
                        LangAPI::Symbol{"lookahead_pos_" + std::to_string(nesting - 1)})
                })
            }),
            LangAPI::PopPosCounter::createStatement(LangAPI::PopPosCounter {})
        };
    }
}
auto LLIR::OpBuilder::resolveLLk(
    const std::vector<std::shared_ptr<AST::RuleMember>>& op,
    const stdu::vector<std::string>& rule_name,
    AST::Tree& tree,
    std::size_t max_k
) -> LLkResolution {
    LLkResolution result;

    for (std::size_t k = 1; k <= max_k; ++k) {
        std::vector<std::set<LookaheadSeq>> perAlt;
        perAlt.reserve(op.size());
        bool valid = !op.empty();

        for (std::size_t alt_index = 0; alt_index < op.size(); ++alt_index) {
            const auto& alt = op[alt_index];
            const auto lookahead = tree.getAlternativeLookahead(*alt, rule_name, k);
            std::set<LookaheadSeq> converted(lookahead.begin(), lookahead.end());

            // Distinguish an invalid/incomplete lookahead computation from
            // a real overlap between two alternatives. Previously `valid &&`
            // short-circuited checkLLkConflicts, so an empty alternative
            // silently produced the misleading "LL(k) conflict" exception.
            if (converted.empty()) {
                valid = false;
                std::cerr << "[LL(k)] k=" << k << " alt=" << alt_index
                          << " has EMPTY lookahead set; inspect FIRST_k of "
                          << *alt << "\n";
            }
            for (const auto& seq : converted) {
                if (seq.empty()) {
                    valid = false;
                    std::cerr << "[LL(k)] k=" << k << " alt=" << alt_index
                              << " has an EPSILON lookahead (FOLLOW_k not resolved)\n";
                }
                std::cerr << "[LL(k)] k=" << k << " alt=" << alt_index << " [";
                for (const auto& token : seq)
                    std::cerr << token << " ";
                std::cerr << "]\n";
            }
            perAlt.push_back(std::move(converted));
        }

        result.k = k;
        result.perAlt = std::move(perAlt);
        // Always check nonempty alternatives, even if another alternative has
        // an invalid lookahead. This gives conflict diagnostics instead of
        // silently skipping the entire check due to short-circuiting.
        const bool conflict_free = checkLLkConflicts(result.perAlt);
        if (!valid) {
            std::cerr << "[LL(k)] k=" << k
                      << " unresolved: missing or epsilon-only lookahead; "
                         "this is NOT proof of overlapping alternatives\n";
        } else if (conflict_free) {
            result.resolved = true;
            return result;
        }
    }

    result.resolved = false;
    return result;
}


void LLIR::OpBuilder::build() {
    // A quantified choice may fail without being a parsing error.
    SpeculativeMatchScope speculative(
        rule.quantifier == '?' || rule.quantifier == '*' || rule.quantifier == '+');
    const auto &op = rule.getOp().options;
    auto var = createEmptyVariable("");
    var.type = deduceVarTypeByRuleMember(rule);
    undoRuleResult(var.type.getValueType());
    var.name = generateVariableName();

    bool uvar_is_named = !rule.prefix.name.empty();
    LangAPI::Variable uvar;
    if (uvar_is_named && !rule.prefix.is_key_value) {
        var.name = rule.prefix.name;
        uvar = var;
    } else if (uvar_is_named) {
        uvar = createEmptyVariable(rule.prefix.name);
        uvar.type = var.type;
    } else {
        uvar = createEmptyVariable("");
        uvar.type = var.type;
    }

    auto svar = createSuccessVariable();
    svar.value = LangAPI::Bool::createExpression(LangAPI::Bool {.value = false});
    statements.push_back(LangAPI::Variable::createStatement(var));
    statements.push_back(LangAPI::Variable::createStatement(svar));
    // Initialization must be executable, not only a Variable initializer:
    // raiseVarsTop/optimizeIR may hoist declarations and clear initializers.
    statements.push_back(grammarComment(rule, "choice; reset match status before selecting an alternative"));
    statements.push_back(assignSvar(svar, false));
    if (corelib::text::isLower(fullname.back())) {
        // This grammar is expected to resolve choices within two tokens.
        // Report genuine ambiguity instead of expanding an unbounded k.
        auto resolution = resolveLLk(op, fullname, tree);

        if (!resolution.resolved) {
            throw Error("LL(k) conflict in rule {}: unresolved within k = {} (inspect common prefixes / left factoring)", fullname, resolution.k);
        }

        // statements.push_back(LangAPI::SkipSpaces::createStatement(LangAPI::SkipSpaces{.isToken = isToken}));
        std::vector<std::size_t> candidates(op.size());
        std::iota(candidates.begin(), candidates.end(), 0);
        auto lookup_statements = buildDecisionTree(
            resolution.perAlt,
            op,
            candidates,
            0,
            resolution.k,
            var,
            svar
        );
        statements.insert(statements.end(), lookup_statements.begin(), lookup_statements.end());

        // FIX: if no case in the switch matched, svar is still false — the
        // alternation failed to find any viable lookahead at runtime (e.g.
        // an unexpected token). Without this check the function falls
        // through and unconditionally reports success with var/uvar left
        // at their default/unset values, exactly matching the symptom of
        // an empty variant in the printed tree.
        LangAPI::Expression not_matched = {
            LangAPI::ExpressionValue{LangAPI::ExpressionElement::Not},
            LangAPI::Symbol::createExpressionValue(LangAPI::Symbol{svar.name})
        };
        statements.push_back(LangAPI::If::createStatement(LangAPI::If{
            std::move(not_matched),
            LangAPI::Statements{
                parserFailure(rule, "no LL(k) alternative matched"),
                LangAPI::Return::createStatements(LangAPI::Return{}).front()
            }
        }));
    }

    if (uvar_is_named && rule.prefix.is_key_value) {
        statements.push_back(LangAPI::Variable::createStatement(uvar));
        statements.push_back(LangAPI::VariableAssignment::createStatement(LangAPI::VariableAssignment {
            .name = LangAPI::Symbol {uvar.name},
            .value = LangAPI::Symbol::createExpression(LangAPI::Symbol {var.name})
        }));
    }

    pushConvResult(rule, var, uvar, svar, {}, rule.quantifier);
}