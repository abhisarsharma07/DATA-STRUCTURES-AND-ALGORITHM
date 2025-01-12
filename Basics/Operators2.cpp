#include<iostream>
using namespace std;
int main(){
     bool a= false;
     bool b=true;
     cout<<(~a)<<endl;
     cout<<(a^b);
//a=(~a)
//a=~(a)
     cout<<(2 & 3);
     cout<<(5 & 10);

//shifting left and right 
int c=12;
c=c<<1; 
cout<<c;   

//pre and post increment
int d=5;
cout<<++d;
int e=6;
cout<<e++<<endl;


int f=5;
cout<<(++f)*(++f);
}