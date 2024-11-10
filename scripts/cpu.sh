if [[ ! -e "$MOD_DIR/cpuid" ]]; then
    # Compile once at first build and use
    c_compiler=0
    find_c_compiler 0

    # Compile the source file
    output=$("$c_compiler" -o "$MOD_DIR/cpuid" "$MOD_DIR/cpuid.cpp" 2>&1)
    if [[ $? -ne 0 ]]; then
        echo "Failed to compile cpuid:"
        echo "$output"
        exit 1
    fi
fi
# Get target cpu
"$MOD_DIR/cpuid"
intel_cpu=$?
if [[ $intel_cpu == 2 ]]; then
    echo "Could not define your cpu vendor or it is not Intel/AMD cpu. Use manual flags to compile with your vendor compiler"

fi
