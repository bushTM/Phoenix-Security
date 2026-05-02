#include "AESCipher.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <fstream>
#include <vector>

// Generates a random 16-byte IV
std::string AESCipher::generateIV() {
    // TODO: Create a 16-byte buffer
    // Call RAND_bytes(buffer, 16) to fill it with random bytes
    // Return as std::string(buffer, 16)
    return "";
}

// Encrypts a file in-place using AES-256-CBC
// File format after encryption: [16-byte IV][encrypted data]
bool AESCipher::encrypt(const std::string& fname, const std::string& key) {
    // TODO:
    // 1. Read all bytes from fname into a buffer
    // 2. Generate a random IV using generateIV()
    // 3. Create an EVP_CIPHER_CTX
    // 4. Call EVP_EncryptInit_ex with EVP_aes_256_cbc(), key, IV
    // 5. Call EVP_EncryptUpdate to encrypt the buffer
    // 6. Call EVP_EncryptFinal_ex to flush remaining bytes
    // 7. Write IV + encrypted bytes back to fname
    // 8. Clean up: EVP_CIPHER_CTX_free
    // 9. Return true on success, false on any error
    return false;
}

// Decrypts a file in-place using AES-256-CBC
// Expects file format: [16-byte IV][encrypted data]
bool AESCipher::decrypt(const std::string& fname, const std::string& key) {
    // TODO:
    // 1. Read all bytes from fname
    // 2. Extract first 16 bytes as IV
    // 3. Remaining bytes are the encrypted data
    // 4. Create an EVP_CIPHER_CTX
    // 5. Call EVP_DecryptInit_ex with EVP_aes_256_cbc(), key, IV
    // 6. Call EVP_DecryptUpdate then EVP_DecryptFinal_ex
    // 7. Write decrypted bytes back to fname
    // 8. Return true on success, false on any error
    return false;
}