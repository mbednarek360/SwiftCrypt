# SwiftCrypt

### Fast and simple two way key based encryption.

#### ⚠️SwiftCrypt is still in alpha, it may be very buggy and unoptomized. Updates will come.⚠️


##### SwiftCrypt is a command line based program, although an optional GUI is currently being developed.

---
To install, clone the repo and run install.sh. You must run this script as root to work.

`sudo sh install.sh`


To uninstall, run uninstall.sh located in the SwiftCrypt directory. Root is again required.

`sudo sh ~/.local/share/SwiftCrypt/uninstall.sh`

---

Encrypting a file requires an argument for an input file and a key file.

Ex:
`swiftcrypt file.txt key.txt -e`


Decoding a file requires a similar process.

Ex:
`swiftcrypt file.txt.sc key.txt -d`

---

Below is a screenshot of the work in progress GUI.

![Screenshot of GUI](screenshot.png)

It can encrypt and decrypt any file with an alphanumerical key.

---
