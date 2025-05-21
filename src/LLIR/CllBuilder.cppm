export module CllBuilder;
import LLIRBuilderBase;
import TreeAPI;
import LLIRBuilderDataWrapper;
import LLIR;
import std;
export namespace LLIR {
    class CllBuilder : public BuilderBase {
        const TreeAPI::Cll *cll;
    public:
        void build();
        CllBuilder(BuilderDataWrapper &data, const TreeAPI::Cll &rule) : BuilderBase(data), cll(&rule) {}
    };

    class CllVarBuilder : public BuilderBase {
        const TreeAPI::CllVar *var;
    public:
        void build() override;
        CllVarBuilder(BuilderDataWrapper &data, const TreeAPI::CllVar &rule) : BuilderBase(data), var(&rule) {}
    };
    class CllIfBuilder : public BuilderBase {
        const TreeAPI::CllIf *cond;
    public:
        void build() override;
        CllIfBuilder(BuilderDataWrapper &data, const TreeAPI::CllIf &rule) : BuilderBase(data), cond(&rule) {}
    };
    class CllExprBuilder : BuilderDataWrapper {
        const TreeAPI::CllExpr *expr;
        Expression result;
        auto CllExprGroupToIR(const TreeAPI::CllExpr &group) -> Expression;
        auto CllExprValueToIR(const TreeAPI::CllExprValue &value) -> Expression;
        auto CllExprTermToIR(const TreeAPI::CllExprTerm &term) -> Expression;
        auto CllExprAdditionToIR(const TreeAPI::CllExprAddition &addition) -> Expression;
        auto CllExprCompareToIR(const TreeAPI::CllExprCompare &compare) -> Expression;
        auto CllExprLogicalToIR(const TreeAPI::CllExprLogical &logical) -> Expression;
        auto deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) -> LLIR::var_type;
        auto deduceTypeFromExprTerm(const TreeAPI::CllExprTerm &term) -> LLIR::var_type;
        auto deduceTypeFromExprAddition(const TreeAPI::CllExprAddition &addition) -> LLIR::var_type;
        auto deduceTypeFromExprCompare(const TreeAPI::CllExprCompare &compare) -> LLIR::var_type;
        auto deduceTypeFromExprLogical(const TreeAPI::CllExprLogical &logical) -> LLIR::var_type;
    public:
        CllExprBuilder(BuilderDataWrapper &bd, const TreeAPI::CllExpr &expr) : BuilderDataWrapper(bd), expr(&expr) {}
        void build();
        auto get() -> Expression;
        auto deduceType() -> LLIR::var_type;
    };
    class CllFunctionBuilder : public BuilderDataWrapper {
        const TreeAPI::CllFunctionCall *call;
        function_call result;
        auto FunctionBodyCallToIR(const TreeAPI::CllFunctionBodyCall &body) -> std::vector<Expression>;
    public:
        void build();
        auto get() -> function_call;
        CllFunctionBuilder(BuilderDataWrapper bd, const TreeAPI::CllFunctionCall &call) : BuilderDataWrapper(bd), call(&call) {}
    };
    class CllMethodCallBuilder : public BuilderDataWrapper {
        const TreeAPI::CllMethodCall *call;
        method_call result;
    public:
        void build();
        auto get() -> method_call;
        CllMethodCallBuilder(BuilderDataWrapper &bd, const TreeAPI::CllMethodCall &call) : BuilderDataWrapper(bd), call(&call) {}
    };
};
