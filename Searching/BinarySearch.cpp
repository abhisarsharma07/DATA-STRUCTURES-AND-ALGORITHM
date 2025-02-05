#include<iostream>
using namespace std;
int BinarySearch(int arr[],int n,int key){
     int s=0;
     int e=n-1;
     int mid=s+(e-s)/2;
 
     while(s<=e){
          if(arr[mid]>key){
               e=mid-1;
          }
          else if(arr[mid]<key){
               s=mid+1;
          }
          else if(arr[mid]==key){
               return mid;
          }
          mid=s+(e-s)/2;
     }
     return -1;
}
int main(){
   int arr[5]={1,2,5,6,7};
   int ans= BinarySearch(arr,5,5);
   cout<<ans;
   return 0;
}