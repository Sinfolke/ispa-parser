set -e
cmake -B build -DCMAKE_BUILD_TYPE=Release -DBOOST_ROOT=./boost
cmake --build build -j$((nproc))
