/*
1 2 3 
4 5 6 
7 8 9 
*/
#include<iostream>
using namespace std;
//count INTRODUCED
int main(){
     int n;
     cin>>n;
     int i=1;
     int cnt=1;
     while(i<=n){
         int j=1;
         while(j<=n){
          cout<<cnt<<" ";
          cnt++;
          j++;
         }
         cout<<endl;
         i++;
     }
}