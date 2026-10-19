%code requires {
#include "ast.h"
}
%{
/* Bison parser for the ISPA DSL, AST variant: every reduction builds a Node.
 * `|` binds only between single patterns (alternative: '|' pattern).
 * Not translated (never referenced): explicit_expr, advanced_rule::fail_call.
 */
#include <stdio.h>
int yylex(void);
void yyerror(const char *msg);
%}

%define parse.error verbose

%union { Node *n; }

%token <n> ID NUMBER STRING CGROUP PY_RAW ANY SPACE NOSPACE QUANT
%token KW_FAIL KW_DEPENDS KW_MATCH KW_INLINE KW_SKIP KW_EXTERN
%token ARROW FATARROW HASH_LB LPAR_P ATN PCTN BAD

%type <n> main item grammar body modifiers modifier mod name scope template_opt
%type <n> params_opt param_opt id_list expr stmt forward_declaration fail_block
%type <n> rule nested_rules nested_rule ast abbr full parts part single_value
%type <n> f_binding value_list value one_capture tail mul_capture one_captures
%type <n> var_capture ast_capture fail_capture pattern group dyn alternatives
%type <n> counter_opt bounded_opt shared_opt advanced_rule dep_decls dep_decl
%type <n> adv_items adv_item regular_match unpack id_plus

/* The 2 shift/reduce conflicts are intentional greedy (PEG-like) choices: a
 * name takes a following '->' ID scope and a following '(a, b)' params. */
%expect 2

%start top

%%

top:      main                       { ast_root = $1; } ;

/* ---- entry.isc ---- */
main:     %empty                     { $$ = mk0(K_ITEMS); }
        | main item                  { $$ = add($1, $2); } ;
item:     grammar | fail_block ;
grammar:  modifiers name body        { $$ = NODE(K_GRAMMAR, $1, $2, $3); } ;
body:     rule | advanced_rule ;
modifiers: %empty                    { $$ = mk0(K_MODIFIERS); }
        | modifiers modifier         { $$ = add($1, $2); } ;
modifier: HASH_LB mod ']'            { $$ = NODE(K_MODIFIER, $2); } ;
mod:      KW_INLINE                  { $$ = mk_leaf(K_MOD, "inline", 6); }
        | KW_SKIP                    { $$ = mk_leaf(K_MOD, "skip", 4); }
        | KW_EXTERN                  { $$ = mk_leaf(K_MOD, "extern", 6); } ;

/* ---- common.isc ---- */
name:     ID scope template_opt params_opt { $$ = NODE(K_NAME, $1, $2, $3, $4); } ;
scope:    %empty                     { $$ = mk0(K_SCOPE); }
        | scope ARROW ID             { $$ = add($1, $3); } ;
template_opt: %empty                 { $$ = NULL; }
        | '<' param_opt '>'          { $$ = NODE(K_TEMPLATE, $2); } ;
params_opt:   %empty                 { $$ = NULL; }
        | LPAR_P param_opt ')'       { $$ = NODE(K_PARAMS, $2); } ;
param_opt:    %empty                 { $$ = NULL; }
        | id_list ;
id_list:  ID                         { $$ = NODE(K_IDLIST, $1); }
        | id_list ',' ID             { $$ = add($1, $3); } ;
expr:     PY_RAW                     { $$ = NODE(K_EXPR, $1); } ;
stmt:     PY_RAW                     { $$ = NODE(K_STMT, $1); } ;
forward_declaration: ARROW ID ARROW  { $$ = NODE(K_FWD, $2); } ;

/* ---- fail_block.isc ---- */
fail_block: KW_FAIL name stmt        { $$ = NODE(K_FAIL_BLOCK, $2, $3); } ;

/* ---- rule.isc ---- */
rule:     ':' value_list nested_rules ';'
                                     { $$ = NODE(K_RULE, $2, $3); }
        | ':' value_list ast nested_rules ';'
                                     { $$ = NODE(K_RULE, $2, $3, $4); }
        | ':' value_list f_binding nested_rules ';'
                                     { $$ = NODE(K_RULE, $2, $3, $4); }
        | ':' value_list ast f_binding nested_rules ';'
                                     { $$ = NODE(K_RULE, $2, $3, $4, $5); } ;
nested_rules: %empty                 { $$ = mk0(K_NESTED); }
        | nested_rules nested_rule   { $$ = add($1, $2); } ;
nested_rule:  '#' grammar            { $$ = $2; } ;

ast:      abbr | full | single_value ;
abbr:     '@' '{' id_list '}'        { $$ = NODE(K_ABBR, $3); } ;
full:     '&' '{' parts '}'          { $$ = NODE(K_FULL, $3); } ;
parts:    part                       { $$ = NODE(K_PARTS, $1); }
        | parts part                 { $$ = add($1, $2); } ;
