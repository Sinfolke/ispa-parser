export module LangRepresentation.Holder;

import LLIR.API;
import std;
export namespace LangRepresentation {
    class Holder {
        LLIR::Declarations data;
    public:
        Holder(const LLIR::Declarations &data) : data(data) {}
        Holder(LLIR::Declarations &&data) : data(std::move(data)) {}
        Holder() {}

        auto get() -> LLIR::Declarations& { return data; };
        auto get() const -> const LLIR::Declarations& { return data; };

        auto push(const LLIR::Declaration &declaration) -> void { data.push_back(declaration); };
        auto push(LLIR::Declaration &&declaration) -> void { data.push_back(std::move(declaration)); };
    };
}