#include "DNSChanger.h"
#include "../../utility/Logger.h"
#include <fstream>
#include <sstream>

using namespace std;

// Loads DNS presets from DNS.json
// Expected JSON format:
// [
//   { "name": "Google",     "primary": "8.8.8.8",       "secondary": "8.8.4.4" },
//   { "name": "Cloudflare", "primary": "1.1.1.1",       "secondary": "1.0.0.1" },
//   { "name": "OpenDNS",    "primary": "208.67.222.222", "secondary": "208.67.220.220" }
// ]
vector<DNSEntry> DNSChanger::getPresets(string fname) {

}

// Applies DNS to all active adapters using netsh
bool DNSChanger::setDNS(string primary, string secondary) {


}

// Restores all adapters back to automatic (DHCP) DNS
bool DNSChanger::restoreToDefault() {

}

// Checks if a string is a valid dotted IPv4 address
bool DNSChanger::isValidIPv4(string address) {

}

// Returns the current DNS setting of the first active adapter
string DNSChanger::getCurrentDNS() {

}

// Returns names of all active (connected) network adapters
vector<string> DNSChanger::getActiveAdapters() {

}

// Runs a shell command and returns its output as a string
string DNSChanger::runCommand(string command) {

}