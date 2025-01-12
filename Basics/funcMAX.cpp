#include<iostream>
using namespace std;
//a,b,c here is paameter
int MAX(int a,int b,int c){
     if(a>b && a>c){
          return a;
     }
     else if(b>a && b>c){
          return b;
     }
     else(c>a && c>b);{
          return c;
     }
}

int main(){

     int a,b,c;
     cin>>a>>b>>c;
     //a,b,c is arguement
int max= MAX(a,b,c);
cout<<max;


}