export module Converter.Writer;

import Converter.Indentation;
import Converter.NameManager;
import Rope.String;
import cpuf.printf;

import dstd;
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
        Rope::String data;
        std::unordered_map<std::size_t, LineData> indentation_memory;
        NameManager name_manager;
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
            auto sprintf_result = cpuf::sprintf(format, std::forward<Args>(args)...);
            data.insert(indentation_offset[line], sprintf_result.begin(), sprintf_result.end());
        }
        /*
         * Output the formatted line
         */
        template<StringType StringType, typename ...Args>
        auto writeln(std::size_t line, std::size_t indentation_offset, StringType format, Args&&... args)  -> void {
            write(line, indentation_offset, format, std::forward<Args>(args)...);
            write(line, indentation_offset, "\n");
        }
        template<typename StringType, typename ...Args>
        auto writeSymbol(const std::string &name, StringType format, Args&& ...args) {
            std::size_t begin = line;
            write(line, 0, format, std::forward<Args>(args)...);
            auto *assign_name = name_manager.getNameInRange(begin, line);
            stdu::vector<std::string> new_name;
            if (assign_name) {
                new_name = *assign_name;
            }
            new_name.push_back(name);
            name_manager.update(new_name, NameManager::NameData {begin, line});
            return new_name;
        }
        template<typename StringType, typename ...Args>
        auto writeToSymbol(const stdu::vector<std::string> &sym, StringType &format, Args&& ...args) {
            auto symbol_line = name_manager.getLineBySymbol(sym);
            auto line_before_change = line;
            write(symbol_line, 0, format, std::forward<Args>(args)...);
            name_manager.increase(sym, line - line_before_change);
        }
        /* indentation level up */
        auto levelUp() -> void {
            indentation++;
        }
        /* indentation level down */
        auto levelDown() -> void {
            indentation--;
        }
        auto nameManager() { return name_manager; }
        auto getLine() { return line; }
    };
}