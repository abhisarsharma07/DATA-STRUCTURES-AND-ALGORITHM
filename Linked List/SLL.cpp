//Singly Linked List
#include<bits/stdc++.h>
using namespace std;
class Node{
     public://data types
     int data;
     Node* next;

     Node(int data){
          this->data=data;
          this->next=NULL;
     }
};
  
int main(){
Node* node1=new Node(); //node Creation
cout<<node1 -> data<<endl;//accessing data
cout<<node1 -> next<<endl;//accessing next pointerr
     return 0;
}  