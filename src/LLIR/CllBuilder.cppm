export module LLIR.CllBuilder;
import AST.API;
import LLIR.Builder.Base;
import LLIR.Builder.DataWrapper;
import LLIR.RValueBuilder;
import LangAPI;
import dstd;
import std;
export namespace LLIR {
    class CllBuilder : public BuilderBase {
        const AST::Cll &cll;
    public:
        void build() override;
        CllBuilder(BuilderDataWrapper &data, const AST::Cll &rule) : BuilderBase(data), cll(rule) {}
    };

    class CllVarBuilder : public BuilderBase {
        const AST::CllVar &var;
    public:
        void build() override;
        CllVarBuilder(BuilderDataWrapper &data, const AST::CllVar &rule) : BuilderBase(data), var(rule) {}
    };
    class CllIfBuilder : public BuilderBase {
        const AST::CllIf &cond;
    public:
        void build() override;
        CllIfBuilder(BuilderDataWrapper &data, const AST::CllIf &rule) : BuilderBase(data), cond(rule) {}
    };
    class CllExprBuilder : BuilderDataWrapper {
        const AST::CllExpr &expr;
        LangAPI::Expression result;
        std::unique_ptr<RValueBuilder> rvalueBuilder = nullptr;
        auto CllExprGroupToIR(const AST::CllExpr &group) -> LangAPI::Expression;
        auto CllExprValueToIR(const AST::CllExprValue &value) -> LangAPI::Expression;
        auto CllExprTermToIR(const AST::CllExprTerm &term) -> LangAPI::Expression;
        auto CllExprAdditionToIR(const AST::CllExprAddition &addition) -> LangAPI::Expression;
        auto CllExprCompareToIR(const AST::CllExprCompare &compare) -> LangAPI::Expression;
        auto CllExprLogicalToIR(const AST::CllExprLogical &logical) -> LangAPI::Expression;
        auto deduceTypeFromExprValue(const AST::CllExprValue &value) -> LangAPI::Type;
        auto deduceTypeFromExprTerm(const AST::CllExprTerm &term) -> LangAPI::Type;
        auto deduceTypeFromExprAddition(const AST::CllExprAddition &addition) -> LangAPI::Type;
        auto deduceTypeFromExprCompare(const AST::CllExprCompare &compare) -> LangAPI::Type;
        auto deduceTypeFromExprLogical(const AST::CllExprLogical &logical) -> LangAPI::Type;
    public:
        CllExprBuilder(BuilderDataWrapper &bd, const AST::CllExpr &expr) : BuilderDataWrapper(bd), expr(expr) {}
        void build();
        auto get() const -> const LangAPI::Expression& { return result; };
        auto get() -> LangAPI::Expression& { return result; };
        auto deduceType() -> LangAPI::Type;
    };
    class CllFunctionBuilder : public BuilderDataWrapper {
        const AST::CllFunctionCall &call;
        LangAPI::FunctionCall result;
        auto FunctionBodyCallToIR(const AST::CllFunctionBodyCall &body) -> stdu::vector<LangAPI::Expression>;
    public:
        void build();
        auto get() const -> const LangAPI::FunctionCall& { return result; };
        auto get() -> LangAPI::FunctionCall& { return result; };
        CllFunctionBuilder(BuilderDataWrapper bd, const AST::CllFunctionCall &call) : BuilderDataWrapper(bd), call(call) {}
    };
    class CllMethodCallBuilder : public BuilderDataWrapper {
        const AST::CllMethodCall &call;
        LangAPI::StorageSymbol result;
    public:
        void build();
        auto get() const  -> const LangAPI::StorageSymbol& { return result; };
        auto get() -> LangAPI::StorageSymbol& { return result; };
        CllMethodCallBuilder(BuilderDataWrapper &bd, const AST::CllMethodCall &call) : BuilderDataWrapper(bd), call(call) {}
    };
};
