module Tests.CharMachineDFA;
import NFA;
import DFA.CharMachineDFA;
import DFA.Runtime;
import DFA.functionality;
import LexerBuilder;
import Tests.AST;
import dstd;
import std;

auto DFA::Test::execute(const DFA::CharMachineDFA &dfa, std::string_view input) -> TestResult {
    DFA::Runtime::CharMachineDFAExecutor executor(dfa);
    auto result = executor.execute(input);
    return {result.accepted, result.accept_index, result.consumed_length};
}

auto DFA::Test::from_file(const char *f) -> LexerBuilder {
    auto AST = AST::Test::get(f);
    LexerBuilder builder(AST);
    builder.build();
    return builder;
}

auto DFA::Test::from_file(const char* f, stdu::vector<std::string> token_name) -> DFA::CharMachineDFA {
    auto AST = AST::Test::get(f);
    LexerBuilder builder(AST);

    // 2. Perform a complete, correct grammar resolution pass
    builder.build();

    // 3. Extract the master lookup mapping populated in Step 5 of LexerBuilder
    // (Ensure builder.name_to_dfa or an accessor is available)
    const auto& name_map = builder.getNameToDFAIndex();
    const auto& dfa_collection = builder.getDFAS().get();

    auto it = name_map.find(token_name);
    if (it == name_map.end()) {
        throw std::runtime_error("Test Error: Requested token group was not built by the generator pipeline.");
    }

    std::size_t target_index = it->second;
    if (target_index >= dfa_collection.size()) {
        throw std::out_of_range("Test Error: Internal table discrepancy. Resolved DFA index out of bounds.");
    }

    // 4. Return the fully formed, context-aware machine
    return dfa_collection[target_index];
}