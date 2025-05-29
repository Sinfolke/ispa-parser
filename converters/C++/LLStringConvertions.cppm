export module LLStringConvertions;
import corelib;
import logging;
import dstd;
import LLInternalData;
import LLIR;
import cpuf.printf;
import std;
export class LLStringConvertions : public LLInternalData {
    protected:
    std::string convert_var_type(const LLIR::var_types &type, const stdu::vector<LLIR::var_type> &data) const;
    std::string convert_var_assing_values(const LLIR::var_assign_values &value, const std::any &data);
    std::string convert_var_assing_types(const LLIR::var_assign_types &value) const;
    std::string conditionTypesToString(const LLIR::condition_types &type, const std::any &data);
    std::string convertFunctionCall(const LLIR::function_call &call);
    std::string convertAssign(const LLIR::assign &asgn);
    std::string convertMethodCall(const LLIR::method_call &method);
    std::string convertDataBlock(const LLIR::DataBlock &dtb);
    std::string convertExpression(const stdu::vector<LLIR::expr> &expression, bool with_braces);
};
