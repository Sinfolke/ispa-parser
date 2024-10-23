## GET COMPILER

if [[ $compiler == 0 ]]; then 
    local comp=0
    if [[ $proc_specific == "intel" ]]; then
        comp=icpx
    elif [[ $proc_specific == "amd" ]]; then
        comp=amdclang++
    fi
    find_compiler $comp compiler
else
    # A custom compiler specified, try to find and test
    # otherwise find any possible compiler and use it
    find_compiler $compiler compiler
fi

## GET COMPILATION FLAGS

if [[ $# -lt 2 ]]; then
    flags="$*"
else
    # set to default
    if [[ $proc_specific != 0 ]]; then
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
    else
        flags="-O2 -flto -s"
        if [[ !$common ]]; then
            flags="$flags -march=native -mtune=native"
        fi
    fi
fi