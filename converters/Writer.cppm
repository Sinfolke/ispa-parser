export module Converter.Writer;

import Converter.Indentation;
import eosio.rope;
import cpuf.printf;
import std;

template<typename T>
concept StringType = std::is_same_v<std::remove_reference_t<T>, const char*> || std::is_same_v<std::remove_reference_t<T>, std::string>;

export namespace Converter {
    struct LineData {
        std::size_t position;
        Indentation indentation;
    };
    class Writer {
        std::size_t indentation = 0;
        std::size_t line = 0;
        eosio::rope data;
        std::unordered_map<std::size_t, LineData> indentation_memory;

        auto fill_indentation_memory(std::size_t position, std::size_t line, const char* format, Indentation indent) -> void {
            bool was_line = false;
            Indentation current_indent;
            for (; *format != '\0'; ++format) {
                unsigned char c = static_cast<unsigned char>(*format);

                if (!was_line && c != '\n') {
                    indent += c;
                    continue;
                }
                if (c == '\n') {
                    if (indentation_memory.contains(line)) {
                        std::optional<std::size_t> highest_line;
                        auto value = indent + current_indent;
                        for (auto &[key, map_value] : indentation_memory) {
                            if (key < line)
                                continue;
                            std::swap(value, map_value);
                            highest_line = key;
                        }
                        indentation_memory[highest_line.value_or(0)] = {position, value};
                    } else {
                        indentation_memory[line] = {position, indent + current_indent};
                    }
                    current_indent.clear();
                    was_line = false;
                    this->line++;

                    continue;
                }
                was_line = true;
            }

            // Handle last line if it didn’t end with newline
            if (was_line || !current_indent.empty()) {
                indentation_memory[line] = current_indent + indent;
            }
        }
    public:
        /*
         * Output the formatted text
         */
        template<StringType StringType, typename ...Args>
        auto write(std::size_t line, std::size_t indentation_offset, StringType format, Args&&... args) -> void {
            fill_indentation_memory(format);
            data.append()
            auto current_pos = data.tellp();
            data.seekp(indentation_memory[line].position);
            data << std::string(indentation + indentation_offset, '\t') << cpuf::sprintf(format, std::forward<Args>(args)...);
            data.seekp(current_pos);
        }
        /*
         * Output the formatted line
         */
        template<StringType StringType, typename ...Args>
        auto writeln(std::size_t line, std::size_t indentation_offset, StringType format, Args&&... args)  -> void {
            write(line, indentation_offset, format, std::forward<Args>(args)...);
            auto current_pos = data.tellp();
            data.seekp(indentation_memory[line].position);
            data << '\n';
            data.seekp(current_pos);        }
        /* indentation level up */
        auto levelUp() -> void {
            indentation++;
        }
        /* indentation level down */
        auto levelDown() -> void {
            indentation--;
        }

    };
}
