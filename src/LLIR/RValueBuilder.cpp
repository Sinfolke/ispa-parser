module LLIR.RValueBuilder;
import std;
import logging;
import LLIR.CllBuilder;
import std;
auto LLIR::RValueBuilder::get() -> RValue {
    return data;
}
auto LLIR::RValueBuilder::deduceType() -> Type {
    Type type = {ValueType::Undef};
    if (value.isString())
        type.type = ValueType::String;
    else if (value.isBoolean())
        type.type = ValueType::Bool;
    else if (value.isNumber())
        type.type = ValueType::Int;
    else if (value.isID()) {
        // likely never execute
        auto find_it = std::find_if(vars.begin(), vars.end(), [&](const Variable &var) { return var.name == value.getID().value; });
        if (find_it == vars.end())
            throw Error("Not found variable to deduce type from expr");
        if (find_it->type.type == ValueType::RuleResult)
            type = {ValueType::Rule};
        else if (find_it->type.type == ValueType::TokenResult)
            type = {ValueType::Token};
        else type = find_it->type;
    } else if (value.isAt()) {
        if (unnamed_datablock_units.empty())
            throw Error("no more data accamulated with @");
        const auto &t = unnamed_datablock_units.front().type;
        if (t.type == ValueType::RuleResult)
            type = {ValueType::Rule};
        else if (t.type == ValueType::TokenResult)
            type = {ValueType::Token};
        else type = t;
    } else if (value.isArray()) {
        Type types;
        for (const auto &el : value.getArray().value) {
            if (types.type == ValueType::Undef) {
                types = CllExprBuilder(*this, el).deduceType();
            } else {
                auto newType = CllExprBuilder(*this, el).deduceType();
                if (newType != types) {
                    type.type = ValueType::Any;
                    break;
                }
            }
        }
        if (types.type != ValueType::Any) {
            type.template_parameters = {types};
            type.type = ValueType::Array;
        }
    } else if (value.isObject()) {
        // todo: add handle key of different types (int or string)
        Type types = {ValueType::Undef};
        for (const auto &[key, value] : value.getObject().value) {
            if (types.type == ValueType::Undef) {
                types = CllExprBuilder(*this, value).deduceType();
            } else {
                auto newType = CllExprBuilder(*this, value).deduceType();
                if (newType != types) {
                    type.type = ValueType::Any;
                    break;
                }
            }
        }
        if (types.type != ValueType::Any) {
            type.template_parameters = {types};
            type.type = ValueType::Map;
        }
    } else {
        throw Error("Undefined rule");
    }
    return type;
}
void LLIR::RValueBuilder::build() {
    if (value.isString()) {
        data.set(String {.value = value.getString().value});
    } else if (value.isBoolean()) {
        data.set(Bool {.value = value.getBoolean().getBoolean()});
    } else if (value.isNumber()) {
        data.set(Float {.value = value.getNumber().getFullNumber()});
    } else if (value.isID()) {
        auto find_it = std::find_if(vars.begin(), vars.end(), [&](const LLIR::Variable &var) { return var.name == value.getID().value; });
        if (find_it == vars.end())
            throw Error("Not found variable to convert into expr");
        data.set(Symbol {find_it->name});
    } else if (value.isAt()) {
        data.set(Symbol {unnamed_datablock_units.front().name});
        unnamed_datablock_units.erase(unnamed_datablock_units.end() - 1);
    } else if (value.isArray()) {
        Array array;
        for (const auto el : value.getArray().value) {
            CllExprBuilder builder(*this, el);
            builder.build();
            array.values.push_back(builder.get());
        }
        data.set(array);
    } else if (value.isObject()) {
        Map map;
        for (const auto &[key, value] : value.getObject().value) {
            CllExprBuilder builder(*this, value);
            builder.build();
            map.keys.push_back(String { .value = key });
            map.values.push_back(std::move(builder.get()));
        }
        data.set(map);
    } else throw Error("Undefined rvalue");
}
