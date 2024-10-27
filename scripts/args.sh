## FUNCTIONS
show_help() {
    echo "Usage [OPTIONS] compiler flags"
    echo "First pass in options, then everything rest is compiler arguments"
    echo "Note if you pass in compiler flags the flags '-common', '-intel' and '-amd' won't affect them"
    echo "Options:"
    echo "    -help                      Show this help message"
    echo "    -common                    Generate common release files (without target-specific optimizations)"
    echo "    -configure                 Only configure cmake without building"
    echo "    -gen <generator>           Use a specific build generator (supported make, ninja and Visual Studio). Note the string must be one that you'd pass to cmake -G option"
    echo "    -compiler <compiler>       Specify the compiler to use"
    echo "    -job-no-safe-limit         By default for compilation used all jobs - 1 to avoid system crashes. Use to disable"
    echo "    -job <num>                 Specify the number of jobs to use (inaffected by -job-no-save-limit)"
    echo "    -intel                     Generate release files using Intel C++"
    echo "    -amd                       Generate release files using AMD C++"
}
has_next_arg() {
    if [[ $# -lt 2 ]]; then
        echo "Error: $1 requires a value"
        exit 1
    fi
}
to_next() {
    i=$(( i + ${#1} + 1))
    shift
}

## ARGUMENT PARSER
compiler=0
flags=0
generator=0
common=0
proc_specific=0
jobs=0
generator_cmd=0
build_immediately=true
i=0
while [[ $# -gt 0 ]]; do
    case "$1" in
        (-help)
            show_help
            exit 1
            ;;
        (-common)
            # Generate common release files
            common=1
            ;;
        (-configure)
            build_immediately=false
            ;;
        (-gen)
            has_next_arg
            c="${2:0:1}"  # Corrected line
            if [[ $c == '"' ]]; then
                begin=$(( i + ${#1} + 1 ))
                parseStr "$*" $begin generator
                countSpaces "$generator" to_shift
                shift $(( to_shift ))
                i=$(( i + ${#generator} ))  # Corrected variable increment syntax
                shift
            else
                generator="$2"
                shift  # Ensure you shift for the next argument
            fi
            ;;
        (-compiler)
            has_next_arg
            compiler="$2"
            shift  # Ensure you shift for the next argument
            ;;
        (-job-no-safe-limit)
            # disables use of one less than maximum jobs to avoid compilation crashes
            jobs=$(nproc)
            ;;
        (-job)
            has_next_arg
            jobs="$2"  # Store the argument as jobs
            shift  # Ensure you shift for the next argument
            ;;
        (-intel)
            proc_specific="intel"
            ;;
        (-amd)
            proc_specific="amd"
            ;;
        (*)
            echo "Unknown argument: $1"
            exit 1
            ;;
    esac
    shift  # Move to the next argument
done
