export module LangRepr.Converter;

import LangRepr.Holder;
import LangAPI;
import Converter.Declarations;
import Converter.Writer;
import Rope.String;
import cpuf.dlib;
import std;
export namespace LangRepr {
    class Converter {
        ::Converter::Writer output;
        dlib converter_lib;
        const Holder &holder;
        const std::string &lang;
        const std::string &namespace_name;
        std::unique_ptr<::Converter::Declarations, void(*)(::Converter::Declarations*)> decls;
        void buildDeclaration(const LangAPI::Declaration &decl) {
            if (decl.isNamespace()) {
                const auto &namespace_decl = decl.getNamespace();
                decls->createNamespace(namespace_decl.name);
                buildDeclarations(namespace_decl.declarations);
                decls->closeNamespace();
            } else if (decl.isClass()) {
                const auto &cls = decl.getClass();
                decls->createClass(cls);
                for (const auto &[declaration, visibility] : cls.data) {
                    decls->setVisibility(visibility);
                    buildDeclaration(*declaration);
                }
                decls->closeClass();
            }
            else if (decl.isVariable()) {
                const auto &var_decl = decl.getVariable();
                decls->createVariable(var_decl);
            } else if (decl.isTypeAlias()) {
                const auto &type_alias = decl.getTypeAlias();
                decls->createTypeAlias(type_alias.name, type_alias.type);
            } else if (decl.isEnum()) {
                const auto &enum_decl = decl.getEnum();
                decls->createEnum(enum_decl.name, enum_decl.value);
                decls->closeEnum();
            } else if (decl.isFunction()) {
                const auto &func_decl = decl.getFunction();
                decls->createFunction(func_decl.name, func_decl.parameters);
            }
        }
        void buildDeclarations(const LangAPI::Declarations &declarations) {
            for (const auto &declaration : declarations) {
                buildDeclaration(declaration);
            }
        }
    public:
        Converter(const Holder &holder, const std::string &lang, const std::string &namespace_name) :
        converter_lib("libispa-converter-" + lang), holder(holder), lang(lang), decls(nullptr, nullptr), namespace_name(namespace_name) {
            decls = std::unique_ptr<::Converter::Declarations, void(*)(::Converter::Declarations*)>
                (
                    converter_lib.loadfun<::Converter::Declarations*, ::Converter::Writer*>(std::string("create_") + lang + "_declarations")(&output),
                    converter_lib.loadfun<void, ::Converter::Declarations*>(std::string("delete_") + lang + "_declarations")
                );
        }
        auto build() -> void {
            decls->openFile(namespace_name);
            decls->initImports();
            buildDeclarations(holder.get());
            decls->closeFile(namespace_name);
        }
        auto get() { return output; }
    };

}
