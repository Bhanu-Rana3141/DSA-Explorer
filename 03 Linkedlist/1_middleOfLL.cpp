/*
BRUTE - 
* CALCULATE LENGTH - O(N)
* FIND MIDDLE - O(N/2)
* TC - O(N)
* SC - O(1)

OPTIMISED 
* Take 2 pointer slow and fast, move slow with 1 step and fast with 2 steps
* TC - O(N/2) - O(N)
* SC - O(1)
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(tail == NULL) {
        Node* node1 = new Node(data);
        tail = node1;
        head = node1;
    }
    else{
        Node* node1 = new Node(data);
        tail->next = node1;
        tail = node1;
    }
    return;
}

void print(Node* &head) {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return;
}

int getLength(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// APPROACH 2 : TORTOISE - HAIR APPROACH
Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main() {
    
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        insertAtTail(head, tail, input);
    }

    cout << "Input Linked List: ";
    print(head);

    int length = getLength(head);
    cout << "Length of Linked list: " << length << endl;
    
    int mid = length/2;
    while(mid--) {
        head = head->next;
    }

    print(head);
    return 0;
}