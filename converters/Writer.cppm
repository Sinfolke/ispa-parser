export module Converter.Writer;

import cpuf.printf;
import std;

template<typename T>
concept StringType = std::is_same_v<std::remove_reference_t<T>, const char*> || std::is_same_v<std::remove_reference_t<T>, std::string>;

export namespace Converter {
    class Writer {
        std::size_t indentation = 0;
        std::size_t line = 0;
        std::ostringstream data;
        std::unordered_map<std::size_t, std::size_t> indentation_memory;

        auto fill_indentation_memory(const char* format, std::size_t custom_ident = 0) -> void {
            bool was_line = false;
            std::size_t current_indent = 0;

            for (; *format != '\0'; ++format) {
                unsigned char c = static_cast<unsigned char>(*format);

                if (!was_line && std::isspace(c) && c != '\n') {
                    current_indent++;
                    continue;
                }
                if (c == '\n') {
                    indentation_memory[line++] = custom_ident + current_indent;
                    current_indent = 0;
                    was_line = false;
                    continue;
                }
                was_line = true;
            }

            // Handle last line if it didn’t end with newline
            if (was_line || current_indent > 0) {
                indentation_memory[line] = custom_ident + current_indent;
            }
        }
    protected:
        /*
         * Output the formatted text
         */
        template<StringType StringType, typename ...Args>
        auto write(StringType format, Args&&... args) -> void {
            fill_indentation_memory(format);
            data << std::string(indentation, '\t') << cpuf::sprintf(format, std::forward<Args>(args)...);
        }
        template<StringType StringType, typename ...Args>
        auto write(std::size_t indentation, StringType format, Args&&... args) -> void {
            fill_indentation_memory(format, indentation);
            data << std::string(this->indentation + indentation, '\t') << cpuf::sprintf(format, std::forward<Args>(args)...);
        }
        /*
         * Output the formatted line
         */
        template<StringType StringType, typename ...Args>
        auto writeln(StringType format, Args&&... args)  -> void {
            fill_indentation_memory(format);
            write(format, std::forward<Args>(args)...) << '\n';
        }
        template<StringType StringType, typename ...Args>
        auto writeln(std::size_t indentation, StringType format, Args&&... args) -> void {
            fill_indentation_memory(format, indentation);
            write(indentation, format, std::forward<Args>(args)...) << '\n';
        }
        /* indentation level up */
        auto levelUp() -> void {
            indentation++;
        }
        /* indentation level down */
        auto levelDown() -> void {
            indentation--;
        }

    public:

    };
}
