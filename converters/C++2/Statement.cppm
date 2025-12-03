export module Cpp.Statement;

import Converter.Statement;
import Converter.Writer;
import LangAPI;
import Rope.String;
import std;

export namespace Cpp {
    class Statement : ::Converter::Statement {
        Converter::Writer &output;
    public:
        Statement(Converter::Writer &output) : output(output) {}

        auto createIf(const LangAPI::Expression &expression)-> void override;
        auto closeIf() -> void override;
        auto createWhile(const LangAPI::Expression &expression) -> void override;
        auto closeWhile() -> void override;
        auto openDoWhile() -> void override;
        auto closeDoWhile(const LangAPI::Expression &expression) -> void override;
        auto createSwitch(const LangAPI::Expression &expression) -> void override;
        auto createCase(const LangAPI::RValue &rvalue) -> void override;
        auto closeCase() -> void override;
        auto closeSwitch() -> void override;
        auto createExpression(const LangAPI::Expression &expression) -> void override;
        auto createVariable(const LangAPI::Variable &v) -> void override;

        virtual ~Statement() = default;
    };
}
