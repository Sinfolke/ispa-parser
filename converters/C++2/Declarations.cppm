export module Cpp.Declarations;

import Converter.Declarations;
namespace Cpp {
    export class Declarations : Converter::Declarations {
    public:
        virtual auto createNamespace(const std::string &name) -> void;
        virtual auto createClass(const std::string &name) -> void;
        virtual auto createFunction(const std::string &name) -> void;

        // types
        virtual auto createFixedStruct(const std::string &name, const stdu::vector<std::string> &keys) -> void;
        virtual auto createTypeAlias(const std::string &name, const Type type) -> void;
        virtual auto createEnum(const std::string &name, const stdu::vector<std::string> names) -> void;

        using Converter::Declarations::Declarations;
        virtual ~Declarations() = default;
    };
}