#pragma once
#include <string>
#include <LLInternalData.h>
#include <IR/LLIR_old.h>
#include <logging.h>
#include <corelib.h>
class LLStringConvertions : public LLInternalData {
    protected:
    std::string convert_var_type(const LLIR_old::var_types &type, const std::vector<LLIR_old::var_type> &data) const;
    std::string convert_var_assing_values(const LLIR_old::var_assign_values &value, const std::any &data);
    std::string convert_var_assing_types(const LLIR_old::var_assign_types &value) const;
    std::string conditionTypesToString(const LLIR_old::condition_types &type, const std::any &data);
    std::string convertFunctionCall(const LLIR_old::function_call &call);
    std::string convertAssign(const LLIR_old::assign &asgn);    
    std::string convertMethodCall(const LLIR_old::method_call &method);
    std::string convertDataBlock(const LLIR_old::DataBlock &dtb);
    std::string convertExpression(const std::vector<LLIR_old::expr> &expression, bool with_braces);
};
