#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

struct Building {
    int x, y, r;
};

struct TaxLine {
    int from, to;
};

struct Vehicle {
    int x, y, r;
};

bool overlaps(const Building &b1, const Building &b2) {
    double distance = sqrt((b1.x - b2.x) * (b1.x - b2.x) + (b1.y - b2.y) * (b1.y - b2.y));
    return distance < (b1.r + b2.r);
}

bool crossesTaxLine(const Vehicle &v, const Building &b1, const Building &b2) {
    // Check if the line between b1 and b2 is crossed by the vehicle
    double x1 = b1.x, y1 = b1.y;
    double x2 = b2.x, y2 = b2.y;
    double vx = v.x, vy = v.y, vr = v.r;

    // Equation of line (x1, y1) to (x2, y2)
    double A = y2 - y1;
    double B = x1 - x2;
    double C = x2 * y1 - x1 * y2;

    // Distance from vehicle's center to the line
    double distance = abs(A * vx + B * vy + C) / sqrt(A * A + B * B);

    return distance < vr;
}

int main() {
    int S, startX, startY, startR, endX, endY, N, T;

    cin >> S;
    cin >> startX >> startY >> startR;
    cin >> endX >> endY;
    cin >> N;

    vector<Building> buildings(N);
    for (int i = 0; i < N; ++i) {
        cin >> buildings[i].x >> buildings[i].y >> buildings[i].r;
    }

    cin >> T;
    vector<TaxLine> taxLines(T);
    for (int i = 0; i < T; ++i) {
        cin >> taxLines[i].from >> taxLines[i].to;
    }

    Vehicle vehicle = {startX, startY, startR};
    if (startX == endX && startY == endY) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    vector<bool> visited(N + 1, false);
    q.push({startX, startY});

    while (!q.empty()) {
        auto [currX, currY] = q.front();
        q.pop();

        for (int i = 0; i < N; ++i) {
            if (visited[i]) continue;

            Building &building = buildings[i];
            if (overlaps(building, {currX, currY, startR})) continue;

            visited[i] = true;
            for (int j = 0; j < T; ++j) {
                if (taxLines[j].from == i || taxLines[j].to == i) {
                    int other = taxLines[j].from == i ? taxLines[j].to : taxLines[j].from;
                    if (!visited[other]) {
                        q.push({buildings[other].x, buildings[other].y});
                    }
                }
            }

            if (crossesTaxLine(vehicle, building, {endX, endY, 0})) {
                cout << "Impossible" ;
                return 0;
            }
        }
    }

    cout << "2"; 
    return 0;
}
