#include<iostream>
using namespace std;
void linearSearch(int arr[],int n,int key){
     for(int i=0;i<n;i++){
          if(arr[i]==key){
               cout<<"Key is present"<<endl;
               cout<<"Index at which key is present:"<<i;
          }
     }
}
int main(){
     int arr[100],size;
     cin>>size;
     for(int i=0;i<size;i++){
          cin>>arr[i];
     }
     linearSearch(arr,size,5);
     return 0;
}