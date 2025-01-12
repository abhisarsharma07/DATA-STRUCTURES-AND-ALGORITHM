#include<iostream>
using namespace std;
int raja=420;//global variable
int main(){
//variable scoping

//decleration
int a;
//initialization
int b=5;
//updation
b=10;

//int b=6; we can not define again that

if(true){//yeh wala b bas isi case tak defined hai
     int b=15;
     cout<<b;
     int raja=421;
}

cout<<b;

}

