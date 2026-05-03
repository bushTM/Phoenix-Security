#include "Quarantine.h"
#include "../../utility/Logger.h"
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

// Moves a file into the quarantine folder and records its original path
void Quarantine::quarantineFile(string fname, string qDir,
                                 string qDataFile, int score, string logFile) {
a
}

// Restores a quarantined file to its original location
void Quarantine::restoreFile(string quarantinedName, string qDir, string qDataFile) {

}

// Permanently deletes a file from quarantine
void Quarantine::deleteFromQuarantine(string quarantinedName, string qDir, string qDataFile) {

}

// Returns a list of all filenames in QuarantineData.json
vector<string> Quarantine::listQuarantined(string qDataFile) {

}

// Reads QuarantineData.json into a string
string Quarantine::loadDataFile(string qDataFile) {

}

// Writes a string back to QuarantineData.json
void Quarantine::saveDataFile(string qDataFile, string content) {

}

// Looks up the original path of a file by name in QuarantineData.json
string Quarantine::getOriginalPath(string quarantinedName, string qDataFile) {

}