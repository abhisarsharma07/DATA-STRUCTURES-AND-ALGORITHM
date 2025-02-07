//IMP
#include<iostream>
using namespace std;
int main()
{
     int i=1;
     int n;
     cin>>n;
     while(i<=n){
          int j=1;
          while(j<=n){
            char ch= 'A' + i + j -2;
            cout<<ch;
            ch++;
            j++;
          }
          cout<<endl;
          i++;
     }
    return 0;
}