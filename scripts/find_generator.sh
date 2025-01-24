
test_generator_exists() {
    # ARGS
    local gen=$1


    if [[ "$generator" == 0 ]]; then
        if [[ $gen == Ninja ]]; then
            # ninja cmd is lowercase
            ninja --version > /dev/null 2>&1
        else
            $gen --version > /dev/null 2>&1
        fi
        if [[ $? == 0 ]]; then
            generator="$gen"
        fi
    fi
}

find_generator() {
    # ARGS
    gen=$1

    if [[ $generator != 0 ]]; then
        local generator_cache=$generator
        generator=0
        test_generator_exists $generator_cache
        if [[ $generator == 0 ]]; then 
            echo "Generator $generator not found"
            exit 1
        fi
        generator=$generator_cache
    else
        # perform check for processor-specific compiler

        test_generator_exists Ninja
        test_generator_exists make
        if $WINDOWS; then
            test_generator_exists msbuild 
        fi
        if [[ $generator == 0 ]]; then
            echo "No suitable generator found"
            exit 1
        fi
    fi
}