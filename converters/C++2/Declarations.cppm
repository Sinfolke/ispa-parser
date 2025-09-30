export module Cpp.Declarations;

import Converter.Declarations;
import Converter.Writer;
import LangAPI;
import Rope.String;
import dstd;
export namespace Cpp {
    class Declarations : Converter::Declarations {
    public:
        // declarations
        auto openFile(const std::string &namespace_name) -> void override;
        auto closeFile(const std::string &namespace_name) -> void override;
        auto initImports() -> void override;
        auto createNamespace(const std::string &name) -> void override;
        auto closeNamespace() -> void override;
        auto createClass(const LangAPI::Class &the_class) -> void override;
        auto closeClass() -> void override;
        auto createForwardDeclarationClass(LangAPI::ForwardDeclaredClass forward_declared_class) -> void override;
        auto createFunction(const std::string &name, const decltype(LangAPI::Function::parameters) &parameters) -> void override;
        auto setVisibility(LangAPI::Visibility visibility) -> void override;
        auto closeFunction() -> void override;

        // types
        auto createTypeAlias(const std::string &name, const LangAPI::Type type) -> void override;
        auto createEnum(const std::string &name, const stdu::vector<std::string> &names) -> void override;
        auto closeEnum() -> void override;

        auto createVariable(const LangAPI::Variable &v) -> void override;
        Declarations(Converter::Writer &output) : Converter::Declarations(output) {}
        ~Declarations() = default;
    };
}