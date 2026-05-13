#pragma once

#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// ─────────────────────────────────────────────
// JunkCleaner
// Finds and deletes temporary / junk files
//
// HOW THE GUI SHOULD USE THIS:
//   Step 1 — call scanJunk()       to find all junk files
//   Step 2 — call calculateSize()  to show user how much space will be freed
//   Step 3 — show a confirmation dialog
//   Step 4 — call deleteFiles() after confirmation
//
// Dependencies:
//   - FilePath
//   - FilePathBuilder
//   - Logger
// ─────────────────────────────────────────────

class JunkCleaner {
private:

    // File extensions considered junk
    vector<string> junkExtensions = {
        ".tmp",
        ".log",
        ".old",
        ".bak",
        ".cache"
    };

    // Checks whether file extension matches junk list
    bool isJunkFile(string extension);

public:

    // Scans all given directories and returns junk file paths
    vector<string> scanJunk(vector<string> junkPaths);

    // Calculates total size of all files
    long long calculateSize(vector<string> files);

    // Deletes files and logs failed deletions
    int deleteFiles(vector<string> files, string logFile);

    // Converts bytes into readable format
    string formatSize(long long bytes);

};
