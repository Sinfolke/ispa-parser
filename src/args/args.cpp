#include <args/args.h>
ND bool Arg::empty() const {
    return prefix == nullptr;
}
ND bool Arg::isBool() const {
    return values.empty();
}
void Arg::clear() {
    prefix = nullptr;
    values.clear();
}
ND const char* Arg::first() const {
    return values[0];
}
ND const char* Arg::_0() const {
    return values[0];
}
ND const char* Arg::last() const {
    return values.back();
}
ND const char* Arg::operator[](const int v) const {
    return values[v];
}

void Args::init(int argc, const char** argv) {
#ifdef _WIN32
    // windows does also provide the executable execute name/path
    argc--;
    argv++;
#endif
    this->argc = argc;
    this->argv = argv;

}
void Args::on(const char* prefix, listenerf func) {
    listeners[prefix] = func;
}
void Args::onParsed(const char* prefix, listenerf func) {
    listeners_parsed[prefix] = func;
}
void Args::onUnparsed(const char* prefix, listenerf func) {
    listeners_unparsed[prefix] = func;
}
void Args::parse() {
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
                    } else if (command == listener_cmd::STOP_PARSING) {
                        break;
                    } else if (command == listener_cmd::CONTINUE_PARSING_AT) {
                        if (command == listener_cmd::ABORT) {
                            throw Error("listener aborted");
                        }
                    }
                }
            }
        } else if (argv[i][0] == '!') {

            if (variadic) {
                // close variadic
                args.push_back(argument);
                variadic = false;
                if (argv[i][1]) {
                    throw UWarning("Ignoring %d symbols here: %s", strlen(argv[i]), argv[i]);
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
ND Arg& Args::operator[](const int& id) {
    if (args.size() < id)
        throw std::out_of_range("Args::operator[]: out of range");
    return args[id];
}
ND std::vector<const char*> Args::unnamed(void) {
    return _unnamed;
};