#include<iostream>
using namespace std;
int main(){
     int num=5;
     cout<<num<<endl;
     cout<<&num<<endl;

     int *ptr=&num;
     cout<<*ptr<<endl;
     cout<<ptr<<endl;

     int a= *ptr;
     a++;

     cout<<num<<endl;
     cout<<a<<endl;
     
     cout<<(*ptr)++<<endl;
     cout<<num<<endl;

     int *q=ptr;
     cout<<ptr<<"-"<<q<<endl;
     cout<<*ptr<<"-"<<*q<<endl;
     return 0;
}