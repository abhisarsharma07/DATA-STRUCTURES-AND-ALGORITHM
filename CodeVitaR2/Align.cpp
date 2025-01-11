#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Instruction {
    string direction;
    int distance;
};

// Function to calculate the next coordinates based on the current direction
pair<int, int> getNextCoordinates(pair<int, int> current, string direction, int distance, char &facing) {
    if (direction == "straight") {
        if (facing == 'N') current.second += distance;
        else if (facing == 'S') current.second -= distance;
        else if (facing == 'E') current.first += distance;
        else if (facing == 'W') current.first -= distance;
    } else if (direction == "left") {
        if (facing == 'N') facing = 'W', current.first -= distance;
        else if (facing == 'S') facing = 'E', current.first += distance;
        else if (facing == 'E') facing = 'N', current.second += distance;
        else if (facing == 'W') facing = 'S', current.second -= distance;
    } else if (direction == "right") {
        if (facing == 'N') facing = 'E', current.first += distance;
        else if (facing == 'S') facing = 'W', current.first -= distance;
        else if (facing == 'E') facing = 'S', current.second -= distance;
        else if (facing == 'W') facing = 'N', current.second += distance;
    } else if (direction == "back") {
        if (facing == 'N') facing = 'S', current.second -= distance;
        else if (facing == 'S') facing = 'N', current.second += distance;
        else if (facing == 'E') facing = 'W', current.first -= distance;
        else if (facing == 'W') facing = 'E', current.first += distance;
    }
    return current;
}

int main() {
    int N;
    cin >> N;

    vector<Instruction> instructions(N);
    for (int i = 0; i < N; ++i) {
        cin >> instructions[i].direction >> instructions[i].distance;
    }

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    // Simulate the journey with the original instructions
    pair<int, int> current = start;
    char facing = 'N'; // Initially facing North
    for (const auto &inst : instructions) {
        current = getNextCoordinates(current, inst.direction, inst.distance, facing);
    }

    if (current == end) {
        cout << "Yes\n";
        return 0; // Already correct path
    }

    // Try correcting each instruction and see if it works
    for (int i = 0; i < N; ++i) {
        current = start;
        facing = 'N';
        for (int j = 0; j < N; ++j) {
            if (i == j) continue; // Skip the instruction to be corrected
            current = getNextCoordinates(current, instructions[j].direction, instructions[j].distance, facing);
        }

        // Try all possible corrections for the ith instruction
        vector<string> possibleTurns = {"left", "right", "straight", "back"};
        for (const string &correction : possibleTurns) {
            if (correction == instructions[i].direction) continue; // Skip if it's the same

            pair<int, int> correctedPos = current;
            char correctedFacing = facing;
            correctedPos = getNextCoordinates(correctedPos, correction, instructions[i].distance, correctedFacing);

            if (correctedPos == end) {
                cout << "Yes\n";
                cout << instructions[i].direction << " " << instructions[i].distance << "\n";
                cout << correction << " " << instructions[i].distance << "\n";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}
