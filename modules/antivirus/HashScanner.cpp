#include "HashScanner.h"
#include "../../utility/FilePath.h"
#include "../../utility/Logger.h"
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

// Loads all hashes from hashes.txt — one hash per line — into knownHashes set
void HashScanner::loadHashes(string hashFile) {

}

// Scans a directory, deletes any file that matches a known malware hash
int HashScanner::scanDirectory(string dirPath, string logFile) {

}

// Returns how many hashes are loaded
int HashScanner::getLoadedHashCount() {
    return knownHashes.size();
}

// Checks one file against the loaded hash set
bool HashScanner::isKnownThreat(string fname) {

}