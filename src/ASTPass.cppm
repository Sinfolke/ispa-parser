export module ASTPass;
import corelib;
import LLIR;
import AST;
import TreeAPI;
import types;
import std;
import std.compat;
export class ASTPass {
    public:
        // struct Conflict {
        //     vector<Parser::Rule>* lhs_rule;
        //     vector<Parser::Rule>* rhs_rule;
        //     vector<Parser::Rule>::iterator lhs_it;
        //     vector<Parser::Rule>::iterator rhs_it;
        // };
        // using ConflictsList = vector<Conflict>;

    private:
        AST *ast;
        size_t token_count = 0;
        void literalsToToken(
            vector<TreeAPI::RuleMember> &literals,
            size_t &count,
            vector<std::pair<vector<std::string>, TreeAPI::Rule>> &toInsert,
            vector<std::pair<TreeAPI::RuleMember, TreeAPI::RuleMember>> &generated
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
        enum class Types {
                string, Rule_escaped, Rule_csequence, Rule_bin, Rule_hex, Rule_any, cll, name, group, nospace, op, empty
            };
        Types getTypes(const TreeAPI::String&) { return Types::string; }
        Types getTypes(const TreeAPI::RuleMemberEscaped &) { return Types::Rule_escaped; }
        Types getTypes(const TreeAPI::RuleMemberCsequence &) { return Types::Rule_csequence; }
        Types getTypes(const TreeAPI::RuleMemberBin&) { return Types::Rule_bin; }
        Types getTypes(const TreeAPI::RuleMemberHex&) { return Types::Rule_hex; }
        Types getTypes(const TreeAPI::RuleMemberAny&) { return Types::Rule_any; }
        Types getTypes(const TreeAPI::Cll&) { return Types::cll; }
        // never meet types
        Types getTypes(const TreeAPI::RuleMemberName&) { return Types::name; };
        Types getTypes(const TreeAPI::RuleMemberGroup&) { return Types::group; }
        Types getTypes(const TreeAPI::RuleMemberNospace&) {return Types::nospace; }
        Types getTypes(const TreeAPI::RuleMemberOp&) { return Types::op; }
        Types getTypes(const std::monostate&) { return Types::empty; }
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
        static void sortByPriority(AST &ast, vector<TreeAPI::RuleMember>& members);
        void removeEmptyRule();
        void inlineSingleGroups();
        void literalsToToken();
        void sortByPriority();
        void addSpaceToken();

};
