/*
APPROACH 1 - MAP
1. Detect loop
2. Find start node
3. calculate length
* TC - O(N)
* SC - O(N)

APPRAOCH 2 - FLOYD'S DETECTION ALGO
* TC - O(N)
* SC - O(1)
*/

#include<iostream>
#include<map>
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

Node* detectLoop(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

Node* startNode(Node* &head) {
    Node* slow = head;
    Node* fast = detectLoop(head);

    if(fast == NULL) {
        return NULL;
    }
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int getLength(Node* &head) {
    Node* startOfLoop = startNode(head);
    if(startOfLoop == NULL) {
        return 0;
    }

    Node* temp = startOfLoop;

    int cnt = 1;
    while(temp->next != startOfLoop) {
        cnt++;
        temp = temp->next;
    }
    temp->next = NULL;
    return cnt;
}

int main() {

    int n;
    cout << "Enter size of LL : ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        insertAtTail(head, tail, input);
    }
    
    cout << "Linkedlist : ";
    print(head);

    // Loop
    tail->next = head->next;

    int length = getLength(head);
    cout << "Length: " << length;

    return 0;
}