/*
ITERATIVE APPROACH
TC - O(N)
SC - O(1)

RECURSIVE APPROACH
TC - O(N)
SC - O(N)
*/

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(tail == NULL) {
        Node* newNode = new Node(data);
        head = NULL;
        tail = NULL;
    }
    else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ITERATIVE APPROACH
void reverseIterative(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// RECURSIVE APPROACH
void reverseRecursive(Node* &head, Node* &curr, Node* &prev) {
    if(curr == NULL) {
        head = prev;
        return;
    }

    reverseRecursive(head, curr->next, curr);
    curr->next = prev;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 3);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 9);

    cout << "linked list : ";
    print(head);
    
    // reverseIterative(head);

    Node* curr = head;
    Node* prev = NULL;
    reverseRecursive(head, curr, prev);

    cout << "Reversed Linked list: ";
    print(head);
    
    return 0;
}