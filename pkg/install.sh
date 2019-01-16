mkdir ~/.local/share/SwiftCrypt
g++ ../src/encrypt.cpp -o ~/.local/share/SwiftCrypt/swiftcrypt
cp uninstall.sh ~/.local/share/SwiftCrypt/uninstall.sh
ln -s ~/.local/share/SwiftCrypt/swiftcrypt /usr/bin