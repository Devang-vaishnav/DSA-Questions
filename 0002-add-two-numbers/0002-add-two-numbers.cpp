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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root1 = l1;
        ListNode* root2 = l2;
        ListNode* root = NULL;
        ListNode* ans = NULL;
        int power = 0;
        while(root1 != NULL && root2 != NULL){
            int sum = root1 -> val + root2 -> val + power;
            if(sum > 9){
                power = sum/10;
                sum = sum%10;
            }else{
                power = 0;
            }

            ListNode* newNode = new ListNode(sum);
            if(root == NULL){
                root = newNode;
                ans = newNode;
            }else{
                root -> next = newNode;
                root = newNode;
            }
            root1 = root1 -> next;
            root2 = root2 -> next;
        }

        while(root1 != NULL){
            int sum = root1 -> val + power;
            if(sum > 9){
                power = sum/10;
                sum = sum%10;
            }else{
                power = 0;
            }
            ListNode* newNode = new ListNode(sum);
            root -> next = newNode;
            root = newNode;
            root1 = root1 -> next;
        }

        while(root2 != NULL){
            int sum = root2 -> val + power;
            if(sum > 9){
                power = sum/10;
                sum = sum%10;
            }else{
                power = 0;
            }
            ListNode* newNode = new ListNode(sum);
            root -> next = newNode;
            root = newNode;
            root2 = root2 -> next;
        }

        if(power > 0){
            ListNode* newNode = new ListNode(power);
            root -> next = newNode;
            root = newNode;
        }
        return ans;
    }
};