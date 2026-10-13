package dev.ispa.grammar

import com.intellij.lexer.Lexer
import com.intellij.lexer.LexerBase
import com.intellij.openapi.editor.DefaultLanguageHighlighterColors as C
import com.intellij.openapi.editor.colors.TextAttributesKey
import com.intellij.openapi.fileTypes.SyntaxHighlighterBase
import com.intellij.openapi.fileTypes.SyntaxHighlighterFactory
import com.intellij.openapi.project.Project
import com.intellij.openapi.vfs.VirtualFile
import com.intellij.psi.TokenType
import com.intellij.psi.tree.IElementType

object IspaTokens {
    val ID = IElementType("ID", IspaLanguage.INSTANCE)
    val RULE_DECLARATION = IElementType("RULE_DECLARATION", IspaLanguage.INSTANCE)
    val STRING = IElementType("STRING", IspaLanguage.INSTANCE)
    val NUMBER = IElementType("NUMBER", IspaLanguage.INSTANCE)
    val COMMENT = IElementType("COMMENT", IspaLanguage.INSTANCE)
    val QUANTIFIER = IElementType("QUANTIFIER", IspaLanguage.INSTANCE)
    val CAPTURE = IElementType("CAPTURE", IspaLanguage.INSTANCE)
    val CHAR_CLASS = IElementType("CHAR_CLASS", IspaLanguage.INSTANCE)
    val OPERATOR = IElementType("OPERATOR", IspaLanguage.INSTANCE)
    val KEYWORD = IElementType("KEYWORD", IspaLanguage.INSTANCE)
}

class IspaLexer : LexerBase() {
    private var buffer: CharSequence = ""
    private var bufferEnd = 0
    private var tokenStart = 0
    private var tokenEnd = 0
    private var token: IElementType? = null

    override fun start(buffer: CharSequence, startOffset: Int, endOffset: Int, initialState: Int) {
        this.buffer = buffer
        this.bufferEnd = endOffset
        this.tokenStart = startOffset
        locate()
    }

    private fun locate() {
        if (tokenStart >= bufferEnd) {
            tokenEnd = bufferEnd
            token = null
            return
        }

        val c = buffer[tokenStart]
        if (c.isWhitespace()) {
            token = TokenType.WHITE_SPACE
            tokenEnd = tokenStart + 1
            while (tokenEnd < bufferEnd && buffer[tokenEnd].isWhitespace()) tokenEnd++
            return
        }

        tokenEnd = tokenStart + 1
        when {
            c == '/' && tokenStart + 1 < bufferEnd && buffer[tokenStart + 1] == '/' -> {
                tokenEnd++
                while (tokenEnd < bufferEnd && buffer[tokenEnd] != '\n') tokenEnd++
                token = IspaTokens.COMMENT
            }
            c == '"' || c == '\'' -> {
                val quote = c
                while (tokenEnd < bufferEnd) {
                    val ch = buffer[tokenEnd++]
                    if (ch == '\\' && tokenEnd < bufferEnd) tokenEnd++ else if (ch == quote) break
                }
                token = IspaTokens.STRING
            }
            c.isDigit() -> {
                while (tokenEnd < bufferEnd && (buffer[tokenEnd].isDigit() || buffer[tokenEnd] == '.')) tokenEnd++
                token = IspaTokens.NUMBER
            }
            c == '#' || c.isLetter() || c == '_' -> {
                var checkEnd = tokenStart + 1
                while (checkEnd < bufferEnd && (buffer[checkEnd].isLetterOrDigit() || buffer[checkEnd] == '_')) {
                    checkEnd++
                }
                if (checkEnd < bufferEnd && buffer[checkEnd] == ':') {
                    tokenEnd = checkEnd + 1
                    token = IspaTokens.RULE_DECLARATION
                } else {
                    tokenEnd = checkEnd
                    token = IspaTokens.ID
                }
            }
            c == '[' -> {
                while (tokenEnd < bufferEnd && buffer[tokenEnd] != ']') {
                    if (buffer[tokenEnd] == '\\' && tokenEnd + 1 < bufferEnd) tokenEnd++
                    tokenEnd++
                }
                if (tokenEnd < bufferEnd) tokenEnd++
                token = IspaTokens.CHAR_CLASS
            }
            c == '@' || c == '{' || c == '}' -> token = IspaTokens.CAPTURE
            c in "*+?" -> token = IspaTokens.QUANTIFIER
            else -> token = IspaTokens.OPERATOR
        }
    }

    override fun getState() = 0
    override fun getTokenType() = token
    override fun getTokenStart() = tokenStart
    override fun getTokenEnd() = tokenEnd
    override fun advance() { tokenStart = tokenEnd; locate() }
    override fun getBufferSequence() = buffer
    override fun getBufferEnd() = bufferEnd
}

object IspaSyntaxHighlighter : SyntaxHighlighterBase() {
    val RULE_DECLARATION_KEY = TextAttributesKey.createTextAttributesKey(
        "ISPA_RULE_DECLARATION",
        C.INTERFACE_NAME
    )
    val IDENTIFIER_KEY = TextAttributesKey.createTextAttributesKey(
        "ISPA_IDENTIFIER",
        C.PARAMETER
    )

    val KEYWORD_KEY = TextAttributesKey.createTextAttributesKey("ISPA_KEYWORD", C.KEYWORD)
    val CAPTURE_KEY = TextAttributesKey.createTextAttributesKey("ISPA_CAPTURE", C.METADATA)

    private val string = TextAttributesKey.createTextAttributesKey("ISPA_STRING", C.STRING)
    private val comment = TextAttributesKey.createTextAttributesKey("ISPA_COMMENT", C.LINE_COMMENT)
    private val number = TextAttributesKey.createTextAttributesKey("ISPA_NUMBER", C.NUMBER)
    private val operator = TextAttributesKey.createTextAttributesKey("ISPA_OPERATOR", C.OPERATION_SIGN)
    private val quantifier = TextAttributesKey.createTextAttributesKey("ISPA_QUANTIFIER", C.KEYWORD)
    private val characterClass = TextAttributesKey.createTextAttributesKey("ISPA_CHARACTER_CLASS", C.STRING)

    override fun getHighlightingLexer(): Lexer = IspaLexer()

    override fun getTokenHighlights(tokenType: IElementType): Array<TextAttributesKey> = when (tokenType) {
        IspaTokens.RULE_DECLARATION -> pack(RULE_DECLARATION_KEY)
        IspaTokens.ID -> pack(IDENTIFIER_KEY)
        IspaTokens.STRING -> pack(string)
        IspaTokens.COMMENT -> pack(comment)
        IspaTokens.NUMBER -> pack(number)
        IspaTokens.CAPTURE -> pack(CAPTURE_KEY)
        IspaTokens.CHAR_CLASS -> pack(characterClass)
        IspaTokens.QUANTIFIER -> pack(quantifier)
        IspaTokens.OPERATOR -> pack(operator)
        IspaTokens.KEYWORD -> pack(KEYWORD_KEY)
        else -> emptyArray()
    }
}

class IspaSyntaxHighlighterFactory : SyntaxHighlighterFactory() {
    override fun getSyntaxHighlighter(project: Project?, virtualFile: VirtualFile?) = IspaSyntaxHighlighter
}