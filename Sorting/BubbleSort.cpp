#include<iostream>
using namespace std;
void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
     for(int j=0;j<n-1;j++){
          if(arr[j]>arr[j+1]){
          swap(arr[j],arr[j+1]);
          }
     }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
int arr[5]={2,5,1,0,0};
printArray(arr,5);
BubbleSort(arr,5);
printArray(arr,5);
return 0;
}