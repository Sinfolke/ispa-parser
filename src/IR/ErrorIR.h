#pragma once
#include <TreeAPI.cppm>
#include <ASTPass.cppm>
class ErrorIR {
public:
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
        std::vector<LLIR_old::expr> cond;
        std::vector<Instruction> block;
        std::vector<Instruction> else_block;
    };
    struct iif_condition_part {
        ConditionTypes type;
        std::any value;
    };
    struct iif_condition {
        std::vector<iif_condition_part> cond;
        std::vector<Instruction> block;
        std::vector<Instruction> else_block;
    };
    using Instructions = std::vector<Instruction>;
private:
    Instructions instructions;
    const TreeAPI::RuleMember *member;
    std::vector<std::pair<std::vector<std::string>, std::set<std::vector<std::string>>>> follow;
    ASTPass *tree;

    // duirng lower to LLIR variables
    size_t variable_count;
    LLIR_old::variable panic_mode_variable;

    bool isFirst;
    auto panic_mode() -> Instructions;
    void lower();
public:
    // construct an error element based on tree value
    ErrorIR(ASTPass *tree, const TreeAPI::RuleMember &member, const std::vector<std::pair<std::vector<std::string>, std::set<std::vector<std::string>>>> &follow, bool isFirst)
    : tree(tree), member(&member), follow(follow), isFirst(isFirst) { lower(); }
    // todo add constructor for custom error messages

    auto getInstructions() -> const Instructions&;
    auto begin() -> Instructions::const_iterator;
    auto end() -> Instructions::const_iterator;

    // lower to LLIR functions
    auto lowerIIFPart(const iif_condition_part &part) -> LLIR_old::expr;
    auto lowerIIF(const std::vector<iif_condition_part> &condition) -> std::vector<LLIR_old::expr>;
    auto lowerToLLIRMember(const Instruction &member) -> std::vector<LLIR_old::member>;
    auto lowerToLLIRMembers(const Instructions &members) -> std::vector<LLIR_old::member>;
    auto lowerToLLIR(size_t &variable_count) -> std::vector<LLIR_old::member>;
};