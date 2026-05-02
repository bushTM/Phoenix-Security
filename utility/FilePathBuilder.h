#pragma once
#include <string>
#include <vector>

// FilePathBuilder — resolves Windows environment paths at runtime
// All paths are built from %TEMP%, %APPDATA%, etc. so they work
// on any Windows machine regardless of username or drive letter.
// Used by: Antivirus (quick scan), JunkCleaner, SecureFolder

class FilePathBuilder {
public:
    // Returns path to Windows %TEMP% folder
    // Example result: "C:\\Users\\Haider\\AppData\\Local\\Temp"
    std::string getTempPath();

    // Returns path to user's Downloads folder
    std::string getDownloadsPath();

    // Returns path to user's Desktop folder
    std::string getDesktopPath();

    // Returns path to Windows Startup folder
    std::string getStartupPath();

    // Returns path to %APPDATA%
    std::string getAppDataPath();

    // Returns all directories that Quick Scan should check
    // (Temp, Downloads, Desktop, Startup)
    std::vector<std::string> getQuickScanPaths();

    // Returns all directories that JunkCleaner should scan
    // (Temp, Prefetch, browser caches, Recycle Bin)
    std::vector<std::string> getJunkPaths();

    // Returns the path where Phoenix stores its own data
    // Example: "C:\\Users\\Haider\\AppData\\Roaming\\PhoenixSecurity"
    std::string getAppDataDir();
};