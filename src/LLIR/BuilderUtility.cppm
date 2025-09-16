export module LLIR.Builder.Utility;
import LLIR.API;
export namespace LLIR {
    class BuilderUtility {
        Statements &statements;
    public:
        void removePrevSpaceSkip();

        BuilderUtility(Statements &statements) : statements(statements) {}
    };
}