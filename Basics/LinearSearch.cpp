#include<iostream>
using namespace std;
int main(){
     int arr[]={1,2,3,4,5,6,7,8};
     int n=8;
     int key=5;
     bool flag=0;
     for(int i=0;i<n;i++){
          if(arr[i]==key){
               cout<<"found"<<endl;
               flag=1;
          }
     }
     if(flag)
     cout<<"Present"<<endl;
     else
     cout<<"Absent"<<endl;
}