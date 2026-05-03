#include "FilePath.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;
namespace fs = filesystem;

// Returns every file and folder found at the given directory path
vector<string> FilePath::getFiles(string path) {

    vector<string> results;

    // Check the path actually exists before trying to open it
    if (!fs::exists(path)) {
        return results;  // return empty list if folder not found
    }

    // Loop through every item in the directory (one level deep)
    for (fs::directory_entry entry : fs::directory_iterator(path)) {
        results.push_back(entry.path().string());
    }

    return results;
}

// Returns the SHA-256 hash of a file as a hex string
string FilePath::fileToHash(string fname) {

    // Open the file in binary mode (needed for executables, images etc.)
    ifstream file(fname, ios::binary);

    if (!file.is_open()) {
        return "";  // return empty string if file cannot be opened
    }

    // Set up OpenSSL SHA-256
    SHA256_CTX context;
    SHA256_Init(&context);

    // Read the file in chunks and feed each chunk to SHA256_Update
    char buffer[4096];
    while (file.read(buffer, sizeof(buffer))) {
        SHA256_Update(&context, buffer, file.gcount());
    }
    // Feed any remaining bytes that didn't fill the last chunk
    SHA256_Update(&context, buffer, file.gcount());

    // Finalize and get the 32-byte hash result
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &context);

    // Convert the 32 bytes into a readable hex string (64 characters)
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return ss.str();
}

// Returns the SHA-256 hash of a plain string
string FilePath::stringToHash(string str) {

    // Same as fileToHash but we feed string bytes directly instead of a file
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)str.c_str(), str.size(), hash);

    // Convert to hex string
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return ss.str();
}