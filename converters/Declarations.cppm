export module Converter.Declarations;

import Converter.Writer;
import Converter.Type;
import dstd;
import std;
export namespace Converter {
    class Declarations {
    protected:
        std::unordered_map<std::string, std::size_t> names;
        Writer &writer;
    public:
        // declarations
        virtual auto createNamespace(const std::string &name) -> void = 0;
        virtual auto createClass(const std::string &name) -> void = 0;
        virtual auto createFunction(const std::string &name) -> void = 0;

        // types
        virtual auto createFixedStruct(const std::string &name, const stdu::vector<std::string> &keys) -> void = 0;
        virtual auto createTypeAlias(const std::string &name, const Type type) -> void = 0;
        virtual auto createEnum(const std::string &name, const stdu::vector<std::string> &names) -> void = 0;

        Declarations(Writer &writer) : writer(writer) {}
        virtual ~Declarations() = default;
    };
}