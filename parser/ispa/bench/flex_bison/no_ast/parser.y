%{
/* Bison parser for the ISPA DSL. Parse-only (no AST), so the benchmark
 * measures lexing + LALR(1) parsing.
 *
 * Reading of the .isc files: in ISPA, `|` binds only between single patterns
 * (alternative: '|' pattern), so e.g. `modifier* name rule | advanced_rule`
 * means  modifier* name (rule | advanced_rule).
 *
 * Not translated (defined in the .isc files but never referenced):
 *   explicit_expr, advanced_rule::fail_call
 */
#include <stdio.h>
int yylex(void);
void yyerror(const char *msg);
%}

%define parse.error verbose

%token ID NUMBER STRING CGROUP PY_RAW ANY SPACE NOSPACE QUANT
%token KW_FAIL KW_DEPENDS KW_MATCH KW_INLINE KW_SKIP KW_EXTERN
%token ARROW FATARROW HASH_LB LPAR_P ATN PCTN BAD

/* The 2 remaining shift/reduce conflicts are intentional "greedy" choices that
 * mirror PEG behaviour: a name takes a following '->' ID scope and a following
 * params list '(a, b)' whenever it can (default = shift). */
%expect 2

%start main

%%

/* ---- entry.isc ---- */
main:     %empty | main item ;
item:     grammar | fail_block ;
grammar:  modifiers name body ;
body:     rule | advanced_rule ;
modifiers: %empty | modifiers modifier ;
modifier: HASH_LB mod ']' ;
mod:      KW_INLINE | KW_SKIP | KW_EXTERN ;

/* ---- common.isc ---- */
name:     ID scope template_opt params_opt ;
scope:    %empty | scope ARROW ID ;
template_opt: %empty | '<' param_opt '>' ;
params_opt:   %empty | LPAR_P param_opt ')' ;
param_opt:    %empty | id_list ;
id_list:  ID | id_list ',' ID ;
expr:     PY_RAW ;
stmt:     PY_RAW ;
forward_declaration: ARROW ID ARROW ;

/* ---- fail_block.isc ---- */
fail_block: KW_FAIL name stmt ;

/* ---- rule.isc ---- */
/* value+ ast? f_binding? nested_rule* ';'  (optionals spelled out: an epsilon
 * for ast? would have to be decided before '%', which also starts a value) */
rule:     ':' value_list nested_rules ';'
        | ':' value_list ast nested_rules ';'
        | ':' value_list f_binding nested_rules ';'
        | ':' value_list ast f_binding nested_rules ';' ;
nested_rules: %empty | nested_rules nested_rule ;
nested_rule:  '#' grammar ;

ast:      abbr | full | single_value ;
abbr:     '@' '{' id_list '}' ;
full:     '&' '{' parts '}' ;
parts:    part | parts part ;
part:     ID ':' expr ;
single_value: '{' expr '}' | '{' '@' '}' ;

f_binding: '%' '{' id_list '}' ;

value_list: value | value_list value ;
value:    one_capture | mul_capture ;

/* var_capture? ast_capture? fail_capture? pattern ...  (spelled out to avoid
 * epsilon-reductions colliding with mul_capture's leading '@' / '%') */
one_capture: tail
    | fail_capture tail
    | ast_capture tail
    | ast_capture fail_capture tail
    | var_capture tail
    | var_capture fail_capture tail
    | var_capture ast_capture tail
    | var_capture ast_capture fail_capture tail
    ;
tail:     pattern alternatives counter_opt shared_opt ;

mul_capture: '@' '=' lparen one_captures ')'
           | '%' '=' lparen one_captures ')' ;
one_captures: one_capture | one_captures one_capture ;

var_capture:  '&' ID ;
ast_capture:  ATN ID | '@' ;
fail_capture: PCTN name | '%' ;

pattern:  name | group | dyn | STRING | CGROUP | ANY | SPACE | NOSPACE ;
group:    lparen value_list ')' ;
lparen:   '(' | LPAR_P ;
dyn:      '$' '{' expr '}' | '$' ID ;

alternatives: %empty | alternatives '|' pattern ;
counter_opt:  %empty | QUANT bounded_opt ;
bounded_opt:  %empty | '=' NUMBER | '=' ID | '=' expr ;
shared_opt:   %empty | FATARROW ID ;

/* ---- adv_rule.isc ---- */
advanced_rule: '{' dep_decls adv_items '}' ;
dep_decls: %empty | dep_decls dep_decl ;
dep_decl:  KW_DEPENDS forward_declaration ;
adv_items: %empty | adv_items adv_item ;
adv_item:  regular_match | stmt ;
regular_match: KW_MATCH value_list unpack
             | KW_MATCH value_list ';' ;
unpack:    ARROW id_plus ;
id_plus:   ID | id_plus ID ;

%%
