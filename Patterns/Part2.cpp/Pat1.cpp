/*
1
2 1
3 2 1 
4 3 2 1
*/
// JAB BHI ULTA HO TO n-j+1 sochna 

//without count so we can do cout<<i-j+1; okkk
#include<iostream>
using namespace std;
int main()
{
     int n;
     cin>>n;
     int i=1;
     while(i<=n)
          {
               int j=1;
               int count=i;
               while(j<=i){
                 cout<<count<<" ";
                 j++;
                 count--;
               }
               cout<<endl;
               i++;
          }
    return 0;
}