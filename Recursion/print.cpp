//Print 1 To N Without Loop
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Complete this function
    int count=0;
    void printNos(int n) {
        if(count==n){
        return;
        }
        count++;
        cout<<count<<" ";
        printNos(n);
        }
    };
    int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}