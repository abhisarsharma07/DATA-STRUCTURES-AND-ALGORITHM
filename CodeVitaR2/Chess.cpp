#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

// Function to convert board position to a string
string positionToString(char piece, char col, char row) {
    return string(1, piece) + col + row;
}

// Function to generate possible moves for each piece
set<string> generatePossibleMoves(char piece, char col, char row) {
    set<string> possibleMoves;
    int colIndex = col - 'A';
    int rowIndex = row - '1';

    if (piece == 'Q') {
        // Queen moves like both a Rook and Bishop
        // Rook-like moves
        for (int i = 0; i < 8; ++i) {
            if (i != colIndex) possibleMoves.insert(positionToString(piece, char('A' + i), row));
            if (i != rowIndex) possibleMoves.insert(positionToString(piece, col, char('1' + i)));
        }
        // Bishop-like moves
        for (int i = -7; i <= 7; ++i) {
            if (colIndex + i >= 0 && colIndex + i < 8 && rowIndex + i >= 0 && rowIndex + i < 8) {
                if (i != 0) possibleMoves.insert(positionToString(piece, char('A' + colIndex + i), char('1' + rowIndex + i)));
            }
        }
    } else if (piece == 'R') {
        // Rook moves (can move in straight lines)
        for (int i = 0; i < 8; ++i) {
            if (i != colIndex) possibleMoves.insert(positionToString(piece, char('A' + i), row));
            if (i != rowIndex) possibleMoves.insert(positionToString(piece, col, char('1' + i)));
        }
    } else if (piece == 'B') {
        // Bishop moves diagonally
        for (int i = -7; i <= 7; ++i) {
            if (colIndex + i >= 0 && colIndex + i < 8 && rowIndex + i >= 0 && rowIndex + i < 8) {
                if (i != 0) possibleMoves.insert(positionToString(piece, char('A' + colIndex + i), char('1' + rowIndex + i)));
            }
        }
    }
    return possibleMoves;
}

int main() {
    string input;
    getline(cin, input);
    vector<string> pieces;
    size_t pos = 0;
    while ((pos = input.find(" ")) != string::npos) {
        pieces.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    pieces.push_back(input); // For the last piece
    int d;
    cin >> d;

    set<string> uniquePositions;
    for (const string& piecePos : pieces) {
        char piece = piecePos[0];
        char col = piecePos[1];
        char row = piecePos[2];

        // Generate initial possible moves for each piece
        set<string> possibleMoves = generatePossibleMoves(piece, col, row);
        
        // If the depth is 1, we just count the unique moves directly
        if (d == 1) {
            uniquePositions.insert(possibleMoves.begin(), possibleMoves.end());
        } else {
            // If depth is greater than 1, we need to calculate the moves for the next ply
            set<string> tempPositions = uniquePositions;
            for (const string& pos : possibleMoves) {
                char newPiece = pos[0];
                char newCol = pos[1];
                char newRow = pos[2];
                // We generate new positions recursively for the next depth
                set<string> nextMoves = generatePossibleMoves(newPiece, newCol, newRow);
                tempPositions.insert(nextMoves.begin(), nextMoves.end());
            }
            uniquePositions = tempPositions;
        }
    }

    // Output the number of unique positions
    cout << uniquePositions.size() << endl;
    return 0;
}
