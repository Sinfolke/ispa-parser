#!/bin/bash



# This script is used to generate release-only files !!!

echo "Running script build-auto.sh means it will try to auto-define best compiler for you and apply host optimizations"
echo "If you experience problems use build.sh with manually set env vars to what you're needed"
echo

# CONFIGURATIONS
SCRIPT_DIR="scripts"
MOD_DIR="$SCRIPT_DIR/mod"
TEST_DIR="$SCRIPT_DIR/compiler-test"
COMPILER_TEST_FILE="$TEST_DIR/compiler-test.cpp"

# INCLUDES
source $SCRIPT_DIR/find_compiler.sh
source $SCRIPT_DIR/find_generator.sh 
source $SCRIPT_DIR/find_linker.sh
source $SCRIPT_DIR/os.sh          # get whether run under Windows
source $SCRIPT_DIR/cpu.sh         # get cpu vendor
source $SCRIPT_DIR/dependecies.sh # find/download required dependecies

# PARSE ARGUMENTS
source $SCRIPT_DIR/args.sh

# GET COMPILE OPTIONS
source $SCRIPT_DIR/compile-options.sh

# GET COMPILER
if [[ -z $c_compiler ]]; then
    find_c_compiler 0
fi
if [[ -z $cxx_compiler ]]; then
    find_cxx_compiler 0
fi
find_ld
# GET GENERATOR
find_generator $generator
if [[ WINDOWS ]]; then
    cmd.exe /c "./prepare_boost.bat"
fi
# configure cmake
echo "Using C compiler: $c_compiler"
echo "Using CXX compiler: $cxx_compiler"
echo "Using generator: $generator"
echo "Using linker: $ld"
echo "Using compile options: $flags"
cmake -B build -G "$generator" \
    -DCMAKE_C_COMPILER="$c_compiler" \
    -DCMAKE_CXX_COMPILER="$cxx_compiler" \
    -DCMAKE_C_FLAGS="$flags" \
    -DCMAKE_CXX_FLAGS="$flags" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PROJECT_NAME="ISC"
if [[ $? != 0 ]]; then
    echo "CMake failed. Building terminated"
    exit 1
fi
if $build_immediately; then
    ## Get generator command

    ## GET JOBS AMOUNT
    if [[ $jobs == 0 ]]; then
        if [[ $(nproc) > 1 ]]; then
            jobs=$(( $(nproc) - 1 ))
        else
            # handle single-core processors
            jobs=1
        fi
    fi

    cmake --build build -j $jobs

    ## CHECK RESULT
    if [[ $? != 0 ]]; then
        echo "Compilation failed. Building terminated"
        exit 1
    fi
    ## PACKAGE RELEASE FILES
    if [[ $package ]]; then
        # package source code into archive
        if [[ $package==*.zip ]]; then
            # windows arhive, use zip command 
            zip -r $package ./build/bin ./release-scripts/*.bat
        else
            tar -czvf $package ./build/bin ./release-scripts/*.sh
        fi

        if [[ ! $? ]]; then
            echo "Failed to create package"
            exit 1
        fi
    fi
elif $package; then
    echo "Warning: option -package ignored due option -configure"
fi