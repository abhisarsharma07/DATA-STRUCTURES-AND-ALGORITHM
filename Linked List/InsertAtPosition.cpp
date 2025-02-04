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

void InsertAtHead(Node* &head,int d){//we dont want copy we want to create change in actual linked list
Node* temp=new Node(d);//create a new node
temp->next=head;//temp ka next points to head
head=temp;

}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
Node* temp=head;
int cnt=1;
//Insert At Start
if(position==1){
     InsertAtHead(head,d);
     return;
}//
//Insert at last
if(temp->next == NULL){
     InsertAtTail(tail,d);
}
while(cnt<position-1){
temp=temp->next;
cnt++;

}

//creating a node for d

Node* nodeToInsert =new Node(d);
nodeToInsert -> next=temp->next;
temp->next=nodeToInsert;
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
InsertAtTail(tail,15);
print(head);
   
insertAtPosition(tail,head,3,22); 
print(head);
insertAtPosition(tail,head,1,2);// i 
print(head);

cout<<"head "<<head->data<<endl;
cout<<"tail "<<tail->data<<endl;
  return 0;
}  