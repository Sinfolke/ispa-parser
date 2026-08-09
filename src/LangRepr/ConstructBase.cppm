export module ConstructBase;
import LangRepr.Holder;
import LexerBuilder;
import LLIR.IR;
import LangAPI;
import NFA;
import DFA.API;

import dstd;
export namespace LangRepr {
    class ConstructBase {
    protected:
        Holder &holder;
        LexerBuilder &lexer_builder;
        LLIR::IR &ir;

        LangAPI::Symbol Token;
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
        auto makeEmptyStateLambda(const stdu::vector<std::string> &name, const stdu::vector<std::string> &clear_name) -> LangAPI::Lambda;
        ConstructBase(Holder &holder, LexerBuilder &lexer_builder, LLIR::IR &ir) : holder(holder), lexer_builder(lexer_builder), ir(ir) {}

        ~ConstructBase() {}
    private:
    };
}