#include "PasswordManager.h"
#include "../../../utility/AESCipher.h"
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;
namespace fs = filesystem;

// Loads Passwords.dat, decrypts it, and returns all saved credentials
vector<Credential> PasswordManager::getPasswords(string fname, string key) {

}

// Adds a new credential and re-saves the encrypted file
bool PasswordManager::storePassword(string serviceName, string username,
                                     string password, string fname, string key) {

 
}

// Deletes a credential entry by service name
bool PasswordManager::deletePassword(string serviceName, string fname, string key) {

}

// Converts a vector of Credentials into a JSON array string
// We build this manually — no library needed
string PasswordManager::toJson(vector<Credential> creds) {

}

// Parses a JSON string into a vector of Credentials
// Simple line-by-line parser — no library needed
vector<Credential> PasswordManager::fromJson(string json) {

}