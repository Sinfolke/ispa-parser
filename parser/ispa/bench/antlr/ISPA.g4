grammar ISPA;

// ==========================================
// PARSER RULES
// ==========================================

main
    : (grammarRule | fail_block)* EOF
    ;

grammarRule
    : modifier* name rule_def action_block?
    | advanced_rule
    ;

modifier
    : '#[' MOD ']' action_block?
    ;

MOD
    : 'inline'
    | 'skip'
    | 'extern'
    ;

fail_block
    : 'fail' capture_mark? name capture_mark? stmt action_block?
    ;

advanced_rule
    : '{' capture_mark? dep_decl* capture_mark? (regular_match | stmt)* '}' action_block?
    ;

dep_decl
    : '#'? 'depends' capture_mark? forward_declaration action_block?
    ;

regular_match
    : '#'? 'match' capture_mark? value+ unpack action_block?
    | ';'
    ;

unpack
    : '->' capture_mark? ID+ action_block?
    ;

fail_call
    : 'fail' capture_mark? name action_block?
    ;

name
    : capture_mark? ID ('->' capture_mark? ID)* capture_mark? template_params? capture_mark? params?
    ;

expr
    : capture_mark? PY_RAW action_block?
    ;

explicit_expr
    : '(' capture_mark? expr ')'
    ;

stmt
    : capture_mark? PY_RAW action_block?
    ;

forward_declaration
    : '->' capture_mark? ID '->' action_block?
    ;

params
    : '(' capture_mark? param? ')'
    ;

template_params
    : '<' capture_mark? param? '>'
    ;

param
    : ID (',' capture_mark? ID)*
    ;

rule_def
    : ':' capture_mark? value+ ast? f_binding? nested_rule* ';' action_block?
    ;

ast
    : capture_mark? (abbr | full | single_value) action_block?
    ;

full
    : '&' '{' capture_mark? part+ '}' action_block?
    ;

part
    : capture_mark? ID ':' capture_mark? expr action_block?
    ;

abbr
    : '@' '{' capture_mark? ID (',' capture_mark? ID)* '}' action_block?
    ;

single_value
    : '{' capture_mark? expr | '@' '}' action_block?
    ;

f_binding
    : '%' '{' capture_mark? ID (',' capture_mark? ID)* '}' action_block?
    ;

value
    : capture_mark? (one_capture | mul_capture) action_block?
    ;

var_capture
    : '&' capture_mark? ID action_block?
    ;

ast_capture
    : '@' NOSPACE? capture_mark? ID? action_block?
    ;

fail_capture
    : '%' NOSPACE? capture_mark? name? action_block?
    ;

pattern
    : capture_mark? (name | group | dyn | STRING | CGROUP | ANY | SPACE | NOSPACE) action_block?
    ;

one_capture
    : capture_mark? var_capture? ast_capture? fail_capture? pattern alternative* counter? shared_counter_registration? action_block?
    ;

mul_capture
    : ('@' | '%') '=' '(' capture_mark? one_capture+ ')' action_block?
    ;

group
    : '(' capture_mark? value+ ')' action_block?
    ;

dyn
    : '$' capture_mark? (dyn_expr | ID) action_block?
    ;

dyn_expr
    : '{' capture_mark? expr '}' action_block?
    ;

alternative
    : '|' capture_mark? pattern
    ;

quantifier
    : '?' | '+' | '*'
    ;

counter
    : capture_mark? quantifier bounded? action_block?
    ;

bounded
    : '=' capture_mark? (NUMBER | ID | expr) action_block?
    ;

shared_counter_registration
    : '=>' capture_mark? ID
    ;

nested_rule
    : '#' NOSPACE? capture_mark? grammarRule action_block?
    ;

action_block
    : ACTION_BLOCK
    ;

capture_mark
    : '@'
    ;


// ==========================================
// LEXER RULES
// ==========================================

ACTION_BLOCK
    : '@{' ~'}'* '}'
    | '{@}'
    | '{@' ~'}'* '}'
    ;

PY_RAW
    : 'p{' ~'}'* '}'
    ;

STRING
    : '\'' ( '\\' . | ~['\r\n\\] )* '\''
    | '"' ( '\\' . | ~["\r\n\\] )* '"'
    ;

CGROUP
    : '[' '^'? ( '\\' . | ~[\]\r\n\\] )+ ']'
    ;

ANY     : '.' ;
SPACE   : '\\s' ;
NOSPACE : '\\s0' ;

NUMBER
    : [0-9]+ ('.' [0-9]+)?
    ;

ID
    : [a-zA-Z_] [a-zA-Z0-9_]*
    ;

WS
    : [ \t\r\n]+ -> skip
    ;