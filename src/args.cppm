export module args;
import CLI;
import dstd;
import std;
import cpuf.printf;
export struct Args {
    enum class Algorithm {
        LL, LR0, LR1, LALR, ELR
    };
    Algorithm algorithm = Algorithm::LL;
    std::string language;
    std::vector<std::string> dir;
    std::vector<std::string> files;
    // debug set to true by default in debug builds
#ifdef DEBUG
    bool debug = true;
#else
    bool debug = false;
#endif
    bool version = false;
    std::string output;
    std::unordered_set<std::string> dump;
    std::string dump_dir;
    bool dump_all = false;
    bool dump_nfa_from_rule = false;
    bool shouldDump(const std::string &s) const {
        return dump_all || dump.contains(s);
    }
    auto makeDumpPath(const std::string &s) const {
        return dump_dir + "/" + s;
    }
    void initDumpDirectory() const;

};
export Args parse_args(int argc, char** argv);