/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* temp = head;
        Node* ansHead = NULL;
        Node* it = NULL;
        while(temp != NULL){
            Node* newNode = new Node(temp -> val);
            if(temp == head){
                ansHead = newNode;
                it = newNode;
            }else{
                it -> next = newNode;
                it = newNode;
            }
            temp = temp -> next;
        }

        Node* temp1 = ansHead;
        temp = head;
        Node* hold1 = NULL;
        Node* hold2 = NULL;

        while(temp != NULL){
            hold2 = temp -> next;
            temp -> next = temp1;
            hold1 = temp1 -> next;
            temp1 -> next = hold2;
            temp = hold2;
            temp1 = hold1;
        }

        temp = head;
        while(temp != NULL){
            temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            temp = temp -> next -> next;
        }

        temp = head;
        temp1 = ansHead;
        while(temp1 -> next != NULL){
            temp -> next = temp1 -> next;
            temp1 -> next = temp -> next -> next;
            temp = temp -> next;
            temp1 = temp1 -> next;
        }
        temp -> next = NULL;
        return ansHead;
    }
};