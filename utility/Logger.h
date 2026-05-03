#pragma once
#include <string>

using namespace std;

// ─────────────────────────────────────────────
// Logger
// Saves timestamped messages to Logs.txt
// Every module calls this after doing anything important
// ─────────────────────────────────────────────

class Logger {
public:

    // Returns the current time as a string
    // Example output:  2026-05-04 14:30:05
    static string getCurrentTime();

    // Writes one line to the log file
    // msg   = what happened  e.g. "DEL C:\\virus.exe"
    // time  = timestamp from getCurrentTime()
    // lfname = path to Logs.txt
    static void log(string msg, string time, string fname);

};