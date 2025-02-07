#include<iostream>
using namespace std;
int main()
{
     int n;
     cin>>n;
     int i=1;
    int k=1;
     
     while(i<=n){
           int j=1;
          while (j<=i)
          {
            char ch='A'+ k -1;
             cout<<ch;
             k++;
             j++;
          }
          cout<<endl;
          i++;

     }
    return 0;
}