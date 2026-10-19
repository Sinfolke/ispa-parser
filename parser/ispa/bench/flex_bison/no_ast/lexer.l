%{
/* Flex lexer for the ISPA DSL (entry/common/rule/adv_rule/fail_block .isc).
 *
 * Whitespace-sensitive spots in the grammar (\s0) are handled here:
 *   '@' \s0 ID?   ->  ATN   if '@' is glued to an identifier, else '@'
 *   '%' \s0 name? ->  PCTN  if '%' is glued to an identifier, else '%'
 *   '#' \s0 grammar -> '#'  only if glued to what follows
 * The identifier itself is NOT consumed by ATN/PCTN (trailing context), the
 * parser reads it next.
 */
#include "parser.tab.h"
static int pydepth;
%}

%option noyywrap nounput noinput yylineno
%x PYRAW

ID   [a-zA-Z_][a-zA-Z0-9_]*
WS   [ \t\r\n]

%%

{WS}+                   ;

"fail"                  return KW_FAIL;
"depends"               return KW_DEPENDS;
"match"                 return KW_MATCH;
"inline"                return KW_INLINE;
"skip"                  return KW_SKIP;
"extern"                return KW_EXTERN;

{ID}                    return ID;
[0-9]+(\.[0-9]+)?       return NUMBER;

 /* PY_RAW: 'p{' ... '}' with balanced braces */
"p{"                    { pydepth = 1; BEGIN(PYRAW); }
<PYRAW>{
  "{"                   { pydepth++; }
  "}"                   { if (--pydepth == 0) { BEGIN(INITIAL); return PY_RAW; } }
  [^{}]+                ;
  <<EOF>>               { fprintf(stderr, "unterminated p{ block\n"); BEGIN(INITIAL); return 0; }
}

 /* STRING: either quote style, backslash escapes */
'(\\(.|\n)|[^'\\])*'    return STRING;
\"(\\(.|\n)|[^\"\\])*\" return STRING;

 /* CGROUP: [^? ... ] */
"["\^?([^\\\]]|\\(.|\n))+"]"   return CGROUP;

"\\s0"                  return NOSPACE;
"\\s"                   return SPACE;
"."                     return ANY;
[?+*]                   return QUANT;

"->"                    return ARROW;
"=>"                    return FATARROW;
"#["                    return HASH_LB;
"#"/[a-zA-Z_#]          return '#';

"@"/[a-zA-Z_]           return ATN;
"%"/[a-zA-Z_]           return PCTN;

 /* '(' that opens a params list: ()  (a)  (a, b)  -- see parser note on params vs group */
"("/{WS}*({ID}({WS}*","{WS}*{ID})*)?{WS}*")"   return LPAR_P;

[{}():;,<>&|=$@%\]]     return yytext[0];

.                       return BAD;   /* incl. an unglued "#": parser reports it */

%%
