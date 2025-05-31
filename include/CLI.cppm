module;
#include <CLI11.hpp> // Now this is part of the module interface
export module CLI;

export namespace CLI {
    using namespace ::CLI;
    using CLI::App;
    using CLI::ParseError;
    using CLI::CallForAllHelp;
    using CLI::CallForHelp;
    using CLI::CallForVersion;
    using CLI::ArgumentMismatch;
    using CLI::RequiredError;
    using CLI::Option;
    using CLI::OptionBase;
    inline auto parse(App& app, int argc, char** argv) {
        CLI11_PARSE(app, argc, argv);
        return 0;
    }
}
