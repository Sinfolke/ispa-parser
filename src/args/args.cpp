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

void Args::init(int argc, char** argv) {
#ifdef _WIN32
    // windows does also provide the executable execute name/path
    argc--;
    argv++;
#endif
    this->argc = argc;
    this->argv = argv;

}
void Args::on(const char* prefix, const std::function<void(Arg&)>& func) 
{
    listeners[prefix] = func;
}
void Args::parse() {
        Arg currentArg;
        for (int i = 1; i < argc; ++i) { // Start from 1 to skip program name
            const char* current = argv[i];
            if (current[0] == '-') { // Prefix found
                if (!currentArg.empty()) {
                    args.push_back(currentArg);
                    currentArg.clear();
                }
                currentArg.prefix = current[1] == '-' ? &current[2] : &current[1]; // Handle `--` or `-`
            } else {
                if (currentArg.empty()) {
                    _unnamed.push_back(current);
                } else {
                    currentArg.values.push_back(current);
                }
            }
        }
        if (!currentArg.empty()) {
            args.push_back(currentArg);
        }
        invokeListeners();
    }
ND bool Args::has(const char* prefix)
{
    for (auto& arg : args) {
        if (!strcmp(arg.prefix, prefix)) {
            return true;
        }
    }
    return false;
}
ND Arg Args::get(const char* prefix)
{
    for (auto& arg : args) {
        if (!strcmp(arg.prefix, prefix)) {
            return arg;
        }
    }
    return {};
}
ND Arg& Args::operator[](const int& id) {
    if (args.size() < id)
        throw std::out_of_range("Args::operator[]: out of range");
    return args[id];
}
ND std::vector<const char*> Args::unnamed(void) {
    return _unnamed;
};
void Args::invokeListeners()
{
    for (auto& arg : args) {
        auto it = listeners.find(arg.prefix);
        if (it != listeners.end()) {
            it->second(arg);
        }
    }
}