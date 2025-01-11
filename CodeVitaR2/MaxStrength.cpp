#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int main() {
    int rows, cols, initialStrength;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols)); // For strength
    vector<vector<int>> time(rows, vector<int>(cols)); // For time
    pair<int, int> start, end; // Start and end positions

    // Input grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char cell;
            cin >> cell;
            if (cell == 'S') start = {i, j}, grid[i][j] = 0; // Start
            else if (cell == 'D') end = {i, j}, grid[i][j] = 0; // Destination
            else grid[i][j] = cell - '0'; // Strength cost
        }
    }

    // Input time for each cell
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> time[i][j];
        }
    }

    // Input initial strength
    cin >> initialStrength;

    // Directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Priority queue for Dijkstra's algorithm
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    pq.push({0, start.first, start.second, initialStrength}); // {time, x, y, strength}

    vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
    minTime[start.first][start.second] = 0;

    while (!pq.empty()) {
        auto [currTime, x, y, strengthLeft] = pq.top();
        pq.pop();

        // If destination is reached
        if (make_pair(x, y) == end) {
            cout << currTime << " " << strengthLeft;
            return 0;
        }

        // Try moving in all 4 directions
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                int nextTime = currTime + time[nx][ny];
                int nextStrength = strengthLeft - 1 - grid[nx][ny];
                if (nextStrength >= 0 && nextTime < minTime[nx][ny]) {
                    minTime[nx][ny] = nextTime;
                    pq.push({nextTime, nx, ny, nextStrength});
                }
            }
        }
    }

    // If destination cannot be reached
    cout << "Not Possible" ;
    return 0;
}
