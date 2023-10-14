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
    ListNode* merge(ListNode* firstHalf, ListNode* secondHalf){
        ListNode* head = NULL;
        ListNode* h = NULL;
        if(firstHalf -> val <= secondHalf -> val){
            head = firstHalf;
            h = head;
            firstHalf = firstHalf -> next;
        }else{
            head = secondHalf;
            h = head;
            secondHalf = secondHalf -> next;
        }

        while(firstHalf != NULL && secondHalf != NULL){
            if(firstHalf -> val <= secondHalf -> val){
                h -> next = firstHalf;
                h = firstHalf;
                firstHalf = firstHalf -> next;
            }else{
                h -> next = secondHalf;
                h = secondHalf;
                secondHalf = secondHalf -> next;
            }
        }
        if(firstHalf != NULL) h -> next = firstHalf;
        if(secondHalf != NULL) h -> next = secondHalf;

        return head;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head -> next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = slow -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* secondHalf = slow -> next;
        slow -> next = NULL;
        ListNode* firstHalf = mergeSort(head);
        secondHalf = mergeSort(secondHalf);
        return merge(firstHalf,secondHalf);

    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};