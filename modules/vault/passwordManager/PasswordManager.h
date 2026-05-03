#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// Credential
// One saved password entry (e.g. Gmail login)
// ─────────────────────────────────────────────
struct Credential {
    string serviceName;  // e.g. "Gmail"
    string username;     // e.g. "haider@gmail.com"
    string password;     // stored encrypted on disk, plaintext in memory only
};


// ─────────────────────────────────────────────
// PasswordManager
// Stores and retrieves saved credentials
// All entries are AES-256 encrypted in Passwords.dat
//
// IMPORTANT:
//   The GUI must verify the master password BEFORE
//   calling any method here. This class does NOT
//   check the master password — it trusts the caller.
//
// Passwords.dat format (before encryption):
//   JSON array:
//   [
//     { "service":"Gmail", "user":"...", "pass":"..." },
//     { "service":"GitHub","user":"...", "pass":"..." }
//   ]
//
// Dependencies: AESCipher
// ─────────────────────────────────────────────
class PasswordManager {
public:

    // Loads and decrypts Passwords.dat, returns all saved credentials
    // key   = 32-byte AES key derived from the master password
    // fname = full path to Passwords.dat
    vector<Credential> getPasswords(string fname, string key);

    // Adds a new credential entry and re-saves the encrypted file
    // Returns true if saved successfully
    bool storePassword(string serviceName, string username,
                       string password, string fname, string key);

    // Deletes a credential entry by service name
    // Returns true if the entry was found and deleted
    bool deletePassword(string serviceName, string fname, string key);

private:

    // Converts a vector of Credentials into a JSON array string
    string toJson(vector<Credential> creds);

    // Parses a JSON array string into a vector of Credentials
    vector<Credential> fromJson(string json);

};