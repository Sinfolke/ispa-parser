module;

export module LLIRBuilderUtility;
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