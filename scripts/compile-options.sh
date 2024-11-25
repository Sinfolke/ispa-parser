## GET COMPILATION FLAGS

if [[ $# > 0 ]]; then
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
            if [[ $intel_cpu ]]; then
                flags="$flags -xHost"
            else
                flags="$flags -march=native"
            fi
            flags="$flags -mtune=native"
        fi
    fi

fi