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
int main(){
     Node* head = new Node(10);

    Node* second = new Node(20);

    Node* third = new Node(30);

    head->next = second;
    second->next = third;

    printList(head);
    return 0;
}