module LLIR.Builder.Utility;
import LLIR;
import std;
import std.compat;
void LLIR::BuilderUtility::setUtilityPointer(LLIR::Nodes *data) {
    this->data = data;
}
void LLIR::BuilderUtility::removePrevSpaceSkip() {
    if (!data->empty()) {
        // remove previous skip of spaces if it does exists
        for (size_t i = data->size(); i > 0; i++) {
            if (data->operator[](i).type == LLIR::types::SKIP_SPACES) {
                data->erase(data->begin() + i);
                break;
            }
        }
    }
}