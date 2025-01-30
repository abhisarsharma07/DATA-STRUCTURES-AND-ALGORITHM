#include<iostream>
#include<limits.h>//for remove the error occuring while INT_MIN
using namespace std;
int findMax(int arr[],int n){
     int maxAns= INT_MIN;
for(int i=0; i<n;i++){
     if(arr[i]>maxAns){
          maxAns=arr[i];
     }
}
     return maxAns;

}
int main(){
  int arr[100];
    int size;
    cout<<"enter the number of elements: "<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"enter the input value for index: "<<i<<endl;
        cin>>arr[i];
    }
    cout<<"max number is: "<< findMax(arr,size)<<endl;
    return 0;

}