#include<iostream>
using namespace std;
class Abhi{
public:
int data;
Abhi* next;
  Abhi(int data){
     this->data=data;
  }

};
int main(){
/*
     int b=5;
     int *ptr=&b;
     int *ptr2=ptr;
     cout<<ptr<<endl;//0x61ff04
     cout<<*ptr<<endl;//5
     cout<<ptr2<<endl;//0x61ff04
     cout<<*ptr2<<endl;//5
*/
Abhi* node = new Abhi(10);
cout<<node->data<<endl;

}