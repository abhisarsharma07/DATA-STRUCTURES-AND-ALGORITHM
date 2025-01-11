#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <tuple> // Added include for std::tie
using namespace std;

struct Position {
    int x, y, z;
    Position(int x, int y, int z) : x(x), y(y), z(z) {}

    bool operator<(const Position &other) const {
        return tie(x, y, z) < tie(other.x, other.y, other.z);
    }
};

// Directions mapping
const vector<pair<string, Position>> directions = {
    {"u", Position(0, -1, 0)}, {"d", Position(0, 1, 0)},
    {"f", Position(1, 0, 0)},  {"b", Position(-1, 0, 0)},
    {"l", Position(0, 0, -1)}, {"r", Position(0, 0, 1)}};

Position move(Position pos, const string &dir) {
    for (const auto &d : directions) {
        if (d.first == dir) {
            return Position(pos.x + d.second.x, pos.y + d.second.y, pos.z + d.second.z);
        }
    }
    return pos;
}

set<Position> generateBand(Position start, const string &sequence) {
    set<Position> band;
    Position current = start;
    band.insert(current);

    for (char c : sequence) {
        string dir(1, c);
        current = move(current, dir);
        band.insert(current);
    }

    return band;
}

int checkOverlap(const set<Position> &band1, const set<Position> &band2) {
    int overlapCount = 0;

    for (const auto &pos : band1) {
        if (band2.count(pos)) {
            return -1; // Interlocked condition
        }
    }

    // Count overlaps where band1 is above band2
    for (const auto &pos1 : band1) {
        for (const auto &pos2 : band2) {
            if (pos1.x == pos2.x && pos1.y == pos2.y && pos1.z == pos2.z + 1) {
                overlapCount++;
            }
        }
    }

    return overlapCount;
}

int main() {
    int S;
    cin >> S;

    // Read Band 1 input
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    string seq1;
    cin >> seq1;

    // Read Band 2 input
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    string seq2;
    cin >> seq2;

    // Generate bands
    set<Position> band1 = generateBand(Position(x1, y1, z1), seq1);
    set<Position> band2 = generateBand(Position(x2, y2, z2), seq2);

    // Check for overlap
    int overlap = checkOverlap(band1, band2);

    if (overlap == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << overlap << endl;
    }

    return 0;
}
