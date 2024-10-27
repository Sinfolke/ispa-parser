#!/bin/bash

# This script is used to generate release-only files !!!
# Debugging is done using CMakePresets.json

# CONFIGURATIONS
SCRIPT_DIR="scripts"
MOD_DIR="$SCRIPT_DIR/mod"
TEST_DIR="$SCRIPT_DIR/compiler-test"
COMPILER_TEST_FILE="$TEST_DIR/compiler-test.cpp"

# INCLUDES
source $SCRIPT_DIR/find_compiler.sh
source $SCRIPT_DIR/find_generator.sh 
source $SCRIPT_DIR/os.sh          # get whether run under Windows
source $SCRIPT_DIR/cpu.sh         # get cpu vendor
source $SCRIPT_DIR/dependecies.sh # find/download required dependecies

# PARSE ARGUMENTS
source $SCRIPT_DIR/args.sh

# GET COMPILE OPTIONS
source $SCRIPT_DIR/compile-options.sh

# GET COMPILER
find_compiler $compiler

# GET GENERATOR
find_generator $generator

# configure cmake
echo "Using compiler: $compiler"
echo "Using generator: $generator"
echo "Using compile options: $flags"

cmake -B build -G "$generator" \
    -DCMAKE_CXX_COMPILER="$compiler" \
    -DCMAKE_CXX_FLAGS="$flags" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PROJECT_NAME="ISC"
if [[ $? != 0 ]]; then
    echo "CMake failed. Building terminated"
    exit 1
fi
if $build_immediately; then
    ## Get generator command
    if [[ $generator == *Makefiles* ]]; then
        generator_cmd="make"
    elif [[ $generator == Ninja ]]; then
        generator_cmd="ninja"
    elif [[ $generator == *"Visual Studio"* ]]; then
        generator_cmd="vs"
    else 
        echo "Undefined generator"
        exit 1
    fi

    ## GET JOBS AMOUNT
    if [[ $jobs == 0 ]]; then
        if [[ $(nproc) > 1 ]]; then
            jobs=$(( $(nproc) - 1 ))
        else
            # handle single-core processors
            jobs=1
        fi
    fi

    ## RUN BUILD
    if [[ $generator_cmd == "vs" ]]; then
        # generate with msbuild
        cd build
        msbuild ISC.sln
    else
        # generate with a normal generator
        $generator_cmd -j$jobs
    fi

    ## CHECK RESULT
    if [[ $? != 0 ]]; then
        echo "Compilation failed. Building terminated"
        exit 1
    fi
fi