export module LLIR.RValueBuilder;
import AST.API;
import LangAPI;
import LLIR.Builder.Base;
import LLIR.Builder.DataWrapper;
export namespace LLIR {
    class RValueBuilder : BuilderBase {
        const AST::rvalue &value;
        LangAPI::RValue data = {};
    public:
        void build() override;
        auto get() -> LangAPI::RValue;
        auto deduceType() -> LangAPI::Type;
        RValueBuilder(BuilderDataWrapper &data, const AST::rvalue &value) : BuilderBase(data), value(value)  {}
    };
}