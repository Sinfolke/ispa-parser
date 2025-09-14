export module LLIR.Builder.Utility;
import LLIR.API;
export namespace LLIR {
    class BuilderUtility {
        Statements *statements = nullptr;
    protected:
        void setUtilityPointer(Statements *data);
    public:
        void removePrevSpaceSkip();

        BuilderUtility(Statements *statements) : statements(statements) {}
    };
}