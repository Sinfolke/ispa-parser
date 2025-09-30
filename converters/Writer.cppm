export module Converter.Writer;

import Rope.String;
import cpuf.printf;

import dstd;
import std;

template<typename T>
concept StringType =
    std::is_same_v<std::decay_t<T>, const char*> ||
    std::is_same_v<std::remove_cvref_t<T>, std::string> ||
    (std::is_array_v<std::remove_reference_t<T>> &&
     std::is_same_v<std::remove_cv_t<std::remove_extent_t<std::remove_reference_t<T>>>, char>);

export namespace Converter {
    class Writer {
        std::string output;
        std::size_t indentation = 0;
    public:
        template<StringType String, typename ...Args>
        auto write(const String &str, Args&&... args) -> void {
            output += std::string(indentation, '\t');
            output += cpuf::sprintf(str, std::forward<Args>(args)...);
        }
        template<StringType String, typename ...Args>
        auto writeln(const String &str, Args&&... args) -> void {
            output += std::string(indentation, '\t');
            output += cpuf::sprintf(str, std::forward<Args>(args)...);
            output += '\n';
        }
        template<StringType String, typename ...Args>
        auto dwrite(const String &str, Args&&... args) -> void {
            output += cpuf::sprintf(str, std::forward<Args>(args)...);
        }
        template<StringType String, typename ...Args>
        auto dwriteln(const String &str, Args&&... args) -> void {
            output += cpuf::sprintf(str, std::forward<Args>(args)...);
            output += '\n';
        }
        auto pop_back() -> void { output.pop_back(); }
        auto increaseIndentation() -> void { ++indentation; }
        auto decreaseIndentation() -> void { indentation > 0 ? --indentation : 0; }
        auto& get() { return output; }
    };
}