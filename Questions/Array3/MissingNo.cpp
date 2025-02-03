//98 test cases pass
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]!=(nums[i]+1)){
            ans=(nums[i]+1);
          cout<<ans;
            }
        }
     
}    
int main(){
     vector<int>arr;
     arr.push_back(5);
     arr.push_back(6);
     arr.push_back(7);
     arr.push_back(9);
    missingNumber(arr);
   
     return 0;
}
//Xor Method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i <= n; i++) {
        xor1 ^= i; // XOR of all numbers from 0 to n
    }

    for (int num : nums) {
        xor2 ^= num; // XOR of elements in the array
    }

    return xor1 ^ xor2; // Missing number
    }
};