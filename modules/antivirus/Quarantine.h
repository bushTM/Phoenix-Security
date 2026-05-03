#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// Quarantine
// Moves suspicious files to a safe holding folder
// Saves each file's original path so it can be restored later
//
// QuarantineData.json stores entries like this:
// [
//   { "name": "sus.exe",  "originalPath": "C:\\Users\\Haider\\Downloads\\sus.exe" },
//   { "name": "bad.bat",  "originalPath": "C:\\Users\\Haider\\Desktop\\bad.bat"   }
// ]
//
// Dependencies: Logger
// ─────────────────────────────────────────────

class Quarantine {
public:

    // Moves a file into the quarantine folder
    // Saves its original path in QuarantineData.json
    // Logs:  [TIME] MOV [originalPath]  SCORE:[score]
    //
    // fname     = full path of the file to quarantine
    // qDir      = path to the quarantine folder
    // qDataFile = path to QuarantineData.json
    // score     = the heuristic score that triggered this
    // logFile   = path to Logs.txt
    void quarantineFile(string fname, string qDir,
                        string qDataFile, int score, string logFile);

    // Restores a quarantined file back to where it came from
    // Looks up the original path from QuarantineData.json
    // Removes the entry from QuarantineData.json after restoring
    //
    // quarantinedName = just the filename (e.g. "sus.exe"), not full path
    void restoreFile(string quarantinedName, string qDir, string qDataFile);

    // Permanently deletes a file from the quarantine folder
    // Also removes its entry from QuarantineData.json
    void deleteFromQuarantine(string quarantinedName, string qDir, string qDataFile);

    // Returns a list of all filenames currently in quarantine
    vector<string> listQuarantined(string qDataFile);

private:

    // Reads the full contents of QuarantineData.json as a string
    // Returns "[]" if the file doesn't exist yet
    string loadDataFile(string qDataFile);

    // Writes a string back to QuarantineData.json
    void saveDataFile(string qDataFile, string content);

    // Finds the original path of a quarantined file in the JSON
    string getOriginalPath(string quarantinedName, string qDataFile);

};