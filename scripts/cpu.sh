if [[ ! -e "$SCRIPTS_DIR/cpuid" ]]; then
    # Compile once at first build and use
    compiler=0
    find_compiler 0 compiler

    # whether to use ld.lld
    check_is_llvm_based

    # Compile the source file
    output=$("$compiler" -o "$SCRIPT_DIR/cpuid" "$MOD_DIR/cpuid.cpp" 2>&1)
    if [[ $? -ne 0 ]]; then
        echo "Failed to compile cpuid:"
        echo "$output"
        exit 1
    fi
fi
# Get target cpu
"$SCRIPT_DIR/cpuid"
intel_cpu=$?
if [[ $intel_cpu == 2 ]]; then
    echo "Could not define your cpu vendor or it is not Intel/AMD cpu. Use manual flags to compile with your vendor compiler"

fi
# clear compiler to request re-find later
compiler=0
