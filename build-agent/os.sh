
if [[ "$OSTYPE" == "darwin"* or "$OSTYPE" == "cygwin" or "$OSTYPE" == "msys"]]; then
    echo "Do not run this script in an emulated environment. Use github shell instead. "
fi

if [[ "$(uname -s)" == *"NT"* || -e "/c/Windows" ]]; then
    echo "Running on Windows"
else
    echo "Running on Unix/Linux"
fi
export WINDOWS=0
path=(get_full_path ./os.sh)
if [[ "$full_path" == *\\* ]]; then
    # uses backslashes like in windows
    # so it is github shell
    WINDOWS=1
fi

get_full_path() {
    local file=$1
    if [[ -e "$file" ]]; then
        output=("$(pwd)/$(basename "$file") > /dev/null 2>&1")
        if [[ $? != 0 ]]; then
            WINDOWS=1
            output=""
        fi
        echo "$output"
    fi
}