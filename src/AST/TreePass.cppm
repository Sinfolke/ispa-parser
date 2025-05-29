export module ASTPass;
import corelib;
import LLIR;
import AST.Tree;
import AST.API;
import dstd;
import std;
import std.compat;
export namespace AST {
    class TreePass {
    public:
        // struct Conflict {
        //     stdu::vector<Parser::Rule>* lhs_rule;
        //     stdu::vector<Parser::Rule>* rhs_rule;
        //     stdu::vector<Parser::Rule>::iterator lhs_it;
        //     stdu::vector<Parser::Rule>::iterator rhs_it;
        // };
        // using ConflictsList = stdu::vector<Conflict>;

    private:
        Tree *ast;
        size_t token_count = 0;
        void literalsToToken(
            stdu::vector<AST::RuleMember> &literals,
            size_t &count,
            stdu::vector<std::pair<stdu::vector<std::string>, AST::Rule>> &toInsert,
            stdu::vector<std::pair<AST::RuleMember, AST::RuleMember>> &generated
        );

        // sort by priority functions
        bool prioritySort(const AST::String &first, const AST::String &second);
        bool prioritySort(const AST::RuleMemberBin &first, const AST::RuleMemberBin &second);
        bool prioritySort(const AST::RuleMemberHex &first, const AST::RuleMemberHex &second);
        bool prioritySort(const AST::RuleMemberName &first, const AST::RuleMemberName &second);
        bool prioritySort(const AST::RuleMemberCsequence &first, const AST::RuleMemberCsequence &second);
        bool prioritySort(const AST::RuleMemberGroup &first, const AST::RuleMemberGroup &second);
        bool prioritySort(const AST::RuleMemberOp &first, const AST::RuleMemberOp &second);
        bool prioritySort(const AST::RuleMember &first, const AST::RuleMember &second);
        
        static auto inlineGroup(AST::RuleMemberGroup group, stdu::vector<AST::RuleMember> &members, stdu::vector<AST::RuleMember>::iterator toInsert)
             -> stdu::vector<AST::RuleMember>::iterator;
        void constructor() {
            removeEmptyRule();
            inlineSingleGroups();
            sortByPriority();
            literalsToToken();
            addSpaceToken();
        }
        enum class Types {
            string, Rule_escaped, Rule_csequence, Rule_bin, Rule_hex, Rule_any, cll, name, group, nospace, op, empty
        };
        Types getTypes(const AST::String&) { return Types::string; }
        Types getTypes(const AST::RuleMemberEscaped &) { return Types::Rule_escaped; }
        Types getTypes(const AST::RuleMemberCsequence &) { return Types::Rule_csequence; }
        Types getTypes(const AST::RuleMemberBin&) { return Types::Rule_bin; }
        Types getTypes(const AST::RuleMemberHex&) { return Types::Rule_hex; }
        Types getTypes(const AST::RuleMemberAny&) { return Types::Rule_any; }
        Types getTypes(const AST::Cll&) { return Types::cll; }
        // never meet types
        Types getTypes(const AST::RuleMemberName&) { return Types::name; };
        Types getTypes(const AST::RuleMemberGroup&) { return Types::group; }
        Types getTypes(const AST::RuleMemberNospace&) {return Types::nospace; }
        Types getTypes(const AST::RuleMemberOp&) { return Types::op; }
        Types getTypes(const std::monostate&) { return Types::empty; }
    public:
        explicit TreePass(Tree &ast, bool rawAssign = false) : ast(&ast) {
            if (!rawAssign)
                constructor();
        }
        static void removeEmptyRule(Tree &ast);
        static void inlineSingleGroups(Tree &ast);
        static void literalsToToken(Tree &ast);
        static void sortByPriority(Tree &ast);
        static void addSpaceToken(Tree &ast);
        static void sortByPriority(Tree &ast, AST::RuleMemberOp& options);
        static void sortByPriority(Tree &ast, stdu::vector<AST::RuleMember>& members);
        void removeEmptyRule();
        void inlineSingleGroups();
        void literalsToToken();
        void sortByPriority();
        void addSpaceToken();

    };
}