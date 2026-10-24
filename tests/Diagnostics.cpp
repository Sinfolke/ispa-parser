#include <gtest/gtest.h>
import std;
import ISPA.Diagnostics;

using namespace ISPA::Diagnostics;

TEST(Diagnostics, SyntaxColorsAndSeverityMarkersStaySeparate) {
    Reporter reporter;
    reporter.source("example.isc", "module Demo;\nrule: 'a' BAD;\nnext: [a-z];\n");
    reporter.error("E1", "bad token", {"example.isc", 23, 3});
    reporter.warning("W1", "check string", {"example.isc", 19, 3});
    reporter.info("N1", "check class", {"example.isc", 34, 5});

    std::ostringstream output;
    reporter.print(output, ColorPolicy::Always);
    const auto text = output.str();
    EXPECT_NE(text.find("\033[35mmodule\033[0m"), std::string::npos);
    EXPECT_NE(text.find("\033[32m'a'\033[0m"), std::string::npos);
    EXPECT_NE(text.find("\033[32m[a-z]\033[0m"), std::string::npos);
    EXPECT_NE(text.find("\033[32m'a'\033[0m BAD"), std::string::npos);
    EXPECT_EQ(text.find("\033[1;31mBAD"), std::string::npos);
    EXPECT_NE(text.find("\033[1;31m^^^\033[0m"), std::string::npos);
    EXPECT_NE(text.find("\033[1;33m^^^\033[0m"), std::string::npos);
    EXPECT_NE(text.find("\033[1;34m^^^^^\033[0m"), std::string::npos);
}

TEST(Diagnostics, PlainOutputHasOnlyTheReportedRangeMarked) {
    Reporter reporter;
    reporter.source("example.isc", "rule:\tGOOD BAD;\n");
    reporter.error("E1", "bad token", {"example.isc", 11, 3});
    std::ostringstream output;
    reporter.print(output, ColorPolicy::Never);
    const auto text = output.str();
    EXPECT_EQ(text.find('\033'), std::string::npos);
    EXPECT_NE(text.find(" 1 | rule:   GOOD BAD;\n   |              ^^^\n"), std::string::npos);
}
