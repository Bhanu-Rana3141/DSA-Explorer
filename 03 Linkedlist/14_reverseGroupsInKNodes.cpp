/*
APPROACH 1 - RECURSIVE APPROACH
* Reverse first k nodes
* Baaki recursion sambhal lega
* TC - O(N)
* SC - O(N)

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

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
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

// Recursive Approach
Node* reverseKGroup(Node* head, int k) {
    // Base case
    if(head == NULL) {
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL) {
        head->next = reverseKGroup(forward, k);
    }

    return prev; 
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        insertAtTail(head, tail, input);
    }

    cout << "Linkedlist: ";
    print(head);

    int k;
    cout << "Enter k: ";
    cin >> k;

    Node* res = reverseKGroup(head, k);
    print(res);

    return 0;
}