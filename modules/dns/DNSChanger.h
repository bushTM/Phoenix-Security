#pragma once
#include <string>
#include <vector>

using namespace std;

// ─────────────────────────────────────────────
// DNSEntry
// One preset DNS provider (loaded from DNS.json)
// ─────────────────────────────────────────────
struct DNSEntry {
    string name;       // display name  e.g. "Google"
    string primary;    // primary DNS   e.g. "8.8.8.8"
    string secondary;  // secondary DNS e.g. "8.8.4.4"
};


// ─────────────────────────────────────────────
// DNSChanger
// Reads and changes Windows DNS settings via netsh
//
// HOW IT WORKS:
//   Your C++ code runs netsh commands using _popen()
//   netsh talks directly to Windows and changes the DNS
//   on all active network adapters (Wi-Fi, Ethernet etc.)
//
// IMPORTANT: Changing DNS requires Administrator rights
//   The user must run Phoenix Security as Administrator
//   for the DNS feature to work
//
// Dependencies: Logger
// ─────────────────────────────────────────────

class DNSChanger {
public:

    // Loads preset DNS providers from DNS.json
    // fname = full path to data/config/DNS.json
    vector<DNSEntry> getPresets(string fname);

    // Applies DNS settings to all active network adapters
    // primary   = e.g. "8.8.8.8"
    // secondary = e.g. "8.8.4.4"
    // Returns true if all adapters were updated successfully
    bool setDNS(string primary, string secondary);

    // Restores all adapters back to automatic (DHCP) DNS
    // Returns true if successful
    bool restoreToDefault();

    // Checks if a string is a valid IPv4 address
    // e.g. "8.8.8.8" → true    "999.1.1" → false    "abc" → false
    bool isValidIPv4(string address);

    // Returns the current DNS of the first active adapter
    // Used to show the current settings in the GUI
    string getCurrentDNS();

private:

    // Returns names of all active network adapters on this machine
    // e.g.  {"Wi-Fi", "Ethernet"}
    vector<string> getActiveAdapters();

    // Runs a shell command and returns its console output as a string
    // Example:  runCommand("netsh interface show interface")
    string runCommand(string command);

};