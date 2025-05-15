#pragma once
#include <corelib.h>
#include <AST.h>
#include <IR/LLIR.h>
class Tree {
    public:
        struct Conflict {
            std::vector<Parser::Rule>* lhs_rule;
            std::vector<Parser::Rule>* rhs_rule;
            std::vector<Parser::Rule>::iterator lhs_it;
            std::vector<Parser::Rule>::iterator rhs_it;
        };
        struct lexer_code {
            LLIR code;
            LLIR::variable success_var;
        };
        using ConflictsList = std::vector<Conflict>;
        using UsePlaceTable = std::unordered_map<std::vector<std::string>, std::vector<std::vector<std::string>>>;
    private:
        AST ast;
        size_t token_count = 0;
        UsePlaceTable use_places;
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
        void sortByPriority(TreeAPI::RuleMemberOp& options);
        void sortByPriority(std::vector<TreeAPI::RuleMember>& members);
        
        void getUsePlacesTable(const std::vector<TreeAPI::RuleMember> &members, const std::vector<std::string> &name);
        void createUsePlacesTable();

        void constructor() {
            removeEmptyRule();
            inlineSingleGroups();
            sortByPriority();
            literalsToToken();
            addSpaceToken();
            createUsePlacesTable();
        }
    public:
        Tree(const AST &ast, bool rawAssign = false) : ast(ast) {
            if (!rawAssign)
                constructor();
        }
        auto getRawAst() -> AST&;

        void removeEmptyRule();
        void inlineSingleGroups();
        void literalsToToken();
        void sortByPriority();
        void addSpaceToken();
        auto getTerminals() -> std::vector<std::vector<std::string>>;
        auto getNonTerminals() -> std::vector<std::vector<std::string>>;
        auto getUsePlacesTable() -> UsePlaceTable&;
        auto getCodeForLexer() -> lexer_code;
};
