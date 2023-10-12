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
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* temp2 = NULL;
        while(temp -> next != NULL){
            temp -> val = temp -> next -> val;
            temp2 = temp;
            temp = temp -> next;
        }
        temp2 -> next = NULL;
    }
};