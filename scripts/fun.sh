

find_compiler(compiler handler) {
    local comp=0
    if [[ $compiler != 0 ]]; then
        test_compiler_exists $compiler comp
        if [[ $comp == 0 ]]; then
            echo "Compiler $compiler is not found"
            exit 1
        fi
    else
        # perform check for processor-specific compiler
        if [[ -z $intel_cpu ]]; then
            if $intel_cpu; then
                test_compiler_exists icpx comp
            else
                test_compiler_exists amdclang++ comp
            fi
        else
            # unknown target cpu, perform linear check
            test_compiler_exists icpx comp
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
    if [[ "$handler" == 0 ]]; then
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

find_generator(generator handler) {
    local gen=0
    if [[ $generator != 0 ]]; then
        $generator > /dev/null 2>&1
        if [[ $? != 0 ]]; then
            echo "Generator $generator is not found"
            exit 1
        fi
        gen=$generator
    else
        # perform check for processor-specific compiler

        test_generator_exists ninja gen
        test_generator_exists make gen
        if $WINDOWS; then
            test_generator_exists msbuild 
        fi
        if [[ $gen == 0 ]]; then
            echo "No suitable generator found"
            exit 1
        fi
    fi
    test_compiler $comp
    $handler=$comp
}