#pragma once
#include <string>
#include <vector>

// FilePath — shared file-system helpers used by all modules
// Provides directory listing and SHA-256 hashing

class FilePath {
public:
    // Returns every file AND folder found at path (non-recursive)
    // Used by: Antivirus, Vault, Cleaner
    // Example: getFiles("C:\\Users\\user\\Downloads")
    std::vector<std::string> getFiles(const std::string& path);

    // Returns the SHA-256 hash of a file as a hex string
    // Used by: HashScanner
    // Example: fileToHash("C:\\sus.exe") → "a3f5c7..."
    std::string fileToHash(const std::string& fname);

    // Returns the SHA-256 hash of a plain string
    // Used by: UserAuth (hashing master password)
    std::string stringToHash(const std::string& str);
};