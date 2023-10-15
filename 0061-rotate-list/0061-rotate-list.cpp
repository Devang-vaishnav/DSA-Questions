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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            temp = temp -> next;
            n++;
        }

        k = k%n;
        if(k == 0){
            return head;
        }

        int travel = n-k-1;
        temp = head;
        while(travel--){
            temp = temp -> next;
        }

        ListNode* newHead = temp -> next;
        temp -> next = NULL;
        temp = newHead;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = head;
        return newHead;
    }
};