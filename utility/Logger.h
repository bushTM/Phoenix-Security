#pragma once
#include <string>
 
// Logger — writes timestamped action records to Logs.txt
// Used by every module. Never call GUI code from here.
// Usage: Logger::log("DEL C:\\file.exe", Logger::getTime(), "data/Logs.txt");
 
class Logger {
public:
    // Returns current system time as: 2026-04-29 14:30:05
    static std::string getTime();
 
    // Appends one line to the log file:  [time] msg
    // lfname = full path to Logs.txt
    static void log(const std::string& msg,
                    const std::string& time,
                    const std::string& fname);
};