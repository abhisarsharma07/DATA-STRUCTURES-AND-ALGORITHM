/*
1 
2 3 
3 4 5 
4 5 6 7 
*/

#include<iostream>
using namespace std;
//count
int main(){
     int n;
     cin>>n;
     int row=1;
     
     while(row<=n){
          int cnt=row;
          int col=1;
          while(col<=row){
           cout<<cnt<<" ";      
           cnt++;
           col++;
          }
          cout<<endl;
          row++;
     }
}