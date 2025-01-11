#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

// Define all 7-segment displays for digits, operators, and brackets
map<string, char> segmentToChar = {
    {"._.|.||_|", '0'},
    {".....|..|", '1'},
    {"._.._||_.", '2'},
    {"._.._|._|", '3'},
    {"...|_|..|", '4'},
    {"._.|_.._|", '5'},
    {"._.|_|.|_", '6'},
    {"._...|..|", '7'},
    {"._.|_||_|", '8'},
    {"._.|_|..|", '9'},
    {"....._.|.", '+'},
    {"....._.|_", '-'},
    {".....|.|.", '*'},
    {".....|_|.", '/'},
    {"....._.|.", '='},
    {".....|..", '('},
    {"....._|_", ')'},
};

// Function to evaluate the expression following BODMAS rules
int evaluate(const string &expr) {
    vector<int> values;
    vector<char> ops;

    auto applyOperation = [](int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    };

    for (size_t i = 0; i < expr.size(); ++i) {
        if (isdigit(expr[i])) {
            int val = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                ++i;
            }
            --i;
            values.push_back(val);
        } else if (expr[i] == '(') {
            ops.push_back('(');
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.back() != '(') {
                int b = values.back(); values.pop_back();
                int a = values.back(); values.pop_back();
                char op = ops.back(); ops.pop_back();
                values.push_back(applyOperation(a, b, op));
            }
            ops.pop_back();
        } else {
            while (!ops.empty() && ops.back() != '(' &&
                   ((expr[i] == '+' || expr[i] == '-') || (expr[i] == '*' || expr[i] == '/'))) {
                int b = values.back(); values.pop_back();
                int a = values.back(); values.pop_back();
                char op = ops.back(); ops.pop_back();
                values.push_back(applyOperation(a, b, op));
            }
            ops.push_back(expr[i]);
        }
    }

    while (!ops.empty()) {
        int b = values.back(); values.pop_back();
        int a = values.back(); values.pop_back();
        char op = ops.back(); ops.pop_back();
        values.push_back(applyOperation(a, b, op));
    }

    return values.back();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> input(3);
        for (int i = 0; i < 3; ++i) {
            cin >> input[i];
        }

        vector<string> segments(n);
        for (int i = 0; i < n; ++i) {
            segments[i] = input[0].substr(3 * i, 3) + input[1].substr(3 * i, 3) + input[2].substr(3 * i, 3);
        }

        string lhs = "", rhs = "";
        int equalIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (segmentToChar[segments[i]] == '=') {
                equalIdx = i;
                break;
            }
            lhs += segmentToChar[segments[i]];
        }
        for (int i = equalIdx + 1; i < n; ++i) {
            rhs += segmentToChar[segments[i]];
        }

        int lhsValue = evaluate(lhs);
        int rhsValue = evaluate(rhs);

        if (lhsValue == rhsValue) {
            cout << "Perfect" << endl;
            continue;
        }

        bool found = false;
        for (int i = 0; i < n; ++i) {
            string original = segments[i];

            for (const auto &[key, value] : segmentToChar) {
                if (key == original) continue;
                if (segmentToChar.count(key) && segmentToChar[key] == '=') continue; // Skip '=' character

                segments[i] = key;
                
                // Evaluate LHS and RHS only once, avoid redundant calculations
                string tempLhs = lhs, tempRhs = rhs;

                if (i < equalIdx) {
                    tempLhs[i * 3] = value;
                } else {
                    tempRhs[(i - equalIdx - 1) * 3] = value;
                }

                int tempLhsValue = evaluate(tempLhs);
                int tempRhsValue = evaluate(tempRhs);

                if (tempLhsValue == tempRhsValue) {
                    cout << i << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
            segments[i] = original;
        }
    }

    return 0;
}
