#include "AESCipher.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <fstream>
#include <vector>

using namespace std;

// Generates a random 16-byte IV using OpenSSL's secure random generator
string AESCipher::generateIV() {


}

// Encrypts a file in-place using AES-256-CBC
// After encryption the file looks like:  [16-byte IV][encrypted bytes]
bool AESCipher::encrypt(string fname, string key) {

    // ── Step 1: Read the entire file into memory ──────────────────────────
    // ── Step 2: Generate a random IV ──────────────────────────────────────
    // ── Step 3: Encrypt using OpenSSL EVP (high-level interface) ─────────
    // Tell OpenSSL: use AES-256-CBC with our key and IV
    // Buffer for the encrypted output (needs extra space for padding)
    // Encrypt the plaintext
    // Flush any remaining bytes
    // ── Step 4: Write  [IV + encrypted data]  back to the same file ──────
    // Write the 16-byte IV first so we can read it back during decryption
    // Write the encrypted bytes

    return true;
}

// Decrypts a file in-place using AES-256-CBC
// Expects file format:  [16-byte IV][encrypted bytes]
bool AESCipher::decrypt(string fname, string key) {

    // ── Step 1: Read the entire file into memory
  // file too small to be valid

    // ── Step 2: Extract the IV from the first 16 bytes
    // The rest of the file is the encrypted data
    // ── Step 3: Decrypt using OpenSSL EVP
   // ── Step 4: Write the decrypted plaintext back to the file ───────────

    return true;
}