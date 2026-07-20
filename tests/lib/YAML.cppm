module;
#include <yaml-cpp/yaml.h>
export module Tests.YAML;
import std;
export struct ExpectedToken {
    std::string token;
    YAML::Node value;
};

export struct TestCase {
    std::string input;
    std::vector<ExpectedToken> expected;
};

export struct LexerTest {
    std::string name;
    std::string grammar;
    std::vector<TestCase> cases;
};

export struct LexerConfig {
    std::string bootloader;
    std::vector<LexerTest> tests;
};

export LexerConfig loadLexerConfig(const std::filesystem::path& path);
