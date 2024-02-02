/*
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

void insertAtTail(Node* &head, Node* &tail, int digit) {
    Node* newNode = new Node(digit);
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
        cout << head->data;
        head = head->next;
    }
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* addOne(Node* head) {

    Node* temp = reverse(head);
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    int val = temp->data + 1;
    int digit = val % 10;
    insertAtTail(ansHead, ansTail, digit);
    carry = val / 10;
    temp = temp->next;

    while(temp != NULL || carry != 0) {
        if(temp == NULL && carry != 0) {
            insertAtTail(ansHead, ansTail, carry);
            break;
        }

        val = 0;
        if(temp != NULL) {
            val = temp->data;
        }

        val += carry;
        digit = val % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = val / 10;

        temp = temp->next;
    }
    ansHead = reverse(ansHead);
    return ansHead;
}

int main() {

    int n;
    cout << "Enter size of list: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0; i<n; i++) {
        int digit;
        cin >> digit;
        insertAtTail(head, tail, digit);
    }
    
    Node* ans = addOne(head);
    print(ans);

    return 0;
}