#include<iostream>
using namespace std;
void printName(){
     int n;
     cin>>n;
     for(int i=0;i<n;i++){
          cout<<"hi"<<endl;
     }
}
int add(int a,int b){
     int result=a+b;
     return result;
}
     

int main(){

     //printName();
     int a;
     cin>>a;
     int b;
     cin>>b;
   int sum=  add(a,b);
    cout<<sum<<endl;
}