export module LLStringConvertions;
import corelib;
import logging;
import dstd;
import LLInternalData;
import LangAPI;
import cpuf.printf;
import std;
export class LLStringConvertions : public LLInternalData {
    protected:
    std::string convert_var_type(const LangAPI::var_types &type, const stdu::vector<LangAPI::var_type> &data) const;
    std::string convert_var_assing_values(const LangAPI::var_assign_values &value, const std::any &data);
    std::string convert_var_assing_types(const LangAPI::var_assign_types &value) const;
    std::string conditionTypesToString(const LangAPI::condition_types &type, const std::any &data);
    std::string convertFunctionCall(const LangAPI::function_call &call);
    std::string convertAssign(const LangAPI::assign &asgn);
    std::string convertMethodCall(const LangAPI::method_call &method);
    std::string convertDataBlock(const LangAPI::DataBlock &dtb);
    std::string convertExpression(const stdu::vector<LangAPI::expr> &expression, bool with_braces);
};
