#include<iostream>
using namespace std;
int main(){
     int broNum;
     cin>>broNum;
     if(broNum==0)
     {
          cout<<"Baat Banjayegi"<<endl;
     }
     else{
          cout<<"Baat Nahi Banegi"<<endl;
     }
      int score;
      
    cout << "Enter your score between 0-100\n";
    cin >> score;
    /* Using if else ladder statement to print
       Grade of a Student */
    if(score >= 90){
        // Marks between 90-100 
        cout << "YOUR GRADE : A\n";
    } else if (score >= 70 && score < 90){
        // Marks between 70-89 
        cout << "YOUR GRADE : B\n";
    } else if (score >= 50 && score < 70){
        // Marks between 50-69 
        cout << "YOUR GRADE : C\n";
    } else {
        // Marks less than 50 
        // if none of the conditions is true
       cout << "YOUR GRADE : Failed\n";
    }
    // for loops
      for(int i=5;i>0;i=i-1)
     {
          cout<<"A";
     }
     for(int i=1;i<=5;i=i+2){
          cout<<i<<" "<<endl;
     }
     for(int i=1;i<=10;i=i+1){
          cout<<2*i<<" "<<endl;
     }
     for(int i=1;i<10;i=i*2)
     {
          cout<<i<<endl;
     }
     for(int i=100;i>0;i=i/2){
          cout<<i<<endl;
     }
     for(int i=5; (i>=0 && i<=10);i=i+1){
          cout<<i<<endl;
     }
}
