# this script will automatically request root

usr=$HOME
PARSER_NAME=isc-parser
echo "[copying]"
sudo cp -r $PARSER_NAME /usr/local/bin
sudo cp uninstall.sh /usr/local/bin/$PARSER_NAME

echo "[setting PATH]"
# add include path
echo "export PATH=/usr/local/bin/$PARSER_NAME:\$PATH" >> $usr/.bashrc

echo "[finished]"