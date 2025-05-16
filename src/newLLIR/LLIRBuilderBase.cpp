module;
#include <ostream>
module LLIRBuilderBase;
std::ostream &operator<<(std::ostream &os, const LLIRBuilderBase &data) {
    data.print(os);
    return os;
}
auto LLIRBuilderBase::getData() -> ::LLIR::Nodes & {
    return data;
}
auto LLIRBuilderBase::getData() const -> const ::LLIR::Nodes & {
    return data;
}

