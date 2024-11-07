# build a common release
# assume the user would use processor >= 2011 year - putting sse4 instruction
OPT="-msse3 -msse4.1 -msse4.2"

# Linux amd64
./build.sh -gen Ninja -compiler g++ -package linux-amd64 $OPT
# Windows amd64
./build.sh -gen Ninja -compiler x86_64-w64-mingw32-g++ $OPT