/*
APPROACH 1 - USE ARRAY
* TC - O(N)
* SC - O(N)

APPROACH 1 - IN THIS APPROACH DATA IS REPLACED
* Count 0 1 2 - TC : O(N)
* Place them in sorting order - TC : O(N)
* BUT HERE DATA IS REPLACED
* TC - O(N)
* SC - O(1)

APPROACH 2 - IN THIS APPROACH LINKS ARE CHANGED, DATA IS NOT REPLACED
* Creating dummy nodes for 0, 1 , 2 and further connecting 0 1 2 making them separate nodes
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

void insertAtTail(Node* &head, Node* &tail, int element) {
    Node* newNode = new Node(element);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// APPROACH 1
Node* sort(Node* &head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroCount++;
        }
        else if(temp->data == 1) {
            oneCount++;
        }
        else {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if(zeroCount != 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0) {
            temp->data = 1;
            oneCount--;
        }
        else {
            temp->data = 2;
        }
        temp = temp->next;
    }
    return head;
}

void insert(Node* &tail, Node* &curr) {
    tail->next = curr;
    tail = curr;
}

// APPROACH 2
Node* sortList(Node* head) {
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL) {
        if(curr->data == 0) {
            insert(zeroTail, curr);
        }
        else if(curr->data == 1) {
            insert(oneTail, curr);
        }
        else {
            insert(twoTail, curr);
        }
        curr = curr->next;
    } 

    if(oneHead->next != NULL) {
        // If list one is not empty
        zeroTail->next = oneHead->next;
    }
    else {
        // if list one is empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
int main() {

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter size of list: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        int element;
        cin >> element;
        insertAtTail(head, tail, element);
    }

    // Node* ans = sort(head);
    Node* ans = sortList(head);
    print(ans);

    return 0;
}