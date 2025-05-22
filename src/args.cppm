export module args;
import CLI;
import std;
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
};
export Args parse_args(int argc, char** argv);