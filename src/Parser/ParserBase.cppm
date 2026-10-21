export module Parser.Base;
import AST.API;
import AST.Tree;
import LangAPI;
import LangAPI.Context;
import hash;
import std;
export namespace Parser {
    struct Settings {
        bool debug = false;
        bool cst = false;
    };
    struct DebugMeta {
        AST::RuleMember member;
    };
    struct LowerMeta {
        LangAPI::Variable value;
        LangAPI::Variable value_list;
        LangAPI::Variable *ast_value = nullptr;
    };
    // Configuration of an automatically generated recovery handler.
    // AST::Tree produces qualified token paths; the C++ converter emits
    // corresponding Tokens::<path> non-type template arguments.
    struct RecoveryOptions {
        std::vector<AST::LLkToken> sync;
        bool allow_insertion = true;
        bool allow_deletion = true;
        bool allow_replacement = true;
        std::size_t max_skip = 64;
    };
    struct LoweredMember {
        LowerMeta meta;
        DebugMeta debug;
        LangAPI::Statements statements;
        RecoveryOptions options;
    };
    struct Ctx {
        const LangAPI::Context *parser_decls;
        Settings settings;
        std::vector<LoweredMember> lowered_members;
        utype::unordered_map<std::vector<std::string>, std::size_t> variables_lowered;
    };

    class ParserBase {
    protected:
        Ctx ctx;
        LangAPI::Declarations decls;
        LangAPI::Context decls_ctx;

        auto account_mem_built(const std::vector<std::string> &name) -> void;

        // Presence detection only. Custom failure actions are lowered
        // separately by the algorithm/frontend, before automatic fallback.
        static auto hasCustomFailure(const AST::RuleMember& member) -> bool;

        // Emit an expression building ISPA_STD::Recovery::handler<...>(...).
        // It is a callable object: handler(pos, recovery_state).
        auto recoveryHandler(
            AST::Tree& tree,
            const AST::LLkToken& rule,
            std::size_t member_index,
            const RecoveryOptions& options = {}
        ) -> LangAPI::Expression;


        auto var_name(const std::vector<std::string> &name, bool is_list) -> std::string;
    public:
        ParserBase(const Ctx &ctx) : ctx(ctx), decls_ctx(decls) {
            this->ctx.parser_decls = &decls_ctx;
        }
        ParserBase(const ParserBase&) = delete;
        ParserBase& operator=(const ParserBase&) = delete;
        ParserBase(ParserBase&&) = delete;
        ParserBase& operator=(ParserBase&&) = delete;


        static auto dataType(const AST::DataType& type) -> LangAPI::Type;

        static auto fun_name(const std::vector<std::string> &name) -> std::string;
        // deduce type functions
        static auto deduceUvarType(const LangAPI::Variable &var, const LangAPI::Variable &shadow_var) -> LangAPI::Type;
        static auto deduceVarTypeByRuleMemberBase(const AST::RuleMember &mem) -> LangAPI::Type;
        static auto deduceVarTypeByRuleMember(const AST::RuleMember &mem) -> LangAPI::Type;
    };
}