export module Parser.Base;
import AST.API;
import LangAPI;
export namespace Parser {
    class ParserBase {
    public:
        ParserBase();

        ~ParserBase();

        // deduce type functions
        static auto deduceUvarType(const LangAPI::Variable &var, const LangAPI::Variable &shadow_var) -> LangAPI::Type;
        static auto deduceVarTypeByRuleMemberBase(const AST::RuleMember &mem) -> LangAPI::Type;
        static auto deduceVarTypeByRuleMember(const AST::RuleMember &mem) -> LangAPI::Type;
    };
}