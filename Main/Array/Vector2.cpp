#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>v){
    int size=v.size();
    cout<<"printing vector: "<<endl;
    for(int i=0; i<size;i++){
        cout<<v[i]<< endl;
    }
}

int main(){

     vector<int>v;
         v.push_back(1);
          v.push_back(10);
           v.push_back(100);//peeche dalo
          print(v);
          v.pop_back();//peeche se nikalo
          print(v);
           return 0;
}