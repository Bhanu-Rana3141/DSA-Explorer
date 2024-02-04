/*

APPROACH 1 - USING MAP
* TC - O(N)
* SC - O(N)

APPROCH 2 - CHANGE LINKS
* TC - O(N)
* SC - O(1)

*/


/* APPROACH 1

void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        
        // Step 1 - Create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }

        // Step 2 - Create a map
        unordered_map<Node*, Node*> oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        // Step 3 - Arranging random pointers
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL) {
            cloneNode->random = oldToNewNode[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
*/


/* APPROACH 2

 void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        
        // Step 1 - clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Step 2 - add cloneNodes in origianl list [mapping by changing links]
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL) {
            Node* originalNext = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = originalNext;

            Node* cloneNext = cloneNode -> next;
            cloneNode -> next = originalNext;
            cloneNode = cloneNext;
        }

        // Step 3 - Arrange random pointers
        temp = head;
        while(temp != NULL) {
            if(temp -> next != NULL) {
                temp -> next -> random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp -> next -> next;
        }

        // Step 4 - revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL) {
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;

            if(originalNode != NULL) {
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }

        // Step 5 - return ans
        return cloneHead;
    }
*/