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
void InsertAtTail(Node* &tail,int d){
Node*temp=new Node(d);
tail->next =temp;
tail=tail->next;
}

void print(Node* &head){
     Node* temp=head;
     while(temp!=NULL){
          cout<<temp->data<<" ";
          temp= temp->next;
     }
     cout<<endl;
}
int main(){
Node* node1=new Node(10); //node Creation
// cout<<node1 -> data<<endl;//accessing data
// cout<<node1 -> next<<endl;//accessing next pointerr

Node* head=node1;
Node* tail=node1;

 print(head);
 InsertAtTail(tail,12);
 print(head);
     return 0;
}  