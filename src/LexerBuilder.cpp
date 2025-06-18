module LexerBuilder;
import corelib;
import LLIR.Builder;
import LLIR.Builder.Data;
import LLIR.Builder.DataWrapper;
import LLIR.Rule.MemberBuilder;
import LLIR.RuleBuilder;
import DFABuilder;
import std;
bool LexerBuilder::isDfaCompatible(const stdu::vector<AST::RuleMember> &member) {
    for (const auto &mem : member) {
        if (mem.isCll())
            return false;
    }
    return true;
}

void LexerBuilder::build() {
    fcdt.build();
    std::size_t dfa_count = 0;
    utype::unordered_set<std::set<FCDT::Name>> build;
    stdu::vector<DFA> function_dfas;
    stdu::vector<LLIR::Data> functions;
    for (auto mem : fcdt.get()) {
        if (mem.empty())
            continue;
        if (build.contains(mem)) {
            continue;
        }
        build.insert(mem);
        NameToDfaMap involved_symbols;
        for (const auto &name : mem) {
            if (isDfaCompatible(ast[name.name].rule_members)) {
                involved_symbols[name] = dfa_count;
                dfa_compatible_table[name.name] = true;
            } else {
                dfa_compatible_table[name.name] = DFA_NOT_COMPATIBLE;
                mem.erase(name);
                LLIR::RuleBuilder builder(ast, name.name, ast[name.name], function_dfas);
                functions.push_back(builder.getData());
            }
        }
        dispatch_names_involve.emplace(mem, involved_symbols);
        dfas.push_back(DFABuilder(ast, mem).get());
        dfa_count++;
    }
    function_ir = std::move(LLIR::IR(functions, function_dfas));
}
