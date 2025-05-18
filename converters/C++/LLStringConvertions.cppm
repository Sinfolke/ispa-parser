module;
export module LLStringConvertions;
import corelib;
import logging;
import LLInternalData;
import LLIR;
class LLStringConvertions : public LLInternalData {
    protected:
    std::string convert_var_type(const IR::var_types &type, const std::vector<IR::var_type> &data) const;
    std::string convert_var_assing_values(const IR::var_assign_values &value, const std::any &data);
    std::string convert_var_assing_types(const IR::var_assign_types &value) const;
    std::string conditionTypesToString(const IR::condition_types &type, const std::any &data);
    std::string convertFunctionCall(const IR::function_call &call);
    std::string convertAssign(const IR::assign &asgn);    
    std::string convertMethodCall(const IR::method_call &method);
    std::string convertDataBlock(const IR::DataBlock &dtb);
    std::string convertExpression(const std::vector<IR::expr> &expression, bool with_braces);
};
