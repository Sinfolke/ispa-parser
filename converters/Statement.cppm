export module Converter.Statement;

import LLIR.API;
export namespace Converter {
    class Statement {
    public:
        virtual auto createIF(LLIR::expr) = 0;
        virtual ~Statement() = default;
    };
}