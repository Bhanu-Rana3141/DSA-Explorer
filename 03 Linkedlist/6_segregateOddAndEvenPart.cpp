/*
APPROACH 1 - USING ARRAY
* Store data of Nodes in array and separate even and odd
* TC - O(N)
* SC - O(N)

APPROACH 2 - USING DUMMY Nodes - 2 dummy nodes are used here 
* No change in original list
* Creating a dummy Node for odd
* Creating a dummy Node for even
* Connect oddTail with evenHead 
TC - O(N)
SC - O(1)
 
APPROACH 3 - One dummy node is used 
* List is manipulated
* TC - O(N)
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
        this -> data = data;
        this -> next = NULL;
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

void printArray(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// APPROACH 1
Node* evenOdd_1(Node* head) {
    vector<int> odd;
    vector<int> even;

    Node* temp = head;
    int i = 1;
    while(temp != NULL) {
        if(i % 2 != 0) {
            odd.push_back(temp -> data);
        }
        else {
            even.push_back(temp -> data);
        }
        i++;
        temp = temp -> next;
    }

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    for(int i=0; i<odd.size(); i++) {
        insertAtTail(ansHead, ansTail, odd[i]);
    }

    for(int i=0; i<even.size(); i++) {
        insertAtTail(ansHead, ansTail, even[i]);
    }
    
    return ansHead;
}

// APPROACH 2
Node* evenOdd_2(Node* head) {

    Node* oddHead = new Node(-1);
    Node* oddTail = oddHead;

    Node* evenHead = new Node(-1);
    Node* evenTail = evenHead;

    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    temp = head;
    int i = 1;
    while(temp != NULL) {
        if(i % 2 != 0) {
            oddTail -> next = temp;
            oddTail = temp;
        }
        else {
            evenTail -> next = temp;
            evenTail = temp;
        }
        temp = temp -> next;
        i++;
    }
    oddTail -> next = evenHead -> next;
    evenTail -> next = NULL;

    return oddHead -> next;
}

// APPROACH 3
Node* evenOdd_3(Node* &head) {
    
    Node* even = new Node(-1);
    Node* evenTail = even;

    Node* temp = head;
    while(temp -> next != NULL) {
        Node* evenNode = temp -> next;
        temp -> next = evenNode -> next;
        evenNode -> next = NULL;
        evenTail -> next = evenNode;
        evenTail = evenNode;
        if(temp -> next != NULL) {
            temp = temp -> next;
        }
    }
    temp -> next = even -> next;
    return head;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter no of Nodes: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        int element;
        cin >> element;
        insertAtTail(head, tail, element);
    }

    cout << "Linkedlist: ";
    print(head);

    // EDGE CASES
    if(head == NULL || head -> next == NULL || head -> next -> next == NULL) {
        cout << head;
        return 0;
    }

    // Node* ans = evenOdd_1(head);
    // Node* ans = evenOdd_2(head);
    Node* ans = evenOdd_3(head);

    cout << "Final list: ";
    print(ans);

    return 0;
}