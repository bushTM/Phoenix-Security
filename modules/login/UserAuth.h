#pragma once
#include <string>

using namespace std;

// ─────────────────────────────────────────────
// UserAuth
// Handles master password setup and login
//
// SECURITY RULES:
//   - The master password is NEVER written anywhere
//   - Only a derived hash + random salt are saved in User.json
//   - The hash is derived using PBKDF2-SHA256 (100,000 iterations)
//     This makes brute-force attacks extremely slow
//
// User.json format:
//   { "hash": "a3f5c7...", "salt": "b8e2d4..." }
//
// HOW LOGIN WORKS:
//   1. Load salt from User.json
//   2. Re-derive the hash from  inputPassword + salt
//   3. Compare with the stored hash
//   4. If they match → login success
//
// Dependencies: FilePath (for stringToHash)
// ─────────────────────────────────────────────

class UserAuth {
public:

    // First-time setup
    // Generates a random salt, derives a hash, and saves both to User.json
    // password = the master password the user chose
    // fname    = full path to User.json
    void setupUser(string password, string fname);

    // Verifies a login attempt
    // Loads the salt, re-derives the hash, compares with stored hash
    // Returns true if the password is correct
    bool verifyPassword(string password, string fname);

    // Returns true if User.json exists (setup has been done before)
    bool isSetupDone(string fname);

    // Derives a 32-byte AES key from a password + salt using PBKDF2
    // Returns the key as a 64-character hex string (32 bytes = 64 hex chars)
    // This key is passed to AESCipher for encrypting/decrypting files
    string deriveKey(string password, string salt);

private:

    // Generates a random 16-byte salt and returns it as a hex string
    string generateSalt();

    // Loads hash and salt from User.json
    // Sets outHash and outSalt if successful
    // Returns false if file not found or malformed
    bool loadUserData(string fname, string& outHash, string& outSalt);

};