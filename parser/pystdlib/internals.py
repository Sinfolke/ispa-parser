"""Native names exposed to Python modules compiled into generated parsers.

__ispa_internal__ is a compiler directive: the first argument is the C++
qualified name, and the optional second argument is a callable's arity.
"""

Tokens = __ispa_internal__("__ispa_parser__.Tokens")
Rules = __ispa_internal__("__ispa_parser__.Rules")
TokensStr = __ispa_internal__("__ispa_parser__.TokensStr")
RulesStr = __ispa_internal__("__ispa_parser__.RulesStr")
Types = __ispa_internal__("__ispa_parser__.Types")
FlatTypes = __ispa_internal__("__ispa_parser__.FlatTypes")
Token = __ispa_internal__("__ispa_parser__.Token")
Lexer = __ispa_internal__("__ispa_parser__.Lexer")
Parser = __ispa_internal__("__ispa_parser__.Parser")
TokensToString = __ispa_internal__("__ispa_parser__.TokensToString", 1)
RulesToString = __ispa_internal__("__ispa_parser__.RulesToString", 1)

RawToken = __ispa_internal__("ISPA_STD.RawToken")
RawTokenMeta = __ispa_internal__("ISPA_STD.RawTokenMeta")
Node = __ispa_internal__("ISPA_STD.Node")
Span = __ispa_internal__("ISPA_STD.Span")
MatchResult = __ispa_internal__("ISPA_STD.MatchResult")
TokenFlow = __ispa_internal__("ISPA_STD.TokenFlow")
LexerBase = __ispa_internal__("ISPA_STD.Lexer_base")
ParserBase = __ispa_internal__("ISPA_STD.Parser_base")
LLParser = __ispa_internal__("ISPA_STD.LLParser")
