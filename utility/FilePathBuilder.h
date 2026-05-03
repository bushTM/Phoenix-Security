#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// FilePathBuilder
// Builds Windows system paths at runtime
// Never hardcode "C:\\Users\\Haider\\" — use this class instead
// so the app works on ANY Windows machine
// ─────────────────────────────────────────────

class FilePathBuilder {
public:

    // Returns path to Windows temp folder
    // Example result:  C:\Users\Haider\AppData\Local\Temp
    string getTempPath();

    // Returns path to the user's Downloads folder
    // Example result:  C:\Users\Haider\Downloads
    string getDownloadsPath();

    // Returns path to the user's Desktop
    // Example result:  C:\Users\Haider\Desktop
    string getDesktopPath();

    // Returns path to the Windows Startup folder
    // Example result:  C:\Users\Haider\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
    string getStartupPath();

    // Returns all directories that Quick Scan should check
    // (Temp, Downloads, Desktop, Startup)
    vector<string> getQuickScanPaths();

    // Returns all directories JunkCleaner should scan
    // (Temp, Prefetch, browser caches)
    vector<string> getJunkPaths();

    // Returns the folder where Phoenix Security stores its own data
    // Example result:  C:\Users\Haider\AppData\Roaming\PhoenixSecurity
    string getAppDataDir();

private:

    // Helper: reads a Windows environment variable like TEMP or APPDATA
    // Returns empty string if the variable does not exist
    string getEnvVar(string varName);

};