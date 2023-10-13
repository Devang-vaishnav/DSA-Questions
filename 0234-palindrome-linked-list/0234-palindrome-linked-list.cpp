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
        stack<int>s;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            s.push(slow -> val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast != NULL && fast -> next == NULL) slow = slow -> next;
        while(slow != NULL && !s.empty()){
            if(s.top() != slow -> val) return 0;
            s.pop();
            slow = slow -> next;
        }
        return 1;
    }
};