#include<iostream>
using namespace std;
void TwoSum(int arr[],int n,int target){
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               if(arr[i]+arr[j]==target){
                    cout<<arr[i]<<","<<arr[j]<<endl;
               }
          }
     }
     return ;
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    int target=60;
   TwoSum(arr,size,target);
    return 0;
} 