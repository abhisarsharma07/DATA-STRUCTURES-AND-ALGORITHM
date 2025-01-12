#include<iostream>
using namespace std;
char GetGrade(int marks){//we can write it through switch case
     if(marks>=90)
     return 'A';
     else if(marks>=80)
     return 'B';
     else if(marks>=70)
     return 'C';
     else if(marks>=60)
     return 'D';
     else
     return 'E';
}
int main(){
     int marks;
     cout<<"enter the marks"<<endl;
     cin>>marks;
     char finalGrade= GetGrade(marks);
     cout<<finalGrade;
     return 0;
     }
     