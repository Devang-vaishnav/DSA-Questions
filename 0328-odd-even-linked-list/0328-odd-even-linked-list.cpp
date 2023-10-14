/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL) return head;
        if(head -> next -> next -> next == NULL){
            ListNode* it1 = head -> next;
            head -> next = it1 -> next;
            it1 -> next = NULL;
            head -> next -> next = it1;
            return head;
        }

        ListNode* itOdd1 = head;
        ListNode* itOdd2 = head -> next -> next;
        ListNode* itEven1 = head -> next;
        ListNode* head2 = itEven1;
        ListNode* itEven2 = itOdd2 -> next;

        while(itOdd2 != NULL || itEven2 != NULL){
            itOdd1 -> next = itOdd2;
            itOdd1 = itOdd2;
            itOdd2 = itOdd2 -> next;
            if(itOdd2 != NULL) itOdd2 = itOdd2 -> next;
            itEven1 -> next = itEven2;
            itEven1 = itEven2;
            if(itEven2 != NULL) itEven2 = itEven2 -> next;
            if(itEven2 != NULL) itEven2 = itEven2 -> next;
        }

        itOdd1 -> next = head2;
        return head;
        
    }
};