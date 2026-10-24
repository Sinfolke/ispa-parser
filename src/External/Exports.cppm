export module External.Exports;
import AST.Tree;
import Modules;
import std;
export namespace External {
std::vector<std::pair<std::string, std::string>> exports(AST::Tree& tree,
    const Modules::Project& project, const std::string& name, bool python = false);
}
