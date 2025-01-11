#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

struct LogEntry {
    int employeeID;
    string activity;
    string location;
    int timeInMinutes; // Time converted to minutes since midnight
};

// Function to convert time string (e.g., "9:01AM") to minutes since midnight
int convertTimeToMinutes(const string &timeStr) {
    int hours, minutes;
    char colon, meridian;
    stringstream ss(timeStr);

    ss >> hours >> colon >> minutes >> meridian;

    if (meridian == 'P' && hours != 12) {
        hours += 12;
    } else if (meridian == 'A' && hours == 12) {
        hours = 0;
    }

    return hours * 60 + minutes;
}

int main() {
    // Input example: number of log entries and the logs
    int n = 10; // Example input
    vector<string> logs = {
        "101 enters cafeteria1 9:01AM",
        "101 exits cafeteria1 10:17AM",
        "154 enters room5 9:15AM",
        "153 enters room4 11:40AM",
        "153 enters pantry2 2:00PM",
        "101 enters room4 12:01PM",
        "154 exits room5 1:05PM",
        "153 exits pantry2 4:00PM",
        "153 enters room4 10:16AM",
        "101 exits room4 1:25PM"
    };
    int suspectEmployeeID = 153; // Example suspect

    // Parse logs into structured format
    vector<LogEntry> logEntries;
    for (const string &log : logs) {
        stringstream ss(log);
        LogEntry entry;
        string timeStr;
        ss >> entry.employeeID >> entry.activity >> entry.location >> timeStr;
        entry.timeInMinutes = convertTimeToMinutes(timeStr);
        logEntries.push_back(entry);
    }

    // Process logs to calculate actual work times
    unordered_map<int, int> workTimes; // Total work time for each employee
    unordered_map<int, vector<pair<int, int>>> roomTimes; // Entry and exit times in rooms

    for (const LogEntry &entry : logEntries) {
        if (entry.location.find("room") != string::npos) {
            if (entry.activity == "enters") {
                roomTimes[entry.employeeID].push_back({entry.timeInMinutes, -1});
            } else if (entry.activity == "exits") {
                for (auto &timePair : roomTimes[entry.employeeID]) {
                    if (timePair.second == -1) {
                        timePair.second = entry.timeInMinutes;
                        workTimes[entry.employeeID] += timePair.second - timePair.first;
                        break;
                    }
                }
            }
        }
    }

    // Find employee with minimum work time
    int minWorkTime = INT_MAX;
    for (const auto &[id, time] : workTimes) {
        minWorkTime = min(minWorkTime, time);
    }

    // Check if the suspect is the employee with the least work time
    if (workTimes[suspectEmployeeID] == minWorkTime) {
        cout << "Yes" << endl;
    } else if (workTimes[suspectEmployeeID] != 0) {
        cout << "No" << endl;
    } else {
        cout << "Cannot be determined" ;
    }

    return 0;
}
