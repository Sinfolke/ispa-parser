export module LLIR.LangAPIMembersAccess;

export namespace LLIR::Serialize {

    struct MembersAccess {
        template<typename T>
        static constexpr auto get(T& object)
            -> decltype(object.members())
        {
            return object.members();
        }
    };

}