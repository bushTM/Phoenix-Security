#include "JunkCleaner.h"
#include "../../utility/FilePath.h"
#include "../../utility/Logger.h"
#include <filesystem>
#include <sstream>
#include <iomanip>

using namespace std;
namespace fs = filesystem;

// Scans all given directories and returns a flat list of junk file paths
vector<string> JunkCleaner::scanJunk(vector<string> junkPaths) {

}

// Returns total size of all files in bytes
long long JunkCleaner::calculateSize(vector<string> files) {

}

// Deletes all given files, logs errors but keeps going
int JunkCleaner::deleteFiles(vector<string> files, string logFile) {

}

// Converts bytes to a human-readable size string
string JunkCleaner::formatSize(long long bytes) {

}