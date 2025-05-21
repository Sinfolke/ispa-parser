module RvalueBuilder;
import std;
import logging;
import CllBuilder;
import std;
auto LLIR::RvalueBuilder::get() -> assign {
    return data;
}
auto LLIR::RvalueBuilder::deduceType() -> LLIR::var_type {
    LLIR::var_type type = {LLIR::var_types::UNDEFINED};
    if (value->isString())
        type.type = LLIR::var_types::STRING;
    else if (value->isBoolean())
        type.type = LLIR::var_types::BOOLEAN;
    else if (value->isNumber())
        type.type = LLIR::var_types::NUMBER;
    else if (value->isID()) {
        // likely never execute
        auto find_it = std::find_if(vars->begin(), vars->end(), [&](const LLIR::variable &var) { return var.name == value->getID().value; });
        if (find_it == vars->end())
            throw Error("Not found variable to deduce type from expr");
        if (find_it->type.type == LLIR::var_types::Rule_result)
            type = {LLIR::var_types::Rule};
        else if (find_it->type.type == LLIR::var_types::Token_result)
            type = {LLIR::var_types::Token};
        else type = find_it->type;
    } else if (value->isAt()) {
        if (unnamed_datablock_units->empty())
            throw Error("no more data accamulated with @");
        const auto &t = unnamed_datablock_units->front().type;
        if (t.type == LLIR::var_types::Rule_result)
            type = {LLIR::var_types::Rule};
        else if (t.type == LLIR::var_types::Token_result)
            type = {LLIR::var_types::Token};
        else type = t;
    } else if (value->isArray()) {
        LLIR::var_type types;
        for (const auto &el : value->getArray().value) {
            if (types.type == LLIR::var_types::UNDEFINED) {
                types = CllExprBuilder(*this, el).deduceType();
            } else {
                auto newType = CllExprBuilder(*this, el).deduceType();
                if (newType.type != types.type || !compare_templ(newType.templ, types.templ)) {
                    type.type = LLIR::var_types::ANY;
                    break;
                }
            }
        }
        if (types.type != LLIR::var_types::ANY) {
            type.templ = {types};
            type.type = LLIR::var_types::ARRAY;
        }
    } else if (value->isObject()) {
        // todo: add handle key of different types (int or string)
        LLIR::var_type types;
        for (const auto &[key, value] : value->getObject().value) {
            if (types.type == LLIR::var_types::UNDEFINED) {
                types = CllExprBuilder(*this, value).deduceType();
            } else {
                auto newType = CllExprBuilder(*this, value).deduceType();
                if (newType.type != types.type || !compare_templ(newType.templ, types.templ)) {
                    type.type = LLIR::var_types::ANY;
                    break;
                }
            }
        }
        if (types.type != LLIR::var_types::ANY) {
            type.templ = {types};
            type.type = LLIR::var_types::OBJECT;
        }
    } else {
        throw Error("Undefined rule");
    }
    return type;
}
void LLIR::RvalueBuilder::build() {
    LLIR::assign data;
    if (value->isString()) {
        data.kind = LLIR::var_assign_values::STRING;
        data.data = std::any_cast<std::string>(value->getString().value);
    } else if (value->isBoolean()) {
        data.kind = LLIR::var_assign_values::BOOLEAN;
        data.data = value->getBoolean().getBoolean() ? LLIR::var_assign_values::True : LLIR::var_assign_values::False;
    } else if (value->isNumber()) {
        data.kind = LLIR::var_assign_values::NUMBER;
        data.data = value->getNumber().getFull();
    } else if (value->isID()) {
        data.kind = LLIR::var_assign_values::VAR_REFER;
        auto find_it = std::find_if(vars->begin(), vars->end(), [&](const LLIR::variable &var) { return var.name == value->getID().value; });
        if (find_it == vars->end())
            throw Error("Not found variable to convert into expr");
        data.data = LLIR::var_refer {.var = *find_it };
    } else if (value->isAt()) {
        data.kind = LLIR::var_assign_values::VAR_REFER;
        data.data = LLIR::var_refer {.var = unnamed_datablock_units->front()};
        unnamed_datablock_units->erase(unnamed_datablock_units->end());
    } else if (value->isArray()) {
        data.kind = LLIR::var_assign_values::ARRAY;
        LLIR::array arr;
        for (const auto el : value->getArray().value) {
            CllExprBuilder builder(*this, el);
            builder.build();
            arr.push_back(builder.get());
        }
        data.data = arr;
    } else if (value->isObject()) {
        data.kind = LLIR::var_assign_values::OBJECT;
        LLIR::object obj;
        for (const auto &[key, value] : value->getObject().value) {
            CllExprBuilder builder(*this, value);
            builder.build();
            obj[key] = builder.get();
        }
        data.data = obj;
    } else throw Error("Undefined rvalue");
}
