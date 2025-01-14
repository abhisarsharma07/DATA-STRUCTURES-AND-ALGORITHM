#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

// Structure to represent a polygon (earring)
struct Polygon {
    vector<Point> vertices;
};

// Function to calculate distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to calculate the distances between consecutive vertices of a polygon
vector<double> calculateDistances(const Polygon& polygon) {
    int n = polygon.vertices.size();
    vector<double> distances;
    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;  // Wrap around the end of the polygon
        distances.push_back(distance(polygon.vertices[i], polygon.vertices[next]));
    }
    return distances;
}

// Function to check if two polygons are identical, considering rotations
bool arePolygonsEqual(const Polygon& p1, const Polygon& p2) {
    if (p1.vertices.size() != p2.vertices.size()) {
        return false;
    }

    vector<double> distances1 = calculateDistances(p1);
    vector<double> distances2 = calculateDistances(p2);
    int n = distances1.size();

    // Try all possible rotations of distances2 and check for equality
    for (int start = 0; start < n; ++start) {
        bool match = true;
        for (int i = 0; i < n; ++i) {
            if (abs(distances1[i] - distances2[(start + i) % n]) > 1e-10) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;
    vector<Polygon> earrings(N);

    // Input polygons
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;  // Corrected this line
        earrings[i].vertices.resize(K);
        for (int j = 0; j < K; j++) {
            cin >> earrings[i].vertices[j].x >> earrings[i].vertices[j].y;
        }
    }

    // Find matching pair
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arePolygonsEqual(earrings[i], earrings[j])) {
                cout << i + 1 << " " << j + 1 ;
                return 0;
            }
        }
    }

    return 0;
}
