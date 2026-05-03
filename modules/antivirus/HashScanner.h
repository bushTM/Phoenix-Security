#pragma once
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// HashScanner  —  Antivirus Module 1
//
// HOW IT WORKS:
//   1. Load all known malware hashes from hashes.txt into a set
//   2. For each file the user wants to scan:
//      - compute the file's SHA-256 hash
//      - check if that hash is in the set  (O(1) lookup)
//      - if YES → delete the file and log it
//   3. Return how many threats were found
//
// Dependencies: FilePath, Logger
// ─────────────────────────────────────────────

class HashScanner {
public:

    // Loads all hashes from hashes.txt into memory
    // Call this when the user clicks Scan (not at startup)
    // hashFile = full path to data/signatures/hashes.txt
    void loadHashes(string hashFile);

    // Scans one directory for known malware
    // Deletes any file whose hash matches a loaded hash
    // Logs every deletion as:  [TIME] HASH-MATCH DEL [path]
    // Returns the number of files deleted
    int scanDirectory(string dirPath, string logFile);

    // Returns how many hashes are currently loaded in memory
    int getLoadedHashCount();

private:

    // Stores all known malware hashes loaded from hashes.txt
    // unordered_set gives us O(1) lookup — very fast even with 100k hashes
    unordered_set<string> knownHashes;

    // Checks one file against the loaded hash set
    // Returns true if the file is a known threat
    bool isKnownThreat(string fname);

};