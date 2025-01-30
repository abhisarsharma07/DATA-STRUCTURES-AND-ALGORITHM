//Q.{10,20,30,40,50,60,70}=>
#include<iostream>
using namespace std;

void ExtremePrinting(int arr[],int n){
int s=0;
int e=n-1;
while(s<=e){
     cout<<arr[s]<<" "<<arr[e]<<" ";
     s++;
     e--;
     if(s==e){
          cout<<arr[s];
          break;
     }
}

}
int main(){
     int arr[]={10,20,30,40,50,60,70};
     int size=7;
     ExtremePrinting(arr,size);
     return 0;
}