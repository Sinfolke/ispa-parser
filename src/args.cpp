module;
module args;
import logging;
import cpuf.printf;
import CLI;
import std;

Args parse_args(int argc, char** argv) {
    Args args;
    CLI::App app{"ISPA Parser Generator"};
    app.allow_extras(false);
    std::string algorithm;
    app.add_flag("-v,--version",  args.version, "Print version");
    app.add_option("-d,--dir", args.dir, "Directory where input modules files are located")->expected(1);
    app.add_option("-o", args.output, "Directory where to output generated files");
    app.add_option("-l,--lang", args.language, "Set build language")->required();
    app.add_option("-a,--algorithm", algorithm, "Set one of algorithms: LL, LR(0), LR(1), LALR, LR(*)");
    app.add_option("--debug", args.debug, "Output debug logs into Logs directory");
    app.add_option("--dump", args.dump, "Dump certain parts of program")->expected(0, 1);
    app.add_option("--ddall", args.dump_all, "Dump everything from program")->expected(0);
    app.add_option("--dd", args.dump_dir, "Directory where to dump");
    try {
        app.parse(argc, argv);
    } catch (CLI::CallForAllHelp&) {
        std::cout << app.help("") << std::endl;
        std::exit(0);
    } catch (CLI::CallForHelp &help) {
        std::cout << app.help(help.get_name()) << std::endl;
        std::exit(0);
    } catch (CLI::ArgumentMismatch &missmatch) {
        std::cerr << "Improperly passed argument " << missmatch.what() << std::endl;
        std::exit(1);
    } catch (CLI::RequiredError &required) {
        std::cerr << "Argument " << required.what() << std::endl;
        std::exit(1);
    } catch (CLI::ParseError& e) {
        std::cerr << "Parsing error: " << e.what() << std::endl;
        std::exit(1);
    }

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

void Args::initDumpDirectory() const {
    if (!dump_all || !dump.empty())
        return;
    if (!std::filesystem::exists(dump_dir)) {
        std::filesystem::create_directories(dump_dir);
    } else {
        std::filesystem::remove_all(dump_dir);
    }
}
