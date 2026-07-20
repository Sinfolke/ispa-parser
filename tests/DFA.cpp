#include <gtest/gtest.h>
import Tests.CharMachineDFA;
import DFA.Runtime;
import File;
import corelib;
import logging;
import std;
auto test(std::string f_name) {
    auto f = File::getGrammarFile(f_name);
    auto DFA = DFA::Test::from_file(f.c_str());
    if (DFA.getDFAS().get().empty()) {
        FAIL() << "No token DFAs were built for grammar '" << f_name << "'. Test is meaningless.";
    }
    for (const auto &[name, index] : DFA.getNameToDFAIndex()) {
        const auto &dfa = DFA.getDFAS().get().at(index);
        std::string input_file = File::getTextFile(f_name + "_" + corelib::text::join(name, "_")).string();
        // Skip tokens that don't have a corresponding test fixture file
        if (!std::filesystem::exists(input_file)) {
            std::cout << "[SKIP] Missing fixture: " << input_file << "\n";
            continue;
        }
        std::cout << "[RUN]  " << input_file << std::endl;
        // READ INPUT FILE
        std::ifstream f(input_file);
        if (!f) {
            throw std::runtime_error("Failed to open file " + input_file);
        }
        std::string content((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        // Trim trailing whitespace/newlines to allow single-token fixtures with line endings
        while (!content.empty() && std::isspace(static_cast<unsigned char>(content.back()))) {
            content.pop_back();
        }
        f.close();
        DFA::Runtime::CharMachineDFAExecutor executor(dfa);
        auto sv = std::string_view(content);
        auto result = executor.execute(sv);
        if (result.consumed_length != sv.size()) {
            throw std::runtime_error(
                "Test Error: Input from file '" + input_file +
                "' was not fully consumed (consumed=" + std::to_string(result.consumed_length) +
                "/" + std::to_string(sv.size()) + ")");
        }
        std::cout << "Test Passed: " << input_file << " with len " << result.consumed_length << std::endl;
    }
}
TEST(DFA, Basic) {
    test("basic");
}
