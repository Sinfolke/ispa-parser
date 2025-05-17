module;
#include <ostream>
#include <vector>
#include <set>
export module LLIRBuilderBase;
import LLIR;
import LLIRBuilderData;
import TreeAPI;
export class LLIRBuilderBase : LLIRBuilderData {
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
protected:
    LLIR::Nodes data;
    virtual void build() = 0;
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
    auto deduceTypeFromExprValue(const TreeAPI::CllExprValue &value) -> LLIR::var_type;
    auto deduceTypeFromExprTerm(const TreeAPI::CllExprTerm &term) -> LLIR::var_type;
    auto deduceTypeFromExprAddition(const TreeAPI::CllExprAddition &addition) -> LLIR::var_type;
    auto deduceTypeFromExprCompare(const TreeAPI::CllExprCompare &compare) -> LLIR::var_type;
    auto deduceTypeFromExprLogical(const TreeAPI::CllExprLogical &logical) -> LLIR::var_type;
    auto deduceTypeFromExpr(const TreeAPI::CllExpr &expr) -> LLIR::var_type;

    void push(LLIR::member mem);
    void add(LLIR::Nodes block);
public:
    virtual auto getData() const -> const LLIR::Nodes&;
    virtual auto getData() -> LLIR::Nodes&;
    virtual void print(std::ostream &os) const = 0;
};
std::ostream &operator<<(std::ostream &os, const LLIRBuilderBase &data);