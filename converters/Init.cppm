export module Converter.Init;
import std;
export namespace Converter {
    void init(const char* name);
    void close();
    auto getSource() -> std::optional<std::string>;
}