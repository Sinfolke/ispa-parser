
find_generator(generator handler) {
    # ARGS
    local generator=$1
    local handler=$2

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