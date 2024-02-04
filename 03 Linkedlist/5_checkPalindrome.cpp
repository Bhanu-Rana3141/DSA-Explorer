/*
APPROACH 1 

* Traverse on each node and store node data in a vector - O(N)
* Check whether it is palindrome or not - O(N/2)
TC - O(N) + O(N/2) - O(N)
SC - O(N)

APPROACH 2

* Find middle  - O(N)
* Reverse LL part after middle -> this will manipulate original list    - O(N )
* Compare both parts    - O(N)
* Now convert list in original list - O(N)
* Return whether palindrome or not  - O(1)
TC - O(N)
SC - O(1)

EDGE CASES 
* If list is empty or only have one node, then return true
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

// APPROACH 1
bool checkPalindrome1(Node* head) {
    vector<int> nodeData;

    while(head != NULL) {
        nodeData.push_back(head->data);
        head = head->next;
    }

    int s = 0;
    int e = nodeData.size() - 1;

    while(s < e) {
        if(nodeData[s] != nodeData[e]) {
            return false;
        }
        else {
            s++, e--;
        }
    }
    return true;
}

// APPROACH 2
Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
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

    // bool ans = checkPalindrome1(head);

    // step 1 - find middle
    Node* middle = getMiddle(head);

    // step 2 - reverse part after middle
    middle->next = reverse(middle->next);
 
    // step 3 - compare both parts
    Node* head1 = head;
    Node* head2 = middle->next;

    bool isPalindrome = true;
    while(head2 != NULL) {
        if(head1->data != head2->data) {
            isPalindrome = false;
            break;
        }
        else {
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    // step 4 - convert manipulated list as given input
    middle->next = reverse(middle->next);

    // step 5 - return ans    
    if(isPalindrome) {
        cout << "List is palindrome";
    }
    else {
        cout << "Not palindrome";
    }

    return 0;
}