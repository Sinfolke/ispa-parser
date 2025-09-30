module Cpp.Declarations;
import Cpp.CoreFunctions;
import Cpp.Statement;
import corelib;
import logging;
import std;

namespace Cpp {
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
        output.writeln("#include <array>");
        output.writeln("#include <string>");
        output.writeln("#include <variant>");
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
        if (the_class.default_visibility == LangAPI::Visibility::Public) {
            output.write("struct {}", the_class.name);
        } else {
            output.write("class {}", the_class.name);
        }
        if (!the_class.inherit_members.empty()) {
            output.dwrite(" : ");
        }
        for (const auto &inherit : the_class.inherit_members) {
            if (inherit.first == LangAPI::Visibility::Public) {
                output.dwrite("public");
            } else {
                output.dwrite("private");
            }
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
    }
    auto Declarations::closeClass() -> void {
        output.decreaseIndentation();
        output.writeln("};");
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

    auto Declarations::createFunction(const std::string &name, const decltype(LangAPI::Function::parameters) &parameters) -> void {
        output.write("auto {} (", name);
        for (const auto &p : parameters) {
            output.write("{} {}, ", Core::convertType(p.first), p.second);
        }
        output.pop_back();
        output.pop_back();
        output.write(")\n{\n");
    }
    auto Declarations::closeFunction() -> void {
        output.write("}\n");
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
        Statement(output).createVariable(v);
    }


}
extern "C" Cpp::Declarations* create_cpp_declarations(Converter::Writer *output) {
    return new Cpp::Declarations(*output);
}
extern "C" void delete_cpp_declarations(Cpp::Declarations *decl) {
    delete decl;
}