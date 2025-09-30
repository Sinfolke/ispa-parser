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
        auto createVariable(const LangAPI::Variable &v) -> void override;

        virtual ~Statement() = default;
    };
}
