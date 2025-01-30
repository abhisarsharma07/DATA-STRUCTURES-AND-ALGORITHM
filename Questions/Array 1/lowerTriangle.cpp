
#include<iostream>
using namespace std;
//print all pairs
void printAllPairs(int arr[],int n){
    for(int i=0; i<n;i++){
        //for every i, we are running looping variable "j" from start to end
        for(int j=i;j<n;j++){
            cout<<arr[i]<<", "<<arr[j]<<endl;
        }
    }
}
int main(){
    int arr[]={10,20,30,40};
    int size=4;
    printAllPairs(arr,size);
    return 0;
}
//output
//10, 10
// 10, 20
// 10, 30
// 10, 40
// 20, 20
// 20, 30
// 20, 40
// 30, 30
// 30, 40
// 40, 40