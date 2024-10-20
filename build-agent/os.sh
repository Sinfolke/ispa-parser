
if [[ "$OSTYPE" == "darwin"* or "$OSTYPE" == "cygwin" or "$OSTYPE" == "msys"]]; then
    echo "Do not run this script in an emulated environment. Use github shell instead. "
fi


if [[ "$(uname -s)" == *"NT"* || -e "/c/Windows" ]]; then
    # git compatibility mode
    export WINDOWS 1
else
    # linux
    export WINDOWS 0
fi
