#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// SecureFolder
// AES-256 encrypted file vault
//
// HOW IT WORKS:
//   Adding a file:
//     1. Copy the file into the vault folder
//     2. Encrypt the copy using AES-256
//     3. Rename it to  filename.ext.vault
//     4. Delete the original file
//
//   Exporting a file:
//     1. Copy the .vault file to the output folder
//     2. Decrypt the copy
//     3. Rename it back to  filename.ext
//
//   Files inside the vault are ALWAYS encrypted.
//   Plaintext only exists momentarily during export.
//
// Dependencies: AESCipher
// ─────────────────────────────────────────────

class SecureFolder {
public:

    // Encrypts a file and stores it in the vault
    // Deletes the original file after successful encryption
    // key      = 32-byte AES key derived from the user's PIN
    // fname    = full path to the file to add
    // vaultDir = path to the vault storage folder
    // Returns the vault filename  e.g.  "document.pdf.vault"
    string addFileToVault(string fname, string vaultDir, string key);

    // Decrypts a vault file and exports it to a folder
    // key       = 32-byte AES key derived from the user's PIN
    // vfname    = full path to the .vault file
    // outputDir = where to write the decrypted file
    // Returns the full path of the restored file
    string exportFileFromVault(string vfname, string outputDir, string key);

    // Returns a list of all .vault filenames in the vault folder
    // These are shown in the vault panel in the GUI
    vector<string> listVaultFiles(string vaultDir);

    // Removes a file from the vault
    // If restoreOriginal is true, it decrypts and restores the file first
    void removeFromVault(string vfname, string vaultDir, string key,
                         bool restoreOriginal = false,
                         string restorePath = "");

private:

    // Converts a filename to a vault filename
    // "document.pdf"  →  "document.pdf.vault"
    string toVaultName(string fname);

    // Converts a vault filename back to the original filename
    // "document.pdf.vault"  →  "document.pdf"
    string fromVaultName(string vfname);

};