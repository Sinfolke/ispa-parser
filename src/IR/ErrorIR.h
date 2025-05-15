#pragma once

class ErrorIR {
public:
    enum class InstructionType {
        EMPTY, MATCH, JUMP, SET, FAIL, SUCCESS
    };
    struct Instruction {
        InstructionType type;
        std::string value;
    };
    using Instructions = std::vector<Instruction>;
private:
    Instructions instruction;
    const TreeAPI::RuleMember *member;
    const std::vector<TreeAPI::RuleMemberName> follow;
    void lower();
public:
    // construct an error element based on tree value
    ErrorIR(const TreeAPI::RuleMember member, const std::vector<TreeAPI::RuleMemberName> follow) : member(&member), follow(follow) {}
    // todo add constructor for custom error messages

    auto getInstructions() -> const Instructions&;
    auto begin() -> Instructions::const_iterator;
    auto end() -> Instructions::const_iterator;

    // lower to LLIR functions
    auto lowerToLLIR() -> LLIR;
};