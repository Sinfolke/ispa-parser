export module LLIR.Builder.Utility;
import LLIR;
export namespace LLIR {
    class BuilderUtility {
        LLIR::Nodes *data = nullptr;
    protected:
        void setUtilityPointer(LLIR::Nodes *data);
    public:
        void removePrevSpaceSkip();

        BuilderUtility(LLIR::Nodes *data) : data(data) {}
    };
}