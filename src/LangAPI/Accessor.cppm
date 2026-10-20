export module LangAPI.Accessor;

export namespace LangAPI {

    struct MembersAccess {
        template<typename T>
        static constexpr auto get(T& object)
            -> decltype(object.members())
        {
            return object.members();
        }
    };

}