module LangRepr.Construct;

import Dump;

import LLIR.API;
import NFA;
import DFA.API;

import constants;
import corelib;
import cpuf.printf;
import logging;
import hash;
import DFA.Collection;
import DFA.CharMachineDFA;
import DFA.Base;

import dstd;
import std;

import LangRepr.ConstructTypes;
import LangRepr.ConstructLexer;

namespace LangRepr {
    auto Construct::constructTypes() -> void {
        ConstructTypes construct_types(holder, lexer_builder, ir);
        construct_types.constructTokensAndRulesEnum();
        // construct_types.constructTokensAndRulesEnumToString();
        construct_types.constructTypesNamespace();
    }

    auto Construct::constructLexer() -> void {
        ConstructLexer construct_lexer(holder, lexer_builder, ir);
        construct_lexer.constructLexer();

    }
    auto Construct::constructParser() -> void {
        LangAPI::IspaLibSymbol parser_symbol {LangAPI::StdlibExports::Parser};
        // MainNode first
        LangAPI::Symbol main_tn = {"main"};
        main_tn.path.insert(main_tn.path.begin(), "Types");
        parser_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(main_tn));

        // Then all other rules
        for (const auto &dtb : ir.getDataBlocks()) {
            if (dtb.first == stdu::vector<std::string>{"main"}) continue;
            LangAPI::Symbol tn = dtb.first;
            tn.path.insert(tn.path.begin(), "Types");
            parser_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(tn));
        }
        // And also all token types (Lexer_base needs them in LLParser_base)
        for (const auto &dtb : lexer_builder.getDataBlocks()) {
            LangAPI::Symbol tn = dtb.first;
            tn.path.insert(tn.path.begin(), "Types");
            parser_symbol.template_parameters.push_back(std::make_shared<LangAPI::Type>(tn));
        }

        LangAPI::Class parser {
            .name = "Parser",
            .inherit_members = {std::make_pair(LangAPI::Visibility::Public, parser_symbol)},
            .default_visibility = LangAPI::Visibility::Private
        };
        // construct DFAs
        for (const auto &dfa : ir.getDfas()) {

        }
        for (const auto &fun_data : ir.getData()) {
            std::function<void(LangAPI::Type&)> fun_data_type_modifier = [&](LangAPI::Type& t) {
                if (t.isSymbol()) {
                    auto &sym = t.getSymbol();
                    sym.path.insert(sym.path.begin(), "Types");
                } else {
                    for (auto &tp : t.template_parameters) {
                        if (std::holds_alternative<LangAPI::Type>(tp))
                            fun_data_type_modifier(std::get<LangAPI::Type>(tp));
                    }
                }
            };
            LangAPI::Symbol fun_data_symbol = fun_data.name;
            fun_data_symbol.path.insert(fun_data_symbol.path.begin(), "Types");
            for (auto &statement : fun_data.members) {
                if (statement.isVariable()) {
                    auto &var = statement.getVariable();
                    fun_data_type_modifier(var.type);
                } else if (statement.isExpression()) {
                    auto &expr = statement.getExpression();
                    if (expr.size() == 1 && expr.front().isDfaLookup()) {
                        auto &dfa_lookup = expr.front().getDfaLookup();
                        fun_data_type_modifier(dfa_lookup.return_type);
                    }
                }
            }
            parser.data.push_back(
                std::make_pair(
                    std::make_shared<LangAPI::Declaration>(
                        LangAPI::Function::createDeclaration(LangAPI::Function {
                            .type = LangAPI::Type {LangAPI::IspaLibSymbol {LangAPI::StdlibExports::Node, {std::make_shared<LangAPI::Type>(LangAPI::Symbol {"Rules"}), std::make_shared<LangAPI::Type>(LangAPI::Symbol {fun_data_symbol})}}},
                            .name = corelib::text::join(fun_data.name, "_"),
                            .parameters = {std::make_pair(LangAPI::Type {LangAPI::IspaLibSymbol {LangAPI::StdlibExports::ParserFunctionParameter} }, "pos")},
                            .statements =  fun_data.members,
                            .template_parameters = {"Iterator"}
                        })
                    ),
                    LangAPI::Visibility::Public
                )
            );
        }
        holder.push(parser);
    }

    auto Construct::construct() -> Holder& {
        constructTypes();
        constructLexer();
        // constructParser();
        LangAPI::Namespace ns;
        ns.name = namespace_name;
        ns.declarations = std::move(holder.get());
        holder.get().clear();
        holder.push(ns);
        return holder;
    }
    auto Construct::construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, LangAPI::Language lang, const std::string &namespace_name) -> Holder {
        Construct construct(std::move(lexer_builder), std::move(ir), lang, namespace_name);
        return construct.construct();
    }
}
