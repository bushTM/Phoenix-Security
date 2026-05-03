#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// HeuristicScanner  —  Antivirus Module 2
//
// HOW IT WORKS:
//   Runs on every file that PASSED Module 1 (no hash match)
//   Scores each file across 6 checks
//   If total score >= 5  →  the file gets quarantined
//
// SCORE TABLE:
//   Check 1 - File name matches malware names        3 pts
//   Check 2 - File content has suspicious strings    3 pts
//   Check 3 - Double extension  e.g. photo.jpg.exe   3 pts
//   Check 4 - Located in a high-risk directory       2 pts
//   Check 5 - Executable in non-standard location    2 pts
//   Check 6 - Ransomware keyword in file name        2 pts
//
// Dependencies: none (reads file bytes directly)
// ─────────────────────────────────────────────

class HeuristicScanner {
public:

    // Quarantine threshold — files scoring 5 or above get quarantined
    static const int THRESHOLD = 5;

    // Runs all 6 checks on a file and returns the total suspicion score
    int scoreFile(string fname);

    // Returns true if the file's score is >= THRESHOLD
    bool shouldQuarantine(string fname);

private:

    // ── The 6 individual checks ───────────────────────────────────────────
    // Each returns its point value if triggered, or 0 if not triggered

    // Check 1: File name contains known malware name strings  (3 pts)
    int checkVirusName(string fname);

    // Check 2: File content contains suspicious byte strings  (3 pts)
    int checkSuspiciousContent(string fname);

    // Check 3: Double extension like  invoice.pdf.exe         (3 pts)
    int checkDoubleExtension(string fname);

    // Check 4: File is inside a risky directory               (2 pts)
    int checkSuspiciousLocation(string fname);

    // Check 5: Executable extension outside Program Files     (2 pts)
    int checkExecutableRisk(string fname);

    // Check 6: Ransomware keyword in the file name            (2 pts)
    int checkVirusKeyword(string fname);

    // Helper: converts a string to all lowercase for case-insensitive checks
    string toLower(string str);

};