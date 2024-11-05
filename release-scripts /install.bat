:: NOTE! Run this cript as root
set PARSER_NAME="isc-parser"

set -e
echo "[copying]"
cp %PARSER_NAME% "C:/Program Files"
cp uninstall.bat "C:/Program Files/%PARSER_NAME%"
IF ERRORLEVEL 1 EXIT /B 1   
echo "[setting PATH]"
setx PATH "%PATH%;C:/Program Files/%PARSER_NAME%"
IF ERRORLEVEL 1 EXIT /B 1
echo "[finished]"