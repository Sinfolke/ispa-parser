package dev.ispa.grammar

import com.intellij.extapi.psi.ASTWrapperPsiElement
import com.intellij.extapi.psi.PsiFileBase
import com.intellij.lang.ASTNode
import com.intellij.lang.ParserDefinition
import com.intellij.lang.PsiParser
import com.intellij.openapi.project.Project
import com.intellij.psi.FileViewProvider
import com.intellij.psi.PsiElement
import com.intellij.psi.TokenType
import com.intellij.psi.tree.IFileElementType
import com.intellij.psi.tree.TokenSet

class IspaParserDefinition : ParserDefinition {
    override fun createLexer(project: Project?) = IspaLexer()
    override fun createParser(project: Project?) = PsiParser { root, builder ->
        val file = builder.mark()
        while (!builder.eof()) builder.advanceLexer()
        file.done(root)
        builder.treeBuilt
    }
    override fun getFileNodeType() = FILE
    override fun getWhitespaceTokens() = TokenSet.create(TokenType.WHITE_SPACE)
    override fun getCommentTokens() = TokenSet.create(IspaTokens.COMMENT)
    override fun getStringLiteralElements() = TokenSet.create(IspaTokens.STRING)
    override fun createElement(node: ASTNode): PsiElement = ASTWrapperPsiElement(node)
    override fun createFile(viewProvider: FileViewProvider) = object : PsiFileBase(viewProvider, IspaLanguage.INSTANCE) {
        override fun getFileType() = IspaFileType.INSTANCE
    }
    companion object { private val FILE = IFileElementType(IspaLanguage.INSTANCE) }
}
