#pragma once
#include <string>
#include <LLInternalData.h>
#include <IR/IR.h>
#include <logging.h>
#include <corelib.h>
class LLStringConvertions : public LLInternalData {
    protected:
    std::string convert_var_type(const LLIR::var_types &type, const std::vector<LLIR::var_type> &data) const;
    std::string convert_var_assing_values(const LLIR::var_assign_values &value, const std::any &data);
    std::string convert_var_assing_types(const LLIR::var_assign_types &value) const;
    std::string conditionTypesToString(const LLIR::condition_types &type, const std::any &data);
    std::string convertFunctionCall(const LLIR::function_call &call);
    std::string convertAssign(const LLIR::assign &asgn);    
    std::string convertMethodCall(const LLIR::method_call &method);
    std::string convertDataBlock(const LLIR::data_block &dtb);
    std::string convertExpression(const std::vector<LLIR::expr> &expression, bool with_braces);
};
