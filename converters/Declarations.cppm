export module Converter.Declarations;

import Converter.Writer;
import Converter.Type;
import dstd;
import std;
export namespace Converter {
    class Declarations {
        std::unordered_map<std::string, std::size_t> names;
        Writer &writer;
    protected:
        // declarations
        virtual auto createNamespace(const std::string &name) -> void = 0;
        virtual auto createClass(const std::string &name) -> void = 0;
        virtual auto createFunction(const std::string &name) -> void = 0;

        // types
        virtual auto createFixedStruct(const std::string &name, const stdu::vector<std::string> &keys) -> void;
        virtual auto createTypeAlias(const std::string &name, const Type type) -> void;
        virtual auto createEnum(const std::string &name, const stdu::vector<std::string> names) -> void;
    public:
        Declarations(Writer &writer) : writer(writer) {}
        virtual ~Declarations() = default;
    };
}