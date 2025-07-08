module Dump;
import std;


void Dump::Dump::initDumpDirectory() const {
    if (!args->dump_all && args->dump.empty() && !args->dump_nfa_from_rule)
        return;
    if (std::filesystem::exists(args->dump_dir))
        std::filesystem::remove_all(args->dump_dir);

    std::filesystem::create_directories(args->dump_dir);
}
Dump dumper;