export module ASTPass;
import corelib;
import LLIR;
import AST;
import TreeAPI;
import std;
import std.compat;
export class ASTPass {
    public:
        // struct Conflict {
        //     std::vector<Parser::Rule>* lhs_rule;
        //     std::vector<Parser::Rule>* rhs_rule;
        //     std::vector<Parser::Rule>::iterator lhs_it;
        //     std::vector<Parser::Rule>::iterator rhs_it;
        // };
        // using ConflictsList = std::vector<Conflict>;

    private:
        AST *ast;
        size_t token_count = 0;
        void literalsToToken(
            std::vector<TreeAPI::RuleMember> &literals,
            size_t &count,
            std::vector<std::pair<std::vector<std::string>, TreeAPI::Rule>> &toInsert,
            std::vector<std::pair<TreeAPI::RuleMember, TreeAPI::RuleMember>> &generated
        );

        // sort by priority functions
        bool prioritySort(const TreeAPI::String &first, const TreeAPI::String &second);
        bool prioritySort(const TreeAPI::RuleMemberBin &first, const TreeAPI::RuleMemberBin &second);
        bool prioritySort(const TreeAPI::RuleMemberHex &first, const TreeAPI::RuleMemberHex &second);
        bool prioritySort(const TreeAPI::RuleMemberName &first, const TreeAPI::RuleMemberName &second);
        bool prioritySort(const TreeAPI::RuleMemberCsequence &first, const TreeAPI::RuleMemberCsequence &second);
        bool prioritySort(const TreeAPI::RuleMemberGroup &first, const TreeAPI::RuleMemberGroup &second);
        bool prioritySort(const TreeAPI::RuleMemberOp &first, const TreeAPI::RuleMemberOp &second);
        bool prioritySort(const TreeAPI::RuleMember &first, const TreeAPI::RuleMember &second);
        

        void constructor() {
            removeEmptyRule();
            inlineSingleGroups();
            sortByPriority();
            literalsToToken();
            addSpaceToken();
        }
    public:
        ASTPass(AST &ast, bool rawAssign = false) : ast(&ast) {
            if (!rawAssign)
                constructor();
        }
        static void removeEmptyRule(AST &ast);
        static void inlineSingleGroups(AST &ast);
        static void literalsToToken(AST &ast);
        static void sortByPriority(AST &ast);
        static void addSpaceToken(AST &ast);
        static void sortByPriority(AST &ast, TreeAPI::RuleMemberOp& options);
        static void sortByPriority(AST &ast, std::vector<TreeAPI::RuleMember>& members);
        void removeEmptyRule();
        void inlineSingleGroups();
        void literalsToToken();
        void sortByPriority();
        void addSpaceToken();

};
