export module LLIR;
import hash;
import dstd;
import LLIR.API;
import DFA.Collection;
import DFA.TokenMachineDFA;
import std;

export namespace LLIR {
    class IR {
        auto getDataBlocks(bool isToken) const -> DataBlockList;
    protected:
        std::string convert_var_type(var_types type);
        std::string convert_var_assing_values(var_assign_values value, std::any data);
        std::string convert_var_assing_types(var_assign_types type);
        std::string conditionTypesToString(condition_types type, std::any data);
        std::string convertFunctionCall(function_call call);
        std::string convertAssign(assign asgn);
        void convertVariable(variable var, std::ostream& out);
        std::string convertExpression(LLIR::Expression expression, bool with_braces);
        void convertBlock(LLIR::Nodes block, std::ostream& out);
        void convertCondition(condition cond, std::ostream& out);
        void convertAssignVariable(variable_assign var, std::ostream &out);
        std::string convertMethodCall(method_call method);
        std::string convertDataBlock(const DataBlock &dtb);
        void convertSwitch(const switch_statement &statement, std::ostream& out);
        void convertMember(const member& mem, std::ostream& out);
        void convertMembers(const LLIR::Nodes &members, std::ostream& out);
        void convertData(const LLIR::Production &data, std::ostream& out);
        void printIR(std::ostream& out);
        stdu::vector<Production> data;
        DFA::Collection<DFA::TokenMachineDFA> dfa_collection;
        // output functions
        std::stack<std::string> current_pos_counter;
        std::size_t indentLevel = 0;
    public:
        explicit IR(const stdu::vector<Production> &data, bool isToken, DFA::Collection<DFA::TokenMachineDFA> &dfa_collection) : data(data), dfa_collection(dfa_collection) {}
        explicit IR(const stdu::vector<Production> &&data, bool isToken, DFA::Collection<DFA::TokenMachineDFA> &&dfa_collection) : data(std::move(data)), dfa_collection(dfa_collection) {}
        IR() = default;
        auto getData() const -> const stdu::vector<Production>&;
        auto getDfas() const -> const DFA::Collection<DFA::TokenMachineDFA>&;
        auto operator[](std::size_t pos) const -> const Production&;
        auto begin() -> stdu::vector<Production>::iterator;
        auto end() -> stdu::vector<Production>::iterator;
        auto cbegin() -> stdu::vector<Production>::const_iterator;
        auto cend() -> stdu::vector<Production>::const_iterator;
        auto size() -> std::size_t;
        auto empty() -> bool;
        auto clear() -> void;
        auto getDataBlocksTerminals() const -> DataBlockList;
        auto getDataBlocksNonTerminals() const -> DataBlockList;

        // print function
        void outputIRToFile(std::string filename);
        void outputIRToConsole();
    };
    using lexer_code = std::pair<IR, variable>;
}