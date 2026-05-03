#include "UserAuth.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iomanip>

using namespace std;
namespace fs = filesystem;

// First-time setup: derive hash from password and save to User.json
void UserAuth::setupUser(string password, string fname) {

}

// Verifies a password attempt against the stored hash
bool UserAuth::verifyPassword(string password, string fname) {

}

// Returns true if User.json already exists
bool UserAuth::isSetupDone(string fname) {

}

// Derives a 32-byte AES key using PBKDF2-SHA256
// Returns the key as a 64-character hex string
string UserAuth::deriveKey(string password, string salt) {

}

// Generates a random 16-byte salt and returns it as a 32-char hex string
string UserAuth::generateSalt() {

}

// Loads hash and salt values from User.json
bool UserAuth::loadUserData(string fname, string& outHash, string& outSalt) {

}