#include<iostream>
using namespace std;
void update(int **p2){
   //check baari baari
p2=p2+1;//No change
// *p=*p+1;
// **p=**p+1;
}
int main(){

    int i = 5;
    int* p = &i;
    int** p2 = &p;

    cout << endl << endl;
    cout<< "before " << i << endl;
    cout<< "before " << p << endl;
    cout<< "before " << p2 << endl;
    update(p2);
    cout<< "after " << i << endl;
    cout<< "after " << p << endl;
    cout<< "after " << p2 << endl;
}