#include "Logger.h"
#include <fstream>
#include <ctime>

using namespace std;

// Returns current system time formatted as:  2026-05-04 14:30:05
string Logger::getCurrentTime() {

    // Get the current time from the system clock
    time_t now = time(0);

    // Convert it to local time (fills a tm struct with hour, min, sec etc.)
    tm* localTime = localtime(&now);

    // Format it into a readable string using a char buffer
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

    return string(buffer);
}

// Appends one line to the log file:  [2026-05-04 14:30:05] DEL C:\virus.exe
void Logger::log(string msg, string time, string fname) {

    // Open the log file in append mode so we never overwrite old logs
    ofstream file(fname, ios::app);

    if (file.is_open()) {
        file << "[" << time << "] " << msg << "\n";
        file.close();
    }

}