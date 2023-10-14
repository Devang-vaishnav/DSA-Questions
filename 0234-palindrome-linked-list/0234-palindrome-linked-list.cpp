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
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL) return 1;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast != NULL && fast -> next == NULL) slow = slow -> next;
        fast = head;
        ListNode* prev = NULL;
        ListNode* nxt = slow -> next;
        while(nxt != NULL){
            slow -> next = prev;
            prev = slow;
            slow = nxt;
            nxt = nxt -> next;
        }
        slow -> next = prev;
        while(slow != NULL){
            if(slow -> val != fast -> val) return 0;
            slow = slow -> next;
            fast = fast -> next;
        }
        return 1;
    }
};