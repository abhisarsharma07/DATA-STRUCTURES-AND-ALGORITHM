#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int i=0;
    void reverseArray(vector<int> &arr) {
        // code here
    /* int l=0,r=arr.size()-1;
     if(l>=r){
         return;
     }
     swap(arr[l],arr[r]);
     l++;
     r--;
     reverseArray(arr);
    }
    */
    if(i>=arr.size()/2){
        return;
    }
    swap(arr[i],arr[arr.size()-i-1]);
    i++;
    reverseArray(arr);

    }
    };
    int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}