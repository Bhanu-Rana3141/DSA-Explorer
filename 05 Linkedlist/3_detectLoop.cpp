/*

DETECT LOOP

APPROACH 1 - USING MAP DATA STRUCUTRE
* Creating a map keeping track of visited nodes
* if any node is visited twice, then loop is present else NOT present
* By using this approach :
1. Loop can be detected
2. Where the loop will be detected that will be the starting node of loop.
* TC - O(N)
* SC - O(N) 

APPRAOCH 2 - FLOYD'S CYCLE DETECTION ALGO USING HARE TORTOISE APPROACH
* Take 2 pointers slow and fast
* slow will move 1 step and fast will move 2 steps
* If at any point slow and fast points to same node means loop is present
THIS IS CALLED FLOYD'S DETECTION ALGO
* Therefore if we will try to print node it will not give starting node of loop, it will give any node from the list
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

// VARIATION 1 - DETECT LOOP

/* APPROACH 1 - 
bool isLoop(Node* head) {
    map<Node*, bool> isVisited;

    Node* temp = head;
    while(temp != NULL) {
        if(isVisited[temp] == true) {
            return true;
        }
        isVisited[temp] = true;
        temp = temp->next;
    }
    return false;
}
*/

// APPROACH 2 - FLOYD'S DETECTION ALGO
Node* detectLoop(Node* head) {
    // EDGE CASES 
    // 1. If no node present or if 1 node is present but its next pointer is pointing to NULL - CYCLE NOT PRESENT
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    // 2. If 1 node is present and it's next pointer is pointing to itself - CYCLE PRESENT
    if(head->next == head) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

// VARIATION 2 - FIND STARTING NODE OF LOOP
Node* getStartingNode(Node* head) {
    if(detectLoop(head) == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = detectLoop(head);

    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // If slow and fast intersect that will be the node from where the LOOP STARTED
    return slow;
}

// VARIATION-3 REMVOVE LOOP
void removeLoop(Node* head) {
    if(head == NULL) {
        return;
    }
    
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop) {
        temp = temp->next;
    }
    temp->next = NULL;
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

    // loop 
    tail->next = head->next;

    // STEP 1 - DETECT LOOP
    if(detectLoop(head) != NULL) {
        cout << "Loop is present" << endl;
    }
    else {
        cout << "Loop is NOT PRESENT" << endl;
    }

    // STEP - 2 - STARTING NODE OF LOOP
    Node* startNode = getStartingNode(head);
    cout << "Loop starts from : " << startNode->data << endl;

    // STEP 3 - REMOVE LOOP
    removeLoop(head);
    print(head);

    return 0;
}