#include<iostream>
using namespace std;
void reverse(int arr[],int n){
int s=0;
int e=n-1;
//code of swap
     while(s<e){
     int temp=arr[s];
     arr[s]=arr[e];
     arr[e]=temp;
     s++;
     e--;
    

}
}
int main(){

int arr[]={10,20,30,40,50,60,70,80,90};
    int n=9;
    reverse(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}