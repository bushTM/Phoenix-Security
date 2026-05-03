#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// JunkCleaner
// Finds and deletes temporary / junk files
//
// HOW THE GUI SHOULD USE THIS:
//   Step 1 — call scanJunk()       to find all junk files
//   Step 2 — call calculateSize()  to show user how much space will be freed
//   Step 3 — show a confirmation dialog  ("Delete 342 MB of junk?")
//   Step 4 — call deleteFiles()    ONLY after user confirms
//
//   NEVER skip the confirmation step.
//
// Dependencies: FilePath, FilePathBuilder, Logger
// ─────────────────────────────────────────────

class JunkCleaner {
public:

    // Scans all given directories and returns a list of junk file paths
    // junkPaths = list of dirs to scan (get these from FilePathBuilder)
    vector<string> scanJunk(vector<string> junkPaths);

    // Returns the total size in bytes of all the given files
    // Used to show the user how much space will be freed
    long long calculateSize(vector<string> files);

    // Deletes all the given files
    // Skips locked files — logs the error and continues
    // logFile = path to Logs.txt
    // Returns the number of files successfully deleted
    int deleteFiles(vector<string> files, string logFile);

    // Converts a byte count to a readable string
    // e.g.  1048576  →  "1.00 MB"
    //       2500     →  "2.44 KB"
    string formatSize(long long bytes);

};