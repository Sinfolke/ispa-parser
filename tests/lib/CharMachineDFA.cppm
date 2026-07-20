export module Tests.CharMachineDFA;

import DFA.CharMachineDFA;
import LexerBuilder;
import std;
import dstd;
export namespace DFA::Test {
    struct TestResult {
        bool accepted;
        std::size_t accept_index;
        std::size_t consumed_length;
    };

    auto execute(const CharMachineDFA &dfa, std::string_view input) -> TestResult;
    auto from_file(const char* f) -> LexerBuilder;;
    auto from_file(const char* f, stdu::vector<std::string> token_name) -> DFA::CharMachineDFA;
}