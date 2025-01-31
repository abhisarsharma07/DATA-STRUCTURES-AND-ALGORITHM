//https://www.geeksforgeeks.org/vector-in-cpp-stl/
//Read Vectors from upper ink
#include <bits/stdc++.h>
using namespace std;
void printV(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
     vector<int>v={1,2,3,5,6};
     for(int i=0.;i<v.size();i++){
          cout<<v[i]<<' '<<endl;

     }
vector<int> v3(5, 9);
printV(v3);
     return 0;
}
//Syntax of Vector->vector<data Type> vec_name;
/*
1. Default Initialization-->>vector<T> vec_name;
2.Initialization with Size and Default Value-->>vector<T> vec_name(size, value); 
3. Initialization Using Initializer List-->>vector<T> vec_name = { v1, v2, v3….};
vector<T> vec_name ({ v1, v2, v3….});
*/