module;
#include <yaml-cpp/yaml.h>
module Tests.YAML;
LexerConfig loadLexerConfig(const std::filesystem::path& path)
{
    YAML::Node root = YAML::LoadFile(path.string());

    LexerConfig cfg;
    cfg.bootloader = root["bootloader"].as<std::string>();

    for (const auto& testNode : root["tests"])
    {
        LexerTest test;

        test.name = testNode["name"].as<std::string>();
        test.grammar = testNode["path"].as<std::string>();

        const auto inputNode = testNode["input"];
        const auto expectNode = testNode["expect"];

        if (inputNode.IsScalar())
        {
            TestCase tc;
            tc.input = inputNode.as<std::string>();

            for (const auto& tokenNode : expectNode)
            {
                ExpectedToken tok;
                tok.token = tokenNode["for"].as<std::string>();
                tok.value = tokenNode["value"];
                tc.expected.push_back(std::move(tok));
            }

            test.cases.push_back(std::move(tc));
        }
        else if (inputNode.IsSequence())
        {
            if (!expectNode.IsSequence() || expectNode.size() != inputNode.size())
                throw std::runtime_error(
                    "Input/expect count mismatch in test '" + test.name + "'");

            for (std::size_t i = 0; i < inputNode.size(); ++i)
            {
                TestCase tc;
                tc.input = inputNode[i].as<std::string>();

                for (const auto& tokenNode : expectNode[i])
                {
                    ExpectedToken tok;
                    tok.token = tokenNode["for"].as<std::string>();
                    tok.value = tokenNode["value"];
                    tc.expected.push_back(std::move(tok));
                }

                test.cases.push_back(std::move(tc));
            }
        }
        else
        {
            throw std::runtime_error(
                "Invalid 'input' node in test '" + test.name + "'");
        }

        cfg.tests.push_back(std::move(test));
    }

    return cfg;
}