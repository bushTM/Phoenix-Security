#include "FilePathBuilder.h"
#include <windows.h>
#include <shlobj.h>    // for SHGetFolderPath
#include <string>

// Helper: reads a Windows environment variable like %TEMP%
// Returns empty string if variable not found
static std::string getEnvVar(const std::string& var) {
    // TODO: Use GetEnvironmentVariableA(var.c_str(), buffer, size)
    // Return the buffer contents as a std::string
    return "";
}

std::string FilePathBuilder::getTempPath() {
    // TODO: Return getEnvVar("TEMP")
    return "";
}

std::string FilePathBuilder::getDownloadsPath() {
    // TODO: Build path as getEnvVar("USERPROFILE") + "\\Downloads"
    return "";
}

std::string FilePathBuilder::getDesktopPath() {
    // TODO: Build path as getEnvVar("USERPROFILE") + "\\Desktop"
    return "";
}

std::string FilePathBuilder::getStartupPath() {
    // TODO: Build path using getEnvVar("APPDATA") +
    // "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup"
    return "";
}

std::string FilePathBuilder::getAppDataPath() {
    // TODO: Return getEnvVar("APPDATA")
    return "";
}

std::vector<std::string> FilePathBuilder::getQuickScanPaths() {
    // Returns the 4 high-risk dirs for Quick Scan
    return {
        getTempPath(),
        getDownloadsPath(),
        getDesktopPath(),
        getStartupPath()
    };
}

std::vector<std::string> FilePathBuilder::getJunkPaths() {
    // TODO: Return Temp + Prefetch + browser cache paths + Recycle Bin
    // Prefetch: "C:\\Windows\\Prefetch"
    // Chrome cache: getEnvVar("LOCALAPPDATA") +
    //   "\\Google\\Chrome\\User Data\\Default\\Cache"
    return {
        getTempPath()
        // TODO: add the rest
    };
}

std::string FilePathBuilder::getAppDataDir() {
    // TODO: Return getEnvVar("APPDATA") + "\\PhoenixSecurity"
    // Also create this folder if it doesn't exist yet
    // Use std::filesystem::create_directories()
    return "";
}