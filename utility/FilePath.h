#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// FilePath
// Shared file-system helpers used by all modules
// Handles: listing files, hashing files, hashing strings
// ─────────────────────────────────────────────

class FilePath {
public:

    // Returns a list of every file and folder found at the given path
    // Used by: Antivirus scanner, JunkCleaner, SecureFolder
    // Example:  getFiles("C:\\Users\\Haider\\Downloads")
    //           returns {"file1.exe", "file2.pdf", ...}
    vector<string> getFiles(string path);

    // Computes the SHA-256 hash of a file and returns it as a hex string
    // Used by: HashScanner to check if a file is malware
    // Example:  fileToHash("C:\\bad.exe")  returns  "a3f5c7d9..."
    string fileToHash(string fname);

    // Computes the SHA-256 hash of a plain text string
    // Used by: UserAuth to hash the master password before storing
    // Example:  stringToHash("mypassword")  returns  "5e884898..."
    string stringToHash(string str);

};