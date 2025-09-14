export module LLIR.Builder.Base;
import AST.API;
import LLIR.API;
import LLIR.Builder.DataWrapper;
import LLIR.Builder.Utility;
import LLIR.Builder.Data;
import dstd;
import std;

export namespace LLIR {
    class BuilderBase : public BuilderDataWrapper, public BuilderUtility {
    public:
        // public static functions
        static auto createEmptyVariable(const std::string &name) -> Variable;
        static auto processExitStatements(Statements &values) -> void;
        static auto generateVariableName(std::size_t &variable_count) -> std::string;
        static auto createSuccessVariable(std::size_t &variable_count) -> Variable;
        static auto createAssignUvarBlock(const Variable &uvar, const Variable &var, const Variable &shadow_var) -> Statement;
        static auto createDefaultBlock(const Variable &var, const Variable &svar) -> Statements;
        static auto createDefaultBlock(const Variable &svar) -> Statements;
        static auto createDefaultBlock() -> Statements;
        static auto createDefaultCall(Statements &block, Variable var, const std::string &name, LLIR::Expression &expr) -> Statement;
        static auto compare_templ(const stdu::vector<LLIR::var_type>& templ1, const stdu::vector<LLIR::var_type>& templ2) -> bool;
        static auto increasePos() -> Expression;

        // cll helper functions
        static auto CllTypeToIR(const AST::CllType &type) -> RValue;
        static auto CllOpToIR(char op) -> OperatorType;
        static auto CllOpToExpr(char op) -> ExpressionElement;
        static auto CllCompareOpToExpr(const AST::CllCompareOp &op) -> ExpressionElement;
        static auto CllLogicalOpToIR(const AST::CllLogicalOp &lop) -> ExpressionElement;
        static auto CllAssignmentOpToIR(char op) -> OperatorType;

        // helper functions to create structures
        auto assignSvar(const variable &svar, var_assign_values value) -> Statement;
        auto getBuilderData() -> BuilderDataWrapper;
    protected:
        Statements statements;
        stdu::vector<LLIR::ExportsAfterBuild> return_vars;
        // helper functions
        auto generateVariableName() -> std::string;
        auto createSuccessVariable() -> Variable;
        auto addPostLoopCheck(const AST::RuleMember &rule, const Variable &var, bool addError = true) -> void;
        auto handle_plus_qualifier(const AST::RuleMember &rule, ConditionalElement loop, const Variable &uvar, const Variable &var, Variable &shadow_var, bool addError = true) -> void;
        auto add_shadow_variable(Statements &block, const Variable &var) -> Variable;
        virtual auto pushBasedOnQualifier(const AST::RuleMember &rule, Expression &expr, Statements &stmt, Variable &uvar, const Variable &var, const Variable &svar, char quantifier, bool add_shadow_var) -> Variable;
        void pushConvResult(const AST::RuleMember &rule, const Variable &var, const Variable &uvar, const Variable &svar, const Variable &shadow_var, char quantifier);

        // error handling functions
        auto getNextTerminal(stdu::vector<AST::RuleMember> symbols, std::size_t pos) ->  std::set<stdu::vector<std::string>>;
        auto getErrorName(const AST::RuleMember &rule) -> std::string;
        auto getLookaheadTerminals(const AST::RuleMember& symbols, const stdu::vector<std::string> &lhs_name) -> BuilderData::SymbolFollow;

        // deduce type functions
        static auto deduceUvarType(const Variable &var, const Variable &shadow_var) -> RValueType;
        static auto deduceVarTypeByProd(const AST::RuleMember &mem) -> RValueType;
        static auto deduceTypeFromRvalue(const AST::rvalue &value) -> RValueType;

        // raise vars on top functions
        void getVariablesToTable(Statements &data, Statements& table, std::string &var_name, bool retain_value, bool recursive);
        void insertVariablesOnTop(Statements &insertPlace, Statements& table);
        void raiseVarsTop(Statements &insertPlace, Statements &readPlace, std::string var_name = "", bool all_rule = false, bool retain_value = true, bool recursive = true);
    public:
        virtual void build() = 0;
        // interaction functions
        void push(LLIR::member mem);
        void pop();
        void add(LLIR::Nodes block);

        virtual auto getData() const -> const Statements&;
        virtual auto getData() -> Statements&;
        virtual auto getReturnVars() const -> const stdu::vector<LLIR::ExportsAfterBuild>&;
        void optimizeIR();

        BuilderBase(BuilderDataWrapper& data) : BuilderDataWrapper(data), BuilderUtility(nullptr) {
            setUtilityPointer(&this->statements);
        }
        virtual ~BuilderBase() = default;
    };
}