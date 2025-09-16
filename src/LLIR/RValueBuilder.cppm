export module LLIR.RValueBuilder;
import AST.API;
import LLIR.API;
import LLIR.Builder.Base;
import LLIR.Builder.DataWrapper;
export namespace LLIR {
    class RValueBuilder : BuilderBase {
        const AST::rvalue &value;
        RValue data = {};
    public:
        void build() override;
        auto get() -> RValue;
        auto deduceType() -> Type;
        RValueBuilder(BuilderDataWrapper &data, const AST::rvalue &value) : BuilderBase(data), value(value)  {}
    };
}