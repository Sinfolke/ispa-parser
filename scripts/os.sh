WINDOWS=1
if [[ "$OSTYPE" == "darwin"* or "$OSTYPE" == "cygwin"]]; then
    echo "Warning: you're running in $OSTYPE. Generally you should compile with sh.exe provided by git"
    WINDOWS=0
elif [[ "$OSTYPE" == "msys" ]]; then
    # either msys or git compatibility mode
    WINDOWS=0
fi