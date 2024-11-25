lld_global_check() {
    if [[ $path == 0 ]]; then
        path_tmp=$(which $1)
        if [[ $? == 0 ]]; then
            path=$path_tmp
        fi
    fi
}
lld_from_installed() {
    if [[ $path == 0 ]]; then
        ls /usr/bin/ld.$1 > /dev/null 2>&1
        if [[ $? == 0 ]]; then
            path=/usr/bin/ld.$1
            lld_name=ld.$1
        fi
    fi
}
lld_check() {
    if [[ $path == 0 ]]; then
        path_tmp=$(ls $1)
        if [[ $? ]]; then
            path=$path_tmp
        fi
    fi
}
find_llvm_ld() {
    path=0
    if $WINDOWS; then
        lld_name=ld-link.exe
    else
        lld_name=ld.lld
    fi
    lld_global_check $lld_name # in global path
    if ! $WINDOWS; then
        if [[ $intel_cpu ]]; then
            # Intel C++ is better to use with it's own linker else errors might occur
            lld_check ~/intel/oneapi/compiler/latest/bin/compiler/ld.lld # installed by apt
            lld_check /opt/intel/oneapi/compiler/latest/bin/compiler/ld.lld # installed via online installer
        fi
        # general-purpose linker
        lld_from_installed lld

        # version specific
        lld_from_installed lld-17
        lld_from_installed lld-15
        lld_from_installed lld-14
        lld_from_installed lld-13


        # .. rest


    fi
    if [[ $path == 0 ]]; then
        echo "Warning: You're using llvm-based compiler but lld is not found"
        lld_path=0
    else
        lld_path=$path
    fi
    unset path
}
find_ld() {
    ld=0
    if [[ $llvm_based ]]; then
        find_llvm_ld
        if [[ $lld_path != 0 ]]; then
            ld=$lld_path
            return
        fi
    fi

    # not found llvm linker or gnu compiler is used

    /usr/bin/ld --version > /dev/null

    if [[ $? ]]; then
        if [[ $llvm_based ]]; then
            echo "Neither GNU nor LLVM linker was found"
        else
            echo "Could not find gnu linker"
        fi
        exit 1
    fi
    
    ld=/usr/bin/ld  # gnu linker found
}