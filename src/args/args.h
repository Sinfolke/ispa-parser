#include <unordered_map>
#include <stdexcept>
class Arg;
enum class listener_cmd {
    SUCCESS = 0,
    STOP_PARSING,
    CONTINUE_PARSING_AT,
    CONTINUE_PARSING_AT_ID,
    ABORT,
};
struct listener_return_t {
    listener_cmd command;
    const char* arg1;
};

typedef listener_return_t (*listenerf)(const Arg& arg);
class Arg {
    public:
        const char* prefix;
        std::vector<const char*> values;
        ND bool empty() const {
            return prefix == nullptr;
        }
        ND bool isBool() const {
            return values.empty();
        }
        void clear() {
            prefix = nullptr;
            values.clear();
        }
        ND const char* first() const {
            return values[0];
        }
        ND const char* _0() const {
            return values[0];
        }
        ND const char* last() const {
            return values.back();
        }
        ND const char* operator[](const int v) const {
            return values[v];
        }

};
class Args {
    private:
        int argc;
        const char** argv;
        std::vector<Arg> args;
        std::vector<const char*> _unnamed;
        std::unordered_map<const char*, listenerf> listeners;
        std::unordered_map<const char*, listenerf> listeners_parsed;
        std::unordered_map<const char*, listenerf> listeners_unparsed;
    public:
        Args(int argc, const char** argv) : argc(argc), argv(argv) {}
        /**
         * @brief Provide the input argc and argv
         * 
         * @param argc 
         * @param argv 
         */
        void init(int argc, const char** argv) {
#ifdef _WIN32
            // windows does also provide the executable execute name/path
            argc--;
            argv++;
#endif
            this->argc = argc - 1;
            this->argv = argv + 1;

        }
        void on(const char* prefix, listenerf func) {
            listeners[prefix] = func;
        }
        void onParsed(const char* prefix, listenerf func) {
            listeners_parsed[prefix] = func;
        }
        void onUnparsed(const char* prefix, listenerf func) {
            listeners_unparsed[prefix] = func;
        }
        void parse() {
            std::vector<Arg> empty_args;
            Arg argument;
            bool variadic = false;
            const char* continue_arg = NULL;
            for (int i = 0; i < argc; ++i) {
                if (argv[i][0] == '-') {
                    if (variadic) {
                        argument.values.push_back(argv[i]);
                        continue;
                    }
                    if (!argument.empty()) {
                        // flush the argument
                        args.push_back(argument);
                    }
                    argument.clear();
                    argument.prefix = &argv[i][1];
                    if (!listeners.empty()) {
                        auto it = listeners.find(argument.prefix);
                        if (it!= listeners.end()) {
                            listener_return_t result = it->second(argument);
                            auto command = result.command;
                            if (command == listener_cmd::SUCCESS) { // parsed successfully
                                continue; // listener is success
                            } elif (command == listener_cmd::STOP_PARSING) {
                                break;
                            } elif (command == listener_cmd::CONTINUE_PARSING_AT) {
                                if (command.arg == NULL) {
                                    runterr("");
                                }
                            }
                        }
                    }
                } elif (argv[i][0] == '!') {

                    if (variadic) {
                        // close variadic
                        args.push_back(argument);
                        variadic = false;
                        if (argv[i][1]) {
                            user::warning("Ignoring %d symbols here: %s", strlen(argv[i]), argv[i]);
                        }
                    } else {
                        // open variadic
                        variadic = true;
                        if (argv[i][1]) {
                            argument.values.push_back(argv[i]);
                        }
                    }
                } else {
                    if (argument.empty())
                       _unnamed.push_back(argv[i]);
                    else
                        argument.values.push_back(argv[i]);
                }
            }
        }
        ND Arg& operator[](const int& id) {
            if (args.size() < id)
                throw std::out_of_range("Args::operator[]: out of range");
            return args[id];
        }
        ND std::vector<const char*> unnamed(void) {
            return _unnamed;
        };
}