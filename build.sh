#!/bin/bash

# This script is used to generate release-only files

# CONFIGURATIONS
TEST_DIR="build-agent"
TEST_PATH="$TEST_DIR/compiler-test.cpp"

# ARGUMENT PARSER
compiler=0
flags=0
generator=0
common=0
proc_specific=0
jobs=0
generator_cmd=0

# get whether it is windows
#./build-agent/os.sh

show_help() {
    echo "Usage [OPTIONS] compiler flags"
    echo "First pass in options, then everything rest is compiler arguments"
    echo "Note if you pass in compiler flags the flags '-common', '-intel' and '-amd' won't affect them"
    echo "Options:"
    echo "    -help                      Show this help message"
    echo "    -common                    Generate common release files (without target-specific optimizations)"
    echo "    -gen <generator>           Use a specific build generator (supported make, ninja and Visual Studio). Note the string must be one that you'd pass to cmake -G option"
    echo "    -compiler <compiler>       Specify the compiler to use"
    echo "    -job-no-save-limit         By default for compilation used all jobs - 1 to avoid system crashes. Use to disable"
    echo "    -job <num>                 Specify the number of jobs to use (inaffected by -job-no-save-limit)"
    echo "    -intel                     Generate release files using Intel C++"
    echo "    -amd                       Generate release files using AMD C++"
}
while [[ $# -gt 0 ]]; do
    case "$1" in
        -help)
            show_help
            exit 1
            ;;
        -common)
            # Generate common release files
            common=1
            ;;
        -gen)
            has_next_arg
            if [[ $2 == "Visual"]]; then
                # capture visual studio generator with multiple spaces
                generator = "$2 $3 $4 $5"
                shift 4
            else
                generator="$2"
                shift
            fi
            ;;
        -compiler)
            has_next_arg
            compiler="$2"
            shift
            ;;
        -job-no-save-limit)
            # disables use of one less than maximum jobs to avoid compilation crashes
            # sometimes being needed
            jobs=$(nproc)
        -job)
            has_next_arg
            jobs=$1
        -intel)
            proc_specific="intel"
            ;;
        -amd)
            proc_specific="amd"
            ;;
        *)
            echo "Unknown argument: $1"
            exit 1
            ;;
    esac
    shift  # Move to the next argument
done
if [[ $compiler == 0 ]]; then 
    if [[ $proc_specific == "intel" ]];
        compiler=icpx
    elif [[ $proc_specific == "amd" ]];
        compiler=amdclang++
    else
        find_compiler $compiler compiler
    fi
fi
if [[ $# -lt 2 ]]; then
    flags="$*"
else
    # set to default
    if [[ $proc_specific != 0 ]]; then
        if [[ "$flags" != 0 ]]; then
            if [[ !$common ]]; then
                if [[ $proc_specific == "intel" ]]; then
                    flags= "-O2 -xHost -mtune=native -flto -s"
                else
                    # amd uses same set of flags as clang
                    flags="-O2 -march=native -mtune=native -flto -s"
                fi
            else
                # tune as a common executable
                flags="-O2 -flto -s"
            fi
        fi
    else
        if [[ $flags == 0 ]]; then
            flags="-O2 -flto -s"
            if [[ !$common ]]; then
                flags="$flags -march=native -mtune=native"
            fi
        fi
    fi
fi
if [[ $generator == *Makefiles* ]]; then
    generator_cmd="make"
elif [[ $generator == Ninja ]]; then
    generator_cmd="ninja"
elif [[ $generator == *Visual Studio* ]]; then
    generator_cmd="vs"
fi
if [[ $jobs == 0 ]]; then
    # handle single-core processors
    if [[ $(nproc) > 1 ]]; then
        jobs=$(( $(nproc) - 1 ))
    else
        jobs=1
    fi
fi


# everything is ready to be build

cmake -B build -G $generator \
    -DCMAKE_CXX_COMPILER=$compiler \
    -DCMAKE_CXX_FLAGS=$flags \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PROJECT_NAME="ISC"
if [[ $? != 0 ]]; then
    echo "CMake failed. Building terminated"
fi
if [[ $generator_cmd == "vs"]]; then
    # generate with msbuild
    cd build
    msbuild ISC.sln
else
    # generate with a normal generator
    $generator_cmd -j$jobs
fi
has_next_arg() {
    if [[ $# -lt 2 ]]; then
        echo "Error: $1 requires a value"
        exit 1
    fi
}
find_compiler(compiler handler) {
    local comp=0
    if [[ $compiler != 0 ]]; then
        $compiler > /dev/null 2>&1
        if [[ $? != 0 ]]; then
            echo "Compiler $compiler is not found"
            exit 1
        fi
        comp=$compiler
    else
        if [[ $proc_specific == "intel" ]]; then
            test_compiler_exists icpx comp
        elif [[ $proc_specific == "amd" ]]; then
            test_compiler_exists amdclang++ comp
        fi
        test_compiler_exists clang++ comp
        test_compiler_exists g++     comp
        if [[ $comp == 0 ]]; then
            echo "No suitable C++ compiler found"
            exit 1
        fi
    fi
    test_compiler $comp
    $handler=$comp
}
test_compiler_exists(compiler, handler) {
    if [[ "$handler" == 0]]; then
        $compiler > /dev/null 2>&1
        if [[ $? == 0 ]]; $handler="$compiler"
    fi
}

test_compiler(compiler) {
    output=($compiler $TEST_PATH > /dev/null 2>&1 )
    if [[ $? != 0]]; then
    echo "Compiler $compiler failed to compile test file"
    echo "Output: "
    echo "$output"
    exit 1
    fi
}