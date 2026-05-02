#include "Logger.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

// Returns current time formatted as: 2026-04-29 14:30:05
std::string Logger::getTime() {
    // TODO: Get current system time
    // Hint: use std::chrono::system_clock::now() and std::put_time
    return "";
}

// Appends "[time] msg" to the log file
void Logger::log(const std::string& msg,
                 const std::string& time,
                 const std::string& fname) {
    // TODO: Open lfname in append mode (std::ios::app)
    // Write one line: "[" + time + "] " + msg + "\n"
    // Always close the file after writing
}