export module LLIRBuilderBase;
import TreeAPI;
import LLIR;
import LLIRBuilderData;
import LLIRBuilderUtility;
import std;
import std.compat;
export namespace LLIR {
    class BuilderBase : public BuilderData, public BuilderUtility {
    public:
        // public static functions
        static auto createEmptyVariable(std::string name) -> LLIR::variable;
        static auto processExitStatements(std::vector<LLIR::member> &values) -> void;
        static auto generateVariableName(size_t &variable_count) -> std::string;
        static auto createSuccessVariable(size_t &variable_count) -> LLIR::variable;
        static auto createAssignUvarBlock(const LLIR::variable &uvar, const LLIR::variable &var, const LLIR::variable &shadow_var) -> LLIR::member;
        static auto createDefaultBlock(const LLIR::variable &var, const LLIR::variable &svar) -> LLIR::Nodes;
        static auto createDefaultBlock(const LLIR::variable &svar) -> LLIR::Nodes;
        static auto createDefaultBlock() -> LLIR::Nodes;
        static auto createDefaultCall(LLIR::Nodes &block, LLIR::variable &var, const std::string &name, LLIR::Expression &expr) -> LLIR::member;
        static auto compare_templ(const std::vector<LLIR::var_type>& templ1, const std::vector<LLIR::var_type>& templ2) -> bool;

        // cll helper functions
        static auto CllTypeToIR(const TreeAPI::CllType &type) -> var_type;
        static auto CllOpToIR(const char op) -> var_assign_types;
        static auto CllOpToExpr(const char op) -> expr;
        static auto CllCompareOpToExpr(const TreeAPI::CllCompareOp &op) -> expr;
        static auto CllLogicalOpToIR(const TreeAPI::CllLogicalOp &lop) -> condition_types;
        static auto CllAssignmentOpToIR(const char op) -> var_assign_types;
        auto getBuilderData() -> BuilderData;
    protected:
        LLIR::Nodes data;
        std::vector<LLIR::ConvertionResult> return_vars;
        // helper functions
        auto generateVariableName() -> std::string;
        auto createSuccessVariable() -> LLIR::variable;
        auto addPostLoopCheck(const TreeAPI::RuleMember &rule, const LLIR::variable &var, bool addError = true) -> void;
        auto handle_plus_qualifier(const TreeAPI::RuleMember &rule, LLIR::condition loop, const LLIR::variable &uvar, const LLIR::variable &var, LLIR::variable &shadow_var, bool addError = true) -> void;
        auto add_shadow_variable(std::vector<LLIR::member> &block, const LLIR::variable &var) -> LLIR::variable;
        virtual auto pushBasedOnQualifier(const TreeAPI::RuleMember &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, LLIR::variable &uvar, const LLIR::variable &var, const LLIR::variable &svar, char quantifier, bool add_shadow_var = true) -> LLIR::variable;


        // error handling functions
        auto getNextTerminal(std::vector<TreeAPI::RuleMember> symbols, size_t pos) ->  std::set<std::vector<std::string>>;
        auto getErrorName(const TreeAPI::RuleMember &rule) -> std::string;

        // deduce type functions
        auto deduceUvarType(const LLIR::variable &var, const LLIR::variable &shadow_var) -> LLIR::var_type;
        auto deduceVarTypeByProd(const TreeAPI::RuleMember &mem) -> LLIR::var_type;
        auto deduceTypeFromRvalue(const TreeAPI::rvalue &value) -> LLIR::var_type;

        // raise vars on top functions
        void getVariablesToTable(std::vector<LLIR::member> &data, std::vector<LLIR::member>& table, std::string &var_name, bool retain_value, bool recursive);
        void insertVariablesOnTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member>& table);
        void raiseVarsTop(std::vector<LLIR::member> &insertPlace, std::vector<LLIR::member> &readPlace, std::string var_name = "", bool all_rule = false, bool retain_value = true, bool recursive = true);
        void optimizeIR();
    public:
        virtual void build() = 0;
        // interaction functions
        void push(LLIR::member mem);
        void pop();
        void add(LLIR::Nodes block);

        virtual auto getData() const -> const LLIR::Nodes&;
        virtual auto getData() -> LLIR::Nodes&;
        virtual auto getReturnVars() const -> const std::vector<LLIR::ConvertionResult>&;

        BuilderBase(BuilderData& data) : BuilderData(data), BuilderUtility(nullptr) {
            setUtilityPointer(&this->data);
        }
        virtual ~BuilderBase() = default;
    };
}