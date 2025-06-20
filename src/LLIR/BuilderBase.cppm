export module LLIR.Builder.Base;
import AST.API;
import LLIR.API;
import LLIR.Builder.DataWrapper;
import LLIR.Builder.Utility;
import LLIR.Builder.Data;
import dstd;
import std;
import std.compat;
export namespace LLIR {
    class BuilderBase : public BuilderDataWrapper, public BuilderUtility {
    public:
        // public static functions
        static auto createEmptyVariable(std::string name) -> LLIR::variable;
        static auto processExitStatements(stdu::vector<LLIR::member> &values) -> void;
        static auto generateVariableName(size_t &variable_count) -> std::string;
        static auto createSuccessVariable(size_t &variable_count) -> LLIR::variable;
        static auto createAssignUvarBlock(const LLIR::variable &uvar, const LLIR::variable &var, const LLIR::variable &shadow_var) -> LLIR::member;
        static auto createDefaultBlock(const LLIR::variable &var, const LLIR::variable &svar) -> LLIR::Nodes;
        static auto createDefaultBlock(const LLIR::variable &svar) -> LLIR::Nodes;
        static auto createDefaultBlock() -> LLIR::Nodes;
        static auto createDefaultCall(LLIR::Nodes &block, LLIR::variable var, const std::string &name, LLIR::Expression &expr) -> LLIR::member;
        static auto compare_templ(const stdu::vector<LLIR::var_type>& templ1, const stdu::vector<LLIR::var_type>& templ2) -> bool;

        // cll helper functions
        static auto CllTypeToIR(const AST::CllType &type) -> var_type;
        static auto CllOpToIR(const char op) -> var_assign_types;
        static auto CllOpToExpr(const char op) -> expr;
        static auto CllCompareOpToExpr(const AST::CllCompareOp &op) -> expr;
        static auto CllLogicalOpToIR(const AST::CllLogicalOp &lop) -> condition_types;
        static auto CllAssignmentOpToIR(const char op) -> var_assign_types;

        // helper functions to create structures
        auto assignSvar(const variable &svar, var_assign_values value) -> LLIR::member;
        auto getBuilderData() -> BuilderDataWrapper;
    protected:
        LLIR::Nodes data;
        stdu::vector<LLIR::ConvertionResult> return_vars;
        // helper functions
        auto generateVariableName() -> std::string;
        auto createSuccessVariable() -> LLIR::variable;
        auto addPostLoopCheck(const AST::RuleMember &rule, const LLIR::variable &var, bool addError = true) -> void;
        auto handle_plus_qualifier(const AST::RuleMember &rule, LLIR::condition loop, const LLIR::variable &uvar, const LLIR::variable &var, LLIR::variable &shadow_var, bool addError = true) -> void;
        auto add_shadow_variable(stdu::vector<LLIR::member> &block, const LLIR::variable &var) -> LLIR::variable;
        virtual auto pushBasedOnQualifier(const AST::RuleMember &rule, stdu::vector<LLIR::expr> &expr, stdu::vector<LLIR::member> &block, LLIR::variable &uvar, const LLIR::variable &var, const LLIR::variable &svar, char quantifier, bool add_shadow_var) -> LLIR::variable;
        void pushConvResult(const AST::RuleMember &rule, const LLIR::variable &var, const LLIR::variable &uvar, const LLIR::variable &svar, const LLIR::variable &shadow_var, char quantifier);

        // error handling functions
        auto getNextTerminal(stdu::vector<AST::RuleMember> symbols, size_t pos) ->  std::set<stdu::vector<std::string>>;
        auto getLookaheadTerminals(const AST::RuleMember& symbols, const stdu::vector<std::string> &lhs_name) -> BuilderData::SymbolFollow;
        auto getErrorName(const AST::RuleMember &rule) -> std::string;

        // deduce type functions
        auto deduceUvarType(const LLIR::variable &var, const LLIR::variable &shadow_var) -> LLIR::var_type;
        auto deduceVarTypeByProd(const AST::RuleMember &mem) -> LLIR::var_type;
        auto deduceTypeFromRvalue(const AST::rvalue &value) -> LLIR::var_type;

        // raise vars on top functions
        void getVariablesToTable(stdu::vector<LLIR::member> &data, stdu::vector<LLIR::member>& table, std::string &var_name, bool retain_value, bool recursive);
        void insertVariablesOnTop(stdu::vector<LLIR::member> &insertPlace, stdu::vector<LLIR::member>& table);
        void raiseVarsTop(stdu::vector<LLIR::member> &insertPlace, stdu::vector<LLIR::member> &readPlace, std::string var_name = "", bool all_rule = false, bool retain_value = true, bool recursive = true);
    public:
        virtual void build() = 0;
        // interaction functions
        void push(LLIR::member mem);
        void pop();
        void add(LLIR::Nodes block);

        virtual auto getData() const -> const LLIR::Nodes&;
        virtual auto getData() -> LLIR::Nodes&;
        virtual auto getReturnVars() const -> const stdu::vector<LLIR::ConvertionResult>&;
        void optimizeIR();

        BuilderBase(BuilderDataWrapper& data) : BuilderDataWrapper(data), BuilderUtility(nullptr) {
            setUtilityPointer(&this->data);
        }
        virtual ~BuilderBase() = default;
    };
}