module;
#include "../../parser/python/parser.hpp"
module UAST.Python;
import std;
namespace {
struct ActionParser : PyRawParser::Parser {
    using PyRawParser::Parser::expr;
    using PyRawParser::Parser::main;
};
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::GLOBAL&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ELIF&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ASSERT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::COMMENT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PASS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DEF&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FINALLY&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::WHILE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::WITH&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MATMUL_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ASYNC&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CONTINUE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RAISE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NONLOCAL&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::TILDE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LSHIFT_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::BREAK&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PERCENT_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PLUS_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::STAR_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::INDENT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DEL&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ELSE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IF&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NOT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MATMUL&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::COMMA&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RPAREN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::SEMICOLON&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NEWLINE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RBRACE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::STRING&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FLOOR_DIV&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::TRUE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::SLASH_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::TRY&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::POWER_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::POWER&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PIPE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::__WS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FOR&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::COLON&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::EXCEPT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NONE_V&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DEDENT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::STAR&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::SLASH&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LBRACKET&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::GT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PLUS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LSHIFT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::GE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IMPORT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FLOOR_DIV_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FALSE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::EQ&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CARET&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AND&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NUMBER&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MINUS_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LPAREN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ID&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AMP&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AMP_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CLASS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MINUS&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DOT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CARET_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RSHIFT_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PERCENT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ARROW&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::OR&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PIPE_ASSIGN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RSHIFT&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RETURN&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FROM&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LBRACE&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RBRACKET&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitand_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitor_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitwise_and&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitwise_or&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitwise_xor&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitxor_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::break_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_arg&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_arg_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_args&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_suffix&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::comparison&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::compound_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::conditional_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::conjunction&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::continue_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::def_header&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_item&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_item_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_items&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::disjunction&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::else_clause&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::except_handlers&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr_list&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr_list_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::factor&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::finally_clause&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::indented_block&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::index_suffix&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::inversion&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::is_op&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::list_expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::not_in&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::not_inversion&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::or_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parenthesized_content&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parenthesized_expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::pass_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::power&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::power_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::primary&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::shift_expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::sum&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::term&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::try_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::try_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::tuple_elements&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::tuple_suffix&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::atom&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::attribute_suffix&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dotted_name&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::except_alias&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::global_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_alias&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::keyword_arg&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::nonlocal_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::sum_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::unary_expr&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::term_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_op&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::shift_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::class_bases&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::annotated_assignment&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assert_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::elif_clause&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::if_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameter_annotation&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameter_default&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::raise_from&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::return_annotation&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::return_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::while_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::compare_op&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::decorator&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_suffix&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::postfix&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::relative_module&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::except_clause&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dotted_as_name&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_name_item&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::class_header&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameter&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::raise_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::compare_tail&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::decorators&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_target&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dotted_as_names&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_names&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_value&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameters&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::class_def&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::decorated_def&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::del_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::for_targets&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_as&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_name&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parenthesized_imports&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::function_header&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::for_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_item&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_targets&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::function_def&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_items&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_from&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::simple_stmt&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::simple_stmts&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::block&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::statement&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::main&, const UAST::SourcePosition&);
UAST::PythonNode snapshot(std::monostate, const UAST::SourcePosition& base) { return {"absent", {}, {}, base, true, {}}; }
UAST::PythonNode snapshot(const std::string& v, const UAST::SourcePosition& base) { return {"string", {}, v, base, false, {}}; }
UAST::PythonNode snapshot(char v, const UAST::SourcePosition& base) { return {"char", {}, std::string(1, v), base, false, {}}; }
template<class T> UAST::PythonNode snapshot(const std::shared_ptr<T>& p, const UAST::SourcePosition& base) {
    return p ? snapshot(*p, base) : UAST::PythonNode{"pointer", {}, {}, base, true, {}};
}
template<class T> UAST::PythonNode snapshot(const ISPA_STD::Node<T>& n, const UAST::SourcePosition& base) {
    if (n.empty()) return {"node", {}, {}, base, true, {}};
    auto p = base;
    if (n.startpos() != std::string::npos) p.offset += n.startpos();
    p.length = n.length();
    if (n.start() && n.startpos() != std::string::npos) {
        for (auto c = n.start() - n.startpos(); c < n.start(); ++c) {
            if (*c == '\n') { ++p.line; p.column = 1; }
            else ++p.column;
        }
    }
    auto out = snapshot(n.data(), base);
    out.position = p;
    return out;
}
template<class... T> UAST::PythonNode snapshot(const std::variant<T...>& v, const UAST::SourcePosition& base) {
    return {"variant", {}, std::to_string(v.index()), base, false, {std::visit([&](const auto& n) { return snapshot(n, base); }, v)}};
}
template<class T> UAST::PythonNode snapshot(const std::vector<T>& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"sequence", {}, {}, base, false, {}};
    for (const auto& n : v) out.children.push_back(snapshot(n, base));
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::GLOBAL& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"GLOBAL", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ELIF& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ELIF", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ASSERT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ASSERT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::COMMENT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"COMMENT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PASS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PASS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DEF& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"DEF", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FINALLY& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"FINALLY", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::WHILE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"WHILE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::WITH& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"WITH", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MATMUL_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"MATMUL_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ASYNC& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ASYNC", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CONTINUE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"CONTINUE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RAISE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RAISE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NONLOCAL& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"NONLOCAL", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::TILDE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"TILDE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LSHIFT_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LSHIFT_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::BREAK& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"BREAK", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PERCENT_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PERCENT_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PLUS_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PLUS_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::STAR_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"STAR_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::INDENT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"INDENT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DEL& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"DEL", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"IS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"IN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ELSE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ELSE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IF& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"IF", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NOT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"NOT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MATMUL& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"MATMUL", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::COMMA& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"COMMA", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RPAREN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RPAREN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::SEMICOLON& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"SEMICOLON", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NEWLINE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"NEWLINE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RBRACE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RBRACE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::STRING& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"STRING", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FLOOR_DIV& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"FLOOR_DIV", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::TRUE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"TRUE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::SLASH_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"SLASH_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::TRY& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"TRY", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::POWER_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"POWER_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::POWER& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"POWER", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PIPE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PIPE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::__WS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"__WS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FOR& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"FOR", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::COLON& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"COLON", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::EXCEPT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"EXCEPT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NONE_V& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"NONE_V", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DEDENT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"DEDENT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"NE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::STAR& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"STAR", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::SLASH& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"SLASH", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LBRACKET& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LBRACKET", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::GT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"GT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PLUS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PLUS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LSHIFT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LSHIFT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::GE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"GE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::IMPORT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"IMPORT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FLOOR_DIV_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"FLOOR_DIV_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FALSE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"FALSE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::EQ& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"EQ", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CARET& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"CARET", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AND& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"AND", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::NUMBER& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"NUMBER", {}, {}, base, false, {}};
    { auto child = snapshot(v.full, base); child.field = "full"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.floating, base); child.field = "floating"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"AS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MINUS_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"MINUS_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LPAREN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LPAREN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ID& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ID", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AMP& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"AMP", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::AMP_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"AMP_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CLASS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"CLASS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::MINUS& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"MINUS", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::DOT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"DOT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::CARET_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"CARET_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RSHIFT_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RSHIFT_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PERCENT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PERCENT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::ARROW& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"ARROW", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::OR& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"OR", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::PIPE_ASSIGN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"PIPE_ASSIGN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RSHIFT& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RSHIFT", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RETURN& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RETURN", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::FROM& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"FROM", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::LBRACE& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"LBRACE", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::RBRACKET& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"RBRACKET", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitand_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"bitand_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitor_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"bitor_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitwise_and& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"bitwise_and", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitwise_or& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"bitwise_or", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitwise_xor& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"bitwise_xor", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::bitxor_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"bitxor_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::break_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"break_stmt", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_arg& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"call_arg", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_arg_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"call_arg_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_args& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"call_args", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::call_suffix& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"call_suffix", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::comparison& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"comparison", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::compound_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"compound_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::conditional_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"conditional_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.condition, base); child.field = "condition"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.otherwise, base); child.field = "otherwise"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::conjunction& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"conjunction", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::continue_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"continue_stmt", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::def_header& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"def_header", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"dict_expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_item& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"dict_item", {}, {}, base, false, {}};
    { auto child = snapshot(v.key, base); child.field = "key"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_item_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"dict_item_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dict_items& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"dict_items", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::disjunction& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"disjunction", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::else_clause& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"else_clause", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::except_handlers& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"except_handlers", {}, {}, base, false, {}};
    { auto child = snapshot(v.handlers, base); child.field = "handlers"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.otherwise, base); child.field = "otherwise"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.finalizer, base); child.field = "finalizer"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.conditional, base); child.field = "conditional"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr_list& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"expr_list", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr_list_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"expr_list_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::factor& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"factor", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::finally_clause& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"finally_clause", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::indented_block& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"indented_block", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::index_suffix& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"index_suffix", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::inversion& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"inversion", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::is_op& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"is_op", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::list_expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"list_expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::not_in& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"not_in", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::not_inversion& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"not_inversion", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::or_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"or_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parenthesized_content& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"parenthesized_content", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parenthesized_expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"parenthesized_expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::pass_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"pass_stmt", {}, {}, base, false, {}};
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::power& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"power", {}, {}, base, false, {}};
    { auto child = snapshot(v.base, base); child.field = "base"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.exponent, base); child.field = "exponent"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::power_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"power_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::primary& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"primary", {}, {}, base, false, {}};
    { auto child = snapshot(v.base, base); child.field = "base"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.suffixes, base); child.field = "suffixes"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::shift_expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"shift_expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::sum& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"sum", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::term& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"term", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::try_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"try_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.handlers, base); child.field = "handlers"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::try_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"try_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::tuple_elements& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"tuple_elements", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::tuple_suffix& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"tuple_suffix", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::atom& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"atom", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::attribute_suffix& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"attribute_suffix", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dotted_name& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"dotted_name", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::except_alias& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"except_alias", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::global_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"global_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_alias& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"import_alias", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::keyword_arg& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"keyword_arg", {}, {}, base, false, {}};
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::nonlocal_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"nonlocal_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::sum_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"sum_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.op, base); child.field = "op"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::unary_expr& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"unary_expr", {}, {}, base, false, {}};
    { auto child = snapshot(v.op, base); child.field = "op"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::term_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"term_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.op, base); child.field = "op"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_op& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"assignment_op", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::shift_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"shift_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.op, base); child.field = "op"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::class_bases& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"class_bases", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::annotated_assignment& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"annotated_assignment", {}, {}, base, false, {}};
    { auto child = snapshot(v.annotation, base); child.field = "annotation"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assert_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"assert_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.condition, base); child.field = "condition"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.message, base); child.field = "message"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::elif_clause& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"elif_clause", {}, {}, base, false, {}};
    { auto child = snapshot(v.condition, base); child.field = "condition"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::if_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"if_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.condition, base); child.field = "condition"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.elifs, base); child.field = "elifs"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.otherwise, base); child.field = "otherwise"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameter_annotation& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"parameter_annotation", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameter_default& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"parameter_default", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::raise_from& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"raise_from", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::return_annotation& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"return_annotation", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::return_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"return_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::while_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"while_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.condition, base); child.field = "condition"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.otherwise, base); child.field = "otherwise"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::compare_op& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"compare_op", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::decorator& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"decorator", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_suffix& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"assignment_suffix", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::postfix& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"postfix", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::relative_module& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"relative_module", {}, {}, base, false, {}};
    { auto child = snapshot(v.relative, base); child.field = "relative"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::except_clause& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"except_clause", {}, {}, base, false, {}};
    { auto child = snapshot(v.exception, base); child.field = "exception"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.alias, base); child.field = "alias"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dotted_as_name& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"dotted_as_name", {}, {}, base, false, {}};
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.alias, base); child.field = "alias"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_name_item& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"import_name_item", {}, {}, base, false, {}};
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.alias, base); child.field = "alias"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"assignment_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.op, base); child.field = "op"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::class_header& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"class_header", {}, {}, base, false, {}};
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.bases, base); child.field = "bases"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameter& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"parameter", {}, {}, base, false, {}};
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.annotation, base); child.field = "annotation"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.def, base); child.field = "def"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::raise_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"raise_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.exception, base); child.field = "exception"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.cause, base); child.field = "cause"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::compare_tail& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"compare_tail", {}, {}, base, false, {}};
    { auto child = snapshot(v.op, base); child.field = "op"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::decorators& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"decorators", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_target& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"assignment_target", {}, {}, base, false, {}};
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.suffixes, base); child.field = "suffixes"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::dotted_as_names& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"dotted_as_names", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_names& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"import_names", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::assignment_value& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"assignment_value", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parameters& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"parameters", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::class_def& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"class_def", {}, {}, base, false, {}};
    { auto child = snapshot(v.decorators, base); child.field = "decorators"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.definition, base); child.field = "definition"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::decorated_def& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"decorated_def", {}, {}, base, false, {}};
    { auto child = snapshot(v.decorators, base); child.field = "decorators"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.definition, base); child.field = "definition"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::del_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"del_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::for_targets& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"for_targets", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_as& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"with_as", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_name& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"import_name", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::parenthesized_imports& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"parenthesized_imports", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::expr_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"expr_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.target, base); child.field = "target"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.assignment, base); child.field = "assignment"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::function_header& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"function_header", {}, {}, base, false, {}};
    { auto child = snapshot(v.async, base); child.field = "async"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.name, base); child.field = "name"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.params, base); child.field = "params"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.returns, base); child.field = "returns"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::for_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"for_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.async, base); child.field = "async"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.targets, base); child.field = "targets"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.iterable, base); child.field = "iterable"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.otherwise, base); child.field = "otherwise"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_item& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"with_item", {}, {}, base, false, {}};
    { auto child = snapshot(v.context, base); child.field = "context"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.target, base); child.field = "target"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_targets& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"import_targets", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::function_def& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"function_def", {}, {}, base, false, {}};
    { auto child = snapshot(v.decorators, base); child.field = "decorators"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.definition, base); child.field = "definition"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_items& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"with_items", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_from& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"import_from", {}, {}, base, false, {}};
    { auto child = snapshot(v.module, base); child.field = "module"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.names, base); child.field = "names"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::with_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"with_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.async, base); child.field = "async"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.items, base); child.field = "items"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.body, base); child.field = "body"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::import_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"import_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::simple_stmt& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"simple_stmt", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::simple_stmts& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"simple_stmts", {}, {}, base, false, {}};
    { auto child = snapshot(v.first, base); child.field = "first"; out.children.push_back(std::move(child)); }
    { auto child = snapshot(v.rest, base); child.field = "rest"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::block& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"block", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::statement& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"statement", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
UAST::PythonNode snapshot(const PyRawParser::FlatTypes::main& v, const UAST::SourcePosition& base) {
    UAST::PythonNode out{"main", {}, {}, base, false, {}};
    { auto child = snapshot(v.value, base); child.field = "value"; out.children.push_back(std::move(child)); }
    return out;
}
}
UAST::PythonNode UAST::parsePython(const std::string& source, const SourcePosition& position, bool expression) {
    try {
        PyLexer lexer;
        lexer.makeTokens(source);
        ActionParser parser;
        PyRawParser::Lexer::iterator begin(lexer);
        if (expression) {
            auto result = parser.expr(begin);
            if (!result.status) throw std::runtime_error("invalid Python expression");
            auto end = result.it;
            if ((*end).template holds<PyRawParser::Types::NEWLINE>()) ++end;
            if (!end.isEnd()) throw std::runtime_error("trailing tokens in Python expression");
            return snapshot(result.node, position);
        }
        auto result = parser.main(begin);
        if (!result.status || !result.it.isEnd()) throw std::runtime_error("invalid Python action or trailing tokens");
        return snapshot(result.node, position);
    } catch (const std::exception& error) {
        throw std::runtime_error(position.file + ":" + std::to_string(position.line) + ":" + std::to_string(position.column) + ": " + error.what());
    }
}
