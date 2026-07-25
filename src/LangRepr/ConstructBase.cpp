module ConstructBase;
import LLIR.Builder.Base;
namespace LangRepr {
    auto ConstructBase::createTypeToken() -> LangAPI::TypeAlias {
        LangAPI::Type variant_type = LangAPI::ValueType::Variant;
        for (const auto &[name, dtb] : lexer_builder.getDataBlocks()) {
            LangAPI::Symbol tn = name;
            tn.path.insert(tn.path.begin(), "Types");
            variant_type.template_parameters.push_back(LangAPI::Type {tn});
        }
        Token = LangAPI::Symbol { "Token" };
        return LangAPI::TypeAlias {.name = "Token", .type = variant_type};
    }
    auto ConstructBase::createLexerClass() -> LangAPI::Class {
        LangAPI::IspaLibSymbol lexer_s {LangAPI::StdlibExports::Lexer};
        lexer_s.template_parameters.push_back(std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Token"}));
        return LangAPI::Class {
            .name = "Lexer",
            .inherit_members = {std::make_pair(LangAPI::Visibility::Public, lexer_s)},
            .default_visibility = LangAPI::Visibility::Private
        };
    }
    auto ConstructBase::getTransitionCount(const std::variant<DFA::FullCharTable, DFA::SortedTransitions> &transitions) -> std::size_t {
        return std::holds_alternative<DFA::FullCharTable>(transitions) ?
            static_cast<int>(std::get<DFA::FullCharTable>(transitions).size())
            :
            static_cast<int>(std::get<DFA::SortedTransitions>(transitions).size());
    }

    auto ConstructBase::makeIntRValue(int v) -> std::shared_ptr<LangAPI::RValue> {
        return std::make_shared<LangAPI::RValue>(
            LangAPI::Int::createRValue(LangAPI::Int{.value = v})
        );
    };
    auto ConstructBase::ensureTypesNs(LangAPI::Type t) -> LangAPI::Type {
        if (t.isSymbol())
            if (std::get<std::string>(t.getSymbol().path.front()) != "Types") {
                t.getSymbol().path.insert(t.getSymbol().path.begin(), "Types");
            }
        if (!t.template_parameters.empty()) {
            for (auto &p : t.template_parameters) p = ensureTypesNs(std::get<LangAPI::Type>(p));
        }
        return t;
    };
    auto ConstructBase::extractRawSymbol(const LangAPI::Type &t) -> stdu::vector<LangAPI::Type> {
        if (t.isSymbol())
            return {t};
        if (!t.template_parameters.empty()) {
            std::vector<LangAPI::Type> types;
            for (auto &p : t.template_parameters) {
                auto r = extractRawSymbol(std::get<LangAPI::Type>(p));
                types.insert(types.end(), r.begin(), r.end());
            }
            return types;
        }
        return {t};
    };
    auto ConstructBase::getStateType(DFA::DfaType state_type) -> LangAPI::IspaLibSymbol {
        LangAPI::IspaLibSymbol s;
        auto makeReturnType = [&]() -> std::shared_ptr<LangAPI::Type> {
            auto rt = std::make_shared<LangAPI::Type>(LangAPI::Symbol{"Token"});
            return rt;
        };
        switch (state_type) {
            case DFA::DfaType::Char:
                s.exports = LangAPI::StdlibExports::DfaCharState;
                break;
            case DFA::DfaType::Token:
                s.exports = LangAPI::StdlibExports::DfaTokenState;
                break;
            case DFA::DfaType::Multi:
                s.exports = LangAPI::StdlibExports::DfaMultiTableState;
                s.template_parameters = { makeReturnType() };
                break;
            default:
                s.exports = LangAPI::StdlibExports::EmptyState;
                s.template_parameters.push_back(makeReturnType());
        }
        return s;
    }

    auto ConstructBase::buildLambdaContent(
        LangAPI::Symbol builder_sym,
        const NFA::TemplatedDataBlockValue &data_block,
        long long N
    ) -> LangAPI::StorageSymbol {
        // where to look for data
        LangAPI::Symbol position_manager = (data_block.type == NFA::StoreCstNode::CST_GROUP ? "gb" : "mb");

        decltype(LangAPI::FunctionCall::template_parameters) template_parameters;
        LangAPI::Array indices_with_groups {.template_parameters = {{std::make_shared<LangAPI::Type>(LangAPI::Type {LangAPI::ValueType::Int})}}};
        decltype(LangAPI::FunctionCall::args) args;
        std::string call_name;
        template_parameters.push_back(LangAPI::RValue {LangAPI::Int {.value = N}});
        if (data_block.type == NFA::StoreCstNode::CST_CONDITION) {
            call_name = "condition";
            // determine what indices have groups
            long long el_count = 0;
            for (const auto &element : data_block.AST->getOp().options) {
                if (element.isGroup())
                    indices_with_groups.values.push_back(LangAPI::Int::createExpression(LangAPI::Int {.value = el_count}));
                el_count++;
                auto raw_sym_vec = extractRawSymbol(ensureTypesNs(LLIR::BuilderBase::deduceVarTypeByRuleMember(element)));
                template_parameters.insert(template_parameters.end(), raw_sym_vec.begin(), raw_sym_vec.end());
            }
            args = {LangAPI::Array::createExpression(indices_with_groups)};
        } else {
            call_name = data_block.type == NFA::StoreCstNode::CST_GROUP ? "group" : "element";
        }


        LangAPI::StorageSymbol call_to_function;
        call_to_function.what = LangAPI::Symbol::createExpression(builder_sym);
        call_to_function.path = {
            LangAPI::FunctionCall {
                .name = std::make_shared<LangAPI::Symbol>(call_name),
                .template_parameters=template_parameters,
                .args = args
            }
        };
        return call_to_function;
    }

    auto ConstructBase::makeEmptyStateLambda(DFA::DfaType dfa_type, const stdu::vector<std::string> &name, const stdu::vector<std::string> &clear_name,
                                              const NFA::DataBlock &nfa_dtb) -> LangAPI::Lambda {
        stdu::vector<std::pair<LangAPI::Type, std::string>> params;
        params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaEmptyStateMemberBegin, .Const =  true, .Reference = true}}, "mb"});
        params.push_back({LangAPI::Type{LangAPI::IspaLibSymbol{.exports = LangAPI::StdlibExports::DfaEmptyStateGroupBegin, .Const = true, .Reference = true}}, "gb"});
        params.push_back({
            LangAPI::Type{LangAPI::IspaLibSymbol{
                .exports = LangAPI::StdlibExports::DfaUniversalDataVector,
                .template_parameters = {std::make_shared<LangAPI::Type>(LangAPI::Type {Token})},
                .Const = true,
                .Reference = true
            }
        }, "dv"});

        LangAPI::Statements body;
        const auto data_blocks = lexer_builder.getDataBlocks();
        const auto &data_block = data_blocks.at(clear_name);
        // declare builder
        auto builder_internal_type = LangAPI::IspaLibSymbol {.exports = LangAPI::StdlibExports::DfaCstBuilder,
            .template_parameters = {
                std::make_shared<LangAPI::Type>(ensureTypesNs(LangAPI::Type {LangAPI::Symbol {name}})),
                std::make_shared<LangAPI::Type>(Token),
            }
        };
        auto builder_symbol = LangAPI::Symbol {"builder"};
        if (data_block.is_inclosed_map()) {
            const auto &templated_data_block = std::get<NFA::TemplatedDataBlock>(nfa_dtb);
            long long N = 0;
            for (const auto &[mname, mdata] : data_block.getInclosedMap()) {
                // add this node type to builder
                builder_internal_type.template_parameters.push_back(std::make_shared<LangAPI::Type>(ensureTypesNs(mdata.second)));
                auto current_templated_data_block = templated_data_block.at(mname);
                body.push_back(LangAPI::StorageSymbol::createStatement(buildLambdaContent(builder_symbol, current_templated_data_block, N)));
                ++N;
            }
        } else if (!data_block.empty()) {
            const auto &[data, type] = data_block.getRegularDataBlock();
            const auto &sv_data_block = std::get<NFA::TemplatedDataBlockValue>(nfa_dtb);
            builder_internal_type.template_parameters.push_back(std::make_shared<LangAPI::Type>(ensureTypesNs(type)));
            body.push_back(LangAPI::StorageSymbol::createStatement(buildLambdaContent(builder_symbol, sv_data_block, 0)));
        } else {
            body.push_back(LangAPI::Return::createStatement(LangAPI::Return { .value = LangAPI::Inheritance::createExpression( LangAPI::Inheritance { .name = LangAPI::Symbol {name} }) }));
            return LangAPI::Lambda{ .parameters = std::move(params), .statements = std::move(body)};
        }
        auto args = LangAPI::Inheritance {
            .name = builder_internal_type,
            .args = {
                LangAPI::Symbol::createExpression(LangAPI::Symbol {"dv"}),
                LangAPI::Symbol::createExpression(LangAPI::Symbol {"mb"}),
                LangAPI::Symbol::createExpression(LangAPI::Symbol {"gb"})
            }
        };
        auto builder = LangAPI::Variable {
            .name = "builder",
            .type = builder_internal_type,
            .value = LangAPI::Inheritance::createExpression(args)
        };
        body.insert(body.begin(), LangAPI::Variable::createStatement(builder));;
        LangAPI::StorageSymbol return_storage_symbol;
        return_storage_symbol.what = LangAPI::Symbol::createExpression(builder_symbol);
        return_storage_symbol.path = {LangAPI::FunctionCall {.name = std::make_shared<LangAPI::Symbol>("build")}};
        body.push_back(LangAPI::Return::createStatement(
            LangAPI::Return {
                .value = LangAPI::StorageSymbol::createExpression(return_storage_symbol)
            }
        ));
        return LangAPI::Lambda{ .parameters = std::move(params), .statements = std::move(body)};
    }
}