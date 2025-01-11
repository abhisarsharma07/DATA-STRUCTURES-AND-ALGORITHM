#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

// Helper function to parse input
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> switchCount;

    // Read conveyor belt system
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        vector<string> parts = split(line, ' ');
        string junction = parts[0];
        for (size_t j = 1; j < parts.size(); j++) {
            graph[parts[j]].push_back(junction);
        }
        switchCount[junction] = 0;
    }

    // Read sequence of goods and costs
    string goodsLine;
    getline(cin, goodsLine);
    vector<string> goods = split(goodsLine, ' ');

    string costsLine;
    getline(cin, costsLine);
    vector<string> costStrings = split(costsLine, ' ');
    vector<int> costs;
    for (const string &costStr : costStrings) {
        costs.push_back(stoi(costStr));
    }

    int K;
    cin >> K;

    unordered_map<string, string> currentPaths; // Tracks current open path for each junction
    int manualCost = 0;

    // Process each good
    for (size_t i = 0; i < goods.size(); i++) {
        string source = goods[i];
        queue<string> q;
        unordered_set<string> visited;
        q.push(source);
        visited.insert(source);
        bool pathAvailable = true;

        // Traverse to warehouse
        while (!q.empty() && pathAvailable) {
            string node = q.front();
            q.pop();

            if (graph.find(node) != graph.end()) {
                for (const string &next : graph[node]) {
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);

                        // Check if we need to switch the path
                        if (currentPaths[next] != node) {
                            if (switchCount[next] < K) {
                                currentPaths[next] = node;
                                switchCount[next]++;
                            } else {
                                pathAvailable = false;
                                break;
                            }
                        }

                        q.push(next);
                    }
                }
            }
        }

        // If path is not available, add manual cost
        if (!pathAvailable) {
            manualCost += costs[i];
        }
    }

    // Output the total manual cost
    cout << manualCost;

    return 0;
}
