if [[ ! -e cpuid ]]; then
    # compile once at first build and use
    comp=0
    find_compiler 0 comp
    output=($comp $MOD_DIR/cpuid.c -o cpuid)
    if [[ $? -ne 0 ]]; then
        echo "Failed compile cpuid: "
        echo "$output"
        exit 1
    fi
    cpuget cpuid

fi

cpuget cpuid

cpuget(name) {
    intel_cpu=(./$name | grep -q Intel)
}