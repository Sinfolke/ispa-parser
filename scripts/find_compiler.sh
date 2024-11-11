test_compiler_exists() {
    # ARGS
    comp=$1

    if [[ $compiler == 0 ]]; then
        "$comp" --version > /dev/null 2>&1
        if [[ $? -eq 0 ]]; then
            compiler="$comp"
        fi
    fi
}
check_is_llvm_based() {
    local comp=$1
    if [[ $comp == "g++" || $comp == "gcc" ]]; then
        llvm_based=1
    else
        llvm_based=0
    fi
}
test_compiler() {
    # ARGS
    local comp=$1

    output=("$comp $TEST_PATH > /dev/null 2>&1 ")
    if [[ $? != 0 ]]; then
        echo "Compiler $comp failed to compile test file"
        echo "Output: "
        echo "$output"
        exit 1
    fi
}
find_c_compiler() {
    # arguments
    local comp=$1
    if [[ $comp != 0 ]]; then
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
                test_compiler_exists icx
            else
                test_compiler_exists amdclang
            fi
        else
            # unknown target cpu, perform linear check
            test_compiler_exists icx
            test_compiler_exists amdclang
        fi

        test_compiler_exists clang
        test_compiler_exists gcc
        if [[ $compiler == 0 ]]; then
            echo "No suitable C++ compiler found"
            exit 1
        fi
    fi
    comp=$compiler
    test_compiler $comp
    check_is_llvm_based $comp
    c_compiler=$comp
    compiler=0
}

find_cxx_compiler() {
    # arguments
    local comp=$1
    if [[ $comp != 0 ]]; then
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
    comp=$compiler
    test_compiler $comp
    check_is_llvm_based $comp
    cxx_compiler=$comp
    compiler=0
}