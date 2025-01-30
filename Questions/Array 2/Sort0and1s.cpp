#include<iostream>
using namespace std;
void sortzeroOne(int arr[],int n){
    int zeroCount=0;
    int oneCount=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        if(arr[i]==1){
            oneCount++;
        }
    }
    for(int i=0;i<zeroCount;i++){
        arr[i]=0;
    }
    for(int i=zeroCount;i<n;i++){
        arr[i]=1;
    }
}
int main(){
  int arr[]={0,1,0,1,1,1,0,1,0,1};
  int size=10;
  sortzeroOne(arr,size);
for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}

//logic is good