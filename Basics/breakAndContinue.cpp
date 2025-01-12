#include<iostream>
using namespace std;
int main(){
     int n=5;
     for(int i=0;i<n;i++){
          cout<<"abhi";
          break;//immediately comes out of loop
     }
     cout<<"sar"<<endl;

     for(int i=0;i<n;i++){
     continue;//ye kabhi neeche jaane hi nahi dega dubara increment pe lejayega aur neeche wali kabhi execute nahi kar payega
     cout<<"abhi";
     
     }
    
}