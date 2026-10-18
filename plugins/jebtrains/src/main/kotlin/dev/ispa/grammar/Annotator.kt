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
import java.util.concurrent.CompletableFuture

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
            val output = CompletableFuture.supplyAsync {
                process.inputStream.bufferedReader(StandardCharsets.UTF_8).use { it.readText() }
            }
            val errors = CompletableFuture.runAsync { process.errorStream.use { it.copyTo(java.io.OutputStream.nullOutputStream()) } }
            process.outputStream.use { it.write(sourceText.toByteArray(StandardCharsets.UTF_8)) }
            if (!process.waitFor(1500, TimeUnit.MILLISECONDS)) {
                process.destroyForcibly()
                return null
            }
            val json = output.get(1, TimeUnit.SECONDS)
            errors.get(1, TimeUnit.SECONDS)
            if (process.exitValue() != 0 || !json.startsWith("{\"ok\":true")) return null

            // Native metadata uses UTF-8 byte offsets; IntelliJ uses UTF-16 offsets.
            val byteOffsets = IntArray(sourceText.toByteArray(StandardCharsets.UTF_8).size + 1) { -1 }
            var byteOffset = 0
            var charOffset = 0
            while (charOffset < sourceText.length) {
                byteOffsets[byteOffset] = charOffset
                val count = Character.charCount(sourceText.codePointAt(charOffset))
                byteOffset += sourceText.substring(charOffset, charOffset + count).toByteArray(StandardCharsets.UTF_8).size
                charOffset += count
            }
            byteOffsets[byteOffset] = sourceText.length
            tokenPattern.findAll(json).mapNotNull { match ->
                val kind = match.groupValues[1]
                val byteStart = match.groupValues[2].toIntOrNull() ?: return@mapNotNull null
                val byteLength = match.groupValues[3].toIntOrNull() ?: return@mapNotNull null

                val type = when {
                    kind == "ID" -> IspaTokens.ID
                    kind == "AUTO" || kind == "FAIL" || kind == "grammar_modifier_MOD" ||
                        kind == "advanced_rule_dep_decl_DEPENDS" || kind == "advanced_rule_regular_match_MATCH" -> IspaTokens.KEYWORD
                    kind == "COMMERCIAL_AT" -> IspaTokens.CAPTURE

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

                val byteEnd = byteStart.toLong() + byteLength
                if (byteLength <= 0 || byteStart !in byteOffsets.indices || byteEnd !in 0L until byteOffsets.size.toLong()) return@mapNotNull null
                val start = byteOffsets[byteStart]
                val end = byteOffsets[byteEnd.toInt()]
                if (start < 0 || end <= start) return@mapNotNull null
                val actualType = if (kind == "ID" && sourceText.substring(end).trimStart().startsWith(":")) IspaTokens.RULE_DECLARATION else type
                BridgeToken(start, end, actualType)
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