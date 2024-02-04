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

Node* add(Node* head1, Node* head2) {

    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(head1 != NULL || head2 != NULL || carry != 0) {

        int value1 = 0;
        if(head1 != NULL) {
            value1 = head1->data;
        }

        int value2 = 0;
        if(head2 != NULL) {
            value2 = head2->data;
        }

        int sum = value1 + value2 + carry;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        if(head1 != NULL) {
            head1 = head1->next;
        }

        if(head2 != NULL) {
            head2 = head2->next;
        }
    }
    return ansHead;
}

int main() {

    int n1;
    cout << "Enter size of list 1: ";
    cin >> n1;

    Node* head1 = NULL;
    Node* tail1 = NULL;

    for(int i=0; i<n1; i++) {
        int digit;
        cin >> digit;
        insertAtTail(head1, tail1, digit);
    }
    
    int n2;
    cout << "Enter size of list 2: ";
    cin >> n2;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    for(int i=0; i<n2; i++) {
        int digit;
        cin >> digit;
        insertAtTail(head2, tail2, digit);
    }
    
    Node* ans = add(head1, head2);
    print(ans);

    return 0;
}