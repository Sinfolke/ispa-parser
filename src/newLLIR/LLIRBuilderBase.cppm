module;
#include <ostream>
export module LLIRBuilderBase;
import LLIR;
export class LLIRBuilderBase {
protected:
    LLIR::Nodes data;
    virtual void build() = 0;
public:
    virtual auto getData() const -> const LLIR::Nodes&;
    virtual auto getData() -> LLIR::Nodes&;
    virtual void print(std::ostream &os) const = 0;
};
std::ostream &operator<<(std::ostream &os, const LLIRBuilderBase &data);