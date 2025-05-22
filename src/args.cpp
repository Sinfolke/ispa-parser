module;
module args;
import logging;
import cpuf.printf;
import CLI;
import std;
Args parse_args(int argc, char** argv) {
    Args args;
    CLI::App app{"Ispa parser"};
    std::string algorithm;
    app.add_flag("-v,--version",  args.version, "Print version");
    app.add_option("-d,--dir", args.dir, "Directory where input modules files are located");
    app.add_option("-o", args.output, "Directory where to output generated files");
    app.add_option("-l,--lang", args.language, "Set build language")->required();
    app.add_option("-a,--algorithm", algorithm, "Set one of algorithms: LL, LR(0), LR(1), LALR, LR(*)");
    app.add_flag("--debug", args.debug, "Output debug logs of program");

    app.parse(argc, argv);

    // Map algorithm string to enum
    if (!algorithm.empty()) {
        if (algorithm == "LL") args.algorithm = Args::Algorithm::LL;
        else if (algorithm == "LR(0)" || algorithm == "LR0") args.algorithm = Args::Algorithm::LR0;
        else if (algorithm == "LR(1)" || algorithm == "LR1") args.algorithm = Args::Algorithm::LR1;
        else if (algorithm == "LALR") args.algorithm = Args::Algorithm::LALR;
        else if (algorithm == "LR(*)" || algorithm == "LR*") args.algorithm = Args::Algorithm::ELR;
        else throw Error("Unknown algorithm {}", algorithm);
    }

    return args;
}
