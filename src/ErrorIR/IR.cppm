export module ErrorIR;

import TreeAPI;
import LLIR;
import AST;
import types;
import std;
import std.compat;

export namespace ErrorIR {
    enum class InstructionType {
        EMPTY, IF, IIF, IS_NEXT, JUMP, JUMP_PM_RESULT, FAIL, SUCCESS, ADVANCE, PANIC_MODE, PERFORM
    };
    enum class ConditionTypes {
        PANIC_MODE_RESULT, EQUAL, TOKEN, OR
    };
    struct Instruction {
        InstructionType type;
        std::any value;
    };
    struct condition {
        vector<LLIR::expr> cond;
        vector<Instruction> block;
        vector<Instruction> else_block;
    };
    struct iif_condition_part {
        ConditionTypes type;
        std::any value;
    };
    struct iif_condition {
        vector<iif_condition_part> cond;
        vector<Instruction> block;
        vector<Instruction> else_block;
    };
    using Instructions = vector<Instruction>;
    class IR {
        Instructions instructions;
        const TreeAPI::RuleMember *member;
        vector<std::pair<vector<std::string>, std::set<vector<std::string>>>> follow;
        AST *tree;

        // variables used for lower to LLIR
        size_t variable_count;
        LLIR::variable panic_mode_variable;

        bool isFirst;
        auto panic_mode() -> Instructions;
        void lower();
    public:
        // construct an error element based on tree value
        IR(AST *tree, const TreeAPI::RuleMember &member, const vector<std::pair<vector<std::string>, std::set<vector<std::string>>>> &follow, bool isFirst)
        : tree(tree), member(&member), follow(follow), isFirst(isFirst) { lower(); }
        // todo add constructor for custom error messages

        auto getInstructions() -> const Instructions&;
        auto begin() -> Instructions::const_iterator;
        auto end() -> Instructions::const_iterator;

        // lower to LLIR functions
        auto lowerIIFPart(const iif_condition_part &part) -> LLIR::expr;
        auto lowerIIF(const vector<iif_condition_part> &condition) -> vector<LLIR::expr>;
        auto lowerMemberToLLIR(const Instruction &member) -> vector<LLIR::member>;
        auto lowerMembersToLLIR(const Instructions &members) -> vector<LLIR::member>;
        auto lowerToLLIR(size_t &variable_count) -> vector<LLIR::member>;
    };
}