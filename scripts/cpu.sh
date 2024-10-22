if [[ -e cpuid ]]; then
    # use prebuild for this target
    cpuget cpuid
    return
fi
# in future it might use prebuild versions
# though compile from source on first build is more flexible and does not even take a second

# arch=(lscpu | grep Architecture)
# if [[ $arch == *x86-* ]]; then
#     # use prebuild i386 executable to get cpu vendor
#     # 0 for Intel, 1 for AMD
#     if [[ $arch == *linux* ]]; then
#         cpuget cpuid-lin    # linux
#     else
#         cpuget cpuid-win    # windows
#     fi
# else

# try any of possible compilers to build cpuid.c
# if non found fail here
find_compiler 0 comp
output=($comp cpuid.c -o cpuid)
if [[ $? -ne 0 ]]; then
    echo "Failed compile cpuid: "
    echo "$output"
    exit 1
fi
cpuget cpuid


cpuget(name) {
    intel_cpu=(./$name | grep -q Intel)
}