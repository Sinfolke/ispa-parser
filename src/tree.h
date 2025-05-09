#pragma once
#include <corelib.h>
#include <TreeAPI.h>
#include <AST.h>
#include <IR/IR.h>
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
            LLIR::ConvertionResult success_var;
        };
        using ConflictsList = std::vector<Conflict>;
        using UsePlaceTable = std::unordered_map<std::vector<std::string>, std::vector<std::vector<std::string>>>;
    private:
        AST ast;
        size_t token_count = 0;
        UsePlaceTable use_places;

        // sort by priority functions
        bool sortPriority(const TreeAPI::String &first, const TreeAPI::String &second);
        bool sortPriority(const TreeAPI::RuleMemberBin &first, const TreeAPI::RuleMemberBin &second);
        bool sortPriority(const TreeAPI::RuleMemberHex &first, const TreeAPI::RuleMemberHex &second);
        bool sortPriority(const TreeAPI::RuleMemberName &first, const TreeAPI::RuleMemberName &second);
        bool sortPriority(const TreeAPI::RuleMemberCsequence &first, const TreeAPI::RuleMemberCsequence &second);
        bool sortPriority(const TreeAPI::RuleMemberGroup &first, const TreeAPI::RuleMemberGroup &second);
        bool sortPriority(const TreeAPI::RuleMemberOp &first, const TreeAPI::RuleMemberOp &second);
        bool sortPriority(const TreeAPI::RuleMember &first, const TreeAPI::RuleMember &second);
        void sortByPriority(std::vector<TreeAPI::RuleMember>& members);
        
        void getUsePlacesTable(const std::vector<TreeAPI::RuleMember> &members, const std::vector<std::string> name, UsePlaceTable &table);
        void createUsePlacesTable();

        void constructor() {
            createUsePlacesTable();
            removeEmptyRule();
            inlineSingleGroups();
            sortByPriority();
            literalsToToken();
            addSpaceToken();
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
