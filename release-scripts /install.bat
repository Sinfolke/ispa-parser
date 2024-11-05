:: NOTE! Run this cript as root

set PARSER_NAME="isc-parser"
echo "[copying]"
cp %PARSER_NAME% "C:/Program Files"
cp uninstall.bat "C:/Program Files/%PARSER_NAME%"

echo "[setting PATH]"
setx PATH "%PATH%;C:/Program Files/%PARSER_NAME%"

echo "[finished]"