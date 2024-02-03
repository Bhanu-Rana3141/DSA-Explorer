/*

- APPROACH 

* Reverse List
* Remove Nth node
* Reverse again
* TC - O(N)
* SC - O(1)

*/

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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* removeNode(Node* head, int n) {

    if(head == NULL || head -> next == NULL) {
        return NULL;
    }

    Node* temp = reverse(head);
    Node* t2 = temp;

    if(n == 1) {
        temp = temp -> next;
        head = reverse(temp);
        return head;
    }
        
    int i = 1;
    while(i < n-1) {
        t2 = t2 -> next;
        i++;
    }

    t2 -> next = t2 -> next -> next;
    head = reverse(temp);

    return head;
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

    Node* ans = removeNode(head, k);
    print(ans);

    return 0;
}