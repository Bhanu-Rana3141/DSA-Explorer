/*
APPROACH 1 - MAP
* Having a single list but 2 starting point
* Start iterating in 1 list and mark true. After traversing 1 list now traverse in another list if true is present check list1 and list2, this will be the point of intersection
* TC - O(N + M)
* SC - O(N)

        map<ListNode* ,bool> isVisited;

        ListNode* temp1 = headA;
        while(temp1 != NULL) {
            isVisited[temp1] = true;  
            temp1 = temp1->next;   
        }
        
        ListNode* temp2 = headB;
        while(temp2 != NULL) {
            if(isVisited[temp2] == true) {
                return temp2;
            }
            isVisited[temp2] = true;
            temp2 = temp2->next;
        }
        return temp1;
    }

APPROACH 2 - NESTED LOOPS
* Use 2 loops , firstly one node of list1 will be checked with all nodes of list2, then list1 will be updated
* TC - O(N*M)
* SC - O(1)

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != NULL) {
            while(temp2 != NULL) {
                if(temp1 == temp2) {
                    return temp1;
                }
                else {
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
            temp2 = headB;
            }      

APPROACH 3 - 
* Find length of list from both head1 and head2
* TC - O(max(n, m))
* SC - O(1)

 int getLength(ListNode* head) {
        int cnt = 0;
        while(head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int len1 = getLength(headA);
        int len2 = getLength(headB);

        if(len1 > len2) {
            while(len1 != len2) {
                headA = headA->next;
                len1--;
            }
        }
        else {
            while(len2 != len1) {
                headB = headB->next;
                len2--;
            }
        }

        while(headA != NULL && headB != NULL) {
            if(headA == headB) {
                return headA;
            }
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }

// APPROACH 4
* TC - O(max(n, m))
* SC - O(1)
            if(headA == NULL || headB == NULL) {
                return NULL;
            }

            ListNode* temp1 = headA;
            ListNode* temp2 = headB;

            while(temp1 != temp2) {
                if(temp1 == temp2) {
                    return temp1;
                }
                else if(temp1 == NULL) {
                    temp1 = headB;
                }
                else if(temp2 == NULL) {
                    temp2 = headA;
                }
                else {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
            return temp1;
        }
*/