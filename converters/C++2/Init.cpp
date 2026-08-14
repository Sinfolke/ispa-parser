module Cpp.Init;
import Cpp.CoreFunctions;
import std;
extern "C" void init(const char* name) {
    Core::output = &Core::h_file;
    Core::name = name;
    Core::symbol_path.push_back(name);
    Core::cpp_file.writeln("#include \"{}.h\"", Core::name);
    Core::cpp_file.writeln("namespace {} {", name);
}
extern "C" void close() {
    Core::cpp_file.writeln("\n}");
}
extern "C" auto getSource() -> std::optional<std::string>* {
    auto str = Core::cpp_file.get();
    if (str.empty()) return nullptr;
    return new std::optional<std::string>(str);
}