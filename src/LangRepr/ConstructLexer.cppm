export module LangRepr.ConstructLexer;
import NFA;
import DFA.API;
import LLIR.IR;
import AST.API;
import LangRepr.Holder;
import LexerBuilder;
import LangAPI;
import dstd;
import std;
export namespace LangRepr {
    class ConstructLexer {
        Holder &holder;
        LexerBuilder &lexer_builder;
        LLIR::IR &ir;

        LangAPI::Symbol Token;
    public:
        auto makeIntRValue(int v) -> std::shared_ptr<LangAPI::RValue>;
        auto ensureTypesNs(LangAPI::Type t) -> LangAPI::Type;
        auto extractRawSymbol(const LangAPI::Type &t) -> stdu::vector<LangAPI::Type>;
        auto createTypeToken() -> LangAPI::TypeAlias;
        auto createLexerClass() -> LangAPI::Class;
        auto getTransitionCount(const std::variant<DFA::FullCharTable, DFA::SortedTransitions> &transition) -> std::size_t;
        auto getStateType(DFA::DfaType state_type) -> LangAPI::IspaLibSymbol;
        auto buildLambdaContent(
            LangAPI::Symbol builder_sym,
            const NFA::TemplatedDataBlockValue &data_block,
            long long N
        ) -> LangAPI::StorageSymbol;
        auto makeEmptyStateLambda(DFA::DfaType dfa_type, const stdu::vector<std::string> &name, const stdu::vector<std::string> &clear_name,
                                    const NFA::DataBlock &nfa_dtb) -> LangAPI::Lambda;
        auto constructLexer() -> void;
        ConstructLexer(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir) : holder(holder), lexer_builder(lexer_builder), ir(ir) {}

        ~ConstructLexer() {}
    private:
    };
}