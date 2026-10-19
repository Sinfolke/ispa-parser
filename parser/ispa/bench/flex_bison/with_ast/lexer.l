%{
/* Flex lexer for the ISPA DSL, AST variant: value tokens carry a Node leaf
 * (copied text) in yylval.n.
 *
 * Whitespace-sensitive spots in the grammar (\s0) are handled here:
 *   '@' \s0 ID?   ->  ATN   if '@' is glued to an identifier, else '@'
 *   '%' \s0 name? ->  PCTN  if '%' is glued to an identifier, else '%'
 *   '#' \s0 grammar -> '#'  only if glued to what follows
 */
#include "parser.tab.h"
static int pydepth;
#define LEAF(k) (yylval.n = mk_leaf((k), yytext, yyleng))
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

{ID}                    { LEAF(K_ID); return ID; }
[0-9]+(\.[0-9]+)?       { LEAF(K_NUMBER); return NUMBER; }

 /* PY_RAW: 'p{' ... '}' with balanced braces; yymore() keeps the whole text */
"p{"                    { pydepth = 1; BEGIN(PYRAW); yymore(); }
<PYRAW>{
  "{"                   { pydepth++; yymore(); }
  "}"                   { if (--pydepth == 0) { BEGIN(INITIAL); LEAF(K_PY_RAW); return PY_RAW; } yymore(); }
  [^{}]+                yymore();
  <<EOF>>               { fprintf(stderr, "unterminated p{ block\n"); BEGIN(INITIAL); return 0; }
}

'(\\(.|\n)|[^'\\])*'    { LEAF(K_STRING); return STRING; }
\"(\\(.|\n)|[^\"\\])*\" { LEAF(K_STRING); return STRING; }

"["\^?([^\\\]]|\\(.|\n))+"]"   { LEAF(K_CGROUP); return CGROUP; }

"\\s0"                  { LEAF(K_NOSPACE); return NOSPACE; }
"\\s"                   { LEAF(K_SPACE); return SPACE; }
"."                     { LEAF(K_ANY); return ANY; }
[?+*]                   { LEAF(K_QUANT); return QUANT; }

"->"                    return ARROW;
"=>"                    return FATARROW;
"#["                    return HASH_LB;
"#"/[a-zA-Z_#]          return '#';

"@"/[a-zA-Z_]           return ATN;
"%"/[a-zA-Z_]           return PCTN;

"("/{WS}*({ID}({WS}*","{WS}*{ID})*)?{WS}*")"   return LPAR_P;

[{}():;,<>&|=$@%\]]     return yytext[0];

.                       return BAD;

%%
