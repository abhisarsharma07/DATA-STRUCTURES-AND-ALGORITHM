#include<iostream>
using namespace std;
void Count(int arr[],int n){
     int count0=0;
     int count1=0;
for(int i=0;i<n;i++){
if(arr[i]==0){
     count0++;
}
if(arr[i]==1){
     count1++;
}
}
cout<<"No of 0's in this Array are:"<<count0<<endl;
cout<<"No of 1's in this Array are:"<<count1;
}
int main(){
int arr[]={0,1,4,6,0,1,0,1,2,3,1};
Count(arr,11);
return 0;
}