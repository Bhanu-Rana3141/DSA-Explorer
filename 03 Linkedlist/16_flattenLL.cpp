/* 
APPROACH 1 - USE ARRAY
* Store data of each node in array - O(N*M)
* sort - O(N*M LOG N*M)
* Create a new Linkedlist from the data of array O(N*M)

* TC - O(N*M) + O(N*M) + O(N*M LOG N*M)
* SC - O(N+M) - for array + O(N+M) - for new LL - O(2 N+M)

*/


/* APPROACH 1
void insertAtTail(Node* &head, Node* &tail, int data) {
	Node* newNode = new Node(data);
	if(head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->child = newNode;
		tail = newNode;
	}
} 

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	vector<int> nodeData;
	Node* temp1 = head;

	while(temp1 != NULL) {
		Node* temp2 = temp1;

		while(temp2 != NULL) {
			nodeData.push_back(temp2->data);
			temp2 = temp2->child;
		}
		temp1 = temp1->next;
	}

	sort(nodeData.begin(), nodeData.end());
	
	Node* ans = NULL;
	Node* ansTail = NULL;
	
	for(int i=0; i<nodeData.size(); i++) {
		insertAtTail(ans, ansTail, nodeData[i]);
	}
	return ans;

}
*/