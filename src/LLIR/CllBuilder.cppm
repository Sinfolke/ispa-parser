export module LLIR.CllBuilder;
import LLIR.Builder.Base;
import AST.API;
import LLIR.Builder.DataWrapper;
import LLIR.API;
import dstd;
import std;
export namespace LLIR {
    class CllBuilder : public BuilderBase {
        const AST::Cll *cll;
    public:
        void build();
        CllBuilder(BuilderDataWrapper &data, const AST::Cll &rule) : BuilderBase(data), cll(&rule) {}
    };

    class CllVarBuilder : public BuilderBase {
        const AST::CllVar *var;
    public:
        void build() override;
        CllVarBuilder(BuilderDataWrapper &data, const AST::CllVar &rule) : BuilderBase(data), var(&rule) {}
    };
    class CllIfBuilder : public BuilderBase {
        const AST::CllIf *cond;
    public:
        void build() override;
        CllIfBuilder(BuilderDataWrapper &data, const AST::CllIf &rule) : BuilderBase(data), cond(&rule) {}
    };
    class CllExprBuilder : BuilderDataWrapper {
        const AST::CllExpr *expr;
        Expression result;
        auto CllExprGroupToIR(const AST::CllExpr &group) -> Expression;
        auto CllExprValueToIR(const AST::CllExprValue &value) -> Expression;
        auto CllExprTermToIR(const AST::CllExprTerm &term) -> Expression;
        auto CllExprAdditionToIR(const AST::CllExprAddition &addition) -> Expression;
        auto CllExprCompareToIR(const AST::CllExprCompare &compare) -> Expression;
        auto CllExprLogicalToIR(const AST::CllExprLogical &logical) -> Expression;
        auto deduceTypeFromExprValue(const AST::CllExprValue &value) -> LLIR::var_type;
        auto deduceTypeFromExprTerm(const AST::CllExprTerm &term) -> LLIR::var_type;
        auto deduceTypeFromExprAddition(const AST::CllExprAddition &addition) -> LLIR::var_type;
        auto deduceTypeFromExprCompare(const AST::CllExprCompare &compare) -> LLIR::var_type;
        auto deduceTypeFromExprLogical(const AST::CllExprLogical &logical) -> LLIR::var_type;
    public:
        CllExprBuilder(BuilderDataWrapper &bd, const AST::CllExpr &expr) : BuilderDataWrapper(bd), expr(&expr) {}
        void build();
        auto get() -> Expression;
        auto deduceType() -> LLIR::var_type;
    };
    class CllFunctionBuilder : public BuilderDataWrapper {
        const AST::CllFunctionCall *call;
        function_call result;
        auto FunctionBodyCallToIR(const AST::CllFunctionBodyCall &body) -> stdu::vector<Expression>;
    public:
        void build();
        auto get() -> function_call;
        CllFunctionBuilder(BuilderDataWrapper bd, const AST::CllFunctionCall &call) : BuilderDataWrapper(bd), call(&call) {}
    };
    class CllMethodCallBuilder : public BuilderDataWrapper {
        const AST::CllMethodCall *call;
        method_call result;
    public:
        void build();
        auto get() -> method_call;
        CllMethodCallBuilder(BuilderDataWrapper &bd, const AST::CllMethodCall &call) : BuilderDataWrapper(bd), call(&call) {}
    };
};
