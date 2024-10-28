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
            lld_check /opt/intel/oneapi/compiler/latest/bin/compiler/ld.lld # installed via shell installer
        fi
        lld_from_installed lld-13
        lld_from_installed lld-14
        lld_from_installed lld-15
        lld_from_installed lld-17
        # .. rest


    fi
    if [[ $path == 0 ]]; then
        echo "Could not find lld. You're using llvm-based compiler which often require lld instead of gnu ld"
        exit 1
    fi
    lld_path=$path
    unset path
}