#include <gtest/gtest.h>
import CppParser;
import Tests.YAML;
import File;
import std;

TEST(Cpp, Lexer) {
    auto cfg = loadLexerConfig(File::getYamlConfigFile("lexer/lexer"));

    for (const auto& lexerTest : cfg.tests)
    {

        CppParser parser("lexer/" + lexerTest.grammar);
        int code;
        try {
            code = parser.generate();
        } catch (std::exception& e) {
            FAIL() << "Test failed [generate]: " << e.what();
        }
        ASSERT_EQ(code, 0);
        std::cout << "Test '" << lexerTest.name << "' Generated" << std::endl;
        try {
            code = parser.compile(cfg.bootloader);
        } catch (std::exception& e) {
            FAIL() << "Test failed [compile]: " << e.what();
        }
        ASSERT_EQ(code, 0);
        std::cout << "Test '" << lexerTest.name << "' Compiled" << std::endl;
        for (const auto& tc : lexerTest.cases)
        {
            auto status = parser.run(tc.input);
            if (status != 0) {
                FAIL() << "Test failed: " << tc.input;
            }
            std::cout << "Test '" << lexerTest.name << "' Passed: " << tc.input << std::endl;
        }
    }
}
TEST(Cpp, Parser) {
    auto cfg = loadLexerConfig(File::getYamlConfigFile("parser/parser"));

    for (const auto& parserTest : cfg.tests)
    {
        CppParser parser("parser/" + parserTest.grammar);
        int code;
        try {
            code = parser.generate();
        } catch (std::exception& e) {
            FAIL() << "Test failed [generate]: " << e.what();
        }
        ASSERT_EQ(code, 0);
        std::cout << "Test '" << parserTest.name << "' Generated" << std::endl;
        try {
            code = parser.compile(cfg.bootloader);
        } catch (std::exception& e) {
            FAIL() << "Test failed [compile]: " << e.what();
        }
        ASSERT_EQ(code, 0);
        std::cout << "Test '" << parserTest.name << "' Compiled" << std::endl;
        for (const auto& tc : parserTest.cases)
        {
            auto status = parser.run(tc.input);
            if (status != 0) {
                FAIL() << "Test failed: " << tc.input;
            }
            std::cout << "Test '" << parserTest.name << "' Passed: " << tc.input << std::endl;
        }
    }
}