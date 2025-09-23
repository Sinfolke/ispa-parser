
export module constants;
import LLIR.API;
import std;

export namespace constants {
    enum class Language {
        Cpp
    };
    enum class StdlibExports {
        Rule, Token, Node
    };
    const std::vector<std::string> whitespace = {"__WHITESPACE"};
    const std::vector<char> whitespace_chars = {'\t', '\n', '\r', '\v', '\f', ' '};
    constexpr const char* stdlib_path(Language language) {
        switch (language) {
            default:
                return "::ISPA_STD";
        }
    }
    constexpr auto stdlib_get_type(Language language, StdlibExports what_path_to_get) -> LLIR::Type  {
        switch (language) {
            default:
                return LLIR::Type {
                    LLIR::Symbol {
                        constants::stdlib_path(language), "Node"
                    },
                    "Rules"
            };
        }
    }
}
