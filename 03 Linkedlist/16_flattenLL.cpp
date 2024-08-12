/* 
APPROACH 1 - USE ARRAY
* Store data of each node in array - O(N*M)
* sort - O(N*M LOG N*M)
* Create a new Linkedlist from the data of array O(N*M)

* TC - O(N*M) + O(N*M) + O(N*M LOG N*M)
* SC - O(N+M) - for array + O(N+M) - for new LL - O(2 N+M)




Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	vector<int> arr;
	Node* temp1 = head;
	
	while(temp1 != NULL) {

		Node* temp2 = temp1;

		while(temp2 != NULL) {
			arr.push_back(temp2 -> data);
			temp2 = temp2 -> child;
		}

		temp1 = temp1 -> next;
	}

	sort(arr.begin(), arr.end());

	Node* ansHead = new Node(-1);
	Node* ans = ansHead;

	int n = arr.size();
	for(int i=0; i<n; i++) {
		ans -> child = new Node(arr[i]);
		ans = ans -> child;
	}

	ans -> child = NULL;
	return ansHead -> child;
}

*/