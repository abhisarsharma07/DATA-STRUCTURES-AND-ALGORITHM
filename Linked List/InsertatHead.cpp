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
void InsertAtHead(Node* &head,int d){//we dont want copy we want to create change in actual linked list
Node* temp=new Node(d);//create a new node
temp->next=head;//temp ka next points to head
head=temp;

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
     
//head point to node 1
 Node* head =node1;

 print(head);
 InsertAtHead(head,12);
 print(head);
 return 0;
}  