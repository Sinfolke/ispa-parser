export module LLIR.Builder.Utility;
import LangAPI;
export namespace LLIR {
    class BuilderUtility {
        LangAPI::Statements &statements;
    public:
        void removePrevSpaceSkip();

        BuilderUtility(LangAPI::Statements &statements) : statements(statements) {}
    };
}