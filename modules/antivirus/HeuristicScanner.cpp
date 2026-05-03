#include "HeuristicScanner.h"
#include <algorithm>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

// ── Known bad strings used in the 6 checks ───────────────────────────────────

// Check 1 — known malware name substrings (case-insensitive)
vector<string> MALWARE_NAMES = {
    "eicar", "netbus", "subseven", "backdoor", "rootkit",
    "spyware", "adware", "wannacry", "mirai", "zeus"
};

// Check 2 — suspicious strings found inside malicious file content
vector<string> SUSPICIOUS_STRINGS = {
    "cmd.exe /c",
    "powershell -enc",
    "WScript.Shell",
    "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
    "wget http",
    "curl http"
};

// Check 4 — high-risk directory substrings (case-insensitive)
vector<string> RISKY_LOCATIONS = {
    "\\temp\\",
    "\\appdata\\roaming\\",
    "\\appdata\\local\\temp\\",
    "\\startup\\",
    "\\downloads\\"
};

// Check 5 — file extensions considered executable / dangerous
vector<string> EXEC_EXTENSIONS = {
    ".exe", ".bat", ".vbs", ".ps1", ".cmd", ".scr", ".pif"
};

// Check 6 — ransomware / trojan keywords
vector<string> VIRUS_KEYWORDS = {
    "ransom", "crypt", "worm", "trojan",
    "keylog", "dropper", "payload", "stealer"
};

// ── Helper ────────────────────────────────────────────────────────────────────

string HeuristicScanner::toLower(string str) {

}

// ── Public methods ────────────────────────────────────────────────────────────

// Runs all 6 checks and adds up the total score
int HeuristicScanner::scoreFile(string fname) {

}

// Returns true if the file should be quarantined
bool HeuristicScanner::shouldQuarantine(string fname) {
    return scoreFile(fname) >= THRESHOLD;
}

// ── The 6 checks ─────────────────────────────────────────────────────────────

// Check 1: File name matches a known malware name  (3 pts)
int HeuristicScanner::checkVirusName(string fname) {

}

// Check 2: File content contains suspicious strings  (3 pts)
int HeuristicScanner::checkSuspiciousContent(string fname) {

}

// Check 3: Double extension like  invoice.pdf.exe  (3 pts)
int HeuristicScanner::checkDoubleExtension(string fname) {

}

// Check 4: File is in a high-risk directory  (2 pts)
int HeuristicScanner::checkSuspiciousLocation(string fname) {

}

// Check 5: Executable extension in a non-standard location  (2 pts)
int HeuristicScanner::checkExecutableRisk(string fname) {

}

// Check 6: Ransomware / trojan keyword in file name  (2 pts)
int HeuristicScanner::checkVirusKeyword(string fname) {
}