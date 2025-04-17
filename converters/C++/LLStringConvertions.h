#pragma once
#include <string>
#include <LLInternalData.h>
#include <IR/IR.h>
#include <logging.h>
#include <corelib.h>
class LLStringConvertions : public LLInternalData {
    protected:
    std::string convert_var_type(LLIR::var_types type, std::vector<LLIR::var_type> data);
    std::string convert_var_assing_values(LLIR::var_assign_values value, std::any data);
    std::string convert_var_assing_types(LLIR::var_assign_types value);
    std::string conditionTypesToString(LLIR::condition_types type, std::any data);
    std::string convertFunctionCall(LLIR::function_call call);
    std::string convertAssign(LLIR::assign asgn);    
    std::string convertMethodCall(LLIR::method_call method);
    std::string convertDataBlock(LLIR::data_block dtb);
    std::string convertExpression(std::vector<LLIR::expr> expression, bool with_braces);
};
