#include "junk_cleaner.h"
#include "../../utility/FilePath.h"
#include "../../utility/Logger.h"

#include <filesystem>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;
namespace fs = filesystem;

// Checks whether extension belongs to junk file list
bool junk_cleaner::isJunkFile(string extension) {

    for (string junkExt : junkExtensions) {

        if (extension == junkExt) {
            return true;
        }
    }

    return false;
}

// Scans all given directories and returns a flat list of junk file paths
vector<string> junk_cleaner::scanJunk(vector<string> junkPaths) {

    vector<string> junkFiles;

    for (string path : junkPaths) {

        try {

            if (!fs::exists(path)) {
                continue;
            }

            for (const auto& entry : fs::recursive_directory_iterator(path)) {

                try {

                    if (entry.is_regular_file()) {

                        string extension = entry.path().extension().string();

                        if (isJunkFile(extension)) {
                            junkFiles.push_back(entry.path().string());
                        }
                    }

                }
                catch (...) {
                    continue;
                }
            }

        }
        catch (...) {
            continue;
        }
    }

    return junkFiles;
}

// Returns total size of all files in bytes
long long junk_cleaner::calculateSize(vector<string> files) {

    long long totalSize = 0;

    for (string file : files) {

        try {

            if (fs::exists(file)) {
                totalSize += fs::file_size(file);
            }

        }
        catch (...) {
            continue;
        }
    }

    return totalSize;
}

// Deletes all given files, logs errors but keeps going
int junk_cleaner::deleteFiles(vector<string> files, string logFile) {

    int deletedCount = 0;

    for (string file : files) {

        try {

            if (fs::exists(file)) {

                fs::remove(file);
                deletedCount++;
            }

        }
        catch (exception& e) {

            Logger logger(logFile);

            logger.writeLog(
                "Failed to delete file: " +
                file +
                " | Error: " +
                e.what()
            );
        }
    }

    return deletedCount;
}

// Converts bytes to a human-readable size string
string junk_cleaner::formatSize(long long bytes) {

    double size = bytes;

    string unit = " B";

    if (size >= 1024) {
        size /= 1024;
        unit = " KB";
    }

    if (size >= 1024) {
        size /= 1024;
        unit = " MB";
    }

    if (size >= 1024) {
        size /= 1024;
        unit = " GB";
    }

    stringstream stream;

    stream << fixed << setprecision(2) << size << unit;

    return stream.str();
}