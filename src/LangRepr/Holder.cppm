export module LangRepr.Holder;

import LangAPI;
import std;
export namespace LangRepr {
    class Holder {
        LangAPI::Declarations data;
    public:
        Holder(const LangAPI::Declarations &data) : data(data) {}
        Holder(LangAPI::Declarations &&data) : data(std::move(data)) {}
        Holder() {}

        auto get() -> LangAPI::Declarations& { return data; };
        auto get() const -> const LangAPI::Declarations& { return data; };

        auto push(const LangAPI::Declaration &declaration) -> void { data.push_back(declaration); };
        auto push(LangAPI::Declaration &&declaration) -> void { data.push_back(std::move(declaration)); };

        template<typename First, typename ...Args>
        auto push(const First &first, Args&& ...args) -> void {
            data.push_back(First::createDeclaration(first));
            (data.push_back(Args::createDeclaration(std::forward<Args>(args))), ...);
        };
    };
}