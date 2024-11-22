set -e
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$((nproc))
