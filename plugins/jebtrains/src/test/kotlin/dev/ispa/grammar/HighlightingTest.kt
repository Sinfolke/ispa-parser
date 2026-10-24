package dev.ispa.grammar

import com.intellij.psi.tree.IElementType
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class HighlightingTest {
    private data class Lexeme(val start: Int, val end: Int, val state: Int, val type: IElementType)
    private fun lex(text: String, start: Int = 0, state: Int = 0): List<Lexeme> {
        val lexer = IspaLexer()
        lexer.start(text, start, text.length, state)
        val result = mutableListOf<Lexeme>()
        while (lexer.tokenType != null) {
            assertTrue(lexer.tokenEnd > lexer.tokenStart)
            result += Lexeme(lexer.tokenStart, lexer.tokenEnd, lexer.state, lexer.tokenType!!)
            lexer.advance()
        }
        return result
    }
    @Test fun highlightsModulesCommentsAndDeclarations() {
        val text = "module core; /* comment */ TOKEN : [a-z]+; entry: TOKEN?;"
        val tokens = lex(text).associate { text.substring(it.start, it.end) to it.type }
        assertEquals(IspaTokens.KEYWORD, tokens["module"])
        assertEquals(IspaTokens.MODULE, tokens["core"])
        assertEquals(IspaTokens.COMMENT, tokens["/* comment */"])
        assertEquals(IspaTokens.TOKEN_REFERENCE, tokens["TOKEN"])
        assertEquals(IspaTokens.RULE_DECLARATION, tokens["entry"])
        assertEquals(IspaTokens.CHAR_CLASS, tokens["[a-z]"])
    }
    @Test fun embeddedPythonRestartsAtEveryTokenBoundary() {
        val text = "entry: 'x' => p{if True: value = {'x': [1, 2]} # } ignored\nreturn value}; tail: 'y';"
        val all = lex(text)
        for ((index, token) in all.withIndex()) assertEquals(all.drop(index), lex(text, token.start, token.state))
        val tokens = all.associate { text.substring(it.start, it.end) to it.type }
        assertEquals(IspaTokens.KEYWORD, tokens["if"])
        assertEquals(IspaTokens.KEYWORD, tokens["return"])
        assertEquals(IspaTokens.COMMENT, tokens["# } ignored"])
        assertEquals(IspaTokens.RULE_DECLARATION, tokens["tail"])
    }
    @Test fun decoderKeepsFailedParseTokensAndConvertsUnicodeOffsets() {
        val source = "// 😀\nentry"
        val json = """{"ok":false,"tokens":[{"kind":"modules.common.ID","role":"declaration","start":8,"length":5}],"diagnostics":[{"message":"Expected \";\"","start":13,"length":0}]}"""
        val result = NativeParserBridge.decode(source, json)
        assertEquals(6, result.tokens.single().start)
        assertEquals(source.length, result.diagnostics.single().start)
        assertEquals("Expected \";\"", result.diagnostics.single().message)
    }
    @Test fun nativeAnnotationsDoNotRepaintPythonIdentifiers() {
        val source = "fail recover { ctx.insert() }"
        val start = source.indexOf("ctx")
        val json = """{"tokens":[{"kind":"ID","role":"","start":$start,"length":3}],"diagnostics":[]}"""
        assertTrue(NativeParserBridge.decode(source, json).tokens.isEmpty())
    }
    @Test fun externalImportRestartsAtEveryTokenBoundary() {
        val text = "import extern python ispa_python as py; #[global] entry: 'x';"
        val all = lex(text)
        for ((index, token) in all.withIndex()) assertEquals(all.drop(index), lex(text, token.start, token.state))
        val tokens = all.associate { text.substring(it.start, it.end) to it.type }
        assertEquals(IspaTokens.KEYWORD, tokens["extern"])
        assertEquals(IspaTokens.MODULE, tokens["python"])
        assertEquals(IspaTokens.MODULE, tokens["ispa_python"])
        assertEquals(IspaTokens.MODULE, tokens["py"])
        assertEquals(IspaTokens.KEYWORD, tokens["global"])
        assertEquals(IspaTokens.RULE_DECLARATION, tokens["entry"])
    }
    @Test fun directPythonBlocksHavePythonColors() {
        val source = "fail recover {\n    if ctx.at('x'):\n        ctx.insert()\n}\nentry { match TOKEN; return ctx.ast }\nvalue: ${'$'}{ctx.at('x')} {ctx.ast};"
        val tokens = lex(source)
        fun typeAt(needle: String): IElementType = tokens.first { it.start == source.indexOf(needle) }.type
        assertEquals(IspaTokens.KEYWORD, typeAt("if ctx"))
        assertEquals(IspaTokens.PY_IDENTIFIER, typeAt("ctx.at"))
        assertEquals(IspaTokens.PY_CALL, typeAt("at('x')"))
        assertEquals(IspaTokens.KEYWORD, typeAt("return ctx"))
        assertEquals(IspaTokens.PY_IDENTIFIER, typeAt("ctx.ast"))
        for ((index, token) in tokens.withIndex()) assertEquals(tokens.drop(index), lex(source, token.start, token.state))
    }
    @Test fun completionIndexSkipsPythonAndFindsNestedRules() {
        val source = "module demo;\nentry: TOKEN\n    #child: entry;\n;\nTOKEN: [a-z];\nfail recover {\n    fake: int = 1\n}\n"
        assertEquals(listOf("entry", "child", "TOKEN", "recover"), IspaSymbols.declarations(source).map { it.name })
        assertEquals("TOKEN", IspaSymbols.referenceAt(source, source.indexOf("TOKEN")))
        assertEquals(null, IspaSymbols.referenceAt(source, source.indexOf("fake")))
        assertEquals(false, IspaSymbols.acceptsCompletion(source, source.indexOf("fake") + 2))
        assertEquals(listOf("A", "main"), IspaSymbols.declarations("A: 'a'; main: A;").map { it.name })
    }
    @Test fun packagedNativeHelperValidatesPythonAndExternalImports() {
        val valid = NativeParserBridge.parse("import extern python ispa_python as python; entry: 'x' {value};")
        assertTrue(valid != null, "Packaged native helper must run")
        assertTrue(valid.diagnostics.isEmpty(), valid.diagnostics.toString())
        val invalid = NativeParserBridge.parse("entry: 'x' {value + };")
        assertTrue(invalid != null, "Packaged native helper must run")
        assertTrue(invalid.diagnostics.isNotEmpty())
    }
    @Test fun unfinishedLexemesStillCoverWholeFile() {
        for (text in listOf("entry: 'unfinished", "/* incomplete", "entry: p{'''long\nstring", "entry: [a\\]")) {
            assertEquals(text.length, lex(text).last().end)
        }
    }
    @Test fun packagedNativeHelperReportsDiagnostics() {
        val result = NativeParserBridge.parse("entry: 'x'")
        assertTrue(result != null, "Packaged native helper must run")
        assertTrue(result.tokens.isNotEmpty())
        assertEquals(10, result.diagnostics.single().start)
        assertTrue(result.diagnostics.single().message.contains("SEMICOLON"))
    }
}
