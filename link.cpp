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
int length(Node* head){
   // if(head==NULL) return 0;
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
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

    while(fast != NULL && fast->next != NULL&& fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
bool detectCycle(Node* head){
    Node* slow = head;
Node* fast = head;

while (fast != NULL && fast->next != NULL) {

    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
        return true;
    }
}

return false;
}
Node* detectCyclePoint(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            Node* ptr = head;

            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }

            return ptr;
        }
    }

    return NULL;
}
Node* mergetwolists(Node* l1,Node* l2){
    Node* dummy=new Node(-1);
    Node* tail=dummy;
    while(l1 != NULL&&l2!=NULL){
    if(l1->data <=l2->data){
        tail->next=l1;
        tail=l1;
        l1=l1->next;
    }
    else{
        tail->next=l2;
        tail=l2;
        l2=l2->next;
    }
}
    if(l1!=NULL) tail->next=l1;
    else tail->next=l2;

    return dummy->next;
    
}
Node* removeNthFromEnd(Node* head, int n) {
Node* dummy=new Node(-1);
dummy->next=head;
Node*slow=dummy;
Node* fast=dummy;
for(int i=0;i<=n;i++){
fast = fast->next;
}
while(fast!=NULL){
    slow=slow->next;
    fast=fast->next;
}
Node* nodetodelete=slow->next;
slow->next=slow->next->next;
delete nodetodelete;

return dummy->next;
}
int main(){
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);

    head->next=second;
    second->next=third;
    third->next=fourth;


    printList(head);

    return 0;
}