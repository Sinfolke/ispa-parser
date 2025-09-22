module Cpp.Declarations;
import std;

auto Cpp::Declarations::createNamespace(const std::string &name) -> void {
    writer.writeSymbol(name, "namespace {} {\n\t", name);
    writer.writeln(writer.getLine(), 0, "\n\t}");
}

auto Cpp::Declarations::createClass(const std::string &name) -> void {
    writer.writeSymbol(name, "class {} {\n\t", name);
    writer.writeln(writer.getLine(), 0, "\n\t}");
}
auto Cpp::Declarations::createEnum(const std::string &name, const stdu::vector<std::string> &names) -> void {
    std::ostringstream os;
    std::size_t count = 0;
    for (const auto &name : names) {
        os << name;
        count++;
        if (count != names.size()) {
            os << ", ";
        }
    }
    auto sym = writer.writeSymbol(name, "enum class {} {\n");
    writer.writeToSymbol(sym, "{}", os);
    writer.writeln(writer.nameManager().getLineBySymbol(sym).latest_line, 0, "");
}
