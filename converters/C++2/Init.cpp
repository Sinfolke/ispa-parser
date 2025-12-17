module Cpp.Init;
import Cpp.CoreFunctions;
import std;
extern "C" void init(const char* name) {
    Core::name = name;
    Core::symbol_path.push_back(name);
    Core::cpp_file.open(Core::name + ".cpp");
    Core::cpp_file << "#include \"" << Core::name << ".h\"\n";
}