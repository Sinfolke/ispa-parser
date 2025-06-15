export module fcdt;
import hash;
import AST.API;
import AST.Tree;
import dstd;
import std;
export class FCDT {
public:
    using Table = std::unordered_map<char, utype::unordered_set<stdu::vector<std::string>>>;
private:
    Table table;
    const AST::Tree &ast;

    auto determineFirstCharacter(const AST::RuleMember &mem) -> std::unordered_set<char>;
public:
    FCDT(const AST::Tree &ast) : ast(ast) {}
    void build();
    auto get() -> Table;
};