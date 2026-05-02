#pragma once
#include <string>

// AESCipher — AES-256-CBC file encryption and decryption
// Used by: PasswordManager, SecureFolder, UserAuth
//
// IMPORTANT: The caller is responsible for deriving the key.
//   - PasswordManager derives key from master password via PBKDF2
//   - SecureFolder derives key from PIN
//   - Pass the derived key into encrypt/decrypt — never store it.
//
// Key must be exactly 32 bytes (256 bits) for AES-256.
// IV is randomly generated per encryption and prepended to output file.

class AESCipher {
public:
    // Encrypt file at fname using the given 32-byte key.
    // Output is written back to the same file (in-place).
    // A random 16-byte IV is prepended to the encrypted output.
    // Returns true if successful.
    bool encrypt(const std::string& fname, const std::string& key);

    // Decrypt file at fname using the given 32-byte key.
    // Reads the IV from the first 16 bytes of the file.
    // Output is written back to the same file (in-place).
    // Returns true if successful.
    bool decrypt(const std::string& fname, const std::string& key);

private:
    // Generates a random 16-byte IV using OpenSSL RAND_bytes
    std::string generateIV();
};