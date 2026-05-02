#include "FilePath.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

// Returns all files and folders at the given path (one level deep)
std::vector<std::string> FilePath::getFiles(const std::string& path) {
    std::vector<std::string> results;

    // TODO: Use std::filesystem::directory_iterator to iterate path
    // For each entry, push entry.path().string() into results
    // Wrap in try/catch — path may not exist or may be permission-denied

    return results;
}

// Returns SHA-256 hash of a file as a lowercase hex string
std::string FilePath::fileToHash(const std::string& fname) {
    // TODO: Open file in binary mode
    // Read file contents in chunks
    // Compute SHA-256 using OpenSSL: SHA256_Init, SHA256_Update, SHA256_Final
    // Convert the resulting byte array to a hex string and return it
    return "";
}

// Returns SHA-256 hash of a plain string
std::string FilePath::stringToHash(const std::string& str) {
    // TODO: Same as fileToHash but feed the string bytes directly
    // into SHA256_Update instead of reading from a file
    return "";
}