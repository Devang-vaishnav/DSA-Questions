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
        string s = "";
        ListNode* temp = head;
        while(temp != NULL){
            s+=((temp->val)+'0');
            temp = temp -> next;
        }
        string st = s;
        reverse(st.begin(),st.end());
        if(s == st) return 1;
        return 0;
    }
};