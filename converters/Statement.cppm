export module Converter.Statement;

import LangAPI;
export namespace Converter {
    class Statement {
    public:
        virtual auto createIf(const LangAPI::Expression &expression) -> void = 0;
        virtual auto createVariable(const LangAPI::Variable &v) -> void = 0;
        virtual ~Statement() = default;
    };
}