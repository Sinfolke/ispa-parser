export module Converter.Construct;
import LangAPI;
import std;
export namespace Converter {
    class ConstructBase {
    protected:
        const LangAPI::Declarations *source;
        const char* namespace_name;

        // configuration
        bool incremental;
    public:
        ConstructBase(const LangAPI::Declarations *source, const char *namespace_name, bool incremental) : source(source), namespace_name(namespace_name), incremental(incremental) {}
        virtual ~ConstructBase() = default;
        virtual auto get_files() -> const std::vector<std::pair<std::string, std::string>>& = 0;
        virtual auto construct() -> void = 0;
    };
}