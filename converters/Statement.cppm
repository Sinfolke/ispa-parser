export module Converter.Statement;

import LangAPI;
import Converter.Writer;

export namespace Converter {
    class Statement {
    protected:
        Writer &output;
    public:
        virtual auto createIf(const LangAPI::Expression &expression) -> void = 0;
        virtual auto closeIf() -> void = 0;
        virtual auto createWhile(const LangAPI::Expression &expression) -> void = 0;
        virtual auto closeWhile() -> void = 0;
        virtual auto openDoWhile() -> void = 0;
        virtual auto closeDoWhile(const LangAPI::Expression &expression) -> void = 0;
        virtual auto createSwitch(const LangAPI::Expression &expression) -> void = 0;
        virtual auto closeSwitch() -> void = 0;
        virtual auto createCase(const LangAPI::RValue &expression) -> void = 0;
        virtual auto closeCase() -> void = 0;
        virtual auto createExpression(const LangAPI::Expression &expression) -> void = 0;
        virtual auto createVariable(const LangAPI::Variable &v) -> void = 0;
        Statement(Writer &output) : output(output) {}
        virtual ~Statement() = default;

        auto &getWriter()  { return output; }
        auto &getWriter() const  { return output; }

    };
}