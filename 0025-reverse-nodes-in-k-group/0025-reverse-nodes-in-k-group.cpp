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

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* forw = head -> next;
        while(forw != NULL){
            head -> next = prev;
            prev = head;
            head = forw;
            forw = forw -> next;
        }
        head -> next = prev;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head -> next == NULL || k == 1) return head;
        int cnt = 0;
        ListNode* temp = head;
        ListNode* h = new ListNode(-1);
        ListNode* ans = h;
        ListNode* revHead = head;
        while(temp != NULL){
            cnt++;
            if(cnt == k){
                ListNode* hold = temp -> next;
                temp -> next = NULL;
                h -> next = reverse(revHead);
                while(h -> next != NULL){
                    h = h-> next;
                }
                temp = hold;
                revHead = temp;
                cnt = 0;
            }else{
                temp = temp -> next;
            }
        }
        if(revHead == NULL) return ans -> next;
        else h -> next = revHead;
        return ans -> next;
    }
};