/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //Creating a loop
        ListNode* tail = headA;
        while(tail -> next != NULL){
            tail = tail -> next;
        }
        tail -> next = headA;

        //Floyd loop detection and finding starting node.
        ListNode* slow = headB;
        ListNode* fast = headB;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                slow = headB;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                tail -> next = NULL;
                return slow;
            }
        }
        tail -> next = NULL;
        return NULL;

    }
};