module;
#include <CLI11.hpp> // Now this is part of the module interface
export module CLI;

export namespace CLI {
    using CLI::App;
    inline auto parse(App& app, int argc, char** argv) {
        CLI11_PARSE(app, argc, argv);
        return 0;
    }
}
