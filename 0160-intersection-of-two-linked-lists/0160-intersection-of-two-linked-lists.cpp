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
    ListNode* solve(ListNode *headA, ListNode *headB, int l1, int l2){
        if(l1 > l2){
            while(l1 != l2){
                headA = headA -> next;
                l1--;
            }
        }else{
            while(l1 != l2){
                headB = headB -> next;
                l2--;
            }
        }

        while(headA != NULL && headB != NULL){
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* t1 = headA, *t2 = headB;
        while(t1 != NULL){
            len1++;
            t1 = t1 -> next;
        }
        while(t2 != NULL){
            len2++;
            t2 = t2 -> next;
        }

        return solve(headA,headB,len1,len2);
    }
};