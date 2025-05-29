#!/bin/bash
# Clear and recreate build dir
BUILD_DIR=build
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

CLANG_VERSION=$(clang --version | grep -o 'clang version [0-9]*' | grep -o '[0-9]*')
if (( CLANG_VERSION < 16 )); then
    echo "ERROR: Clang version 16 or newer required. Found: $CLANG_VERSION"
    exit 1
fi

# Adjust these paths to your actual std module location
# Search for std.cppm in /lib and /usr
#STD_CPPM=$(find /lib /usr -type f -name std.cppm 2>/dev/null | head -n 1)
#
#if [[ -z "$STD_CPPM" ]]; then
#    echo "ERROR: Could not find std.cppm in /lib or /usr"
#    exit 1
#fi
#
## Derive the directory and std.compat.cppm path
#STD_MODULE_DIR=$(dirname "$STD_CPPM")
#STD_COMPAT_CPPM="${STD_MODULE_DIR}/std.compat.cppm"
## Check if std.compat.cppm exists
#if [[ ! -f "$STD_COMPAT_CPPM" ]]; then
#    echo "ERROR: std.compat.cppm not found in $STD_MODULE_DIR"
#    exit 1
#fi

echo "Found std.cppm: $STD_CPPM"
echo "Found std.compat.cppm: $STD_COMPAT_CPPM"
STD_MODULE_DIR=/usr/lib/llvm-18/share/libc++/v1
STD_CPPM="/usr/lib/llvm-18/share/libc++/v1/std.cppm"
STD_COMPAT_CPPM="/usr/lib/llvm-18/share/libc++/v1/std.compat.cppm"

# Compiler flags for Clang modules
CXX=clang++
CXXFLAGS="-g -std=c++20 -stdlib=libc++ -I$STD_MODULE_DIR -Wno-reserved-identifier -Wno-reserved-module-identifier"

# 1) Compile std modules first
echo "Compiling std modules..."
$CXX $CXXFLAGS  "$STD_MODULE_DIR/std.cppm" --precompile -o "$BUILD_DIR/std.pcm"
$CXX $CXXFLAGS  \
    -fprebuilt-module-path="$BUILD_DIR" \
    "$STD_MODULE_DIR/std.compat.cppm" \
    --precompile -o "$BUILD_DIR/std.compat.pcm"

# 2) Compile your source modules
echo "Compiling source modules..."
for mod in src/*.cppm; do
    modname=$(basename "$mod" .cppm)
    $CXX $CXXFLAGS -fprebuilt-module-path="$BUILD_DIR" \
        "$mod" --precompile -o "$BUILD_DIR/${modname}.pcm"
done

# 4) Compile tests linking against the modules
echo "Compiling tests..."
MODULE_FLAGS=""
for cppm in src/*.cppm; do
    modname=$(basename "$cppm" .cppm)
    pcm_file="$BUILD_DIR/$modname.pcm"
    MODULE_FLAGS="$MODULE_FLAGS -fmodule-file=dstd.$modname=$pcm_file"
done
for testsrc in tests/*.cpp; do
    testname=$(basename "$testsrc" .cpp)
    $CXX $CXXFLAGS -fprebuilt-module-path="$BUILD_DIR" $MODULE_FLAGS \
        "$testsrc" -L"$BUILD_DIR" -o "$BUILD_DIR/${testname}"
done

# 5) Run tests
echo "Running tests..."
for testexe in "$BUILD_DIR"/vector "$BUILD_DIR"/variant; do
    if [[ -x "$testexe" ]]; then
        echo "Running $(basename "$testexe")..."
        "$testexe"
    else
        echo "Test executable $testexe not found or not executable"
        exit 1
    fi
done

echo "All done."
