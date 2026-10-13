package dev.ispa.grammar

import com.intellij.lang.annotation.AnnotationHolder
import com.intellij.lang.annotation.ExternalAnnotator
import com.intellij.lang.annotation.HighlightSeverity
import com.intellij.openapi.util.TextRange
import com.intellij.psi.PsiFile
import com.intellij.psi.TokenType
import com.intellij.psi.tree.IElementType
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.util.concurrent.TimeUnit

data class BridgeToken(val start: Int, val end: Int, val type: IElementType)

object NativeParserBridge {
    private val tokenPattern = Regex("""\{"kind":"([^"]+)","start":(\d+),"length":(\d+)\}""")

    private val executable: java.io.File? by lazy {
        try {
            val suffix = if (System.getProperty("os.name").lowercase().contains("windows")) ".exe" else ""
            val stream = IspaLexer::class.java.getResourceAsStream("/native/ispa-grammar-bridge$suffix") ?: return@lazy null
            val file = Files.createTempFile("ispa-grammar-bridge-", suffix).toFile()
            stream.use { input -> file.outputStream().use(input::copyTo) }
            file.setExecutable(true)
            file.deleteOnExit()
            file
        } catch (_: Exception) { null }
    }

    fun parse(sourceText: String): List<BridgeToken>? {
        val binary = executable ?: return null
        return try {
            val process = ProcessBuilder(binary.absolutePath).start()
            process.outputStream.use { it.write(sourceText.toByteArray(StandardCharsets.UTF_8)) }
            if (!process.waitFor(1500, TimeUnit.MILLISECONDS)) {
                process.destroyForcibly()
                return null
            }
            val json = process.inputStream.bufferedReader(StandardCharsets.UTF_8).use { it.readText() }
            if (process.exitValue() != 0 || !json.startsWith("{\"ok\":true")) return null

            tokenPattern.findAll(json).mapNotNull { match ->
                val kind = match.groupValues[1]
                val start = match.groupValues[2].toIntOrNull() ?: return@mapNotNull null
                val length = match.groupValues[3].toIntOrNull() ?: return@mapNotNull null

                // Inside NativeParserBridge.parse in Annotator.kt
                val type = when {
                    // 1. RULE DECLARATIONS (headers ending with ':' or marked as decl/name_AUTO_0) -> BLUE
                    kind == "name_AUTO_0" ||
                    kind.contains("nested_rule") ||
                    kind.contains("rule_decl") ||
                    kind.endsWith("_decl_AUTO_0") -> IspaTokens.RULE_DECLARATION

                    // 2. IDENTIFIER REFERENCES (#value, #ast, #abbr, ID, expr, v, data, key, e) -> YELLOW
                    kind == "ID" ||
                    kind.contains("name") ||
                    kind.contains("param") ||
                    kind.contains("ref") ||
                    kind.startsWith("rule_value_") ||
                    kind.contains("capture_var") -> IspaTokens.ID

                    // 3. Other token types
                    kind == "NUMBER" || kind.contains("counter") -> IspaTokens.NUMBER
                    kind == "rule_value_STRING" -> IspaTokens.STRING
                    kind == "rule_value_CGROUP" -> IspaTokens.CHAR_CLASS
                    kind == "rule_value_QUANTIFIER" -> IspaTokens.QUANTIFIER
                    kind.contains("ast_capture") || kind.contains("full_part") -> IspaTokens.CAPTURE
                    kind.contains("compound_statement") || kind.contains("fail_block") || kind.contains("grammar_modifier") ||
                        kind.contains("forward_declaration") || kind.startsWith("expr_") -> IspaTokens.KEYWORD
                    kind == "rule_value_SPACE" || kind == "__WS" -> TokenType.WHITE_SPACE
                    else -> IspaTokens.OPERATOR
                }

                if (length <= 0 || start < 0 || start + length > sourceText.length) return@mapNotNull null

                val tokenText = sourceText.substring(start, start + length)
                val actualType = if (kind == "rule_value_STRING" && tokenText.startsWith("'") && tokenText.endsWith("'")) IspaTokens.CHAR_CLASS else type
                BridgeToken(start, start + length, actualType)
            }.toList().sortedBy { it.start }
        } catch (_: Exception) { null }
    }
}

class IspaNativeAnnotator : ExternalAnnotator<String, List<BridgeToken>>() {

    override fun collectInformation(file: PsiFile): String? = file.text

    override fun doAnnotate(collectedInfo: String?): List<BridgeToken>? {
        if (collectedInfo == null) return null
        return NativeParserBridge.parse(collectedInfo)
    }

    override fun apply(file: PsiFile, annotationResult: List<BridgeToken>?, holder: AnnotationHolder) {
        if (annotationResult == null) return
        for (token in annotationResult) {
            val key = when (token.type) {
                IspaTokens.RULE_DECLARATION -> IspaSyntaxHighlighter.RULE_DECLARATION_KEY
                IspaTokens.ID -> IspaSyntaxHighlighter.IDENTIFIER_KEY
                IspaTokens.KEYWORD -> IspaSyntaxHighlighter.KEYWORD_KEY
                IspaTokens.CAPTURE -> IspaSyntaxHighlighter.CAPTURE_KEY
                else -> continue
            }
            holder.newSilentAnnotation(HighlightSeverity.INFORMATION)
                .range(TextRange(token.start, token.end))
                .textAttributes(key)
                .create()
        }
    }
}