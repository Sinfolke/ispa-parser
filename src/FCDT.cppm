export module fcdt;
import hash;
import AST.API;
import AST.Tree;
import AST.Pass;
import dstd;
import std;
export class FCDT {
public:
    struct Name {
        const AST::Tree &ast;
        stdu::vector<std::string> name;
        bool operator<(const Name &second) const {
            return AST::TreePass::prioritySort(ast, AST::RuleMemberName { name } , AST::RuleMemberName {second.name });
        }
        bool operator==(const Name &second) const {
            return name == second.name;
        }
        explicit operator stdu::vector<std::string>() const {
            return name;
        }
    private:
        friend struct ::uhash;
        auto members() const {
            return tie(name);
        }
    };
    using Table = std::array<std::set<Name>, std::numeric_limits<unsigned char>::max() + 1>;
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