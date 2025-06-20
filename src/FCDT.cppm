export module fcdt;
import hash;
import cpuf.op;
import AST.API;
import AST.Tree;
import AST.Pass;
import dstd;
import std;
export class FCDT {
public:
    using Table = std::array<stdu::vector<stdu::vector<std::string>>, std::numeric_limits<unsigned char>::max() + 1>;
private:
    Table table;
    const AST::Tree &ast;
    void skipNospace(stdu::vector<AST::RuleMember>::iterator &it, const stdu::vector<AST::RuleMember>::iterator &end);
    auto determineFirstCharacter(const AST::RuleMember &mem) -> std::unordered_set<char>;
public:
    FCDT(const AST::Tree &ast) : ast(ast) {}
    void build();
    auto get() -> Table&;
    auto get() const -> const Table&;
};