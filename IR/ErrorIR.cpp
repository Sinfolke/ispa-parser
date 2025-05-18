#include "ErrorIR.h"
#include <corelib.cppm>
auto ErrorIR::panic_mode() -> Instructions {
    Instructions newInstructions;
    newInstructions.push_back({InstructionType::PANIC_MODE, follow});
    // return fail
    Instruction instruction = {InstructionType::IIF};
    iif_condition condition;
    bool first = true;
    for (const auto el : follow.back().second) {
        if (!first)
            condition.cond.push_back({ConditionTypes::OR});
        condition.cond.insert(condition.cond.end(), {
                iif_condition_part {ConditionTypes::PANIC_MODE_RESULT},
                iif_condition_part {ConditionTypes::EQUAL},
                iif_condition_part {ConditionTypes::TOKEN, el}
            }
        );
        first = false;
    }
    condition.block = {
        Instruction {InstructionType::PERFORM, TreeAPI::RuleMember {.value = TreeAPI::RuleMemberName {follow.back().first}}},
    };
    condition.else_block = {
        Instruction {InstructionType::JUMP_PM_RESULT},
        Instruction {InstructionType::FAIL}
    };
    newInstructions.push_back({ErrorIR::InstructionType::IIF, condition});
    return newInstructions;
}
auto ErrorIR::lowerIIFPart(const iif_condition_part &part) -> LLIR_old::expr {
    switch (part.type) {
        case ConditionTypes::EQUAL:
            return {LLIR_old::condition_types::EQUAL};
        case ConditionTypes::TOKEN:
            return {
                LLIR_old::condition_types::TOKEN,
                corelib::text::join(std::any_cast<std::vector<std::string>> (part.value), "_")
            };
        case ConditionTypes::PANIC_MODE_RESULT:
            return {LLIR_old::condition_types::TOKEN_NAME, panic_mode_variable};
        case ConditionTypes::OR:
            return {LLIR_old::condition_types::OR};
    }
}
auto ErrorIR::lowerIIF(const std::vector<iif_condition_part> &condition) -> std::vector<LLIR_old::expr> {
    std::vector<LLIR_old::expr> result;
    for (const auto &part : condition) {
        result.push_back(lowerIIFPart(part));
    }
    return result;
}

auto ErrorIR::lowerToLLIRMember(const Instruction &member) -> std::vector<LLIR_old::member> {
    switch (member.type) {
        case InstructionType::EMPTY:
            return {{LLIR_old::types::EMPTY}};
        case InstructionType::IF:
        {
            const auto &data = std::any_cast<const ErrorIR::condition&>(member.value);
            LLIR_old::condition newCondition;
            newCondition.expression = data.cond;
            newCondition.block = lowerToLLIRMembers(data.block);
            newCondition.else_block = lowerToLLIRMembers(data.else_block);
            return {{LLIR_old::types::IF, newCondition}};
            break;
        }
        case InstructionType::IIF: {
            const auto &data = std::any_cast<const ErrorIR::iif_condition&>(member.value);
            LLIR_old::condition newCondition;
            newCondition.expression = lowerIIF(data.cond);
            newCondition.block = lowerToLLIRMembers(data.block);
            newCondition.else_block = lowerToLLIRMembers(data.else_block);
            return {{LLIR_old::types::IF, newCondition}};
        }
        case InstructionType::JUMP:
            return {{LLIR_old::types::JUMP,  std::any_cast<std::vector<std::string>>(member.value)}};
        case InstructionType::JUMP_PM_RESULT:
            return {{LLIR_old::types::JUMP_FROM_VARIABLE, panic_mode_variable.name}};
        case InstructionType::ADVANCE:
            return {{LLIR_old::types::INCREASE_POS_COUNTER}};
        case InstructionType::FAIL:
            return {{LLIR_old::types::EXIT}};
        case InstructionType::SUCCESS:
            // todo
            return {{LLIR_old::types::EMPTY}};
            break;
        case InstructionType::PANIC_MODE: {
            panic_mode_variable = LLIR_old::createEmptyVariable("_" + std::to_string(variable_count));
            LLIR_old::function_call function_call =  {
                "PANIC_MODE",
                std::vector<std::vector<LLIR_old::expr>> {{LLIR_old::expr {LLIR_old::condition_types::VARIABLE, LLIR_old::var_refer {.var = panic_mode_variable}}}},
            };
            panic_mode_variable.value = {LLIR_old::var_assign_values::FUNCTION_CALL, function_call};
            return {{LLIR_old::types::VARIABLE, panic_mode_variable}};
        }
        case InstructionType::PERFORM: {
            LLIR_old perform(tree, std::any_cast<TreeAPI::RuleMember>(member.value), false);
            return perform.getMembers();
        }
    }
    return {};
}

auto ErrorIR::lowerToLLIRMembers(const Instructions &members) -> std::vector<LLIR_old::member> {
    std::vector<LLIR_old::member> result;
    for (const auto &instruction : members) {
        auto instructions = lowerToLLIRMember(instruction);
        result.insert(result.end(), instructions.begin(), instructions.end());
    }
    return result;
}

auto ErrorIR::lowerToLLIR(size_t &variable_count) -> std::vector<LLIR_old::member> {
    this->variable_count = variable_count;
    return lowerToLLIRMembers(instructions);
}

void ErrorIR::lower() {
    if (!member->isName())
        throw Error("ErrorIR is not used in Lexer, but non-name member detected");

    // lower based on follow set
    const auto &name = member->getName().name;
    if (corelib::text::isUpper(name.back())) {
        // try to apply error production
        std::vector<LLIR_old::expr> condition;
        bool first = true;
        for (const auto &el : follow.back().second) {
            if (!first) {
                condition.push_back({LLIR_old::condition_types::OR});
            }
            condition.push_back({
                LLIR_old::condition_types::CURRENT_TOKEN,
                LLIR_old::current_token{LLIR_old::condition_types::EQUAL, corelib::text::join(el, "_")}
            });
            first = false;
        }
        ErrorIR::condition newCondition = {
            condition,
            {
                {ErrorIR::InstructionType::ADVANCE}, // advance from current pos to next
            }
        };
        if (isFirst) {
            // it is the first check so fail on false
            newCondition.else_block.push_back({InstructionType::FAIL});
        } else {
            // perform panic mode and then continue if success
            newCondition.else_block = panic_mode();
        }
        instructions.push_back({InstructionType::IF, newCondition});
    } else {
        // apply panic mode
        instructions = panic_mode();
    }
}