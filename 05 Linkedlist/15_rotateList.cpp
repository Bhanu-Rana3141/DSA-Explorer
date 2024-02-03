/*
APPROACH 1 - USE ARRAY
* TC - O(N)
* SC - O(N)

APPROACH 2 - USE CONCEPT OF ARRAYS
* TC - O(N)
* SC - O(1)

APPROACH 3 - TRAVERSAL
* Find length - O(N)
* Traverse and reach at new head node len-k , O(N) - in worst case if k = len
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

Node* rotateList(Node* head, int k) {

    if(head == NULL || head->next == NULL) {
        return head;
    }
    if(k == 0) {
        return head;
    }

    Node* temp = head;
    int len = 1;

    while(temp->next != NULL) {
        len++;
        temp = temp->next;
    }    

    temp->next = head;

    temp = head;
    for(int i=1; i<len-k; i++) {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

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

    Node* ans = rotateList(head, k);
    print(ans);

    return 0;
}