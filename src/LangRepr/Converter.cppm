export module LangRepr.Converter;

import LangRepr.Holder;
import Converter.Construct;
import LangAPI;
import cpuf.dlib;
import std;

export namespace LangRepr {
    class Converter {
        dlib converter_lib;
        const Holder &holder;
        std::string namespace_name;
        bool incremental;
        std::vector<std::pair<std::string, std::string>> files;
        std::string lang;
        ::Converter::ConstructBase *builder;
    public:
        Converter(const Holder &holder, const std::string &lang, const std::string &namespace_name, bool incremental)
            : converter_lib("libispa-converter-" + lang),
              holder(holder), namespace_name(namespace_name), incremental(incremental), lang(lang) {}

        auto init() -> void {
            auto construct = converter_lib.loadfun<::Converter::ConstructBase*, const LangAPI::Declarations *, const char*, bool>(lang + "_construct");
            builder = construct(&holder.get(), namespace_name.c_str(), incremental);
        }
        auto construct() -> void {
            builder->construct();
            files = builder->get_files();
            for (auto& [name, source] : files) {
                if (!name.ends_with(".h")) continue;
                std::ostringstream headers;
                for (const auto& header : holder.getIncludes()) {
                    headers << "#include ";
                    if (header.starts_with('<') && header.ends_with('>')) headers << header;
                    else headers << std::quoted(header);
                    headers << '\n';
                }
                source.insert(source.starts_with("#pragma once\n") ? 13 : 0, headers.str());
            }
        }
        [[nodiscard]] auto get() const -> const std::vector<std::pair<std::string, std::string>>& {
            return files;
        }
        ~Converter() {
            converter_lib.loadfun<void, ::Converter::ConstructBase*>(lang + "_construct_finish")(builder);
        }
    };
}
