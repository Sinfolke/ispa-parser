
export module Tlog.Logger;
import Tlog.oss;
import cpuf.op;
import std;
import std.compat;
export namespace Tlog {
    struct Branch_data {
        std::filesystem::path path;
        oss oss;
    };
    class Logger {
        std::filesystem::path base_path;
        std::unordered_map<std::string, Branch_data> branches;
        std::vector<Branch_data> branches_stack;
        std::string file;
        size_t line;
        std::string getFormattedPath(std::string path) {
            std::string final_path;
            for (auto it = path.begin(); it != path.end(); ++it) {
                if (*it == '$' && std::next(it) != path.end() && *(std::next(it)) == '{') {
                    // skip $ and {
                    it += 2;
                    std::string branch_name;
                    while (it != path.end() && *it != '}') {
                        branch_name += *it;
                        ++it;
                    }
                    if (it == path.end()) {
                        throw std::runtime_error("Unclosed ${ in path");
                    }
                    if (branch_name.empty()) {
                        throw std::runtime_error("Empty branch name in ${}");
                    }
                    if (branches.find(branch_name) == branches.end()) {
                        throw std::runtime_error("Referenced branch '" + branch_name + "' does not exist");
                    }
                    // Append root_directory as string
                    auto &data = branches.at(branch_name);
                    final_path += data.path.root_directory().string();
                    // After '}', continue normal processing, it will ++ in for loop
                } else {
                    final_path += *it;
                }
            }
            final_path.insert(0, base_path.string() + "/");
            return final_path;
        }
        std::string get_relative_source_path(const std::string full_path) {
            namespace fs = std::filesystem;

            static const fs::path source_root = __SOURCE_ROOT__;

            fs::path full = fs::path(full_path).lexically_normal();

            // If full path starts with source_root, remove the prefix
            if (std::mismatch(source_root.begin(), source_root.end(), full.begin()).first == source_root.end()) {
                return fs::relative(full, source_root).string();
            } else {
                return full.string(); // fallback: not under source root
            }
        }
    public:
        explicit Logger(const std::filesystem::path path) : base_path(path) {}
        Logger() : base_path("./") {}

        void createBranch(const std::string& name, const std::string& path) {
            auto final_path = getFormattedPath(name);
            branches.insert_or_assign(name, Branch_data{final_path, oss(final_path)});
        }
        void pushBranch(std::string path) {
            auto final_path = getFormattedPath(path);
            branches_stack.emplace_back(final_path, oss(final_path));
        }
        void popBranch() {
            if (branches_stack.empty())
                throw std::runtime_error("Cannot pop branch, stack is empty");
            branches_stack.pop_back();
        }
        void closeBranch(std::string b) {
            branches.at(b).oss.close();
        }
        template<typename Format, typename... Args>
        void log(Format str, Args&&... args) {
            //branches_stack.back().oss.vprintf("[{}, {}] ", file, line);
            branches_stack.back().oss.print(str, std::forward<Args>(args)...);
        }
        template<typename Format, typename ...Args>
        void dlog(Format str, Args ...args) {
            //branches_stack.back().oss.vprintf("[{}, {}] ", file, line);
            branches_stack.back().oss.dprint(str, std::forward<Args>(args)...);
        }
        template<typename Format, typename ...Args>
        void logToBranch(std::string name, Format str, Args ...args) {
            branches[name].oss.print(str, args...);
        }
        template<typename Format, typename ...Args>
        void dlogToBranch(std::string name, Format str, Args ...args) {
            branches[name].oss.dprint(str, args...);
        }
        void increaseIndentLevel() {
            branches_stack.back().oss.increaseIndentLevel();
        }
        void increaseIndentLevel(std::string branch) {
            branches.at(branch).oss.increaseIndentLevel();
        }
        void decreaseIndentLevel() {
            branches_stack.back().oss.decreaseIndentLevel();
        }
        void decreaseIndentLevel(std::string branch) {
            branches.at(branch).oss.decreaseIndentLevel();
        }
        void record_location(std::source_location loc = std::source_location::current()) {
            file = get_relative_source_path(loc.file_name());
            line = loc.line();
        }
        void set_location(std::string file, size_t line) {
            this->file = get_relative_source_path(file);
            this->line = line;
        }
    };
    class Branch {
        Logger *logger;
    public:
        Branch(Logger &logger, std::string path, std::source_location loc = std::source_location::current()) : logger(&logger) {
            logger.set_location(loc.file_name(), loc.line());
            this->logger->pushBranch(path);
        }
        ~Branch() {
            logger->popBranch();
        }
        template<typename ...Args>
        void print(const char* message, Args ...args) {
            logger->log(message, args...);
        }
        template<typename ...Args>
        void print(std::string message, Args ...args) {
            logger->log(message, args...);
        }
    };
};
