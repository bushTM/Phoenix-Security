#pragma once
#include <string>

using namespace std;

// ─────────────────────────────────────────────
// AESCipher
// Encrypts and decrypts files using AES-256-CBC ( are we using cbc?)
// Used by: PasswordManager, SecureFolder, UserAuth
//
// Note: i dont really know in detail how haider is coding this
// this is assumption or suggestion
//
// IMPORTANT RULE:
//   This class does NOT generate or store the key.
//   The caller (PasswordManager, SecureFolder) derives
//   the key from the user's password and passes it in.
//   Key must be exactly 32 characters (256 bits).
//
// File format after encryption:
//   First 16 bytes = IV (random, stored so we can decrypt later)
//   Rest of file   = encrypted data
// ─────────────────────────────────────────────

class AESCipher {
public:

    // Encrypts the file at fname using the given 32-byte key
    // Generates a random IV and prepends it to the file
    // Returns true if encryption succeeded
    bool encrypt(string fname, string key);

    // Decrypts the file at fname using the given 32-byte key
    // Reads the IV from the first 16 bytes of the file
    // Returns true if decryption succeeded
    bool decrypt(string fname, string key);

private:

    // Generates a random 16-byte string to use as an IV
    // IV = Initialization Vector (makes each encryption unique)
    string generateIV();

};