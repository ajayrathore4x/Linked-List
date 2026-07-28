#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
    return;
}
void insertAtTail(Node*& head,int value){
Node* newnode =new Node(value);
if(head == NULL) {
    head = newnode;
    return;
}
Node* temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newnode;
return;
}
void insertAtpositin(Node*& head,int value,int position){
    Node* newnode=new Node(value);
    if(position == 1){
    newnode->next = head;
    head = newnode;
    return;
}
    Node* temp=head;
    int count=1;
    while(temp != NULL){
    if(count == position-1){
        newnode->next = temp->next;
        temp->next = newnode;
        return;
    }

    temp = temp->next;
    count++;
}
return;
}
int main(){
     Node* head = new Node(10);

    Node* second = new Node(20);

    Node* third = new Node(30);

    head->next = second;
    second->next = third;
   
    //insertAtHead(head,5);
    insertAtTail(head,40);
    insertAtMiddle(head,25,3);

    printList(head);
    return 0;
}