
show_help() {
    echo "Usage [OPTIONS] compiler flags"
    echo "First pass in options, then everything rest is compiler arguments"
    echo "Note if you pass in compiler flags the flags '-common', '-intel' and '-amd' won't affect them"
    echo "Options:"
    echo "    -help                      Show this help message"
    echo "    -common                    Generate common release files (without target-specific optimizations)"
    echo "    -gen <generator>           Use a specific build generator (supported make, ninja and Visual Studio). Note the string must be one that you'd pass to cmake -G option"
    echo "    -compiler <compiler>       Specify the compiler to use"
    echo "    -job-no-safe-limit         By default for compilation used all jobs - 1 to avoid system crashes. Use to disable"
    echo "    -job <num>                 Specify the number of jobs to use (inaffected by -job-no-save-limit)"
    echo "    -intel                     Generate release files using Intel C++"
    echo "    -amd                       Generate release files using AMD C++"
}