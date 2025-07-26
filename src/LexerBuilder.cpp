module LexerBuilder;
import corelib;
import LLIR.Builder;
import LLIR.Builder.Data;
import LLIR.Builder.DataWrapper;
import LLIR.Rule.MemberBuilder;
import LLIR.RuleBuilder;
import DFABuilder;
import cpuf.printf;
import std;

bool LexerBuilder::isDfaCompatible(const stdu::vector<AST::RuleMember> &member) {
    for (const auto &mem : member) {
        if (mem.isCll())
            return false;
    }
    return true;
}
void accumulateNestedNames(stdu::vector<AST::RuleMember> members, stdu::vector<stdu::vector<std::string>> &names) {
    for (const auto &mem : members) {
        if (mem.isGroup())
            accumulateNestedNames(mem.getGroup().values, names);
        if (mem.isOp())
            accumulateNestedNames(mem.getOp().options, names);
        if (mem.isName())
            names.push_back(mem.getName().name);
    }
}
void LexerBuilder::build() {
    fcdt.build();
    utype::unordered_set<stdu::vector<stdu::vector<std::string>>> build;
    stdu::vector<DFA> function_dfas;
    stdu::vector<LLIR::Data> functions;
    for (auto mem : fcdt.get()) {
        // mem should be copy
        if (mem.empty())
            continue;
        if (build.contains(mem)) {
            continue;
        }
        build.insert(mem);
        NameToDfaMap involved_symbols;
        for (const auto &name : mem) {
            if (isDfaCompatible(ast[name].rule_members)) {
                involved_symbols[name] = dfas.getDFAS().size();
                dfa_compatible_table[name] = dfas.getDFAS().size();
            } else {
                dfa_compatible_table[name] = DFA_NOT_COMPATIBLE;
                auto it = std::find(mem.begin(), mem.end(), name);
                mem.erase(it);
                LLIR::RuleBuilder builder(ast, name, ast[name], function_dfas);
                builder.build();
                functions.push_back(builder.getData());
            }
            stdu::vector<stdu::vector<std::string>> names;
            accumulateNestedNames(ast[name].rule_members, names);
            // build DFA for each nested member
            for (const auto &nested_name : names) {
                if (isDfaCompatible(ast[nested_name].rule_members)) {
                    involved_symbols[nested_name] = dfas.getDFAS().size();
                    dfa_compatible_table[nested_name] = dfas.getDFAS().size();
                    DFABuilder builder(ast, ast[nested_name].rule_members, &ast[nested_name].data_block, nested_name, true);
                    dfas.getDFAS().push_back(builder.get());
                } else {
                    dfa_compatible_table[nested_name] = DFA_NOT_COMPATIBLE;
                    LLIR::RuleBuilder builder(ast, nested_name, ast[nested_name], function_dfas);
                    builder.build();
                    functions.push_back(builder.getData());
                }
            }
        }
        dispatch_names_involve.emplace(mem, involved_symbols);
        if (!mem.empty()) {
            DFABuilder builder(ast, mem, true);
            dfas.getDFAS().push_back(builder.get());
        }
    }
    function_ir = std::move(LLIR::IR(functions, true, function_dfas));
}
auto LexerBuilder::getDataBlocks() const -> LLIR::DataBlockList {
    LLIR::DataBlockList list;
    for (const auto &[name, rule] : ast) {
        if (corelib::text::isLower(name.back()))
            continue;
        // token here
        stdu::vector<DFA> dfas; LLIR::RuleBuilder builder(ast, name, rule, dfas); builder.build();
        list[name] = builder.getData().block;
    }
    return list;
}

auto LexerBuilder::getStateSet() const -> DFAS::StateSet_t {
    utype::unordered_map<DFA::Transitions, std::size_t> state_to_map;

    auto state_set = dfas.getStateSet();
    function_ir.getDfas().getStateSet(state_set);
    return state_set;
}