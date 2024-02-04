/*
APPROACH 1 
* Find length - O(N)
* Delete middle node - O(N/2)
* TC - O(N)
* SC - O(1)

APPROACH 2: HARE AND TORTOISE
* TC - O(N/2) - O(N)
* SC - O(1)
*/

#include<iostream>
#include<vector>
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
    if(tail == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
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

Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    fast = head->next->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// APPROCH 1
void deleteMiddle1(Node* head) {

    Node* middle = getMiddle(head);

    Node* nodeToDelete = middle->next;
    middle->next = middle->next->next;
    delete nodeToDelete;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        int element;
        cin >> element;
        insertAtTail(head, tail, element);
    }

    cout << "Linkedlist: ";
    print(head);

    deleteMiddle1(head); 
    print(head);   

    return 0;
}