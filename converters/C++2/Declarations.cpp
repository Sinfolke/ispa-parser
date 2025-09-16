module Cpp.Declarations;
import std;

auto Cpp::Declarations::createNamespace(const std::string &name) -> void {
    writer.writeln("namespace {} {\n\t\n\t}", name)
}
