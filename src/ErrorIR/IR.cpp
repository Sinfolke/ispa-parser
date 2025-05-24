module ErrorIR;
import LLIR;
import LLIRBuilderBase;
import LLIRBuilderData;
import LLIRRuleMemberBuilder;
import LLIRBuilderDataWrapper;
import cpuf.printf;
import corelib;
import logging;
import std;

auto ErrorIR::IR::panic_mode() -> Instructions {
    Instructions newInstructions;
    newInstructions.push_back({InstructionType::PANIC_MODE, follow});
    // return fail
    Instruction instruction = {InstructionType::IIF};
    iif_condition condition;
    bool first = true;
    cpuf::printf("follow.back().second: {}", follow.back().second.size());
    for (const auto &el : follow.back().second) {
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
auto ErrorIR::IR::lowerIIFPart(const iif_condition_part &part) -> LLIR::expr {
    switch (part.type) {
        case ConditionTypes::EQUAL:
            return {LLIR::condition_types::EQUAL};
        case ConditionTypes::TOKEN:
            return {
                LLIR::condition_types::TOKEN,
                corelib::text::join(std::any_cast<vector<std::string>> (part.value), "_")
            };
        case ConditionTypes::PANIC_MODE_RESULT:
            return {LLIR::condition_types::TOKEN_NAME, panic_mode_variable};
        case ConditionTypes::OR:
            return {LLIR::condition_types::OR};
    }
}
auto ErrorIR::IR::lowerIIF(const vector<iif_condition_part> &condition) -> vector<LLIR::expr> {
    vector<LLIR::expr> result;
    for (const auto &part : condition) {
        result.push_back(lowerIIFPart(part));
    }
    return result;
}

auto ErrorIR::IR::lowerMemberToLLIR(const Instruction &member) -> vector<LLIR::member> {
    switch (member.type) {
        case InstructionType::EMPTY:
            return {{LLIR::types::EMPTY}};
        case InstructionType::IF:
        {
            const auto &data = std::any_cast<const ErrorIR::condition&>(member.value);
            LLIR::condition newCondition;
            newCondition.expression = data.cond;
            newCondition.block = lowerMembersToLLIR(data.block);
            newCondition.else_block = lowerMembersToLLIR(data.else_block);
            return {{LLIR::types::IF, newCondition}};
            break;
        }
        case InstructionType::IIF: {
            const auto &data = std::any_cast<const ErrorIR::iif_condition&>(member.value);
            LLIR::condition newCondition;
            newCondition.expression = lowerIIF(data.cond);
            newCondition.block = lowerMembersToLLIR(data.block);
            newCondition.else_block = lowerMembersToLLIR(data.else_block);
            return {{LLIR::types::IF, newCondition}};
        }
        case InstructionType::JUMP:
            return {{LLIR::types::JUMP,  std::any_cast<vector<std::string>>(member.value)}};
        case InstructionType::JUMP_PM_RESULT:
            return {{LLIR::types::JUMP_FROM_VARIABLE, panic_mode_variable.name}};
        case InstructionType::ADVANCE:
            return {{LLIR::types::INCREASE_POS_COUNTER}};
        case InstructionType::FAIL:
            return {{LLIR::types::EXIT}};
        case InstructionType::SUCCESS:
            // todo
            return {{LLIR::types::EMPTY}};
            break;
        case InstructionType::PANIC_MODE: {
            panic_mode_variable = LLIR::BuilderBase::createEmptyVariable("_" + std::to_string(variable_count));
            LLIR::function_call function_call =  {
                "PANIC_MODE",
                vector<vector<LLIR::expr>> {{LLIR::expr {LLIR::condition_types::VARIABLE, LLIR::var_refer {.var = panic_mode_variable}}}},
            };
            panic_mode_variable.value = {LLIR::var_assign_values::FUNCTION_CALL, function_call};
            return {{LLIR::types::VARIABLE, panic_mode_variable}};
        }
        case InstructionType::PERFORM: {
            LLIR::BuilderData data(*tree);
            LLIR::BuilderDataWrapper wrapper(data);
            LLIR::MemberBuilder perform(wrapper, std::any_cast<TreeAPI::RuleMember>(member.value), false);
            perform.build();
            return perform.getData();
        }
    }
    return {};
}

auto ErrorIR::IR::lowerMembersToLLIR(const Instructions &members) -> vector<LLIR::member> {
    vector<LLIR::member> result;
    for (const auto &instruction : members) {
        auto instructions = lowerMemberToLLIR(instruction);
        result.insert(result.end(), instructions.begin(), instructions.end());
    }
    return result;
}

auto ErrorIR::IR::lowerToLLIR(size_t &variable_count) -> vector<LLIR::member> {
    this->variable_count = variable_count;
    return lowerMembersToLLIR(instructions);
}

void ErrorIR::IR::lower() {
    if (!member->isName())
        throw Error("ErrorIR is not used in Lexer, but non-name member detected");
    // lower based on follow set
    const auto &name = member->getName().name;
    if (corelib::text::isUpper(name.back())) {
        // try to apply error production
        vector<LLIR::expr> condition;
        bool first = true;
        for (const auto &el : follow.back().second) {
            if (!first) {
                condition.push_back({LLIR::condition_types::OR});
            }
            condition.push_back({
                LLIR::condition_types::CURRENT_TOKEN,
                LLIR::current_token{LLIR::condition_types::EQUAL, corelib::text::join(el, "_")}
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