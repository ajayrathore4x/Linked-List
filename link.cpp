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
void insertAtposition(Node*& head,int value,int position){
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
void insertAtposition1(Node*& head,int value,int position){
    Node* newnode=new Node(value);
    if(position == 1){
    newnode->next = head;
    head = newnode;
    return;
}
    Node* temp=head;
    int count=1;
    while (temp != NULL && count < position - 1) {
    temp = temp->next;
    count++;
  }
  if (temp == NULL) {
    return; // Invalid position
}

newnode->next = temp->next;
temp->next = newnode;
return;
}
void deletenode(Node*& head){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return;
}
void deleteTail(Node*& head) {

    if(head == NULL)
        return;

    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;

    temp->next = NULL;

    delete nodeToDelete;
}
void deleteAtPosition(Node*& head, int position) {

    if (head == NULL) {
        return;
    }

    if (position == 1) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return;
}
void searchinlinklist(Node* head,int value){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==value){
            cout<<"it exists"<<endl;
            return;
        }
        temp=temp->next;
    }
     cout<<"doesn't exist"<<endl;
     return;
}
void reverseList(Node*& head) {

    Node* previous = NULL;
    Node* current = head;
    Node* nextnode = NULL;
    while (current != NULL) {
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }
    head = previous;
}
Node* findMiddle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
int main(){
     Node* head = new Node(10);

    Node* second = new Node(20);

    Node* third = new Node(30);

    head->next = second;
    second->next = third;
   
    //insertAtHead(head,5);
    insertAtTail(head,40);
   // insertAtposition(head,25,3);
  // deleteAtPosition(head ,3);
  //reverseList(head);

    printList(head);
    return 0;
}