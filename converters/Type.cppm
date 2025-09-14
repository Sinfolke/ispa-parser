export module Converter.Type;

import std;
export namespace Converter {
    class Type {
    public:
        struct IntegralType {};
        struct FloatType {};
        struct StringType {};
        struct EnumType {};
        struct ArrayType {
            std::shared_ptr<Type> template_argument;
        };
        struct MapType {
            std::shared_ptr<Type> template_key;
            std::shared_ptr<Type> template_value;
        };
        enum class TypeEnum {
            Integral, Float, String, Enum, Array, Map
        };
        Type(std::variant<IntegralType, FloatType, StringType, EnumType, ArrayType, MapType> type) : type(type) {}
        ~Type();
        auto get() -> std::variant<IntegralType, FloatType, StringType, EnumType, ArrayType, MapType> {
            return type;
        }
        auto getEnum() -> TypeEnum {
            return static_cast<TypeEnum>(type.index());
        }
    private:
        std::variant<IntegralType, FloatType, StringType, EnumType, ArrayType, MapType> type;
    };
}