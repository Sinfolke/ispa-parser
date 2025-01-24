# Initialize submodules with depth 1
init_submodule() {
    local path=$1
    echo "Initializing submodule: $path"
    git submodule update --recursive "$path" || echo "Failed to initialize $path"
}
#!/bin/bash

# Initialize a specific submodule and its immediate submodules
init_submodule_with_limit() {
    local submodule=$1

    # Initialize the top-level submodule
    echo "Initializing submodule: $submodule"
    git submodule update --init "$submodule" || echo "Failed to initilize $submodule"
}


init_submodule mod/parser
init_submodule external/cpuf
init_submodule_with_limit mod/converter-cpp
rm -rf mod/converter-cpp/mod/main
rm -rf mod/converter-cpp/mod/parser
rm -rf mod/converter-cpp/external/cpuf
git clone --branch main https://github.com/Sinfolke/ispa-parser mod/converter-cpp/mod/main
ln -s $(pwd)/mod/parser ./mod/converter-cpp/mod/parser
ln -s $(pwd)/external/cpuf ./mod/converter-cpp/external/cpuf