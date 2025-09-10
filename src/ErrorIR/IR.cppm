export module ErrorIR;

import AST.API;
import LLIR.API;
import AST.Tree;
import DFA.Collection;
import DFA.TokenMachineDFA;
import dstd;
import std;

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
        stdu::vector<LLIR::expr> cond;
        stdu::vector<Instruction> block;
        stdu::vector<Instruction> else_block;
    };
    struct iif_condition_part {
        ConditionTypes type;
        std::any value;
    };
    struct iif_condition {
        stdu::vector<iif_condition_part> cond;
        stdu::vector<Instruction> block;
        stdu::vector<Instruction> else_block;
    };
    using Instructions = stdu::vector<Instruction>;
    class IR {
        Instructions instructions;
        const AST::RuleMember *member;
        stdu::vector<std::pair<stdu::vector<std::string>, std::set<stdu::vector<std::string>>>> follow;
        AST::Tree *tree;
        DFA::Collection<DFA::TokenMachineDFA> *dfas;

        // variables used for lower to LLIR
        std::size_t variable_count;
        LLIR::variable panic_mode_variable;

        bool isFirst;
        auto panic_mode() -> Instructions;
        void lower();
    public:
        // construct an error element based on tree value
        IR(
            AST::Tree *tree,
            const AST::RuleMember &member,
            const stdu::vector<std::pair<stdu::vector<std::string>, std::set<stdu::vector<std::string>>>> &follow,
            DFA::Collection<DFA::TokenMachineDFA> *dfas,
            bool isFirst
            )
        : tree(tree), member(&member), follow(follow), dfas(dfas), isFirst(isFirst) { lower(); }
        // todo add constructor for custom error messages

        auto getInstructions() -> const Instructions&;
        auto begin() -> Instructions::const_iterator;
        auto end() -> Instructions::const_iterator;

        // lower to LLIR functions
        auto lowerIIFPart(const iif_condition_part &part) -> LLIR::expr;
        auto lowerIIF(const stdu::vector<iif_condition_part> &condition) -> stdu::vector<LLIR::expr>;
        auto lowerMemberToLLIR(const Instruction &member) -> stdu::vector<LLIR::member>;
        auto lowerMembersToLLIR(const Instructions &members) -> stdu::vector<LLIR::member>;
        auto lowerToLLIR(std::size_t &variable_count) -> stdu::vector<LLIR::member>;
    };
}