
cpuget() {
    # ARGS
    local name=$1
    ./$name
    intel_cpu=$?


    if [[ $intel_cpu == 2 ]]; then
        echo "Could not define your cpu vendor or it is not Intel/AMD cpu. Use manual flags to compile with your vendor compiler"
    fi
}

if [[ ! -e cpuid ]]; then
    # compile once at first build and use
    comp=0
    find_compiler 0 comp
    output=("$comp $MOD_DIR/cpuid.c -o cpuid")
    if [[ $? -ne 0 ]]; then
        echo "Failed compile cpuid: "
        echo "$output"
        exit 1
    fi
    cpuget cpuid

fi

cpuget cpuid
