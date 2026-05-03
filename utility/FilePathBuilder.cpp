#include "FilePathBuilder.h"
#include <windows.h>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

// ── Private helper ────────────────────────────────────────────────────────────
// Reads a Windows environment variable and returns its value as a string
// Example:  getEnvVar("TEMP")  →  "C:\Users\Haider\AppData\Local\Temp"
string FilePathBuilder::getEnvVar(string varName) {

    char buffer[512];
    DWORD result = GetEnvironmentVariableA(varName.c_str(), buffer, sizeof(buffer));

    if (result == 0) {
        return "";  // variable not found
    }

    return string(buffer);
}

// ── Public methods ────────────────────────────────────────────────────────────

string FilePathBuilder::getTempPath() {
    return getEnvVar("TEMP");
}

string FilePathBuilder::getDownloadsPath() {
    return getEnvVar("USERPROFILE") + "\\Downloads";
}

string FilePathBuilder::getDesktopPath() {
    return getEnvVar("USERPROFILE") + "\\Desktop";
}

string FilePathBuilder::getStartupPath() {
    return getEnvVar("APPDATA") + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup";
}

// Returns all directories Quick Scan should check
vector<string> FilePathBuilder::getQuickScanPaths() {

    vector<string> paths;
    paths.push_back(getTempPath());
    paths.push_back(getDownloadsPath());
    paths.push_back(getDesktopPath());
    paths.push_back(getStartupPath());
    return paths;

}

// Returns all directories JunkCleaner should scan
vector<string> FilePathBuilder::getJunkPaths() {

    vector<string> paths;
    paths.push_back(getTempPath());
    paths.push_back("C:\\Windows\\Prefetch");
    // Chrome cache
    paths.push_back(getEnvVar("LOCALAPPDATA") + "\\Google\\Chrome\\User Data\\Default\\Cache");
    // Edge cache
    paths.push_back(getEnvVar("LOCALAPPDATA") + "\\Microsoft\\Edge\\User Data\\Default\\Cache");
    return paths;

}

// Returns (and creates if needed) the app's own data folder
string FilePathBuilder::getAppDataDir() {

    string dir = getEnvVar("APPDATA") + "\\PhoenixSecurity";

    // Create the folder if it doesn't already exist
    if (!fs::exists(dir)) {
        fs::create_directories(dir);
    }

    return dir;
}