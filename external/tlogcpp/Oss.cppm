
export module Tlog.oss;
import std;
import std.compat;
import cpuf.op;

export namespace Tlog {
    class Oss {
        std::ofstream of;
        std::size_t indent_level = 0;
        // Base case: no arguments left
        inline void print_nth(int index) {
            of << "<none>";
        }

        // Recursive variadic print_nth, perfect forwarding args
        template <typename T, typename... Args>
        void print_nth(int index, T&& first, Args&&... args) {
            if (index == 0) {
                of << std::forward<T>(first);
            } else {
                print_nth(index - 1, std::forward<Args>(args)...);
            }
        }

        // Internal helper: processes the format string and outputs to the given ostream
        template <typename... Args>
        int vprintf_impl(const char* format, Args&&... args) {
            int id = 0;
            const char* start = format;
            while (*format) {
                if (*format == '{' && *(format + 1) == '}') {
                    print_nth(id++, std::forward<Args>(args)...);
                    format += 2;
                } else {
                    of << *format++;
                }
            }
            return static_cast<int>(format - start);
        }
        std::string now_to_string() {
            using namespace std::chrono;
            auto now = system_clock::now();
            std::time_t now_time_t = system_clock::to_time_t(now);
            std::tm tm = *std::localtime(&now_time_t);
            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
            return oss.str();
        }
        std::string format_str(std::string str) const {
            str.insert(0, std::string(indent_level, '\t'));
            for (std::size_t i = 0; i < str.size(); i++) {
                if (str[i] == '\n') {
                    str.insert(i, std::string(indent_level, '\t'));
                }
            }
            return str;
        }
        std::string format_str(const char* str) const {
            return format_str(std::string(str));
        }
    public:
        Oss(std::filesystem::path path, bool append) {
            std::filesystem::create_directories(path.parent_path());
            of.open(path, append ? std::ios_base::app : std::ios_base::out);
            if (!of.is_open()) {
                throw std::runtime_error("Open branch " + path.string() + "failed");
            }
            of << "[opened at " << now_to_string() << "]\n";
        }
        void close() {
            of << "[closed at " << now_to_string() << "\n]";
            of.close();
        }
        // Overload for std::string format: just forward to the const char* version
        template <typename... Args>
        int vprintf(const std::string& format, Args&&... args) {
            return vprintf_impl(format.c_str(), std::forward<Args>(args)...);
        }
        template<typename Format, typename ...Args>
        void dprint(Format format, Args&&... args) {
            auto new_f = format_str(format);
            vprintf(new_f, std::forward<Args>(args)...);
            of.flush();
        }
        template<typename Format, typename ...Args>
        void print(Format format, Args&&... args) {
            auto new_f = format_str(format);
            vprintf(new_f, std::forward<Args>(args)...);
            of << '\n';
            of.flush();
        }
        void increaseIndentLevel() {
            indent_level++;
        }
        void decreaseIndentLevel() {
            if (indent_level != 0)
                indent_level--;
        }
    };
}
