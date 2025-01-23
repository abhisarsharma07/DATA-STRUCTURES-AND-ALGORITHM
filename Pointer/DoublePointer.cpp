#include<iostream>
using namespace std;
int main(){
int i=5;
int *ptr=&i;
int **ptr2=&ptr;
cout<<ptr<<endl;//same
cout<<&ptr<<endl;
cout<<*ptr2<<endl;//same
//same
cout<<i<<endl;//samee
cout<<*ptr<<endl;//samee
cout<<**ptr2<<endl;//samee
//same
cout<<&ptr<<endl;//sameeee
cout<<ptr2<<endl;//sameeee


}