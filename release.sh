# build a common release
# assume the user would use processor >= 2011 year - putting sse4 instruction
OPT="-msse3 -msse4.1 -msse4.2"
export CFLAGS=$OPT
export CXXFLAGS=$OPT

build() {
    cmake -B build -G Ninja
    ninja -j$((nproc)) -C build
}
set_comp() {
    export CC=$1
    export CXX=$2
}
# Linux x86_64
set_comp gcc g++
build

# make script to package an executable here
# Windows x86_64
set_comp x86_64-w64-mingw32-gcc x86_64-w64-mingw32-g++
build
# make script to package an executable here





#./build.sh -gen Ninja -compiler g++ -package ubuntu-x86_64 $OPT
# Windows x86_64
#./build.sh -gen Ninja -compiler x86_64-w64-mingw32-g++ -package windows-x86_64 $OPT

