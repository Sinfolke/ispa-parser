module args;
import logging;
import std;
bool Arg::empty() const {
    return values.empty() && !isBool;
}
const std::string& Arg::first() const {
    return values[0];
}
const std::string& Arg::_0() const {
    return values[0];
}
const std::string& Arg::last() const {
    return values.back();
}
const std::string& Arg::operator[](int v) const {
    return values[v];
}
auto Args::begin() -> std::unordered_map<std::string, Arg>::iterator {
    return args.begin();
}
auto Args::end() -> std::unordered_map<std::string, Arg>::iterator {
    return args.end();
}
void Args::init(int argc, char** argv) {
#ifdef _WIN32
    argc--;
    argv++;
#endif
    this->argc = argc;
    this->argv = argv;
}

void Args::parse() {
    if (!args.empty())
        throw Error("Already parsed arguments");
    _unnamed.clear();

    std::string currentPrefix;
    for (int i = 1; i < argc; ++i) {
        std::string current(argv[i]);

        if (!current.empty() && current[0] == '-') {
            // It's a new named argument
            if (current.size() > 1 && current[1] == '-') {
                currentPrefix = current.substr(2);
            } else {
                currentPrefix = current.substr(1);
            }

            // Look ahead for a value
            if ((i + 1) < argc) {
                std::string next(argv[i + 1]);
                if (!next.empty() && next[0] != '-') {
                    if (next.front() == '"' && next.back() == '"' && next.length() > 1) {
                        next = next.substr(1, next.length() - 2);
                    }
                    args[currentPrefix].values.push_back(next);
                    ++i; // Consume the value
                } else {
                    args[currentPrefix].isBool = true; // Register a bool-style argument
                }
            } else {
                args[currentPrefix].isBool = true; // Register a bool-style argument
            }

        } else {
            // This is an unnamed value
            _unnamed.push_back(current);
        }
    }
}

bool Args::has(const std::string& prefix) {
    return args.count(prefix);
}

Arg &Args::get(const std::string& prefix) {
    auto f = args.find(prefix);
    
    return args[prefix];
}

Arg &Args::operator[](const std::string& prefix) {
    return args[prefix];
}

std::vector<std::string> Args::unnamed() {
    return _unnamed;
}