part:     ID ':' expr                { $$ = NODE(K_PART, $1, $3); } ;
single_value: '{' expr '}'           { $$ = NODE(K_SINGLE, $2); }
        | '{' '@' '}'                { $$ = mk0(K_SINGLE); } ;

f_binding: '%' '{' id_list '}'       { $$ = NODE(K_FBIND, $3); } ;

value_list: value                    { $$ = NODE(K_VALUES, $1); }
        | value_list value           { $$ = add($1, $2); } ;
value:    one_capture | mul_capture ;

one_capture: tail                    { $$ = NODE(K_ONE, $1); }
    | fail_capture tail              { $$ = NODE(K_ONE, $1, $2); }
    | ast_capture tail               { $$ = NODE(K_ONE, $1, $2); }
    | ast_capture fail_capture tail  { $$ = NODE(K_ONE, $1, $2, $3); }
    | var_capture tail               { $$ = NODE(K_ONE, $1, $2); }
    | var_capture fail_capture tail  { $$ = NODE(K_ONE, $1, $2, $3); }
    | var_capture ast_capture tail   { $$ = NODE(K_ONE, $1, $2, $3); }
    | var_capture ast_capture fail_capture tail
                                     { $$ = NODE(K_ONE, $1, $2, $3, $4); }
    ;
tail:     pattern alternatives counter_opt shared_opt
                                     { $$ = NODE(K_TAIL, $1, $2, $3, $4); } ;

mul_capture: '@' '=' lparen one_captures ')' { $$ = NODE(K_MUL_AST, $4); }
           | '%' '=' lparen one_captures ')' { $$ = NODE(K_MUL_FAIL, $4); } ;
one_captures: one_capture            { $$ = NODE(K_ONES, $1); }
        | one_captures one_capture   { $$ = add($1, $2); } ;

var_capture:  '&' ID                 { $$ = NODE(K_VAR_CAP, $2); } ;
ast_capture:  ATN ID                 { $$ = NODE(K_AST_CAP, $2); }
            | '@'                    { $$ = mk0(K_AST_CAP); } ;
fail_capture: PCTN name              { $$ = NODE(K_FAIL_CAP, $2); }
            | '%'                    { $$ = mk0(K_FAIL_CAP); } ;

pattern:  name | group | dyn | STRING | CGROUP | ANY | SPACE | NOSPACE ;
group:    lparen value_list ')'      { $$ = NODE(K_GROUP, $2); } ;
lparen:   '(' | LPAR_P ;
dyn:      '$' '{' expr '}'           { $$ = NODE(K_DYN, $3); }
        | '$' ID                     { $$ = NODE(K_DYN, $2); } ;

alternatives: %empty                 { $$ = mk0(K_ALTS); }
        | alternatives '|' pattern   { $$ = add($1, $3); } ;
counter_opt:  %empty                 { $$ = NULL; }
        | QUANT bounded_opt          { $$ = NODE(K_COUNTER, $1, $2); } ;
bounded_opt:  %empty                 { $$ = NULL; }
        | '=' NUMBER                 { $$ = NODE(K_BOUNDED, $2); }
        | '=' ID                     { $$ = NODE(K_BOUNDED, $2); }
        | '=' expr                   { $$ = NODE(K_BOUNDED, $2); } ;
shared_opt:   %empty                 { $$ = NULL; }
        | FATARROW ID                { $$ = NODE(K_SHARED, $2); } ;

/* ---- adv_rule.isc ---- */
advanced_rule: '{' dep_decls adv_items '}' { $$ = NODE(K_ADV, $2, $3); } ;
dep_decls: %empty                    { $$ = mk0(K_DEPS); }
        | dep_decls dep_decl         { $$ = add($1, $2); } ;
dep_decl:  KW_DEPENDS forward_declaration { $$ = $2; } ;
adv_items: %empty                    { $$ = mk0(K_ITEMS_ADV); }
        | adv_items adv_item         { $$ = add($1, $2); } ;
adv_item:  regular_match | stmt ;
regular_match: KW_MATCH value_list unpack { $$ = NODE(K_MATCH, $2, $3); }
             | KW_MATCH value_list ';'    { $$ = NODE(K_MATCH, $2); } ;
unpack:    ARROW id_plus             { $$ = NODE(K_UNPACK, $2); } ;
id_plus:   ID                        { $$ = NODE(K_IDS, $1); }
        | id_plus ID                 { $$ = add($1, $2); } ;

%%
