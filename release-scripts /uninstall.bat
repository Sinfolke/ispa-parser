:: NOTE! Run this script as root
set -e

set PARSER_NAME="isc-parser"

echo "[uninstalling]"
rmdir  "C:/Program Files/%PARSER_NAME%"
IF ERRORLEVEL 1 EXIT /B 1
echo "[finished]"