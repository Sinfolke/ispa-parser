export module RvalueBuilder;
import TreeAPI;
import LLIR;
import LLIRBuilderBase;
import LLIRBuilderDataWrapper;
export namespace LLIR {
    class RvalueBuilder : BuilderBase {
        const TreeAPI::rvalue *value;
        assign data = {};
    public:
        void build();
        auto get() -> assign;
        auto deduceType() -> var_type;
        RvalueBuilder(BuilderDataWrapper &data, const TreeAPI::rvalue &value) : BuilderBase(data), value(&value)  {}
    };
}