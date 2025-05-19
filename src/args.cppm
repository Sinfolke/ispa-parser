module;
import std;
export module args;
export class Arg {
    public:
    bool isBool = false;
    std::vector<std::string> values;
    bool empty() const;
    void clear();
    Arg(bool isBool, const std::vector<std::string> &values) : isBool(isBool), values(values) {}
    Arg(bool isBool) : isBool(isBool) {}
    Arg() {}
    const std::string& first() const;
    const std::string& _0() const;
    const std::string& last() const;
    const std::string& operator[](int v) const;
};

export class Args {
private:
    int argc;
    char** argv;
    std::unordered_map<std::string, Arg> args;
    std::vector<std::string> _unnamed;
public:
    Args(int argc, char** argv) : argc(argc), argv(argv) {}
    void init(int argc, char** argv);
    auto has(const std::string& prefix) -> bool;
    auto get(const std::string& prefix) -> Arg&;
    void parse();
    auto begin() -> std::unordered_map<std::string, Arg>::iterator;
    auto end() -> std::unordered_map<std::string, Arg>::iterator;

    Arg& operator[](const std::string& id);
    std::vector<std::string> unnamed();
};
