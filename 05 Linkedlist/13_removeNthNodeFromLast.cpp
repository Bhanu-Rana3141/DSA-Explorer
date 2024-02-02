#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void print(Node* head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
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

    
    
    return 0;
}