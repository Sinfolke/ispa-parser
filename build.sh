set -e
cmake -B build
cmake --build build -j$((nproc))
