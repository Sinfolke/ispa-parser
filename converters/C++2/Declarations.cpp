module Cpp.Declarations;
import Cpp.CoreFunctions;
import Cpp.Statement;
import Cpp.CoreFunctions;
import corelib;
import logging;
import std;

namespace Cpp {
    Declarations::Declarations(Converter::Writer &output) :  Converter::Declarations(output) {
        Core::writer = &output;
        Core::declarations_converter = this;
    }
    auto Declarations::openFile(const std::string &namespace_name) -> void {
        output.writeln("#ifndef {}_H", corelib::text::ToUpper(namespace_name));
        output.writeln("#define {}_H", corelib::text::ToUpper(namespace_name));
    }

    auto Declarations::closeFile(const std::string &namespace_name) -> void {
        output.writeln("#endif // {}_H", corelib::text::ToUpper(namespace_name));
    }

    auto Declarations::initImports() -> void {
        output.writeln("#include <string>");
        output.writeln("#include <vector>");
        output.writeln("#include <unordered_map>");
        output.writeln("#include <array>");
        output.writeln("#include <string>");
        output.writeln("#include <variant>");
        output.writeln("#include <optional>");
        output.writeln("#include <memory>");
        output.writeln("#include <ispastdlib.hpp>");
    }

    auto Declarations::createNamespace(const std::string &name) -> void {
        output.writeln("namespace {} {", name);;
        output.increaseIndentation();
    }
    auto Declarations::closeNamespace() -> void {
        output.decreaseIndentation();
        output.writeln("}");
    }
    auto Declarations::createClass(const LangAPI::Class &the_class) -> void {
        Core::prev_visibility = the_class.default_visibility;
        if (the_class.default_visibility == LangAPI::Visibility::Public) {
            output.write("struct {}", the_class.name);
        } else {
            output.write("class {}", the_class.name);
        }
        if (!the_class.inherit_members.empty()) {
            output.dwrite(" : ");
        }
        for (const auto &inherit : the_class.inherit_members) {
            if (inherit.first != the_class.default_visibility) {
                if (inherit.first == LangAPI::Visibility::Public) {
                    output.dwrite("public");
                } else {
                    output.dwrite("private");
                }
            } else output.pop_back(); // remove space
            if (std::holds_alternative<LangAPI::Symbol>(inherit.second))
                output.dwrite(" {}", Core::convertSymbol(std::get<LangAPI::Symbol>(inherit.second)));
            else
                output.dwrite(" {}", Core::convertIspaLibSymbol(std::get<LangAPI::IspaLibSymbol>(inherit.second)));
            if (&inherit != &the_class.inherit_members.back()) {
                output.dwrite(", ");
            }
        }
        output.dwriteln(" {");
        output.increaseIndentation();
        Core::symbol_path.push_back(the_class.name);
    }
    auto Declarations::closeClass() -> void {
        output.decreaseIndentation();
        output.writeln("};");
        Core::symbol_path.pop_back();
        Core::templated = false;
    }
    auto Declarations::createForwardDeclarationClass(const LangAPI::ForwardDeclaredClass forward_declared_class) -> void {
        output.writeln("{} {};", forward_declared_class.isStruct ? "struct" : "class", forward_declared_class.name);
    }
    auto Declarations::setVisibility(const LangAPI::Visibility visibility) -> void {
        if (Core::prev_visibility != visibility) {
            output.decreaseIndentation();
            switch (visibility) {
                case LangAPI::Visibility::Private:
                    output.writeln("private: ");
                    break;
                case LangAPI::Visibility::Public:
                    output.writeln("public: ");
                    break;
                default:
                    throw Error("Unknown visibility");
            }
            output.increaseIndentation();
            Core::prev_visibility = visibility;
        }
    }

    auto Declarations::createFunction(const LangAPI::Type& type, const std::string &name, const decltype(LangAPI::Function::parameters) &parameters) -> void {
        output.write("auto {}(", name);
        for (const auto &p : parameters) {
            output.dwrite("{} {}, ", Core::convertType(p.first), p.second);
        }
        output.pop_back();
        output.pop_back();
        output.dwrite(")\n");
        output.writeln("{");
        output.increaseIndentation();
        Core::symbol_path.push_back(name);
    }
    auto Declarations::closeFunction() -> void {
        output.decreaseIndentation();
        output.write("}\n");
        Core::symbol_path.pop_back();
        Core::templated = false;
    }
    auto Declarations::openTemplateParameters() -> void {
        output.write("template<");
        Core::templated = true;
    }
    auto Declarations::createTemplateParameter(const std::string &name) -> void {
        if (!Core::first_template_parameter) {
            output.dwrite(", ");
            Core::first_template_parameter = false;
        }
        output.dwrite("typename {}", name);
    }
    auto Declarations::closeTemplateParameters() -> void {
        output.dwriteln(">");
        Core::first_template_parameter = true;
    }
    auto Declarations::createTypeAlias(const std::string &name, const LangAPI::Type type) -> void {
        output.writeln("using {} = {};", name, Core::convertType(type));
    }
    auto Declarations::createEnum(const std::string &name, const stdu::vector<std::string> &names) -> void {
        output.writeln("enum class {} {", name);
        output.increaseIndentation();
        for (const auto &n : names) {
            output.writeln("{},", n);
        }
        output.decreaseIndentation();
    }
    auto Declarations::closeEnum() -> void {
        output.writeln("};");
    }
    auto Declarations::createVariable(const LangAPI::Variable &v) -> void {
        output.write("{} {} {}", v.is_static ? "static" : "", Core::convertType(v.type), v.name);
        if (!v.value.empty()) {
            if (v.is_static) {
                Core::cpp_file << corelib::text::join(Core::symbol_path, "::") << "::" << v.name << " = " << Core::convertExpression(v.value) << ";\n";
            } else {
                output.dwrite(" = {}", Core::convertExpression(v.value));
            }
        }
        output.dwriteln(";");
    }
}
extern "C" Cpp::Declarations* create_cpp_declarations(Converter::Writer *output) {
    return new Cpp::Declarations(*output);
}
extern "C" void delete_cpp_declarations(Cpp::Declarations *decl) {
    delete decl;
}