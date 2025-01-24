WINDOWS=false
if [[ "$OSTYPE" == "darwin"* && "$OSTYPE" == "cygwin" ]]; then
    echo "Warning: you're running in $OSTYPE. Generally you should compile with sh.exe provided by git"
    WINDOWS=true
elif [[ "$OSTYPE" == "msys" ]]; then
    # either msys or git compatibility mode
    WINDOWS=true
fi