test_compiler_exists() {
    # ARGS
    comp=$1

    if [[ $compiler == 0 ]]; then
        "$comp" --version > /dev/null 2>&1
        if [[ $? -eq 0 ]]; then
            compiler="$1"
        fi
    fi
}
check_is_llvm_based() {
    if [[ $compiler == "g++" ]]; then
        llvm_based=(false)
    else
        llvm_based=(true)
    fi
}
test_compiler() {
    # ARGS
    local compiler=$1

    output=("$compiler $TEST_PATH > /dev/null 2>&1 ")
    if [[ $? != 0 ]]; then
    echo "Compiler $compiler failed to compile test file"
    echo "Output: "
    echo "$output"
    exit 1
    fi
}

find_compiler() {
    # arguments
    local name=$1

    if [[ $compiler != 0 ]]; then
        local comp=$compiler
        compiler=0 
        test_compiler_exists $comp
        if [[ $compiler == 0 ]]; then
            echo "Compiler $compiler is not found"
            exit 1
        fi
    else
        # perform check for processor-specific compiler
        if [[ -z $intel_cpu ]]; then
            if $intel_cpu; then
                echo "Searching icpx"
                test_compiler_exists icpx
            else
                test_compiler_exists amdclang++
            fi
        else
            # unknown target cpu, perform linear check
            test_compiler_exists icpx
            test_compiler_exists amdclang++
        fi

        test_compiler_exists clang++
        test_compiler_exists g++
        if [[ $compiler == 0 ]]; then
            echo "No suitable C++ compiler found"
            exit 1
        fi
    fi
    test_compiler $compiler
}
