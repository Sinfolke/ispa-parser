export module LLIR.RvalueBuilder;
import AST.API;
import LLIR;
import LLIR.Builder.Base;
import LLIR.Builder.DataWrapper;
export namespace LLIR {
    class RvalueBuilder : BuilderBase {
        const AST::rvalue *value;
        assign data = {};
    public:
        void build();
        auto get() -> assign;
        auto deduceType() -> var_type;
        RvalueBuilder(BuilderDataWrapper &data, const AST::rvalue &value) : BuilderBase(data), value(&value)  {}
    };
}