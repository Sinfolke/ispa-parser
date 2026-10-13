package dev.ispa.grammar

import com.intellij.lang.Language
import com.intellij.openapi.fileTypes.LanguageFileType
import com.intellij.openapi.util.IconLoader
import javax.swing.Icon

class IspaLanguage private constructor() : Language("ISPA") {
    companion object { @JvmField val INSTANCE = IspaLanguage() }
}

class IspaFileType private constructor() : LanguageFileType(IspaLanguage.INSTANCE) {
    override fun getName() = "ISPA Grammar"
    override fun getDescription() = "ISPA grammar source"
    override fun getDefaultExtension() = "isc"
    override fun getIcon(): Icon? = null
    companion object { @JvmField val INSTANCE = IspaFileType() }
}
