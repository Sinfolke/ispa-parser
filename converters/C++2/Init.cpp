module Cpp.Init;
import Cpp.CoreFunctions;
import std;
extern "C" void init(const char* name) {
    Core::name = name;
    Core::symbol_path.push_back(name);
    Core::cpp_file << "#include \"" << Core::name << ".h\"\n";
    Core::cpp_file << "namespace " << name << " {\n";
}
extern "C" void close() {
    Core::cpp_file << "\n}\n";
}
extern "C" auto getSource() -> std::optional<std::string>* {
    auto str = Core::cpp_file.str();
    if (str.empty()) return nullptr;
    return new std::optional<std::string>(str);
}