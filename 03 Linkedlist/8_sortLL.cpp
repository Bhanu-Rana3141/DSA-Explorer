/*
APPROACH 1 - USE ARRAY
* Convert in array and sort
* TC - O(N LOG N)
* SC - O(N)

APPROACH 2: MERGE SORT
* TC - O(N LOG N)
* SC - O(LOG N)
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
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {

    Node* ansHead = new Node(-1);
    Node* temp = ansHead;

    while(left != NULL && right != NULL) {
        if(left->data <= right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    
    return ansHead->next;
}

Node* mergeSort(Node* head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* mid = getMiddle(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* res = merge(left, right);
    return res;
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

    Node* ans = mergeSort(head);
    print(ans);

    return 0;
}