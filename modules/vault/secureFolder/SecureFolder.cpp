#include "SecureFolder.h"
#include "../../../utility/AESCipher.h"
#include <filesystem>

using namespace std;
namespace fs = filesystem;

// Encrypts a file and stores it in the vault
string SecureFolder::addFileToVault(string fname, string vaultDir, string key) {

}

// Decrypts a vault file and exports it to a folder
string SecureFolder::exportFileFromVault(string vfname, string outputDir, string key) {

}

// Returns a list of all .vault filenames in the vault folder
vector<string> SecureFolder::listVaultFiles(string vaultDir) {

}

// Removes a file from the vault (with optional restore)
void SecureFolder::removeFromVault(string vfname, string vaultDir, string key,
                                    bool restoreOriginal, string restorePath) {

}

// "document.pdf"  →  "document.pdf.vault"
string SecureFolder::toVaultName(string fname) {

}

// "document.pdf.vault"  →  "document.pdf"
string SecureFolder::fromVaultName(string vfname) {
 
}